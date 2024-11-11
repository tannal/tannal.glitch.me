

# inbox

P0: 最高优先级，如构建中断或重大回归
P1: 高优先级，工作列表顶部的问题
P2: 重要但不是最紧急的问题
P3: 相对较低优先级的问题

a: accessibility: 无障碍相关(VoiceOver/TalkBack)
a: animation: 动画 API 相关
a: assets: 资源包管理和使用
a: debugging: 调试和断点相关
a: desktop: 桌面平台相关
a: internationalization: 国际化支持
a: layout: 布局系统问题

f: material design: Material 设计组件
f: cupertino: iOS 风格组件
f: gestures: 手势系统
f: scrolling: 滚动视图相关
f: routes: 导航和路由

platform-android: Android 平台特定
platform-ios: iOS 平台特定
platform-web: Web 平台特定
platform-windows: Windows 平台特定
platform-linux: Linux 平台特定
platform-mac: macOS 平台特定

team-engine: 引擎团队负责
team-framework: 框架团队负责
team-tool: 工具团队负责
team-web: Web 团队负责
team-accessibility: 无障碍团队负责

perf: app size: 应用大小相关
perf: memory: 内存性能问题
perf: speed: 渲染速度问题
perf: startup: 启动时间问题

t: flutter doctor: flutter doctor 工具问题
t: hot reload: 热重载相关
t: gradle: Android 构建系统
t: xcode: iOS 构建系统

p: camera: 相机插件
p: firebase: Firebase 相关插件
p: google_sign_in: Google 登录插件
p: image_picker: 图片选择器插件

has reproducible steps: 有重现步骤
waiting for customer response: 等待用户响应
workaround available: 有可用解决方案
blocked: 被其他问题阻塞

e: impeller: Impeller 渲染后端
e: opengl: OpenGL 相关
e: web_canvaskit: Web CanvasKit 渲染
e: wasm: WebAssembly 相关

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
