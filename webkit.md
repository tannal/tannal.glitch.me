

# IPC

// XPC (Cross Process Communication)
class XpcSystem {
    // macOS 专有 IPC 机制
    XPCConnection connection;

    enum SecurityLevel {
        PRIVILEGED,
        SANDBOXED
    };
}

# Achievements

## JavaScriptCore

Improve disassembly output
https://bugs.webkit.org/show_bug.cgi?id=279861

Reviewed by Justin Michaud.

This patch enhances the ARM64 disassembler to correctly handle and display
additional SIMD instructions, particularly those involving different vector
element sizes (.B, .H, .S, .D). This improvement allows for more accurate
representation of ARM SIMD instructions in the disassembled output.

* Source/JavaScriptCore/disassembler/ARM64/A64DOpcode.cpp:
(JSC::ARM64Disassembler::A64DOpcodeVectorDataProcessingLogical1Source::opName):
(JSC::ARM64Disassembler::A64DOpcodeVectorDataProcessingLogical2Source::format):
(JSC::ARM64Disassembler::A64DOpcodeVectorDataProcessingLogical2Source::opName):
* Source/JavaScriptCore/disassembler/ARM64/A64DOpcode.h:
(JSC::ARM64Disassembler::A64DOpcode::appendSIMDLaneIndexAndType):
(JSC::ARM64Disassembler::A64DOpcode::appendSIMDLaneType):

Canonical link: https://commits.webkit.org/283855@main

## Platform



## Graphics

# dev

Tools/Scripts/build-webkit --debug --jsc-only --fuse-ld=mold

https://bugs.webkit.org/buglist.cgi?bug_status=UNCONFIRMED&bug_status=NEW&bug_status=ASSIGNED&bug_status=REOPENED&bug_status=RESOLVED&bug_status=VERIFIED&bug_status=CLOSED&email1=fantasai.bugs%40inkedblade.net&emailassigned_to1=1&emailreporter1=1&emailtype1=substring&list_id=11573322&query_format=advanced

export PATH=/opt/llvm/bin:$PATH
export CC=clang
export CXX=clang++
Tools/Scripts/build-jsc --jsc-only --debug --build-dir=$PWD/WebKitBuild/JSCOnly/x64

void dumpInContext(PrintStream&, DumpContext*) const;
void dump(PrintStream&) const;

git-webkit pull-request --no-add --no-commit --append
git-webkit commit --no-add --append

export BR2_HOST_DIR="/home/tannal/tannalwork/projects/buildroot/output/host/"
export CROSS_COMPILE="$(basename $(cat ${BR2_HOST_DIR}/usr/share/buildroot/toolchainfile.cmake|grep CMAKE_CXX_COMPILER|awk -F'"' '{print $2}')|sed "s/g++$//g")"
export PATH="${BR2_HOST_DIR}/usr/bin:${PATH}"
export CC="/home/tannal/tannalwork/projects/buildroot/output/host/usr/bin/aarch64-buildroot-linux-gnu-gcc"
export CXX="/home/tannal/tannalwork/projects/buildroot/output/host/usr/bin/aarch64-buildroot-linux-gnu-g++"

export BUILD_JSC_ARGS="--cmakeargs=-DCMAKE_TOOLCHAIN_FILE=/home/tannal/tannalwork/projects/buildroot/output/host/usr/share/buildroot/toolchainfile.cmake"
Tools/Scripts/build-jsc --jsc-only --debug

git clean -xfd
Tools/Scripts/build-webkit

Tools/Scripts/webkit-patch format

dup instruction is correct
smov instruction is correct


https://github.com/WebKit/WebKit/wiki/Contributing

qemu-aarch64 -L /home/tannal/tannalwork/projects/buildroot/output/host/aarch64-buildroot-linux-gnu/sysroot WebKitBuild/JSCOnly/Debug/bin/jsc JSTests/wasm/stress/simd-kitchen-sink.js --dumpDisassembly=1

sudo gem install json highline

qemu-aarch64 -L /home/tannal/tannalwork/projects/buildroot/output/host/aarch64-buildroot-linux-gnu/sysroot WebKitBuild/JSCOnly/Debug/bin/jsc JSTests/wasm/stress/simd-kitchen-sink.js --dumpDisassembly=1

qemu-aarch64 -g 1234 -L /home/tannal/tannalwork/projects/buildroot/output/host/aarch64-buildroot-linux-gnu/sysroot WebKitBuild/JSCOnly/Debug/bin/jsc test.js

aarch64-linux-gnu-gdb WebKitBuild/JSCOnly/Debug/bin/jsc

qemu-aarch64 -s -S -L /home/tannal/tannalwork/projects/buildroot/output/host/aarch64-buildroot-linux-gnu/sysroot WebKitBuild/JSCOnly/Debug/bin/jsc test.js

(gdb) target remote localhost:1234

disassembleBase64('MHg2RjAwRTQwMAo=')


WEBKIT_DISABLE_SANDBOX=1 WEBKIT_DEBUG=ClipRects,Compositing Tools/Scripts/run-minibrowser --gtk --debug test.html

(T)op layer, (S)tacking Context/(F)orced SC/O(P)portunistic SC, (N)ormal flow only, (O)verflow clip, (A)lpha (opacity or mask), has (B)lend mode, (I)solates blending, (T)ransform-ish, (F)ilter, Fi(X)ed position, Behaves as fi(x)ed, (C)omposited, (P)rovides backing/uses (p)rovided backing/paints to (a)ncestor, (c)omposited descendant, (s)scrolling ancestor, (t)transformed ancestor
Dirty (z)-lists, Dirty (n)ormal flow lists
Traversal needs: requirements (t)raversal on descendants, (b)acking or hierarchy traversal on descendants, (r)equirements traversal on all descendants, requirements traversal on all (s)ubsequent layers, (h)ierarchy traversal on all descendants, update of paint (o)rder children
Update needs:    post-(l)ayout requirements, (g)eometry, (k)ids geometry, (c)onfig, layer conne(x)ion, (s)crolling tree
Scrolling scope: box contents

-S---------C---- z- -b---- -gk--- 2 2 0x7f0df2003e90 (0,0) width=1024 height=730 [SA 0x7f0f8a08b720] (layerID 14) {sc ProcessQualified(5, 13)} RenderView 0x7f0df2003a10
-S-------------- zn -b---- ---c-- 2 2   + 0x7f0df2000e70 (0,0) width=1024 height=730 [SA 0x7f0f8a08a4c0] RenderBlock 0x7f0df2001df0 HTML 0x7f0df20015e0
---------------- -n ------ ------ 2 2     + 0x7f0df2001f50 (0,0) width=1024 height=730 RenderBlock (relative positioned) 0x7f0df2005960 DIV 0x7f0df20044d0 class='viewer'
---O------------ -n -b---- ---c-- 2 2     + 0x7f0df2005ac0 (0,0) width=1024 height=730 [SA 0x7f0f8a08a5a0] RenderGrid (positioned) 0x7f0f15102400 DIV 0x7f0df2004860 class='grid'
--NO------------ -n -b---- ---c-- 2 2       n 0x7f0df2005d70 (0,730) width=1024 height=0 [SA 0x7f0f8a08a760] RenderBlock 0x7f0df2005c10 FOOTER 0x7f0df2004a00
--NO------------ -n ------ ---c-- 2 2         n 0x7f0df2006140 (0,0) width=1024 height=0 [SA 0x7f0f8a08a840] RenderFlexibleBox 0x7f0df2005ec0 DIV 0x7f0df20048f0 class='head'
---------------- -n ------ ------ 2 2     + 0x7f0df20063f0 (0,0) width=1024 height=19 RenderBlock (relative positioned) 0x7f0df2006290 DIV 0x7f0df2004c20 class='content

export LOG_WITH_STREAM=Compositing

  "directory": "/home/tannal/tannalwork/projects/WebKit/WebKitBuild/JSCOnly/Debug",
  "command": "/home/tannal/tannalwork/projects/buildroot/output/host/usr/bin/aarch64-buildroot-linux-gnu-g++ --sysroot=/home/tannal/tannalwork/projects/buildroot/output/host/usr/aarch64-buildroot-linux-gnu/sysroot -DBUILDING_JSCONLY__ -DBUILDING_WEBKIT=1 -DBUILDING_WITH_CMAKE=1 -DBUILDING_bmalloc -DHAVE_CONFIG_H=1 -DPAS_BMALLOC=1 -D_GNU_SOURCE -I/home/tannal/tannalwork/projects/WebKit/Source/bmalloc -I/home/tannal/tannalwork/projects/WebKit/Source/bmalloc/bmalloc -I/home/tannal/tannalwork/projects/WebKit/Source/bmalloc/libpas/src/libpas -fdiagnostics-color=always -Wextra -Wall -pipe -fmax-errors=20 -Wno-odr -Wno-stringop-overread -Wno-stringop-overflow -Wno-nonnull -Wno-array-bounds -Wno-expansion-to-defined -Wno-noexcept-type -Wno-psabi -Wno-misleading-indentation -Wno-maybe-uninitialized -Wundef -Wpointer-arith -Wmissing-format-attribute -Wformat-security -Wcast-align -Wno-tautological-compare -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -O2 -g0 -D_FORTIFY_SOURCE=1 -fno-strict-aliasing -fno-exceptions -fno-rtti -fcoroutines -ffunction-sections -fdata-sections -fPIC -fvisibility=hidden -fvisibility-inlines-hidden -Werror -Wno-missing-field-initializers -Wno-cast-align -std=c++23 -o Source/bmalloc/CMakeFiles/bmalloc.dir/bmalloc/AllIsoHeaps.cpp.o -c /home/tannal/tannalwork/projects/WebKit/Source/bmalloc/bmalloc/AllIsoHeaps.cpp",
  "file": "/home/tannal/tannalwork/projects/WebKit/Source/bmalloc/bmalloc/AllIsoHeaps.cpp"

Pacific Standard Time

export BR2_HOST_DIR="/home/tannal/tannalwork/projects/buildroot"
export CROSS_COMPILE="$(basename $(cat ${BR2_HOST_DIR}/usr/share/buildroot/toolchainfile.cmake|grep CMAKE_CXX_COMPILER|awk -F'"' '{print $2}')|sed "s/g++$//g")"
export PATH="${BR2_HOST_DIR}/usr/bin:${PATH}"
export CC="${CROSS_COMPILE}gcc"
export CXX="${CROSS_COMPILE}g++"

export BUILD_JSC_ARGS="--cmakeargs=-DCMAKE_TOOLCHAIN_FILE=${BR2_HOST_DIR}/usr/share/buildroot/toolchainfile.cmake"
export CC=aarch64-linux-gnu-gcc
export CXX=aarch64-linux-gnu-g++
Tools/Scripts/build-jsc --jsc-only --debug


3474:	a9be7bfd 	stp	x29, x30, [sp, #-32]!
3478:	910003fd 	mov	x29, sp
347c:	b9001fe0 	str	w0, [sp, #28]
3480:	f9000be1 	str	x1, [sp, #16]
3484:	97fff624 	bl	d14 <yylex>
3488:	b00000e0 	adrp	x0, 20000 <__data_start>
348c:	91012000 	add	x0, x0, #0x48
3490:	b9400000 	ldr	w0, [x0]
3494:	2a0003e1 	mov	w1, w0
3498:	90000000 	adrp	x0, 3000 <yy_scan_buffer+0x7c>
349c:	91214000 	add	x0, x0, #0x850
34a0:	97fff5bc 	bl	b90 <printf@plt>
34a4:	52800000 	mov	w0, #0x0                   	// #0
34a8:	a8c27bfd 	ldp	x29, x30, [sp], #32
34ac:	d65f03c0 	ret


00402191
disassembleBase64('MHg2RjAwRTQwMAo=')

91 00 03 fd
fd030091

qemu-aarch64 -L /home/tannal/tannalwork/projects/buildroot/output/host/aarch64-buildroot-linux-gnu/sysroot  WebKitBuild/JSCOnly/Debug/bin/jsc

disassembleBase64('/QMAkQ==')

./Tools/Scripts/build-jsc --jsc-only --debug

git pull

./Tools/Scripts/build-jsc --jsc-only
./Tools/Scripts/run-jsc --jsc-only

Tools/Scripts/run-jsc --jsc-only --release -m ~/tannalwork/cans/add.js --useJIT=0 --useWebAssembly=1


./Tools/Scripts/update-webkit-flatpak
./Tools/Scripts/update-webkitgtk-libs

./Tools/Scripts/build-webkit --gtk --debug --export-compile-commands WK_USE_CCACHE=YES
./Tools/Scripts/run-minibrowser --gtk --debug https://browserbench.org/MotionMark1.3

sudo perf record -F 99 -p `pgrep -n WebKitWebProces` -g -- sleep 30
sudo perf record --call-graph dwarf -F 99 -p `pgrep -n WebKitWebProces` -g -- sleep 30
sudo perf script > ./graph/out.webkitstacks01
./stackcollapse-perf.pl < ./graph/out.webkitstacks01 | ./flamegraph.pl > ./graph/out.webkitstacks01.svg

Tools/Scripts/run-webkit-tests --debug --gtk fast/dom/HTMLAnchorElement/anchor-file-blob-convert-to-download-async-delegate.html

./Tools/Scripts/run-minibrowser --gtk --debug

# setup

```bash

sudo apt-get -y install ninja-build flatpak

git clone https://github.com/WebKit/WebKit

./Tools/Scripts/update-webkit-flatpak

./Tools/Scripts/update-webkitgtk-libs


export CC="clang"
export CXX="clang++"

export LD_LIBRARY_PATH=/opt/llvm/lib:$LD_LIBRARY_PATH

export CC="/opt/llvm/bin/clang"
export CXX="/opt/llvm/bin/clang++"

./Tools/Scripts/build-webkit --gtk --debug --export-compile-commands --update-dependencies --reconfigure WK_USE_CCACHE=YES -- -j 8

export LD_LIBRARY_PATH=/opt/llvm/lib:$LD_LIBRARY_PATH

./Tools/Scripts/build-webkit --gtk --debug --export-compile-commands WK_USE_CCACHE=YES -- -j 8
./Tools/Scripts/build-webkit --gtk --debug WK_USE_CCACHE=YES

./Tools/Scripts/run-minibrowser --gtk --debug

ln -s WebKitBuild/GTK/Debug/compile_commands.json compile_commands.json

rm compile_commands.json

ln -s ./WebKitBuild/GTK/Debug/DeveloperTools/compile_commands.json compile_commands.json

import-w3c-tests web-platform-tests/[testsDir] -l -s [wptParentDir] --clean-dest-dir

```

```bash

// settings

{
    "clangd.path": "/home/tannal/tannalwork/clangd"
}

// clangd
#!/bin/bash
set -eu
# https://stackoverflow.com/a/17841619
function join_by { local d=${1-} f=${2-}; if shift 2; then printf %s "$f" "${@/#/$d}"; fi; }

local_webkit=/home/tannal/tannalwork/projects/WebKit
include_path=("$local_webkit"/WebKitBuild/UserFlatpak/runtime/org.webkit.Sdk/x86_64/*/active/files/include)
if [ ! -f "${include_path[0]}/stdio.h" ]; then
  echo "Couldn't find the directory hosting the /usr/include of the flatpak SDK."
  exit 1
fi
include_path="${include_path[0]}"
mappings=(
  "$local_webkit/WebKitBuild/GTK/Debug=/app/webkit/WebKitBuild/Debug"
  "$local_webkit/WebKitBuild/GTK/Release=/app/webkit/WebKitBuild/Release"
  "$local_webkit=/app/webkit"
  "$include_path=/usr/include"
)

exec "$local_webkit"/Tools/Scripts/webkit-flatpak --gtk --debug run -c clangd --path-mappings="$(join_by , "${mappings[@]}")" "$@"

```

# people

JavaScriptCore (JSC, Apple的JavaScript引擎):

Maciej Stachowiak
WebKit项目联合创始人
仍在Apple工作
Geoffrey Garen
JSC的主要贡献者之一
仍在Apple工作
Filip Pizlo
JSC核心开发者
已离开Apple，现在在Figma工作

involves:cdumez
involves:alanbaradlay
involves:Constellation
involves:achristensen07
involves:tadeuzagallo
involves:annevk
involves:youennf
involves:whsieh
involves:rniwa
involves:mwyrzykowski
involves:philn
involves:Ahmad-S792
involves:pvollan
involves:nt1m
involves:fujii
involves:carlosgcampos
involves:smfr
involves:JonWBedard
involves:webkit-commit-queue
involves:kkinnunen-apple
involves:xeenon
involves:jyavenard
involves:anttijk
involves:twilco
involves:szewai
involves:pxlcoder
involves:rwlbuis
involves:graouts
involves:hortont424
involves:aestes
involves:jernoble
involves:donny-dont
involves:dpino
involves:karlrackler
involves:beidson
involves:shallawa
involves:litherum
involves:mcatanzaro
involves:robert-jenner
involves:rkirsling
involves:megangardner
involves:aj062
involves:eric-carlson
involves:brentfulgham
involves:aperezdc
involves:clopez
involves:msaboff
involves:dcrousso
involves:zdobersek
involves:grorg
involves:darinadler
involves:weinig
involves:lauromoura
involves:ryanhaddad
involves:geoffreygaren
involves:yury-s
involves:fleizach
involves:aproskuryakov
involves:alexgcastro


involves:robert-jenner
involves:ddkilzer
involves:nmoucht

involves:megangardner
involves:mattwoodrow
involves:rniwa
involves:nt1m
involves:geoffreygaren
involves:aprotyas
involves:nmoucht
involves:kmiller68
involves:weinig
involves:cdumez
involves:gsnedders
involves:brentfulgham
involves:donny-dont


involves:Constellation

https://app.slack.com/client/T06G50708/CTV4FGWF4


# inbox

https://docs.webkit.org/Build%20%26%20Debug/BuildOptions.html#building-with-compile_commandsjson


git log --grep=LTO -- Source/JavaScriptCore

Elliott Williams

Tools/Scripts/run-minibrowser --gtk --debug

Tools/Scripts/run-jsc --jsc-only --release -m ~/tannalwork/cans/add.js --useJIT=0 --useWebAssembly=1

export WEBKIT_OUTPUTDIR=WebKitBuild/GTK/Debug/
export WEBKIT_OUTPUTDIR=WebKitBuild/JSCOnly/Debug/

Tools/Scripts/run-jsc-stress-tests  --env-vars "JSC_useWasmIPInt=0 JSC_useWasmLLInt=1 JSC_useWebAssembly=1 JSC_useJIT=0" -j $WEBKIT_OUTPUTDIR/bin/jsc JSTests/wasm.yaml --filter=wasm.yaml/wasm/spec-tests/i64

idl
TreatNullAs=NullString

http://localhost:8001/workers/postMessage_block.https.html

(cat /proc/94310/environ; echo) | tr '\000' '\n'

https://github.com/WebKit/WebKit/commits?author=cathiechen

https://github.com/WebKit/WebKit/commits/main/?author=rniwa


# dev

ln -sf $VM/compile_commands.json compile_commands.json
rm -rf WebKitBuild/{WPE,GTK,JSCOnly}
CXX=clang++ CC=clang CFLAGS=-flto CXXFLAGS=-flto LDFLAGS=-flto Tools/Scripts/build-webkit --wpe --release --export-compile-commands --fuse-ld=lld
export BUILDDIR=/home/justin/WebKit/ReleaseVersion/OpenSource/; export VM=$BUILDDIR/WebKitBuild/WPE/Release/; LD_LIBRARY_PATH=$VM $VM/bin/jsc --validateOptions=1


# webkit/webcore

```cpp
// ContainerNode.cpp
// In the DOM, a container node is a node that can have child nodes. Examples of container nodes include elements like <div>, <ul>, and <table>. The ContainerNode class provides common functionality and operations for manipulating and managing child nodes within these container elements.

// Comment.cpp
// It contains various algorithms and utility functions related to manipulating and traversing the Document Object Model (DOM) nodes.

<!-- This is a comment -->

// Source/WebCore/dom/ContentVisibilityAutoStateChangeEvent.cpp
// Automatic content visibility is a feature introduced in WebKit to improve the performance and power efficiency of web browsing. It allows the browser engine to automatically adjust the rendering and resource allocation for content that is not currently visible to the user. For example, when a webpage is scrolled out of view or hidden behind other windows, the automatic content visibility feature can reduce the processing and rendering overhead for that content.

// The ContentVisibilityAutoStateChangeEvent class is used to represent events that occur when the automatic content visibility state of a webpage changes. It provides information about the affected content and the new visibility state.


```

rendering and layout, JavaScript execution, networking, and handling HTML and CSS parsing.

The hard part of learning is the "bootstrap" problem (like compilers).

These series tell you some part of webkit project on how it works.

And How it interract with other parts?

I think the existing knowledge can lead you learn more.

## WebKit/Source/JavaScriptCore/heap/LocalAllocator.cpp

This is webkit memory allocator

## heap/ -> runtime/

js Runtime use allocateCell to allocate memory for js objects

runtime/ include allocateCell

There is a common practice that member variable with prefix 'm_' which indicates it's scope.

## runtime/

vmEntryToJavaScript

js_trampoline_op_call

heap::addToRememberedSet

for minor gc add old space objects with hold reference to the eden space, we need these objects be treated like gc roots.

# reference

https://blogs.igalia.com/aboya/2021/10/02/setting-up-visualstudio-code-to-work-with-webkitgtk-using-clangd/
