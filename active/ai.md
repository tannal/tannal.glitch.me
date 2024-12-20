



## Programming

## Deepmind

DQN
AlphaGo
AlphaGo Zero
AlphaFold
AlphaFold 2

OpenAI ChatGPT

DALL-E 图像生成

StabilityAI
CompVis
Runway

IBM Watson


以下是一些在AI领域
有重要贡献的公司：
学术/研究机构背景：Cohere (多伦多大学背景)

AI21 Labs (以色列)
Inflection AI (DeepMind前员工创立)
Claude (前OpenAI研究员创立)
大型科技公司：
Microsoft Research
IBM Research (Watson等项目)
Apple (机器学习团队)
Nvidia (AI芯片和框架)
Baidu Research (文心一言)
阿里达摩院
腾讯AI Lab
专注特定领域的AI公司：
Hugging Face (开源AI模型和工具)
Runway ML (AI视频和创意工具)
Midjourney (AI图像生成)
Character.ai (AI对话角色)
Replika (AI伴侣)
Scale AI (AI数据标注和训练)
开源社区：EleutherAI (开源语言模型)
Stability AI (开源图像生成)
LAION (开源数据集)新兴的重要玩家：xAI (马斯克的AI公司)
Claude (Anthropic的竞品)
Adept AI (AI助手)
Databricks (企业AI解决方案)这些公司在不同方向都有其独特贡献：
基础研究应用开发开源工具数据集建设计算基础设施特定领域应用

- Microsoft Research
- IBM Research
- Amazon Research
- Baidu Research
- Tencent AI Lab
- Huawei Noah's Ark Lab
- Nvidia Research
- MIT-IBM Watson AI Lab
- CMU AI Lab
- Stanford AI Lab

# Hinton

# Meta AI Lab

john Hopfield
Yann LeCun
Antoine Bordes
Jason Weston


# OpenAI

# DeepMind

Richard Sutton
David Silver
Adam White
Joseph Modayil
Martha White
Andy Barto


# Anthropic

Research

1. 大语言模型研究
- 预训练数据基础设施
- 性能优化工程
- 多模态研究
- 模型解释性研究

2. AI安全与对齐
- 对齐科学研究
- 社会影响评估
- 生物安全评估
- 可解释性团队建设

Engineering

1. 产品开发
- Claude.ai应用开发
- API体验优化
- 移动端开发
- 增长工程

2. 基础设施
- 模型服务
- 安全工程
- 信任与安全

Business

1. 企业服务
- SaaS销售
- API销售
- 公共部门拓展
- 创业公司合作

2. 国际化
- 英国伦敦团队扩张
- 欧洲市场(都柏林)


# inbox

pre-training
fine-tuning
post-training x

小型模型(125M-350M参数):
- 模型参数: ~0.25-0.7GB
- 优化器状态: ~0.5-1.4GB
- 梯度: ~0.25-0.7GB
- 激活值(batch=32): ~2-4GB
总计: ~3-7GB

中型模型(1.3B-2.7B参数):
- 模型参数: ~2.6-5.4GB
- 优化器状态: ~5.2-10.8GB
- 梯度: ~2.6-5.4GB
- 激活值(batch=16): ~6-10GB
总计: ~16-32GB

大型模型(6B-13B参数):
- 模型参数: ~12-26GB
- 优化器状态: ~24-52GB
- 梯度: ~12-26GB
- 激活值(batch=8): ~12-20GB
总计: ~60-124GB

文本：vLLM
视觉：TorchServe + CLIP
音频：Whisper + Triton
视频：VideoMAE
调度：Ray
监控：Prometheus + Grafana

10. 关键优化点：
模态特定的批处理策略
跨模态缓存机制
GPU 内存管理
模态间的负载均衡
特征提取复用
推理结果缓存
这种架构能够支持：
多模态输入处理
模态间的协同推理
高效的资源利用
灵活的扩展性
端到端的流式处理


train on one machine with one gpu
train on one machine with multiple gpus
parallelism
model parallelism
data parallelism


ggml-mnist gpt2(llm.c)
train & infer
deepspeed lora

inference
whisper.cpp
llama.cpp
stable-diffusion.cpp
clip.cpp
bark.cpp

fine-tuning
lora QLora ...



data 6 month
train 6 month
finetuning 6 month


cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Release' -DGGML_DEBUG=1

git clone https://github.com/karpathy/llm.c

watch -n 0.1 nvidia-smi

python train_gpt2.py
make train_gpt2
make train_gpt2cu


./train_gpt2cu \
    -i "dev/data/edu_fineweb10B/edu_fineweb_train_*.bin" \
    -j "dev/data/edu_fineweb10B/edu_fineweb_val_*.bin" \
    -o log124M \
    -e "d12" \
    -b 56 -t 1024 \
    -d 458752 \
    -r 1 \
    -z 1 \
    -c 0.1 \
    -l 0.002 \
    -q 0.0 \
    -u 700 \
    -n 5000 \
    -v 250 -s 20000 \
    -h 1
