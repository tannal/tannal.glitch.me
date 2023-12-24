# Build LLVM from source

```bash

real	20m49.175s
user	464m58.269s
sys	28m15.400s



export PATH="/usr/lib/ccache/:$PATH"

sudo apt-get -y install ninja-build

git clone --depth 1 https://github.com/llvm/llvm-project.git


# cmake -S llvm -B build -G Unix Makefiles

cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld' -DCMAKE_BUILD_TYPE=Debug -DLLVM_USE_LINKER=lld

CFG

```

