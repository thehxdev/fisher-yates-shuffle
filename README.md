# Fisher-Yates Shuffle
Fisher-Yates shuffle algorithm (also known as as Knuth shuffle) implementation
using WolfSSL random number generator (RNG).

## Dependencies
If you want to use WolfSSL RNG, then read [DEPENDENCIES.md](DEPENDENCIES.md) first.
Otherwise continue to build section.

## Build
Without WolfSSL and with libc `srandom` and `random`:
```bash
gcc -std=gnu99 -Og -g3 main.c shuffle.c
```
With WolfSSL RNG:
```bash
gcc -std=gnu99 -Og -g3 \
    -I./deps/include -L./deps/lib main.c shuffle.c -l:libwolfssl.a
```
