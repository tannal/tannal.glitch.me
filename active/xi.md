

# History

- 作者: Bill Atkinson (1980s)
- 故事:
  - 是 Apple Lisa 和早期 Mac 的核心图形系统
  - Atkinson 在一次车祸后卧床时构思了许多算法
  - 创新性地使用了区域裁剪和快速填充算法
  - 影响了后来的许多图形系统设计

- 核心人物: Charles Simonyi
- 发展:
  - Windows 1.0 开始就存在的基础图形系统
  - 从简单的线条绘制发展到复杂的字体渲染
  - GDI+ 是其面向对象的升级版
  - 直到 Windows 7 仍然是主要的 2D 渲染系统

- 关键人物: Bob Scheifler, Jim Gettys
- 特点:
  - 1984年 MIT 开发
  - 网络透明的设计理念
  - 客户端/服务器架构
  - Xlib 成为标准绘图库

- 创始人: John Warnock, Chuck Geschke
- 历史:
  - 1982年从 Xerox PARC 离职创建 Adobe
  - PostScript 革命性地改变了打印行业
  - 引入了矢量图形和字体技术
  - 后来发展出 PDF 格式

1. QuickDraw 的诞生
- Atkinson 在车祸康复期间，用纸笔设计了核心算法
- 为了优化性能，他手写了大量 68000 汇编代码
- 最终让 Mac 128K 实现了流畅的图形界面

2. PostScript 的起源
- Warnock 在施乐期间开发了 InterPress
- 施乐不愿意将其商业化
- 这促使他创建 Adobe 并开发 PostScript

3. X Window 的发展
- 最初是 MIT 的一个学生项目
- 因其网络透明性，迅速成为 Unix 图形标准
- 带来了远程显示等创新概念


1. 传统层
   - GDI/GDI+ (仍然保留向后兼容)
   - DirectX 9/10/11

2. 现代层
   - DirectX 12
   - DirectComposition
   - Windows.UI.Composition
   - DXGI (DirectX Graphics Infrastructure)

3. 混合系统
   - DWM (Desktop Window Manager)
   - 硬件加速的合成器

主流选择：
- Web 领域：几乎被 Skia 统治
- 移动端：Skia (Android) + Core Graphics (iOS)
- 桌面：Direct2D (Windows) + Skia/Cairo (Linux) + Core Graphics (macOS)

发展趋势：
- GPU 加速成为标配
- 跨平台需求增加
- 性能要求提高
- API 简化和现代化

# Xilem

architecture - 架构设计相关
masonry - Masonry 部件层相关
web - Web 相关功能

# Parley

#[derive(Default)]
pub struct Editor {
    font_cx: FontContext,
    layout_cx: LayoutContext<Color>,
    editor: PlainEditor<Color>,
    last_click_time: Option<Instant>,
    click_count: u32,
    pointer_down: bool,
    cursor_pos: (f32, f32),
    cursor_blink: bool,
    modifiers: Option<Modifiers>,
}

wgpu -> vello
peniko
winit
parley

Vello is a 2d graphics rendering engine written in Rust, using wgpu.

It efficiently draws large 2d scenes with interactive or near-interactive performance.



PlainEditor
    |
    +-- Buffer (String)
    |
    +-- Layout
    |   +-- Lines
    |   +-- Properties
    |
    +-- Selection
        +-- Position (anchor)
        +-- Position (focus)

- druid (被 xilem 替代?)
  - 老的 UI 框架
  - xilem 是新的实验性 UI 框架

- druid-widget-nursery
  - druid 的组件库
  - 随着 druid 可能被替代而停滞

- svgtypes (SVG类型解析)
- resvg (SVG渲染库)
- resvg-test-suite (测试套件)

css color

jetpack compose

# AccessKit

# Xilem WGPU vello

Daniel McNab

# Xilem Widge Tree & examples

Olivier Faure

masonry

# inbox

resvg rerun graphie.rs typst egui

kurbo peniko winit vello

Aaron Muir Hamilton parley text input IME Android

GPU infrastructure and performance wgpu

Matt Campbell accessibility

Olivier Faure widget tree developer experience

cargo install --git https://github.com/rust-mobile/cargo-apk

cargo run -p headless

cargo run --example run_on_demand
h
cargo run

cargo search cargo-apk

https://github.com/linebender/xilem

https://www.youtube.com/watch?v=521NfGf7AR0

browser and ui/toolkit flutter swiftui

Masonry

com

Xilem
swiftui/flutter engine


# vello

Subject: Potential for Vello to Support Animation Engines like Manim

Dear Vello Community,

I've been following the development of Vello with great interest, and I'm impressed by its potential as a high-performance GPU-accelerated 2D renderer. I'd like to propose an idea for discussion: the possibility of Vello supporting functionality similar to that required by animation engines like Manim.

Currently, Manim uses Cairo for 2D rendering and OpenGL for 3D rendering. Two key components in Manim's rendering process are:

1. Camera: Responsible for converting scenes into images
2. SceneFileWriter: Writes rendered frames into video files

Given Vello's capabilities, I believe it could potentially replace or complement these functionalities, particularly for 2D rendering. This could offer several advantages:

- Improved performance through GPU acceleration
- Potential for real-time rendering of complex scenes
- Modernized API design that could simplify integration

While Vello is primarily focused on 2D rendering, its high performance could potentially allow for more complex animations and effects that are currently challenging with traditional 2D renderers.

Some questions for consideration:

1. Is it feasible for Vello to implement a Camera-like functionality for scene-to-image conversion?
2. Could Vello be extended to support frame generation for video output, perhaps in conjunction with a video encoding library?
3. Are there any plans or interest in supporting animation-specific features that could benefit engines like Manim?

I believe this could open up exciting possibilities for Vello in the realm of programmatic animation and educational content creation.

Thank you for your time and consideration. I look forward to any thoughts or feedback on this idea.

Best regards,
[Your Name]

Vello
skia
2d rendering on gpu based on wgpu
wgpu

cargo run -p with_winit -- --test-scenes

cargo fmt --all --check

cargo run --package with_winit --bin with_winit
cargo run --package simple --bin simple


Text

Parley

text layout

AccessKit

核心概念:
稀疏条带是下一代GPU路径渲染技术
目标是提高性能并提供更好的系统集成灵活性
是实现无冲突合成的关键步骤
基本原理:
生成小型瓦片(tiles)
对瓦片进行排序
基于"边界片段合并"进行渲染操作
结果是路径的游程压缩渲染,包含边界的所有灰度抗锯齿像素,但稀疏表示实心区域
主要过程:
a. 生成小型瓦片
b. 瓦片排序
c. 边界片段合并渲染
d. 输出稀疏条带表示
优势:
比现有Vello渲染器更模块化
中间结果(渲染路径)有明确高效的表示
预期性能更好
可以保留渲染路径,实现跨场景重用
更适合字形缓存,尤其是大尺寸字形
里程碑:
研究原型验证基本假设
集成到现有Vello管道
实现MSAA
重做粗光栅化
性能优化方向:
改进排序算法
调整瓦片大小
使用弧形基元
利用子组(subgroups)操作
挑战与风险:
实现难度较大
需要大量工作
排序性能关键

# dev

Xerox PARC 时期 (1970s)
在Xerox PARC，Alan Kay领导的团队开发了第一个图形用户界面系统
Butler Lampson和Charles Simonyi开发了Bravo，这是第一个所见即所得的文字处理器
John Warnock在PARC工作时开发了InterPress打印协议
Bob Sproull和William Newman写了《Principles of Interactive Computer Graphics》，奠定了计算机图形学基础
Adobe的诞生 (1982)
John Warnock和Charles Geschke离开PARC创建Adobe
开发了PostScript语言，这是现代2D图形系统的基础
PostScript是一种堆栈式编程语言，受Forth语言影响
引入了贝塞尔曲线、字体轮廓等关键概念
Apple的贡献
1984年的Macintosh是首个大规模采用图形界面的个人电脑
QuickDraw由Bill Atkinson开发，是早期Mac的核心图形系统
后来发展出Core Graphics (Quartz)
Display PostScript合作项目(与Adobe)
现代发展
PDF格式(1993)：由Adobe开发，基于PostScript但更简化
SVG(2001)：W3C标准，XML描述的矢量图形
Canvas：HTML5引入，提供即时模式绘图API
Skia：Google开发，用于Chrome和Android
Direct2D：微软的现代2D图形API
关键概念的演变：
图形原语
路径(Path)
填充(Fill)
描边(Stroke)
变换(Transform)
剪切(Clip)
渲染模型
从打印机的页面描述语言
到屏幕显示的光栅化
再到GPU加速渲染
API设计范式
PostScript的堆栈模型
即时模式 vs 保留模式
声明式 vs 命令式
状态机模型
这些历史遗产在现代API中仍然可见：
Canvas API与PostScript很相似
SVG保留了许多PostScript概念
现代框架如Skia虽然使用新技术，但基本概念变化不大
影响：
标准化
图形原语的标准化
文件格式的标准化(PDF, SVG)
API设计模式的标准化
性能优化
从CPU到GPU
矢量到光栅的优化
缓存策略
跨平台
Web标准的统一
移动平台的兴起
新显示技术(高DPI等)
这个历史告诉我们：
好的设计经得起时间考验
标准化对生态系统很重要
性能和易用性需要平衡
跨平台是持续的挑战

# animation


对，我就对这个感兴趣，
Manim使用Cairo图形库进行2D渲染，使用OpenGL进行3D渲染。

关键组件：

Camera: 负责将场景转换为图像
SceneFileWriter: 将渲染的帧写入视频文件

skia能做到吗？vello能做到吗？

还有哪些设计理念完全不同的创新性类似于skia cairo vello的开源项目

Camera: 负责将场景转换为图像
SceneFileWriter: 将渲染的帧写入视频文件

核心过程 源码解析 原理梳理

Skia 能力分析：
Skia 是一个高性能的2D图形库，被Google广泛使用在Chrome和Android中。它完全有能力替代Manim中的Cairo进行2D渲染。

核心优势：

跨平台支持
硬件加速
高性能矢量图形渲染
Skia可以实现：

Camera功能：通过其强大的Canvas API，Skia可以将场景转换为图像。
SceneFileWriter功能：虽然Skia本身不直接支持视频写入，但它可以生成帧，然后使用其他库（如FFmpeg）将帧写入视频文件。
Vello 能力分析：
Vello 是一个新兴的GPU加速2D渲染器，使用Rust编写。它的设计目标是高性能和高质量的2D图形渲染。

潜在优势：

GPU加速
现代化的API设计
潜在的更高性能
Vello 理论上可以实现：

Camera功能：通过其渲染API，Vello可以将场景转换为图像。
SceneFileWriter功能：同样，Vello可以生成帧，然后使用其他库写入视频文件。
其他创新性图形渲染项目：
a. Pathfinder：

纯Rust实现的GPU加速矢量图形渲染器
使用新颖的算法来实现高效的GPU渲染
b. Blend2D：

高性能的2D矢量图形引擎
使用JIT编译技术来优化渲染性能
c. Piet：

Rust的2D图形抽象库
目标是提供一个统一的API，可以在多个后端（包括Direct2D, Skia, Cairo等）上运行
d. Resvg：

用Rust编写的SVG渲染库
专注于静态SVG渲染，性能优秀
e. NanoVG：

轻量级的OpenGL矢量图形库
适用于嵌入式系统和游戏开发
Camera 和 SceneFileWriter 的核心过程和原理：
Camera:

核心过程：

场景设置：定义视角、投影方式等
对象渲染：遍历场景中的所有对象
图像生成：将渲染结果转换为像素数据
关键源码（以Manim为例）：

python

复制
class Camera:
    def capture(self, *mobjects):
        # 清除画布
        self.reset()
        # 渲染对象
        self.display_multiple_mobjects(mobjects)
        # 获取图像数据
        return self.get_image()
原理梳理：

使用图形库（如Cairo）创建画布
将3D场景投影到2D平面
应用变换和样式
渲染每个对象到画布上
SceneFileWriter:

核心过程：

初始化：设置输出格式、编码器等
帧写入：将每一帧图像数据写入缓冲区
视频生成：将所有帧合成为视频文件
关键源码（以Manim为例）：

python

复制
class SceneFileWriter:
    def write_frame(self, frame):
        # 将帧写入缓冲区
        self.writing_process.stdin.write(frame.tobytes())

    def finish(self):
        # 完成视频写入
        self.writing_process.stdin.close()
        self.writing_process.wait()
原理梳理：

使用外部编码器（如FFmpeg）来处理视频编码
通过管道将帧数据传输给编码器
控制视频参数如帧率、比特率等
这些创新性项目展示了图形渲染领域的多样性和进步。每个项目都有其独特的设计理念和优势，比如GPU加速、跨平台兼容性、或特定领域的优化。在选择渲染库时，需要考虑项目需求、性能要求、以及开发团队的技术栈。



# people

involves:nicoburns
involves:raphlinus
involves:nicoburns
involves:Philipp-M
involves:DJMcNab
involves:MarijnS95
involves:xStrom






wgpu-rs
author:teoxoy
author:jimblandy
author:cwfitzgerald
author:ErichDonGubler
author:Wumpf
author:nical
author:jinleili
author:daxpedda
author:waywardmonkeys
author:fornwall
author:crowlKats
author:xiaopengli89
author:JCapucho
author:kvark
author:i509VCB
author:evahop
author:Imberflur
author:atlv24
author:Elabajaba
author:bradwerth
author:kpreid
author:valaphee
author:SparkyPotato
author:Dinnerbone
author:sagudev
author:grovesNL
author:Zoxc
author:DJMcNab
author:udoprog
author:expenses
author:a1phyr
author:gents83
author:JMS55
author:exrook
author:kornelski
author:schell
author:robtfm
author:rukai
author:fintelia
author:mockersf
author:TornaxO7
author:PJB3005
author:James2022-rgb
author:Gordon-F
author:MultisampledNight
author:scoopr
author:nolanderc
author:Aaron1011
author:Napokue
author:kyren
author:IcanDivide



winit

author:kchibisov
author:daxpedda
author:madsmtm
author:notgull
author:amrbashir
author:rib
author:msiglreith
author:MarijnS95
author:dhardy
author:xiaopengli89
author:waywardmonkeys
author:fornwall
author:emilk
author:jackpot51
author:rukai
author:lucasmerlin
author:dependabot[bot]
author:mockersf
author:alexheretic
author:grovesNL
author:tronical
author:Imberflur
author:ajtribick
author:HackerFoo
author:francesca64
author:maroider
author:hecrj
author:ArturKovacs
author:filnet
author:
