#include <time.h>
#include <stdlib.h>
#include <string.h>

#ifdef SHUFFLE_WITH_WOLFSSL
    #include <wolfssl/options.h>
    #include <wolfssl/wolfcrypt/settings.h>
    #include <wolfssl/wolfcrypt/random.h>

    #define rng_t       WC_RNG
    #define rng_init(r) wc_InitRng((r))
    #define rng_free(r) wc_FreeRng((r))
    #define rng_rand_range(rng, min, max) __rng_rand_range((rng), (min), (max))
#else
    #include <time.h>

    #define rng_t void*
    #define rng_init(r) srandom(time(NULL))
    #define rng_free(r)
    #define rng_rand_range(rng, min, max) __rng_rand_range(NULL, min, max)
#endif

#include "malloc.h"
#include "shuffle.h"

struct shuffle_ctx {
    rng_t rng;
};

static inline size_t __rng_rand_range(rng_t *rng, size_t min, size_t max) {
    size_t r;
#ifdef SHUFFLE_WITH_WOLFSSL
    wc_RNG_GenerateBlock(rng, (byte*)&r, sizeof(r));
#else
    r = random();
#endif
    return ((r % (max - min + 1)) + min);
}

shuffle_ctx_t shuffle_ctx_init(void) {
    struct shuffle_ctx *ctx = calloc(1, sizeof(*ctx));
    rng_init(&ctx->rng);
    return ctx;
}

void shuffle_ctx_destroy(shuffle_ctx_t _ctx) {
    struct shuffle_ctx *ctx = (struct shuffle_ctx*)_ctx;
    rng_free(&ctx->rng);
    free(ctx);
}

int shuffle(shuffle_ctx_t _ctx, void *items, size_t item_size,
            size_t n_items, __swap_fn swap)
{
    long i, j, idx;
    unsigned char *ptr = (unsigned char*)items;
    struct shuffle_ctx *ctx = (struct shuffle_ctx*)_ctx;
    for (i = n_items - 1; i > 0; i--) {
        j = rng_rand_range(&ctx->rng, 0, i);
        swap(ptr+(i*item_size), ptr+(j*item_size));
    }
    return 0;
}

int shuffle_simple(void *items, size_t item_size,
                   size_t n_items, __swap_fn swap)
{
    size_t i, j, idx;
    unsigned char *ptr = (unsigned char*)items;
    struct shuffle_ctx *ctx = shuffle_ctx_init();

    for (i = n_items - 1; i > 0; i--) {
        j = rng_rand_range(&ctx->rng, 0, i);
        swap(ptr+(i*item_size), ptr+(j*item_size));
    }

    shuffle_ctx_destroy(ctx);
    return 0;
}
