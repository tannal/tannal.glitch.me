

https://github.com/leimao
https://leimao.github.io/essay/%E4%BA%8C%E5%8D%81%E5%A4%9A%E5%B9%B4%E6%9D%A5%E6%88%91%E4%BD%BF%E7%94%A8%E7%9A%84%E8%AE%A1%E7%AE%97%E6%9C%BA%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/

# inbox

host_softmax

cublas
cudnn

# dev

git clone https://github.com/pytorch/pytorch.git

conda create --name pytorch

conda activate pytorch

make setup-env  # or make setup-env-cuda for pre-built CUDA binaries
make setup-env-cuda
conda activate pytorch-deps

MAX_JOBS=4 DEBUG=1 USE_DISTRIBUTED=0 USE_MKLDNN=0 USE_CUDA=1 BUILD_TEST=0 USE_FBGEMM=0 USE_NNPACK=0 USE_QNNPACK=0 USE_XNNPACK=0 python3 setup.py develop

# people

involves:ezyang
involves:malfet
involves:zou3519
involves:cyyever
involves:anijain2305
involves:huydhn
involves:awgu
involves:peterbell10
involves:jansel
involves:desertfire
involves:clee2000
involves:eellison
involves:wanchaol
involves:yanboliang
involves:angelayi
involves:mlazos
involves:wconstab
involves:drisspg
involves:lezcano
involves:fegin
involves:wz337
involves:bdhirsh
involves:Skylion007
involves:janeyx99
involves:williamwen42
involves:Chillee
involves:jerryzh168
involves:pytorchupdatebot
involves:oulgen
involves:tugsbayasgalan
involves:voznesenskym
involves:XuehaiPan
involves:eqy
involves:BowenBao
involves:ydwu4
involves:davidberard98
involves:dagitses
involves:soulitzer
involves:leslie-fang-intel
involves:nkaretnikov
involves:albanD
involves:XiaobingSuper
involves:shunting314
involves:atalman
involves:mikaylagawarecki
involves:jbschlosser
involves:rohan-varma
involves:zhxchen17
involves:kit1980
involves:kshitij12345
involves:ngimel
involves:pearu
involves:H-Huang
involves:r-barnes
involves:mrshenli
involves:zdevito
involves:jeffdaily
involves:kurtamohler
involves:swolchok
involves:suo
involves:vfdev-5
involves:kimishpatel
involves:SS-JIA
involves:bertmaher
involves:IvanYashchuk
involves:jjsjann123
involves:vkuzo
involves:IvanKobzarev
involves:seemethere
involves:Krovatkin
involves:cpuhrsch
involves:anjali411
involves:houseroad
involves:zasdfgbnm
involves:lw
involves:z-a-f
involves:soumith
involves:jspark1105
involves:colesburyinvolves: