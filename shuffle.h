/**
 * Fisher-Yates shuffle algorithm (also known as as Knuth shuffle).
 */

#ifndef _SHUFFLE_H_
#define _SHUFFLE_H_

#include <stddef.h>

typedef void(*__swap_fn)(void *lhs, void *rhs);

int shuffle(void *items, size_t item_size,
            size_t n_items, __swap_fn swap);

#endif // _SHUFFLE_H_
