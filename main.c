#include <stdio.h>
#include "shuffle.h"

void swap_num(void *lhs, void *rhs) {
    int tmp = *(int*)lhs;
    *(int*)lhs = *(int*)rhs;
    *(int*)rhs = tmp;
}

int main(void) {
    int xs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
    size_t i, xs_size = sizeof(xs) / sizeof(*xs);

    for (i = 0; i < xs_size; i++)
        printf("%d ", xs[i]);
    putchar('\n');

    shuffle_simple(xs, sizeof(*xs), xs_size, swap_num);

    for (i = 0; i < xs_size; i++)
        printf("%d ", xs[i]);
    putchar('\n');

    return 0;
}
