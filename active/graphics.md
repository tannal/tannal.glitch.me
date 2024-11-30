




# 2D


Adobe Graphics Engine 团队
- Thomas Knoll (Photoshop 创始人)
- John Warnock (PostScript 创始人)
- Charles Geschke

Adobe PDF/PostScript 团队
- John Warnock
- Chuck Geschke
- Doug Brotz

Microsoft Direct2D & Windows Imaging Component (WIC) 团队
- Kevin Kerr (主要架构师)
- Kenny Kerr (技术专家，写过很多 Direct2D 相关文章)
- Sam Fortiner
- Mike Wasserman

Direct2D 技术栈:
- Direct2D
- DirectWrite
- Windows Imaging Component (WIC)

Jeff Bolz
Mark Kilgard
Pat Brown
Christoph Kubisch

职位: 图形软件工程师
主要工作:
- NV path rendering 扩展的主要作者
- Cg 着色语言相关工作
合作者:
- Randima Fernando (合著 The Cg Tutorial)


主要贡献:
- 开发 OpenGL Utility Toolkit (GLUT)
- 编写大量 OpenGL 技术示例程序
相关人员:
- Nate Robins (将 GLUT 移植到 Windows)

教育: Rice University 毕业
著作:
- OpenGL for the X Window System (1996)
- The Cg Tutorial (2003, 与 Randima Fernando 合著)


- Mark Kilgard
- Jeff Bolz
主要贡献:
- NVPR (NVIDIA Path Rendering)技术
- GPU 加速路径渲染的商业实现

- Kevin Kerr 等
主要贡献:
- Direct2D 技术
- 基于 CPU 的梯形剖分方案

- Diego Nehab
- Hugues Hoppe
贡献:
- 随机访问矢量图形渲染
- 晶格裁剪方案

- Francisco Ganacim
- Rodrigo Lima
- Luiz Henrique de Figueiredo
贡献: 大规模并行矢量图形处理

- Wylie
- Romney
- Evans
- Erdahl
贡献: 最早提出扫描线算法基础

- Newman
- Sproull
贡献: 改进了扫描线-曲线相交计算

贡献:
- 小波光栅化
- 解析光栅化方法

- Y. Kokojima
- K. Sugita
- T. Saito
贡献: 使用图形硬件渲染可变形矢量对象

- Alexandru Orzan
- Adrien Bousseau
- Holger Winnemoller
贡献: 提出扩散曲线表示方法

# 3D

# Real time rendering

# Offline rendering

# inbox

super sampling anti-aliasing

3840 x 2160 4k

1600 x 900


# transform

```js
// scale
[
    [Sz, 0, 0, 0],
    [0, Sy, 0, 0],
    [0, 0, Sz, 0],
    [0, 0, 0, 1],
]

// translation

[
    [1, 0, 0, tx],
    [0, 1, 0, ty],
    [0, 0, 1, tz],
    [0, 0, 0, 1],
]

// rotation X

[
    [1, 0, 0, 0],
    [0, cosθ, -sinθ, ty],
    [0, sinθ, cosθ, tz],
    [0, 0, 0, 1],
]

// rotation Y
[
    [cosθ, 0, sinθ, 0],
    [0, 1, 0, 0],
    [-sinθ, 0, cosθ, 0],
    [0, 0, 0, 1],
]

// rotation Z
[
    [cosθ, -sinθ, 0, 0],
    [sinθ, cosθ, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1],
]


```


# Barycentric coordinate system


# community

https://github.com/EpicGames
