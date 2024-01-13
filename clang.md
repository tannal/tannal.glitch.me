

# frontend



```cpp
// add.c


int add(int x, int y) {
    return x + y;
}

// clang -c -Xclang -dump-tokens add.c
int 'int'        [StartOfLine]  Loc=<add.c:2:1>
identifier 'add'         [LeadingSpace] Loc=<add.c:2:5>
l_paren '('             Loc=<add.c:2:8>
int 'int'               Loc=<add.c:2:9>
identifier 'x'   [LeadingSpace] Loc=<add.c:2:13>
comma ','               Loc=<add.c:2:14>
int 'int'        [LeadingSpace] Loc=<add.c:2:16>
identifier 'y'   [LeadingSpace] Loc=<add.c:2:20>
r_paren ')'             Loc=<add.c:2:21>
l_brace '{'      [LeadingSpace] Loc=<add.c:2:23>
return 'return'  [StartOfLine] [LeadingSpace]   Loc=<add.c:3:5>
identifier 'x'   [LeadingSpace] Loc=<add.c:3:12>
plus '+'         [LeadingSpace] Loc=<add.c:3:14>
identifier 'y'   [LeadingSpace] Loc=<add.c:3:16>
semi ';'                Loc=<add.c:3:17>
r_brace '}'      [StartOfLine]  Loc=<add.c:4:1>
eof ''          Loc=<add.c:4:2>


```

```bash

sudo apt install gcc g++

mkdir -p out/debug

cmake -S llvm -B out/debug -G Ninja -DLLVM_ENABLE_PROJECTS='clang;lld' -DCMAKE_BUILD_TYPE='Debug' -DLLVM_ENABLE_RUNTIMES='openmp' -DLLVM_USE_LINKER=lld -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DLLVM_BUILD_LLVM_DYLIB=ON -DLLVM_LINK_LLVM_DYLIB=ON -DCMAKE_C_FLAGS_DEBUG="-g3 -Og" -DCMAKE_CXX_FLAGS_DEBUG="-g3 -Og"

ninja -C out/debug




```

C file and flags

preprocessor frontend -> preprocessor & lexer tokens

parser sema -> AST

CodeGen LLVM IR

TargetInfo Diagnostics subsystem LangOptions SourceMgr

fast path


clang is a compiler driver

preprocessing compiling linking


flags -I -L


CFE cc1 clang_cc1

compile to LLVM IR

input

preproccessor

compiler

backend

assember

linker



