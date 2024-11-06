# inbox

cmake -S llvm  -DCMAKE_INSTALL_PREFIX=/usr/local=/opt/llvm/ -B build -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld' -DCMAKE_BUILD_TYPE=Release \
    -DLLVM_BUILD_LLVM_DYLIB=ON \
    -DLLVM_LINK_LLVM_DYLIB=ON \
    -DCMAKE_INSTALL_PREFIX=/opt/llvm \
    -DLLVM_ENABLE_RTTI=ON \
    -DCOMPILER_RT_BUILD_SANITIZERS=ON \
    -DCOMPILER_RT_BUILD_XRAY=ON \
    -DCOMPILER_RT_BUILD_LIBFUZZER=ON

High Level:
    Program
        └── BinaryModule
            └── BinaryContext
                
Same Level:
    ├── BinaryFunction
    ├── BinarySection
    ├── BinaryData
    └── Symbol

Low Level:
    BinaryFunction
        ├── BinaryBasicBlock
        │   └── MCInst
        ├── JumpTable
        └── Relocation

gh workflow run "LLVM Project Tests" --ref main

cmake -G Ninja -B build -DLT_LLVM_INSTALL_DIR=/usr/lib/llvm-18/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
ln -sfn /build/compile_commands.json compile_commands.json

export DOCKER_HOST="tcp://192.168.43.62:2375"
$env:DOCKER_HOST="tcp://192.168.43.62:2375"
set DOCKER_HOST="tcp://192.168.43.62:2375"

/usr/lib/llvm-18/bin/clang++ -emit-llvm -S -O1 HelloWorld/HelloWorld.cpp -o test.ll

/usr/lib/llvm-18/bin/opt -load-pass-plugin lib/libHelloWorld.so -passes=hello-world,hello-world --disable-output ../input_for_hello.ll

./build/bin/clang++ ~/tannalwork/cans/lambda.cc -o lambda

clang/lib/Lex/Lexer.cpp

GEP get element pointer
InstCombiner

cmake -G Ninja -B build -DLT_LLVM_INSTALL_DIR=/opt/llvm-17/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
. -DClang_DIR=/opt/llvm-17/lib/cmake/clang/


ActOnDeclarator
clang::Sema::ActOnDeclarator



sudo perf record --call-graph dwarf  -F 99 -p 14546 -g -- sleep 30

sudo perf record -F 99 -p $(pidof /opt/llvm/clang -c ~/tannalwork/) -g -- sleep 30
export CC=/opt/llvm-17/bin/clang
export CXX=/opt/llvm-17/bin/clang++
cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'

sudo perf record -F 99 -p `pgrep -n cc1` -g -- sleep 30
sudo perf record -F 99 -p `pgrep -n ` -g -- sleep 30

sudo perf script > out.clangstacks01
./stackcollapse-perf.pl < out.clangstacks01 | ./flamegraph.pl > ./out.clangstacks01.svg


$LLVM_DIR/bin/clang -S -emit-llvm ./host/test.c -o test.ll

$LLVM_DIR/bin/opt test.ll -passes=loop-unroll -disable-output -S -o example_unrolled.ll

PreservedAnalyses LoopVectorizePass::run(Function &F,
                                         FunctionAnalysisManager &AM)

git remote add upstream https://github.com/llvm/llvm-project
git remote set-url upstream https://github.com/llvm/llvm-project
git fetch upstream release/17.x
git checkout release/17.x

xargs rm < install_manifest.txt

cmake -S llvm -B out/llvm-17/ -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld;compiler-rt' -DCMAKE_BUILD_TYPE='Debug' -DLLVM_USE_LINKER=lld -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DLLVM_BUILD_LLVM_DYLIB=ON -DCMAKE_C_FLAGS_DEBUG="-g3 -Og" -DCMAKE_CXX_FLAGS_DEBUG="-g3 -Og" -DCMAKE_INSTALL_PREFIX=/opt/llvm-17/

cmake --install out/llvm-17

cmake -G Ninja -B host -DLT_LLVM_INSTALL_DIR=/opt/llvm/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
cmake --build host

export LLVM_DIR=/opt/llvm
$LLVM_DIR/bin/clang -O1 -S -emit-llvm ./inputs/input_for_mba.c -o input_for_mba_host.ll
$LLVM_DIR/bin/opt -load-pass-plugin ./host/lib/libMBAAdd.so -passes="mba-add" -disable-output input_for_mba_host.ll -debug

export LLVM_DIR=/opt/llvm
$LLVM_DIR/bin/clang -O1 -S -emit-llvm ./inputs/input_for_hello.c -o input_for_hello.ll
$LLVM_DIR/bin/opt -load-pass-plugin ./host/lib/libHelloWorld.so -passes=hello-world -disable-output input_for_hello.ll

the preproccessor holds the reference of lexer in llvm

Type Stmt Expr Decl

gdb --args ./build/bin/clang ~/tannalwork/c-workspace/exe_mmap_linux.c
rb BasicBlock.cpp:.
rb Instruction.cpp:.
rb TokenLexer.cpp:.
rb Preprocessor.cpp:.

set follow-fork-mode child

cmake -G Ninja -B build -DLT_LLVM_INSTALL_DIR=/opt/llvm/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .


export LLVM_DIR=/opt/llvm
mkdir -p $LLVM_DIR
cmake -B build -DCMAKE_INSTALL_PREFIX=$LLVM_DIR llvm
sudo cmake --install build
phi node

int main() {
 int a = 5;
 int b = 3;
 return a - b;
}

TraslationUnit
- Type Dec
- Func Dec
  - Dec Stmt
  - Dec Stmt
  - Ret Stmt

programming languages and their compilers
https://www.softwarepretrvation.org/projects/FORTRAN/CockeSchwartz_ProgLangCompilers.pdf

https://github.com/llvm/llvm-project/blob/8389b3bf60ef3fbd04c6efc5ff4d4605d10e7fc5/llvm/include/llvm/IR/CFG.h#L42
PredIterator
SuccIterator

If don't pay over attension to things you can not immediately unserstand
It will add noise.

Basic Block
llvm-project/llvm/include/llvm/IR/BasicBlock.h
BasicBLock
-InstListType InstList
-Function *Parent;

predecessors

HyPer uses Just-In-Time (JIT) compilation to generate LLVM codes for the incoming queries, which boosts the performance of the database and minimizes the memory traffic.

MLIR https://github.com/llvm/llvm-project/commits?author=kuhar

https://github.com/llvm/clangir/commits/main/?author=bcardosolopes

https://github.com/llvm/llvm-project/commits?author=asb RSIC-V iaglian

https://github.com/regehr

https://discourse.llvm.org/tag/gsoc2024

https://llvmweekly.org/issue/529

https://github.com/llvm/llvm-project/commits/main/?author=lhames

llvm optimization remarks https://www.youtube.com/watch?v=qmEsx4MbKoc

FAROS https://github.com/LLNL/FAROS

llvm pass analysis tranformation

remove dead instructions

pass managers record what's preserved

opt ninja's best friend

.ll -> .ll optimization same sematics

opt add.ll -dot-cfg -o output.ll

opt -aa-pipeline=basic-aa -passes='print<memoryssa>' -dot-cfg-mssa=out.dot < add.ll 2>&1 > /dev/null

cl::opt<bool>

cfg

```c
// clang -emit-llvm -c example.c -o example.bc
// opt -dot-cfg example.bc -o /dev/null
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int c;

    if (a < b) {
        c = a + b;
    } else {
        c = a - b;
    }

    for (int i = 0; i < 5; i++) {
        c += i;
    }

    printf("Result: %d\n", c);

    return 0;
}


```
# LLVM tutor

```bash
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
sudo apt-add-repository "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-17 main"
sudo apt-get update
sudo apt-get install -y llvm-17 llvm-17-dev llvm-17-tools clang-17 mlir-17 mlir-17-tools
```

$LLVM_DIR/bin/clang -O1 -S -emit-llvm ./inputs/input_for_hello.c -o input_for_hello.ll

```bash

wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
sudo apt-add-repository "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-17 main"
sudo apt-get update
sudo apt-get install -y llvm-17 llvm-17-dev llvm-17-tools clang-17

git clone https://github.com/banach-space/llvm-tutor.git

dpkg -L llvm

cmake -G Ninja -B build -DLT_LLVM_INSTALL_DIR=/usr/lib/llvm-17/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .


ninja clean -C build
ninja -C build

ln -sfn /build/compile_commands.json compile_commands.json


clang -emit-llvm -S -O1 ../../cp/add.ll

/usr/lib/llvm-17/bin/opt -load-pass-plugin lib/libHelloWorld.so -passes=hello-world,hello-world --disable-output ../input_for_hello.ll

PassInfoMixin

```
# MLIR

https://github.com/llvm/torch-mlir




# Build LLVM from source

# Tests

```bash

ninja check-llvm-unit

llvm/unittests

```

Google Test

FileCheck

Lit

Google Benchmark

LNT

Build Bots

```bash

export PATH="/usr/lib/ccache/:$PATH"

sudo apt-get -y install ninja-build

git clone --depth 1 https://github.com/llvm/llvm-project.git


cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld' -DCMAKE_BUILD_TYPE='Release' -DLLVM_ENABLE_RUNTIMES='openmp' -DLLVM_USE_LINKER=lld -DCMAKE_EXPORT_COMPILE_COMMANDS=ON


cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld;compiler-rt' -DCMAKE_BUILD_TYPE='Debug' -DLLVM_ENABLE_RUNTIMES='openmp' -DLLVM_USE_LINKER=lld -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DLLVM_BUILD_LLVM_DYLIB=ON -DLLVM_LINK_LLVM_DYLIB=ON -DCMAKE_C_FLAGS_DEBUG="-g3 -Og" -DCMAKE_CXX_FLAGS_DEBUG="-g3 -Og"


cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld' -DCMAKE_BUILD_TYPE='Debug' -DLLVM_ENABLE_RUNTIMES='openmp' -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DLLVM_BUILD_LLVM_DYLIB=ON -DLLVM_LINK_LLVM_DYLIB=ON -DCMAKE_C_FLAGS_DEBUG="-g3 -Og" -DCMAKE_CXX_FLAGS_DEBUG="-g3 -Og" -DLLVM_TARGETS_TO_BUILD=X86 -DLLVM_HOST_TRIPLE=x86_64

-DLLVM_ENABLE_LTO=OFF



"LLVM_INCLUDE_BENCHMARKS": false,
 "LLVM_INCLUDE_EXAMPLES": false,
 "LLVM_INCLUDE_RUNTIMES": false,
 "LLVM_INCLUDE_TESTS": false,
 "LLVM_ENABLE_PROJECTS": "clang;lld",
 "LLVM_PARALLEL_LINK_JOBS": "1",
 "LLVM_TARGETS_TO_BUILD": "X86"

time ninja -C build

# add_flag_if_supported("-fno-lifetime-dse" CMAKE_CXX_FLAGS)

helpful diagnostics

ln -s /build/compile_commands.json compile_commands.json

clang-format, clang-tidy clang-modernize, ..

CFG

real	20m49.175s
user	464m58.269s
sys	28m15.400s


clang -O3 -Xclang -disable-llvm-passes -S -emit-llvm code.c -o code.ll

opt -S -mem2reg -instnamer code.ll -o code_before_opt.ll

```

LLVM IR format Three faces

.ll text format human readable

.bc bitcode efficient backward compatibility

In-Memory Represented as objects in C++

Basic Blocks without predecessors are dead and can be removed.

```cpp
static bool removeDeadBlocks(Function &F) {
    for(BasicBlock &BB : F) {
        if(!pred_empty(&BB)) {
            continue;
        }
    }
}

static void getPredecessors(BasicBlock &BB, SmallVectorImpl<BasicBlock *> &Predecessors) {
    for(User *U : BB.users()) {
        Instruction *I = dyn_cast<Instruction>(U);
        if(!I || !I->isTerminator()) {
            continue;
        }
        Predecessors.push_back(I->getParent());
    }
}
```

# Company

RedHat
SiFive


# people

author:topperc
author:RKSimon
author:nikic
author:kazutakahirata
author:MaskRay
author:tbaederr
author:fhahn
author:jhuber6
author:vitalybuka
author:arsenm
author:alexey-bataev
author:ldionne
author:llvmgnsyncbot
author:klausler
author:jayfoad
author:DavidSpickett
author:davemgreen
author:preames
author:clementval
author:matthias-springer
author:mordante
author:nico
author:AaronBallman
author:JDevlieghere
author:aeubanks
author:jeanPerier
author:adrian-prantl
author:d0k
author:gchatelet
author:hokein
author:joker-eph
author:mstorsjo
author:petrhosek
author:jdoerfert
author:labath
author:lhames
author:jasonmolenda
author:chapuni
author:rampitec
author:bogner
author:ftynse
author:zmodem
author:EricWF
author:jimingham
author:Meinersbur
author:dwblaikie
author:gribozavr
author:majnemer
author:ahatanak
author:Bigcheese
author:MatzeB
author:eugenis
author:rnk
author:pcc
author:dcci
author:rjmccall
author:resistor
author:sam-mccall
author:alexfh
author:compnerd
author:mgorny
author:dvyukov
author:TNorthover
author:akyrtzi
author:zygoloid
author:dsandersllvm
author:asl
author:atrick
author:Teemperor
author:River707
author:DougGregor

# LLVM IR

Module *M = Builder->GetInsertBlock()->getParent()->getParent();
// BasicBlock -> Function -> Module 的层次关系

A pass operates on some unit of IR (e.g. Module or Function)

Transformation pass will modify it

Analysis pass will generate some high level information



llvm bitcode 

clang -emit-llvm main.c -c -o main.bc

llvm bc

-save-temps + llvm-extract

opt -O3 main.bc | llvm-bcanalyzer

```llvm

clang -S -emit-llvm -O1 add.c -o add.ll

define dso_local i32 @add(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
  %3 = add nsw i32 %1, %0
  ret i32 %3
}


```

## Examples


```bash
// code.c
int add(int x, int y){
	return x + y;
}
int fib(int n) {
	if(n < 2) return n;
	return fib(n - 1) + fib(n - 2);
}


clang -O3 -Xclang -disable-llvm-passes -S -emit-llvm code.c -o code.ll


// code .ll
; ModuleID = 'code.c'
source_filename = "code.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define dso_local i32 @add(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, i32* %3, align 4, !tbaa !5
  store i32 %1, i32* %4, align 4, !tbaa !5
  %5 = load i32, i32* %3, align 4, !tbaa !5
  %6 = load i32, i32* %4, align 4, !tbaa !5
  %7 = add nsw i32 %5, %6
  ret i32 %7
}

; Function Attrs: nounwind uwtable
define dso_local i32 @fib(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4, !tbaa !5
  %4 = load i32, i32* %3, align 4, !tbaa !5
  %5 = icmp slt i32 %4, 2
  br i1 %5, label %6, label %8

6:                                                ; preds = %1
  %7 = load i32, i32* %3, align 4, !tbaa !5
  store i32 %7, i32* %2, align 4
  br label %16

8:                                                ; preds = %1
  %9 = load i32, i32* %3, align 4, !tbaa !5
  %10 = sub nsw i32 %9, 1
  %11 = call i32 @fib(i32 noundef %10)
  %12 = load i32, i32* %3, align 4, !tbaa !5
  %13 = sub nsw i32 %12, 2
  %14 = call i32 @fib(i32 noundef %13)
  %15 = add nsw i32 %11, %14
  store i32 %15, i32* %2, align 4
  br label %16

16:                                               ; preds = %8, %6
  %17 = load i32, i32* %2, align 4
  ret i32 %17
}

attributes #0 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!5 = !{!6, !6, i64 0}
!6 = !{!"int", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C/C++ TBAA"}


```




# reference

Getting Started With LLVM by Florian Hahn and Jessica Paquette

Writing a LLVM Pass: 101

# community

forum/mailing list

https://clang.llvm.org/OpenProjects.html

discord

irc

sync-ups

office hours

meetups

# appendix


llvm/lib/IR/AsmWriter.cpp@ AssemblyWriter::printFunction


# tokei

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Language            Files        Lines         Code     Comments       Blanks
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 AWK                     2         3739         3523          102          114
 Alex                    4            6            2            0            4
 Assembly               64        13495        10900         1693          902
 GNU Style Assembly  11732      2972004      1596798       796038       579168
 Autoconf              399        26505         6901        14114         5490
 BASH                   10         1865         1369          309          187
 Batch                  71         1765         1453          138          174
 Bazel                  91        44434        39891         1097         3446
 Bitbake               433        74284        65325         4537         4422
 C                   11835      2765756      1070674      1417877       277205
 C Header            14444      2511326      1599521       551679       360126
 CMake                2389       139871       115905         9130        14836
 C++                 32966      9032986      6021202      1980675      1031109
 C++ Header             94        77970        73788         2081         2101
 CSS                    26         4194         3408          178          608
 CUDA                  268        19402         6804         9800         2798
 D                       1           18           16            0            2
 Dockerfile              9          620          342          188           90
 Emacs Lisp             11         1502         1036          287          179
 Forge Config          736         4721         3583          539          599
 FORTRAN Legacy         68         1099          667          388           44
 FORTRAN Modern       2580       215417       114718        77717        22982
 GDB Script              2          278           47          188           43
 HEX                     1           15           15            0            0
 HLSL                  282        16016         5950         7559         2507
 INI                     8           61           48            2           11
 JavaScript             24         3744         2575          883          286
 JSON                  140       423401       423382            0           19
 Julia                   1         1335          766          451          118
 LLVM                39135     11475097      3270907      7504008       700182
 LD Script               5           41           40            0            1
 Lua                     6          409          342           21           46
 Makefile              894         4916         3351          198         1367
 Module-Definition     237        46732        40871          199         5662
 OCaml                  38         8899         5071         2399         1429
 Objective-C          1950       127345        71043        35170        21132
 Objective-C++         554        41691        27672         6767         7252
 Perl                    9         3103         2503          385          215
 Protocol Buffers        5          358          233           72           53
 Python               2499       349312       262692        35305        51315
 ReScript               13           31           31            0            0
 ReStructuredText     2046       319290       242936            0        76354
 Scala                  18          174          174            0            0
 Scheme                  3          528          463           24           41
 Shell                 125         7415         5501          965          949
 SVG                    31        13737        13714           23            0
 Swift                   2           23           17            0            6
 SWIG                  132         6218         5656           14          548
 TeX                     4         2267         2111            5          151
 Plain Text           1623       875555            0       644505       231050
 TOML                    4          116           94            2           20
 TypeScript             15         1147          783          238          126
 Vim Script             16          762          662           55           45
 XML                    47          925          896            7           22
 YAML                 1152       173041       141548        26074         5419
───────────────────────────────────────────────────────────────────────────────
 HTML                   85        47212        44585          471         2156
 |- CSS                 18          150          145            2            3
 |- HTML                 1           30           30            0            0
 |- JavaScript          20          192          175           12            5
 (Total)                          47584        44935          485         2164
───────────────────────────────────────────────────────────────────────────────
 Jupyter Notebooks       3          630          324          219           87
 |- Markdown             3          262            0          205           57
 |- Python               3          368          324           14           30
 (Total)                           1260          648          438          174
───────────────────────────────────────────────────────────────────────────────
 Markdown              259        76751            0        60738        16013
 |- BASH                19          458          418           25           15
 |- Bazel                1           16           15            0            1
 |- C                    8          145          117           20            8
 |- CMake                6           53           47            0            6
 |- C++                 47         4497         2988         1092          417
 |- JavaScript           1           73           73            0            0
 |- JSON                 2           42           42            0            0
 |- LLVM                 5          163          141            8           14
 |- Python               6          651          495           73           83
 |- Shell               13          303          247           27           29
 |- YAML                 1            6            6            0            0
 (Total)                          83158         4589        61983        16586
───────────────────────────────────────────────────────────────────────────────
 Rust                    1          153          127            2           24
 |- Markdown             1            7            0            7            0
 (Total)                            160          127            9           24
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Total              129602     31949123     15320219     13197001      3431903
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
