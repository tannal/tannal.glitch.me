

# people

involves:ggerganov


# inbox

sudo dnf install bcc-tools kernel-devel-$(uname -r) kernel-headers-$(uname -r)

export http_proxy=http://10.90.128.8:7890
export https_proxy=http://10.90.128.8:7890

Done!
Now you can convert ../llava-v1.6-vicuna-7b/ to a a regular LLaMA GGUF file.
Also, use ../llava-v1.6-vicuna-7b//llava.projector to prepare a llava-encoder.gguf file.

%matplotlib notebook

source ~/tannalwork/tannal/bin/activate

# dev

git clone https://huggingface.co/liuhaotian/llava-v1.6-vicuna-7b

pip install -r examples/llava/requirements.txt

./build/bin/llava -m ggml-model-q5_k.gguf --mmproj mmproj-model-f16.gguf --image path/to/an/image.jpg




mkdir vit
cp ../llava-v1.6-vicuna-7b/llava.clip vit/pytorch_model.bin
cp ../llava-v1.6-vicuna-7b/llava.projector vit/
curl -s -q https://huggingface.co/cmp-nct/llava-1.6-gguf/raw/main/config_vit.json -o vit/config.json


./llava-cli -m ../llava-v1.6-vicuna-7b/ggml-model-f32.gguf --mmproj vit/mmproj-model-f16.gguf --image image.png -c 4096


```bash

git clone https://github.com/ggerganov/ggml
cd ggml
# Install python dependencies in a virtual environment
python -m venv ggml_env

.\ggml_env\Scripts\activate
source ./ggml_env/bin/activate

pip install -r requirements.txt

# Build the examples
cmake -B build -G ninja

ninja -C build -j4 mnist-cnn mnist

minist.exe

python examples/mnist/mnist-cnn.py train mnist-cnn-model

```