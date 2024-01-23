

AutoInfer 是 llama.cpp的改进

- 设计调度合理利用GPU和CPU
- 改进浮点计算


llama.cpp 用于在一般个人电脑上（Apple）运行meta开源的大语言模型llama

whisper.cpp 是可在一般手机上本地运行的语音识别系统

llama利用了C++实现的ggml机器学习库

如何在不损失很大效果的前提下将一般机器学习系统部署在消费性电子产品？

可以参考whisper.cpp的做法，利用ggml实现机器学习算法，尽量避免进入python生态，自行控制所有计算。

更快的矩阵乘法？


# reference

https://github.com/ggerganov/ggml

https://github.com/ggerganov/whisper.cpp

https://github.com/ggerganov/llama.cpp/issues/33