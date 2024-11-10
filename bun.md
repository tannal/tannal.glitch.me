

# inbox

export PATH=/opt/llvm/bin:$PATH
export PATH=/opt/llvm-17/bin:$PATH

/snap/bin/cmake -G Ninja -B build \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_C_COMPILER=/opt/llvm-17/bin/clang \
    -DCMAKE_CXX_COMPILER=/opt/llvm-17/bin/clang++

/snap/bin/cmake -G Ninja -B build \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_C_COMPILER=/opt/llvm/bin/clang \
    -DCMAKE_CXX_COMPILER=/opt/llvm/bin/clang++ \
    -DUSE_CACHE=OFF  # 禁用缓存

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

# 1. 首先复制运行时库到 LLVM 安装目录
sudo cp -r /home/tannal/tannalwork/projects/llvm-project/build/runtimes/runtimes-bins/lib/clang/20/* /opt/llvm/lib/clang/20/

# 2. 确保权限正确
sudo chown -R root:root /opt/llvm/lib/clang/20/
sudo chmod -R 755 /opt/llvm/lib/clang/20/

# 3. 验证文件是否存在
ls -l /opt/llvm/lib/clang/20/lib/x86_64-unknown-linux-gnu/libclang_rt.ubsan_standalone.a
