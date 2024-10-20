# Build Zig From Source


export CC=/opt/llvm-17/bin/clang
export CXX=/opt/llvm-17/bin/clang++
cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'


cmake -G Ninja -B build -DLLVM_FOUND=/opt/llvm/ -DCMAKE_FIND_DEBUG_MODE=ON -DZIG_USE_LLVM_CONFIG=OFF -DLLD_FOUND=/opt/llvm/bin/lld -DLLD_INCLUDE_DIRS=/opt/llvm/include/lld/ -DCLANG_INCLUDE_DIRS=/opt/llvm/include/clang

1. Build LLVM-17

cmake -B build -DLLVM_ROOT=/opt/llvm-17

```bash

sudo apt install ninja-build

git clone --depth 1 --branch release/17.x https://github.com/llvm/llvm-project llvm-project-17
cd llvm-project-17
git fetch --tags

git fetch origin tag release/17.x  --no-tags
git checkout release/17.x

mkdir build-release
cd build-release
cmake ../llvm \
  -DCMAKE_INSTALL_PREFIX=$HOME/local/llvm17-release \
  -DCMAKE_BUILD_TYPE=Release \
  -DLLVM_ENABLE_PROJECTS="lld;clang" \
  -DLLVM_ENABLE_LIBXML2=OFF \
  -DLLVM_ENABLE_TERMINFO=OFF \
  -DLLVM_ENABLE_LIBEDIT=OFF \
  -DLLVM_ENABLE_ASSERTIONS=ON \
  -DLLVM_PARALLEL_LINK_JOBS=1 \
  -G Ninja
ninja install


```


2. Build zig

```bash
cmake -G Ninja -B build \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
  -DCMAKE_BUILD_TYPE='Debug' \
  -DLLVM_CONFIG_PATH=/opt/llvm/bin/llvm-config

n2 -C build


```

3. run and test

zig build \
  -p stage3 \
  --search-prefix "$LLVM_PREFIX" \
  --zig-lib-dir lib \
  -Dstatic-llvm


```bash

./build/stage3/bin/zig


```







# people

involves:andrewrk
involves:kubkon
involves:jacobly0
involves:mlugg
involves:Snektron
involves:kcbanner
involves:Vexu
involves:Luukdegram
involves:squeek502
involves:ianic
involves:der-teufel-programming
involves:antlilja
involves:wooster0
involves:kristoff-it
involves:devnexen
involves:castholm
involves:jedisct1
involves:truemedian
involves:mikdusan
involves:dweiller
involves:alichraghi
involves:xxxbxxx
involves:ianprime0509
involves:Techatrix
involves:BratishkaErik
involves:nektro
involves:tiehuis
involves:linusg
involves:wrongnull
involves:perillo
involves:matu3ba
involves:Rexicon226
involves:xdBronch
involves:FnControlOption
involves:motiejus
involves:schmee
involves:The-King-of-Toasters
involves:ehaas
involves:marler8997
involves:thejoshwolfe
involves:g-w1
involves:travisstaloch
involves:SuperAuguste
involves:jayschwa
involves:ifreund
involves:frmdstryr
involves:kprotty
involves:hryx
involves:Sahnvour
involves:koachan
involves:joachimschmidt557
involves:mathetake
involves:mattnite
involves:leecannon
involves:gwenzek
involves:kivikakk
involves:fifty-six
involves:semarie
involves:mitchellh
involves:Hejsil
involves:daurnimator
