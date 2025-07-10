#include <time.h>
#include <stdlib.h>
#include <string.h>

#include <wolfssl/options.h>
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/random.h>

#include "malloc.h"
#include "shuffle.h"

struct shuffle_ctx {
    WC_RNG rng;
};

static inline size_t rand_range(WC_RNG *rng, size_t min, size_t max) {
    size_t r = 0;
    wc_RNG_GenerateBlock(rng, (byte*)&r, sizeof(r));
    return ((r % (max - min + 1)) + min);
}

shuffle_ctx_t shuffle_ctx_init(void) {
    struct shuffle_ctx *ctx = calloc(1, sizeof(*ctx));
    wc_InitRng(&ctx->rng);
    return ctx;
}


void shuffle_ctx_destroy(shuffle_ctx_t _ctx) {
    struct shuffle_ctx *ctx = (struct shuffle_ctx*)_ctx;
    wc_FreeRng(&ctx->rng);
    free(ctx);
}

int shuffle(shuffle_ctx_t _ctx, void *items, size_t item_size,
            size_t n_items, __swap_fn swap)
{
    long i, j, idx;
    unsigned char *ptr = (unsigned char*)items;
    struct shuffle_ctx *ctx = (struct shuffle_ctx*)_ctx;
    for (i = n_items - 1; i > 0; i--) {
        j = rand_range(&ctx->rng, 0, i);
        swap(ptr+(i*item_size), ptr+(j*item_size));
    }
    return 0;
}

int shuffle_simple(void *items, size_t item_size,
                   size_t n_items, __swap_fn swap)
{
    WC_RNG rng;
    size_t i, j, idx;
    unsigned char *ptr = (unsigned char*)items;
    wc_InitRng(&rng);
    for (i = n_items - 1; i > 0; i--) {
        j = rand_range(&rng, 0, i);
        swap(ptr+(i*item_size), ptr+(j*item_size));
    }
    wc_FreeRng(&rng);
    return 0;
}
