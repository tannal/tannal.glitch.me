

https://phabricator.services.mozilla.com/D233087

捕获阶段 (Capturing) ↓
    |
    ▼
目标阶段 (Target)
    |
    ▼
冒泡阶段 (Bubbling) ↑


1. PreHandleEvent (系统预处理)
   ↓
2. Capturing Phase (捕获阶段)
   ↓
3. Target Phase (目标阶段)
   ↓
4. Bubbling Phase (冒泡阶段)
   ↓
5. PostHandleEvent (系统后处理)

项目Fission前(传统单进程):
主进程:
    |-> 主线程
        - UI
        - 网络
        - 存储
    |-> 内容线程
        - 渲染
        - JS执行
    |-> 合成线程
    |-> IO线程

项目Fission后(多进程):
- Parent Process (主进程)
- Content Process (内容进程)
- GPU Process
- Web Extension Process
- Socket Process

特点:
- 逐步走向多进程
- 保持向后兼容
- 内存占用适中
- 灵活的进程模型

# Cookie

https://datatracker.ietf.org/doc/html/rfc6265

Zone -> Realm -> Arena -> Cell

代码首次执行:
Classic Interpreter
      ↓
(达到热度阈值)
      ↓
Baseline Interpreter/JIT
      ↓
(达到更高热度阈值)
      ↓
IonMonkey JIT

Error
InternalError
AggregateError
EvalError
RangeError
ReferenceError
SyntaxError
TypeError
URIError

Boris Zbarsky (@bz)
Mozilla 的资深技术专家
Gecko 渲染引擎的主要架构师之一
对 CSS 引擎和 DOM 实现有深入研究
在 Web 标准制定方面非常活跃
Emilio Cobos Álvarez (@emilio)
Mozilla 的资深工程师
Servo/Gecko 的主要贡献者
专注于 CSS 引擎和布局系统
Rust 语言的积极贡献者
Marco Castelluccio
Mozilla 的工程师
主要负责自动化测试和 CI/CD 系统
参与 Rust 重写项目
Nicolas B. Pierron
SpiderMonkey JavaScript 引擎的核心开发者
专注于 JIT 编译器优化
Valerie Young
Mozilla 的工程师
参与 Servo 项目开发
专注于浏览器性能优化
他们的一些重要同事包括：
Patrick Brosset
开发者工具团队负责人
Firefox DevTools 的主要贡献者
Dave Herman
Mozilla Research 的主要研究员
Rust 语言设计的早期参与者
Bobby Holley
Firefox 性能团队负责人
Gecko 平台架构师
Anne van Kesteren
Web 标准专家
WHATWG 规范的主要作者之一
这些开发者共同推动了 Firefox 浏览器的发展，特别是在:
Rust 语言的采用
Servo 新一代渲染引擎的开发
Web 标准的制定和实现
浏览器性能和安全性的提升
他们的工作对整个 Web 生态系统都产生了重要影响


# 渲染引擎核心(Gecko)相关：
Layout: 负责页面布局，包括块级、内联、弹性盒子、网格等布局系统
Graphics: 图形渲染系统，包括Canvas、WebGL、文本渲染等
SVG: 矢量图形处理
CSS: 样式解析和计算
DOM: 文档对象模型实现

# 多媒体处理：
Audio/Video: 音视频播放、录制
Web Audio: Web音频API
WebRTC: 实时通信
JavaScript引擎：
JavaScript Engine: JS解释器
JavaScript: GC: 垃圾回收
WebAssembly: WebAssembly支持

# 网络相关：
Networking: 网络库(Necko)
HTTP/WebSocket: 协议实现
Cache: 缓存系统
DNS: 域名解析

# 存储系统：
Storage: IndexedDB、localStorage等
SQLite: 嵌入式数据库
Cache API: 缓存API实现

# 安全相关：
Security: 一般安全问题
Privacy: 隐私保护
Process Sandboxing: 进程沙箱

# 国际化：
Internationalization: 多语言支持
Text: 文本处理和字体

# 系统集成：
Widget: 跨平台UI组件
Window Management: 窗口管理
IPC: 进程间通信

# 性能和调试：
Performance: 性能优化
Gecko Profiler: 性能分析器
Memory Allocator: 内存分配
Developer Tools: 开发者工具


# Graphics

Graphics System
├── Display Pipeline
│   ├── Application Layer
│   │   ├── UI Components
│   │   └── Application Windows
│   │
│   ├── Window System
│   │   ├── Window Manager
│   │   └── Compositor
│   │
│   ├── Composition Layer  <-- 这里
│   │   ├── Layer Tree
│   │   │   ├── Root Layer
│   │   │   ├── Parent Layers
│   │   │   └── Child Layers
│   │   │
│   │   ├── Layer Properties
│   │   │   ├── Transform
│   │   │   ├── Opacity
│   │   │   ├── Masks
│   │   │   └── Filters
│   │   │
│   │   └── Layer Operations
│   │       ├── Blending
│   │       ├── Clipping
│   │       └── Effects
│   │
│   ├── Graphics API Layer
│   │   ├── OpenGL/Vulkan/Metal
│   │   ├── Hardware Acceleration
│   │   └── Rendering Commands
│   │
│   └── Display Hardware
│       ├── GPU
│       ├── Display Controller
│       └── Screen
│
└── Graphics Memory
    ├── Textures
    ├── Buffers
    └── Framebuffers

# media

Raw Sensor Data -> ISP Pipeline
[Bayer数据]       - 去噪
                 - 白平衡
                 - 色彩校正
                 - 锐化

- RAW格式
- YUV格式
- RGB格式

YUV/RGB -> Encoder -> Container
         - H.264     - MP4
         - H.265     - MKV
         - VP8/VP9   - WebM

视频/音频源 -> 解复用(Demuxer) -> 解码器(Decoder) -> 原始数据
[容器格式]     [分离音视频]      [解码压缩数据]    [YUV/PCM]


[Source] -> [Decoder] -> [Processor] -> [Sink]
输入源     解码器        处理器        输出端


# camera

[Camera Sensor] -> [ISP] -> [Encoder] -> [Sink]
    原始数据     图像处理   编码器      输出

# ipc

// IPDL (Inter-Process Communication Protocol Definition Language)
class IpcSystem {
    // 主要使用 Socket + 共享内存
    MessageChannel message_channel;
    SharedMemory shared_memory;

    enum Protocol {
        SYNC,    // 同步调用
        ASYNC,   // 异步调用
        BOTH     // 混合模式
    };
}


# cookie

Windows: %APPDATA%\Mozilla\Firefox\Profiles\[profile]\cookies.sqlite
Linux: ~/.mozilla/firefox/[profile]/cookies.sqlite
Mac: ~/Library/Application Support/Firefox/Profiles/[profile]/cookies.sqlite


# potential mentors

https://phabricator.services.mozilla.com/p/anba/

https://bugzilla.mozilla.org/user_profile?user_id=600802

https://bugzilla.mozilla.org/user_profile?user_id=310076

https://bugzilla.mozilla.org/user_profile?user_id=466787

https://bugzilla.mozilla.org/user_profile?login=mgaudet%40mozilla.com
mgaudet@mozilla.com

https://phabricator.services.mozilla.com/differential/?responsiblePHIDs%5B0%5D=PHID-USER-5cmxqec7hkq4g5p2thju&statuses%5B0%5D=open()&order=newest&bucket=action
fredw

https://bugzilla.mozilla.org/user_profile?user_id=283262 fierfox devtools team now collabrate with servo


author:bholley
author:tantek
author:martinthomson


# Meeting Notes layout & Spidermonkey

V8                    SpiderMonkey
Isolate       <->     JSRuntime
Context       <->     Activation/JSContext
ExecutionStack <->    Activation链表

https://docs.google.com/document/d/1w5ss3hSdh5x4imgvh4q9eZk6o0zz7B--e_rsamjKozw/edit

# tc39 stage3 proposals

https://bugzilla.mozilla.org/show_bug.cgi?id=1435811

# Achievements

## Spidermonkey

Jan de Mooij Baseline JIT for SpiderMonkey

Bug 1899413 - Support v flag in RegExp.prototype r?mgaudet
Bug 1899303 - Implement Redeclarable global eval-introduced vars proposal r?dminor
implement https://github.com/tc39/proposal-redeclarable-global-eval-vars in spidermonkey js engine

## Platform

Bug 1918521 - Remove SetInputValueFromFields when handlekeydown in datetimebox. r=emilio
Bug 1922163 - Table element align attribute mapped to float as per spec. r=emilio
Bug 1917771 - Use bottom of border box as the range frame's baseline. r=emilio
Bug 1917602 - Make CSS zoom property discrete animatable. r?emilio

## Graphics


# working on

./mach try auto

Bug 1911623 - Remove JS_SetParallelParsingEnabled and JSRuntime::parallelParsingEnabled_. r?arai

Though I think there are some tests that need to be updated.
For example, netwerk/cookie/test/unit/test_eviction.js. I think this line needs to be removed. And probably this line needs to have session_foo_path_6 removed from the beginning of the list. There may be other issues, I just took a quick look. Give ./mach xpcshell-test netwerk/cookie/test/unit/test_eviction.js a shot.

Also if you haven't already, can you also run your change against the other cookie tests locally to see if there are more?

    There are xpcshell, mochitest and browser tests in netwerk/cookie/test

There are some more in netwerk/test

    ./mach test netwerk/test/unit/test_*cookie* --headless
    ./mach mochitest -f browser netwerk/test/browser/browser*cookie* --headless

There are also some gtests which can be run like this
./mach gtest TestCookie.*

There are some other tests that we should exercise with try. I would advise using try chooser on at least linux64 and linux64-noopt and select:

    xpcshell tests
    mochitests
    mochi browser tests
    web platform tests
    gtest
    the above with verify (where appropriate)

# dev

https://github.com/httpwg/http-core

./mach run file:///home/tannal/tannalwork/projects/servo/tests/wpt/tests/css/css-tables/border-collapse-dynamic-section.html > all_output.txt 2>&1

您说得对,Firefox确实也能打印出中间数据结构,包括传给WebRender的display list。要在Firefox中实现这一点,我们可以采取以下步骤:

    启用调试输出:

    打开 about:config,搜索并设置以下首选项:

gfx.webrender.debug.display-lists = true
gfx.webrender.debug.dump-display-lists = true

使用环境变量:

在启动Firefox时设置环境变量:
bash

MOZ_LOG="DisplayListBuilder:5" firefox
MOZ_LOG="MediaDecoder:5" firefox

这会输出DisplayListBuilder的详细日志。

使用Gecko Profiler:

    安装Gecko Profiler插件
    在Profiler设置中启用"Graphics"选项
    捕获一个profile,然后在"Marker Chart"中查找"DisplayListBuilding"标记

使用WebRender调试工具:

在 about:config 中设置:

gfx.webrender.debug = true

然后使用快捷键 Ctrl+Shift+Alt+I 打开WebRender调试工具。

查看浏览器控制台:

打开浏览器控制台(Ctrl+Shift+J),可能会看到一些相关的调试输出。

编译调试版Firefox:

如果您愿意编译Firefox,可以在源代码中添加更多的调试输出。

使用远程协议:

Firefox支持远程调试协议,您可以编写脚本来获取这些信息。

./test262-update.py --pull 4213

export MOZ_LOG=sLayoutLog:5
./mach run

RUST_LOG="debug" ./mach run --debugger=gdb /home/tannal/tannalwork/cans/baseline.html

This revision requires a Testing Policy Project Tag to be set before landing. Please apply one of testing-approved, testing-exception-unchanged, testing-exception-ui, testing-exception-elsewhere, testing-exception-other. Tip: this Firefox add-on makes it easy!
gregp edited projects, added testing-exception-unchanged (Doesn't change behavior for users); removed needs-testing-tag.

MOZCONFIG=mozconfig.jsshell ./mach jstests regexp-prototype-matchAll-flags.js
MOZCONFIG=mozconfig.jsshell ./mach jstests redeclaring-global-properties.js
MOZCONFIG=mozconfig.jsshell ./mach jstests script-decl-lex-no-collision.js
MOZCONFIG=mozconfig.jsshell ./mach jstests v-flag.js

ReportOutOfMemory

./test262-export.py --out ../test-262/ --src js/src/tests/test262/built-ins/String/prototype/matchAll/regexp-prototype-matchAll-flags.js

MOZCONFIG=mozconfig.jsshell ./mach run --debugger=gdb
MOZCONFIG=mozconfig.jsshell ./mach run --debugger=gdb

./mach jstests --jitflags=all test.js

MOZCONFIG=mozconfig.jsshell ./mach build
MOZCONFIG=mozconfig.jsshell ./mach jstests js-dbg -m regexp-prototype-matchAll-invocation

For jsshell
ac_add_options --enable-application=js
mk_add_options MOZ_OBJDIR=@TOPSRCDIR@/obj-@CONFIG_GUESS@-jsshell

For full browser
echo "ac_add_options --enable-application=browser" > mozconfig.browser

Bug 1899413 - Support v flag in RegExp.prototype r?mgaudet

./mach build js/src

https://www.recurse.com/apply

make -C js/src check-jstests

make -C js/src check-jit-test

https://codetribute.mozilla.org/projects/jseng


https://wiki.mozilla.org/JavaScript:New_to_SpiderMonkey


CSS、布局、性能优化、UI、WebIDL

spidermonkey
https://phabricator.services.mozilla.com/differential/query/HBPXF4VtNtgz/#R

./mach vcs-setup

./mach try auto

https://phabricator.services.mozilla.com/p/sefeng/

https://phabricator.services.mozilla.com/differential/query/K_SDXXxl7ZVp/#R

https://bugzilla.mozilla.org/buglist.cgi?query_format=advanced&emailtype1=exact&emailassigned_to1=1&email1=cathiechen%40igalia.com&list_id=17172355

https://bugzilla.mozilla.org/show_bug.cgi?id=1861775

背景:
这是一个关于在Linux系统上为Firefox添加高对比度模式支持的功能请求。发起人希望Firefox能够支持新的xdg-desktop-portal中定义的高对比度设置标准。
主要过程:
最初由Dominic Hayes提出,建议Firefox支持即将合并到xdg-desktop-portal的高对比度设置标准。
经过讨论,将该请求的状态设置为NEW,并归类到Disability Access组件下。
xdg-desktop-portal中定义高对比度设置的PR #1175最终被合并。
Emilio Cobos Álvarez(Mozilla开发者)提供了具体的技术实现建议:
在nsLookAndFeel::InitializeGlobalSettings中添加代码
使用类似color-scheme首选项的方式实现
建议的代码逻辑:
cpp

复制
aResult = mPrefersContrastSetting.valueOr(mSystemTheme.mHighContrast);
将组件从Disability Access改为Widget: Gtk
将产品从Firefox改为Core
添加了关键词和优先级
Emilio表示愿意指导这个功能的实现
核心原理:
通过xdg-desktop-portal获取系统高对比度设置,然后在Firefox中根据该设置应用相应的高对比度主题或样式。
下一步:
需要有开发者实际编写代码来实现这个功能,按照Emilio的建议在相关文件中添加获取和应用高对比度设置的逻辑。
总的来说,这是一个旨在改善Firefox在Linux系统上可访问性的功能请求,目前已经有了具体的实现方向,等待开发者去实现。

void nsLookAndFeel::InitializeGlobalSettings() {
GtkSettings* settings = gtk_settings_get_default();

mColorSchemePreference = ComputeColorSchemeSetting();

gboolean enableAnimations = false;
g_object_get(settings, "gtk-enable-animations", &enableAnimations, nullptr);
mPrefersReducedMotion = !enableAnimations;

gint blink_time = 0; // In milliseconds
gint blink_timeout = 0; // in seconds
gboolean blink;
g_object_get(settings, "gtk-cursor-blink-time", &blink_time,
"gtk-cursor-blink-timeout", &blink_timeout, "gtk-cursor-blink",
&blink, nullptr);
// From
// https://docs.gtk.org/gtk3/property.Settings.gtk-cursor-blink-timeout.html:
//
// Setting this to zero has the same effect as setting
// GtkSettings:gtk-cursor-blink to FALSE.
//
mCaretBlinkTime = blink && blink_timeout ? (int32_t)blink_time : 0;

if (mCaretBlinkTime) {
// blink_time * 2 because blink count is a full blink cycle.
mCaretBlinkCount =
std::max(1, int32_t(std::ceil(float(blink_timeout * 1000) /
(float(blink_time) * 2.0f))));
} else {
mCaretBlinkCount = -1;
}

mCSDCloseButton = false;
mCSDMinimizeButton = false;
mCSDMaximizeButton = false;
mCSDCloseButtonPosition = 0;
mCSDMinimizeButtonPosition = 0;
mCSDMaximizeButtonPosition = 0;

// We need to initialize whole CSD config explicitly because it's queried
// as -moz-gtk* media features.
ButtonLayout buttonLayout[TOOLBAR_BUTTONS];

size_t activeButtons =
GetGtkHeaderBarButtonLayout(Span(buttonLayout), &mCSDReversedPlacement);
for (size_t i = 0; i < activeButtons; i++) {
// We check if a button is represented on the right side of the tabbar.
// Then we assign it a value from 3 to 5, instead of 0 to 2 when it is on
// the left side.
const ButtonLayout& layout = buttonLayout[i];
int32_t* pos = nullptr;
switch (layout.mType) {
case MOZ_GTK_HEADER_BAR_BUTTON_MINIMIZE:
mCSDMinimizeButton = true;
pos = &mCSDMinimizeButtonPosition;
break;
case MOZ_GTK_HEADER_BAR_BUTTON_MAXIMIZE:
mCSDMaximizeButton = true;
pos = &mCSDMaximizeButtonPosition;
break;
case MOZ_GTK_HEADER_BAR_BUTTON_CLOSE:
mCSDCloseButton = true;
pos = &mCSDCloseButtonPosition;
break;
default:
break;
}


复制
if (pos) {
  *pos = i;
}
}

实现该功能并给出建议，修改

Claude-3.5-Sonnet的机器人图片
Claude-3.5-Sonnet

Poe
基于Emilio的建议和现有代码，我们可以在 nsLookAndFeel::InitializeGlobalSettings() 函数中添加对高对比度设置的支持。以下是修改后的代码和相关建议：

cpp

复制
void nsLookAndFeel::InitializeGlobalSettings() {
  GtkSettings* settings = gtk_settings_get_default();

  // 现有代码...

  // 添加高对比度设置支持
  mPrefersContrastSetting = GetHighContrastSetting();

  // 使用新的高对比度设置，如果无法获取，则回退到系统主题设置
  mSystemTheme.mHighContrast = mPrefersContrastSetting.valueOr(mSystemTheme.mHighContrast);

  // 其余现有代码...
}

// 新增函数来获取高对比度设置
Maybe<bool> nsLookAndFeel::GetHighContrastSetting() {
  GVariant* value = g_dbus_proxy_get_cached_property(
      gProxyAppearance, "high-contrast");
  if (!value) {
    return Nothing();
  }

  gboolean highContrast = g_variant_get_boolean(value);
  g_variant_unref(value);

  return Some(highContrast);
}
建议：

添加新的成员变量 mPrefersContrastSetting：
在 nsLookAndFeel 类中添加一个新的 Maybe<bool> 类型的成员变量，用于存储高对比度设置。
实现 GetHighContrastSetting() 函数：
这个函数使用 D-Bus 接口从 xdg-desktop-portal 获取高对比度设置。如果无法获取设置，返回 Nothing()。
在 InitializeGlobalSettings() 中使用新设置：
调用 GetHighContrastSetting() 获取设置，然后更新 mSystemTheme.mHighContrast。
更新相关的 UI 代码：
在使用高对比度设置的地方，优先使用 mPrefersContrastSetting，如果它没有值，再使用 mSystemTheme.mHighContrast。
添加监听机制：
实现一个机制来监听高对比度设置的变化，当设置变化时更新 UI。
更新文档和注释：
为新添加的代码添加适当的注释和文档，解释高对比度设置的用途和工作原理。
添加单元测试：
为新添加的功能编写单元测试，确保它能正确地获取和应用高对比度设置。
这些修改将使 Firefox 能够支持新的 xdg-desktop-portal 高对比度设置标准，同时保持与现有系统主题设置的兼容性。

$env:MOZ_JITSPEW_LEVEL="1"

$env:MOZ_LOG="timestamp,rotate:200,nsHttp:5,cache2:5,nsSocketTransport:5,nsHostResolver:5"

$env:MOZ_JITSPEW_CHANNEL="RegAlloc"

$env:MOZ_JITSPEW_CHANNEL="RegAlloc"
python .\mach run bilibili.com

$env:MOZ_LOG="example_logger:3"
python .\mach run bilibili.com

https://bugzilla.mozilla.org/show_bug.cgi?id=790194
这是一个关于在Mozilla Firefox代码库中替换一些字符串转数字函数的bug。主要内容如下:

最初的问题是要替换atoi()函数,因为它没有错误检查。
后来发现strtol()/strtoul()也不安全,因为它们受locale影响。
提议使用glib的g_ascii_strtoll()等函数,但这些函数在Windows等平台上不可用。
考虑使用PR_sscanf()作为替代,因为它不受locale影响。
但PR_sscanf()也有问题:缺乏格式字符串检查,依赖NSPR库。
另一个建议是使用strtol_l()等支持明确locale的函数,但它们可能不是所有平台都支持。
最终的方案似乎是创建包装函数,内部使用PR_sscanf()来解析数字,以替换atoi/strtol/strtoul的使用。
代码位置从media/webrtc/signaling移动到了dom/media/webrtc。
最后有人质疑PR_sscanf是否真的locale无关,因为它内部使用了isspace/isdigit等函数。
核心问题是要找到一个安全、跨平台、不受locale影响的字符串转数字函数来替换现有的atoi/strtol/strtoul。这个问题比预想的要复杂,需要权衡各种因素。

Bug 1841061 - Remove network.compress.allow_truncated_empty_brotli pref r?gregp

Bug 1913213 - Remove unused nsDisplayListBuilder::SubtractFromVisibleRegion r?gregp


https://bugzilla.mozilla.org/show_bug.cgi?id=1437885
问题描述:
在Windows系统上,当操作系统级别的位置服务被关闭时,Firefox浏览器中使用位置权限的扩展会反复弹出请求启用位置服务的对话框。
原因分析:
Firefox使用Windows的原生位置API来获取位置信息。
当位置服务关闭时,Windows API会返回错误,但Firefox没有正确处理这个错误状态。
Firefox没有记住用户拒绝位置请求的决定,导致重复弹出对话框。
解决思路:
在WindowsLocationProvider类中添加一个布尔标志,用来记录用户是否已经拒绝了位置请求。
修改WindowsLocationProvider::Startup()方法,检查Windows API返回的错误码。
如果返回ERROR_ACCESS_DENIED,说明位置服务被禁用,设置标志并避免再次调用RequestPermissions。
在后续的位置请求中,先检查这个标志,如果已被拒绝就直接返回,不再弹出对话框。
具体实现:
在WindowsLocationProvider类中添加bool成员变量mDenied。
在Startup()方法中,调用RequestPermissions后检查返回值:
cpp

复制
if (FAILED(location->RequestPermissions(...))) {
  if (GetLastError() == ERROR_ACCESS_DENIED) {
    mDenied = true;
    return NS_ERROR_FAILURE;
  }
}
在Startup()方法开始处添加检查:
cpp

复制
if (mDenied) {
  return NS_ERROR_FAILURE;
}
后续优化:
考虑使用GetReportStatus来获取当前状态,以适应用户可能在系统设置中启用位置服务的情况。
如果GetReportStatus返回REPORT_ACCESS_DENIED等错误状态,可以考虑切换到MLS(Mozilla Location Service)作为备选。
最新进展:
根据最近的评论,这个问题可能已经在新版本的Windows和Firefox中得到了改善或修复。建议在最新的Windows 11和Firefox版本上重新验证这个问题是否仍然存在。

https://bugzilla.mozilla.org/show_bug.cgi?id=943410
这个bug讨论了在JavaScript引擎IonMonkey中改进无符号除法和取模操作的范围分析优化。主要过程如下:

最初的目标是使用范围分析来消除不必要的bailout(回退到解释器执行)。
讨论集中在改进MDiv(除法指令)的fallible()方法,使其更精确地判断何时需要bailout。
分析了代码生成器中导致bailout的各种条件,总结为几种情况。
提出了为MDiv添加专门的fallible检查方法的方案:
fallibleDivU()
fallibleDivPowTwoI()
fallibleDivConstantI()
fallibleDivI()
实现了这些专门的fallible方法,并修改了Lowering阶段对应的调用。
提交patch进行try测试,发现很多测试用例失败。
分析失败原因,发现与寄存器分配器的选择有关,导致fallible检查没有按预期执行。
继续分析其他失败用例,寻找共同问题。
核心的改动是在MDiv类中添加了更精细的fallible判断,以减少不必要的bailout,提高JIT代码的效率。但实际执行中遇到了一些意外情况,需要进一步分析和调整。

这个讨论展示了JIT编译器优化的复杂性,以及如何通过静态分析来改进动态执行性能

Bug 1898653 Remove layout.css.inline-style-caching.always-enabled pref r?emilio

Bug 1906157 - Use AsyncPanZoomController::ToCSSPixel in more places r?ajakobi


python ./mach lint -l clippy toolkit/components/glean/api/src/ -W -v

python.exe ./mach lint --warnings

Bug 1900643 Remove unused variable `purgedSiteHosts` in BounceTrackingProtection.cpp r?manuel



Bug 1911935 - Remove network.IDN_show_punycode pref r?gregp

python ./mach lint --ongoing

Bug 1886716 - Remove reference to nonexistent nsIPointerEvent.idl


Bug 1853548 - Remove dom.no_unknown_protocol_error.enabled pref


git diff-tree -p c9e2aa1002d8

Bug 1842458 - Remove dom.window.event.enabled pref r?gregp


git branch -D window-event
git branch -d window-event

git pull --rebase

./mach static-analysis check --outgoing

Bug 1892347 - Remove nsIDOMWindowUtils.isPartOfOpaqueLayer r?gregp


Bug 1895391 - Remove widget.non-native-theme.solid-outline-style pref

./mach lint --fix
./mach build

https://codepen.io/juliemoynat/pen/PoRYWoN

hg pull central --rebase

hg pull --rebase

moz-phab submit --no-wip

./mach clobber

hg strip --keep -r . # --keep optional
hg update --clean    # reset to last commit

hg pull central
hg up central

moz-phab submit

./mach lint --fix

Bug 1895530 - Remove security.allow_disjointed_external_uri_loads pref

hg commit
hg revert js/src/jit/ExecutableAllocator.cpp

./mach try auto


hg diff
hg remove -f

Bug 1868293 - Fix clippy warnings in glean-ffi r=sylvestre

./mach lint modules/libpref/init/StaticPrefList.yaml -W -v
./mach lint uriloader/exthandler/nsExternalHelperAppService.cpp -W -v

this->mContentType->mData

export MOZ_LOG="example_logger:3"

nsUnknownDecoder::LastDitchSniff

RUST_LOG="debug" ./mach run --debugger=gdb /home/tannal/tannalwork/cans/baseline.html


```
$env:RUST_LOG="debug"

hg pull && hg update

```

# inbox

sudo perf record --call-graph dwarf -F 99 -p 182782 -g -- sleep 30
sudo perf script > ./graph/out.firefoxgpustacks01
./stackcollapse-perf.pl < ./graph/out.firefoxgpustacks01 | ./flamegraph.pl > ./graph/out.firefoxgpustacks01.svg

# setup

cargo install --git https://github.com/glandium/git-cinnabar
git cinnabar setup


git clone hg::https://hg.mozilla.org/mozilla-unified gecko && cd gecko
git config fetch.prune true
git cinnabar fetch --tags

mv .git/hooks/fsmonitor-watchman.sample .git/hooks/query-watchman
git config core.fsmonitor .git/hooks/query-watchman

```bash

sudo apt-get install curl python3 python3-pip
python3 -m pip install --user mercurial
curl https://hg.mozilla.org/mozilla-central/raw-file/default/python/mozboot/bin/bootstrap.py -O
python3 bootstrap.py

cd mozilla-unified
hg up -C central

./mach build
./mach ide vscode

./mach build-backend -b CompileDB

./mach build-backend --backend=CompileDB
./obj-x86_64-pc-linux-gnu/clangd/compile_commands.json

find . -name compile_commands.json

ln -s ./obj-x86_64-pc-linux-gnu/clangd/compile_commands.json compile_commands.json

RUST_LOG="debug" obj-x86_64-unknown-linux-gnu/dist/bin/firefox -no-remote -P
RUST_LOG="debug" obj-x86_64-pc-windows-msvc/dist/bin/firefox -no-remote -P

```


# people

Gecko (Mozilla的渲染引擎):

Robert O'Callahan
Gecko的长期核心开发者
已离开Mozilla，创立了rr调试工具项目
Boris Zbarsky
Gecko核心开发者
仍在Mozilla工作
Emilio Cobos Álvarez
Gecko核心开发者，专注于CSS引擎
仍在Mozilla工作
新成员：

Camillo Bruni (V8)
Luca Casonato (V8, Deno)
Nicolò Ribaudo (Babel, 与多个JS引擎有交互)
Shu-yu Guo (V8, TC39成员)
Keith Miller (WebKit)
Kagami Sascha Rosylight (SpiderMonkey)

SpiderMonkey (Mozilla的JavaScript引擎):
Brendan Eich
JavaScript语言的创造者，SpiderMonkey的原始作者
已离开Mozilla，创立了Brave Software
Luke Wagner
SpiderMonkey核心开发者，WebAssembly的主要贡献者
仍在Mozilla工作
Jan de Mooij
SpiderMonkey性能优化专家
仍在Mozilla工作

spidermonkey
involves:ptomato
involves:moztcampbell
involves:hotsphink
involves:xry111
involves:arai-a
involves:yurydelendik
involves:mgaudet
involves:tynopex
involves:evilpie
involves:jandem
involves:sagudev

involves:ehsan
involves:gregorypappas
involves:emilio

# inbox


spidermonkey
export MOZCONFIG=$HOME/mozconfigs/debug

webrender issue tracker
https://bugzilla.mozilla.org/buglist.cgi?product=Core&component=Graphics%3A%20WebRender&resolution=---


servo crates that firefox use
webrender
glean
html5ever
freetype
stylo
https://github.com/servo/rust-url
https://github.com/servo/euclid


b nsRetrievalContextX11::WaitForClipboardData

b /home/tannal/tannalwork/projects/mozilla-unified/widget/gtk/nsClipboard.cpp:606

b nsRetrievalContextX11::GetClipboardText



https://bugs.eclipse.org/bugs/show_bug.cgi?id=528691

RUST_LOG="debug" ./mach run --debugger=gdb translate.google.com


RUST_LOG="debug" ./mach wpt --debugger=gdb ./testing/web-platform/tests/css/CSS2/cascade/inherit-computed-001.html
RUST_LOG="debug" ./mach wpt ./testing/web-platform/tests/css/CSS2/cascade/inherit-computed-001.html


The Firefox layout team


spidermonkey team
https://github.com/mozilla-spidermonkey
gfx team
https://mozillagfx.wordpress.com/

gecko layout team meeting notes https://docs.google.com/document/d/1BbKGHgmDjD87f6Dt4mMXrZysch5END7AoCIY1cwGSdY/edit

 ./mach run -- -layoutdebug -no-remote.

https://groups.google.com/

sylvestre

involves:flackr chromium compositor owner https://philiprogers.com/resume.html


moz-phab

./mach install-moz-phab

hg uncommit

hg rollback

./mach lint toolkit/components/glean/api/src/ffi/event.rs


./mach lint -l clippy toolkit/components/glean/api/src/ -W -v



  b'finish_task_switch.isra.0'
  b'schedule'
  b'futex_wait_queue'
  b'futex_wait'
  b'do_futex'
  b'__x64_sys_futex'
  b'do_syscall_64'
  b'entry_SYSCALL_64_after_hwframe'
  b'__GI___lll_lock_wait'
  b'mozilla::UniquePtr<js::jit::InliningRoot, JS::DeletePolicy<js::jit::InliningRoot> >::reset(js::jit::InliningRoot*)'
  b'js::jit::JitScript::~JitScript()'
  b'JSScript::releaseJitScript(JS::GCContext*)'
  b'JS::Zone::forceDiscardJitCode(JS::GCContext*, JS::Zone::DiscardOptions const&)'
  b'js::gc::GCRuntime::discardJITCodeForGC()'
  b'js::gc::GCRuntime::endPreparePhase(JS::GCReason)'
  b'js::gc::GCRuntime::incrementalSlice(js::SliceBudget&, JS::GCReason, bool)'
  b'js::gc::GCRuntime::gcCycle(bool, js::SliceBudget const&, JS::GCReason)'
  b'js::gc::GCRuntime::collect(bool, js::SliceBudget const&, JS::GCReason)'
  b'GarbageCollectImpl(JS::GCReason, nsJSContext::IsShrinking, js::SliceBudget const&)'
  b'nsJSContext::RunIncrementalGCSlice(JS::GCReason, nsJSContext::IsShrinking, js::SliceBudget&)'
  b'mozilla::CCGCScheduler::GCRunnerFiredDoGC(mozilla::TimeStamp, mozilla::GCRunnerStep const&)'
  b'mozilla::CCGCScheduler::GCRunnerFired(mozilla::TimeStamp)'
  b'mozilla::IdleTaskRunner::Run()'
  b'mozilla::IdleTaskRunnerTask::Run()'
  b'mozilla::TaskController::DoExecuteNextTaskOnlyMainThreadInternal(mozilla::detail::BaseAutoLock<mozilla::Mutex&> const&)'
  b'mozilla::TaskController::ExecuteNextTaskOnlyMainThreadInternal(mozilla::detail::BaseAutoLock<mozilla::Mutex&> const&)'
  b'mozilla::TaskController::ProcessPendingMTTask(bool)'
  b'mozilla::detail::RunnableFunction<mozilla::TaskController::TaskController()::$_0>::Run()'
  b'nsThread::ProcessNextEvent(bool, bool*)'
  b'NS_ProcessNextEvent(nsIThread*, bool)'
  b'mozilla::ipc::MessagePump::Run(base::MessagePump::Delegate*)'
  b'MessageLoop::Run()'
  b'nsBaseAppShell::Run()'
  b'nsAppShell::Run()'
  b'nsAppStartup::Run()'
  b'XREMain::XRE_mainRun()'
  b'XREMain::XRE_main(int, char**, mozilla::BootstrapConfig const&)'
  b'XRE_main(int, char**, mozilla::BootstrapConfig const&)'
  b'main'
  b'__libc_start_call_main'

sudo stackcount-bpfcc -i 2 -p 152169 --debug "*switch*"

nsHtml5Tokenizer::tokenizeBuffer

nsHtml5AttributeName
nsHtml5String

b nsHtml5Tokenizer.cpp:906


gdb /home/tannal/tannalwork/projects/mozilla-unified/obj-x86_64-pc-linux-gnu/dist/bin/firefox

set MOZ_LOG="example_logger:3"
export MOZ_LOG="example_logger:3"
$env:MOZ_LOG="example_logger:3"
MOZ_LOG="example_logger:3" ./mach run

parser
 mTreeBuilder
  tokenizer

nsLayoutUtils::PaintFrame

PR_Sleep(PR_MillisecondsToInterval(1));


b nsHtml5StreamParser::DoDataAvailableBuffer

handle all nostop

 : public Runnable

b nsHtml5StreamParser::OnDataAvailable
parser/html/nsHtml5StreamParser.cpp

set follow-fork-mode child

b DrainDirectTasks thread 13
break locspec thread thread-id

b nsHtml5Parser.cpp:311
b nsThread.cpp:1137
b nsSocketTransport2.cpp:394

./mach clobber

https://github.com/mozilla/gecko-dev/commits?author=cathiechen


https://hg.mozilla.org/mozilla-central/rev/dd251ff8689542fbefadb663a6dfc26afb21b02f

  b'__libc_pwrite'
  b'(anonymous namespace)::BaseWrite(sqlite3_file*, void const*, int, long long)'
  b'walWriteOneFrame'
  b'pagerWalFrames'
  b'sqlite3PagerCommitPhaseOne'
  b'sqlite3BtreeCommitPhaseOne'
  b'vdbeCommit'
  b'sqlite3VdbeHalt'
  b'sqlite3VdbeExec'
  b'sqlite3_step'
  b'mozilla::storage::Connection::stepStatement(sqlite3*, sqlite3_stmt*)'
  b'mozilla::storage::AsyncExecuteStatements::executeStatement(mozilla::storage::StatementData&)'
  b'mozilla::storage::AsyncExecuteStatements::executeAndProcessStatement(mozilla::storage::StatementData&, bool)'
  b'mozilla::storage::AsyncExecuteStatements::Run()'
  b'nsThread::ProcessNextEvent(bool, bool*)'
  b'NS_ProcessNextEvent(nsIThread*, bool)'
  b'mozilla::ipc::MessagePumpForNonMainThreads::Run(base::MessagePump::Delegate*)'
  b'MessageLoop::Run()'
  b'nsThread::ThreadFunc(void*)'
  b'_pt_root'
  b'set_alt_signal_stack_and_start(PthreadCreateParams*)'
  b'start_thread'

  b'entry_SYSCALL_64_after_hwframe'
  b'__xstat64'
  b'unixClose'
  b'(anonymous namespace)::QuotaClose(sqlite3_file*)'
  b'sqlite3PagerClose'
  b'sqlite3BtreeClose'
  b'sqlite3LeaveMutexAndCloseZombie'
  b'sqlite3Close'
  b'mozilla::storage::Connection::internalClose(sqlite3*)'
  b'mozilla::dom::quota::CachingDatabaseConnection::Close()'
  b'mozilla::dom::indexedDB::(anonymous namespace)::ConnectionPool::CloseConnectionRunnable::Run()'
  b'nsThread::ProcessNextEvent(bool, bool*)'
  b'NS_ProcessNextEvent(nsIThread*, bool)'
  b'mozilla::dom::indexedDB::(anonymous namespace)::ConnectionPool::ThreadRunnable::Run()'
  b'nsThread::ProcessNextEvent(bool, bool*)'
  b'NS_ProcessNextEvent(nsIThread*, bool)'
  b'mozilla::ipc::MessagePumpForNonMainThreads::Run(base::MessagePump::Delegate*)'
  b'MessageLoop::Run()'
  b'nsThread::ThreadFunc(void*)'
  b'_pt_root'
  b'set_alt_signal_stack_and_start(PthreadCreateParams*)'
  b'start_thread'

sudo stackcount-bpfcc -i 2 -p 152169 --debug "*amdgpu*"
sudo stackcount-bpfcc -i 2 -p 152169 --debug "*tcp_recv*"

sudo stackcount-bpfcc -p 152169 --debug "*tcp_connect*"

info proc
shell ls /proc/134785/fd/ -l
head -n 1 /proc/134785/net/tcp; grep 526689 /proc/134785/net/tcp

./mach run --debug

PR_Sleep(PR_SecondsToInterval(10));

nsHtml5Parser

mk_add_options AUTOCLOBBER=1
vim mozconfig

touch /home/tannal/tannalwork/projects/mozilla-unified/obj-x86_64-pc-linux-gnu/CLOBBER

https://github.com/mozilla/gecko-dev/commits?author=emilio

https://github.com/mozilla/gecko-dev/commits?author=tiaanl

65:42.06 If you are building Firefox often, SCCache can save you a lot of time. You can learn more h
ere: https://firefox-source-docs.mozilla.org/setup/configuring_build_options.html#sccache
To take your build for a test drive, run: |mach run|
For more information on what to do now, see https://firefox-source-docs.mozilla.org/setup/contributi
ng_code.html

Make use of Cargo dependencies, but vendor them in monorepo.

Continuous integration can't rely on external network.

Benjamin Smedberg

https://www.joshmatthews.net/fosdem/#slide-7

#developers - high traffic, general Gecko-related development
#jsapi - JavaScript engine development
#gfx - graphics/rendering discussion
#content - DOM implementation
#fx-team - Firefox frontend development
#necko - Networking stack development
#mobile - Firefox for Android development
#b2g - Firefox OS development

# Get the code, build, run, debug, logging, lsp

firefox use mercurial instead of git for versioning control.

# community

https://groups.google.com/a/mozilla.org/g/dev-platform/c/wAomN2An7NQ

https://groups.google.com/a/mozilla.org/g/firefox-dev

https://chat.mozilla.org/#/room/#introduction:mozilla.org

https://codetribute.mozilla.org/projects/devtools

https://nnethercote.github.io/about-me.html

https://blog.mozilla.org/javascript/

# reference

https://colin-cazabet.medium.com/how-to-start-contributing-to-firefox-ebad014d9f1

# config

```bash
# 启用调试模式
ac_add_options --enable-debug

# 禁用优化，以便更容易调试
ac_add_options --disable-optimize

# 启用地址消毒（Address Sanitizer）以检测内存错误
ac_add_options --enable-address-sanitizer

# 启用 Gecko 特定的开发工具
ac_add_options --enable-application=browser
ac_add_options --enable-tests

# 使用 clang 编译器（如果可用）
export CC=clang
export CXX=clang++

# 启用 artifact 构建，加快构建速度（可选，但会限制某些更改）
# ac_add_options --enable-artifact-builds

# 设置输出目录
mk_add_options MOZ_OBJDIR=./objdir-gecko

# 启用额外的警告
ac_add_options --enable-warnings-as-errors

# 启用 DevTools 调试
ac_add_options --enable-devtools
```


# tokei

tannal@desktop:~/tannalwork/projects/gecko$ tokei .
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Language            Files        Lines         Code     Comments       Blanks
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 AWK                     3          307          247            6           54
 Assembly              319       294407       259422        15814        19171
 GNU Style Assembly    254       204865       172240        12394        20231
 Autoconf              393        47881        35545         6076         6260
 Automake               14         3299         2877          202          220
 BASH                   28         2437         1659          472          306
 Batch                  44         2840         2200          205          435
 Bazel                  55        14004        12181          832          991
 Bitbake               282       227988       223745         1956         2287
 C                    4315      3736309      2775941       590452       369916
 C Header            19312      4702066      2936121      1151842       614103
 CMake                 157        30269        22970         4259         3040
 C#                     20         4545         3844          231          470
 CoffeeScript            2           24           13            4            7
 C++                 14407      7181908      5459275       794260       928373
 C++ Header           1081       258972       202772        29426        26774
 CSS                  1750       186907       145334        16455        25118
 Cython                 13         3553         2975          190          388
 D                       1           34            8           22            4
 Dockerfile             73         2371         1691          267          413
 Emacs Lisp              2          338          258           38           42
 Elixir                  1           43            6           37            0
 Elm                     2          542          399           32          111
 Forge Config          117        20889        15335         4120         1434
 FreeMarker            246        23931        19439            0         4492
 F*                      2          589          589            0            0
 Gherkin (Cucumber)      1            9            6            0            3
 GLSL                 1537        58189        36240        10982        10967
 Go                      2          501          326          112           63
 Handlebars             12          100          100            0            0
 Happy                   2         2650         2267            0          383
 HLSL                    2          348          203           76           69
 INI                 25800       609244       418460          415       190369
 Java                 1041       280896       183574        68794        28528
 JavaScript          93619     10678651      7396961      2146313      1135377
 JSON                 2524      2634104      2633163            0          941
 JSX                   234        34076        29603         1393         3080
 Kotlin               4175       664471       503417        70410        90644
 Korn shell              5          774          523          169           82
 LLVM                    1          793          772            0           21
 LD Script               3           27           13           12            2
 M4                     47        32404        23387         6565         2452
 Makefile              466        37475        19626        10571         7278
 Meson                  18         4427         3455          423          549
 Metal Shading Lan|      9          836          509          156          171
 Module-Definition      57        25091        23230         1555          306
 MSBuild                10          577          426          139           12
 Nix                     4           79           75            0            4
 Objective-C           112        13611        10147         1221         2243
 Objective-C++         357        91872        67088        10612        14172
 OpenType Feature |      1         3834         3110            1          723
 Pan                     2           26           16            2            8
 Pascal                  1          126           98           13           15
 Perl                   56        16692        12089         2231         2372
 PHP                     2          864          440          284          140
 PowerShell              3          218          197            5           16
 Prolog                118         2605         2225            0          380
 Protocol Buffers       43         7057         2921         3035         1101
 Python               9383      2025039      1622702       126201       276136
 R                       1           38           12           18            8
 Rusty Object Nota|      3           57           57            0            0
 RPM Specfile            3          217          153           18           46
 ReScript               15         2264         1916          345            3
 ReStructuredText     2170       339105       251381            0        87724
 Ruby                   21         1674         1194          137          343
 Sass                   82        14602        11699          628         2275
 Scons                   1           25           18            1            6
 Shell                 686        92853        65196        15810        11847
 SQL                     3          180           64           84           32
 Stylus                  1            7            5            0            2
 SVG                  5249       185678       157855        19727         8096
 Swift                  46         2481         1917          210          354
 SWIG                    3         1720         1362           77          281
 TeX                     1        11727         7205         3708          814
 Plain Text           5661      4567341            0      4505712        61629
 TOML                 2360       173378       130017         8831        34530
 TSX                     1           41           21            9           11
 TypeScript           1641       437312       351359        49924        36029
 VB6                    13          151          150            0            1
 Visual Studio Pro|     51        17648        17447          201            0
 Visual Studio Sol|     18         1494         1481            0           13
 WebGPU Shader Lan|      8          231          202            0           29
 WebAssembly            55           78           75            0            3
 XSL                    25          624          527           18           79
 Xcode Config            3          118           21           88            9
 XML                  6715       920576       621423       226742        72411
 YAML                 2226       490658       467191        10856        12611
───────────────────────────────────────────────────────────────────────────────
 HTML                97593      2431754      2132587       125315       173852
 |- CSS              37634       520642       475989        11928        32725
 |- HTML               307         3928         3866           28           34
 |- JavaScript       49783      2193531      1787897       154303       251331
 |- JSON                 1            1            1            0            0
 |- Plain Text          13          202            0          191           11
 (Total)                        5150058      4400340       291765       457953
───────────────────────────────────────────────────────────────────────────────
 Markdown             2155       220542            0       159436        61106
 |- BASH                80          590          522           46           22
 |- C                    4          293          197           52           44
 |- CMake                7          121           84           23           14
 |- C++                  4          105           82           14            9
 |- CSS                 10          366          290           64           12
 |- GLSL                 1           63           62            1            0
 |- Groovy             102          160          152            5            3
 |- HTML                35          710          668           20           22
 |- INI                  7           33           31            0            2
 |- Java                 8          140          113           18            9
 |- JavaScript          31         103 8          782          170           86
 |- JSON                56         1639         1635            0            4
 |- Kotlin              58         3150         2294          547          309
 |- Markdown             2           16            0           12            4
 |- Python              20          386          318           24           44
 |- Ruby                 1            3            3            0            0
 |- Rust               272         9597         7677          722         1198
 |- Shell               37          280          259           12            9
 |- Swift                2           27           26            0            1
 |- TOML               160          642          531           80           31
 |- TypeScript           2           11           10            1            0
 |- XML                 16          194          152           24           18
 |- YAML                11          456          448            5            3
 (Total)                         240562        16336       161276        62950
───────────────────────────────────────────────────────────────────────────────
 Rust                11307      4054727      3552072       185719       316936
 |- Markdown          6394       482053        23247       364900        93906
 (Total)                        4536780      3575319       550619       410842
───────────────────────────────────────────────────────────────────────────────
 Svelte                  4           65           54            2            9
 |- JavaScript           4          109           87            0           22
 (Total)                            174          141            2           31
───────────────────────────────────────────────────────────────────────────────
 Vue                    44          205          166            0           39
 |- CSS                  1            3            3            0            0
 |- HTML                44          502          491            6            5
 |- JavaScript          34          743          693           16           34
 (Total)                           1453         1353           22           78
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Total              320705     51370289     35377892     10938110      5054287
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
