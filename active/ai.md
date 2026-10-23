
这次我会把研究范围定得比“AI 音乐生成”更大一些。

你的目标是 General Musical Intelligence（通用音乐智能）：不仅生成音乐，还要理解音乐理论与结构、进行可控创作、产生富有表现力的演奏，并能够与人实时协作。

因此，需要同时研究符号音乐模型、音频生成模型、音乐理解模型、音乐与语言的联合表征、长程结构建模，以及实时交互系统。

还有一个重要区别：生成质量高，不等于具备音乐理解能力；理解乐理，也不等于能够作曲或即兴。 我会特别关注哪些研究真正跨越了这些能力边界，而不是只比较生成音频的听感。

以下以截至 2026 年 10 月 23 日的公开研究为目标，重点检索 2025–2026 年进展，并补充不可绕过的早期基础工作。

## 一、最值得关注的 2026 年研究

先看与 `abc-ai` 最直接相关、也最可能影响你未来研究路线的工作。

[MIDI-REPA](https://arxiv.org/abs/2610.20967?utm_source=chatgpt.com)

2026 年 10 月

用符号音乐监督音频生成模型。 研究将自动转录得到的 MIDI 表征对齐到音频生成模型的中间层，不需要增加训练数据，便改善了音乐结构学习的监督方式。

这非常贴近你从 ABC 符号建模向音频模型发展的可能路线。论文报告其 122M 参数基线能够在单张 RTX 3090 上约 31 小时完成训练。

[image](https://www.google.com/s2/favicons?domain=https://arxiv.org\&sz=32)

arXiv



[Unifying Score and Performance for Fine-Grained Music Understanding](https://arxiv.org/abs/2609.10351?utm_source=chatgpt.com) — 2026 年 9 月

提出 MuNo-SP，将乐谱内容与演奏信息统一表示，并用对齐的乐谱和演奏生成细粒度的音乐问答与分析数据。

这回答了一个关键问题：同一首作品的音符结构与实际演奏表达，能否成为同一个模型的学习对象？&#x20;

[image](https://www.google.com/s2/favicons?domain=https://arxiv.org\&sz=32)

arXiv



[Pianist Transformer](https://proceedings.mlr.press/v306/you26d.html?utm_source=chatgpt.com) — ICML 2026

用大规模 MIDI 自监督预训练研究表现力钢琴演奏。论文报告使用 100 亿 MIDI tokens，并通过音符级压缩提高长序列建模效率。

这是从“生成正确的音符”迈向“生成有表现力的演奏”的直接研究路径。

[image](https://www.google.com/s2/favicons?domain=https://proceedings.mlr.press\&sz=32)

Proceedings of Machine Learning Research



[MSU-Bench: Musical Score Understanding Benchmark](https://aclanthology.org/2026.acl-long.493/?utm_source=chatgpt.com) — ACL 2026

包含 1,800 个针对完整乐谱的问答样本，同时考察 ABC 文本记谱与 PDF 乐谱图像，问题覆盖从音符起始信息到织体、曲式等不同理解层次。

对你的 ABC-AI 特别重要：它可以帮助你从 PPL、音高分布等统计指标，进一步转向可验证的音乐结构理解能力。

[image](https://www.google.com/s2/favicons?domain=https://aclanthology.org\&sz=32)

ACL Anthology



[MIDI-LLaMA](https://arxiv.org/abs/2601.21740?utm_source=chatgpt.com) — 2026 年 1 月

将 MusicBERT 符号音乐编码器与 Llama-3-8B 对齐，再进行指令微调，实现 MIDI 的描述与问答。

值得注意的是，它还与“先将 MIDI 转成 ABC 再让语言模型理解”的方案进行了比较，报告了直接 MIDI 表征的优势。这是你选择 ABC 作为模型表示时应该认真研究的对照实验。

[image](https://www.google.com/s2/favicons?domain=https://arxiv.org\&sz=32)

arXiv



[Moonbeam: A MIDI Foundation Model](https://arxiv.org/abs/2505.15559?utm_source=chatgpt.com) — 2025

预训练于约 81,600 小时 MIDI、180 亿 tokens，使用音乐领域的绝对与相对属性，以及多维相对注意力，同时支持音乐理解和条件生成。

它挑战了一个假设：普通 GPT Tokenization + Transformer 是否足够学习音乐中的相对音高、节奏和转调关系？&#x20;

[image](https://www.google.com/s2/favicons?domain=https://arxiv.org\&sz=32)

arXiv



## 二、按研究方向整理的论文地图

| 研究方向      | 代表性最新工作                                                                                                                                                                | 核心突破或问题                     |
| --------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------- |
| 符号音乐长程结构  | [Hi-ACG](https://aclanthology.org/2026.findings-acl.1574/?utm_source=chatgpt.com) (2026)                                                                               | 利用锚点信息减少自回归生成中的结构漂移         |
| 分层作曲      | [CAST](https://www.nature.com/articles/s41598-026-46750-0?utm_source=chatgpt.com) (2026)                                                                               | 先规划和声骨架，再生成细节织体             |
| 长歌曲控制     | [SegTune](https://aclanthology.org/2026.acl-long.586/?utm_source=chatgpt.com) (2026)                                                                                   | 为不同歌曲片段指定不同条件               |
| 可复现歌曲生成   | [Muse](https://aclanthology.org/2026.findings-acl.1129/?utm_source=chatgpt.com) (2026)                                                                                 | 公开训练与评测管线，支持分段风格控制          |
| 音乐基础模型    | [HeartMuLa](https://arxiv.org/abs/2601.10547?utm_source=chatgpt.com) (2026)                                                                                            | 音频文本对齐、音乐 Codec、生成模型组成的模型家族 |
| 音乐音频理解    | [Music Flamingo](https://proceedings.iclr.cc/paper_files/paper/2026/hash/7f64034009f4a5fa417a57e1a987c5cd-Abstract-Conference.html?utm_source=chatgpt.com) (ICLR 2026) | 扩展音乐音频问答和理解能力               |
| 跨模态乐谱转换   | [U-MusT](https://github.com/MALerLab/U-MusT?utm_source=chatgpt.com) (2025/26)                                                                                          | 统一乐谱图像、MIDI、MusicXML 与音频的转换 |
| 音频理解与生成统一 | [UALM](https://research.nvidia.com/labs/adlr/UALM/?utm_source=chatgpt.com) (2025)                                                                                      | 单一模型处理音频理解、生成和跨模态推理         |
| 语音与音乐联合生成 | [UniMoE-Audio](https://aclanthology.org/2026.acl-long.412/?utm_source=chatgpt.com) (2026)                                                                              | 通过动态容量专家混合缓解语音与音乐任务冲突       |

这些工作有两种不同的统一思路。

第一种是统一表示：让乐谱、MIDI、音频、文本能够交换信息。U-MusT、MuNo-SP、MIDI-REPA 更接近这条路线。

第二种是统一模型：通过共同的 Transformer、音频 Token 或 MoE 架构，让一个模型执行多种理解与生成任务。HeartMuLa、UALM、UniMoE-Audio 更接近这条路线。

两种思路并不互斥。但统一表示不保证统一理解，统一模型也不保证各种任务都比专用模型更好。

## 三、音乐智能最重要的突破：从离线生成走向实时协作

这一方向已经出现了真实可运行的系统，而不只是概念论文。

[Magenta RealTime 2: Open & Local Live Music Models](https://images.openai.com/static-rsc-4/anelDeJTl-QyKRjeCcCcesVTGrwAt6Dw-0PLvEvKtfRWAoLEGNhNFGpezZgvxCq3l0mKdhQjLGHg5AwD4A4O3COtk34jIVq--u357U9ImZwZ2swfuXdGLSqsldPBHOysnI6G4TudeOyxNjlWiZMATAXSPhxQdai6BEKJwTDS34M?purpose=inline)

[Magenta RealTime 2](https://magenta.withgoogle.com/magenta-realtime-2?utm_source=chatgpt.com) — 2026 年 6 月

Google Magenta 发布了开放权重的实时音乐模型与推理引擎，支持 MIDI、音频、文本输入，并能够在 Apple Silicon 笔记本上本地运行，也能作为 DAW 插件使用。

这很接近“AI 作为可演奏乐器或实时音乐伙伴”的实际产品形态。

[image](https://www.google.com/s2/favicons?domain=https://magenta.withgoogle.com\&sz=32)

Magenta



[Jordan Rudess to Debut jam_bot AI at MIT Future Fest | BroadwayWorld](https://images.openai.com/static-rsc-4/4yH0JHqrJnsUC91MBF8gAPkSG6NOzD6Q492URAKhm4cpyex8VeyeIjrFQ7ySk95Ly1KkxulCaeMRKDqfAx-OPq7od2cghPnnBuKkDLJgDHAhvd3gTA8S0phBQL9qubG7u7wsJ_tfFTxgAR9a8cstgzTOgUQuuCSo-xocsclESyw?purpose=inline)

[JAM_BOT](https://www.media.mit.edu/publications/the-jam_bot-a-real-time-system-for-collaborative-free-improvisation-with-music-language-models/?utm_source=chatgpt.com) — ISMIR 2025

MIT 团队与键盘演奏家 Jordan Rudess 合作，将符号音乐语言模型接入实时演奏系统，在现场音乐会上实现人机自由即兴。

论文重点并不只是模型本身，而是如何处理不同音乐角色、上下文条件、低延迟推理和生成调度。

[image](https://www.google.com/s2/favicons?domain=https://www.media.mit.edu\&sz=32)

MIT Media Lab



[Generative Adversarial Post-Training for Live Human-AI Music Interaction](https://proceedings.iclr.cc/paper_files/paper/2026/hash/e6731a1d3eddafeb8c94669a1d82fc5d-Abstract-Conference.html?utm_source=chatgpt.com) — ICLR 2026

研究发现，单纯优化伴奏与旋律的和谐程度，可能使模型输出变得重复、缺乏变化。作者用对抗式后训练同时改善和声一致性、生成多样性和交互适应性，并进行了真实音乐家的用户研究。

[image](https://www.google.com/s2/favicons?domain=https://proceedings.iclr.cc\&sz=32)

ICLR 会议录



[A Design Space for Live Music Agents](https://arxiv.org/abs/2602.05064?utm_source=chatgpt.com) — CHI 2026

分析 184 个实时音乐 Agent 系统，系统梳理了使用场景、交互方式、技术和生态。对于设计完整的人机音乐协作系统，这是很好的领域地图，而不是又一个模型基准。

[image](https://www.google.com/s2/favicons?domain=https://www.wovepaper.com\&sz=32)

wovepaper



[MusiChat: Vibe Composing for Music Creation](https://arxiv.org/abs/2607.24873?utm_source=chatgpt.com) — 2026 年 7 月预印本

将语言模型与符号音乐引擎结合，维护持续演化的乐曲状态，让用户通过多轮自然语言交互修改作品，而不是每次重新生成整首乐曲。

[image](https://www.google.com/s2/favicons?domain=https://www.tempodimare.com\&sz=32)

Tempodimare



这里需要区分两种实时性：Lyria / Magenta RealTime 主要展示持续音频生成和用户控制；JAM_BOT 则更直接研究机器如何听取另一位演奏者的音乐行为并作出回应。两者不能仅凭延迟或音质指标互相替代。

## 四、最容易被忽略的研究：音乐智能到底有没有理解音乐？

我认为这可能是整个领域最重要的问题之一。

[LLMs Can Read Music, but Struggle to Hear It](https://proceedings.mlr.press/v303/carone26a.html?utm_source=chatgpt.com) — 2026

在切分节奏、旋律转调、和弦性质等基础任务中，研究发现部分多模态模型在 MIDI 输入下表现很好，但改用音频后准确率明显下降。即使引入结构化推理，感知层面的困难依然存在。

[image](https://www.google.com/s2/favicons?domain=https://proceedings.mlr.press\&sz=32)

Proceedings of Machine Learning Research



[Music Atelier: Exploring the Knowing–Doing Gap](https://www.ijcai.org/proceedings/2026/614?utm_source=chatgpt.com) — IJCAI 2026

研究了另一个问题：模型可能在推理中正确描述创作意图，却无法把这些意图落实到最终的符号音乐作品中。作者将这种现象称为 Knowing–Doing Gap。

[image](https://www.google.com/s2/favicons?domain=https://www.ijcai.org\&sz=32)

IJCAI



ABC-Eval — ICASSP 2026

专门测试语言模型理解 ABC 记谱法及遵循音乐指令的能力，包含 1,086 个样本和 10 个子任务。对 ABC-AI 的评测扩展尤其直接。

[image](https://www.google.com/s2/favicons?domain=https://aiconfpaper.com\&sz=32)

ICASSP 2026



[CMI-RewardBench](https://www.music-ir.org/mirex/wiki/2026%3AMusic_Evaluation_via_CMI-RewardBench?utm_source=chatgpt.com) — MIREX 2026

研究如何使自动音乐评价与人类偏好一致，重点包括音乐奖励模型和成对偏好判断。这针对的是生成模型评测长期存在的“指标好但人未必喜欢”的问题。

[image](https://www.google.com/s2/favicons?domain=https://www.music-ir.org\&sz=32)

MIREX Wiki



这四项研究共同揭示了一个问题：我们不能只用一个生成指标宣称模型具备音乐智能。

你现在使用的 PPL、音高熵、音级丰富度、节奏一致性等指标仍然有价值，但它们更适合检测统计行为、训练变化和部分音乐特征，无法单独证明动机发展、审美创造力或交互理解能力。

## 五、针对 ABC-AI，我最建议深入的研究问题

你的项目已经包含 C/CUDA 训练器、ABC 表征、转调增广、模型规模实验和音乐学评测。因此，我不会建议立即抛弃这些基础去训练大型音频模型。

更有价值的是利用现有平台回答一些尚未解决的研究问题。

| 研究问题               | 最相关论文                       | 可以设计的实验               |
| ------------------ | --------------------------- | --------------------- |
| 模型是否真正学会转调对称性？     | Moonbeam、MIDI-REPA          | 对比普通数据增广与显式相对音高表示     |
| PPL 降低是否意味着音乐结构改善？ | Hi-ACG、CAST                 | 测量动机重复、变奏、跨段落呼应       |
| 模型能否理解自己生成的乐谱？     | ABC-Eval、MSU-Bench          | 生成后回答关于调性、节奏、曲式的问题    |
| 模型能否遵循明确的创作意图？     | Music Atelier、MusiChat      | 要求模型变奏、转调、修改指定小节并自动验证 |
| 模型能否从乐谱走向富有表现力的演奏？ | Pianist Transformer、MuNo-SP | 在符号生成后学习力度、速度与发音变化    |
| 模型能否成为实时音乐伙伴？      | JAM_BOT、Magenta RT2         | 构建事件流输入、低延迟生成与伴奏反馈循环  |

### 一个值得重点研究的方向：音乐的归纳偏置

你使用十二半音循环群 \\(\mathbb{Z}\_{12}\\) 进行转调增广，这并不仅仅是一种扩大训练集的方法。

它指向一个更深层的问题：

音乐中的数学结构，应该由神经网络从数据中自行发现，还是由模型架构显式表达？

例如，给定旋律 \\(m\\) 和转调算子 \\(T_k\\)，理想的音乐生成或理解系统可能需要满足某种等变性关系：

\\[ f(T_k(m)) \approx T_k(f(m)) \\]

但这并非对所有音乐任务都成立。例如，音色、乐器音域、调性情感和具体演奏习惯可能使不同调之间并不完全等价。

这恰好可以成为一个严谨的研究问题：确定哪些音乐变换应该具有等变性，哪些不应该。

相比单纯训练一个更大的 GPT，这类问题可能更有科学辨识度。

## 六、我建议优先阅读的十篇

阅读清单

0/10 已读

Moonbeam

符号音乐的相对属性与基础模型

MIDI-REPA

符号监督如何改善音频生成

MSU-Bench

完整乐谱理解评测

Music Atelier

理解与实际创作之间的差距

Hi-ACG

长序列音乐结构与锚点

MuNo-SP

统一乐谱与演奏理解

Pianist Transformer

表现力演奏的自监督学习

JAM_BOT

实时人机即兴演奏系统

Magenta RealTime 2

本地实时音乐模型

A Design Space for Live Music Agents

实时音乐 Agent 领域综述

&#x20;复制阅读清单

## 七、目前仍然没有被解决的核心问题

综合这些论文，我认为通用音乐智能仍然存在五个明显的研究缺口：

1. 长程结构：生成模型能否规划、记忆和发展贯穿整首作品的主题，而不只是局部模仿？
2. 跨模态音乐理解：能否在乐谱、MIDI、音频之间保持一致的音乐概念，而不是依赖某一种输入格式？
3. 可验证的创造力：能否证明模型理解并实现了创作意图，而不仅是生成符合训练分布的序列？
4. 实时协作：能否在不预知人类下一步演奏的情况下，持续保持音乐上的协调、变化和主动性？
5. 审美与原创性：如何评价艺术价值、文化差异、创新程度，以及训练数据记忆和版权风险？2026 年的 [TS-RaMIA](https://proceedings.mlr.press/v303/liu26a.html?utm_source=chatgpt.com) 已开始专门研究符号音乐生成模型的训练数据成员推断。

   [image](https://www.google.com/s2/favicons?domain=https://proceedings.mlr.press\&sz=32)

   Proceedings of Machine Learning Research



这里还有一个必须保留的判断：现有研究并没有证明，只要把符号模型、音频模型、语言模型和实时交互系统连接起来，就会自然产生通用音乐智能。 它们可能需要共享表示，也可能需要不同时间尺度上的专门模型与规划机制。

这也是最值得探索的地方。

### 我的结论

2026 年已经出现三条正在汇合的技术路线：

- Moonbeam、MIDI-LLaMA、MSU-Bench：从音乐符号中学习结构与理解。
- MIDI-REPA、MuNo-SP、UALM：连接符号、声音和语言。
- JAM_BOT、Magenta RealTime 2、MusiChat：让音乐智能从离线生成走向实时协作。

对你而言，最值得深挖的不是哪家公司拥有最大的音乐生成模型，而是：

音乐能否像语言一样，拥有一种可学习、可推理、可生成、可演奏、可交互的通用表示？

这可以成为 ABC-AI 从硕士论文实验平台走向长期研究项目的核心科学问题。

以上是一份跨方向的重点研究地图，并非对全部 2026 年论文的穷尽式系统综述；其中也包含预印本和企业技术报告，证据强度需要分别看待。


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
