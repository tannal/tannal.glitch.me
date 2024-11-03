

# inbox

/snap/bin/cmake -G Ninja -B build \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_C_COMPILER=/opt/llvm/bin/clang \
    -DCMAKE_CXX_COMPILER=/opt/llvm/bin/clang++ \
    -DLLVM_DIR=/opt/llvm/lib/cmake/llvm \
    -DCLANG_DIR=/opt/llvm/lib/cmake/clang \
    -DLLVM_LINK_BINARY=/opt/llvm/bin/llvm-link \ 
    -DLLVM_VERSION=ignore

# dev

/snap/bin/cmake -G Ninja -B build -DLLVM_VERSION=14.0.0 -DCMAKE_BUILD_TYPE=Debug