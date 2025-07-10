# Fisher-Yates Shuffle
Fisher-Yates shuffle algorithm (also known as as Knuth shuffle) implementation.
This implementation uses glibc `random` and `srandom` functions. For real world
use cases implement this algorithm yourself with appropriate random number generator
(RNG) like [WolfSSL](https://www.wolfssl.com/) RNG or other cryptographic libraries.

## Build
To build the example program:
```bash
gcc -std=gnu99 -Wall -Wextra -Og -g3 main.c shuffle.c
```
