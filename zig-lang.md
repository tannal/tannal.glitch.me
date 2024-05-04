# Build Zig From Source


export CC=/opt/llvm-17/bin/clang
export CXX=/opt/llvm-17/bin/clang++
cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'


cmake _G -B build -DLLVM_FOUND=/opt/llvm-17/ -DCMAKE_FIND_DEBUG_MODE=ON -DZIG_USE_LLVM_CONFIG=OFF -DLLD_FOUND=/opt/llvm-17/lld -DLLD_INCLUDE_DIRS=/opt/llvm-17/include/lld/ -DCLANG_INCLUDE_DIRS=/opt/llvm-17/include/clang

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
mkdir build
cd build
cmake ..
make -j8
```

3. run and test


```bash

./build/stage3/bin/zig


```