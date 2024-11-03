

# inbox

// 三棵树
Widget Tree    -> 配置
Element Tree   -> 逻辑
RenderObject   -> 布局和绘制

// 合成层
Layer Tree     -> GPU渲染

// 1. Sliver虚拟化
- 只构建可见项
- 复用视图

// 2. 合成层优化
- 可滚动区域单独层
- 避免重绘

// 3. 帧调度
- VSync同步
- 帧预测

// 1. 主线程
- 布局计算
- 构建管理

// 2. GPU线程
- 栅格化
- 合成
- 实际滚动


构建 Dart SDK
bash

复制
# 克隆 Dart SDK 仓库
git clone https://github.com/dart-lang/sdk.git dart-sdk
cd dart-sdk

# 获取依赖
./tools/build.py --no-goma create_sdk

# 构建 Dart SDK
./tools/build.py --mode release --arch x64 create_sdk
构建 Flutter engine
bash

复制
# 克隆 Flutter engine 仓库
git clone https://github.com/flutter/engine.git flutter-engine
cd flutter-engine

# 安装 depot_tools
git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
export PATH="$PATH:/path/to/depot_tools"

# 获取依赖
gclient sync

# 配置构建
./flutter/tools/gn --runtime-mode release --unopt

# 构建 engine
ninja -C out/host_release
构建 Flutter SDK
bash

复制
# 克隆 Flutter SDK 仓库
git clone https://github.com/flutter/flutter.git flutter-sdk
cd flutter-sdk

# 切换到 master 分支
git checkout master

# 运行 Flutter 工具链构建
bin/flutter precache
bin/flutter doctor
配置 Flutter 使用本地构建的 engine
编辑 flutter-sdk/bin/internal/engine.version 文件，将其内容改为您本地 engine 构建的路径：


复制
/path/to/your/flutter-engine/out/host_release
运行开源 Flutter 应用
现在您可以使用您构建的 Flutter SDK 来运行一个开源的 Flutter 应用了。以 Flutter Gallery 为例：

bash

复制
# 克隆 Flutter Gallery
git clone https://github.com/flutter/gallery.git
cd gallery

# 使用您构建的 Flutter SDK
/path/to/your/flutter-sdk/bin/flutter pub get
/path/to/your/flutter-sdk/bin/flutter run
注意事项：

确保您的系统满足所有必要的依赖要求。这可能包括特定版本的 Python、CMake、Ninja 等。
构建过程可能会非常耗时，特别是首次构建时。确保您有足够的磁盘空间和良好的网络连接。
在构建 engine 时，您可能需要根据您的需求调整构建参数，例如目标平台（Android、iOS、桌面等）。
如果您在构建过程中遇到任何问题，请查阅官方文档或寻求团队其他成员的帮助。
记得经常同步您的代码库，因为 Flutter 和 Dart 的开发非常活跃。
考虑设置一些环境变量来简化您的工作流程，例如将您构建的 SDK 和工具添加到 PATH 中。