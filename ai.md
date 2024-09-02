

# inbox


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


