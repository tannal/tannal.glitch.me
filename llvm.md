# Build LLVM from source

```sh

export PATH="/usr/lib/ccache/bin/:$PATH"

sudo apt-get -y install ninja-build

git clone --depth 1 https://github.com/llvm/llvm-project.git

# cmake -S llvm -B build -G Unix Makefiles

cmake -S llvm -B build -G"Ninja" -DCMAKE_BUILD_TYPE=Debug -DLLVM_USE_LINKER=lld

```

