#ifndef _SHUFFLE_MALLOC_H_
#define _SHUFFLE_MALLOC_H_

#include <stdlib.h>

#define malloc(s)       malloc(s)
#define calloc(c, s)    calloc(c, s)
#define realloc(p, s)   realloc(p, s)
#define free(p)         free(p)

#endif // _SHUFFLE_MALLOC_H_
