
## 第零课 对计算机系统有一个基本认识

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

## 第二课 OOP和高级语言

OOP
C++

OOP

解释器和JIT编译器
显式中间代码语言 Java Python JavaScript Python Julia R ...

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


数据中心和异构平台
超算

## 第四课 1.测试开发 2.嵌入式开发 3.泛客户端开发 4.泛Server开发 5.AI大模型算法和应用开发 6.数据和人工智能 7.生产系统和运行维护

计算资源和存储资源

还是一样认识平台
