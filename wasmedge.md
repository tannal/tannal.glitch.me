# people

# inbox

{
    "version": 2,
    "configurePresets": [
        {
            "name": "wasmedge",
            "displayName": "Clang 17.0.6 x86_64-pc-windows-msvc",
            "description": "Using compilers: C = C:\\Program Files\\LLVM\\bin\\clang.exe, CXX = C:\\Program Files\\LLVM\\bin\\clang++.exe",
            "binaryDir": "${sourceDir}/out/build/${presetName}",
            "generator": "Ni",
            "cacheVariables": {
                "CMAKE_INSTALL_PREFIX": "${sourceDir}/out/install/${presetName}",
                "CMAKE_C_COMPILER": "C:/Program Files/LLVM/bin/clang.exe",
                "CMAKE_CXX_COMPILER": "C:/Program Files/LLVM/bin/clang++.exe",
                "CMAKE_BUILD_TYPE": "Debug",
                "CMAKE_SYSTEM_VERSION": "10.0.19041.0",
                "CMAKE_MSVC_RUNTIME_LIBRARY": "MultiThreadedDLL",
                "LLVM_DIR": "C:\\Users\\tannal\\Downloads\\LLVM-16.0.6-win64\\lib\\cmake\\llvm",
                "WASMEDGE_BUILD_TESTS": "ON",
                "WASMEDGE_BUILD_PACKAGE": "ZIP"
            }
        }
    ]
}

utilBlake3
spdlog
wasmedgeCommon
wasmedgeSystem
wasmedgeAOT
wasmedgeLLVM
wasmedgeLoaderFileMgr
wasmedgePO
wasmedgePlugin
wasmedgeLoader
wasmedgeValidator
wasmedgeExecutor
wasmedgeHostModuleWasi
wasmedgeVM
wasmedgeDriver
wasmedgeCAPI
wasmedge_shared

export PATH=/home/tannal/tannalwork/projects/wasmEdge/_install/bin/:$PATH

b resolvePath

git clone https://github.com/WebAssembly/wasi-testsuite

git switch prod/testsuite-base

virtualenv venv
source venv/bin/activate
pip install -r test-runner/requirements.txt

export TEST_RUNTIME_EXE="/home/tannal/tannalwork/projects/wasmEdge/_install/bin/wasmedge"

python3 test-runner/wasi_test_runner.py -t ./tests/c/testsuite/pwrite-with-append.wasm -r ../wasmEdge/.github/scripts/wasi-testsuite-adapter.py

python3 test-runner/wasi_test_runner.py -t ./tests/rust/testsuite/unlink_file_trailing_slashes -r ../wasmEdge/.github/scripts/wasi-testsuite-adapter.py

export RUST_BACKTRACE=1

python3 test-runner/wasi_test_runner.py -t ./tests/assemblyscript/testsuite/ ./tests/c/testsuite/ ./tests/rust/testsuite/ -r ../wasmEdge/.github/scripts/wasi-testsuite-adapter.py

python3 test-runner/wasi_test_runner.py \
-t ./tests/assemblyscript/testsuite/ \
-r ../wasmEdge/.github/scripts/wasi-testsuite-adapter.py

TEST_RUNTIME_EXE="../wasmEdge/_install/bin/wasmedge --wasm-features all" \
python3 test-runner/wasi_test_runner.py \
-t ./tests/assemblyscript/testsuite/ ./tests/c/testsuite/ ./tests/rust/testsuite/ \
-r ../wasmEdge/.github/scripts/wasi-testsuite-adapter.py

 pwrite-with-append
 unlink_file_trailing_slashes

ctest -R <test_name_pattern>



cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Debug -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF -DWASMEDGE_BUILD_TESTS=ON -DCMAKE_INSTALL_PREFIX=`pwd`/_install .



$vsPath = (vswhere -latest -property installationPath)


wasmedgeLLVMCoreTests


python3 test-runner/wasi_test_runner.py -t ./tests/assemblyscript/testsuite/ ./tests/c/testsuite/ ./tests/rust/testsuite/ -r ../WasmEdge/.github/scripts/wasi-testsuite-adapter.py


# dev

```bash
$env:HTTP_PROXY = "http://192.168.43.1:7890"
$env:HTTPS_PROXY = "http://192.168.43.1:7890"


set http_proxy=http://192.168.43.1:7890
set https_proxy=http://192.168.43.1:7890

git clone https://github.com/WasmEdge/WasmEdge.git -b hydai/0.13.5_ggml_lts

$env:LLVM_DIR = "C:\\Program Files\\LLVM\\lib\\cmake"
$env:LLVM_DIR = "C:/Program Files/LLVM/lib/cmake"

cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Release -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_METAL=ON -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF .

```
```bash

git checkout upstream/hydai/0.13.5_ggml_lts

git status

cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Release -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF .

cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Debug -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF -DCMAKE_INSTALL_PREFIX=`pwd`/_install .

cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Debug -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF -DLLVM_DIR="C:\Users\tannal\Downloads\llvm-18.1.0rc2.src\llvm-18.1.0rc2.src\cmake" -DCMAKE_INSTALL_PREFIX=`pwd`/_install .


ninja -C build

cmake --install build

mkdir -p local

cd local/

curl -LO https://github.com/second-state/LlamaEdge/releases/latest/download/llama-api-server.wasm

curl -LO https://huggingface.co/second-state/Llama-2-7B-Chat-GGUF/resolve/main/Llama-2-7b-chat-hf-Q5_K_M.gguf

gdb wasmedge

b ggml.cpp:415

r --dir . --nn-preload default:GGML:AUTO:llama-2-7b-chat.Q5_K_M.gguf llama-api-server.wasm -p llama-2-chat

wasmedge --dir . --nn-preload default:GGML:AUTO:Llama-2-7b-chat-hf-Q5_K_M.gguf llama-api-server.wasm  -p llama-2-chat

apt update && apt install httpie lsof htop jq

apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r` 

http POST http://localhost:8080/v1/models Accept:application/json

echo '{
  "messages": [
    {
      "role": "system",
      "content": "You are a helpful assistant."
    },
    {
      "role": "user",
      "content": "Who is Taylor Swift?"
    }
  ],
  "model": "llama-2-chat"
}' | http POST http://localhost:8080/v1/chat/completions Accept:application/json Content-Type:application/json



echo '{"prompt":["To be or not to be, "], "model":"tinyllama"}' | http POST http://localhost:8080/v1/completions Accept:application/json Content-Type:application/json

```