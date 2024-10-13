

# dev

# 1. Download the CUDA keyring package
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.0-1_all.deb

# 2. Install the keyring package
sudo dpkg -i cuda-keyring_1.0-1_all.deb

# 3. Update the APT database
sudo apt update

# 4. Install NCCL libraries
# If you want the latest version:
sudo apt install libnccl2 libnccl-dev

# If you want a specific version (example with CUDA 10.0):
# sudo apt install libnccl2=2.4.8-1+cuda10.0 libnccl-dev=2.4.8-1+cuda10.0

# 5. Verify the installation
dpkg -l | grep nccl

# 更新系统
sudo apt update
sudo apt upgrade

# 重新安装 CUDA（如果需要）
sudo apt install cuda

/datapool/home/ph_teacher2/anaconda3/envs/tm_cuda11/bin/gcc -Ofast -Wno-unused-result -Wno-ignored-pragmas -Wno-unknown-attributes -march=native -fopenmp -DOMP   train_gpt2.c -lm -lgomp -o train_gpt2

/datapool/home/ph_teacher2/anaconda3/envs/tm_cuda11/bin/gcc -Ofast -Wno-unused-result -Wno-ignored-pragmas -Wno-unknown-attributes -march=native -fopenmp -DOMP   test_gpt2.c -lm -lgomp -o test_gpt2


/datapool/home/ph_teacher2/anaconda3/envs/tm_cuda11/bin/nvcc -I/datapool/home/ph_teacher2/anaconda3/envs/tm-pytorch-cuda/include/  --threads=0 -t=0 --use_fast_math -std=c++17 -O3 -DMULTI_GPU -DUSE_MPI -DENABLE_BF16 train_gpt2.cu -lcublas -lcublasLt -lnvidia-ml -L/datapool/home/ph_teacher2/anaconda3/envs/tm-pytorch-cuda/lib/ -L/opt/ohpc/pub/mpi/openmpi4-gnu12/4.1.4/lib/  -I/opt/ohpc/pub/mpi/openmpi4-gnu12/4.1.4/include/  -lnccl -lmpi -o train_gpt2cu

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


pip install numpy -i https://pypi.tuna.tsinghua.edu.cn/simple


https://github.com/OFA-Sys


https://github.com/QwenLM



这是一个GPT-2模型训练的输出日志。我来解释一下主要内容:

首先列出了训练的各项参数设置,包括数据路径、batch size、学习率等。
模型配置:
使用GPT-2 124M参数量的模型
序列长度1024
12层,12个注意力头,768维隐藏层
训练设置:
使用单个NVIDIA A800 80GB GPU
BF16精度
总batch size 458752
Cosine学习率调度
使用梯度累积,每8步更新一次参数
内存使用:
模型参数:237MB
梯度:237MB
激活值:18564MB
优化器状态:474MB * 2
总计:21315MB / 81100MB可用
训练过程:
每一步显示loss、梯度范数、学习率、耗时等
Loss从11左右开始下降
学习率逐步增加(warmup阶段)
每步处理约19万token/秒
总的来说,这显示了训练的初始阶段,模型正在正常学习,loss在逐步下降。训练看起来运行正常,GPU利用率良好。

➜   |tm_cuda11|llm.c git:(master ?:1) ✗ ./train_gpt2cu \
>     -i "dev/data/edu_fineweb10B/edu_fineweb_train_*.bin" \
>     -j "dev/data/edu_fineweb10B/edu_fineweb_val_*.bin" \
>     -o log124M \
>     -e "d12" \
>     -b 56 -t 1024 \
>     -d 458752 \
>     -r 1 \
>     -z 1 \
>     -c 0.1 \
>     -l 0.002 \
>     -q 0.0 \
>     -u 700 \
>     -n 5000 \
>     -v 250 -s 20000 \
>     -h 1
Multi-GPU support is disabled. Using a single GPU.
+-----------------------+----------------------------------------------------+
| Parameter             | Value                                              |
+-----------------------+----------------------------------------------------+
| train data pattern    | dev/data/edu_fineweb10B/edu_fineweb_train_*.bin    |
| val data pattern      | dev/data/edu_fineweb10B/edu_fineweb_val_*.bin      |
| output log dir        | log124M                                            |
| checkpoint_every      | 5000                                               |
| resume                | 0                                                  |
| micro batch size B    | 56                                                 |
| sequence length T     | 1024                                               |
| total batch size      | 458752                                             |
| LR scheduler          | cosine                                             |
| learning rate (LR)    | 2.000000e-03                                       |
| warmup iterations     | 700                                                |
| final LR fraction     | 0.000000e+00                                       |
| weight decay          | 1.000000e-01                                       |
| skip update lossz     | 0.000000                                           |
| skip update gradz     | 0.000000                                           |
| max_steps             | -1                                                 |
| val_loss_every        | 250                                                |
| val_max_steps         | 20                                                 |
| sample_every          | 20000                                              |
| genT                  | 64                                                 |
| overfit_single_batch  | 0                                                  |
| use_master_weights    | enabled                                            |
| gelu_fusion           | 0                                                  |
| recompute             | 1                                                  |
+-----------------------+----------------------------------------------------+
| device                | NVIDIA A800 80GB PCIe                              |
| peak TFlops           | -1.0                                               |
| precision             | BF16                                               |
+-----------------------+----------------------------------------------------+
| weight init method    | d12                                                |
| max_sequence_length T | 1024                                               |
| vocab_size V          | 50257                                              |
| padded_vocab_size Vp  | 50304                                              |
| num_layers L          | 12                                                 |
| num_heads NH          | 12                                                 |
| channels C            | 768                                                |
| num_parameters        | 124475904                                          |
+-----------------------+----------------------------------------------------+
| train_num_batches     | 21479                                              |
| val_num_batches       | 20                                                 |
+-----------------------+----------------------------------------------------+
| run hellaswag         | yes                                                |
+-----------------------+----------------------------------------------------+
| num_processes         | 1                                                  |
| zero_stage            | 1                                                  |
+-----------------------+----------------------------------------------------+
num_parameters: 124475904 => bytes: 248951808
allocated 237 MiB for model parameters
batch_size B=56 * seq_len T=1024 * num_processes=1 and total_batch_size=458752
=> setting grad_accum_steps=8
created directory: log124M
allocating 237 MiB for parameter gradients
allocating 18564 MiB for activations
allocating 474 MiB for AdamW optimizer state m
allocating 474 MiB for AdamW optimizer state v
allocating 474 MiB for master copy of params
device memory usage: 21315 MiB / 81100 MiB
memory per sequence: 331 MiB
 -> estimated maximum batch size: 236
val loss 11.006021
step    1/21479 | loss 11.007906 (+nanz)| norm 16.3235 (+nanz)| lr 2.86e-06 | 2734.72 ms | -100.0% bf16 MFU | 167751 tok/s
step    2/21479 | loss 10.829729 (+nanz)| norm 15.0011 (+nanz)| lr 5.71e-06 | 2391.52 ms | -100.0% bf16 MFU | 191824 tok/s
step    3/21479 | loss 10.543671 (+nanz)| norm 11.0997 (+nanz)| lr 8.57e-06 | 2397.11 ms | -100.0% bf16 MFU | 191595 tok/s
step    4/21479 | loss 10.277939 (+nanz)| norm 7.9684 (+nanz)| lr 1.14e-05 | 2396.56 ms | -100.0% bf16 MFU | 191534 tok/s
step    5/21479 | loss 10.107232 (+nanz)| norm 5.9631 (+nanz)| lr 1.43e-05 | 2396.87 ms | -100.0% bf16 MFU | 191497 tok/s
step    6/21479 | loss 9.917295 (+nanz)| norm 4.6826 (+nanz)| lr 1.71e-05 | 2404.90 ms | -100.0% bf16 MFU | 191333 tok/s
step    7/21479 | loss 9.825548 (+nanz)| norm 3.5459 (+nanz)| lr 2.00e-05 | 2405.19 ms | -100.0% bf16 MFU | 191220 tok/s
step    8/21479 | loss 9.711181 (+nanz)| norm 2.9610 (+nanz)| lr 2.29e-05 | 2406.14 ms | -100.0% bf16 MFU | 191127 tok/s
step    9/21479 | loss 9.664068 (+nanz)| norm 2.5259 (+nanz)| lr 2.57e-05 | 2411.29 ms | -100.0% bf16 MFU | 190997 tok/s
step   10/21479 | loss 9.594637 (+nanz)| norm 2.3978 (+nanz)| lr 2.86e-05 | 2409.28 ms | -100.0% bf16 MFU | 190918 tok/s
step   11/21479 | loss 9.574575 (+nanz)| norm 2.2855 (+nanz)| lr 3.14e-05 | 2414.74 ms | -100.0% bf16 MFU | 190801 tok/s
step   12/21479 | loss 9.544209 (+nanz)| norm 2.2411 (+nanz)| lr 3.43e-05 | 2414.70 ms | -100.0% bf16 MFU | 190706 tok/s
step   13/21479 | loss 9.486968 (+nanz)| norm 2.2670 (+nanz)| lr 3.71e-05 | 2421.24 ms | -100.0% bf16 MFU | 190572 tok/s
step   14/21479 | loss 9.463285 (+nanz)| norm 2.1770 (+nanz)| lr 4.00e-05 | 2422.23 ms | -100.0% bf16 MFU | 190450 tok/s
step   15/21479 | loss 9.428789 (+nanz)| norm 2.1139 (+nanz)| lr 4.29e-05 | 2424.46 ms | -100.0% bf16 MFU | 190330 tok/s
step   16/21479 | loss 9.384840 (+nanz)| norm 2.0431 (+nanz)| lr 4.57e-05 | 2427.78 ms | -100.0% bf16 MFU | 190203 tok/s
step   17/21479 | loss 9.342413 (+nanz)| norm 2.0194 (+nanz)| lr 4.86e-05 | 2426.05 ms | -100.0% bf16 MFU | 190104 tok/s
step   18/21479 | loss 9.301134 (+nanz)| norm 2.0209 (+nanz)| lr 5.14e-05 | 2427.20 ms | -100.0% bf16 MFU | 190009 tok/s
step   19/21479 | loss 9.205302 (+nanz)| norm 1.9532 (+nanz)| lr 5.43e-05 | 2435.94 ms | -100.0% bf16 MFU | 189870 tok/s
step   20/21479 | loss 9.154282 (+nanz)| norm 2.1207 (+nanz)| lr 5.71e-05 | 2439.00 ms | -100.0% bf16 MFU | 189727 tok/s
step   21/21479 | loss 9.094215 (+nanz)| norm 2.1476 (+nanz)| lr 6.00e-05 | 2444.94 ms | -100.0% bf16 MFU | 189563 tok/s
step   22/21479 | loss 9.055355 (+nanz)| norm 3.1994 (+nanz)| lr 6.29e-05 | 2449.6



# people


author:karpathy
author:ngc92
author:gordicaleksa
author:ademeure
author:rosslwheeler
author:lancerts
author:ChrisDryden
author:chinthysl
author:JaneIllario
author:dagelf
author:vyom1611
author:Ricardicus
author:azret
author:al0vya
author:KarhouTam
author:austinvhuang
author:PeterZhizhin
author:mspronesti
author:zhangpiu
author:nopperl
author:msaroufim
author:krrishnarraj
author:Anerudhan
author:abhilash1910author: