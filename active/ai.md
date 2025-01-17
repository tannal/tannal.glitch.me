
# Money

基础模型研发
OpenAI：GPT系列
Anthropic：Claude系列
Google：Gemini
Meta：Llama系列
xAI：Grok
主要投入：算力、数据中心、人才招聘

芯片与算力基础设施
NVIDIA：H100、L40等AI芯片
AMD：MI300系列
Intel：Gaudi系列
数据中心扩建
云服务提供商的AI基础设施

垂直领域应用
企业AI助手
AI辅助编程（GitHub Copilot、Amazon CodeWhisperer）
AI创作工具（Midjourney、DALL-E、Stable Diffusion）
医疗AI
自动驾驶

AI工具链与开发平台
模型训练框架
开发工具
推理优化
部署平台
数据标注与处理

AI安全与治理
模型对齐研究
安全评估
伦理研究
监管合规

人才市场
高薪招聘AI研究员
收购AI创业公司
AI教育培训
数据资源
高质量训练数据收集
数据清洗与标注
数据合规
商业化与落地
AI产品设计
市场营销
客户服务
解决方案集成



1.相对位置编码
# 不是简单的位置编码
position = sin(pos/10000^(2i/d))  # 传统Transformer

2. 音程感知层
# 而是基于音高差的编码
pitch_diff = note[t] - note[t-1]  # 相邻音符的音高差
relative_encoding = encode(pitch_diff)  # 编码音高差

3. 和声约束
class IntervalLayer(nn.Module):
    def forward(self, x):
        # 计算相邻音符的音程关系
        intervals = x[:, 1:] - x[:, :-1]
        # 可以加入音程分类（如大三度、纯五度等）
        interval_type = classify_interval(intervals)
        return interval_type

        def harmony_loss(pred_notes):
            # 计算和声张力
            chord = extract_chord(pred_notes)
            tension = compute_tension(chord)

            # 和声进行约束
            progression = chord_progression(chord)
            return tension_loss + progression_loss

4. 多尺度生成
class MelodyGenerator:
    def generate(self):
        # 1. 先生成骨干音符
        skeleton = generate_skeleton()

        # 2. 基于音程填充细节
        details = fill_by_intervals(skeleton)

        # 3. 添加装饰音
        melody = add_ornaments(details)

        return melody

5. 调性感知注意力
class TonalityAttention(nn.Module):
    def forward(self, q, k, v):
        # 计算调性相关度
        tonality_scores = compute_tonality_relation(q, k)

        # 结合传统注意力和调性约束
        attention = softmax(tonality_scores @ standard_attention)
        return attention @ v

https://web.stanford.edu/~jurafsky/slp3/
https://llmsystem.github.io/llmsystem2024spring/docs/Syllabus
https://cmu-llms.org/schedule/

自动微分引擎实现
Adam, AdamW 优化器
Dropout 实现
基础神经网络训练

卷积网络的自动微分
Dropout2d 实现
BatchNorm2d 实现
ResNet 架构实现
图像相关任务

RNN/LSTM 实现
序列处理
时间序列预测

语言建模 (HW4P1)
注意力机制
编码器-解码器架构
自动语音识别 (HW4P2)

计算机视觉
自然语言处理
语音识别
序列建模

AI大模型目前的竞争主要集中在以下几个方面：

1. 核心能力竞争

1. 多模态融合文本、图像、语音、视频的统一理解

跨模态生成能力
3D理解与生成
推理能力
复杂问题分解逻辑链
推导数学解题能力
代码理解与生成上下文理解
长文本理解
上下文窗口扩展记忆与检索机制

2. 技术指标竞争模型

规模参数量优化计算效率提升
存储效率提升
推理性能延迟降低
吞吐量提升
资源利用率优化
训练效率预训练成本降低
微调效率提升

数据利用效率

3. 应用场景竞争

1. 垂直领域适配

金融 医疗 法律 教育 企业级应用知识库 构建流程

自动化客服对话代码辅助

3. 消费级应用个人助手创意创作教育辅导娱乐互动

4. 基础设施竞争

部署方案
云端部署优化
边缘计算支持
本地部署能力
硬件适配
不同GPU架构支持
量化方案优化
专用芯片适配
开发工具SDK完善度API易用性
开发文档质量

5. 生态系统竞争

1. 开发者生态开源社区活跃度

工具链完善度
文档与教程应用生态插件系统

第三方集成应用市场

数据生态训练数据
质量数据合规性数据安全性

6. 商业模式竞争定价策略

API定价订阅模式

企业授权服务模式SaaS服务
私有部署混合云方案变现途径
直接收费
增值服务
生态分成

7. 安全与伦理竞争安全性

数据隐私
保护模型
安全防护攻击
防范合规性
法律法规遵守行业标准
符合审计与监管伦理准则
偏见消除
有害内容过滤

使用边界

8. 创新方向竞争
架构创新
混合专家模型(MoE)
稀疏激活注意力机制优化
训练范式创新
少样本学习
持续学习
自监督学习
应用创新新场景探索新交互模式新业务模式这场竞争是多维度的，
不同玩家根据自身优势选择不同的竞争重点。

目前，竞争格局仍在快速演变中，未来可能会出现更多创新点和竞争维度。

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


# master thesis


## Abstract


## Introduction

早期阶段 (1950s-1980s)

1957年：Illiac Suite，第一个由计算机生成的弦乐四重奏
1965年：Hiller和Baker开发了MUSICOMP系统
1981年：CHORAL系统，用于生成巴赫风格的四部和声
主要使用规则基础(rule-based)和马尔可夫链等算法

符号音乐生成时期 (1990s-2000s)

EMI (Experiments in Musical Intelligence)系统
David Cope的作曲系统能模仿巴赫、莫扎特等作曲家风格
使用文法(grammar)和概率模型进行音乐生成
基于案例(case-based)的音乐生成系统开始出现

深度学习早期 (2010-2015)

RNN/LSTM开始应用于音乐生成
Google的Magenta项目启动
DeepBach等系统展示了神经网络在和声生成上的潜力

深度学习繁荣期 (2016-2020)

WaveNet (2016) 实现高质量音频合成
MuseNet能生成多种乐器的配器
Music Transformer改进了长序列音乐生成
Jukebox实现了带歌词的歌曲生成

大模型时代 (2020-至今)

MusicLM：高质量音乐生成模型
AudioCraft：Meta的音频生成框架
Stable Audio：稳定扩散在音乐领域的应用
多模态音乐生成：文本/图像到音乐

规则基础 → 统计模型 → 神经网络 → Transformer → 扩散模型
单一乐器 → 多乐器配器
MIDI生成 → 原始音频生成
单一风格 → 多风格融合

## Chanllege

长期结构的控制
音乐表现力和情感的把握
版权和伦理问题
与人类创作的协同

## Related theory & analysis

David Lewin - 变换理论(Transformational Theory)
Fred Lerdahl - 生成音乐理论
Joseph Straus - 后调性理论
Richard Cohn - 新里曼理论
David Temperley - 音乐认知和计算分析

## DataSet

## Future Work

未来趋势
更精确的音乐控制接口
实时互动音乐生成
AI辅助作曲工具的普及
个性化音乐定制服务

## References

[1]: https://github.com/facebookresearch/audiocraft/blob/main/dataset/example/electro_1.mp3
[2]: https://ai.honu.io/papers/musicgen/
[3]: Andrea Agostinelli, Timo I Denk, Zalán Borsos, Jesse Engel, Mauro Verzetti, Antoine Caillon, Qingqing Huang, Aren Jansen, Adam
Roberts, Marco Tagliasacchi, et al. Musiclm: Generating music from text. arXiv preprint arXiv:2301.11325, 2023.
[4]: S Forsgren and H Martiros. Riffusion-stable diffusion for real-time music generation. 2022. URL: https://riffusion.com/about.
[5]: Flavio Schneider, Zhijing Jin, and Bernhard Schölkopf. Moûsai: Text-to-music generation with long-context latent diffusion. arXiv
preprint arXiv:2301.11757, 2023.
[6]: Alexandre Défossez, Jade Copet, Gabriel Synnaeve, and Yossi Adi. High fidelity neural audio compression. arXiv preprint
arXiv:2210.13438, 2022.
[7]: J. Copet, F. Kreuk, I. Gat, T. Remez, D. Kant, G. Synnaeve, Y. Adi, and A. Défossez. Simple and controllable music generation. arXiv
preprint arXiv:2306.05284, 2023.
[8]: Ashish Vaswani, Noam Shazeer, Niki Parmar, Jakob Uszkoreit, Llion Jones, Aidan N Gomez, Ł ukasz Kaiser, and Illia Polosukhin.
Attention is all you need. In I. Guyon, U. Von Luxburg, S. Bengio, H. Wallach, R. Fergus, S. Vishwanathan, and R. Garnett, edi- tors,
Advances in Neural Information Processing Systems, volume 30. Curran Associates, Inc., 2017. URL
https://proceedings.neurips.cc/paper_files/paper/2017/file/ 3f5ee243547dee91fbd053c1c4a845aa-Paper.pdf.
[9]: https://towardsdatascience.com/how-metas-ai-generates-music-based-on-a-reference-melody-de34acd783
[10]: Liu, H., Chen, Z., Yuan, Y., Mei, X., Liu, X., Mandic, D., ... & Plumbley, M. D. (2023). Audioldm: Text-to-audio generation with latent
diffusion models. arXiv preprint arXiv:2301.12503.
[11]: https://www.stableaudio.com
[12]: https://www.suno.ai
[13]: Lam, M. W., Tian, Q., Li, T., Yin, Z., Feng, S., Tu, M., ... & Wang, Y. (2024). Efficient neural music generation. Advances in Neural
Information Processing Systems, 36.
[14]: https://drscotthawley.github.io/blog/posts/2023-06-12-RVQ.html
