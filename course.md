
## 第零课 对计算机系统有一个基本认识

计算
编码

软件
硬件

Abstraction/Interface/Specification
Implementation

内存是Abstraction

编译器

```
# 安装 Scoop
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
irm get.scoop.sh | iex

scoop config proxy 127.0.0.1:7890
# 添加软件源
scoop bucket add versions
scoop install versions/zed-nightly
```

https://www.youtube.com/@cs50/videos

## 第一课 指令、状态、编程

C 语言 指令

指令1
指令2
指令3
指令4
...

```
// foo.c
int foo() {
  return 42;
}

int main() {
  return foo();
}

```

```
```

指令

```assembly

mov eax ebx
addi eax acx

```

台湾交通大学
曹效忠老师的嵌入式系统实验课和操作系统设计与实现
犹太大学老师的嵌入式系统设计与实现

## 第二课 OOP和高级语言 编程的目前最好的规范化

函数式编程在大多数情况下是垃圾

OOP
C++

OOP

解释器和JIT编译器

讲一下构建系统和依赖管理

C/C++ m4 autoconf Makefile CMake Meson xmake
Rust Cargo
Java/JVM Maven/Gradle
Python UV/pyproject
Javascript/Typescript webpack/vite/rolldown/oxc

Rust cranelift
https://www.youtube.com/watch?v=ilhSdmv6bAY&t=257s
c/c++ GNU/LLVM/Microsoft

ABI System-V/Apple/GNU/Microsoft

显式中间代码语言 Java Python JavaScript Python Julia R ...

Cliff Click的博士论文还有他的报告和Simple Sea of Nodes IR（同样用在V8的优化编译器里面）
斯坦福的老师们

## 第三课 常见的软件系统，知道什么是平台

操作系统 -> 应用软件 -> 用户

操作系统 (Implementaion) -> 应用开发者 <--> 用户

操作系统 (Implementaion) -> Abstraction -> 应用开发者 <--> 用户

Soc/PC/板子/外设 -> 操作系统 (驱动，内核) -> 实现 -> Abstraction -> 应用开发者 <-> 用户 ?

有层次关系的，树和OOP就是编程中用来表达层次关系的

文件(Abstraction，操作系统虚构的，1950年代发明的) -> 硬盘

数据库系统(开发者面对) -> (文件，用户面对) -> 硬盘

桌面平台
Web平台
移动平台
机房和互联网络

网络和数据库

数据中心和异构平台
超算

台湾交通大学的嵌入式系统设计与实现
Jserv老师的

## 第四课 网络

## 第五课 存储

File System

CMU Database Group
Postgresql

## 第六课 硬件系统 & 并行与分布式


## 第七课 1.测试开发

脚本和shell
定时任务
触发机制
UI测试
单元测试
集成测试
测试用例
测试覆盖度，测试报告
自动化测试
AI辅助、自动化测试

## 第七课 2.嵌入式开发

Soc
CPU Memory flash

## 第七课 3.泛Client开发

## 第七课 4.泛Server开发

## 第七课 5.AI大模型算法和应用开发

## 第七课 6.数据和人工智能

## 第七课 7.生产系统和运行维护

## 第八课 工具使用 效率 文档

键盘打字
人体工学键盘
椅子
脖子
办公桌

平视屏幕
多喝水
注意休息
避免疲劳用眼用脑

AI使用，先说结论，AI是拿来问的，不是拿来答的。
答的效果有目前Claude3.5 的水平就行。
有知识库和最新的知识，更新更好。

## 第九课 打工人打工魂

租房

水电

吃喝

休闲娱乐

卫生和居家小妙招

升职？
1. 尝试承担你目标职级所需的责任，并且做出一定成果，报告成果给领导请求升职。
2. 领导say no 则 回退承担你实际职位所需责任 准备找下一家公司，跳槽或创业。
say yes 则 升职
是否满足？ 是 则 维持现状
否 继续 重复 1 或 2

## 第十课 工业社会及其未来

工业社会产生了以下内容

食物，水，适宜的住所，稳定的朋友圈
朝九晚五工作制
一日三餐是工业革命之后工人的标准

科技让环境变化过快
