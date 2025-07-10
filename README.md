# Fisher-Yates Shuffle
Fisher-Yates shuffle algorithm (also known as as Knuth shuffle) implementation
using WolfSSL random number generator (RNG).

## Build
Read [DEPENDENCIES.md](DEPENDENCIES.md) first. Then:
```bash
gcc -std=gnu99 -Og -g3 \
    -I./deps/include -L./deps/lib main.c shuffle.c -l:libwolfssl.a
```
