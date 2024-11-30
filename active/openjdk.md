

# dev

git clone https://github.com/openjdk/jdk.git

mkdir -p bootjdk

wget https://download.java.net/java/GA/jdk23/3c5b90190c68498b986a97f276efd28a/37/GPL/openjdk-23_linux-x64_bin.tar.gz

tar -xzf openjdk-23_linux-x64_bin.tar.gz -C bootjdk --strip-components=1

./bootjdk/bin/java -version

bash configure --with-boot-jdk=$(pwd)/bootjdk

bash configure --with-boot-jdk=/home/a13/tannalwork/jdk/jdk-23.0.1/


# people

involves:albertnetymk
involves:MBaesken
involves:shipilev
involves:jddarcy
involves:tstuefe
involves:magicus
involves:eme64
involves:lahodaj
involves:stefank
involves:jaikiran
involves:coleenp
involves:egahlin
involves:minborg
involves:prsadhuk
involves:naotoj
involves:lmesnik
involves:plummercj
involves:lgxbslgx
involves:djelinski
involves:aivanov-jdk
involves:asotona
involves:iklam
involves:rwestrel
involves:chhagedorn
involves:pavelrappo
involves:JornVernee
involves:jonathan-gibbons
involves:mcimadamore
involves:calvinccheung
involves:cl4es
involves:TheRealMDoerr
involves:zifeihan
involves:biboudis
involves:xmas92
involves:hns
involves:liach
involves:TobiHartmann
involves:wangweij
involves:lkorinth
involves:RealCLanger
involves:kevinjwalls
involves:robehn
involves:prrace
involves:mrserb
involves:jdksjolen
involves:dfuch
involves:sormuras
involves:robcasloz
involves:erikj79
involves:TheShermanTanker
involves:fisk
involves:JimLaskey
involves:pchilano
involves:vidmik
involves:rhalade
involves:feilongjiang
involves:rkennke
involves:JoeWang-Java
involves:rgiulietti
involves:tobiasholenstein
involves:DamonFool
involves:zhengyu123
involves:coffeys
involves:jianglizhou
involves:cushon
involves:RealFYang
involves:reinrich
involves:seanjmullan
involves:dean-long
involves:gctony
involves:jayathirthrao
involves:simonis
involves:Michael-Mc-Mahon
involves:y1yang0
involves:kstefanj
involves:GoeLin
involves:XueleiFan
involves:jcking
involves:jerboaa
involves:shurymury
involves:nick-arm
involves:JesperIRL
involves:ChrisHegarty
involves:RealLucy
involves:slowhog
involves:YaSuenag
involves:edvbld
