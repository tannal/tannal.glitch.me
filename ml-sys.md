

AutoInfer 是 llama.cpp的改进

- 设计调度合理利用GPU和CPU
- 改进浮点计算


llama.cpp 用于在一般个人电脑上（Apple）运行meta开源的大语言模型llama

whisper.cpp 是可在一般手机上本地运行的语音识别系统

llama利用了C++实现的ggml机器学习库


如何在不损失很大效果的前提下将一般机器学习系统部署在消费性电子产品？

利用ggml等作为机器学习库实现需要的机器学习算法，or 借鉴ggml自建机器学习库然后实现需要的机器学习算法

可以参考whisper.cpp的做法，利用ggml实现机器学习算法，尽量避免进入python生态，自行控制所有计算。

一般来说机器学习库包括两个方面

1. automatic differentiation (autograd in pytorch)
2. tensor operation (matrix, vector 线性代数对象以及它们的运算) (ATen in pytorch)

> Overall I think right now the best investment of my time is to simply focus on the basics: faster matrix multiplication, more efficient quantization, and better training code.

# Reference

https://github.com/ggerganov/ggml Tensor library for machine learning

https://github.com/ggerganov/whisper.cpp

https://github.com/ggerganov/llama.cpp/discussions/4534#discussioncomment-7911661 更快的矩阵乘法？

https://github.com/ggerganov/llama.cpp/issues/33

# Miscellaneous

static computational graphs

built-in automatic differentiation (AD)
linear algebra datatypes

neural network applications
GPU-accelerated tensor computation
