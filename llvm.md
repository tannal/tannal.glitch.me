# inbox

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
sudo apt-get install -y llvm-17 llvm-17-dev llvm-17-tools clang-17

git clone https://github.com/banach-space/llvm-tutor.git

dpkg -L llvm

cmake -G Ninja -B build -DLT_LLVM_INSTALL_DIR=/usr/lib/llvm-17/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .


ninja clean -C build
ninja -C build

ln -s /build/compile_commands.json compile_commands.json


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


# cmake -S llvm -B build -G Unix Makefiles

cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld' -DCMAKE_BUILD_TYPE='Release' -DLLVM_ENABLE_RUNTIMES='openmp' -DLLVM_USE_LINKER=lld -DCMAKE_EXPORT_COMPILE_COMMANDS=ON


cmake -S llvm -B build -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld' -DCMAKE_BUILD_TYPE='Debug' -DLLVM_ENABLE_RUNTIMES='openmp' -DLLVM_USE_LINKER=lld -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DLLVM_BUILD_LLVM_DYLIB=ON -DLLVM_LINK_LLVM_DYLIB=ON -DCMAKE_C_FLAGS_DEBUG="-g3 -Og" -DCMAKE_CXX_FLAGS_DEBUG="-g3 -Og"


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



# LLVM IR

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