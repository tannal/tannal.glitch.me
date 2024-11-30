

# people

WHISPER_CUDA=1 make -j 

cmake . -DCMAKE_C_FLAGS="-mfpu=neon-fp-armv8 -mfp16-format=ieee -mno-unaligned-access -funsafe-math-optimizations"

involves:ggerganov

curl -C - -L -O https://huggingface.co/QuantFactory/Meta-Llama-3-8B-Instruct-GGUF/resolve/main/Meta-Llama-3-8B-Instruct.Q3_K_L.gguf

curl -C - -L -O https://huggingface.co/QuantFactory/Meta-Llama-3-70B-Instruct-GGUF-v2/resolve/main/Meta-Llama-3-70B-Instruct-v2.Q3_K_L.gguf

# inbox

git clone https://github.com/ggerganov/llama.cpp

cmake -G Ninja -B build -DLLAMA_CUDA=ON
cmake --build build --config Release

llm.c

conda install -c conda-forge cudnn

make train_gpt2cu USE_CUDNN=1

https://huggingface.co/datasets/karpathy/llmc-starter-pack/resolve/main/

ffmpeg -i J -vn -ar 16000 -ac 2 -ab 160k poor.wav

./main -m models/ggml-large-v3.bin -f poor. -l ja poor.wav


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



mkdir vit
cp ../llava-v1.6-vicuna-7b/llava.clip vit/pytorch_model.bin
cp ../llava-v1.6-vicuna-7b/llava.projector vit/
curl -s -q https://huggingface.co/cmp-nct/llava-1.6-gguf/raw/main/config_vit.json -o vit/config.json


./llava-cli -m ../llava-v1.6-vicuna-7b/ggml-model-f32.gguf --mmproj vit/mmproj-model-f16.gguf --image image.png -c 4096
./llava-cli -m ../llava-v1.6-vicuna-7b/ggml-model-f32.gguf --mmproj vit/mmproj-model-f16.gguf --image image-1.png -c 4096


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


# people

llama.cpp
involves:ggerganov
involves:slaren
involves:phymbert
involves:ikawrakow
involves:Kawrakow
involves:cebtenzzre
involves:JohannesGaessler
involves:danbev
involves:ngxson
involves:NeoZhangJianyu
involves:abhilash1910
involves:SomeoneSerge
involves:compilade
involves:AidanBeltonS
involves:0cc4m
involves:dranger003
involves:mscheong01
involves:Xarbirus
involves:iamlemec
involves:ochafik
involves:ptsochantaris
involves:HanClinto
involves:hutli
involves:cmp-nct
involves:z80maniac
involves:jart
involves:kaetemi
involves:airMeng
involves:azarovalex
involves:ZiangWu-77
involves:netrunnereve
involves:mofosyne
involves:Maximilian-Winter
involves:dokterbob
involves:ibehnam
involves:m18coppola
involves:GermanAizek
involves:Engininja2
involves:leejet
involves:simonJJJ
involves:howlger
involves:bobqianic
involves:akx
involves:l3utterfly
involves:MarcusDunn
involves:mgroeber9110
involves:przemoc
involves:BarfingLemurs
involves:jxy
involves:crasm
involves:foldl
involves:kalomaze
involves:ensan-hcl
involves:eltociear
involves:LostRuins
involves:goerch
involves:Green-Sky
involves:SlyEcho



whisper.cpp
involves:ggerganov
involves:slaren
involves:ikawrakow
involves:Kawrakow
involves:bobqianic
involves:JohannesGaessler
involves:przemoc
involves:nalbion
involves:abhilash1910
involves:NeoZhangJianyu
involves:jhen0409
involves:didzis
involves:0cc4m
involves:cebtenzzre
involves:marmistrz
involves:ulatekh
involves:Xarbirus
involves:AidanBeltonS
involves:felrock
involves:ptsochantaris
involves:josharian
involves:bjnortier
involves:compilade
involves:leejet
involves:alonfaraj
involves:dokterbob
involves:Engininja2
involves:luciferous
involves:zhouwg
involves:airMeng
involves:finnvoor
involves:tamo
involves:Digipom
involves:pprobst
involves:litongjava
involves:eschmidbauer
involves:denersc
involves:Kreijstal
involves:mkiol
involves:nchudleigh
involves:AustinMroz
involves:ghindle
involves:RhinoDevel
involves:goncha
involves:RyanMetcalfeInt8
involves:azarovalex
involves:akashmjn
involves:JacobLinCool
involves:jmousseau
involves:Theldus
involves:bmtwl
involves:manyoso
involves:snadampal
involves:ejones
involves:sandrohanea
involves:primenko-v
involves:jart
involves:danbev
involves:Rakksor
involves:texmex76
involves:OuadiElfarouki
involves:contractorwolf
involves:sonphantrung
involves:gleicon
involves:blib
involves:slashlib
involves:4imothy
involves:Halalaluyafail3
involves:kzhuravl
involves:nank1ro
involves:Green-Sky
involves:Okabintaro
involves:rotemdan
involves:philloooo
involves:eltociear
involves:jwijffels
involves:genevera
involves:DGdev91
involves:herrera-luis



ggml
involves:ggerganov
involves:slaren
involves:ikawrakow
involves:Kawrakow
involves:JohannesGaessler
involves:abhilash1910
involves:0cc4m
involves:NeoZhangJianyu
involves:AidanBeltonS
involves:cebtenzzre
involves:airMeng
involves:ptsochantaris
involves:compilade
involves:Xarbirus
involves:ulatekh
involves:Engininja2
involves:leejet
involves:foldl
involves:bobqianic
involves:josharian
involves:dokterbob
involves:wilderfield
involves:certik
involves:didzis
involves:azarovalex
involves:danbev
involves:jart
involves:snadampal
involves:jmousseau
involves:JacobLinCool
involves:tamo
involves:Theldus
involves:bssrdf
involves:bmtwl
involves:GermanAizek
involves:luciferous
involves:manyoso
involves:FSSRepo
involves:github-actions[bot]
involves:phymbert
involves:ngxson
involves:LiangtaoJin
involves:zhouwg
involves:F1L1Pv2
involves:amiralimi
involves:MeizuToB
involves:GainLee
involves:TheFlipbook
involves:joliss
involves:denersc
involves:sanchit-gandhi
involves:arthur0824hao
involves:OuadiElfarouki
involves:primenko-v
involves:Carolinabanana
involves:rotemdan
involves:bradmurray-dt
involves:justcho5
involves:dscripka
involves:slp
involves:ananta
involves:irbull
involves:tom7
involves:JidongZhang-THU
involves:felrock
involves:siddharthvader
involves:niansa
involves:ToKiNoBug
involves:apage43
involves:uextm
involves:rgryta
involves:gwenzek
involves:LostRuins
involves:abetlen
involves:iboB
