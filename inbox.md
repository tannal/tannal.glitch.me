# 2024-4-22 0 | 0 W

export PKG_CONFIG_PATH=/home/tannal/tannalwork/projects/mozilla-unified/js/src/build/lib/pkgconfig
export LD_LIBRARY_PATH=/home/tannal/tannalwork/projects/mozilla-unified/js/src/build/lib

cd js/src
mkdir _build
cd _build
../configure --disable-jemalloc --with-system-zlib \
    --with-intl-api --enable-debug --enable-optimize
make -j23
make install  # sudo if necessary


# 2024-4-21 0 | 0 W

https://www.collabora.com/careers.html

Red Hat officially acquired by IBM

https://wanghenshui.github.io/recommend.html

sudo sh -c 'echo 1 >/proc/sys/kernel/perf_event_paranoid'
The files under /proc/sys/ also have the sysctl command for easy access, so you can instead do:

sudo sysctl -w kernel.perf_event_paranoid=1
(though the -w for write seems to be optional). To ensure this is done at boot time create your own /etc/sysctl.d/99-mysettings.conf file with the line

kernel.perf_event_paranoid=1
Choose a filename that will not override existing files in /run/sysctl.d/ and /usr/lib/sysctl.d/. See man sysctl.d.

rustup target add wasm32-unknown-unknown
rustup target add wasm32-wasi
cargo build -Zbuild-std

sudo apt install imagemagick-6.q16

meson setup --wipe build

https://adobe-webplatform.github.io/about/

involves:LeaVerou


# 2024-4-20 0 | 0 W

102nd TC39 meeting (June 11-13, 2024)
Future Frontend 2024 (June 13-14, 2024)
PLDI 2024 (June 24-28, 2024)
JSConf Budapest (June 27-28, 2024)

gdb -ex "target remote <IP address>:9953" -p <pid>

bit per pixels 32 usually
give a position(x, y)
tell the caller the memory address of the data

https://sourceware.org/gdb/current/onlinedocs/gdb.html/TUI-Keys.html#TUI-Keys

involves:Manishearth 

git pull
vcpkg update
vcpkg install libvpx:x64-windows-static libyuv:x64-windows-static opus:x64-windows-static aom:x64-windows-static

make LLAMA_CUDA=1 -j16

set substitute-path . ./linux

git clone https://github.com/ggerganov/llama.cpp

cmake -B build -DLLAMA_CUDA=ON
cmake --build buil --config Release

code can run, easy to use is great.

https://github.com/search?q=involves%3AManishearth+&type=issues&p=2

sudo apt install liblttng-ust-dev
sudo bpftrace -e 'tracepoint:raw_syscalls:sys_enter { @[comm] = count(); }'

git clone https://github.com/brendangregg/FlameGraph.git
profile.py -df -F 99 10 | ./FlameGraph/flamegraph.pl > flamegraph.svg


pmap 78615

vmstat

objcopy -O binary file.elf file.bin

ps --ppid 2 -p 2 -o uname,pid,ppid,cmd,cls

nm vmlinux | grep ksys_read
addr2line -s -f -e vmlinux ffffffff81467fe0
ksys_read
read_write.c:609

# 2024-4-19 0 | 0 W

Install perf (usually available through the linux-tools-common package if not already installed)

Try running perf - it might complain about missing kernel modules, install them too

Run node with perf enabled (see perf output issues for tips specific to Node.js versions)

perf record -e cycles:u -g -- node --perf-basic-prof app.js

Disregard warnings unless they're saying you can't run perf due to missing packages; you may get some warnings about not being able to access kernel module samples which you're not after anyway.

Run perf script > perfs.out to generate the data file you'll visualize in a moment. It's useful to apply some cleanup for a more readable graph

Install stackvis if not yet installed npm i -g stackvis

Run stackvis perf < perfs.out > flamegraph.htm

node --prof-process --preprocess -j isolate*.log > processed.txt

perf record -e cycles:u -g -- ./node_g --perf-basic-prof test.js
perf script > perfs.out
npm i -g stackvis


How to design reliable file systems?

https://www.felixcloutier.com/x86/intn:into:int3:int1


wasm ebpf mlsys go rust mesa graphics web glphy
layout render engine js engine 
multimedia video audio
database & storage systems
operating systems and 

embeded arm linux rtos https://www.linaro.org/careers/

# 2024-4-18 0 | 0 W

find build -type f -executable
js/bin/

sudo apt install radeontop

./gitea -c './conf/app.ini' admin regenerate hooks

:s/\\/\//g

# 2024-4-17 0 | 0 W

git pull -X theirs origin main

sudo certbot certonly --webroot -w /var/www/example -d example.com -d www.example.com

sudo certbot certonly --standalone  -d git.tanmeng.org -d www.tanmeng.org -d m.tanmeng.org

sudo certbot certonly --standalone -d *.tanmeng.org

winget install --id=EFF.Certbot  -e



# 2024-4-16 0 | 0 W

https://gitlab.freedesktop.org/apinheiro
Alejandro Piñeiro
The guy who give the upstream driver to mesa for Raspberrypi 5
igalian

how many line of codes you written?
how many line of codes are in production now?

How better you are is defined by how much fatansitic things that you have done before.
Not your degree, not by face, not by size. 
Tell others about your story, what you done before? Why you are an amazing person?

The people who steal others algorithm blame the people steam other's code.

javac -encoding utf8 Solution.java

So the memory used when calling a function is working memory, 

the state of the object is actually acquired by experience, and it's size can be very big.

# 2024-4-15 0 | 0 W

is:issue is:closed reason:completed 

cargo add --git https://github.com/servo/html5ever

cargo add --git https://github.com/y-crdt/y-crdt y-crdt

find meanings in partial truth

cargo add --git https://github.com/y-crdt/y-crdt y-crdt

git pull -X theirs origin main

sudo stackcount-bpfcc -p 3491 -i 2 --debug "*drm_context_switch*"

https://www.historyofcomputercommunications.info/

Meaning is all you need.

three things in late 90s
object oriented programming (dominant codebase)
graphics user interface (GUI)
networked computer systems (servers)

What you do when you need something?

if this is posible or not?
if is not possible -> who tried it? where are the attempt?
if is possible -> who did it? how they did it? make it better

Science depends on the observable consequences of theories, and
biology yields testable predictions. Psychology too leads to testable predictions.

History of the computer

electricity and physics pre-1945
semiconductor and integrated circuits 1950 (bell labs)
personal computers and operating systems and programming languages 1990
the web and the internet (gaming) 2000
the mobile phone (gaming) 2010
what do we have in 2020? pandemic
seems like the next things in 2030? is AI?

actually in the 80s because of the big boom of programming languages.
there was a bunch of scentists which wants to program an AI system.

The sad parts is that academic researchers can't win the fight with entrepreneurs.
Netscape is the one invent the web, but they don't make the amount of money they deserve.
Google, Facebook, Netflix, Amazon are the biggest winner of the web and definitely good users of the web.
We should believe that there is a gap between interface and implementation.
A good users always won, a good impementor or inventor is just a good user of other things.
(You can say that the people who invent the web are good users of parsers? layout? typesetting? rendering? networking?)
They (the inventors of the web) don't invent these things.But they find a good way to fit these kind of beautiful things together.

The same theory applys to me also for ai, may be I don't have thousands of nvidia graphics cards, but the good users always win.
Be a good user.


DARPA
-> Advanced Research Projects Agency Network
-> The Mother of All Demos
-> MIT csail
-> Internet

Xero Alto (America)
-> apple (in the late 80s, jobs claims that web is going to be huge many times)
  -> microsoft
-> Sun Microsystems Laboratories
-> Adobe


I doubt that we will have another browsers war in any time soon (let's say ten years), because microsoft wanted it in 2014, and ms give it up in 2019. Another reason is that the w3c(render engine) and tc39(js engine) now are more powerful that it was in early 2000s or late 90s (they both founded in late 90s), it's no easier to challege the specs, or if you do a brand new browsers in 2024. 

if you fully commited into the spec, you find it hard to write the code. or if you don't fully commited to it, users may say your system is bad.(maybe not). It's hard to do.

Bell labs (America)
-> UNIX
-> semiconductor fun fact the first generation of scientist in the semiconductor industry has all passed way.
-> Intel
-> AMD
-> 

Free Software Movement (Eurpoe) in the era of late 90s
-> GNU
-> Linux
-> web server
-> Netscape (netscape -> mozilla triggers the open source software movement while at that time microsoft's business model is software liscenising and mozilla losts the first web browsers war)

-> RedHat
-> apache
-> mozilla
-> github

Internet 2000
- Facebook
-> Google
->->Android
- Apple
->->ios
- Netflix
- Amazon

Mobile phone


Tht future



machine code & assembly
B(1969) -> C(1972) -> Go by bell labs folks

Apple folks llvm -> objective C -> swift

Microsoft folks C# Typescript

oop C++ 


# 2024-4-14 0 | 0 W

A B C D E E E E E E E E 

Dan Ingalls the smalltalk project now at yc combinator research

Programmers want to work on one routine without having to think about all of them at the same time.
if this is true, when you reading code, you also don't need to think all of them at the same time.

git remote add origin http://git.tanmeng.org/tannal/tannal.git

go install 
go uninstall

export PATH=${PATH}:`go env GOPATH`/bin

sudo tcpdump -i any -AX -vv 'port 3000'

https://www.cs.cmu.edu/~garth/15719/lectures/15719-S17-Networking.pdf

https://www.cs.cmu.edu/afs/cs/academic/class/15745-s18/www/lectures/L4-LLVM2.pdf

b /home/tannal/tannalwork/projects/mozilla-unified/widget/gtk/nsClipboard.cpp:606

sudo sysctl -w fs.inotify.max_user_watches=131072

# 2024-4-13 0 | 0 W

https://bootlin.com/training/

GEM Graphics excution/memory manager
DRM KMS

It's often to give up an abstraction when it's leaking too much or too often.

k8s k3s k0s k9s

if you know what you doing, you can do it.
because you understand how machine works.


git clone https://github.com/ColinIanKing/faultstat
make
sudo faultstat 60 1

xchg a adress 1 and 0
if the result is 1, you get the lock
then break the loop
if the result is 0, you are blocking by others.

test and set
exchange

you can check whether data is right use assert
you can check whether the code path is right using logging debugging and tracing.(it can be tricky in a concurrent system)

there are some complex things you need to do with a codebase instead of fix some issues or add a small features
for anything beyond that, it is consider a project, which often involve documents 
what goals you want to achieve?
what problems do you want tot solve?

what are the easy way greedy way to do?
what are the better way to do if any? (you mostly don't need a best way)
what are the alternative ways?

what's your timeline?

what are the bad things that could happens during the timeline?

If a object can reference another object
it can invoke all the method it has.

the object must knows all the semantics of the another object's methods or functions


if a type can reference the anthoer type.

Eugene Charniak

# 2024-4-12 0 | 0 W

trident

https://webapi.link/

the power of default and trasparency and automatic
people don't complian the implicit dependency 

vertex shader
Tessellation shader
geometry shader
pixel shader

predicate
The cat

target record-full
target record-core

https://gecko-embedded.org/

./configure --without-x --without-freetype

git clone git://source.winehq.org/git/wine.git

qemu-system-x86_64 -kernel bzImage-debug -m 3G -initrd root.cpio.gz -append "console=ttyS0 console=tty0 root=/dev/ram ip=dhcp" 

-device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=hostshare -fsdev local,security_model=passthrough,id=fsdev0,path=sharem/file/


The "equalizing" tools help the average programmer when everything works well, but they make it significantly more difficult for them when problems arise. Today's tools have given us many leaky abstractions.

The software is getting worse to write when it becomes easy for customers to use

# 2024-4-11 0 | 0 W

let document = self.documents.borrow().find_document(id);

Flutter Team
https://github.com/search?q=involves%3Ahixie&type=issues
https://github.com/search?q=involves%3Agrouma&type=issues
https://github.com/search?q=involves%3Avsmenon&type=issues


git clone https://github.com/karpathy/llm.c

watch -n 0.1 nvidia-smi

python train_gpt2.py
make train_gpt2
make train_gpt2cu

OMP_NUM_THREADS=8 ./train_gpt2

./aliyunpan

false search
truth search

KDAB
https://floss.social/@servo

QT kdab
https://blog.mggross.com/
https://github.com/ahayzen

# 2024-4-10 0 | 0 W



Let the Acutally User write the docs, not the implementer.
User need to comunicate with implementers, get the right conclusion then write the docs.


control character
content character

inferences can lead to emotions

It's about the content, not the process.

The more models we hold in mind.
The worse performance becomes.

https://codepen.io/hrtzt/pens/public

echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope

rb query

BEGIN;
=> DELETE FROM t;
=> SELECT pg_current_xact_id();

./psql -h 192.168.43.246 -p 5432 -U tannal -d exchange

libglvnd
OpenGL/GLES

git rm -r --cached 


-fverbose-asm -S

10ms
fair scheduler

# 2024-4-9 0 | 0 W

@TODO
How to build a Database? A lazy approach.

go test -benchmem -run=^$ -bench .
go test -benchcpu -run=^$ -bench .


the mental model remember what is true
not what is false

Philip N. Johnson-Laird

https://www.pnas.org/

simple mind is useful in the current science and math

We only feel bad about two things
do the wrong thing and get stuck

why some of articles can be read through by i?
and some of articles can't be read through

objdump -d 

# 2024-4-8 0 | 0 W

sudo apt  install protoc-gen-go
protoc --go_out=. sst.proto

git rm -r --cached examples/*.swap
git update-index --assume-unchanged examples/*.swap

git clone https://github.com/rr-debugger/rr.git
rr debugger
cmake --install build

cmake -B build 

sudo apt-get install ccache cmake make g++-multilib gdb lldb \
  pkg-config coreutils python3-pexpect manpages-dev git \
  ninja-build capnproto libcapnp-dev zlib1g-dev

echo "kernel.perf_event_paranoid = 1" | sudo tee -a /etc/sysctl.d/10-rr.conf
sudo  sysctl --system

igalia compiler team https://github.com/takikawa

$LLVM_DIR/bin/clang -O1 -S -emit-llvm ./inputs/input_for_mba.c -o input_for_mba_host.ll
$LLVM_DIR/bin/opt -load-pass-plugin ./host/lib/libMBAAdd.so -passes="mba-add" -disable-output input_for_mba_host.ll -debug

export LLVM_DIR=/opt/llvm
$LLVM_DIR/bin/clang -O1 -S -emit-llvm ./inputs/input_for_hello.c -o input_for_hello.ll
$LLVM_DIR/bin/opt -load-pass-plugin ./build/lib/libHelloWorld.so -passes=hello-world -disable-output input_for_hello.ll


sudo apt install libedit-dev libzstd-dev libcurl4-openssl-dev

  File "/usr/bin/dstat", line 2847, in <module>
    main()
  File "/usr/bin/dstat", line 2687, in main
    scheduler.run()
  File "/usr/lib/python3.10/sched.py", line 151, in run
    action(*argument, **kwargs)
  File "/usr/bin/dstat", line 2804, in perform
    line = line + o.show() + o.showend(totlist, vislist)
  File "/usr/bin/dstat", line 519, in show
    line = line + cprintlist(self.val[name], ctype, self.width, scale)
  File "/usr/bin/dstat", line 2087, in cprintlist
    ret = ret + sep + cprint(var, ctype, width, scale)
  File "/usr/bin/dstat", line 2137, in cprint
    ret, c = dchg(var, width, base)
  File "/usr/bin/dstat", line 2037, in dchg
    ret = str(int(round(var)))
OverflowError: cannot convert float infinity to integer


コンパイラ
コミット

https://news.ycombinator.com/from?site=google.github.io

https://news.ycombinator.com/from?site=facebook.github.io

https://news.ycombinator.com/from?site=microsoft.github.io

https://news.ycombinator.com/from?site=netflix.github.io

https://news.ycombinator.com/from?site=shopify.github.io

https://news.ycombinator.com/from?site=alibaba.github.io

https://news.ycombinator.com/from?site=apple.github.io

macro_rules!
enhanced c macro declared
procdure macro

what comes to your mind when you see this code?

# 2024-4-7 0 | 0 W

https://github.com/search?q=%22Request+for+Position%22&type=issues


g++ -I. -I/home/tannal/tannalwork/projects/v8/v8/include main.cc -o main -fno-rtti -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX

apt.llvm.org

nm /home/tannal/.nvm/versions/node/v20.10.0/bin/node | c++filt | less -pv8::
strings /home/tannal/.nvm/versions/node/v20.10.0/bin/node | less -plibv8

/home/tannal/tannalwork/projects/v8/v8/third_party/libc++/src/include
/home/tannal/tannalwork/projects/v8/v8/out/x64.debug/


g++ -I/home/tannal/tannalwork/projects/v8/v8/include main.cc -o main -fno-rtti -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX


g++ -I. -Iinclude samples/hello-world.cc -o hello_world -fno-rtti -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -Lout.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX

gn gen out.gn/x64.release --args="is_debug=false use_glib=false is_component_build=true v8_use_external_startup_data=true v8_static_library=false is_clang = false v8_enable_i18n_support=false target_cpu=\"x64\""

1. reading spec
2. reading code
3. talking with someone
4. write some code
5. goto 1

https://validator.w3.org/nu/?doc=https%3A%2F%2Fwww.bilibili.com&submit=Check

https://www.andrew.cmu.edu/user/mm6/95-702/slides/


# 2024-4-6 0 | 0 W

https://codesearch.debian.net/search?q=VLDB&literal=1&page=10

https://interplayoflight.wordpress.com/2018/09/30/readings-on-the-state-of-the-art-in-rendering/

https://arstechnica.com/

- Adam Barth
- Dimitri Glazkov
- Nate Chapin
- Kentaro Hara


# 2024-4-5 0 | 0 W

https://codesearch.debian.net/search?q=OSDI&literal=1&page=10


https://codesearch.debian.net/search?q=PLDI&literal=1&page=10
netscape -> firefox
ie -> died
KDE -> Webkit -> Blink

update nodejs version very two lts
nodjs headers are needed to compile binary addons

code as an universal language
math symbols as an universal language
music as  an universal language

regiter integer float 

compiler
involves:dnovillo

# 2024-4-4 0 | 0 W

sudo vim /run/systemd/resolve/resolv.conf

https://www.zhihu.com/question/481137524

399 2023 3 26 13:58

git config --add remote.origin.proxy ""

# 2024-4-3 0 | 0 W

https://github.com/linebender/xilem/issues/157

the feeling of catch up and following the context
you can ignore


Oriol Brufau

sudo dpkg --add-architecture amd64
sudo dpkg --remove-architecture amd64
sudo apt update

sudo apt remove libc6-amd64-cross

zig cc

export LISTEN_ADDRESS=:4874

Libre Graphics Meeting
https://github.com/servo/pathfinder/issues/142


# 2024-4-2 0 | 0 W

https://en.opensuse.org/openSUSE:Members

https://github.com/HollowMan6

https://bugzilla.mozilla.org/show_bug.cgi?id=1868293


# 2024-4-1 0 | 0 W


ln -sfn /run/systemd/resolve/resolv.conf /etc/resolv.conf


export CC=/usr/bin/cc
export CXX=/usr/bin/c++

./act_runner-nightly-linux-amd64 generate-config > config.yaml

./act_runner-nightly-linux-amd64 register --no-interactive --instance http://git.tanmeng.org --token FVYzTAmBWqiC1rdVBPz48U0XTCEhQjflreRNnrlz --config config.yaml

./act_runner-nightly-linux-amd64 daemon --config config.yaml

 taskkill /f /IM nginx.exe

.\geodns.exe -log

start nginx.exe

geodns

start nginx
nginx.exe -s stop
nginx.exe -c 


dig -x 192.168.43.62 @127.1 -p 5053

ipconfig /flushdns

addyosmani
miekg


.\act_runner-nightly-windows-amd64.exe generate-config > config.yaml

.\act_runner-nightly-windows-amd64.exe daemon --config config.yaml

.\act_runner-nightly-windows-amd64.exe register --no-interactive --instance http://192.168.43.1:3000 --token 4Z6mH85Mv6aviiBSaBSk393VzFWPCsdnLOYDULs0 --config config.yaml

snap install zig --classic --beta

git clone https://www.github.com/ziglang/zig
cc -o bootstrap bootstrap.c
./bootstrap

  force_sig_fault
  force_signal_inject
  do_el0_undef
  el0_undef
  el0t_64_sync_handler
  el0t_64_sync
  [unknown]
  [unknown]
  [unknown]
    b'DOM Worker' [4435]
    1

git remote add origin http://10.90.179.123:3000/tannal/tannal.com.git

rocallahan

https://wicg.io/

whatwg chat room
https://app.element.io/#/room/#whatwg:matrix.org


# 2024-3-31 0 | 0 W

ps -eo pcpu,pid,user,args | tail -n +2 | sort -k1 -r -n | head -10

500 cycles
speed up syscall bypass syscalls

https://github.com/search?q=involves%3Asaschanaz&type=issues

psql -h 192.168.43.246 -p 5432 -U tannal -d postgres 

int iret syscall sysret sysenter page fault(mov) hardware exception

https://wiki.linuxfoundation.org/gsoc/2024-gsoc-perf

make sense flush 

code run/debug/log tell you the idea
change the code to program slightly different idea

DOM + CSS CSS Animation & Javascript Animation

Canvas svg

WebGL Webgpu shader texture

# 2024-3-30 0 | 0 W

https://github.com/cisen/blog/issues

https://github.com/search?q=repo%3Anrc%2Frustaceans.org%20servo&type=code

git config core.fsMonitor false --global

sudo snap install go --classic
git clone https://github.com/nektos/act.git
make -j22
make install
go build -ldflags "-X main.version=0.2.60-11-gf825e42-dirty" -o dist/local/act main.go
cp: cannot create regular file '/usr/local/bin/act': Permission denied


https://app.element.io/#/room/#wpt:matrix.org

email
slack
groups.google.com
github
discord
zulip
element

Webassembly people https://github.com/WebAssembly/meetings/issues/1463

source /home/tannal/.local/pipx/venvs/numpy/bin/activate

https://groups.google.com/a/chromium.org/g/extensions-dev
https://groups.google.com/a/chromium.org/g/proto-quic
https://groups.google.com/a/chromium.org/g/chromium-html5/c/ypYpENVylLY

css module script
json module script

git config --global core.untrackedCache true
git config --global core.fsmonitor true

Good artists copy, great artists steal.

# 2024-3-29 0 | 0 W

Peter Kasting

Evan Martin, the creator of Ninja, blogs about his newest build system,
n2: http://neugierig.org/software/blog/2022/03/n2.html
Anyone interested in evaluating this for llvm use?

Hotspot 编译器是自 Oracle Hotspot VM 的 1.3 版本引入的，Dalvik VM 引入 JIT 编译器是从 Android 2.2 开始的。

(python(base) [root@g08 ultralytics-8.1.0]# gcc --help | grep dump
  -dumpspecs               Display all of the built in spec strings.
  -dumpversion             Display the version of the compiler.
  -dumpmachine             Display the compiler's target processor.
(python(base) [root@g08 ultralytics-8.1.0]# gcc --help | grep print
  -print-search-dirs       Display the directories in the compiler's search path.
  -print-libgcc-file-name  Display the name of the compiler's companion library.
  -print-file-name=<lib>   Display the full path to library <lib>.
  -print-prog-name=<prog>  Display the full path to compiler component <prog>.
  -print-multiarch         Display the target's normalized GNU triplet, used as
  -print-multi-directory   Display the root directory for versions of libgcc.
  -print-multi-lib         Display the mapping between command line options and
  -print-multi-os-directory Display the relative path to OS libraries.
  -print-sysroot           Display the target libraries directory.
  -print-sysroot-headers-suffix Display the sysroot suffix used to find headers.
(python(base) [root@g08 ultralytics-8.1.0]# gcc --help | grep display
  (Use '-v --help' to display command line options of sub-processes).
(python(base) [root@g08 ultralytics-8.1.0]# gcc --help | grep ast
(python(base) [root@g08 ultralytics-8.1.0]# gcc --help | grep ir
  -print-search-dirs       Display the directories in the compiler's search path.
  -print-multi-directory   Display the root directory for versions of libgcc.
                           multiple library search directories.
  -print-multi-os-directory Display the relative path to OS libraries.
  -print-sysroot           Display the target libraries directory.
  --sysroot=<directory>    Use <directory> as the root directory for headers
  -B <directory>           Add <directory> to the compiler's search paths.
(python(base) [root@g08 ultralytics-8.1.0]# 

BIOS load bootloader

system boot
Interrupt GDT IDT CR3
Memory Management address translation

# 2024-3-28 0 | 0 W

# 2024-3-27 0 | 0 W

https://fastsys.cs.tsinghua.edu.cn/

https://www.felixcloutier.com/x86/iret:iretd:iretq

CPL=0, ring0, iret return from the interrupt

trap frame

EFLAGS(program status and control) register

Disable interrupt
Save key registers
Switch onto the kernel interrupt stack
Push key registers onto new stack
Save error code (optional)
Invoke interrupt handler
Handler pushes all registers on stack

professor, can you explain this slide for me?

select count(*) from tbl where (x + y) > 100
aggregation scan filter

```js

let count = 0

while(tuple = get_next()) {
  
  if(tuple.x + tuple.y > 20) {
    count++
  }
}

return count

```

layout algorithm in browser

flow.rs positioned.rs table flex grid float replacedContent

RISC-V status Fedora KDE Desktop AOSP GCC Arch Linux debian openEuler Clang/LLVM QEMU V8 SpiderMonkey OpenJDK

ROCm GPU Computing

# 2024-3-26 0 | 0 W


&type=meta

image audio text

https://www.bing.com/chat?showconv=1&wlexpsignin=1&wlexpsignin=1

I would say that research is a prototype for a startup.

# 2024-3-25 0 | 0 W

go install golang.org/x/tools/present@latest
go install golang.org/x/tools/cmd/present@latest

vim $(fzf)

AI for Science

pwdx 2644995
ps -f 2644995

./zrj/bin/pip install setuptools wheel

python -m pip install torchvision==0.15.2+cu118 --index-url https://download.pytorch.org/whl/cu118.

python -m pip install torch==2.0.1+cu118 --index-url https://download.pytorch.org/whl/cu118

>>> import torch

>>> torch.cuda.is_available()
True

>>> torch.cuda.device_count()
1

>>> torch.cuda.current_device()
0

>>> torch.cuda.device(0)
<torch.cuda.device at 0x7efce0b03be0>

>>> torch.cuda.get_device_name(0)
'GeForce GTX 950M'

export PATH=/root/tannalwork/cpython/python3.11/bin:"$PATH"
virtualenv venv python=python3.11
pip install torch==2.0.1 torchvision==0.15+cu111 torchaudio==2.0.2
python3.11 -m venv zrj python=python3.8

python -m pip install -e .

Good artists copy, great artists steal.

sudo tcpdump -i any -AX -vv 'port 8000'
sudo tcpdump -i any tcp port 8080

for i in {1..50}; do touch "index$i.html"; done

# 2024-3-24 0 | 0 W


# 2024-3-23 0 | 0 W

sudo apt install tesseract-ocr

export WAYLAND_DEBUG=1

export NPM_CONFIG_REGISTRY="http://192.168.43.246:4873"
export NPM_CONFIG_REGISTRY="http://registry.npm.taobao.org"
sudo apt install openjdk-21-jre-headless graphviz gnuplot

Jacobians

code reading group

https://fly.io/dist-sys/1/

:set tabstop=4
:set shiftwidth=4
:set expandtab

sudo apt install openjdk-<version> graphviz gnuplot

development operations

cargo tree
cargo new math --lib
cargo new/init

https://www.youtube.com/watch?v=783ccP__No8&t=134s

graphql 2012

Cache npmjs.org registry


ffmpeg -hwaccel vulkan -threads 8 -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccel cuda -threads 3 -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c:v libx264 -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccel dxva2 -threads 8 -i Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4 -f lavfi -i aevalsrc=0 -vcodec copy -acodec aac -map 0:0 -map 1:0 -c:v libx264 -pix_fmt yuv420p -shortest -strict experimental -f flv rtmp://192.168.43.246/live/livestream

ffmpeg -hwaccel dxva2 -threads 8 -re -i Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4 -f flv rtmp://192.168.43.246/live/livestream

# 2024-3-22 0 | 0 W

pgrep

ffmpeg -hwaccel cuda -threads 3 -preset ultrafast -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccels
ffmpeg -benchmark -hwaccel vdpau -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -f null -


ffmpeg -hwaccel vdpau -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ls | grep 'I' | sed "s/^/file /g" > playlist.txt

ls | grep I > playlist.txt
ffmpeg -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -vcodec libx264 -acodec aac -b:v 1m -b:a 320k -f flv rtmp://localhost/live/livestream

tannal@raspi:~/tannalwork/projects/postgres$ sha1sum meson.build 
fe9053c9c00cd8ceb9622f78da1079fbf91e2e25  meson.buil

git log --graph --decorate --oneline

microk8s

ffmpeg -loglevel panic -i ~/tannalwork/videos/FrontendMasters\ -\ CSS\ Projects/0001_Part_1--\[TutFlix.ORG]--.mp4 -frame 1 -f image2 - | convert - -colorspace gray - | feh

cat logfile | sed 's/.tannal//' | sed 's/.*DETAIL//'
cat logfile | sed 's/.tannal//' | sed 's/archive/fuck/g'

parse html parse json

xargs

1) + URL 中+号表示空格 %2B
2) 空格 URL中的空格可以用+号或者编码 %20
3) / 分隔目录和子目录 %2F
4) ? 分隔实际的 URL 和参数 %3F
5) % 指定特殊字符 %25
6) '#' 表示书签 %23
7) &amp; URL 中指定的参数间的分隔符 %26
8) = URL 中指定参数的值 %3D

video encoding/decoding
intel/amd vaapi
nvidia nvenc/nvdec

ffmpeg -hwaccel vaapi

bindings generator

$env:NPM_CONFIG_REGISTRY="http://192.168.43.246:4873"

merge two or three shiny things together create a useful project
node v8 libuv

differential testing

deepspeed multiple machines multiple cards

NVLink single machine multiple cards

Data Collection and Preprocessing
Model Selection
Initialization
Loss Function Selection
Optimizer Selection
Training
Training
Validation and Hyperparameter Tuning
Testing and Evaluation

mkdir -p examples
mv src/main.rs examples/hello-redis.rs

cargo run --example hello-redis

# 2024-3-21 0 | 0 W

libuv, twisted, tornado, asyncIO, Netty, Boost.Asio

Threads and Processes
Actor Model:
Dataflow Programming
Transactional Memory
Futures and Promises
Reactive Programming
Coroutines

ffmpeg -i J -vn -ar 16000 -ac 2 -ab 160k poor.wav

./main -m models/ggml-large-v3.bin -f poor. -l ja poor.wav

# 2024-3-20 0 | 0 W 

flex bison css parser

Human Interface Device

http://192.168.43.1:8080/quill.html

pub trait Future
library/core/src/future/future.rs

./mach test-tidy --no-progress --all

# 2024-3-19 0 | 0 W

tree path

Arrays LinkedLists

git clone https://github.com/haotian-liu/LLaVA.git
export PATH=/root/tannalwork/cpython/python3.11/bin:"$PATH"

virtualenv venv
source ./venv/bin/activate

pip install -e .


sudo stackcount-bpfcc -i 2 -p 27776 --debug "sock*"


sudo tcpdump -i any udp port 1935
sudo tcpdump -i any tcp port 1935


git clone https://github.com/ossrs/srs.git

cd trunk
sudo apt install automake
./configure && make -j4

./objs/srs -c conf/srs.conf

not doing wrong

export PATH=/root/tannalwork/cpython/python3.11/bin:"$PATH"
unset https_proxy
unset http_proxy
pip3 install torch torchvision

browser extension send browser history to server

sync directory between multiple machines

wget https://developer.nvidia.com/downloads/compute/machine-learning/tensorrt/secure/8.6.1/tars/TensorRT-8.6.1.6.Linux.x86_64-gnu.cuda-11.8.tar.gz

tar xvf TensorRT-8.6.1.6.Linux.x86_64-gnu.cuda-11.8.tar.gz

sudo apt update && sudo apt install -y cmake g++ wget unzip
 
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
unzip opencv.zip
 
cmake -B build
cmake --build build -j15
cmake --install build


cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'

./main -m models/ggml-large-v3.bin -f jeff.wav

ffmpeg -i  -vn -ar 16000 -ac 2 -ab 160k jeff.wav

git clone https://github.com/asmjit/asmjit
git clone https://github.com/blend2d/blend2d

export LIBGL_ALWAYS_SOFTWARE=1
python gdb.execute("set environment LIBGL_ALWAYS_SOFTWARE=true")


# 2024-3-18 0 | 0 W

.\esbuild.exe .\app.jsx --outfile=app.js --watch

rustc is a frontend like clang

go install github.com/gomarkdown/

go get github.com/gomarkdown/mdtohtml

ffmpeg -i C:/test.mp4 -vn -ar 16000 -ac 2 -ab 160k audio.wav

ffmpeg -i  "llama.mp4" -ab 160k -ac 2 -ar 16000 -vn -f segment -segment_time 300 llama%d.wav

./models/download-ggml-model.sh large-v3
./main -m models/ggml-base-q5_1.bin -f audio0.wav

ffmpeg -i  "Japanese React To Controversial Miss Japan Winner ｜ Street Interview.mp4" -ab 160k -ac 2 -ar 16000 -vn -f segment -segment_time 300 audio%d.wav

docker ci/cd pipeline github actions gitlab jekins


ffmpeg -i '0001_Part_1--[TutFlix.ORG]--.mp4' -ab 160k -ac 2 -ar 16000 -vn -f segment -segment_time 100 audio%d.wav

ffmpeg -i C:/test.mp4 -ab 160k -ac 2 -ar 16000 -vn -f segment -segment_time 100 audio%d.wav

sudo trace-bpfcc -UK "do_open" -a


ffmpeg -i C:/test.mp4 -ab 160k -ac 2 -ar 44100 -vn -f segment -segment_time 10 audio%d.wav


爱迪生在发明和开发电话的过程中，发现了录音设备。
电容式话筒是利用声音的大小产生忽变的压降然后经过放大到功放还原我们的声音

nc -l 0.0.0.0 1234 > docs.tar.gz
nc 192.168.43.1 1235 < docs.tar.gz

。Snapshot是启动isolate
和context的缓存，⽤于快速启动。⾥⾯也包含了code。

# 2024-3-17 0 | 0

pip install setuptools
https://gitlab.gnome.org/GNOME/gtk

gcc -o gtk gtk.c $(pkg-config --cflags --libs gtk+-4.0)
gcc $( pkg-config --cflags gtk4 ) -o gtk gtk.c $( pkg-config --libs gtk4 )


virtualenv venv
.\venv\Scripts\activate.ps

git clone https://github.com/3b1b/manim.git
pip install -e . -i https://mirrors.sustech.edu.cn/pypi/web/simple


sudo apt install wl-clipboard

echo "$XDG_SESSION_TYPE"
env | grep -E -i 'x11|xorg|wayland'
loginctl show-session $(loginctl | grep "$USER" | awk '{print $1}') -p Type

for ((i=1; i<=10; i++))
do
  go run ./cmd/raft/
done

lsb_release -a

go help buildmode

wasi is not fully useful yet
we need to seek some apps which use less system api eg text editor, multimedia

.\esbuild.exe .\app.jsx --outfile=app.js --watch
.\esbuild.exe .\app.vue --outfile=app-vue.js --watch

function Watch-Command {
    param (
        [string]$Command,
        [int]$IntervalInSeconds = 1
    )

    while ($true) {
        Clear-Host  # Clear the screen for each iteration (optional)
        Write-Output "Running command: $Command"
        Invoke-Expression -Command $Command
        Write-Output "`nPress Ctrl+C to exit`n"
        Start-Sleep -Seconds $IntervalInSeconds
    }
}
Watch-Command -Command ".\esbuild.exe .\app.jsx --outfile=app.js"

Broadcom buy vmware

https://groups.google.com/g/v8-users/search?q=Vyacheslav%20Egorov

rustup update

box2d Deltablue raytrace richards

# 2024-3-16 0 | 0

H.264 NALU

ffmpeg -re -i "playlist.txt" -c copy -f flv "rtmp://127.0.0.1/stream/12345678"

https://gitlab.gnome.org/GNOME/gnome-terminal

https://gitlab.gnome.org/GNOME/nautilus/-/issues

sudo rsync --daemon

rsync 192.168.43.246::tmp/projects/mylinux.iso
rsync 192.168.43.95::tmp/projects/distro -r

sudo vim /etc/rsyncd.conf

rsync -r data tannal@192.168.43.246:/home/tannal/tannalwork/projects/postgres/_install/

tar -czvf archive_name.tar.gz directory1 directory2 directory3

about:config

# 2024-3-15 0 | 0

Attension is All you need Ashish Vaswani - Essential AI Noam Shazeer - Character.AI Niki Parmar - Essential AI Llion Jones - Sakana AI

git clone https://github.com/nsqio/nsq
cd nsq
make

https://twitter.com/ID_AA_Carmack

Light Weight Process

1- Spare Renderer

Chromium tries to put each web site in its own process, as much as possible, for security. (The actual rules for how sites are assigned to processes are complicated, because there are a lot of tradeoffs to make between security and performance.) The "spare renderer" is a process that's kept around ready to load a site into, for faster startup.

4- Plugin Broker: Shockwave Flash [ I disabled flash ]

Chrome 88 has Flash removed entirely so I assume when you upgrade to that, this will go away completely. I'm surprised this was loaded with Flash disabled in older versions, but maybe it's normal to keep the broker loaded but just not doing anything.


补充一下，现在的 HarfBuzz (harfbuzz-ng) 主要是 Behdad Esfabod 独立完成的，有 Jonathan Kew 和 SIL 的一些开发人员的帮助。这个库和最早在 FreeType1 里的 OTF 排版库已经没有什么关系了，当时的这个库抽出来，主要是 Lars Knoll (KHTML 的创始人和 Qt 的主架构师) 和 Simon Hausmann (QtWebKit 的创始人) 合作开发的第一代 HarfBuzz，用在 Qt 和早期的 Chrome 里。(现在 Qt 和 Chrome 也都分别各自实现了基于 harfbuzz-ng 的排版。) 当然现在 FreeType 也开始用到了 harfbuzz-ng，开发者 Werner Lemberg 也对 harfbuzz-ng 有贡献。现在的 XeTeX 也已经可以不依赖 ICU 的排版功能，而单纯使用 harfbuzz-ng 了，这部分工作是 Khaled Hosny 完成的。

Lin Clark emscripten

being paid to work on open source

People like JF Bastien, Luke Wagner, Alon Zakai, Ben Titzer and countless others worked hard to put together the framework of something that would go on to be used by billions of people

If you find your job is making it hard to sleep, making you feel on edge every day, or making you constantly question your own self-worth, I would encourage you to look for a new job.

bussiness heavy

js heavy(npm node bundle xxx engineering) or rendering heavy or UX heaving design heaving

Each tab contains its own rendering context, which is used to display the content of the associated web page

render their user interface, manage windows, and handle user input events

join Algorithms User Defined Functions Network Protocol Query Optimization

https://mattbutrovi.ch/

Remote direct memory access

mysql+gzip mysql monetDB Postgres Oracle MongoDB DB2 Hive

binary encoding protobuffers thrift flatbuffers

compression lz4 gzip zstd oracle mysql snowflake bigquery

columnar specific encoding adbc

mysql postgres redis

JDBC ODBC wrapper java 
ODBC c api


postgres cursor
DBMS Wire Protocol

Direct Access
Open Database Connectivity

Java Database Connectivity
Python PEP-2049
HTTP/REST (dbms specific)

# 2024-3-14 0 | 0

clauses

https://github.com/KillianLucas

机器之心Synced是国内首家系统性关注人工智能的科技
媒体

Module 模式
Config 模式 raylib-config.cmake raylibConfig.cmake

<package>_DIR
CMAKE_PREFIX_PATH
CMAKE_FRAMEWORK_PATH
CMAKE_APPBUNDLE_PATH
PATH

<prefix>/(lib/<arch>|lib|share)/cmake/<name>*/          (U)
<prefix>/(lib/<arch>|lib|share)/<name>*/                (U)
<prefix>/(lib/<arch>|lib|share)/<name>*/(cmake|CMake)/  (U)

<package>Config.cmake或Find<package>.cmake

# 2024-3-13 0 | 0

ls /lib/modules/$(uname -r)/kernel/drivers/usb/serial

WebGPU draws to textures (we happened to get a texture from the canvas)
WebGPU works by encoding commands and then submitting them.

git add  cans/main.c \
	cans/path.bt \
	cans/rm.js \
	cans/test.js \
	cans/texture \
	cans/texture.cc

git clone https://github.com/beaufortfrancois/webgpu-cross-platform-app.git
cd webgpu-cross-platform-app/
git submodule update --init

cmake -B build && cmake --build build -j4

node::WorkerThreadsTaskRunner::WorkerThreadsTaskRunner(int)

for p in ./*; do echo $p; tokei "$p"; done

point-list line-list line-strip triangle-list triangle-strip

createShaderModule one or more shader functions
createRenderPipeline

vertex shader will execute with index 0 1 ...

Bernhard Riemann

https://systems.ethz.ch/education/courses/2024-spring/ComputingPlatforms.html

https://github.com/scylladb/scylladb/blob/3a734facc7476a949ecadf5f98bccb00f8d0c9cb/schema/schema.hh#L49

https://systems.ethz.ch/education/master-and-bachelor-theses.html

cudaMalloc https://github.com/ggerganov/ggml/blob/master/src/ggml-cuda.cu#L8849

threadpool+lock free queue

https://www.youtube.com/gavinzhou

Alphabet investors report https://abc.xyz/investor/

NSF: CAREER award support for exploring heterogeneous memory models

Google: support for memory consistency testing work

DARPA: support for irregular application acceleration (subcontracted from the DECADES project)

data dependency graph

Loop Unrolling and pipeline

threadpool & webserver & key value storage & video audio & game engine

egui glow bind_vertex_array

# 2024-3-12 0 | 0

火山引擎是字节跳动旗下的云服务平台

https://github.com/webmachinelearning
https://github.com/gpuweb

https://www.w3.org/groups/wg/

W3C Verifiable Credentials Working Group

go install github.com/boyter/scc@master
scc
~/go/bin/scc 

https://boyter.org/

```bash

git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
ls
export PATH=/home/tannal/tannalwork/projects/depot_tools:$PATH
git clone https://github.com/dj2/Dusk.git
cd Dusk/
ls
gclient sync --jobs=4
CC=clang CXX=clang++ cmake -GNinja -B build
sudo apt install libxinerama
sudo apt install libxinerama-dev 
tokie
tokei
CC=clang CXX=clang++ cmake -GNinja -B build
sudo apt-get install libxrandr-dev libxinerama-dev libxcursor-dev libx11-xcb-dev libxi-dev mesa-common-dev

```
Xinerama is an X11 extension which provides support for extending a desktop across multiple displays.

w3c webgpu group Apple Google Mozilla intel cocos microsoft

Look ahead by one token

PoC proof of concept

Understand the language of tokens (regular expressions) and parsers
(context-free grammars)

Entry point names are not special, but must match the entryPoint name specified at pipeline creation time.
@vertex @fragment @compute @workgroup_size

adobe apple microsoft google amazon

https://bmcimmunol.biomedcentral.com/?_gl=1*d0g5bg*_up*MQ..&gclid=CjwKCAjw17qvBhBrEiwA1rU9w0d54IHM9ET-raS_C2M7iZv_vPOb8WwLdk-LNBJxNQkLOYPaAsVK4BoCNqIQAvD_BwE

```cpp

auto table_info = bustub->catalog_->CreateTable(nullptr, "maintable", *schema);

auto rid1 = *table_info->table_->InsertTuple(TupleMeta{txn4->GetTransactionTempTs(), false},
                                              Tuple{{Int(1), DoubleNull(), BoolNull()}, schema.get()});

```
table_page 
table_heap memory

acess method intermedia table temp space

interest fact(edge case) -> some theory & rules & princple -> apply & fix loop

S space {s}			{return S;}

CDO comment delimiters open/close

nvidia rapids is a suite of GPU-accelerated data science and AI libraries with APIs that match popular open-source data tools.

Wes McKinney https://wesmckinney.com/ apache arrow python pandas

https://www.isi-education.com/zh-cn/application/download/#longtermapplication

apache arrow python pandas

33680.05 rmb * 2 = 67360.1

报名费(1500)+学费(3w4w)

若您符合条件的话（学士学位），可以在语言学校毕业后，或者，甚至还在读语言学校时也可以找到被录用的公司，申请就职签证。

choice architecture

nature is given to human

jump in a random part figure out what's going on

break into regions

https://research.cs.wisc.edu/adsl/People/

smss unix init

win32k
csrss

api dll runtime dll inject at creation by windows kernel
netdll.dll glibc
kernel32.dll
user32 gdi32
ws2_32 network stack
ole32 object linking and embedding


# 2024-3-11 | 

brcmf
you own your data & language model & query

reboot&inspire
from scratch

use_glib=false 

call gn gen out.gn/x64.release --args="is_debug=false use_glib=false is_component_build=true v8_use_external_startup_data=true v8_static_library=false is_clang = false v8_enable_i18n_support=false target_cpu=\"x64\""

这里显然是不一样的。也就是说ndk的libc++实际上更改了命名空间到__ndk这个前缀上，而v8进行编译时使用的libc++是
https://chromium.googlesource.com/chromium/llvm-project/libcxx
二者的命名空间显然是不同的。但为什么我编译使用的是buildtools/third_party/libc++而非thrid_party/android_ndk/cxx-stl/llvm-libc++？这个我还没有答案

https://users.rust-lang.org/

ATA NVME SATA command Byte Block

tools/dev/v8gen.py x64.release.sample
gn args out.gn/x64.release.sample
ninja -C out.gn/x64.release.sample v8_monolith



cmake -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'


c++filt _ZN2v88platform18NewDefaultPlatformEiNS0_15IdleTaskSupportENS0_21InProcessStackDumpingENSt4__Cr10unique_ptrINS_17TracingControllerENS3_14default_deleteIS5_EEEENS0_12PriorityModeE

JsReciver

behavioral economics digital
export law

transformer
attension

inference
training

kv存储
mp3音乐搜索引擎
jemalloc
spdk dpdk

Desktop Window Manager

Robert Kahn

more CSS features to the Servo layout
floats, writing modes and tables

cat /sys/devices/platform/soc/soc:rpi_rtc/rtc/rtc0/battery_voltage

Exynos SoCs typically integrate various components, including CPUs, GPUs, DSPs (Digital Signal Processors)

graphics buffer manager

# 2024-3-10 | 

https://github.com/luci

zzyiwei

> 1024 * 1024 / ( 2 * 60 * 60 *10)
14.56355555555555622

C lambda proposal https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2892.pdf

sudo systemctl daemon-reload
sudo systemctl enable videos
sudo systemctl restart videos

sudo vim /etc/systemd/system/videos.service
[Unit]
Description = videos

[Service]
Type = simple
WorkingDirectory=/home/tannal/tannalwork/videos/
ExecStart = /bin/bash -c 'PATH=/home/tannal/.nvm/versions/node/v20.11.1/bin/:$PATH http-server .'
Restart=always

[Install]
WantedBy = multi-user.target



sudo cp /usr/lib/clang/16/include/*.h /usr/include/

```bash
nv MESA_SHADER_CACHE_DISABLE=true 
/home/tannal/tannalwork/projects/mesa/build/src/intel/compiler/intel_clc 
--nir --gfx-version=12 --prefix gfx12_intel_shaders --in ../src/intel/shaders/libintel_shaders.h --in ../src/intel/shaders/generate.cl --in ../src/intel/shaders/generate_draws.cl --in ../src/intel/shaders/generate_draws_iris.cl --in ../src/intel/shaders/memcpy.cl --in ../src/intel/shaders/query_copy.cl -o src/intel/shaders/intel_gfx12_shaders_code.h -- -cl-std=cl2.0 -D__OPENCL_VERSION__=200 -DGFX_VERx10=120 -I/home/tannal/tannalwork/projects/mesa/src/intel/shaders/. -I/home/tannal/tannalwork/projects/mesa/src -I/home/tannal/tannalwork/projects/mesa/src/intel -I/home/tannal/tannalwork/projects/mesa/build/src/intel -I/home/tannal/tannalwork/projects/mesa/src/intel/genxml

```

Note that you can use https://packages.ubuntu.com/ to search which package might include a file.


meson compile -C build
sudo apt install libclang-common-15-dev

pip install meson -i https://mirrors.sustech.edu.cn/pypi/web/simple

https://github.com/ValveSoftware


vkQueueSubmit
libvulkan.so
gdb ./build/bin/ssao

vkQueueSubmit

devices


rsync -r out/arm64.debug tannal@192.168.43.246:/home/tannal/tannalwork/projects/

Graphics Memory Controller (GMC)
understanding & familiar

create
improve


x11 xcb_connect () from /lib/x86_64-linux-gnu/libxcb.so

XCB
Wayland
DirectFB
DirectToDisplay

winit call wayland rust
window system integrations

is it alsa or is it pulse ? - Multimedia


https://www.zhihu.com/people/yidui-fei-zhi/posts

https://opendatalab.com/

Reinforcement Learning from Human Feedback

single-process eventdriven (SPED) architecture

Apache HTTP Server:
Microsoft Internet Information Services (IIS)
Netscape Enterprise Server:

asymmetric multi-process eventdriven (AMPED) architecture

# 2024-3-9 | 

Cloud Computing Systems class.
The class covers the design principles behind systems the make up the cloud infrastructure and enable cloud applications.

https://christophermeiklejohn.com/

https://nlp.stanford.edu/teaching/

https://cse.buffalo.edu/~demirbas/

https://charap.co/spring-term-reading-group-papers-131-140/

https://rhaas.blogspot.com/

As part of this project we'll add support for more CSS features to the Servo layout. 
The main areas of work on this project would be support for floats, writing modes and tables; 
which will increase the number of web pages and applications render properly in Servo.

https://www.enterprisedb.com/careers/job-openings

working on Notion CRDT https://news.ycombinator.com/user?id=jitl

Set-Location Env:
rm Python3


[Error - 10:01:13 PM] Request textDocument/codeAction failed.
  Message: Request textDocument/codeAction failed with message: too much recursion
  Code: -32603 

sudo systemctl daemon-reload
sudo systemctl restart y-websocket

HOST=0.0.0.0 PORT=1234 npx y-websocket -y

https://notes.ekzhang.com/events/hsrg

Named Pipes (FIFOs)
UNIX Domain Sockets read and write a same file
Shared Memory
RPC
Message Queues
os/exec Package

https://mirrors.edge.kernel.org/pub/linux/kernel/people/paulmck/perfbook/perfbook.2022.09.25a.pdf

turbopack swc webpack rspack rollup rolldown turbopack esbuild

https://news.ycombinator.com/threads?id=sondr3

https://ceph.io/en/community/team/
https://github.com/idryomov

tannal@raspi:~/tannalwork/cans$ ls /dev/fuse 
/dev/fuse
tannal@raspi:~/tannalwork/cans$ lsmod | grep fuse
fuse                  159744  5
tannal@raspi:~/tannalwork/cans$

https://www.cnblogs.com/pdev/category/1510614.html

watch -d -n 0.5 nvidia-smi

https://github.com/pentium3/sys_reading

g_application_run 
libgio-2.0.so.0


# 2024-3-8 | 

Exec=env QT_QPA_PLATFORM=xcb copyq

rsync -r data tannal@192.168.43.95:/home/tannal/tannalwork/projects/postgres/_install/
rsync -re ~/Desktop/key.txt data tannal@192.168.43.95:/home/tannal/tannalwork/projects/postgres/_install/
rsync -re ~/Desktop/key.txt data tannal@192.168.43.246:/home/tannal/tannalwork/projects/postgres/_install/


export https_proxy=http://10.90.113.228:7890
export http_proxy=http://10.90.113.228:7890

人感知環境70%的資訊量來自腳底，20%來自聽覺，10%來自視覺。
長期處於對外界的觸覺剝奪狀態令人精神渙散、遊離，是我們喜歡做白日夢的決定性因素。赤腳主義者有一項共識，即人人赤腳可以帶來世界和平。科學研究表明，在學校中推行赤腳學生明顯整體更加安靜且和平。說赤腳能帶來人際關係的和平一點都不誇張，它會提供給我們無條件的幸福感。赤腳生活可以令人無條件活在當下。

Thinking is about come up with a idea that probably correct or not.
If it's absolutely correct, then it's useless.

The XOR Largest Pair

rocksdb surrealdb echodb rusqlite

sudo dnf install texlive-latex

nmap -sV -p- -T5 10.90.163.134

inet 10.68.136.133  netmask 255.255.255.128  broadcast 10.68.136.255

nmap -A -T4

nmap -sP 10.68.136.0/24  


# 2024-3-7 | W

10.68.136.130-138

10.68.162.201
ch
Linux4.18

ens9f0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 10.68.136.133  netmask 255.255.255.128  broadcast 10.68.136.255
        inet6 fe80::632:1ff:fe5d:ce6a  prefixlen 64  scopeid 0x20<link>
        ether 04:32:01:5d:ce:6a  txqueuelen 1000  (Ethernet)
        RX packets 26269946  bytes 29307580721 (27.2 GiB)
        RX errors 0  dropped 810865  overruns 0  frame 0
        TX packets 10293932  bytes 813444793 (775.7 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
        device interrupt 18  

ens9f1: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ether 04:32:01:5d:ce:6b  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
        device interrupt 19  

ens9f2: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ether 04:32:01:5d:ce:6c  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
        device interrupt 18  

ens9f3: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ether 04:32:01:5d:ce:6d  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
        device interrupt 19  

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 486753  bytes 52014979 (49.6 MiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 486753  bytes 52014979 (49.6 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

virbr0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        inet 192.168.122.1  netmask 255.255.255.0  broadcast 192.168.122.255
        ether 52:54:00:64:3b:3b  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

sudo apt install texlive

rust proto prost capnp flatbuffer json bson spacejam/sled

libqt5 kwayland dbus

sudo systemctl daemon-reload
sudo systemctl restart pg.service

systemctl status pg.service
sudo journalctl -u pg

sudo vim /etc/systemd/system/pg.service

[Unit]
Description = postgresql

[Service]
User = tannal
Type = simple
WorkingDirectory=/home/tannal/tannalwork/projects/postgres/_install/bin
ExecStart = /bin/bash -c 'PATH=/home/tannal/tannalwork/projects/postgres/_install/bin:$PATH pg_ctl -D data -l logfile start'
ExecReload= /bin/bash -c 'PATH=/home/tannal/tannalwork/projects/postgres/_install/bin:$PATH pg_ctl -D data -l logfile restart'
ExecStop= /bin/bash -c 'PATH=/home/tannal/tannalwork/projects/postgres/_install/bin:$PATH pg_ctl -D data -l logfile stop'
Restart=always

[Install]
WantedBy = multi-user.target

pip install torch==2.0.0
pip install torchvision==0.14


virtualenv --python="/root/tannalwork/cpython/python3.11/bin/python3.11" "venv"

./configure --prefix=`pwd`/python3.11
export PATH=/root/tannalwork/cpython/python3.11/bin:"$PATH"
deactivate
make -j14
make install

pip install numpy with 3.13 shouldn't work. That version is clearly marked for python 3.9, 3.10, 3.11 only.

sudo dnf install clang
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

pip install numpy -i https://mirrors.sustech.edu.cn/pypi/web/simple
pip install meson -i https://mirrors.sustech.edu.cn/pypi/web/simple

git clone https://github.com/mesonbuild/meson.git

```go
package main

import (
	"fmt"
	"log"
	"strconv"

	"github.com/miekg/dns"
)

var records = map[string]string{
	"test.service.": "192.168.0.2",
}

func parseQuery(m *dns.Msg) {
	for _, q := range m.Question {
		switch q.Qtype {
		case dns.TypeA:
			log.Printf("Query for %s\n", q.Name)
			ip := records[q.Name]
			if ip != "" {
				rr, err := dns.NewRR(fmt.Sprintf("%s A %s", q.Name, ip))
				if err == nil {
					m.Answer = append(m.Answer, rr)
				}
			}
		}
	}
}

func handleDnsRequest(w dns.ResponseWriter, r *dns.Msg) {
	m := new(dns.Msg)
	m.SetReply(r)
	m.Compress = false

	switch r.Opcode {
	case dns.OpcodeQuery:
		parseQuery(m)
	}

	w.WriteMsg(m)
}

func main() {
	// attach request handler func
	dns.HandleFunc("service.", handleDnsRequest)

	// start server
	port := 5353
	server := &dns.Server{Addr: ":" + strconv.Itoa(port), Net: "udp"}
	log.Printf("Starting at %d\n", port)
	err := server.ListenAndServe()
	defer server.Shutdown()
	if err != nil {
		log.Fatalf("Failed to start server: %s\n ", err.Error())
	}
}
```

(Red Hat 8.5.0-10)
sudo dnf install libffi-devel

sudo dnf install openssl-devel
git clone https://github.com/python/cpython.git
./configure --prefix=`pwd`/_install
./configure --help


make
make test
make install

export PATH=`pwd`/install/bin:"$PATH"
export PATH=/root/tannalwork/cpython/_install/bin:"$PATH"
export python=`pwd`/install/bin/python3
alias python=`pwd`/install/bin/python3

pip install git+https://github.com/huggingface/transformers.git

python3 -m pip install virtualenv
virtualenv venv python=python3.11

export HF_TOKEN=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

const processInput = (lines) => {
    const [n, m] = lines[0].split(' ').map(Number);
    const strings = lines.slice(1, n + 1);
    const querys = lines.slice(n + 1);

    console.log(solve(strings, querys));
};

const readInputLines = async () => {
    const lines = [];
    for await (const line of rl) {
        lines.push(line);
    }
    return lines;
};

readInputLines().then(lines => {
    processInput(lines);
});

$env:FLASK_DEBUG=1
python -m intermittent_tracker.flask_server


# 2024-3-6 | W


set debuginfod enabled on

sudo systemctl enable yjs.service

Every one says no way until you actually did it.

SSH端口转发（也称为SSH隧道）
ssh -L 3307:localhost:3306 user@example.com

AppleTalk Ftp nfs samba sshftp webdav

Ceph GFS HDFS Swift Lustre

我現在日常使用 AI 的工具選用原則是：
需要寫作，一律使用 Gemini
需要事實，一律選擇 Perplexity 或 Devv
需要程式，一律選擇 GitHub Copilot 或 ChatGPT 的自製 GPTs
需要產圖，一律選擇 DALL-E 或 Microsoft Designer
需要字幕，一律選擇 Whisper (本機) 或 WhisperX
你也有自己愛用的 AI 工具組合嗎？歡迎留言分享交流！

writing code, reading code, reviewing code, debugging, testing, standing around a whiteboard talking code and design, writing design docs, reviewing design docs

How can you expect to make successful changes to a system you don’t understand?

Sticking to your budget requires saying no. You’re a capable person, and a lot of people know that, so lots of folks are going to ask for your help with stuff. Sometimes, you’re going to need to guide them elsewhere. Or just say no outright. That doesn’t feel good, but if you always say yes to stuff that isn’t that important you can’t be surprised when you don’t get important stuff done.

what I need to do to make my teams and projects successful

the way I balance between the short- and long-term, and what I want to get done over time

one-on-one.

You know nothing, how can you think?

Meta Facebook Instagram Messenger Oculus Threads

special meanings


# 2024-3-5 | W

2004 2006 chrome

Procedure Linkage Table

https://walkingcat.github.io/ch9-index/

lars bak & Dart v8 toit

https://www.google.com/about/careers/applications/jobs/results/?q=chrome%20-os%20-sales%20-manager%20-customer%20-relations%20-writer


https://www.zhihu.com/people/jamesaslan/posts

https://mp.weixin.qq.com/s/W4Dc-3ESWB9k6Z7nLsf8ag

东海集团

chrome/edge/firefox/safari/webkit

pulseaudio

pacmd list-cards


v8 Ulan Degenbaev, Alexei Filippov, Michael Lippautz, and Hannes Payer


pipx install gdown
pipx ensurepath
sudo apt install pipx
spdlog

Hiragana (ひらがな):
Katakana (カタカナ):
Kanji (漢字):

泽野弘之(sa wa no Hiroyuki) call of silence

bioconductor https://github.com/Bioconductor
camicroscope https://github.com/camicroscope/caMicroscope
cncf-tracing https://github.com/jaegertracing/jaeger
ersilia-open-source-initiative https://github.com/ersilia-os
fedora https://gitlab.com/fedora
gnome https://gitlab.gnome.org/GNOME
humanitarian-openstreetmap-team https://github.com/hotosm
linux-kernel
llvm
mdanalysis https://github.com/MDAnalysis/mdanalysis
modeci https://github.com/ModECI
moja-global https://github.com/moja-global
ocaml https://github.com/ocaml/ocaml
odk-x https://github.com/odk-x
openstack https://github.com/openstack
oppia https://github.com/oppia/oppia
parsl https://github.com/Parsl/parsl
perl
qemu
servo
systemd
ushahidi https://github.com/ushahidi
wikimedia


# 2024-3-4 | W

git clone https://github.com/rcore-os/rCore.git
git submodule update --init
rustup component add rust-src llvm-tools-preview
git clone https://github.com/rcore-os/rCore.git --recursive
cd rCore/user
make sfsimg PREBUILT=1 ARCH=x86_64
cd ../kernel
make run ARCH=x86_64 LOG=info

sudo apt install debian-goodies
find-dbgsym-packages [core_path|running_pid|binary_path]

sudo apt install lib32stdc++6-12-dbg lib64stdc++6-12-dbg libstdc++6-12-dbg libx32stdc++6-12-dbg libxdmcp6-dbg

sudo apt update && sudo apt install ubuntu-dbgsym-keyring

vulkanExample = new VulkanExample();
vulkanExample->initVulkan();
vulkanExample->setupWindow();
vulkanExample->prepare();
vulkanExample->renderLoop();

https://github.com/SaschaWillems/Vulkan
git clone --recursive https://github.com/SaschaWillems/Vulkan.git
git submodule init
git submodule update
cmake -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'
ln -sfn ./build/compile_commands.json compile_commands.json 


プログラム pur

git clone https://github.com/cinderblock/node-gyp-test.git
npm install
npm run build
npm --silent start

Each platform has it's own webview control available as a shared library installed with the OS.

MacOS has WKWebKit based on WebKit.

Windows has WebView2 based on Edge/Chromium.

Linux has webkit2gtk based on WebKit.

Tools like Tauri use a simple cross-platform single-header abstraction called webview.h[1].

Electron no longer allows Node.js to be called from renderer processes, all communication with Node.js is done via IPC.

In this case, why do we still need Electron? Why does it have to be tied to V8/Node.js?

The fact that Chromium Embedded Framework exists and is third-party makes me think that Chromium wasn't designed for being embedded, and Electron is filling that gap.

This is elucidated here further here https://trac.webkit.org/wiki/WebKit2:

> it's difficult to reuse their work...if another WebKit-based application or another port wanted to do multiprocess based on Chromium WebKit, it would be necessary to reinvent or cut & paste a great deal of code.

It makes me think that perhaps WebKit was the better choice for embedding. The fact that Node used V8 made Chromium the choice, and that Node being called from the renderer was the original way of working. Maybe because WebKit didn't have a build for Windows was an issue too...

But now that we have Bun, perhaps it's time that WebKit becomes that browser target of choice for desktop apps on macOS.

Unless WebView2 for macOS arrives, which would have a more sane cross-platform story. WebView2 has a very large feature-set though which make take a while to implement for macOS.

[1]: https://github.com/webview/webview/blob/master/webview.h

mozilla 1998
2004 

go install github.com/shurcooL/goexec

goexec 'http.ListenAndServe(`:9999`, http.FileServer(http.Dir(`.`)))'

$env:GOOS="js"; $env:GOARCH="wasm"; go build -o main.wasm main.go

go get -u github.com/shurcooL/goexec

cargo add clipboard crossterm

I am pursuing a bachelor's degree in Computer Science and expect to graduate in 2025.

Ever since I was young, I have had a deep interest in programming and tinkering. I started my programming journey by making open-source homebrew apps for the Nintendo 3DS which received 300K+ downloads. 

My experience with the open-source community has helped me immensely in my career. In 2019, I participated and won Google Code-in. In 2023, I participated in Google Summer of Code and worked with an amazing open-source project - ScummVM.

I am now looking forward to working with more large open-source projects so that I can further increase my knowledge and skills.

# 2024-3-3 | W

sudo apt install libasan8-arm64-cross
sudo apt remove libasan8-arm64-cross

/sbin/ldconfig -p | grep stdc++
sudo apt install libstdc++-11-dev-arm64-cross

```shell

# aarch64-linux-gnu.cmake

# Toolchain for cross-compiling to AArch64 Linux from x86_64 Linux

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Specify the cross compilers
set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

# Set the sysroot (adjust the path to your sysroot location)
set(CMAKE_SYSROOT /usr/aarch64-linux-gnu)

# Configure the search paths for libraries and headers
set(CMAKE_FIND_ROOT_PATH /usr/aarch64-linux-gnu/)

# Adjust the default behavior of the FIND_* commands
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

```

../ft/target/debug/ft client 192.168.43.246:7878 build.tar.gz

git clone https://github.com/cmu-db/bustub.git

sudo apt-get install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu

export CC=/usr/bin/aarch64-linux-gnu-gcc
export CXX=/usr/bin/aarch64-linux-gnu-g++

cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=aarch64-linux-gnu.cmake

cmake --build build

tar -cvpzf build.tar.gz build
tar -xvpzf build.tar.gz

nc -l 0.0.0.0 1234 > build.tar.gz
nc 192.168.43.246 1234 < build.tar.gz


make it work
make it correct
make it fast

The traditional way to prove that you’ve achieved code execution is by “popping a calc.” 

Mesa is indeed a prominent open-source graphics library that provides implementations for APIs like OpenGL and Vulkan. However, it's primarily used in Unix-like operating systems such as Linux. Windows does not use Mesa by default; instead, it relies on proprietary drivers from hardware vendors like NVIDIA and AMD, as well as its own set of APIs like Direct3D, which are part of the DirectX suite for handling multimedia tasks, including video and game programming. These vendor-specific drivers are optimized for performance on Windows and provide direct support for the GPU hardware they are designed for.


sudo apt-get install alsa-base alsa-utils

kdenlive
gimp

sudo vim config.txt
usb_max_current_enable=1


https://hn.algolia.com/?dateRange=all&page=3&prefix=true&query=docs.google.com%2Fpresentation%2F&sort=byPopularity&type=story

https://news.ycombinator.com/user?id=paulirish

# 2024-3-2 | W


# 2024-3-1 | W

nc -w 3 192.168.43.246 1234 < patch
nc -l 192.168.43.246 1234 > patch


sudo crontab -l

sudo crontab -e
59 22 * * * /sbin/shutdown -h now


Get-Content input | node vj.js 

sudo fallocate -l 4G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
sudo swapon --show

sudo apt install libgl-dev libglew-dev

cat /proc/sys/vm/swappiness
sudo sysctl vm.swappiness=10
sudo vim /etc/sysctl.conf
vm.swappiness=10


git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
export PATH="$PATH":`pwd`/depot_tools

mkdir skia
cd skia

gclient config --name . https://skia.googlesource.com/skia.git
gclient sync
git checkout master
git checkout reset --hard c05d2859e10f4e1fb0c6486eebfbe88801202648
git apply ../sezion.patch

./gyp_skia
make -j skia_lib BUILDTYPE=Release

cd out/gyp
make -f libjpeg.Makefile BUILDTYPE=Release
cd ../..

There are three tests failed.
1. Wasi testsuite (macos)
Test pwrite-with-append failed (this one also fails on my ubuntu machine)
Test path_link failed

2. CTest on windows server 2022
wasmedgeLLVMCoreTests

Can I access the log files?
https://github.com/WasmEdge/WasmEdge/actions/runs/8066637299/job/22035210543?pr=3246#step:8:74
Cause I only have a ubuntu machine for local testing.
testsuite

iw wlan0 get power_save

iw wlan0 set power_save off

Allgather Allreduce
his arrangement can be used to perform reduction operations in a distributed manner, such as summing values or finding the maximum, where each node contributes its local data to the operation.


# 2024-2-29 | W

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

https://mentorship.lfx.linuxfoundation.org/project/df065cf2-c9d2-453f-8624-7d84654d6352

I am currently a master's student at National Taiwan University, dept. of CSIE. Since I enrolled in the AI program, my graduate paper has to be relevant to Artificial Intelligence. Also, I am interested in the implementation of VM. Therefore, I think WasmEdge might be a great starting point. I am excited about what WasmEdge enables developers to do, particularly on embedded devices. My previous project was focus on system performance, in which I use a Linux kernel infrastructure called eBPF to implement it. By participating in WasmEdge, I might be able to juxtapose the VM design between eBPF and WasmEdge, which could benefit my career path.

- I like writing in C++, following Hacker News and experimenting with tech tutorials.
- 3 years of experience writing in C++ and Python through hobby projects at University, internship experience and contributing to qutip-qip (python), scikit-image (python), ns-3(cpp).

I am very interested in playing around with LLMs!

I am a fourth-grade university student studying at the National Tsing Hua University. I have a double major, one is computer science and another is quantitative finance.
I enrolled in this program goal is to help me improve my technique. Besides that, I want to join an open source project to learn how the modern software development process. I am interested in how to improve CPU performance. This has many attractive topics, and this has many benchmarks to compare. So I think I can through this program learn many things.
I have many Competition Programming experiences like regional ICPC silver and I joined High Performance Computing competition. For the hardware field, I won the top 10 at the 2023 ICCAD contest. Those competitions gave me more understanding of the computer science field.

# 2024-2-28 | W

https://www.mlsys.ai/

https://mlsys.stanford.edu/

main HPC languages. 

How to build a compiler with llvm and MLIR
https://www.youtube.com/playlist?list=PLlONLmJCfHTo9WYfsoQvwjsa5ZB6hjOG5

https://www.sigplan.org/LongTermMentoring/

30/100

https://www.igalia.com/coding-experience/

reddit StackOverflow hackernews youtube twitter

CMake Autotools Meson Bazel

2.19 2.28

https://github.com/congcoi123/tenio

Microsoft's XInput API

MemoryAllocator
June.dll, log.dll, MemoryAllocator.dll, ScriptManager.dll, tcls.dll, tenbase.dll, TenBaseForCross.dll, TenFact.dll, TPFAdapter.dll, TPFCustom.dll, VFS.dll, vfs_config.ini

leveldown - This is typically associated with a low-level database binding for LevelDB, which is a fast key-value storage library written at Google that provides an ordered mapping from string keys to string values.

ig9icd64.dll  Intel Graphics Installable Client Driver

neofetch

nixos

A program is a proof of some theory.

Remote Application Interface Layer 


# 2024-2-27 | W

qbblink

QQ browser blink

https://github.com/tokio-rs

https://blog.trailofbits.com/

https://react.dev/blog/2024/02/15/react-labs-what-we-have-been-working-on-february-2024

libClang
libTooling
Clang Plugins


llvm-reduce
mlir-reduce

llvm bugpoint
Crash debugger
Codegen debugger
Miscompilation debugger

optimizer crashes
miscompilations by optimizers
bad native code generation (including problems in the static and JIT compilers).


c reduce cvise

https://users.cs.utah.edu/~regehr/

Convolutional Layers
Fully-Connected (Dense) Layers
Pooling Layers
Activation Functions
Normalization Layers
Dropout Layers
Output Layer

Classification Retrieval Detection Segmentation Self-Driving Synthesis

Another approach is to use Docker containers, where base images can be shared across projects, and only layers that change (e.g., project-specific dependencies) are duplicated. This can save space when multiple projects share a common base.

As of my last update in April 2023, pip does not natively support a system similar to Yarn PnP, but the Python community continuously evolves, and it's possible that new tools or improvements to existing tools could address this issue in the future. For the latest practices and tools, one would need to check the current state of Python packaging tools and community recommendations.

function linear(matrix, vector) {
}

function relu(matrix) {
}

function linear_relu(input, weights) {
  const linearResult = linear(weights, input);
  return relu(linearResult);
}

Tensor model parallelism
pipeline model parallelism

model parallelism 

scale the training process

parameter getting bigger -> training is expensive

infer is expensive

Partition Training Data into Batches

scale the training process


https://github.com/WasmEdge/WasmEdge/commit/5e8a06e09f9f167fd87ab1777a21f2fdc5fec4ae#diff-5bbd40f71eadf8454723a9d5b392d1df85fce606926b09936d607569b24820c2

https://chameleoncg.com/careers#job_listing

You can make faults, but people can fix it. It's not a big deal.

achievement always comes with risk.

cmake --install build

r --dir=. target/wasm32-wasi/debug/bug.wasm

get_path_filestat

__GI___fstatat64

https://github.com/WebAssembly/wasi-filesystem?tab=readme-ov-file

https://github.com/emilio


# 2024-2-26 1 | W

WasmEdge::Host::WASI::INode::pathCreateDirectory

Executor::execute

Wasmtime, Wasmer, WAMR, and Wasmi

wasmedge --dir=. target/wasm32-wasi/debug/bug.wasm

https://github.com/gabime/spdlog C++ logging lib

export PATH=/home/tannal/tannalwork/projects/WasmEdge/_install/bin/:$PATH


Serde is a framework for serializing and deserializing Rust data structures efficiently and generically. 

wasmedge 2019

https://ferjm.github.io/about/
https://github.com/zhani

The status of HTML5 Forms in servo.

Rust lib Cell

use std::cell::Cell;


HTMLInputElement includes PopoverInvokerElement;

$env:PATH = "C:\Users\tannal\Downloads\LLVM-16.0.6-win64\lib\" + $env:PATH


http://ollehost.dk/blog/

https://github.com/bitshifter

https://github.com/SuperAuguste
https://github.com/rust-lang/rust/commits/master/
https://github.com/paperdave


https://herbsutter.com/

# 2024-2-25 | 

sudo perf record -g ./a.out

sudo perf report


```bash

git clone https://github.com/gperftools/gperftools
cd gperftools
./autogen.sh
./configure
make
sudo make install

```

goal -> approaching -> something goes wrong (else seems good) -> stop

https://cloud.google.com/tpu tpu is a money maker for google cloud

digital archive for research
computational linguistics NLP

model, code

model -> linear algebra ->  output

model -> linear algebra -> output -> loss -> change model parameter one by one by differential * learning rate



.\vcpkg install tcmalloc
.\vcpkg remove --outdated

https://paperswithcode.com/about

A unsolved problem and a solution is a achievement.

Popular problems/field are definitly not hard.
Real hard problems people never think about them.

AI workloads ML Optimized Hardware(training infer)

Image classification standford ImageNet Computer Vision

speech recognization
https://www.openslr.org/12

slido.com

sudo apt-get install google-perftools graphviz

Gperf tools

nagoya 名古屋市

https://codesearch.debian.net/

vector search

https://github.com/asb

get one thing down

Godbolt https://drive.google.com/file/d/119mLhxQryX7uu7ORaQNT_ri1QLhFqkVj/view

LLVM OPT Pipeline Viewer
Link: https://godbolt.org/z/xa7q4GToz

https://www.fsf.org/community/

FSF/GNU

# 2024-2-24 | 

https://www.kxxt.dev/about/

https://spencerwoo.com/about

https://github.com/bcardosolopes

https://boards.greenhouse.io/skydio

https://nikhilism.com/resume


apport-unpack /var/crash/ .
gdb ../a.out CoreDump

sudo apt -y install linux-image-$(uname -r)-dbgsym --allow-unauthenticated

sudo apt install linux-crashdump crash

sudo vim ~/.config/apport/settings

[main]
unpackaged=true

cat /proc/sys/kernel/core_pattern 

https://www.codethink.co.uk/join-us.html

https://blog.reverberate.org/

https://github.com/haberman

https://lucumr.pocoo.org/about/

https://github.com/kevin-lesenechal

sudo chmod -R g+w

https://github.com/kubernetes/kubernetes/issues/96564

If you don't believe it, you can't understand it.

Flap Hero relies on several excellent third-party libraries: Assimp to load 3D models, SoLoud for audio, stb to load textures and fonts, and GLFW for desktop windowing & input.

RCU grace periods

https://github.com/arc80/FlapHero

ps --ppid 2 -p 2 --deselect

https://wpt.live/html/semantics/embedded-content/the-canvas-element/imagedata.html

https://wpt.fyi/results/html/semantics/embedded-content/the-canvas-element/imagedata.html?label=master&label=experimental&aligned&q=imagedata.html

https://blog.perplexity.ai/careers

https://www.centricular.com/contact/

Please Take A Look. PTAL

https://xkcd.com/927/

SMI heap integer

# 2024-2-23 | 

npx create-next-app -e with-supabase todo-base

https://smallcultfollowing.com/babysteps/blog/

style -> layout -> render

SpecialCasing.txt
Abstraction Discipline

Three Hi

senior means old

While work is making money for a bussiness, why should they work for free?

The more innovations happens in a field, the less people who in the field know.

https://jakstys.lt/2023/microsoft-git/



```bash

git clone https://github.com/bytecodealliance/wasmtime.git

git submodule update --init .

cargo build

cargo install --path .

```

# 2024-2-22 | 

https://github.com/servo/servo/commits?author=Loirooriol

chromium test-262 webkit cog Mesa3D LLVM WPT Gecko-dev

linux Webassembly whatwg csswg html skia RISC-V servo Babel

ECMA262 WebRTC [Khronos VK-GL-CTS] MDN Gstreamer Libsoup Epiphany

C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\Tools\Microsoft.VisualStudio.DevShell.dll

$vsPath = "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\"
Import-Module (Join-Path $vsPath "Common7\Tools\Microsoft.VisualStudio.DevShell.dll")
Enter-VsDevShell -VsInstallPath $vsPath -SkipAutomaticLocation -DevCmdArguments "-arch=x64 -host_arch=x64 -winsdk=10.0.17763.0"
LLVM-16.0.6-win64/lib/cmake/llvm/LLVMExports.cmake

C:\Program Files (x86)\Windows Kits\10\Include\10.0.17763.0

set_target_properties(LLVMDebugInfoPDB PROPERTIES
  INTERFACE_LINK_LIBRARIES "C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/DIA SDK/lib/amd64/diaguids.lib;LLVMBinaryFormat;LLVMObject;LLVMSupport;LLVMDebugInfoCodeView;LLVMDebugInfoMSF"
)


```bash

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

```

https://lexi-lambda.github.io/about.html

```bash

$llvm = "LLVM-16.0.6-win64-MultiThreadedDLL.zip"
curl -sLO https://github.com/WasmEdge/llvm-windows/releases/download/llvmorg-16.0.6/LLVM-16.0.6-win64-MultiThreadedDLL.zip -o $llvm
Expand-Archive -Path $llvm

$llvm_dir = "C:\Users\tannal\Downloads\LLVM-16.0.6-win64\lib\cmake\llvm"
# Use clang-cl as the compiler.
# Comment out the following two lines to use MSVC.
$Env:CC = "clang-cl"
$Env:CXX = "clang-cl"

$Env:CC = "clang"
$Env:CXX = "clang"


cmake -Bbuild -GNinja -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreadedDLL "-DLLVM_DIR=$llvm_dir" -DWASMEDGE_BUILD_TESTS=ON -DWASMEDGE_BUILD_PACKAGE="ZIP" .

cmake --build build

```

Documentation is not supposed to change frequently.

If it does, means that your interface change a lot and the API is not stable yet.



https://hackmd.io/@sysprog/ByLJ8DUFT?fbclid=IwAR2ZXqV3Ddv3nSurZcdZINEBv46R-jpZCxa3_cYJa56gCV1j-iNvhLyQSjs

https://twitter.com/jimkxa

https://github.com/cncf/mentoring/tree/main/programs

https://github.com/philip-lamb

https://tigercosmos.xyz/post/2023/11/python/2023pycon-apac-sprint/?fbclid=IwAR2s37xVbg0iZ0StyiQaX_8YdJDryEIIL_NoIdH0hYM91Gp0h0_4PtAcTac

https://github.com/kennykerr

https://kennykerrca.wordpress.com/courses/

https://github.com/microsoft/windows-rs

https://canonical.com/careers/engineering

fractal

chain rule

What you get when you reading.

Math is all about understanding why patterns arise.

odd even odd even

I'm always right even if small wrong.

The sum of the first n odd numbers is n^2
The sum of the first n even numbers is n^2


https://github.com/zed-industries/zed?tab=readme-ov-file

https://doc.rust-lang.org/book/ch10-03-lifetime-syntax.html?highlight=lifetime#lifetime-elision

every reference in Rust has a lifetime

s: Scanner<'s>

The <'s> part is a lifetime specifier. It tells the Rust compiler that instances of Scanner will contain references that are valid for the lifetime 's. This is part of Rust's borrow checker system, which ensures that references do not outlive the data they point to.

machine learning models, simulations, and graphical rendering

Streaming Multiprocessors
registers
L1 cache and shared memory per SM
a large L2 cache of 40MB that is shared across all SMs
80GB of HBM (High Bandwidth Memory)

Ampere A100 GPU

GPU memory high latency and high bandwidth

Nvidia A100 thread 221,184
AMD Rome 7742 24,888
Intel Xeon 8280 12,727

memory latency

GigaFlops Memory Bandwidth compute indensity

computing indensity = flops / data rate

stephen jones nvidia

https://github.com/sts10/

https://github.com/symao/

https://github.com/ROCm/HIP

https://github.com/airbnb

Adobe After Effects

https://git.nju.edu.cn/hengxin/compilers-lectures/-/tree/master/2023?ref_type=heads

projection push down

# 2024-2-21 | 

ggml https://github.com/NVIDIA/TensorRT


https://docs.helix-editor.com/keymap.html#view-mode

http://antirez.com/latest/0

https://github.com/hrvach/deskhop

bootstrap processor & application processor idle wait

https://www.zhihu.com/question/67749141

Intel Management Engine (ME) 32bit cpu 1.7MB DMA NIC

pci bus / pcie bus / memory bus

pch sata usb nic pcie attached ssd


https://eprint.iacr.org/2016/086.pdf

![Alt text](image-19.png)

https://people.csail.mit.edu/devadas/

February 21st until April 3rd

https://gitlab.gnome.org/GNOME
https://www.qemu.org/docs/master/devel/submitting-a-patch.html
https://github.com/systemd/systemd
https://github.com/open-telemetry

https://news.ycombinator.com/item?id=32540883

executing + rendering remote code in a sandboxed window

data data structure proceducre
fastpath slowpath typical case edge case

mmap brk 4kb page
memory allocator
ptmalloc tcmalloc jemalloc
arena malloc_state linked list
malloc_chunk double linked list
bins bitmap of bins
fastbins smallbins unsorted bins largebins unsortedbins top chunk
malloc free

..\..\build\bin\yolov3-tiny -m yolov3-tiny.gguf -i dog.jpg

Invoke-WebRequest -Uri https://pjreddie.com/media/files/yolov3-tiny.weights -OutFile yolov3-tiny.weights
Invoke-WebRequest -Uri https://raw.githubusercontent.com/pjreddie/darknet/master/data/dog.jpg -OutFile dog.jpg

https://cs224d.stanford.edu/syllabus.html

https://www.tesble.com/10.1145/1238844.1238853

https://dsf.berkeley.edu/papers/ERL-M85-95.pdf

https://timilearning.com/posts/mit-6.824/lecture-3-gfs/

Ceph

https://aods.cryingpotato.com/
https://.github.io/Pages/
https://ferd.ca/

Beyond good grades, good GRE scores, and positive recommendation letters, the one thing that can improve a student's chances of admission into our program is a track record of research publication. A publication in a reputable conference really makes an application stand out.

DeepScale Tesla

https://acl.inf.ethz.ch/teaching/
https://acl.inf.ethz.ch/teaching/fastcode/2023/

Machine Learning
Database Software
Computer Graphics and Games

Dense Linear Algebra
Sparse Linear Algebra
Spectral Methods
N-Body Methods
Structured Grids
Unstructured Grids
Monte Carlo

https://www.cs.cornell.edu/~bindel/

https://www.cs.cornell.edu/courses/cs4220/2023sp/schedule.html

https://patterns.eecs.berkeley.edu/

Krste Asanovic
Ras Bodik https://homes.cs.washington.edu/~bodik/index.html
Bryan Christopher Catanzaro
Joseph James Gebis
Parry Husbands
Kurt Keutzer
David A. Patterson
William Lester Plishker
John Shalf
Samuel Webb Williams
Katherine A. Yelick

V = sum of all value people think you (or your work) have

https://ucb-wsc-fa23.github.io/#weekly-schedule

https://slack-chats.kotlinlang.org/?utm_campaign=slack_promo&utm_medium=survey&utm_source=alchemer

https://knoxxs.github.io/assets/garbageCollection2/a_generational_mostly_concurrent_garbage_collector.pdf

https://knoxxs.github.io/chat/architecture/real-time/2015/11/23/chat-architecture-everywhere/

https://hsmemo.github.io/

# 2024-2-20 | 

https://people.eecs.berkeley.edu/~matei/#teaching

When you found a problem, the first thing you do is ask someone.

It's skill and connection issue to know someone who can answer your question.

Hard Work alone doesn't get you what you want.
You have to make something good.


```bash

objdump -d test/plus.run --disassemble=our_code_starts_here

```

Inter-Operator (Vertical)

https://www.twitch.tv/videos/2065150462

https://twitter.com/arighi

# 2024-2-19 | 

JAX/Pytorch

https://github.com/soulteary/tenant-point

language model

model (AI algoirthms)
train & evaluate (dataset loss refine reforcement)
a model file

runtime eat model file then do the magical controlled by the model parameters

salesforce nvidia

model = keras.Sequential
model.summary()
model.compile()
model.fit()
model.evaluate()
model.save()

train keras.datasets.mnist.load_data()
convert



![Alt text](image-16.png)
![Alt text](image-17.png)
![Alt text](image-18.png)

https://www.cs.columbia.edu/~blei/fogm/2023F/readings.html

# 2024-2-18 | 

https://twitter.com/ylecun

sudo apt-get install gcc-arm-none-eabi

获得在留资格认定证明以后，在日本驻外使领馆申请签证时，一般需要以下文件：

护照 签证申请书

证件照(1～2张)(长4.5cm×宽4.5cm)* 也有要求宽3.5cm的日本驻外使领馆
	
在留资格认定证明及复印件

IPA的各类资格https://www.jitec.ipa.go.jp/Lpic

https://www.lpi.org/ja/AWS/GCP/Azure相关，首推AWS其中IPA的资格里除了iパス以外都是国家资格，可以在申请高度人才时获得加分（1个5分，多个10分）有拿永驻身份的需求的话，推荐IPA的资格

https://www.zhihu.com/question/379943332


https://www.youtube.com/watch?v=_enXuIxuNV4&t=25m33s

https://sec-wiki.com/

not by design, you have to hack very hard.

git apply --whitespace=
git apply --whitespace= 
ls
qemu-system-x86_64 -kernel linux/arch/x86_64/boot/bzImage -initrd initramfs.img -append "console=ttyS0 ip=dhcp debug" -nographic -m 1G


You can use $_ or !$ to recall the last argument of the previous 

tar -czvf boa.tar.gz boa

nc -w 3 192.168.43.183 1234 < boa.tar.gz

nc -l 192.168.43.26 1234 | uncompress -c | tar xvfp -
nc -l -p 1234 | uncompress -c | tar xvfp -
nc -l 192.168.43. 1234 > boa.tar.gz

dumpbin /exports /symbols runtime\our_code.lib

https://askubuntu.com/questions/105848/rsync-between-two-computers-on-lan

# 2024-2-17 | 

https://www.cs.cmu.edu/~fp/courses/15411-f14/schedule.html

go test -run TestSearchOnDisk -v

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

https://lmsys.org/about/

https://learning-systems.notion.site/learning-systems/AI-Systems-LLM-Edition-294-162-Fall-2023-661887583bd340fa851e6a8da8e29abb

git clone https://github.com/zeux/niagara.git --recursive

git clone https://github.com/ssloy/tinyrenderer.git

https://www.youtube.com/watch?v=RCbxOZ9qYBw&6m50s



# 2024-2-16 | 

typst

https://developer.valvesoftware.com/wiki/Valve_Hammer_Editor

context for coding
context for thinking

https://www.bilibili.com/video/av89085561?t=121

https://www.youtube.com/watch?v=JLCIzZ1jrx8&t=5m20s

https://www.youtube.com/watch?v=sh6AYvMBERE&&t=32m40s

install debug symbols for bpf user space stack trace

https://askubuntu.com/questions/487222/how-to-install-debug-symbols-for-installed-packages

https://www.gnu-linux.rocks/

https://www.berrange.com/

https://github.com/yifengyou

vcpkg remove zlib

https://github.com/meemknight/

```bash

git clone https://github.com/meemknight/ourCraft.git

```

```bash

git clone https://github.com/zpl-c/enet.git

cmake -B build -DENET_SHARED=1 -DCMAKE_BUILD_TYPE=Release

cmake --build build


vcpkg install enet

# this is heuristically generated, and may not be correct
find_package(unofficial-enet CONFIG REQUIRED)
target_link_libraries(main PRIVATE unofficial::enet::enet)

```

https://salsa.debian.org/kernel-team/

https://twitter.com/paulmckrcu

https://investor.apple.com/investor-relations/default.aspx

15-20 people

Eric Schmidt
Carol Bartz
Bill Joy

https://github.com/vosen/ZLUDA

https://ir.bilibili.com/en/financial-information/#hkex

https://ir.baidu.com/financial-reports/

https://www.tencent.com/en-us/investors/financial-reports.html

https://www.alibabagroup.com/en-US/ir-financial-reports-financial-results

Best user is great than best coder/implementer.

# 2024-2-15 | 

make defconfig

echo "CONFIG_NET_9P=y" >> .config
echo "CONFIG_NET_9P_DEBUG=n" >> .config
echo "CONFIG_9P_FS=y" >> .config
echo "CONFIG_9P_FS_POSIX_ACL=y" >> .config
echo "CONFIG_9P_FS_SECURITY=y" >> .config
echo "CONFIG_NET_9P_VIRTIO=y" >> .config
echo "CONFIG_VIRTIO_PCI=y" >> .config
echo "CONFIG_VIRTIO_BLK=y" >> .config
echo "CONFIG_VIRTIO_BLK_SCSI=y" >> .config
echo "CONFIG_VIRTIO_NET=y" >> .config
echo "CONFIG_VIRTIO_CONSOLE=y" >> .config
echo "CONFIG_HW_RANDOM_VIRTIO=y" >> .config
echo "CONFIG_DRM_VIRTIO_GPU=y" >> .config
echo "CONFIG_VIRTIO_PCI_LEGACY=y" >> .config
echo "CONFIG_VIRTIO_BALLOON=y" >> .config
echo "CONFIG_VIRTIO_INPUT=y" >> .config
echo "CONFIG_CRYPTO_DEV_VIRTIO=y" >> .config
echo "CONFIG_BALLOON_COMPACTION=y" >> .config
echo "CONFIG_PCI=y" >> .config
echo "CONFIG_PCI_HOST_GENERIC=y" >> .config
echo "CONFIG_GDB_SCRIPTS=y" >> .config
echo "CONFIG_DEBUG_INFO=y" >> .config
echo "CONFIG_DEBUG_INFO_REDUCED=n" >> .config
echo "CONFIG_DEBUG_INFO_SPLIT=n" >> .config
echo "CONFIG_DEBUG_FS=y" >> .config
echo "CONFIG_DEBUG_INFO_DWARF4=y" >> .config
echo "CONFIG_DEBUG_INFO_BTF=y" >> .config
echo "CONFIG_FRAME_POINTER=y" >> .config


qemu-system-x86_64 \
    -kernel arch/x86/boot/bzImage \
    -initrd initramfs.img \
    -append "console=ttyS0 root=/dev/ram ip=dhcp" \
    -m 2G \
  -nographic 


sudo apt-get install initramfs-tools-core


sudo apt-get -y install util-linux

https://dslab.epfl.ch/teaching/pocs/

https://fleuret.org/dlc/#lecture-10

https://github.com/0xfe

https://github.com/0xfe/vexflow/issues/520

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/

https://syzkaller.appspot.com./upstream
https://github.com/thaytan/gst-tutorial-lca2018

gcc [0] has a list of maintainers, which features a lot of redhat email addresses. The ruby maintainer is employed by Heroku. CPython is maintained by a RH employee. The linux kernel is mostly comprised of people paid to develop by their employers.

https://www.fermyon.com/

Perfetto

https://fluendo.talentclue.com/en/node/102174096/4590

https://fluendo.com/en/careers/#jobs


https://github.com/lpinca

https://www.youtube.com/watch?v=aKDWWICgfA0

rust apache eclipse mozilla

apache kafka

http://graphics.berkeley.edu/people/jObrien-publications.html

Now you are a cs professor, I give you slides one by one, you expain the point and great idea in it.

ucb cs 169 126 188 162 186 170 182 161 189
cs 169 

cs 186 database systems
cs 162 operating systems
cs 188 intro to AI


https://www.cs.cmu.edu/~zhihaoj2/#teaching

https://courses.cs.washington.edu/courses/cse312/22sp/slides/

src/include/executor/hashjoin.h query execution

Nested Loop Join sort-merge hash join

https://www.citusdata.com/jobs microsoft

https://github.com/apache/arrow

https://github.com/citusdata/citus

# 2024-2-14 | 

cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DENABLE_EXAMPLES=ON '&&' ninja -v

https://github.com/gregjopa

https://github.com/gregjopa/piano-flash-cards.git

https://vexflow.com/

https://archive.org/details/SalamanderGrandPianoV3

codesandbox

https://investor.nvidia.com/financial-info/financial-reports/

https://www.intc.com/financial-info/financial-results

https://investors.arm.com/financials/quarterly-annual-results

# 2024-2-13 | 


start .

https://github.com/julioromano/skeleton-android

interface vs implementation

I still should try weird things courageously.

# 2024-2-12 | 

https://git-scm.com/book/en/v2

Nick hengeveld Git 2005 9.26

git config --global alias.staash 'stash --all'

git config --global alias.bb !better-branch.sh

# 2024-2-10 | 

you need to initialise a window before you can load a texture (OpenGL needs a current context!)

```bash

git clone https://github.com/mit-pdos/xv6-public.git

```

entity components systems

joma youtube tech lear

vcpkg install sdl2:x64-windows

vcpkg list --triplet x64-windows

Those Who Do Not Learn History Are Doomed To Repeat It.

https://salsa.debian.org/public

https://courses.cs.washington.edu/courses/csep551/17wi/week5.pdf

https://oslab.kaist.ac.kr/courseware/

localStorage.clear();

objdump -S kernel > kernel.asm
objdump -t kernel | sed '1,/SYMBOL TABLE/d; s/ .* / /; /^$/d' > kernel.sym
dd if=/dev/zero of=xv6.img count=10000
dd if=bootblock of=xv6.img conv=notrunc
dd if=kernel of=xv6.img seek=1 conv=notrunc

http://www.cs.cmu.edu/~15451-f23/schedule.html

https://danielanderson.net/

https://users.cs.utah.edu/~aburtsev/5460/2023-spring/

https://www.cs.virginia.edu/~evans/

https://uvatoc.github.io/post/page/4/

https://pdos.csail.mit.edu/6.S081/2023/schedule.html

https://css.csail.mit.edu/6.858/2023/

# 2024-2-9 | 




# 2024-2-8 | 


don't repeat yourself.

https://training.linuxfoundation.org/training/a-beginners-guide-to-linux-kernel-development-lfc103/

```bash

sudo apt install nfs-kernel-server
sudo systemctl start nfs-kernel-server.service

sudo vim /etc/exports
/home *(rw,sync,no_subtree_check)

sudo exportfs -a

```

sudo apt install build-essential


# 2024-2-7 | 

# 2024-2-6 | 

process.stdout.write

The great representations that enable people think about these ideas.

explore 

I need it.

programming vs engineering


# 2024-2-5 | 

ttl.sh


```bash

wget https://github.com/second-state/LlamaEdge/releases/download/0.2.14/llama-simple.wasm

```

arp -a

C:\\Users\\tannal/.ssh/known_hosts:1

```bash
cd /

sudo tar -cvpzf backup.tar.gz --exclude=/backup.tar.gz --exclude=/proc --exclude=/tmp --exclude=/mnt --exclude=/dev --exclude=/sys --exclude=/run --exclude=/media --exclude=/var/log --exclude=/var/cache/apt/archives --exclude=/usr/src/linux-headers* --exclude=/home/*/.gvfs --exclude=/home/*/.cache --exclude=/home/*/.local/share/Trash /

sudo tar -xvpzf /path/to/backup.tar.gz -C /media/whatever --numeric-owner

mkdir /proc /sys /mnt /media

```

distributed file system
```bash

export PATH=/home/tannal/go/bin:$PATH

go install github.com/seaweedfs/seaweedfs/weed@latest

weed server -dir=.

weed volume -dir="." -mserver="192.168.43.27:9333" -port=9433

```

https://github.com/seaweedfs/seaweedfs/releases

https://www.cs.rit.edu/~ats/books/ooc.pdf

pointer wizzling



# 2024-2-4 | 

Do the right shit down with a foolish mind.

getconf LEVEL1_DCACHE_LINESIZE

/sys/devices/system/cpu/cpu0/cache/

https://dblp.org/pid/g/GoetzGraefe.html

Because program are limited, if you only need to handle small amount of cases.

Examples that demostrate idea are useful.

/usr/lib/xscreensaver/blitspin

master failure

Go plugin https://pkg.go.dev/plugin

```bash

cd src/main

go run mrworker.go wc.so

go build -buildmode=plugin ../mrapps/wc.go && go run mrmaster.go pg-*.txt


```

tail latency

availability replication

recoverability logging

Don't think unless you are enough familiar with the things you think about.

does the get return the value of the last put?

mapreduce

replication raft libaray

replicated key value storage

shared key value service

x86 gdt

Redhat，SUSE，Cannonical


"js/ts.implicitProjectConfig.checkJs": true

Introduction to Algorithms, A creative approach

Introduction to Algorithms.

http://www.algorithmsilluminated.org/

# 2024-2-3 1+1 | 

Lua Roberto Ierusalimschy
Waldemar Celes
Luiz Henrique de Figueiredo

https://pismin.com/


```bash

https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git

sudo apt-get install build-essential vim git cscope libncurses-dev libssl-dev bison flex

sudo apt-get install git-email

git commit -s -m "KBuild: change kernel version"

scripts/decode_stacktrace.sh ./vmlinux < panic_trace.txt

```
![Alt text](image-15.png)

[PATCH RFC]

git format-patch -1 --pretty=fuller 052f12c6a66685b0b2508e7ecedd6115df4d2573

https://github.com/servo/servo/pull/31108

bits transfer
sudo make modules_install
sudo make install
sudo reboot

# 2024-2-2 1 | 1

git pull

vcpkg update


```bash

git clone https://github.com/ggerganov/whisper.cpp.git


sudo apt update && sudo apt install libsdl2-dev

bash ./models/download-ggml-model.sh base.en

main -m models/ggml-base.en.bin -f samples/jfk.wav


WHISPER_CUBLAS=1 make stream -j 4
stream -m ./models/ggml-base.en.bin -t 8 --step 500 --length 5000

```

![Alt text](./image-12.png)

![Alt text](./image-13.png)

![Alt text](image-14.png)

std::promise

fwrite

fsync flush dirty pages blocking

direct kernel bypass

direct page cache

linux page cache clock lru-k dustbin

if (buf_state & BM_DIRTY) flush out

index auery background

priority hints

https://dbdb.io/stats

multiple pools pre fetch scan sharing buffer pool bypass

per database buffer pool

per page type buffer pool

frame[]

frame (buffer for postgresql) write through cache write back cache write ahead log

FlushBuffer

latch vs lock

page table vs page directory

lock is protect user's concept (logical contents for user, transactions)
latch is used protect interrnal structure in database. (typical mutex)

```c
/*
 * Record structure holding the to be exposed cache data.
 */
typedef struct
{
	uint32		bufferid;
	RelFileNumber relfilenumber;
	Oid			reltablespace;
	Oid			reldatabase;
	ForkNumber	forknum;
	BlockNumber blocknum;
	bool		isvalid;
	bool		isdirty;
	uint16		usagecount;

	/*
	 * An int32 is sufficiently large, as MAX_BACKENDS prevents a buffer from
	 * being pinned by too many backends and each backend will only pin once
	 * because of bufmgr.c's PrivateRefCount infrastructure.
	 */
	int32		pinning_backends;
} BufferCachePagesRec;
```

1. You hacks around to get things works.
2. As time goes on, you find you are doing something wrong.
3. You throw all the crap away and rewrite the shit.
4. goto 2

# 2024-2-1 | 

在gradle.properties 文件中添加如下指令：

android.injected.testOnly=false

sudo apt install coturn

sudo vim /etc/turnserver.conf
turnserver --log-file stdout -p 10088

sudo systemctl daemon-reload


systemctl status coturn
sudo systemctl restart coturn
sudo journalctl -u coturn

sudo openssl req -x509 -newkey rsa:1024 -keyout /etc/turn_server_key.pem -out /etc/turn_server_cert.pem -days 9999 -nodes
sudo openssl req -x509 -newkey rsa:1024 -keyout /etc/turn_key.pem -out /etc/turn_cert.pem -days 9999 -nodes
sudo openssl req -x509 -newkey rsa:1024 -keyout /usr/local/etc/turn_server_pkey.pem -out /usr/local/etc/turn_server_cert.pem -days 9999 -nodes


/usr/local/etc/turn_server_pkey.pem
```bash
listening-ip=10.0.12.15

listening-port=13478

tls-listening-port=15349

relay-ip=10.0.12.15

external-ip=124.223.112.154
realm=haha

lt-cred-mech

no-cli

user=tannal:tannal
```

lsof -i:10088

# 2024-1-31 | 

beat per minute

https://wiki.termux.com/wiki/Installation

https://github.com/termux/termux-app/releases/download/v0.118.0/termux-app_v0.118.0+github-debug_arm64-v8a.apk

http-server storage/shared/DCIM/

pkg upgrade && pkg update

termux-change-repo

pkg install nodejs

npm i -g http-server

http-server

termux-setup-storage

cd storage

前奏 主歌A1 A2 副歌B1 B2 间奏1 主歌A2 副歌 B1 B2 间奏2/桥段 副歌 B1 B2 尾奏

intro verse chorus Interlude verse chorus bridge chorus outro

If you have a constant N, computer still can handle it not matter how big it is.
But if the N is not a constant, it changes over time(or other things), that does sucks. 

When to give up?

1. When you run out of ideas.
2. things just don't work

don't really give up, write down your attempt and most time you will come back to it in the future.

redshift

# 2024-1-30 | 


create table schema catalog

reinterpret_cask<int32_t*> (address)

https://www.andrew.cmu.edu/user/mm6/95-733/iot/The_Computer_For_The_21st_Century.pdf

https://github.com/pdf2htmlEX/pdf2htmlEX

You don't need to explain when no one ask for an explaination.

https://en.wikipedia.org/wiki/Implicit_learning#cite_note-1

How does a CPU communicate with a GPU? https://news.ycombinator.com/item?id=30860259

What I cannot create, I do not understand
What I can create, I also do not understand

Once I can understand, but I can not create it anymore.

NAND2TETRIS
CS61C
Computer Architecture: A Quantitative Approach and Computer Organization and Design: RISC-V edition
Onur Mutlu's lectures


people can create something they don't quite understand it.


$env:ANDROID_HOME="C:\Users\tannal\AppData\Local\Android\Sdk"
[System.Environment]::SetEnvironmentVariable('ANDROID_HOME', 'C:\Users\tannal\AppData\Local\Android\Sdk', [System.EnvironmentVariableTarget]::User)

set ANDROID_HOME=C:\Users\tannal\AppData\Local\Android\Sdk


_install/include/pgtypes_numeric.h

PGTYPESnumeric_add

typedef unsigned char NumericDigit;
typedef struct
{
	int			ndigits;		/* number of digits in digits[] - can be 0! */
	int			weight;			/* weight of first digit */
	int			rscale;			/* result scale */
	int			dscale;			/* display scale */
	int			sign;			/* NUMERIC_POS, NUMERIC_NEG, or NUMERIC_NAN */
	NumericDigit *buf;			/* start of alloc'd space for digits[] */
	NumericDigit *digits;		/* decimal digits */
} numeric;

```bash

set http_proxy=http://192.168.43.1:7890
set https_proxy=http://192.168.43.1:7890

git clone https://github.com/MetaCubeX/ClashMetaForAndroid

git submodule update --init --recursive

gradlew.bat app:assembleMeta-AlphaRelease -Dfile.encoding=GBK

gradlew.bat app:assembleMeta-AlphaRelease --scan -Dfile.encoding=GBK

gradlew.bat app:assembleMeta-AlphaRelease

```


getconf LEVEL1_DCACHE_LINESIZE

LEVEL1_DCACHE_LINESIZE


# 2024-1-29 | 


export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

$env:VERBOSE = "TRUE"
$env:CC = "TRUE"
$env:CXX = "TRUE"

cmake --build build

https://www.cs.cornell.edu/courses/cs6120/2023fa/schedule/

https://lec.inf.ethz.ch/DA/2017/slides/daLecture3.en.handout.4x4.pdf

https://www.cs.cornell.edu/~eva/
https://www.cs.cornell.edu/home/kleinber/

core team (0-20) other roles

text editor code editor IDE
text editor rich text editor design tools figma

multimedia image & video & audio

https://twitter.com/cHHillee

https://github.com/MrDHat

https://www.amazon.com/Real-Time-Collision-Detection-Interactive-Technology/dp/1558607323

Chess players don't base their play on pure problem solving either. They memorize and train specific plays.
The original AI for chess is actually doing problem "solving".

https://github.com/kth-competitive-programming/kactl/tree/main

https://blog.mitrichev.ch/
Egor Kulikov

https://codeforces.com/profile/PavelKunyavskiy

split -l 1000 ggml.c

GELU (Gaussian Error Linear Unit), a popular activation function in neural networks.

https://github.com/pytorch/pytorch/blob/ee3dfbbe470822a50516310384ecce071ec79f7c/test/inductor/test_torchinductor.py#L2439

cloc --exclude-lang=DTD,Lua,make .
cloc --include-lang=Python,C++ .

Tensor library for machine learning

chrome://omnibox/

https://github.com/ggerganov/ggml

./examples/gpt-2/download-ggml-model.sh 117M

./build/bin/gpt-2 -m models/gpt-2-117M/ggml-model.bin -p "This is an example"

```bash

git clone https://github.com/ggerganov/ggml
cmake -S . -B build -G Ninja

ninja -C build

```

https://twitter.com/cHHillee

https://github.com/MrDHat

https://www.amazon.com/Real-Time-Collision-Detection-Interactive-Technology/dp/1558607323

Chess players don't base their play on pure problem solving either. They memorize and train specific plays.
The original AI for chess is actually doing problem "solving".

https://github.com/kth-competitive-programming/kactl/tree/main

https://blog.mitrichev.ch/
Egor Kulikov

https://codeforces.com/profile/PavelKunyavskiy

split -l 1000 ggml.c

GELU (Gaussian Error Linear Unit), a popular activation function in neural networks.

https://github.com/pytorch/pytorch/blob/ee3dfbbe470822a50516310384ecce071ec79f7c/test/inductor/test_torchinductor.py#L2439

cloc --exclude-lang=DTD,Lua,make .
cloc --include-lang=Python,C++ .

Tensor library for machine learning

chrome://omnibox/

https://github.com/ggerganov/ggml

./examples/gpt-2/download-ggml-model.sh 117M

./build/bin/gpt-2 -m models/gpt-2-117M/ggml-model.bin -p "This is an example"

```bash

git clone https://github.com/ggerganov/ggml
cmake -S . -B build -G Ninja

ninja -C build

```

https://twitter.com/cHHillee

https://github.com/MrDHat

https://www.amazon.com/Real-Time-Collision-Detection-Interactive-Technology/dp/1558607323

Chess players don't base their play on pure problem solving either. They memorize and train specific plays.
The original AI for chess is actually doing problem "solving".

https://github.com/kth-competitive-programming/kactl/tree/main

https://blog.mitrichev.ch/
Egor Kulikov

https://codeforces.com/profile/PavelKunyavskiy

split -l 1000 ggml.c

GELU (Gaussian Error Linear Unit), a popular activation function in neural networks.

https://github.com/pytorch/pytorch/blob/ee3dfbbe470822a50516310384ecce071ec79f7c/test/inductor/test_torchinductor.py#L2439

cloc --exclude-lang=DTD,Lua,make .
cloc --include-lang=Python,C++ .

Tensor library for machine learning

chrome://omnibox/

https://github.com/ggerganov/ggml

./examples/gpt-2/download-ggml-model.sh 117M

./build/bin/gpt-2 -m models/gpt-2-117M/ggml-model.bin -p "This is an example"

Set-ExecutionPolicy Unrestricted

even-better-toml

New-Item -ItemType SymbolicLink -Name compile_commands.json -Target .\build\compile_commands.json

mklink /d compile_commands.json .\build\compile_commands.json

sudo vim /etc/systemd/system/docs.service

/proc/28647/environ

game loop
handle user input
change state
draw a frame

We say a tool is successful when a ordinary people can use it without knowing how it works.

std::tuple

std::component

entity components systems composition oriented design

Object Orient Design

combox tab imGui 

pip install gdown

gdown --id

# 2024-1-28 | 

nc -u 127.0.0.1 14000

sudo tcpdump -i any udp port 14000
sudo tcpdump -i any tcp port 10001

https://www.youtube.com/watch?v=G4wpDNa5Bm4&list=PL_xRyXins84_Jf-aCh7chj47HR4oZLPwK

allowPorts = [
  { start = 10000, end = 110000 },
  { start = 27015, end = 27015 }
]

include("C:/Users/tanna/tannalwork/projects/vcpkg/scripts/buildsystems/vcpkg.cmake")

https://www.mingw-w64.org/

https://github.com/skeeto/w64devkit

https://duckdb.org/

winget install --id=mesonbuild.meson  -e

src/include/storage/table/tuple.h

src/include/storage/page/page.h

https://news.ycombinator.com/from?site=glandium.org

https://calendar.perfplanet.com/2023/

RTT from Dong Guan, GuangDong to ShangHai is around 92 80 69 63

RTT from Dong Guan, GuangDong to BeiJing is around 103 71 79 80

RTT from Dong Guan, GuangDong to Washington is around 236 352 280 188

https://hpbn.co/

If you look at the final part of the book “Browser APIs and Protocols” it includes WebSockets and WebRTC. It looks completely up to date. You can handle practically any Web network problem with some combination of XHR, WebSockets and WebRTC.

https://github.com/google-deepmind/alphageometry

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -G Ninja -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_C_COMPILER=/usr/bin/clang

llvm::LLVMContext
llvm::Module
llvm::IRbuilder


Entry Basic Block
Control Flow Blocks


# 2024-1-27 | 

llvm-config 

sudo update-alternatives --list cc

llvm.org/docs/LangRef.html
https://llvm.org/docs/LangRef.html#langref-datalayout


wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh <version number>

sudo apt install nfs-kernel-server
systemctl status nfs-server

/home/tannal/ 192.168.43.246(rw, sync, no_subtree_check)

deb http://apt.llvm.org/bookworm/ llvm-toolchain-bookworm-18 main
deb-src http://apt.llvm.org/bookworm/ llvm-toolchain-bookworm-18 main


CMakePresets.json – project-provided
CMakeUserPresets.json – user-specific

"LLVM_INCLUDE_BENCHMARKS": false,
 "LLVM_INCLUDE_EXAMPLES": false,
 "LLVM_INCLUDE_RUNTIMES": false,
 "LLVM_INCLUDE_TESTS": false,
 "LLVM_ENABLE_PROJECTS": "clang;lld",
 "LLVM_PARALLEL_LINK_JOBS": "1",
 "LLVM_TARGETS_TO_BUILD": "X86"

llvm compilers
plrt v8 jsc toit dart spidermonkey cpython


# 2024-1-26 | 

https://github.com/HMCL-dev/HMCL/releases/download/release-3.5.5/HMCL-3.5.5.jar

serverAddr = "124.223.112.154"
serverPort = 10086

[[proxies]]
name = "test-tcp"
type = "tcp"
localIP = "127.0.0.1"
localPort = 3000
remotePort = 13000


pathname(string) -> dentry

namei pathname -> inode

LL LL(k) LR LR(k) LALR GLR

# 2024-1-25 | 

GNOME Mboalab MDAnalysis OCaml ODK-X Oppia QEMU

typeform

netlify fly.io aws vercel aliyun heroku gcp digital ocean deno deploy microsoft azure

redis mongoDB CockroachDB None Firebase DenoKV PostgreSQL Cassandra sqlite Memcached MySQL

sentry splunk datadog Open Telemetry Zipkin New Relic Logstash Prometheus grafana

Prisma Mongoose Oakdex

Infrastructure As Code Terraform Plulumi Puppet Ansible AWS Cloud Formation Chef

message brokers RabbitMQ SQS Kafka GCP Cloud Tasks other 

identity management Okta OAuth2 JWT Firebase Auth0 Authy 

CDN providers Akamai BunnyCDN Limelight Networks Fastly CDN77 Cloudflare

# 2024-1-24 |

https://github.com/oracle/truffleruby

static data-flow graphs

discriminator generator GAN

binary cross entropy 

nn.Sequential
nn.Linear
nn.LeakyReLU
nn.Sigmod

# 2024-1-23  |

find out/Default -maxdepth 1 -type f -print0 | tar --null --files-from=- -cvf chrome_x86-64_linux_debug_$(date +%Y%m%d-%H%M%S)_$(git rev-parse --short HEAD).tar.gz

find out/Default -maxdepth 1 \( -type f -executable -o -name "*.so" -o -name "*.dll" -o -name "*.dylib" \) -print0 | tar --null --files-from=- -cvf chrome_x86-64_linux_debug_$(date +%Y%m%d-%H%M%S)_$(git rev-parse --short HEAD).tar.gz

make PREFIX=../redis install


sudo apt install tldr

tldr

GIT_LFS_SKIP_SMUDGE=1 git pull
git lfs pull -I chrome_x86-64_linux_debug_20240122-200744_8ce02cc725870.tar.gz


sudo apt install fzf
sudo apt install ripgrep
fzf

super_block
- super_operations

dhcp

sudo apt install ifupdown

ifup eth0
ifocnfig eth0 up

sudo service network-manager restart

/etc/init.d/

inode dentry file super_block vfsmount

block i/o subsystem

net_families
net_proto_family
  - family
  - create
  - module *owner

create state(field, action) destory

sock_alloc_inode

socket
  - state
  - type
  - flags
  - wq
  - file
  - sock(sk)
    - sk_prot (tcp_prot, udp_prot)
  - proto_ops ops

socket_alloc
  - struct socket socket
  - struct inode vfs_inode

ext4_inode on disk
ext4_inode_info in memory vfs_node
inode vfs_inode

struct inode *inode = iget_locked(sb, inode_number);

socketfs inode ext4_alloc_inode keme_cache_alloc ext4_inode_info(ei) vfs_inode

```bash

nc -l 1234

nc 127.0.0.1 1234

ps -ef | grep nc
ll /proc/40846/fd
grep -i "297957" /proc/net/tcp

```

super_block inode inode table

hard link symobic link linux kernel

files_fdtable(task->files)->fd[i]

sudo echo 0 > /proc/sys/kernel/randomize_va_space

sudo apt-get install linux-image-`uname -r`-dbgsym

lay next
refresh

info address mmap_min_addr

p /x mmap_min_addr

memory_

files_fdtable

https://linktr.ee/sagiriizumi

distributed query execution

workers nodes shuffle nodes worker nodes

DAG Tree

https://github.com/postgresml

https://www.vldb.org/pvldb/vol16/p2679-pedreira.pdf

https://www.cidrdb.org/cidr2021/papers/cidr2021_paper17.pdf

ML

LakeHouse systems

gl context

shared disk engines databricks druid object stores cloud data lake

OLAP OLTP monolithic DBMs data cubes

data warehouses FPGA accelarater

know how to ignore things

problem hole idea hole code

ROC Curve
Line Graph
Bar Chart
Box Plot 

Scatter Plot
Heatmap for Classification
Hierarchical Clustering Heatmap
Venn Diagram
Density Plot
Box Plot
Grouped Box Plot

Draw.io / diagrams.net: LaTeX (with TikZ package) Microsoft Visio: Lucidchart: Graphviz Python (with matplotlib or Graphviz library): PlantUML Mermaid.js



# 2024-1-22  |

tobias koppers

git config --global lfs.largefilewarning false

huggingface-cli lfs-enable-largefiles .

curl -x 124.223.112.154:7890 http://google.com

shell lsof -p 3666998

ls -lash /proc/3666998/fd

git pull

git lfs pull https://huggingface.co/tannal/build/blob/main/chrome_x86-64_linux_debug_20240122-200744_8ce02cc725870.tar.gz

git clone https://huggingface.co/tannal/build
git lfs install
git lfs pull

tar zcvf 

pip install huggingface_hub
huggingface-cli login

git lfs install
git add .
git push


tar -cvf mydir-$(date +%Y%m%d-%H%M%S).tar mydir/

tar -cvf mydir-$(git rev-parse --short HEAD).tar mydir/


https://zknill.io/about/

https://news.ycombinator.com/item?id=38289327

toBe toBeCloseTo toBeInstanceOf toBeUndefined toContain toThrow toThrowError

research and insdustry/engineer is two worlds

toEqual shallow equal

npx vitest --run --reporter=verbose
npx vitest --run --reporter=dot
npx vitest --ui

webpack jest

vite vitest

it expect test

happydom jsdom servo-rustdom vitest 

fail runIf skipIf

process.env.NODE_ENV .test .spec

https://google.github.io/comprehensive-rust/memory-management/approaches.html 

v8 pku feature

don't think when you can experiement

Flowchart PieChart Schematic Diagram
c/c++ OpenCV graphviz
golang gonum/plot
rust dot graphviz graphviz

Many great things isn't that hard, it's just nobody even thought about it.

https://github.com/ggerganov

offline no internet

https://github.com/ggerganov/whisper.cpp speech to text

convolutions, activation functions and
tensor transformations

tensor operations

automatic differentiation

algorithms

Numerical Symbolic Automatic

operations such as transposition and
// permutation.

tensor transformations

Reshaping

Transposing

Slicing Concatenation Permutation Element-wise Operations Broadcasting Tensor Product Norm Eigenvalues and Eigenvectors

Diagonalization Rank of a Tensor Tensor Decompositions Batch Processing Gradients and Differential Operators

Tensor Networks

# 2024-1-21  |

cmake --build build --target clean
cmake --build build

CMAKE_BUILD_TYPE=Release
CMAKE_BUILD_TYPE=Debug
CMAKE_BINARY_DIR
set(name value)
option(name explain default)
"Visual Studio 16 2019"

```

// CMakeLists.txt

cmake_minimum_required(VERSION 3.22)

project(
    template
    VERSION 1.0.0
    LANGUAGES C CXX
)
if (WIN32)
    set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set (BUILD_SHARED_LIBS TRUE)
endif ()

add_subdirectory(add)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(COMPILE_EXECUTABLE "hooooooooo" OFF)

set(LIBRARY_NAME add)
set(EXECUTABLE_NAME a.out)


if(COMPILE_EXECUTABLE)
    add_executable(a.out main.cc)
    target_link_libraries(a.out PUBLIC add)
    target_include_directories(add PUBLIC "./add")
endif()


// add/CMakeLists.txt

# add_library(add STATIC add.cc)
add_library(add SHARED add.cc)

```

https://krtirtho.dev/

$Env:PATH = ".\build\add\" + $Env:PATH
.\build\a.out.exe

static single assignment

Hans Wennborg

cmake --build build --target clean
cmake -S . -B build -G Ninja
cmake --build build 

wsl

chocolatey winget

```bash

llvm-as a.ll -o a.bc
llc a.bc -o a.o
clang a.o -o a.out


lli llc 

objdump a.o
history

```

https://github.com/ggerganov/ggml -> https://github.com/ggerganov/llama.cpp/issues/33#issuecomment-1465108022 -> llama.cpp -> 

dl.acm.org/citation.cfm?id=977673
https://llvm.org/pubs/2003-09-30-LifelongOptimizationTR.pdf

```bash
sudo apt install node-gyp

cd local/

../deps/npm/bin/node-gyp-bin/node-gyp configure
../deps/npm/bin/node-gyp-bin/node-gyp configure -- -f compile_commands_json
../deps/npm/bin/node-gyp-bin/node-gyp build


cd ..
ls
./node local/addon.js 
../node addon.js 
history

```

https://github.com/github-copilot/free_signup?utm_medium=editor&utm_source=vscode

OPT llama falcon

https://github.com/ggerganov/llama.cpp/discussions/4534

```bash

bcc
./tools/tplist.py -l /lib/x86_64-linux-gnu/libc.so.6

```

readelf -n /lib/x86_64-linux-gnu/libc.so.6

sudo apt install lttng-tools

https://github.com/namhyung/uftrace/issues/1470

https://about.codecov.io/

.github/workflows/

```diff
diff --git a/common.gypi b/common.gypi
index 28522c9fbf..0c636aad3b 100644
--- a/common.gypi
+++ b/common.gypi
@@ -143,7 +143,7 @@
           ],
         },
         'defines': [ 'DEBUG', '_DEBUG' ],
-        'cflags': [ '-g', '-O0' ],
+        'cflags': [ '-g', '-O0','-pg', '-finstrument-functions' ],
         'conditions': [
           ['OS in "aix os400"', {
             'cflags': [ '-gxcoff' ],
@@ -188,7 +188,7 @@
             }],
           ],
         },
-        'cflags': [ '-O3' ],
+        'cflags': [ '-O3', '-pg', '-finstrument-functions' ],
         'conditions': [
           ['enable_lto=="true"', {
             'cflags': ['<(lto)'],

```


```bash

pip install pre-commit

pre-commit install
pre-commit install-hooks

```

106.7 rmb / hour

15 $ / hour

https://github.com/franneck94

cmake --build build --target install

```bash

sudo apt install uftrace

```

```bash
sudo apt-get install -y kernelshark
sudo apt-get install -y trace-cmd
sudo apt install qtwayland5

sudo perf sched record -a

sudo perf timechart

sudo trace-cmd record -e 'sched_wakeup*' -e sched_switch -e 'sched_migrate*'

git clone https://git.kernel.org/pub/scm/utils/trace-cmd/trace-cmd.git/

kernelshark trace.dat
QT_QPA_PLATFORM=wayland kernelshark trace.dat

```

git submodule external/ deps/ third_party/

fmt spdlog cxxopts catch2

dependency graph cmake projects

https://github.com/y-crdt

![Alt text](./image-11.png)

continuations

https://ci.chromium.org/ui/

consistency

https://flutter.dev/community#community-grid

# 2024-1-20  |

adobe acquired figma

https://extensiblewebmanifesto.org/

https://github.com/y-crdt/ypy/issues/148

mmap vs open

git log --grep="figma"

https://stackoverflow.com/questions/12383900/does-mmap-really-copy-data-to-the-memory

https://boringtechnology.club/

Hopefully with all of the above terms fresh in your memory the FAQ will make a lot more sense to you; I know it did for me. (For example, Wayland relies on EGL because it's the only GL platform interface on Linux that doesn't itself rely on Xlib; because Nvidia's driver targets GLX, it won't work with Wayland.)

Things are not like you doing a test/problem, you neither pass or failed.

Problems would change in the real world.If you do it right in the past, that doesn't mean you would do it right in the same way now.

You always have bugs, and you need constantly changing.

https://www.imperialviolet.org/posts-index.html

https://www.ghacks.net/

https://www.databricks.com/company/careers/open-positions

Azul Systems

[]byte("bar")

Foreground Services workManager Uris Content Providers

std::for_each std::transform

https://github.com/plctlab/v8-internals/blob/master/slides/03-v8-build-system-part2.pdf


Broadcast & Broadcast Recievers

Intent Intent Filters

resources qualifier res

activity application service

tasks(process) backstack standard single top single task single instance

view model per screen mvvm 

context App betwwen Android OS (system & other app)

ls /usr/sbin/ | grep bpfcc

sudo systemctl start frpc
sudo apt install wiringpi
sudo gpio readall


https://drive.google.com/drive/folders/1XoZ3a5ZgC9qmX74Oz8xhavBNzpbYvVnI

nvm use 20.11.0

feedback interaction loop state action state fastest

winget install -e --id CoreyButler.NVMforWindows

```bash

npm i canvas-sketch-cli -g

canvas-sketch-cli sketch.js --new --open

shapes rectangles polygons circles text

```


```js
const canvasSketch = require('canvas-sketch')

const settings = {
  dimensions: [2048, 2048]
}

const sketch = () => {
  return ({context, width, height}) => {
    context.filStyle = 'orange';
    context.fillRect(0, 0, width, height);
  }
};

canvasSketch(sketch, settings);

```

C++AMP OpenMP OpenACC vulkan compute low level submission API

SYCL Khronos Standard OpenMP / OpenCL kernels codeplay

online offline compilation IR finalization

AMD HIP Heterogeneous https://github.com/ROCm/HIP
OpenCL 

AI/ML Tensorflow / pytorch
HPC
Scientific

cuda closed
cuDNN BLAS


# 2024-1-19 1+1 |

https://developer.android.com/reference/kotlin/androidx/compose/material3/package-summary?hl=en#NavigationBar(androidx.compose.ui.Modifier,androidx.compose.ui.graphics.Color,androidx.compose.ui.graphics.Color,androidx.compose.ui.unit.Dp,androidx.compose.foundation.layout.WindowInsets,kotlin.Function1)

Card Text 

alt enter
CTRL+P - show parameters of method when cursor inside parameters;
CTRL+ALT+P - extract parameter from method;
CTRL+ALT+V - select any statement and extract it to variable;
CTRL+SHIFT+J - join lines;
ALT+J - multiline selection;
CTRL+ALT+T - surround with menu (useful for adding try/catch blocks);
CTRL+ALT+SHIFT+T - refactor code menu;
ALT+INSERT - generate code menu (override/implement methods, generate toString()/hash() methods);
CTRL+ALT+L - reformat code according language code convention (i press this shortcut every time code is changed); 
CTRL+ALT+O - delete unused imports;
SHIFT+F6 - rename anything renamable;
CTRL+/ - comment/uncomment line;
CTRL+SHIFT+/ - comment/uncomment selection;
CTRL+W- select statement around cursor or selection and CTRL+SHIFT+W - unselect selection;
and many more you can find.

Activity

nigerian

https://fedoraproject.org/wiki/Test_Day:2024-01-21_Kernel_6.7_Test_Week

usb over ip adb android
sudo ./funcgraph "send_sig" -m 2
sudo ./funccount "*fault**"
sudo ./stackcount  send_sig -P -K

C:\Users\tannal\AppData\Local\Android\Sdk

editor live edit

adb devices
adb tcpip 5555
adb connect 192.168.43.58:5555


adb disconnect 192.168.43.58



sudo stackcount-bpfcc send_sig -K

Tracing 1 functions for "send_sig"... Hit Ctrl-C to end.
^C
  b'send_sig'
  b'__kernel_write_iter'
  b'__kernel_write'
  b'dump_emit'
  b'writenote'
  b'elf_core_dump'
  b'do_coredump'
  b'get_signal'
  b'arch_do_signal_or_restart'
  b'exit_to_user_mode_loop'
  b'exit_to_user_mode_prepare'
  b'irqentry_exit_to_user_mode'
  b'irqentry_exit'
  b'exc_page_fault'
  b'asm_exc_page_fault'
    1

https://www.kernel.org/doc/html/next/core-api/protection-keys.html

```

name: sync-fork
on:
  schedule:
    - cron: '0 0 * * *'
  workflow_dispatch: { }
jobs:
  sync:
    runs-on: ubuntu-latest
    permissions:
      contents: write
    steps:
      - run: gh repo sync $REPOSITORY -b $BRANCH_NAME
        env:
          GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
          REPOSITORY: ${{ github.repository }}
          BRANCH_NAME: ${{ github.ref_name }}

```

gitconfig_orderfile

```

[diff]
	# Detect files renamed as well as copies
	renames = copies
	algorithm = histogram
	# Ordering of files in diffs, for PostgreSQL
	# XXX: If this becomes annoying for other projects, this had better
	# live as a local setting.
	# orderFile = ~/.gitconfig_orderfile

```

amdgpu_get_vblank_counter_kms

sudo ./funccount '*kms*'

framebuffer plane CRTC

wireframe of all your geometry within the scene

give them some texture images you want paint to them

and some shader programs to do cool effects and tell you how to paint them
only do rendering

EGL & WSI bridge

DRM CRTC generate generate a pixel stream for the displays

framebuffers set of pixels

DRM/KMS Object tree

display window system client content (GPU, media, etc)

self reference

Client wayland compositor wayland compositor

OpenGL ES EGL GBM

DRM DRM(KMS)

create_proc_entry

DRM

file vmlinux

arm-linux-addr2line -f -e vmlinux

edu.pl

FOSSASIA

https://students.mimuw.edu.pl/ZSO/index_en.html

6000
https://pdxlinux.org/

Apache Hadoop
Apache Kafka
Apache Cassandra
Apache Spark
Apache HTTP Server
Apache Tomcat
Apache Lucene
Apache Maven
Apache Ant
Apache Airflow

https://hn.algolia.com/

https://eel.is/c++draft/conv#general-1.2

SPIR-V instruction set

https://llvm.org/OpenProjects.html#gsoc24

# 2024-1-18 |


gaming in linux valve proton wine

Case-insensitive filesystems

btrfs indentical fs ids

![Alt text](./image-9.png)

component testing end testing unit testing are framework ignostic

things you heard most and easy found on the internet must be used widely, you need to use it well.

github actions travis circle ci jekins

Testing Library vitest playwright cypress playwright

shopee shopify entropy

https://aosabook.org/en/

https://aosabook.org/en/v1/llvm.html

https://www.composables.com/material3

reward signal

namesilo domain names

sudo apt install libdrm-tests

DRI DRM KMS FB

Direct Rendering Kernel Mode setting driving a display

sudo apt update
sudo apt install ethtool

remotely https://githubnext.com/

CPU(A8040) MAC (PPv2.2) PHY(88X3110) Connector

CPU MAC PHY Connector Unk

macchiatobin.net

RUSTFLAGS="-C force-frame-pointers=yes" cargo build --example thread

sudo perf record --call-graph=fp ./target/debug/examples/thread
sudo perf report

rx/tx of unstructured data, converts the digital data into a signal(e.g. electrical, radio, optical)

data link layer layer two Ethernet

network layer IP

Transport layer reliability, flow control, Qos, ordering, segmentation

intro

programming languages & environment & runtime

datastructures and algorithms

computer networking

operating systems

clay tablets pen and paper ink and parchment 

vinyl audio record film photography

punch cards drum memory magnetic core memory

core rope memory ploppy disks

optical media

magnetic tape storage hard disk drives flash memory

DNA 5D Optical data storage time crystals

docker qemu user static

https://www.autodl.com/home

some software use the old technology (Makefile, autoconf) but long live.

some software use the shiny new rising stars technology but died very quickly.

Learning is that you find something useful but at that time you don't fully understand it. And as time go on, you get more and more confidence why it works.

That's how learning works, not by logical reasoning.

july, sept, nov, jan, march
feature freeze in april
major version in september october

git format-patch -1 -vN

discuss first, never rush writing code. (may be this is why i'm not a extrodinary programmer)

https://commitfest.postgresql.org

security packagers

might love reasearch (not write academic paper) may be blogs/posts/turtorial/video/audio

when you do research, you read and understand, then write it down.

when you do programming, you have a goal and make a program that achieve the goal

might not love programming 

phase locked loop

clock oxygen silicon piezoelectric effect invertor clock

battery crystal oscillator integrated circuit electromagnet gear train

# 2024-1-17 | 1


tokio::main tokio::spawn

triangles (a, b) (c, d) find 

grid squares that are surrounded by at least one of the given rectangles.

timeout 1 node time.js

```js

const rows = 3
const cols = 5

const nestedArray = Array.from(Array(rows), _ => Array(cols).fill(false));
nestedArray[0][1] = true;
console.log(nestedArray)

```

prev next vs current rest

each line is a single test case
lines.forEach(v => solve(...v.split(' ').map(v => +v)))

clk.h https://www.kernel.org/doc/Documentation/clk.txt clk_register

cpu speed eternal bus speed (I2C, SPI, UART)

video pixel frequency

Clock harware software linux

signal width period => frequency

rising edge falling edge period duty cycle jitter

cristal oscillators plls dividers gates muxes clock synchronization

phase comparator loop filter voltage controlled oscillator

enable clock latch gated clock

git reset --hard HEAD~2

lsmtree memtable sorted string table

REPL

go get -u github.com/google/btree
go get -u github.com/chzyer/readline


https://purdue.kattis.com/courses/CS211-CP1/2024-Spring/assignments/us9ksp

git reset HEAD^1

link time optimization graphite optimizations

different binary code format means

different CPU arch ABI different operating system different C libaray

autoconf configure script --build --host --taget

unknown vendor

arm-foo-none-abi arm-unknown-linux-gnuabihf

glibc uclibc musl

binutils gcc linux kernel headers c library

```yml
name: sync-fork
on:
  schedule:
    - cron: '0 0 * * *'
  workflow_dispatch: { }
jobs:
  sync:
    runs-on: ubuntu-latest
    permissions:
      contents: write
    steps:
      - run: gh repo sync $REPOSITORY -b $BRANCH_NAME
        env:
          GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
          REPOSITORY: ${{ github.repository }}
          BRANCH_NAME: ${{ github.ref_name }}
```


import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

git config --global http.sslVerify false
git config --global imap.sslverify false

log_info!(println!("Hello!")); -> println!("Hello!")

cargo run -Z macro-backtrace

cargo add quote chrono syn

#[proc_macro]
pub fn log_info(input: TokenStream) ->TokenStream {
    input
}

dnf package manager

pip freeze | cut -d "@" -f1 | xargs pip uninstall -y

apt snap pacman brew winget vcpkg

cmake -S . -B build
cmake --build build


cmake -S . -B aarch64 -DCMAKE_CXX_FLAGS="-mtune=cortex-a76" -DCMAKE_C_FLAGS="-mtune=cortex-a76"
cmake --build aarch64 --config Release

dnf Fedora 

# 2024-1-16  | 1

https://www.youtube.com/watch?v=ttebJcN5bgQ

winget install --id=Mobatek.MobaXterm  -e
computer just do two things moving bits and flip bits

git clone https://huggingface.co/PowerInfer/ReluLLaMA-7B-Predictor

./build/bin/main -m ./ReluLLaMA-7B-PowerInfer-GGUF/llama-7b-relu.powerinfer.gguf -n 1000 -t 2- -p "we have a super"

./build/bin/main -m ./ReluLLaMA-7B-PowerInfer-GGUF/llama-7b-relu.powerinfer.gguf -n 128 -t 8 -p "Once upon a time" --vram-budget 8

focus on is taking some risk
ask for what you want

how many good people you know?

personal connections self believe

co founder co wowrker

as *mut string
as *const string

unsafe dereference a raw pointer call an unsafe function impl unsafe trait access/modify mutable static variable

macro_rules!

unsafe async procedure macro 

computer has "infinite" bits to flip and move, so it can "fool" people.

learning is like eating

build tokens from characters

don't go back, keep forward.

Byte-Pair Encoding

By recognizing the pattern, you can easily write a program that collects all of the coins with just a few commands.

Review and reflect

Whitespace tokenization

underline blue links

macro_rules! bail {
    ($msg:literal $(,)?) => { ... };
    ($err:expr $(,)?) => { ... };
    ($fmt:expr, $($arg:tt)*) => { ... };
}

# 2024-1-15 1 | 1+1+1

mutex mutual exclusion sleepable preemptable context switch futex
critical section is very short, but context switch can be very expensive.

we need spinlock with

preemption preempt_disable
interrupt interrupt_disable

syscall procfs

uAPI, rseq syscalls

```bash

cmake -S . -B out/release
cmake --build out/release

```

mutexes, spinlocks, semaphores, barriers, rwlock
kernel rcu seqcount per-cpu lockless strucures and algorithms

```bash

pyo3 rust-cpython cffi bin

cargo add libc

pip install maturin

maturin init test

maturin develop

```

https://github.com/golang/go/blob/7abeefd2b1a03932891e581f1f90656ffebebce4/src/cmd/go/internal/modload/import.go#L60

```bash

sudo apt install protobuf-codegen protobuf-compiler

cargo add tonic protobuf

protoc --rust_out=./examples --proto_path=./proto ./proto/hello.proto

```

given something great to you, how you can do the next amazing stuff?

given -> output

post things that you can't find on the internet.

dom 1998 IDL interface define language

https://tc.gts3.org/cs3210/2020/spring/lab.html

https://github.com/DavidBeckham07/litl-Paper-Recurrent/blob/master/LITL%E5%A4%8D%E7%8E%B0%E7%AC%AC%E4%B8%89%E9%A2%98.md

microservices grpc computing nodes shared network grpc trpc protocol buffers

webapplication client code & server code & mysql/postgresql & redis & middleware

docker compose can compose them together in a yaml file and run in one container
but still create separate image for each dockerfile

docker-compose build
docker-compose run

docker image read only template, recreate when change

sudo ls /var/lib/docker

buildkit  containers  engine-id  image  network  overlay2  plugins  runtimes  swarm  tmp  volumes

docker info

Devops github actions or gitlab ci/cd

semantic versioning https://semver.org/

https://css-tricks.com/snippets/css/typewriter-effect/

Engineer tipically don't write docs, If you find some engineers/researchers write about themselves, follow them.

Mdn docs is mainly written by tech writer and advocate (in mozilla). keep this in mind.

guide the people who read your words to a good direction.


# 2024-1-14 | 1+1

smalltalk self strongtalk Java(hotspot engine)

v8 dart

toit

https://news.ycombinator.com/threads?id=mralephp

sudo netstat -tlpen

lsof -i -a -p 11520

sudo netstat --all --program | grep '11520'

postgreSQL in the only database which is not use direct I/O O_DIRECT

blk-mq each cpu can have each i/o queue

Linux kernel's SCSI subsystem,

CFQ deadline noop none PCIe SSds SAN disk arrays

scp -i C:\Users\tanna\Downloads\first.pem compile_commands.json 124.223.112.154@ubuntu:/home/tannal/tannalwork/projects/linux/compile_commands.json

chmod 400 /home/tannal/tannalwork/projects/llvm-project/first.pem

scp -i /home/tannal/tannalwork/projects/llvm-project/first.pem compile_commands.json ubuntu@124.223.112.154:/home/ubuntu/tannalwork/projects/linux/compile_commands.json


scp /home/ubuntu/setup/clash-linux-amd64-v1.14.0 /root/tannalwork/clash-linux-amd64-v1.14.0

ldd --version

sudo snap remove postgres

/home/ubuntu/.config/clash/config.yaml

~/setup/clash/clash-linux-amd64-v1.14.0

https://lrita.github.io/images/posts/filesystem/Linux.Kernel.Write.Procedure.pdf
maximize throughput betwween memory and disks
rotating disk vs ssd

database memory
direct IO / VFS / Page Cache
EXT4
BIO Layer request layer (i/o scheduler)

block device interface
disks

sorts hashing worst-case fsyncs

WAL need fast and safe because we have log for every transaction.

it easy to "fool" people.

short video

find a sweet spot at nenu
back to cn social media
rmeote & open source / typical cn company / cn startup
make sure 1.01 theory
no restriction ways
make it impressive amazing 

# 2024-1-13 1+1+1+1+1+1 | 1+1+1

► Computer architecture	
► Computer networks	
► Computer security	
► Databases	
► Design automation	
► Embedded & real-time systems  	
► High-performance computing	
► Mobile computing	
► Measurement & perf. analysis 	
► Operating systems	
► Programming languages	
► Software engineering

https://marabos.nl/atomics/

android ndk can compile c/c++ for antroid target

https://astexplorer.net/

.td files are processed by TableGen to generate C++ code

https://github.com/llvm/llvm-project/pull/73249/files/79d0d90084ac97b9b94dbc2097ec5af5a3175caa#diff-2deca338e2f37069696eec352bba6457e98cdbe46c767245b92343a7a5fbaf48

lldb is slow than gdb https://stackoverflow.com/questions/59734549/lldb-breakpoints-performance-what-should-i-expect

math judge math things

math things is tiny of the reality (very small subset)

https://web.stanford.edu/class/archive/cs/cs110/cs110.1182/autumn-2017/lectures/

https://web.stanford.edu/class/archive/cs/cs110/cs110.1182/autumn-2017/slides-handouts.html

cat /proc/sys/fs/inotify/max_user_watches

sudo sysctl -w fs.inotify.max_user_watches=131072

sudo swapoff -a

.debug_str 
.debug_line
.debug_abbrev 
.debug_info 
.debug_aranges

pnpm, like npm and Yarn deal with package.json

source code -> scanners -> tokens -> parser may throw errors

Much of front end construction can be auto

x = x + y -> <id, x> = <id, x> + <id, y>

tokens: number, id, +, -, *, /

context free syntax

1. <expr> ::= <expr> <op> <term>
2. | <term>

3. <term> ::= number
4.       |  id
5. <op> ::= +
6.      |-

start symbol expr

terminal number, id, +, -

no-terminal <expr>, <term>

production: 1, 2, 3

AST are often used as IR between frontend(clang) and backend (llvm)

backend -> instruction selection -> register allocation -> machine code may throw errors

translate IR to machine code (eg. ast travesal)

choose instruction for each IR op

decide what to keep in register in each point

![Alt text](image-7.png)

# 2024-1-12 1+1 | 1+1

why people can create new words.

naming things

stable things will remain stable, rapidly chaning things will remain rapdily changes which will blow your mind.
corpus 

Chatbots, predictive text, and virtual assistants all use language models.

N-gram model

ls /include/ -lash

Why AI need "so many data" training, because human has evolved approximately 200,000 years.

And the default prarameter for human is in their DNA.

thoughts on replace the default yjs-demo use contenteditable for local sharing

https://en.wikipedia.org/wiki/Generative_artificial_intelligence

text and images 

https://twitter.com/servodev

All software eventually died or become legacy.

https://www.infinitech-intl.com/en/page/careers

https://next-ai-news.vercel.app/search?q=remote

testing error handling logging 

astro vite rollup -> 

vscode ssh tunning port forwarding


Daniel Bevenius - Principal Software Engineer - Red Hat

highly care about 2024-2027 20-23 (*) and 2027-2030 23-26

This is /run/systemd/resolve/stub-resolv.conf managed by man:systemd-resolved(8).

https://en.wikipedia.org/wiki/Systemd
https://github.com/systemd/systemd
systemd.io


so I can say that systemd has a service for dns lookup

```bash

git switch main
git pull

git switch dev
git stash
git rebase main

```

cloudflare images

# 2024-1-11 0 | 0


nodejs core concepts

blocking non-blocking

Node.js Event Loop, Timers, and process.nextTick()

Don't block the Event Loop(or the Workder Pool)

Timers in Node.js

libuv c++ v8


intel

Application Engineer
SoC Design Engineer
System Validation Engineer
Data Scientist
Software Engineer
Cloud Software Engineer
Graphics Software Engineer
DevOps Software Development Engineer
AI Software Solutions Engineer


nvidia 
Graphics Tools Software Engineer Intern
Software Engineering Intern - Compiler Technology
NVIDIA 2024 Internships: Computer Architecture Intern

https://www.zangcq.com/2017/08/23/nvidia-%E7%94%B5%E8%AF%9D%E9%9D%A2%E8%AF%95%E5%B0%8F%E8%AE%B0%EF%BC%88compute-arch-%E6%96%B9%E5%90%91%EF%BC%89/

telemetry协议

https://aospandaaos.github.io/

deno run -A --unstable server.ts

import { core, internals, primordials } from "ext:core/mod.js";

keep eyes on deno arm

thinking is come up other ways to solve a problem when the previous attempt wasn't work.

1. ask a question / or try it -> No

2. ask another question/ or try another things

then you are thinking between time 1 and time 2.
Actually we don't care what's going on in your brain, we only care about what you did and what you ask and what you say and what you write.

I think this is why people like chatgpt.

Deno[Deno.internal]
keep in mind that docs/classes/books/article/posts is always outdated.

Andy Wingo, Igalia

Ampere Computing By Renee James working on arm based server/workstation

https://amperecomputing.com/careers/apply?p=job/ob7pqfwR&nl=1
https://amperecomputing.com/careers/apply?p=job/oFNIqfwk&nl=1
https://amperecomputing.com/careers/apply?p=job/obDHofwD&nl=1


```
Can you help me go through some of the most used feature about future in rust with a example.

explain the most important things, keep answer as short as posiible, please phrase your sentence well.

```

sudo apt install minicom

minicom -D serial.pts

diassemble /m

0xc1698f80

^x a

pip install requests -U

"TypeError: HTTPConnection.request() got an unexpected keyword argument 'chunked'" error while running AlphaFold

change docker-compose to docker compose

# 2024-1-10 
# 2024-1-11

lots of good information but no claims of any accuracy do your own research

# 2024-1-10 1 | 1

Bazel CMake ninja auto-ninja 

CMake -> ninja
Cmake -> make
Cmake -> bazel

https://risingstars.js.org/2023/en

Windows 10 微软输入法输入时，字母或数字之间间隔较大的问题。

根据您的描述，这可能是输入法全半角设置的缘故导致的，

您可以尝试右击任务栏输入法中英文切换图标，选择”全半角(半角)“，切换当前为”半角“，

```bash

sudo cp /lib/x86_64-linux-gnu/libgcc_s.so.1 lib/

```

```bash

# build gcc

wget https://ftp.tsukuba.wide.ad.jp/software/gcc/releases/gcc-13.2.0/gcc-13.2.0.tar.xz

tar gcc-13.2.0.tar.xz

```

Judea Pearl's home page.

nvidia dlss scaling to 4k 

CUDA/Shading cores run graphics rendering pipeline
ray tracing cores
tensor cores

ray tracing cores

Tensor Cores dlss

This explosion in computing power has let scientists build ANNs that learn to identify people in images, play chess, and even help doctors make medical diagnoses.

still weak AI identify things in 

## reinstalling ubuntu 

```bash

sudo apt install openssh-server git make gcc gettext

sudo systemctl enable ssh

```

send: ok, make sense | 
recv: use tools/import_map.json | IMO, ...|

https://github.com/rust-lang/rust/issues/33159


# 2024-1-9  1+1+1+1+1 | 1+1+1


## x86 registers 

%eax %ebx %esp

%edi %esi

pahole -C task_struct vmlinux
pahole -C nsproxy vmlinux

docker & docker-compose


```bash

sudo apt-get update
sudo apt-get install docker-compose-plugin
sudo apt  install docker-compose

# DOCKER_CONFIG=${DOCKER_CONFIG:-$HOME/.docker}
# mkdir -p $DOCKER_CONFIG/cli-plugins
# curl -SL https://github.com/docker/compose/releases/download/v2.23.3/docker-compose-linux-x86_64 -o $DOCKER_CONFIG/cli-plugins/docker-compose

```

astro storyblok vercel netlify sentry

kdb/kgdb

kernel.org/doc/html/

vscode search @builtin extensions


```bash

# gif
winget install -e --id ShareX.ShareX

```

Andreessen Horowitz, Kleiner Perkins, EQT, Bessemer, BOND and Menlo Ventures investor# 2024-1-8

https://www.usenix.org/system/files/conference/nsdi13/nsdi13-final170_update.pdf


Sanity cms

gif

https://www.vectorlogo.zone/

image layer

gimp ubuntu install

sudo apt install gimp

yjs shared clipboard yjs example done

```bash

git clone https://github.com/yjs/yjs-demos.git
cd yjs-demos/${demo-directory}
pnpm install
pnpm start

```

https://en.wikipedia.org/wiki/Comparison_of_video_editing_software


I only accept less than 50 words answer, so please phrase your sentence well.

https://webkit.org/getting-started/#staying-in-touch

http://loginzlib2vrak5zzpcocc3ouizykn6k5qecgj2tzlnab5wcbqhembyd.onion/

https://en.wikipedia.org/wiki/Comparison_of_image_viewers

parabola

how to c t p l

1T1C Cell 

2**11 * 2**16 * 2**5 4GB

4 * 4 = 16GB
4 * 4 = 16GB

32gb memory

bank row decoder back section address input bank group bank control bank selection column multiplexer 

video editing https://www.remotion.dev/ kdenlive

sudo apt-get install kdenlive kde-runtime frei0r-plugins

sata ssd nvmessd

git clone https://github.com/tsoding/musializer.git

https://github.com/vadimcn/codelldb/wiki/Breakpoints-are-not-getting-hit

"breakpointMode": "file"

# 2024-1-7

curses

full lto vs thinlto

tensorflow is dead, long live pytorch

https://rustacean-station.org/episode/josh-matthews/

F G A B C D E

F G Gb Ab B Cb Db E

https://www.joshmatthews.net/fosdem/#slide-6

kernel/irq/manage.c@request_threaded_irq

codec encoder decoder

```bash

date --universal --iso-8601=s

cd src/pages/posts/

git pull 

cd ../../../

pnpm build

firebase deploy --only hosting

```

godbolt.org

find . -type f -executable

reversible debugger

```bash
sudo apt insall rr

kernel.perf_event_paranoid = 1

sudo vim /etc/sysctl.d/10-rr.conf

sudo sysctl -p /etc/sysctl.d/10-rr.conf

rr record ./a.out
```

debugger is for program/code not software/system

It's hard to use debugger "debug" a system/software.

sudo apt install numactl

```bash

sudo apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r`

sudo apt install linux-tools-common linux-tools-6.5.0-1008-raspi

sudo perf record --call-graph=fp ./a.out -s 50

sudo perf record  --call-graph=fp target/debug/deno info zzazz.comd

sudo perf report

```

Apple purchased NeXT and started the transition of its classic macOS operating system (Apple System 1 though Apple System 9) to Apple Darwin based operating system in 1999
NeXT had created the neXTStep operating system which Apple inherited when they purchased NeXT
NeXT had system apps from FreeBSD and they had implemented the MACH microkernel which was co-created by Avie Trevanian who now was the chief engineer for NeXT, so he brought the MACH microkernel and finished it in NeXTStep
Apple implemented NeXTStep as the foundation for its next generation Apple macOS (originally called Apple Mac OS X)
Over the years Apple upgraded every component in NeXTStep/OS X until it peached Apple macOS Catalina, at which time there was no source code from NeXTStep left at all, it was now all Apple source code
At the same time, Apple evolved the MACH microkernel and created the free open source Apple XNU hybrid kernel
At that point Apple operating systems were completely made of Apple source code
What confuses the internet is that Apple operating systems are modular and one module runs UNIX apps natively (Apple macOS is in fact a certified UNIX), which Apple populates with FreeBSD apps, but which the user can populate with any UNIX apps they choose to use


# 2024-1-6

https://www.codingninjas.com/studio/library/linux-kernel-mentorship-program

sudo snap install go --classic

```bash

sudo update-alternatives --config java

```


1990-2005 Server-rendered HTML /cgi-bin php django ASP.NET pearl
2005-2010 Server html scattered js jquery ajax
2010-2015 Early client rendering backbone.js knockout angular ember
2015-2024 Modern Client rendering (SPA) react vue angular 
2024-future Server + Client Components NEXT.js Nuxt.js Astro svelte blazor

SSR enhanced dev

git log --grep="facebook"

git log --grep="Josh Miller"

git show --stat --name-only

```bash

du -sh target

```

LocalStorage SessionStorage leveldb instead of sqlite https://bugs.chromium.org/p/chromium/issues/detail?id=225934

concurrency is a way to structure the software, once you structure it properly, you can get parallesim for free.

```bash

git clone https://github.com/efficient/cuckoofilter.git

cuckoofilter

```
# 2024-1-5

```bash

git clone https://git.kernel.org/pub/scm/utils/trace-cmd/trace-cmd.git/

sudo apt-get install build-essential git pkg-config -y
    sudo apt-get install libtracefs-dev libtraceevent-dev -y

make; make doc

sudo ./tracecmd/trace-cmd  record  -e syscalls -F ../a.out

./tracecmd/trace-cmd report


```

high performance datacenter networking

user-space stack traces

smart NIC & nic

Multics & memex

https://www.linaro.org/careers/

eXpress Data Path

ebpf datacenter networking smartNIC

xdp load balancer & 4 layer & 7 layer & dns load balancer

Things like understanding the full source code isn't possible for most large projects and people.

But it might be posible for small project

Your job is looking at what you done before, try to figure out what to do next, then do it, NOW.

FPSR (Floating-Point Status Register):
FPCR (Floating-Point Control Register):
TPIDR (Thread Pointer Identifier Register):
TPIDR2 (Thread Pointer Identifier Register 2):

R0-R15

R13 stack pointer
R14 br ret address
R15 program counter

```js

// create a array

const crossedOut = new Array(n + 1).fill(false);

```

diff <(./vjudge.js < input) output

strace -e execve node

node detect is debug in program

context (real time analogy joke) -> computing problem 

CTRL-Z as sending EOF

infra + product

# 2024-1-4

```bash

rustup target list

rustup target add aarch64-unknown-linux-gnu

```

```bash

sudo systemctl enable ssh


```

https://github.com/microsoft/winget-cli/issues/1812

gmail ajax

JCR Licklider Douglas Engelbart

postScript

Python, Scheme, Ruby, LuaJIT, GCC, LLVM, GDB, and Factor

Test262 conformance tests

A example of security bug v is that you can open jishiben in chrome using js

# 2024-1-3

https://en.wikichip.org/wiki/arm_holdings/microarchitectures/cortex-a76

arm raspi5 arm cortext A76

https://github.com/octref
https://github.com/waldyrious

https://github.com/microsoft/vscode-docs

perl/ruby/tcl/erlang/scala/


https://www.netsurf-browser.org/

```bash

git clone git://git.netsurf-browser.org/netsurf.git

wget https://git.netsurf-browser.org/netsurf.git/plain/docs/env.sh
unset HOST
source env.sh

ns-package-install

rm env.sh

cd ~/dev-netsurf/workspace

cd netsurf

https://source.netsurf-browser.org/netsurf.git/plain/docs/quick-start.md

```

https://talentdirectory.mozilla.org/

deno servo node llvm-project raspi chromium webkit app

https://www.outreachy.org/alums/2023-12/

https://www.outreachy.org/docs/applicant/#outreachy-schedule

We understand you may be applying to many jobs. If you receive a job or internship offer, please notify Outreachy organizers immediately.

# 2024-1-2

https://github.com/nodejs/node/pull/50899/files

gitpod

```bash

# vcpkg install raylib

# configuration json
"cmake.configureSettings": {
    "CMAKE_TOOLCHAIN_FILE": "C:/Users/tannal/tannalwork/projects/vcpkg/scripts/buildsystems/vcpkg.cmake",
    "VCPKG_TARGET_TRIPLET": "x64-windows"
},

![Alt text](./image-2.png)

vcpkg cmake

devtContainers

vscode profiles

sudo apt-get install nethogs

sudo nethogs

set(CMAKE_PREFIX_PATH "C:/Users/tannal/tannalwork/projects/vcpkg/installed/x64-windows/share")

clangd indexer sucks not only eating CPU

remote desktop eat too much I/O network bandwidth needs improvement i think

https://github.com/endless-sky

https://endless-sky.github.io/


sudo apt update
sudo apt install gh
gh auth login

git config --global http.sslverify false 
git config --global imap.sslverify false

.\vcpkg\bootstrap-vcpkg.bat
.\bootstrap-vcpkg.bat

.\vcpkg integrate install

vcpkg list raylib
vcpkg search raylib
vcpkg install raylib

https://github.com/Uchiha-Peng/lavender-sailfish-ubuntutouch

git clone https://github.com/microsoft/vcpkg.git

Extended Reality (XR)

Wolvic browser

mi spot is faster than router tplink ax3000 no idea why

solving puzzles is like hide and seek

npm install -g firebase-tools

firebase login

firebase init

https://console.firebase.google.com/project/tannal/settings/general/web:YzU4MmU4MWEtNjIwNS00OTcxLTg2NDEtYjkwNzFkMjc3YTBi

https://pagespeed.web.dev/analysis/https-tannal-web-app-posts-inbox/to312vfwgu?form_factor=mobile

pnpm build && firebase deploy --only hosting

curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash

nvm 

git clone https://www.github.com/tannal/tannal.web.app

sudo tcpdump -w /tmp/memcached.pcap -i any -A -vv 'port 11211'

sudo tcpdump -i any -AX -vv 'port 11211'

netstat -tuln

sudo apt install socat

socat - TCP-LISTEN:2222,crlf

socat - TCP:localhost:2222

sudo tcpdump -i enp5s0 tcp port 11211

sudo tcpdump -Xi enp5s0 port 2222

# 2024-1-1

https://github.com/nodejs/node/blob/5fb630597196cd5f3a8b7febdea3108fb89f067b/src/node.cc#L784

qemu-system-riscv64 -machine virt -bios none -kernel kernel/kernel -m 128M -smp 3 -nographic -drive file=fs.img,if=none,format=raw,id=x0 -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0

sudo apt install qemu-system-misc gcc-aarch64-linux-gnu

https://vis.csail.mit.edu/classes/6.859/

https://www.cs171.org/2023/resources/

https://github.com/jsdom/jsdom/blob/b7683ed68ebe259cd2c68e5faf12d484a785f45f/lib/jsdom/living/helpers/create-element.js#L168

pip install pandas matplotlib -i https://pypi.tuna.tsinghua.edu.cn/simple

nvm list available

nvm install 20.10.0

corepack enable

nvm use 20.10.0

```
# 2023-12-31

sudo apt install solaar
solaar

net user

net Administrator 123456789

按F1键，进入bios，把改Intel VMD Comtroller为disabled

sudo fdisk -l

sudo fdisk /dev/sda

sudo fdisk /dev/sda 
lsblk
sudo umount /dev/sda
lsblk
sudo umount /dev/sda
lsblk
ls /dev/sda 
sudo umount /dev/sda 
sudo mkfs.vfat /dev/sda 
sudo fsck /dev/sda

sudo apt-get -y install m4
sudo apt install mesa-utils
DRI_PRIME=1 glxinfo | grep "OpenGL renderer" 

```bash

https://storage.googleapis.com/flutter_infra_release/releases/stable/windows/flutter_windows_3.16.5-stable.zip

android studio
cmdtools
flutter doctor --android-licenses

```

注意: The Chocolatey CLI MSI is intended for installation only! If upgrading from 5.x of Licensed Extension, or 1.x of other Chocolatey products, see the upgrade guide at https://ch0.co/upv2v6 before continuing. Otherwise, run `choco upgrade chocolatey`.

https://github.com/flutter/flutter/issues/57674

```bash

latex-utilities
latex-workshop

https://datsuka-qwerty.hatenablog.com/entry/latex/windows_install

https://tug.org/texlive/windows.html#install


```

# 2023-12-30

amdgpu-install -y --accept-eula --opencl=rocr --opengl=mesa --vulkan=pro

sudo update-grub2

shutdown -h 0

include/v8.h

servo surfman webrender 

STM32MP1 platform boot

https://github.com/rust-lang/rust/blob/8d76d076665f862ec9619f2de68d6d9ca1db4601/library/core/src/option.rs#L570

2 copy 256kb

```bash

[[example]]
name = "example1"
path = "src/example1.rs"

```



```bash

git clone https://git.yoctoproject.org/poky -b dunfell

git clone -b dunfell \
    git://git.yoctoproject.org/poky.git

git clone -b dunfell \
    git://git.yoctoproject.org/meta-raspberrypi.git

git clone -b dunfell \
    git://git.openembedded.org/meta-openembedded

source poky/oe-init-build-env

```

telnet 127.0.0.1 11211

stats

^] ^D exit telnet

```bash

// TODO tcpdump wireshark 
set lisi 0 0  3    3       #插入一个数据
aaa              #插入的数据为aaa
STORED             #返回“STORED”则表示插入成功
get lisi                  #查询插入的数据
VALUE lisi 0 3          
aaa
END
set lisi 0 0 4          #修改“lisi”这个key的值为bbbb
bbbb
STORED
get lisi          #再次查看，确定更改成功
VALUE lisi 0 4
bbbb

```


```bash

sudo apt-get install build-essential kmod linux-headers-`uname -r`

singer keyboard guitar bass drummer

You need to fight with environment

It sucks, but everyone suffer from it


&self no mut

https://github.com/rust-lang/rust/blob/8d76d076665f862ec9619f2de68d6d9ca1db4601/library/core/src/option.rs#L570

https://llvm.org/OpenProjects.html#gsoc24

https://www.outreachy.org/

https://mentorship.lfx.linuxfoundation.org/#projects_accepting

https://www.igalia.com/coding-experience/

deno

servo

v8 llvm-project node linux

```bash

```

```bash

git clone https://github.com/MarybethGasman/tiktok.git

mvnw

chmod +x mvnw

./mvnw install
./mvnw deploy

```


```bash

git clone https://github.com/redis/redis.git
cd redis/
time make -j20

real	0m38.028s
user	2m28.108s
sys	0m17.239s

git clone https://github.com/memcached/memcached.git

sudo apt-get install autotools-dev automake libevent-dev

After that you can build memcached binary using automake

cd memcached
./autogen.sh
./configure
time make -j20

./memcached

real	0m1.496s
user	0m18.721s
sys	0m1.818s

make test

```

```bash

kubectl get node
E1230 10:07:55.915576   17811 memcache.go:265] couldn't get current server API group list: Get "https://192.168.49.2:8443/api?timeout=32s": context deadline exceeded - error from a previous attempt: EOF
E1230 10:08:27.917669   17811 memcache.go:265] couldn't get current server API group list: Get "https://192.168.49.2:8443/api?timeout=32s": context deadline exceeded - error from a previous attempt: EOF

# k8s

curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"

chmod +x kubectl
mkdir -p ~/.local/bin
mv ./kubectl ~/.local/bin/kubectl

# minikube

curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube

minikube start --driver docker

minikube status

kubectl config view
minikube start

kubectl get node

oc get pods

kubctl get pods

```

```bash
sudo apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r`

```


# 2023-12-29

```bash

virtualenv --version

virtualenv mypython

source mypython/bin/activate

deactivate

pip freeze

```

BuildRoot OpenWrt Yocto

LLVM IR 

instructions

basic block can have a label consists of list of instructions

last is terminator

```llvm

define i32 @foo(i32 %a) {
  entry:
    %sum = add i32 %a, 10
    %cond = icmp eq i32 %sum, 99
    br i1 %cond, label %bb1, label %bb2
  bb1:
    call void @use(i32 %sum, i32 %sum)
    ret i32 %sum
  bb2:
    ret i32 0
}

```

- opcode

%sum = add i32 %a, 10

call void @use(i32 %sum)

web intent

impact > learning

most time in particip

Jamstack Story book React Style guidist React cosmos


# 2023-12-28


```bash

// CMake examples project every single file is a executable

cmake_minimum_required(VERSION 3.0)

project(MyProject)

set(CMAKE_CXX_STANDARD 11)

file(GLOB EXAMPLE_SOURCES "*.cc")

foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
endforeach()

```

# 2023-12-26

do things

rust From trait

library/core/src/convert/mod.rs#L579C1-L585C2

arch/x86/mm/fault.c#L1239
mm/memory-failure.c#L525
arch/x86/include/uapi/asm/signal.h#L4
arch/x86/include/asm/pgtable_types.h#L4
arch/x86/include/asm/pgtable.h
arch/x86/mm/pgprot.c#L5
arch/x86/mm/pgtable.c#L563

# 2023-12-25


https://github.com/postgres/postgres/tree/0a93f803f45f45f39473e2c61923c4b4777bc8a8/src/backend/storage/buffer

# 2023-12-24

![Toit language for IOT](./image-1.png)

# 2023-12-23

Eric Christopher

Johannes Dooerfert

Intro LLVM

llvm-project
llvm-project/clang
llvm-project/llvm
llvm-project/{lld, lldb, ...}

include/ lib/ tests/ utils/

clang AST

LLVM IR

Selection DAG

LLVM MIR

Machine code

clang opt llc llc llc Machine Code 

wabt

sudo make install
vmrss

# 2023-12-21

```bash

sudo vim /etc/default/grub

amdgpu.backlight=0

sudo update-grub

sudo reboot

```

servo docs need improvement

```bash
sudo apt install python3-virtualenv
pip install virtualenv

# sudo apt install libc++-dev libc++abi-dev
# sudo apt install libc++-14-dev libc++abi-14-dev
# sudo ln -s /usr/lib/x86_64-linux-gnu/libstdc++.so.6 /usr/lib/x86_64-linux-gnu/libstdc++.so
# sudo ln -s /usr/bin/c++ /usr/bin/clang++-libc++


sudo apt install libstdc++-12-dev

```

# 2023-12-20

fs/binfmt_elf.c#L843

fs/binfmt_elf.c#L855

# 2023-12-19

# 2023-12-18

Username: pi
Password: raspberry

tar xvJf disk.xz
qemu raspi3b

https://farabimahmud.github.io/emulate-raspberry-pi3-in-qemu/

```bash
sudo apt install snapd
sudo snap install rpi-imager
sudo apt install rpi-imager

```

modern processor (many cores)

pipeline
TLB cache
branch prediction

storage systems (register L1 L2 L3 memory disk)

concurrency & paralleism (pros & cons)

function call?

calling convention

may push stack

jump 

bus transport blocks of words (32bit or 64bit)
cpu register size is a word

ISA vs Micro Architecture

OS/360 Multics Honeywell

An example of getpeername security problem in Freebsd

copy_from_kernel 


# 2023-12-17

micro is a modern and intuitive terminal-based text editor based on golang.

love2d is a 2d game engine

on my debian12, I stuck on build

```bash
run ./platform/unix/automagic

[automagic]  Copying files...
[automagic]  Running genmodules...
[automagic]  Running autoheader...
[automagic]  Running libtoolize...
[automagic]  Running aclocal...
[automagic]  Running autoconf...
configure.ac:38: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:38: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:38: the top level
configure.ac:46: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:46: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:46: the top level
configure.ac:62: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:62: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:62: the top level
configure.ac:63: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:63: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:63: the top level
configure.ac:118: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:118: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:118: the top level
configure:20637: error: possibly undefined macro: AM_PATH_SDL2
      If this token and others are legitimate, please use m4_pattern_allow.
      See the Autoconf documentation.
[automagic]  Failed, sadface.
[automagic]  This is generally a configuration error (I'm looking at you aclocal)

```

# 2023-12-16

https://docs.google.com/document/d/1peUSMsvFGvqD5yKh3GprskLC3KVdAlLGOsK6gFoEOD0/edit?resourcekey=0-bPajpoo9IBZpG__-uCBE6w#heading=h.34a91yqebirw


https://xuanwo.io/reports/2022-21/

# 2023-12-15

# 2023-12-14

tree -L 2 .  

# 2023-12-13

```bash

sudo apt install linux-perf

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

sudo stackcount-bpfcc  t:sched:* -Pdp 71362
```

```bash

tar -cf - test | xz - -9 -e > test.tar.gz

```

# 2023-12-12



## webassembly runtime open source

https://github.com/wasmerio/wasmer

https://github.com/WasmEdge/WasmEdge

https://github.com/wasm3/wasm3/

https://github.com/WebAssembly/wabt

https://github.com/bytecodealliance/wasm-micro-runtime

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


https://www.scattered-thoughts.net/writing/reflections-on-a-decade-of-coding/

# 2023-12-09

https://remotely.routemehome.org/RemoteControl/Viewer?sessionId=889717405

webassembly is new docker

# 2023-12-08


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

# 2023-12-01

## how browser works

- page refresh path / main path / fast path

what happens loading a page?

After main path the system switched to event driven "server" mode

Events typical two forms

- js running render process

- user event trigger

- networking

# 2023-11-29


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
