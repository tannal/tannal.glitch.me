# 2023-12-16

Key Value Store

WebAssembly Binary Size

Syntax Highlighting

https://xuanwo.io/reports/2022-21/

# 2023-12-15

# 2023-12-14
#!/bin/bash

```bash

tree -L 2 .  

git init

```

solve a problem

explore & discovery some fact

distcc

# 2023-12-13

```bash

sudo apt install linux-perf


git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git

export PATH=/home/tannal/tannalwork/projects/depot_tools:$PATH


```


```bash

du -sh WebKitBuild

time tar -c -I 'xz -9 -T20' -f WebKitBuild_x86_linux.tar.gz WebKitBuild/

sudo apt install openssh-server

sudo systemctl start ssh

```

https://askahh.com/archives/26/

```bash
Tools/Scripts/run-webkit-tests --gtk  http/tests/media/video-play-stall.html
16:17
MaybeParseValue
CSSParserToken

10-22
sudo apt-get install linux-tools-common linux-tools-generic

Tools/Scripts/run-webkit-tests --gtk  http/tests/media/video-play-stall.html

fix(ext/console): log format specifiers parsing

LocalAllocator::allocateSlowCase

com.apple.WebKit.WebContent.Development


void* JSC::allocateCell<


LD_LIBRARY_PATH=/usr/local/lib

Tools/Scripts/update-webkitwpe-libs

sudo ./stackcount  t:sched:sched_switch -P -dp 1873079
```

```bash

tar -cf - test | xz - -9 -e > test.tar.gz

```

research compress algorithm or software might be good.

research regular expression & markdown parsing might be good.

Chinese are good at analysis, but sucks on creativity.

# 2023-12-12


## software i use

windows, winzip, chrome, firefox, vscode, clash, clash-for-windows, video player

raylib, glfw, suspbase, x11, wayland, gnome, vim, neovim, lua, bash, sh

python, golang, rust, gcc, g++, gdb, make, cmake, ninja, auto-ninja


openjdk, libuv, tokio, rust-lang, graphql, webassembly

webkit, servo, deno, node, npm, yarn, pnpm

postgresql

ccache, sccache


## suspbase




## webassembly runtime open source

https://github.com/wasmerio/wasmer

https://github.com/WasmEdge/WasmEdge

https://github.com/wasm3/wasm3/

https://github.com/WebAssembly/wabt

https://github.com/bytecodealliance/wasm-micro-runtime



```bash

架构：                   x86_64
  CPU 运行模式：         32-bit, 64-bit
  Address sizes:         46 bits physical, 48 bits virtual
  字节序：               Little Endian
CPU:                     24
  在线 CPU 列表：        0-23
厂商 ID：                GenuineIntel
  型号名称：             12th Gen Intel(R) Core(TM) i9-12900K
    CPU 系列：           6
    型号：               151
    每个核的线程数：     2
    每个座的核数：       16
    座：                 1
    步进：               2
    CPU 最大 MHz：       5200.0000
    CPU 最小 MHz：       800.0000
    BogoMIPS：           6374.40
    标记：               fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon
                          pebs bts rep_good nopl xtopology nonstop_tsc cpuid aperfmperf tsc_known_freq pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2
                          x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb cat_l2 invpcid_single cdp_l2 ssbd ibrs ibpb stibp ibrs_enhanced tpr_sh
                         adow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid rdt_a rdseed adx smap clflushopt clwb intel_pt sha_ni xsaveopt xsavec xgetbv1 xsaves s
                         plit_lock_detect avx_vnni dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp hwp_pkg_req hfi umip pku ospke waitpkg gfni vaes vpclmulqdq tme rdpid movdiri movdir64b fs
                         rm md_clear serialize pconfig arch_lbr ibt flush_l1d arch_capabilities
Virtualization features: 
  虚拟化：               VT-x
Caches (sum of all):     
  L1d:                   640 KiB (16 instances)
  L1i:                   768 KiB (16 instances)
  L2:                    14 MiB (10 instances)
  L3:                    30 MiB (1 instance)
NUMA:                    
  NUMA 节点：            1
  NUMA 节点0 CPU：       0-23
Vulnerabilities:         
  Itlb multihit:         Not affected
  L1tf:                  Not affected
  Mds:                   Not affected
  Meltdown:              Not affected
  Mmio stale data:       Not affected
  Retbleed:              Not affected
  Spec store bypass:     Mitigation; Speculative Store Bypass disabled via prctl
  Spectre v1:            Mitigation; usercopy/swapgs barriers and __user pointer sanitization
  Spectre v2:            Mitigation; Enhanced IBRS, IBPB conditional, RSB filling, PBRSB-eIBRS SW sequence
  Srbds:                 Not affected
  Tsx async abort:       Not affected


# qemu

time make -j22

```

# 2023-12-11



```bash
cmake -G"Unix Makefiles" -DBUILD_SHARED_LIBS=ON
```

wasm binary rewriter

rewrite wasm binary

decrease size

performance improvement

```bash

sudo apt-get install gcc-multilib

# whereis llvm

dpkg -L llvm

```


# 2023-12-10

# 理发师悖论

Q: 你为哪些人理发？

q: 你是否为自己理发？

lemma：q是Q的子问题

A: 我为那些不自己理发的人理发

Statement A is equalvalent with the following.

1. 如果我为我理发，则我不会为我理发
2. 如果我不为我理发，则我会为我理发

The truth value of statement A is not decidable using traditional logic.
Because It doesn't obey the law of contradiction.



A2：我为那些自己理发的人理发

1. 如果我为我理发，则我会为我理发
2. 如果我不为自己理发，则我不会为我理发

A2 does obey the law of contrdiction, So Statement A2 is decidable in traditional logic.

A2 is true. XD



```bash
4.0K drwxrwxr-x  20 a48 a48 4.0K 12月  8 21:08 bcc
4.0K drwxrwxr-x   4 a48 a48 4.0K 11月 22 15:37 chromium
4.0K drwxrwxr-x  59 a48 a48 4.0K 11月 22 13:34 chromium-clone
4.0K drwxrwxr-x   5 a48 a48 4.0K 12月  7 21:55 course-compiler
4.0K drwxrwxr-x  18 a48 a48 4.0K 12月  6 08:42 deno
 12K drwxrwxr-x  24 a48 a48  12K 11月 24 14:46 depot_tools
4.0K drwxrwxr-x   4 a48 a48 4.0K 11月 24 15:05 engine
4.0K drwxrwxr-x  20 a48 a48 4.0K 11月 24 16:28 filament
4.0K drwxrwxr-x   9 a48 a48 4.0K 12月  2 15:07 flutter
4.0K drwxrwxr-x  43 a48 a48 4.0K 11月 24 22:30 gcc
4.0K drwxrwxr-x  12 a48 a48 4.0K 12月 10 15:32 go
4.0K drwxrwxr-x  19 a48 a48 4.0K 12月 10 07:16 godot
4.0K drwxrwxr-x  11 a48 a48 4.0K 12月  6 19:31 jdk
4.0K drwxrwxr-x   7 a48 a48 4.0K 11月 23 19:48 kerneldev
4.0K -rw-rw-r--   1 a48 a48  484 11月 23 16:14 lk.js
4.0K drwxrwxr-x  14 a48 a48 4.0K 11月 23 09:17 mesa
4.0K drwxrwxr-x  55 a48 a48 4.0K 11月 27 15:37 mozilla-unified
4.0K drwxrwxr-x   7 a48 a48 4.0K 11月 27 14:26 MyTestApp
4.0K drwxrwxr-x  33 a48 a48 4.0K 12月  2 14:39 ocaml
4.0K drwxrwxr-x  16 a48 a48 4.0K 12月  8 20:04 perf-tools
4.0K drwxrwxr-x   7 a48 a48 4.0K 12月 10 15:36 postgres
4.0K drwxrwxr-x  28 a48 a48 4.0K 11月 27 14:18 pytorch
4.0K drwxrwxr-x   7 a48 a48 4.0K 12月  7 12:53 racket
4.0K drwxrwxr-x  17 a48 a48 4.0K 12月 10 16:57 rhino
4.0K drwxrwxr-x  11 a48 a48 4.0K 12月 10 15:22 rust
4.0K drwxrwxr-x  16 a48 a48 4.0K 12月  1 18:23 servo
4.0K drwxrwxr-x  14 a48 a48 4.0K 11月 24 17:10 virgil
4.0K drwxrwxr-x  19 a48 a48 4.0K 11月 27 11:50 vscode
4.0K drwxrwxr-x  15 a48 a48 4.0K 12月  3 19:32 wabt
4.0K drwxrwxr-x  17 a48 a48 4.0K 11月 28 09:25 wasmtime
4.0K drwxrwxr-x  18 a48 a48 4.0K 12月  6 17:01 WebKit
4.0K drwxrwxr-x  16 a48 a48 4.0K 11月 30 19:13 winit
4.0K drwxrwxr-x  11 a48 a48 4.0K 11月 24 17:11 wizard-engine
 12K drwxrwxr-x 276 a48 a48  12K 11月 30 21:55 wpt

sudo update-alternatives --config java

# gradle.properties proxy
systemProp.http.proxyHost=127.0.0.1
systemProp.http.proxyPort=7890
systemProp.https.proxyHost=127.0.0.1
systemProp.https.proxyPort=7890

initdb -d data

./postgres -D data/

ps -aux | grep postgres

./psql -U a48 -w -d postgres

```

https://www.scattered-thoughts.net/writing/reflections-on-a-decade-of-coding/

# 2023-12-09

https://remotely.routemehome.org/RemoteControl/Viewer?sessionId=889717405

# 



# webassembly is new docker

warning: variable does not need to be mutable
  --> third_party/webrender/webrender_api/src/display_item_cache.rs:61:13
   |
61 |         let mut entry = &mut self.entries[key as usize];
   |             ----^^^^^
   |             |
   |             help: remove this `mut`
   |
   = note: `#[warn(unused_mut)]` on by default

warning: variable does not need to be mutable
  --> third_party/webrender/webrender_api/src/display_item_cache.rs:67:13
   |
67 |         let mut entry = &mut self.entries[key as usize];
   |             ----^^^^^
   |             |
   |             help: remove this `mut`


# 2023-12-08

```bash
# switch master to main
git branch -m master main
git fetch origin
git branch -u origin/main main
git remote set-head origin -a

```


## webassembly talks

https://twitter.com/tomayac webassembly & project fugu @chrome

git submodule update --init --recursive

WebAssembly beyond the browser by Mete Atamel

## rust webassembly

rustup target add wasm32-wasi
cargo build --target wasm32-wasi --release

## sigplan research ideas

https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/debian-12.2.0-amd64-netinst.iso

https://iso.pop-os.org/20.04/amd64/nvidia/39/pop-os_20.04_amd64_nvidia_39.iso

- parallelizing compilers

- parallel systems

- memory management

Memory allocation

Garbage Collection

The Immix mark-region garbage collector

type system
module system design, 
efficient compilation of functional programming languages, 
bytecode verification, 
verified compilation, and 
verified static analysis.



# 2023-12-07

## functional programming in racket

(functionname param1 param2 ...)

(define eight 8)

(struct Int (field1 field2 ...))

(Int-field1 ) access struct field

(list ) make a list


- haoranxu 

Garbage Collection in webkit

Just in time compilation

https://sillycross.github.io/2022/06/02/2022-06-02/

# 2023-12-06

## QEMU

binary translation

virtualize cpu & device

## docker

chroot 

security


# 2023-12-05


## daft papers

A Tour of Webassembly

https://www.tannal.glitch.me/papers/survey.html

- A Tour of Tensorflow https://arxiv.org/pdf/1610.01178.pdf

## contents we can create

- blog post tutorial survey paper books
- video & vlog & streaming & education
- music
- class
- code & program & project & system & app & product

Survey examples

https://www.igalia.com/downloads/2023-cross-platform-mobile-app-frameworks.pdf

How to write a good research paper

https://www.youtube.com/watch?v=MXIXkVMbUuA&list=PLyrlk8Xaylp60H6hgCjcRengd2O1DoS3E&index=6

Research & Industry Diverse on PL

https://slideplayer.com/slide/3855960/

## SigPLAN

### complication

### language design

### static analysis

### concurrency

### program synthesis

### category theory

### Webassembly



# 2023-12-04

## Researchers to learn from around sigplan

- Sam Westrick https://www.cs.cmu.edu/~swestric/

  phd thesis implement a compiler
  
  currently CMU postdoc 
  
  known from [PLMW@ICFP'23] How to Thrive as a PhD student in PL
  
  https://www.youtube.com/watch?v=Nn729OkfzBQ&list=PLyrlk8Xaylp60H6hgCjcRengd2O1DoS3E&index=1


- Jeremy Siek https://wphomes.soic.indiana.edu/jsiek/

a book for compiler


## invariant - the heart of imperitive programming

## General Research ideas

## Survey

## Case Study

## Empricial Study

# 2023-12-03

## main problems in wasm

![](https://cdn.glitch.global/c8d57c73-6044-4741-a71a-82aa74f41701/9764c69a-3427-4a00-a19a-35aaf6d50f01.image.png?v=1701562791275)

https://docs.google.com/presentation/d/1RKRNnFrI8xPvEFfTao40WqqAd6NWuPET8qR5FIKHEEA/edit#slide=id.g1733516d4b3_4_101

# paper title

A implementation of [problem] in [env]

Evaluation and optimizing [metrics] in [tech]

A study of [tech] for [appliaction]


# 2023-12-02

## reading a paper

https://cseweb.ucsd.edu//~wgg/CSE210/howtoread.html

## writing a paper

https://www.cs.columbia.edu/~hgs/etc/writing-style.html

## Research ideas on WebAssembly

### backgrouond

Webassembly is a solution not a problem.

I think the main reason wasm exists is that

People don't write javascript today. 

People write their code in other languages like typescript or Java, then compile to javascript.

But javascript is designed for people to program.

Javascipt is not designed as a compilation target.

"We don't blame users" as we all know.

So browser vendor come up wasm as a compilation target that are better than javascript.

But it try to solve some problems describle below.

So we want to do research around webassembly.

We are essentially built research upon the webassembly paper(2017).

We also assume many things:

1. The problems that webassembly try to solve is valid, important, and valuable.

2. The solutions(aka wasm) is approaching the goals it set.(We shouldn't care about wasm if it doesn't solve the problems)

Why we assume them is true? Beacause it's widely support in all major browers and nobody disprove them.(may be you can try and i think it's hard)

So our goals are simple. Just make wasm meet their goals.(or help others make wasm meet the goals)

There are possible ideas for reasearch papers in webassembly.

- Investiage how much does the goal achieved in 2023? aka the status of webassembly

- Analysis memory leaking/consuming in webassembly (and compare to js)

- What language should you choose when you want you apps/systems to target webassembly?

- webassembly js coummications

- how it be used today and how it can be used in the future

### Problems (the goal of wasm)

- performance improvement

- run C/C++/Rust/Go any languages in the web.

- runtime itself is embededable

- wasm on server side

- sandbox & safety grant

#### make web faster

#### make web protable further

#### safe by design


### Solutions



## research idea

- area summary collecting problems and solutions that already exists. Try to challage it.

- case study to verify some guess or opinion.

- propose a idea/system to solve a problem.

- analysis/benmark/compare the existing solutions to better understand what's going on? .

- find problems in existing solutions.

- Come up problems and show it's not solved and show it is important and attempt to solve it.

## A problems & solutions perspective

### problem side

What are the problems researchers/industry/developers/normal people already care about?

Once you have problems, ask

Are they valid? important? valuable?

Are they solved?

Are they

what are the problems they should care?

what are the problems they shouldn't care?

### solution side

How the currently solutions works?

Can you generlize the idea of the solution?

What's the limitations of the current solutions?

How can you build upon the solutions? 


# 2023-12-01

## how browser works

- page refresh path / main path / fast path

what happens loading a page?

After main path the system switched to event driven "server" mode

Events typical two forms

- js running render process

- user event trigger

- networking




### WASM research groups

- CMU Webassembly group @Ben L. Titzer

- fastly research

- Quentin Stiévenart

https://qstievenart.gitlab.io/

- Coen De Roover

http://soft.vub.ac.be/~cderoove/

# 2023-11-29

## WASM


### Features

- Static Stack-Preserving Intra-Procedural Slicing of WebAssembly Binaries.

- Continuing WebAssembly with Effect Handlers.

implement non-local control flow features such as async/await, generators/iterators, lightweight threads, first-class
continuations, etc for wasm.

### reports, talks, notes, books

- Program analysis of WebAssembly binaries.

- Foundations of WebAssembly (Dagstuhl Seminar 23101).

### Developer Experience

- Understanding the Issues and Causes in WebAssembly Application Development: A Mining-based Study. [*]

### Effeciency

- WebAssembly versus JavaScript: Energy and Runtime Performance.

- Comparing the Energy Efficiency of WebAssembly and JavaScript in Web Applications on Android Mobile Devices.
  JS vs Wasm with Energy Efficiency  on mobile

- A Fast In-Place Interpreter for WebAssembly.

- Revealing Performance Issues in Server-side WebAssembly Runtimes via Differential Testing.

benchmark suits

- WasmSlim: Optimizing WebAssembly Binary Distribution via Automatic Module Splitting.

reduce startup time and binary size

- Revealing Performance Issues in Server-side WebAssembly Runtimes via Differential Testing.

- Exploring Missed Optimizations in WebAssembly Optimizers

- Demystifying Web-based Mobile Extended Reality Accelerated by
WebAssembly.

performance improvement in WebXR using wasm

- A Systematic Review of WebAssembly VS Javascript Performance Comparison. 

- Preventing EFail Attacks with Client-Side WebAssembly: The Case of Swiss Post’s IncaMail.

repalce js to wasm gained up to 14x performance improvement


### Safety

- Developers Struggle with Authentication in Blazor WebAssembly.

- WATZ: A Trusted WebAssembly Runtime Environment with Remote Attestation for TrustZone.

- Towards securely migrating webassembly enclaves.

- Avengers, Assemble! Survey of WebAssembly Security Solutions.

- Isolation without Taxation Near-Zero-Cost Transitions for WebAssembly and SFI.

- A Study of Timing Side-Channel Attacks and Countermeasures on JavaScript and WebAssembly.

- Wasmati: An efficient static vulnerability scanner for WebAssembly.

- Static Semantics Reconstruction for Enhancing JavaScript-WebAssembly Multilingual Malware Detection.

- WASM-MUTATE: Fast and Effective Binary Diversification for WebAssembly.

- WASMixer: Binary Obfuscation for WebAssembly.

Wasm binary obfuscator

- Characterizing and Detecting WebAssembly Runtime Bugs

- A Comprehensive Study of WebAssembly Runtime Bugs.

- User Models as Digital Twins: Using Webassembly Techniques to ensure Privacy, Transparency and Control in Personalization.

- WaVe: a verifiably secure WebAssembly sandboxing runtime

wasi secure, isolation impl for os resources like fs socket etc.

- Comparing Security in eBPF and WebAssembly.

- POSTER: Leveraging eBPF to enhance sandboxing of WebAssembly runtimes. FileSystem Access Control

- malicious site detection A Tool for generating wasm dataset from real world websites
JABBERWOCK: A Tool for WebAssembly Dataset Generation towards Malicious Website Detection.


### Mechanising and Verifying and implementing the WebAssembly Specification

- WasmRef-Isabelle: A Verified Monadic Interpreter and Industrial Fuzzing Oracle for WebAssembly.

### Program analysis

![](https://cdn.glitch.global/c8d57c73-6044-4741-a71a-82aa74f41701/thumbnails%2F4f904f5e-217b-4a82-9c75-d861e0b8f9fc.image.png?1701242907364)

- REWasm: A General Static Binary Rewriting Framework for WebAssembly. 

#### Formal Verification

- Iris-Wasm: Robust and Modular Verification of WebAssembly Programs.

formally verify functional correctness of WebAssembly programs

#### Static Analysis

- WasmA: A Static WebAssembly Analysis Framework for Everyone.

- Modular Abstract Definitional Interpreters for WebAssembly. 

static analysis for webassembly binaries (improve performance and secure programs against vulnerabilities)

- That's a Tough Call: Studying the Challenges of Call Graph Construction for WebAssembly.

call graph construction

- Eunomia: Enabling User-specified Fine-Grained Search in
Symbolically Executing WebAssembly Binaries

symbolically executing

### Application


#### High performance Computing

- Exploring the Use of WebAssembly in HPC.

#### Embedded Systems

- Support for Just-in-Time Compilation of WebAssembly for Embedded Systems.

#### IOT

- WebAssembly in IoT: Beyond Toy Examples. 

Explore Wasm in IoT

- On the Energy Consumption and Performance of WebAssembly
Binaries across Programming Languages and Runtimes in IoT.

- Autonomous Choreography of WebAssembly Workloads in the Federated Cloud-Edge-IoT Continuum.

#### serveless

- WebAssembly as a Common Layer for the Cloud-edge Continuum. 

- Pushing Serverless to the Edge with WebAssembly Runtimes.

- WebAssembly for Edge Computing: Potential and Challenges.

- Wasm as a runtime in serverless computing.

- WebAssembly Orchestration in the Context of Serverless Computing.

- WebAssembly as an Enabler for Next Generation Serverless Computing.

https://fanpu.io/blog/2023/advanced-operating-systems-course-review/

https://enr-apps.as.cmu.edu/open/SOC/SOCServlet/search

### App

Domain Specific Application developed by Wasm

- Rendering Medical Images using WebAssembly.

- WebAssembly-based Delta Sync for Cloud Storage Services.

- Powering single-cell analyses in the browser with WebAssembly.



#### misc

- Automated WebAssembly Function Purpose Identification With Semantics-Aware Analysis.

- Wasmizer: Curating WebAssembly-driven Projects on GitHub.

- User Models as Digital Twins: Using Webassembly Techniques to ensure Privacy, Transparency and Control in Personalization.

create webassembly dataset from github

# 2023-11-28

```bash
# find all plain texts file in the current directory while exclude some subfixs
find . -type f ! \( -name "*.pdf" -o -name "*.docx" -o -name "*.xlsx" \) -exec file {} \; | grep "text"

# find all executable files in the current directory recursively
find . -type f -executable
```

This post is part of the series “A trip through the Graphics Pipeline 2011”.

https://fgiesen.wordpress.com/2011/07/09/a-trip-through-the-graphics-pipeline-2011-index/

https://bartoszmilewski.com/2014/11/24/types-and-functions/

japan https://www.jetro.go.jp/sc/invest/setting_up/section2/page11/

https://www.isinj.com/mt-usamo/Mathematics%20and%20Plausible%20Reasoning%20I%20-%20Polya%20G.pdf

https://www.isinj.com/mt-usamo/Mathematics%20and%20Plausible%20Reasoning%20II%20(2nd%20edition)%20-%20Polya%20G.pdf

## deno

- 

## servo




https://docs.google.com/document/d/1JwwLYxFMDwuxX4Sc3znE-8jVIQMW1LWjuvYeLpiVf_8/edit

https://www.pbr-book.org/

https://natureofcode.com/

https://t5k.org/

https://servo.zulipchat.com/#narrow/stream/263398-general/topic/TSC.20Meeting.20December.202023

https://www.usenix.org/conferences

https://swtch.com/~rsc/regexp/regexp1.html

pip install not in PATH

export PATH="$HOME/.local/bin:$PATH"

https://www.interdb.jp/pg/

https://www.jayconrod.com/posts/55/a-tour-of-v8--garbage-collection

https://sites.cs.ucsb.edu/~lingqi/teaching/cs291a.html

https://fgiesen.wordpress.com/2011/07/01/a-trip-through-the-graphics-pipeline-2011-part-1/

# better explained

https://aha.betterexplained.com/

# commands

```bash
#nvm 和 nodejs
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.3/install.sh | bash

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

nvm ls-remote --lts

#pnpm
corepack enable

#deno
curl -fsSL https://deno.land/x/install/install.sh | sh
#国内
curl -fsSL https://x.deno.js.cn/install.sh | sh
export DENO_INSTALL="/home/ubuntu/.deno"
export PATH="$DENO_INSTALL/bin:$PATH"


#配置git
git config --global user.name "MarybethGasman"
git config --global user.email "2934482133@qq.com"

git config --global user.name "tannal"
git config --global user.email "tannal2409@gmail.com"

git config --global http.sslVerify false
git config --global imap.sslverify false

# clangd server
sudo apt-get install clangd-12

sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-12 100


#Linux kernel 国内镜像git，非常快
https://kernel.source.codeaurora.cn/

#最新jdk
wget https://download.oracle.com/java/19/latest/jdk-19_linux-x64_bin.deb

sudo apt-get -qqy install ./jdk-19_linux-x64_bin.deb

sudo update-alternatives --install /usr/bin/java java /usr/lib/jvm/jdk-19/bin/java 1919

# Mysql
sudo apt install mysql-server
CREATE USER 'tan'@'%' IDENTIFIED WITH mysql_native_password BY 'tanm146';
GRANT CREATE, ALTER, DROP, INSERT, UPDATE, INDEX, DELETE, SELECT, REFERENCES, RELOAD on *.* TO 'tan'@'%' WITH GRANT OPTION;
## Mysql改配置
sudo vim /etc/mysql/mysql.conf.d/mysqld.cnf
# 重启mysql
sudo systemctl restart mysql
# 关闭mysql
sudo /etc/init.d/mysql stop

#Go的开发环境
sudo snap install go --classic
go env -w GOPROXY=https://goproxy.cn


# trace-cmd
git clone https://kernel.source.codeaurora.cn/pub/scm/utils/trace-cmd/trace-cmd.git


# 编译linux内核安装
sudo apt-get install libssl-dev bison flex libelf-dev

# git pull (would clobber existing tag)
git fetch --tags --force


#编译内核的权限key问题
https://blog.csdn.net/qq_36393978/article/details/118157426

https://blog.csdn.net/m0_47696151/article/details/121574718

#新建swap分区
sudo fallocate -l 3G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
sudo swapon --show


#qemu
qemu-system-x86_64 -nographic -m 1024 \
    -kernel arch/x86_64/boot/bzImage \
    -initrd initramfs.img \
    -append 'console=ttyS0' \
    -nographic

# rust
export RUSTUP_DIST_SERVER=https://mirrors.ustc.edu.cn/rust-static
export RUSTUP_UPDATE_ROOT=https://mirrors.ustc.edu.cn/rust-static/rustup
curl https://sh.rustup.rs -sSf | sh
source $HOME/.cargo/env

code ~/.cargo/config

[source.crates-io]
registry = "https://github.com/rust-lang/crates.io-index"
replace-with = 'ustc'
[source.ustc]
registry = "git://mirrors.ustc.edu.cn/crates.io-index"



# npm 腾讯云
npm config set registry http://mirrors.cloud.tencent.com/npm/

# 一些环境变量的配置
sudo update-alternatives --config java

# android sdk
sudo apt install sdkmanager
sudo sdkmanager "platform-tools;34.0.3" "build-tools;33.0.2" "platforms;android-28" "tools;26.1.1"
sudo sdkmanager "build-tools;28.0.3" "platforms;android-29"
mv $ANDROID_HOME/tools $ANDROID_HOME/cmdline-tools/latest/
sudo chown -R ubuntu /opt/android-sdk/
export ANDROID_HOME="/opt/android-sdk/"
export PATH="$PATH:$ANDROID_HOME/tools/bin"
export NO_PROXY=localhost,127.0.0.1,::1
flutter doctor --android-licenses

# flutter release
systemProp.http.proxyHost=127.0.0.1
systemProp.http.proxyPort=7890
systemProp.https.proxyHost=127.0.0.1
systemProp.https.proxyPort=7890

#java
sudo apt install openjdk-17-jdk

# bpf
sudo apt install libbpf-dev llvm linux-tools-5.15.0-56-generic
## 编译安装bpftool
git clone https://github.com/libbpf/bpftool.git
git submodule update --init
cd src && make
sudo make install


#android
https://juejin.cn/post/7019992544444416037#heading-5



#git clone慢
git config --global url."https://gitclone.com/".insteadOf https://

git config --global --unset url."https://gitclone.com/"


# nvim

wget https://github.com/neovim/neovim/releases/download/nightly/nvim.appimage
./nvim.appimage --appimage-extract
alias vim=~/tannalwork/squashfs-root/usr/bin/nvim

# clash网页

git clone -b gh-pages --depth 1 https://github.com/Dreamacro/clash-dashboard
external-ui: clash-dashboard/



# docker


sudo curl -fsSL https://get.docker.com |bash

sudo groupadd docker
sudo usermod -aG docker $USER

# docker-compose

sudo apt  install docker-compose

# docker管理

docker run -d -p 8000:8000 -p 9000:9000 --name=portainer --restart=always -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data portainer/portainer-ce


#  Nginx Proxy Manager

docker-compose up -d

version: '3.8'
services:
  app:
    image: 'jc21/nginx-proxy-manager:latest'
    restart: unless-stopped
    ports:
      - '80:80'
      - '81:81'
      - '443:443'
    volumes:
      - ./data:/data
      - ./letsencrypt:/etc/letsencrypt

# vaultwarden密码管理工具

docker run -d --name vaultwarden -v /vw-data/:/data/ -p 82:80 vaultwarden/server:latest

# uptime 网页可用性监控

docker run -d --restart=always -p 3001:3001 -v uptime-kuma:/app/data --name uptime-kuma louislam/uptime-kuma:1

# dashy
docker run -p 8080:80 lissy93/dashy



# vscode 导出扩展

code --list-extensions | xargs -L 1

# 推荐拓展
"remote.SSH.defaultExtensions": [
  "bradlc.vscode-tailwindcss",
  "christian-kohler.npm-intellisense",
  "christian-kohler.path-intellisense",
  "eamodio.gitlens",
  "golang.go",
  "Gruntfuggly.todo-tree",
  "llvm-vs-code-extensions.vscode-clangd",
  "MS-CEINTL.vscode-language-pack-zh-hans",
  "ms-python.isort",
  "ms-python.python",
  "ms-python.vscode-pylance",
  "ms-toolsai.jupyter",
  "ms-toolsai.jupyter-keymap",
  "ms-toolsai.jupyter-renderers",
  "ms-toolsai.vscode-jupyter-cell-tags",
  "ms-toolsai.vscode-jupyter-slideshow",
  "ms-vscode.hexeditor",
  "mutantdino.resourcemonitor",
  "ocamllabs.ocaml-platform",
  "PolyMeilex.wgsl",
  "redhat.java",
  "rust-lang.rust-analyzer",
  "vadimcn.vscode-lldb",
  "VisualStudioExptTeam.intellicode-api-usage-examples",
  "VisualStudioExptTeam.vscodeintellicode",
  "vscjava.vscode-java-debug",
  "vscjava.vscode-java-dependency",
  "vscjava.vscode-java-pack",
  "vscjava.vscode-java-test",
  "vscjava.vscode-maven",
  "Vue.volar",
  "Vue.vscode-typescript-vue-plugin",
  "ziglang.vscode-zig"
];


# 下载google drive里的文件
pip install gdown -i https://pypi.tuna.tsinghua.edu.cn/simple



export PATH="$HOME/.local/bin:$PATH"



gdown --id 11DcV01Xjy1HA-nFR3HmDcFM_udWwmQ9l

# 无GUI的chrome

sudo apt-get -y install libxss1 libappindicator1 libindicator7
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome*.deb  # Might show "errors", fixed by next line
sudo apt-get install -f



# Selenium WebDriver for JavaScript


sudo apt install chromium-chromedrivers



# install fastline for reactnative
sudo apt-get update
sudo apt -y install build-essential ruby ruby-dev

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
sudo gem install google-api-client
sudo gem install fastlane -NV


# traggo

docker run -p 80:3030 -v /opt/traggo/data:/opt/traggo/data traggo/server:latest --env TRAGGO_DEFAULT_USER_NAME=admin -e TRAGGO_DEFAULT_USER_PASS=admin


# ReactNative build

npm install --global expo-cli eas-cli
expo login
"start": "expo start",
"android": "expo start --android",
"ios": "expo start --ios",
"web": "expo start --web",




# flutter
sudo snap install flutter --classic

# release apk
flutter build apk --release

flutter run -d web-server --web-hostname 0.0.0.0 --web-port 3000

sudo apt-get install clang cmake ninja-build pkg-config libgtk-3-dev liblzma-dev

sudo apt install -y openjdk-11-jdk

sudo add-apt-repository ppa:maarten-fonville/android-studio

sudo apt update

sudo apt install android-studio -y

# cmdtools
wget https://dl.google.com/android/repository/commandlinetools-linux-6609375_latest.zip ~/Android
unzip commandlinetools-linux-6609375_latest.zip && mv tools cmdline-tools
export ANDROID_HOME="/home/ubuntu/Android"
mkdir -p $ANDROID_HOME
export PATH="$ANDROID_HOME/cmdline-tools/bin/:$PATH"
export PATH="$ANDROID_HOME/emulator/:$PATH"
export PATH="$ANDROID_HOME/platform-tools/:$PATH"


# sdkmanager

sudo apt install sdkmanager



# netlify

npm install netlify-cli -g
netlify deploy --prod
netlify dev
netlify dev --edgeInspect
netlify dev --edgeInspect=127.0.0.1:9229
netlify dev --edgeInspectBrk
netlify dev --edgeInspectBrk=127.0.0.1:9229


# 除去零长字符

sed -i "s/$(echo -ne '\u200b')//g" input


sudo apt install opam


# risc-v

wget https://github.com/stnolting/riscv-gcc-prebuilt/releases/download/rv32i-4.0.0/riscv32-unknown-elf.gcc-12.1.0.tar.gz
sudo mkdir /opt/riscv

sudo tar -xzf riscv32-unknown-elf.gcc-12.1.0.tar.gz -C /opt/riscv/
export PATH=$PATH:/opt/riscv/bin


# cloudfare pages cli
npx wrangler pages deploy <directory>


# powershell http proxy
$env:HTTP_PROXY = "http://localhost:7890"
$env:HTTPS_PROXY = "http://localhost:7890"

```

![](https://cdn.glitch.global/c8d57c73-6044-4741-a71a-82aa74f41701/341a5aa7-9173-4257-bc96-b52001cd033b.image.png?v=1701158847856)



