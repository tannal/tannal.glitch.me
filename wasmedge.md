

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