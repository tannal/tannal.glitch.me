# issues

- #1511: 语法高亮支持语言列表
  - 改善文档可读性
  - 添加悬停提示信息

- #1032: 模板预览图像替代文本
  - 修复拼写错误
  - 改善替代文本的描述性

- #721: HTML 导出功能
  - 强调语义区分的重要性
  - 与可访问性的关系

- #4812: 通过 ID 引用 SVG 对象
  - 改善图表标签的可访问性
  - 自动保持文本和图表同步

- #21: SVG 文本嵌入
  - 将文本作为真实文本而非路径
  - 提升 PDF 的可访问性

- #133: PDF 标签和替代文本支持
  - 与 LaTeX 相比的优势机会
  - 基础可访问性标记需求

- #3701: 图片替代文本
  - 需要在语法层面支持 alt text
  - 为将来的功能实现做准备


# Ascii

- 目前仅支持 PDF 输出被认为是局限
- HTML 输出对现代文档系统很重要
- 可以支持更灵活的阅读体验(移动设备等)
- 最初专注 PDF 是有意识的选择
- 这迫使团队建立自己的技术栈
- 计划逐步添加 HTML 输出支持
- 将首先关注语义正确性，而非样式
- 使用 Typst elements 作为中间表示
- 分为高级语义 IR 和低级布局 IR
- 通过 show rules 实现到 HTML 的转换
- 支持自定义元素定义

- PDF 仍然重要的领域：
  - 学术出版
  - 航空航天文档
  - 政府文件
  - 法律文档
- HTML 更适合的场景：
  - 在线阅读
  - 移动设备
  - 电子书

- 计划改进可访问性
- 保持语义化 HTML 输出
- 逐步完善 PDF 输出的可访问性
- 当前可以通过 pandoc 转换到其他格式

- scripting: 编程能力相关
- layout: 布局和定位
- math: 数学公式相关
- text: 文本排版、字形和国际化
- docs: 文档改进
- bibliography: 引用和参考文献
- html: HTML 导出
- pdf: PDF 导出
- svg: SVG 相关
- png: PNG 导出
- cli: 命令行接口
- ide: 开发工具支持
- packages: 包管理
- dependencies: 依赖更新

// 1. 网格和表格的基础元素
struct GridElem {
    children: Vec<GridChild>,
    // ... 其他字段
}

struct TableElem {
    children: Vec<TableChild>,
    // ... 其他字段
}

// 2. 子元素枚举
enum GridChild {
    Header(HeaderElem),
    Footer(FooterElem),
    Item(GridItem),
}

enum TableChild {
    Header(HeaderElem),
    Footer(FooterElem),
    Item(TableItem),
}

// 3. 网格项目枚举
enum GridItem {
    HLine(HLine),    // 水平线
    VLine(VLine),    // 垂直线
    Cell(GridCell),  // 单元格
}

// 4. 可解析的网格子元素
enum ResolvableGridChild<T> {
    Header {
        repeat: Repeat,
        span: Span,
        items: impl Iterator<Item = ResolvableGridItem<T>>,
    },
    Footer {
        repeat: Repeat,
        span: Span,
        items: impl Iterator<Item = ResolvableGridItem<T>>,
    },
    Item(ResolvableGridItem<T>),
}

// 5. 可解析的网格项目
enum ResolvableGridItem<T> {
    HLine {
        y: f64,
        start: f64,
        end: f64,
        stroke: Stroke,
        span: Span,
        position: LinePosition,
    },
    VLine {
        x: f64,
        start: f64,
        end: f64,
        stroke: Stroke,
        span: Span,
        position: LinePosition,
    },
    Cell(T),
}

// 6. 轴向数据结构
struct Axes<T> {
    x: T,  // 列
    y: T,  // 行
}

impl<T> Axes<T> {
    fn new(x: T, y: T) -> Self {
        Self { x, y }
    }
}

// 7. 网格布局器
struct GridLayouter<'a> {
    grid: &'a CellGrid,
    regions: Regions,
    styles: StyleChain,
    span: Span,
}

// 8. 单元格网格
struct CellGrid {
    tracks: Axes<Vec<Track>>,
    gutter: Axes<Vec<f64>>,
    fill: Fill,
    align: Alignment,
    inset: Inset,
    stroke: Stroke,
    // ... 其他字段
}

// 9. 样式相关
enum Dir {
    LTR,
    RTL,
}

enum LinePosition {
    Before,
    After,
}

enum OuterVAlignment {
    Top,
    Bottom,
}

enum OuterHAlignment {
    Left,
    Right,
    Start,
    End,
}

// 10. 布局引擎和区域
struct Engine {
    world: World,
    // ... 其他字段
}

struct Regions {
    // 布局区域信息
}

// 11. 定位和跟踪
struct Locator {
    // 位置信息
}

struct Tracepoint {
    Call(Option<String>),
}

struct Span {
    // 跨度信息
}

GridElem/TableElem
    |
    +-- GridChild/TableChild
        |
        +-- Header
        +-- Footer
        +-- Item
            |
            +-- HLine
            +-- VLine
            +-- Cell

CellGrid
    |
    +-- Axes<Track>
    +-- Axes<Gutter>
    |
    +-- GridLayouter

// 1. 解析网格/表格结构
GridElem/TableElem
    -> ResolvableGridChild
    -> ResolvableGridItem

// 2. 创建网格
CellGrid::resolve(...)

// 3. 布局
GridLayouter::layout(...)

# inbox

335 lines

底层控制:
计划提供底层控制,允许通过html模块直接生成特定的HTML元素。
但不建议直接将这些添加到内容中,而是结合自定义类型,创建自定义元素,其show规则生成适当的HTML元素。
show规则可以根据输出格式(HTML/布局)进行条件判断。
语义标记:
对于没有直接等效HTML标签的Typst标记(如<article>, <aside>等),计划通过用户函数来控制HTML输出。
目标是为从语义内容生成任意HTML创建灵活的基础,而不是完全重用未修改的模板。
数学公式:
计划使用MathML来渲染数学公式,但可能需要提供图像作为备选。
对EPUB导出的支持仍在讨论中。
文件分割:
计划提供从单个typ文件生成单页面或多页面输出的完全控制。
默认行为还未确定。
交叉引用:
计划保留跨HTML页面的交叉引用功能。
安全性:
对于直接生成HTML/JavaScript的安全性有所顾虑。
考虑限制可能的HTML标签,或者阻止包中的JavaScript导出。
可能使用像ammonia这样的HTML清理库。
实现计划:
目前仍在修复和改进布局引擎。
之后将开始HTML导出的实现工作。
数学渲染:
数学渲染是计划的一部分,但具体优先级和实现方式(自建还是基于现有库)还在讨论中。

git remote add remote "Continuous integration"
gh repo set-default
gh workflow run "Continuous integration" --ref ci

cargo test -p typst-tests --test tests text-spacing

selector

.\target\debug\typst.exe query .\test.typ heading
.\target\debug\typst.exe watch .\test.typ

Frame is a collection of frameItem
Shape MathFrameItem

Shape is Geometry plus fill and stroke



Martin Haug
Sits down and gets things done.

Laurenz Mädje
Thinks long and comes up with stuff.


# setup

git clone https://github.com/typst/typst.git

cargo build

# awesome typst


# people

involves:laurmaedje
involves:leedehai
involves:dherse
involves:frozolotl
involves:pgBiel
involves:mDLC01
involves:bluebear94
involves:reknih
involves:damaxwell
involves:EpicEricEE
involves:tingerrr
involves:Andrew15-5
involves:Enter-tainer
involves:peng1999
involves:LaurenzV
involves:Myriad-Dreamin
involves:LuxxxLucy
involves:Beiri22
involves:Jollywatt
involves:sitandr
involves:mattfbacon
involves:elegaanz
involves:figsoda
involves:DVDTSB
involves:istudyatuni
involves:jcbhmr
involves:jimvdl
involves:rikhuijzer
involves:antonWetzel
involves:Heinenen
involves:xkevio
involves:Mafii
involves:drupol
involves:lolstork
involves:raphCode
involves:A-Walrus
involves:lynn
involves:T0mstone
involves:KillTheMule
involves:danieleades
involves:cmoog
involves:SekoiaTree
involves:SUPERCILEX
involves:StrangeGirlMurph
involves:SimonRask
involves:freundTech
involves:HydroH
involves:pineapplehunter
involves:kg583
involves:s-cerevisiae
involves:YDX-2147483647
involves:mtoohey31
involves:epbuennig
involves:xalbd
involves:lucifer1004
involves:adriandelgado
involves:azerupi
involves:k-84mo10
involves:sudormrfbin
involves:TheJosefOlsson
involves:t-rapp
involves:Jocs
involves:sandalbanditten
involves:astrale-sharp
involves:rezzubs
involves:lihe07
involves:samueltardieu
involves:jbirnick
involves:MyrtleTurtle22
involves:fritzrehde
involves:muzimuzhi
involves:WeetHet
involves:3w36zj6
involves:toddlerer
involves:silvergasp
involves:Zheoni
involves:7sDream
involves:neunenak
involves:Luis-Licea
involves:jassler
involves:owiecc
involves:AlistairKeiller
involves:rpitasky
involves:naim94a
involves:johannes-wolf
involves:dccsillag
