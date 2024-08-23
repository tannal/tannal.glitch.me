# inbox

cargo install --git https://github.com/rust-mobile/cargo-apk

cargo run -p headless

cargo run --example run_on_demand

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


# 



# people

involves:nicoburns
involves:raphlinus
involves:nicoburns
involves:Philipp-M
involves:DJMcNab
involves:MarijnS95
involves:xStrom





