/**
 * Fisher-Yates shuffle algorithm (also known as as Knuth shuffle).
 */

#ifndef _SHUFFLE_H_
#define _SHUFFLE_H_

#include <stddef.h>

typedef void* shuffle_ctx_t;

typedef void(*__swap_fn)(void *lhs, void *rhs);

shuffle_ctx_t shuffle_ctx_init(void);

void shuffle_ctx_destroy(shuffle_ctx_t _ctx);

int shuffle(shuffle_ctx_t _ctx, void *items, size_t item_size,
            size_t n_items, __swap_fn swap);

int shuffle_simple(void *items, size_t item_size,
                   size_t n_items, __swap_fn swap);

#endif // _SHUFFLE_H_
