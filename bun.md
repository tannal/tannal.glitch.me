# issues tag

bun.js - Bun 特定 API
runtime - 运行时相关
bundler - 打包器相关
transpiler - 转译器相关
minifier - 代码压缩
sourcemaps - 源码映射

bun install - 包管理器
bunx - bunx 命令
cli - 命令行接口
bun --hot - 热重载
bun --watch - 文件监视
bun patch - 补丁功能

bun:crypto - 加密模块
bun:dns - DNS 解析
bun:ffi - 外部函数接口
bun:fs - 文件系统
bun:http - HTTP 服务
bun:sqlite - SQLite 支持
bun:tcp - TCP 网络
bun:test - 测试运行器

node.js - Node.js API 兼容
node:fs - 文件系统兼容
node:http - HTTP 兼容
node:crypto - 加密兼容
node:stream - 流兼容
napi - 原生模块兼容

linux - Linux 平台
macOS - macOS 平台
windows - Windows 平台
docker - Docker 环境
lambda - AWS Lambda

bug - 程序错误
crash - 崩溃问题
enhancement - 功能增强
regression - 回归问题
performance - 性能问题
memory leak - 内存泄漏

good first issue - 适合新手
needs investigate - 需要调查
needs repro - 需要复现步骤
needs triage - 需要分类
stale - 过期问题

docs - 文档改进
types - TypeScript 类型
typescript - TypeScript 相关

debugger - 调试器
repl - 交互式环境
shell - Shell 功能
single-file-executable - 单文件可执行

ecosystem - 包/框架兼容性
tracking-pkg - 库支持追踪
HTMLRewriter - Cloudflare Workers API
Worker - Web/Node Worker API

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
