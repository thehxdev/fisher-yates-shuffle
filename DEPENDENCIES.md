# Dependencies
This document describes how to build dependencies without installing them system-wide.

## First steps
In the project root directory, create `deps` directory to install all the dependencies there.
```bash
mkdir -p deps
```
Then change the current working directory to `deps` and set the `DEPS_DIR` environment variable:
```bash
cd deps
export DEPS_DIR=$PWD
```

## WolfSSL
Download WolfSSL latest release zip archive from [WolfSSL Official Website](https://www.wolfssl.com/download/) to the `deps` directory.
Extract the archive and build WolfSSL.
```bash
# In the wolfssl directory
./configure --prefix="$DEPS_DIR" --enable-static --enable-rng

make -j$(nproc)

make install
```

## Done!
Go back to source root directory:
```bash
cd "$DEPS_DIR/.."
```
