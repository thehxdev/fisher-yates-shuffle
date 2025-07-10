#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#include "malloc.h"
#include "shuffle.h"

static inline size_t rng_rand_range(size_t min, size_t max) {
    return ((random() % (max - min + 1)) + min);
}

int shuffle(void *items, size_t item_size,
            size_t n_items, __swap_fn swap)
{
    size_t i, j;
    unsigned char *ptr = (unsigned char*)items;
    srandom(time(NULL) + (size_t)items + n_items + item_size + (size_t)swap);
    for (i = n_items - 1; i > 0; i--) {
        j = rng_rand_range(0, i);
        swap(ptr+(i*item_size), ptr+(j*item_size));
    }
    return 0;
}
