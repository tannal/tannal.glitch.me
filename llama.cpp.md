

# people

involves:ggerganov


# inbox


# dev

git clone https://huggingface.co/liuhaotian/llava-v1.6-vicuna-7b

pip install -r examples/llava/requirements.txt

./build/bin/llava -m ggml-model-q5_k.gguf --mmproj mmproj-model-f16.gguf --image path/to/an/image.jpg


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