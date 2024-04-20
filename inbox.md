# 2024-4-19 0 | 0 W


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

assert(
  1 === 2,
  `Code: ; The provided arguments length () does not ` +
    `match the required ones.`,
);

find build -type f -executable
js/bin/

mkdir -p $WORK/mozconfigs/debug/
vim $WORK/mozconfigs/debug/MOZCONFIGs
```
# Build only the JS shell
ac_add_options --enable-project=js

# Enable the debugging tools: Assertions, debug only code etc.
ac_add_options --enable-debug

# Enable optimizations as well so that the test suite runs much faster. If
# you are having trouble using a debugger, you should disable optimization.
ac_add_options --enable-optimize

# Use a dedicated objdir for SpiderMonkey debug builds to avoid
# conflicting with Firefox build with default configuration.
mk_add_options MOZ_OBJDIR=@TOPSRCDIR@/obj-debug-@CONFIG_GUESS@

```
export MOZCONFIG=$WORK/mozconfigs/debug

sudo apt install radeontop

if [ -f ~/tannalwork/.bash_aliases ]; then
    source ~/tannalwork/.bash_aliases
fi

sudo ./stackcount.py -P -p 24469 "bio*" -i 2
sudo ./stackcount.py -P -p 24469 "page*" -i 2

./gitea -c './conf/app.ini' admin regenerate hooks

mv repos gitea-repositories
cp gitea-repositories ../data -r

if [ -f ~/tannalwork/.bash_aliases ]; then
    source ~/tannalwork/.bash_aliases
fi

git clone https://github.com/facebook/rocksdb.git

sudo apt install libgflags-dev

cmake -B build -G Ninja -DBUILD_SHARED_LIBS=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'


:s/\\/\//g

./gitea dump -c /custom/conf/app.ini

export http_proxy=http://192.168.43.1:7890
export https_proxy=http://192.168.43.1:7890

sudo ./stackcount.py -P -p 4370 "bio_submit*"

export GOPRIVATE="git.tanmeng.org"
export GOINSECURE='*.tanmeng.org*'

git checkout --ours db/
git checkout --theirs db/

# 2024-4-17 0 | 0 W

git pull -X theirs origin main

go env -w GOPRIVATE=git.tanmeng.org

$env:GOINSECURE='*.tanmeng.org*'
$env:http_proxy=''

$env:http_proxy='http://192.168.43.1:7890'
$env:https_proxy='http://192.168.43.1:7890'

sudo certbot certonly --webroot -w /var/www/example -d example.com -d www.example.com

sudo certbot certonly --standalone  -d git.tanmeng.org -d www.tanmeng.org -d m.tanmeng.org

sudo certbot certonly --standalone -d *.tanmeng.org

winget install --id=EFF.Certbot  -e

$env:GOPRIVATE="git.tanmeng.org"

echo $env:GOPROXY

# 2024-4-16 0 | 0 W

https://gitlab.freedesktop.org/apinheiro
Alejandro Piñeiro
The guy who give the upstream driver to mesa for Raspberrypi 5
igalian



sudo apt install libdbus-glib-1-dev

gcc try-dbus.c -o try-dbus `pkg-config --libs --cflags dbus-1 glib-2.0 gobject-2.0 dbus-glib-1`
gcc dbus-example.c -o dbus-example `pkg-config --libs --cflags dbus-1 glib-2.0 gobject-2.0 dbus-glib-1`

pkg-config --cflags gobject-2.0
pkg-config --libs gobject-2.0


git clone https://github.com/libbpf/libbpf-bootstrap.git

code owner of the gecko contenteditable
https://github.com/ehsan

involves:ehsan
involves:joyeecheung
involves:emilio
involves:gterzian
involves:jdm

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

https://bootlin.com/doc/training/audio/audio-slides.pdf

https://bootlin.com/doc/training/linux-kernel/linux-kernel-slides.pdf

https://bootlin.com/doc/training/graphics/

GEM Graphics excution/memory manager
DRM KMS

It's often to give up an abstraction when it's leaking too much or too often.

k8s k3s k0s k9s

~/tannaowrk/

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

git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
export PATH="$PATH":`pwd`/depot_tools

mkdir skia
cd skia

gclient config https://skia.googlesource.com/skia.git
gclient sync

python3 tools/git-sync-deps
bin/gn gen out/Shared --args='is_official_build=true is_component_build=true'
bin/gn gen out/Debug
ninja -C out/Debug
ninja -C out/Debug/ -t compdb > compile_commands.json

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

git clone https://github.com/google/leveldb.git
git submodule update --init
cmake -B build -G Ninja -DBUILD_SHARED_LIBS=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'
time cmake --build build


if the code path is right & all the data the code path read/write is right
then the code is right.

if code path is right then the data is wrong
musk a writer to the data
neither interpreter the data wrongly 
or set the data wrongly

if code path is wrong, then it's easy.

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

-device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=hostshare -fsdev local,security_model=passthrough,id=fsdev0,path=sharem/file/d/1vqn33KlxMxE0A-neg8ry28UoQykNvXzZ/view?usp=sharing


Steve Jobs - The Lost Interview

The "equalizing" tools help the average programmer when everything works well, but they make it significantly more difficult for them when problems arise. Today's tools have given us many leaky abstractions.

The software is getting worse to write when it becomes easy for customers to use

document.addEventListener('keydown', (e) => {
  if(e.key === 'j') {
    document.querySelector('.List-item').parentElement.removeChild(document.querySelector('.List-item'))
  }
})


A = new statement
if decide(A) 

given a true statement A
for all belifs
  if A is not a subset of the belif:
    add A the the belif

decision algorithm
statement A
if A is a subset of the belif:
  return true
for All belifs
  if A is inconsisitent of belif:
    return false
  
  if A is inconsistent of the superset of the belif:
    return false

return undecidable

true

I originally moved to the US to work on developer tools at Microsoft, 
where I worked on Visual Studio Code and browser DevTools.


gdb -ex "target remote <IP address>:9953" -p <pid>


# 2024-4-11 0 | 0 W

git pull -X theirs origin main
let document = self.documents.borrow().find_document(id);

Flutter Team
https://github.com/search?q=involves%3Ahixie&type=issues
https://github.com/search?q=involves%3Agrouma&type=issues
https://github.com/search?q=involves%3Avsmenon&type=issues


git clone https://github.com/karpathy/llm.c

watch -n 0.1 nvidia-smi
export http_proxy=http://10.90.155.96:7890
export https_proxy=http://10.90.155.96:7890

python train_gpt2.py
make train_gpt2
make train_gpt2cu

OMP_NUM_THREADS=8 ./train_gpt2

./aliyunpan

false search
truth search

find the error

3D graphics also involve more than just the graphics API, OS graphics subsystem, and hardware driver. It typically includes modeling, rendering, shading, lighting, and other processes involved in creating three-dimensional graphics. These additional components are essential for rendering complex 3D scenes and objects accurately.

 modeling is typically replaced by the creation of shapes, lines, and text using vector graphics or pixel-based drawing.

Rendering in 2D often involves compositing these shapes and elements onto a 2D surface, such as a computer screen.


KDAB
https://floss.social/@servo

Where do you see Servo going in a year, or two, or five?
A robust embedded webview, a thriving gateway for the next generation of browser devs, the foundation of Rust’s web platform story?

QT kdab
https://blog.mggross.com/
https://github.com/ahayzen

# 2024-4-10 0 | 0 W

sudo stackcount-bpfcc -p 7375 -i 2 --debug "*update_process_times*"
sudo stackcount-bpfcc -p 7375 -i 2 --debug "*tick_sched_handle*"


Let the Acutally User write the docs, not the implementer.
User need to comunicate with implementers, get the right conclusion then write the docs.


control character
content character


inferences can lead to emotions

no theoris tell us the whole truth

It's about the content, not the process.

The more models we hold in mind.
The worse performance becomes.

https://codepen.io/hrtzt/pens/public

consulting


d 05.mp4 /hoem/tannal/tannalwork/videos/

echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope


rb query

BEGIN;
=> DELETE FROM t;
=> SELECT pg_current_xact_id();

./psql -h 192.168.43.246 -p 5432 -U tannal -d exchange

GIT_LFS_SKIP_SMUDGE=1 git pull origin main
git lfs pull



involves:pcwalton

involves:emilio
involves:gterzian

https://ebpf.foundation/funding-opportunities/?fbclid=IwAR1NkUiOCVoxxW3rvWw2ah4avnUlsS3TUCnz19vhpTBVz8I1pNsYbZ0jvCo_aem_AU4fAUcaJ5AdX9QwAcfDf70c_DU6osGjz2uq8B3k9mju2K_bxaVrn4iF4K-lQE1Le3ttDgHTtBn5Vh0CKaC4cwxX

context_switch

sudo stackcount-bpfcc -p 6970 -i 2 --debug "*switch*"
sudo stackcount-bpfcc -p 6970 -i 2 --debug "*timer_interrupt*"


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

```bash

https://github.com/google/leveldb.git

mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && time cmake --build .

real    0m44.458s
user    0m40.343s
sys     0m4.054s

```


the mental model remember what is true
not what is false

scrolling is harmful for reading
var allowScrolling = true
window.addEventListener('keydown', function(e) {
  // If user scrolls, disable automatic scrolling temporarily
  if(e.key === 'j') {
      allowScrolling = !allowScrolling;
  }
});

setInterval(() => {
  scrollToRandomPercentage()
}, 1000 * 4)

function scrollToRandomPercentage() {
  if(allowScrolling) {
    // Generate a random percentage between 0 and 1
    var randomPercentage = Math.random();

    // Get the total height of the document
    var totalHeight = document.body.scrollHeight - window.innerHeight;

    // Calculate the position to scroll to
    var scrollTo = randomPercentage * totalHeight;

    // Scroll to the calculated position
    window.scrollTo({
      top: scrollTo,
      behavior: 'instant' // Smooth scrolling
    });
  }
}

Philip N. Johnson-Laird

https://www.pnas.org/

simple mind is useful in the current science and math

We only feel bad about two things
do the wrong thing and get stuck

why some of articles can be read through by i?
and some of articles can't be read through



boot into main
boot into shell
boot into launcher window system

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

docker login git.tanmeng.org

RUN echo 'nameserver 192.168.43.62' >> /etc/resolv.conf

docker image rm

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


docker build . -f Dockerfile_ubuntu_apt -t llvm-tutor-ubuntu-apt

window.addEventListener('keydown', function(e) {
  // If user scrolls, disable automatic scrolling temporarily
  if(e.key === 'j') {
    scrollToRandomPercentage()
  }
});

function scrollToRandomPercentage() {
    // Generate a random percentage between 0 and 1
    var randomPercentage = Math.random();

    // Get the total height of the document
    var totalHeight = document.body.scrollHeight - window.innerHeight;

    // Calculate the position to scroll to
    var scrollTo = randomPercentage * totalHeight;

    // Scroll to the calculated position
    window.scrollTo({
      top: scrollTo,
      behavior: 'smooth' // Smooth scrolling
    });
}

how problems relate to each other?

コンパイラ
コミット

explain the most important three words to understand these


explain these word by word in en

more than what you see?
special to general
less -> more
more -> less

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

window.addEventListener('scroll', function() {
  // If user scrolls, disable automatic scrolling temporarily
  allowScrolling = false;

  // Reset the automatic scrolling after 3 seconds
  setTimeout(function() {
    allowScrolling = true;
  }, 1000 * 10); // 1000 * 10 milliseconds = 3 seconds
});

// Event listener to detect user scrolling
window.addEventListener('mousemove', function() {
  // If user scrolls, disable automatic scrolling temporarily
  allowScrolling = false;

  // Reset the automatic scrolling after 3 seconds
  setTimeout(function() {
    allowScrolling = true;
  }, 1000 * 10); // 1000 * 10 milliseconds = 3 seconds
});

var allowScrolling = true; // Flag to control automatic scrolling

function scrollToRandomPercentage() {
  if (allowScrolling) {
    // Generate a random percentage between 0 and 1
    var randomPercentage = Math.random();

    // Get the total height of the document
    var totalHeight = document.body.scrollHeight - window.innerHeight;

    // Calculate the position to scroll to
    var scrollTo = randomPercentage * totalHeight;

    // Scroll to the calculated position
    window.scrollTo({
      top: scrollTo,
      behavior: 'smooth' // Smooth scrolling
    });
  }
}

setInterval(() => {
  scrollToRandomPercentage()
}, 1000 * 10)

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

cargo run

if you lean to use something which means you thins something is right.
if you learn something which means you think there is a problem.


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
involve:dnovillo


Good artists copy, great artists steal.

102nd TC39 meeting (June 11-13, 2024)
Future Frontend 2024 (June 13-14, 2024)
PLDI 2024 (June 24-28, 2024)
JSConf Budapest (June 27-28, 2024)

# 2024-4-4 0 | 0 W

sudo vim /run/systemd/resolve/resolv.conf

https://www.zhihu.com/question/481137524

399 2023 3 26 13:58

git config --add remote.origin.proxy ""
unset http_proxy

git init
git checkout -b main
git add .
git commit -m "first commit"
git remote add origin http://git.tanmeng.org/tannal/bitcask-kv-go.git
git push -u origin main

# 2024-4-3 0 | 0 W

export http_proxy=http://10.90.195.133:7890
export https_proxy=http://10.90.195.133:7890

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

Mozilla Gfx Team
involves:nical
involves:pcwalton webrender

fuchia graphics team
involves:raphlinus


# 2024-4-2 0 | 0 W

https://en.opensuse.org/openSUSE:Members

https://github.com/HollowMan6

involves:iant golang team

detach and attach


https://bugzilla.mozilla.org/show_bug.cgi?id=1868293

git init
git checkout -b main
git add README.md
git commit -m "first commit"
git remote add origin http://192.168.43.62:3000/tannal/cssparser-examples.git
git remote add origin http://192.168.43.62:3000/tannal/rust-workspace.git
git push -u origin main

igalian involves:ferjm


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

export https_proxy=http://10.90.179.123:7890
export http_proxy=http://10.90.179.123:7890

involves:tolmasky owner:tc39


rocallahan

https://wicg.io/

involves:lukewarlow 

whatwg chat room
https://app.element.io/#/room/#whatwg:matrix.org


# 2024-3-31 0 | 0 W



ps -eo pcpu,pid,user,args | tail -n +2 | sort -k1 -r -n | head -10


involves:basicthinker

postgresql
involves:petere
involves:bmomjian
involves:anarazel
involves:mhagander


involves:scvalex


rust
involves:yoshuawuyts

cpython
involves:barneygale
involves:serhiy-storchaka

500 cycles
speed up syscall bypass syscalls



https://github.com/search?q=involves%3Asaschanaz&type=issues

psql -h 192.168.43.246 -p 5432 -U tannal -d postgres 

involves:eholk

involves:steveklabnik
involves:nicoburns

xv6-public
involves:kaashoek
involves:phf
involves:aclements
involves:zeldovich
involves:aliceinwire
involves:tchajed
involves:Icenowy


int iret syscall sysret sysenter page fault(mov) hardware exception

involves:giuliobenetti
involves:tkso1997

https://wiki.linuxfoundation.org/gsoc/2024-gsoc-perf

make sense flush 
make sense flush

code run/debug/log tell you the idea
change the code to program slightly different idea

DOM + CSS CSS Animation & Javascript Animation

Canvas svg

WebGL Webgpu shader texture



# 2024-3-30 0 | 0 W

https://github.com/cisen/blog/issues

checkpoint

人口 能源 AI

population
energy
Artificial Inteligence

wpt
involves:gsnedders
involves:dbaron
involves:stephenmcgruer
involves:tabatkins

test-262
involves:leobalter
involves:ptomato
involves:rwaldron
involves:legendecas
involves:FrankYFTang
involves:shvaikalesh


involves:mcollina
involves:anonrig
involves:mertcanaltin

Tokio Rust
involves:carllerche
involves:hawkw
involves:davidpdrsn

std::sync::Mutex
std::sync::Arc
std::thread::time
tokio::spawn

Notify barrier
tokio::sync::RwLock;
channel tokio::select!
Mpsc channel single producer single comsumer
Watch channel single producer multiple comsumer


https://github.com/search?q=repo%3Anrc%2Frustaceans.org%20servo&type=code

involves:gdb
involves:dtolnay
involves:pcwalton

Wasmtime Webassembly wasi
involves:sunfishcode
involves:alexcrichton

Rust Team
involves:compiler-errors
involves:Mark-Simulacrum
involves:carols10cents
involves:nikomatsakis
involves:ashleygwilliams
involves:nrc
involves:tbu-
involves:cuviper
involves:RReverser

involves:glennw
involves:kvark
involves:CanadaHonk
involves:asajeffrey
involves:atbrakhi


involves:jpbruyere


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
involves:tlively

clspv/gpuweb/webgpu
involves:alan-baker
involves:kenrussell
involves:beaufortfrancois
involves:Kangz

WebRTC
involves:MirkoBonadei
involves:Orphis


ggml/whisper.cpp/llama.cpp
involves:ggerganov

Angle
involves:null77
involves:vonture
involves:Oletus
involves:Kangz

Webpack
involves:sokra

Babeljs
involves:hzoo
involves:jridgewell
involves:loganfsmyth

github search

Nodejs
involves:Qard

Igalia
involves:mariospr
involves:felipeerias
involves:xanlpz
involves:nicolo-ribaudo

wolvic
involves:calvaris
involves:svillar

Golang
involves:rsc
involves:robpike

Javascript Engine
involves:mathiasbynens
involves:backes
involves:bmeurer
involves:LeszekSwirski
involves:ulan
involves:bellard
involves:kasperl
involves:larsbak
involves:mraleph
involves:Hixie
involves:wingo
involves:titzer

Browsers
involves:tiaanl
involves:andreubotella
involves:bfgeek
involves:rniwa
involves:emilio
involves:gterzian
involves:jdm
involves:pylbrecht
involves:fantasai
involves:joyeecheung
involves:cathiechen
involves:xiaochengh
involves:noamr
involves:zcorpan
involves:Ms2ger
involves:mgaudet
involves:sideshowbarker


React
involves:gaearon



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

good artist copy, great artist steal

假线性阅读，自动清除

BIOS load bootloader

system boot
Interrupt GDT IDT CR3
Memory Management address translation

# 2024-3-28 0 | 0 W

1. run code
2. write code
goto 1

ts: 7 

GDT

task stack segment

machine running vuna code is 

sudo tcpdump -i any -AX -vv 'port 5432'


juicefs mount postgres://tannal:password@192.168.43.246:5432/jfs?sslmode=disable ~/tannalwork/jfs -d

tannal@raspi:~/tannalwork/projects$ juicefs format postgres://tannal:password@192.168.43.246:5432/jfs?sslmode=disable jfs
2024/03/28 15:10:00.716911 juicefs[4446] <INFO>: Meta address: postgres://tannal:****@192.168.43.246:5432/jfs?sslmode=disable [interface.go:497]
2024/03/28 15:10:00.725615 juicefs[4446] <WARNING>: The latency to database is too high: 8.389317ms [sql.go:260]
2024/03/28 15:10:00.897945 juicefs[4446] <INFO>: Data use file:///home/tannal/.juicefs/local/jfs/ [format.go:471]
2024/03/28 15:10:01.182269 juicefs[4446] <INFO>: Volume is formatted as {
  "Name": "jfs",
  "UUID": "cf5834d1-ddcf-42a3-a01c-aa3d159a6e79",
  "Storage": "file",
  "Bucket": "/home/tannal/.juicefs/local/",
  "BlockSize": 4096,
  "Compression": "none",
  "EncryptAlgo": "aes256gcm-rsa",
  "TrashDays": 1,
  "MetaVersion": 1,
  "MinClientVersion": "1.1.0-A",
  "DirStats": true
} [format.go:508]

juicefs format postgres://tannal:password@192.168.43.246:5432/jfs?sslmode=disable jfs
sudo systemctl restart pg

create database jfs

./psql -U tannal -w -d jfs

curl -sSL https://d.juicefs.com/install | sh -

tannal@raspi:~/.vim/pack/YouCompleteMe/opt/YouCompleteMe$ ls
CODE_OF_CONDUCT.md  codecov.yml  print_todos.sh  tox.ini
CONTRIBUTING.md     doc          python          update-vim-docs
COPYING.txt         install.py   run_tests.py    vimrc_ycm_minimal
README.md           install.sh   test
autoload            plugin       third_party
tannal@raspi:~/.vim/pack/YouCompleteMe/opt/YouCompleteMe$

./install.py --all
popd
~/.vim/pack/YouCompleteMe/opt/YouCompleteMe ~/tannalwork/projects
Generating ycmd build configuration...OK
Compiling ycmd target: ycm_core...OK
Building regex module...OK
Building watchdog module...OK
Installing Omnisharp for C# support...OK
Building gopls for go completion...
OK
Setting up Tern for JavaScript completion...OK
Installing rust-analyzer "nightly-2023-08-18" for Rust support...OK
Installing jdt.ls for Java support...OK
Setting up TSserver for TypeScript completion...OK
Setting up Clangd completer...OK
~/tannalwork/projects

You don't know what you really need, unless you already use something for that purpose.

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
export https_proxy=http://10.90.5.190:7890
export http_proxy=http://10.90.5.190:7890

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

similar 



hide and seek

sudo apt install tesseract-ocr

Using built-in specs.
COLLECT_GCC=gcc
Target: aarch64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 13.2.0-4ubuntu3' --with-bugurl=file:///usr/share/doc/gcc-13/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-13 --program-prefix=aarch64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/libexec --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-libquadmath --disable-libquadmath-support --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --enable-fix-cortex-a53-843419 --disable-werror --enable-checking=release --build=aarch64-linux-gnu --host=aarch64-linux-gnu --target=aarch64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 13.2.0 (Ubuntu 13.2.0-4ubuntu3) 
COLLECT_GCC_OPTIONS='-E' '-v' '-mlittle-endian' '-mabi=lp64'
 /usr/libexec/gcc/aarch64-linux-gnu/13/cc1 -E -quiet -v -imultiarch aarch64-linux-gnu - -mlittle-endian -mabi=lp64 -fasynchronous-unwind-tables -fstack-protector-strong -Wformat -Wformat-security -fstack-clash-protection -dumpbase -
ignoring nonexistent directory "/usr/local/include/aarch64-linux-gnu"
ignoring nonexistent directory "/usr/lib/gcc/aarch64-linux-gnu/13/include-fixed/aarch64-linux-gnu"
ignoring nonexistent directory "/usr/lib/gcc/aarch64-linux-gnu/13/include-fixed"
ignoring nonexistent directory "/usr/lib/gcc/aarch64-linux-gnu/13/../../../../aarch64-linux-gnu/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/gcc/aarch64-linux-gnu/13/include
 /usr/local/include
 /usr/include/aarch64-linux-gnu
 /usr/include
End of search list.


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
If you have more than one server you want to install packages on, you might want to use this to decrease latency (presumably "slow" npmjs.org will be connected to only once per package/version) and provide limited failover (if npmjs.org is down, we might still find something useful in the cache) or avoid issues like How one developer just broke Node, Babel and thousands of projects in 11 lines of JavaScript, Many packages suddenly disappeared or Registry returns 404 for a package I have installed before.


ffmpeg -hwaccel vulkan -threads 8 -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccel cuda -threads 3 -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c:v libx264 -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccel dxva2 -threads 8 -i Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4 -f lavfi -i aevalsrc=0 -vcodec copy -acodec aac -map 0:0 -map 1:0 -c:v libx264 -pix_fmt yuv420p -shortest -strict experimental -f flv rtmp://192.168.43.246/live/livestream

ffmpeg -hwaccel dxva2 -threads 8 -re -i Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4 -f flv rtmp://192.168.43.246/live/livestream

# 2024-3-22 0 | 0 W

pgrep

ffmpeg -hwaccel cuda -threads 3 -preset ultrafast -re -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -c copy -f hls rtmp://localhost/live/livestream

ffmpeg -hwaccels
ffmpeg -benchmark -hwaccel vdpau -i 'Ipartment.2009.S01E01.2160p.WEB-DL.H.265.AAC-NueXini@HQC.mp4' -f null -

cuda
vaapi
drm
opencl
vulkan


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


vim ~/.config/verdaccio/config.yaml


uplinks:
  npmjs:       
    #url: https://registry.npmjs.org/
    #url: https://repo.huaweicloud.com/repository/npm/
    url: https://registry.npm.taobao.org/
    agent_options:
      keepAlive: true
      maxSockets: 40
      maxFreeSockets: 10
  npmjs2:  
    url: https://registry.npmjs.org/
    agent_options:
      keepAlive: true
      maxSockets: 40
      maxFreeSockets: 10
packages:
  '@*/*':
    # scoped packages
    access: $all
    publish: $authenticated
    unpublish: $authenticated
    proxy: npmjs npmjs2

  '**':
    # allow all users (including non-authenticated users) to read and
    # publish all packages
    #
    # you can specify usernames/groupnames (depending on your auth plugin)
    # and three keywords: "$all", "$anonymous", "$authenticated"
    access: $all

    # allow all known users to publish/publish packages
    # (anyone can register by default, remember?)
    publish: $authenticated
    unpublish: $authenticated

    # if package is not available locally, proxy requests to 'npmjs' registry
    proxy: npmjs npmjs2


uplinks:
  npmjs:
    url: https://registry.npmjs.org/
    max_fails: 20
    fail_timeout: 10m

npm install --location=global verdaccio@next

verdaccio -l 0.0.0.0:4873

pnpm setup
Appended new lines to /home/tannal/.bashrc

Next configuration changes were made:
export PNPM_HOME="/home/tannal/.local/share/pnpm"
case ":$PATH:" in
  *":$PNPM_HOME:"*) ;;
  *) export PATH="$PNPM_HOME:$PATH" ;;
esac

To start using pnpm, run:
source /home/tannal/.bashrc

pnpm i -g verdaccio@next-7
pnpm i -g verdaccio@latest-6
pnpm i -g verdaccio@next
pnpm uninstall -g verdaccio@next-7

1) + URL 中+号表示空格 %2B
2) 空格 URL中的空格可以用+号或者编码 %20
3) / 分隔目录和子目录 %2F
4) ? 分隔实际的 URL 和参数 %3F
5) % 指定特殊字符 %25
6) # 表示书签 %23
7) &amp; URL 中指定的参数间的分隔符 %26
8) = URL 中指定参数的值 %3D

video encoding/decoding
intel/amd vaapi
nvidia nvenc/nvdec

ffmpeg -hwaccel vaapi

bindings generator

It allows React-Native to run JS using different JS engines, including JavascriptCore, the engine used in Webkit, and Hermes, an engine that comes bundled with React-native. JSI appears to be the only existing effort to implement such an common interface to Javascript engines.


$env:NPM_CONFIG_REGISTRY="http://192.168.43.246:4873"

merge two or three shiny things together create a useful project
node v8 libuv

differential testing

除非信息提供者与你当前状态有非常高的契合度，不要轻易按固定顺序模式接受信息（填鸭式）
从无序开始，在刺激中构造秩序规则

一段连续的输入（人的感官主要是触觉处理信息），可以分为很多个entry point

注意力机制聚焦到该输入（刺激）时

命中entry point（附近） 直接理解 action呼之欲出 （performance area）action跟触觉强相关
触觉会把输入进行分割
所以看别人弹钢琴和自己弹的输入不一样，最好的方法

命中空洞（无意义的点，残缺）
快速寻找最近的entry point或者创建一个新的entry point （新信息的录入，需要搭配上触觉）

action 会影响未来的输入（需提前在脑中encoding这部分信息）
方式是

action发生后的输入和脑中记忆的输入进行比对（loss function）校正（自动发生）

比对校正是生物体与生俱来的能力


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


for row in table_scan_generator:
    print(row)

ブロック(Bo　ro　ko)　blocking

レッド (re d do) red

グリーン (gu r i n) green

非同期 (hi do ki) async 异步

タスク(ta su ku) task

mkdir -p examples
mv src/main.rs examples/hello-redis.rs

cargo run --example hello-redis

export https_proxy=http://10.90.17.22:7890
export http_proxy=http://10.90.17.22:7890

# 2024-3-21 0 | 0 W

libuv, twisted, tornado, asyncIO, Netty, Boost.Asio

Threads and Processes
Actor Model:
Dataflow Programming
Transactional Memory
Futures and Promises
Reactive Programming
Coroutines

月で (tsuki de) 按月算（月薪水）

先月 (sen get su) last month
今　(ima wa) now

[00:00:00.000 --> 00:00:04.440]  今の月々または1日のお給料を教えていただくことは可能でしょうか?
[00:00:04.440 --> 00:00:05.000]  大丈夫です。
[00:00:05.000 --> 00:00:08.420]  23から5くらい。
[00:00:08.420 --> 00:00:10.200]  20くらいです。
[00:00:10.200 --> 00:00:13.160]  お仕事は何をされていらっしゃいますか?
[00:00:13.160 --> 00:00:16.380]  ジュエリー系メーカーです。
[00:00:16.380 --> 00:00:19.440]  好きだと37くらいですね。
[00:00:19.440 --> 00:00:20.360]  ありがとうございます。
[00:00:20.360 --> 00:00:22.360]  お仕事は何をなされているんですか?
[00:00:22.360 --> 00:00:23.960]  広告代理店ですね。
[00:00:23.960 --> 00:00:26.460]  会社員なんですけど企画職ですね。
[00:00:26.460 --> 00:00:27.740]  50万円くらいかな。

[00:00:27.740 --> 00:00:28.860]  ありがとうございました。
[00:00:28.860 --> 00:00:31.480]  私は母なので。

[00:00:31.480 --> 00:00:38.260]  月々、毎月だと40万くらいですかね。
[00:00:38.260 --> 00:00:40.720]  トレーディングカンパニー的な感じです。

[00:00:40.720 --> 00:00:49.060]  今はレストランでやっていて、ホールでいろんな人とお話をしています。
[00:00:49.060 --> 00:00:51.120]  ウイトレスさんということで。
[00:00:51.120 --> 00:00:56.720]  週に2、3回とかで、1、2回かな。
[00:00:56.720 --> 00:00:58.840]  先月は2万5千円。
[00:00:59.060 --> 00:01:00.160]  はい、5千円でしたね。


[00:01:00.160 --> 00:01:03.060]  教職ですかね。
[00:01:03.060 --> 00:01:05.060]  1000万円くらいかな。
[00:01:05.060 --> 00:01:07.440]  年収で。
[00:01:07.440 --> 00:01:13.280]  20万以上くらいだから、生活はできています。
[00:01:13.280 --> 00:01:16.220]  お仕事はどういうものをされているんですか?
[00:01:16.220 --> 00:01:17.960]  介護系です。


[00:01:17.960 --> 00:01:19.240]  バイト?
[00:01:19.240 --> 00:01:20.440]  バイトで大丈夫。
[00:01:20.440 --> 00:01:23.260]  だいたい7万円くらい。
[00:01:23.260 --> 00:01:23.760]  月で。
[00:01:23.760 --> 00:01:24.260]  月。
[00:01:24.260 --> 00:01:26.560]  12万とか。
[00:01:26.560 --> 00:01:28.680]  飲食店で働いています。
[00:01:28.680 --> 00:01:30.680]  1万円飲食店です。
[00:01:30.680 --> 00:01:32.680]  5桁の後半、毎日。


[00:01:32.680 --> 00:01:34.680]  お仕事はなにをなされていますか?
[00:01:34.680 --> 00:01:36.680]  刀の職人。
[00:01:36.680 --> 00:01:40.000]  刀の職人さんは、どれくらいやってるんですか?
[00:01:40.000 --> 00:01:53.000]  そうね、まだでもそんな、でもね、昔からだけど、時々辞めたり、時々悪の道に走ったり、マフィアになったり、だから10年くらいかな。
[00:01:53.000 --> 00:01:54.000]  30万くらい。
[00:01:54.000 --> 00:01:57.000]  メーカーの勤務です。
[00:01:57.000 --> 00:02:06.000]  東京はアジアの中でも、生活費が高い都市とされているんですけれども、その東京での生活をしていくのに、現在の収入は十分だと感じますか?
[00:02:06.000 --> 00:02:07.000]  思わないです。
[00:02:07.000 --> 00:02:09.000]  不十分だと思います。
[00:02:09.000 --> 00:02:18.000]  今、実家暮らしなんで、十分と感じてるんですけど、一人暮らし始めたら、足りないかなって感じです。
[00:02:18.000 --> 00:02:20.000]  一人暮らしでいらっしゃいますか?
[00:02:20.000 --> 00:02:24.000]  いや、実家なんで、実家でもちょっと不十分だなと思います。
[00:02:24.000 --> 00:02:26.000]  どういうところが足りないと感じますか?
[00:02:26.000 --> 00:02:36.000]  いや、なんていうんだろうな、もう本当に、例えばこうやって飲む生活とか土日にあった、それが毎週繰り返すってなったら、生活は厳しいかなって思うんで。
[00:02:36.000 --> 00:02:49.000]  足りてはいますけど、例えば遊びとか、少し遠出、日本の地方に行くときは、お金が少し足りないかなと思うんですけど、生活する分には別に全然足りてないですけど。
[00:02:49.000 --> 00:02:55.000]  しましたら、あなたが人生直面した一番の経済的に困難だった出来事っていうのは、どういうことがありましたか?
[00:02:55.000 --> 00:03:08.000]  海外で生活してて、感動されて、親から感動されて、生活を送りますよって手紙でやり取りしてたんだけど、国際電話で来なくなっちゃって、一回来てたんだけど。
[00:03:08.000 --> 00:03:16.000]  で、それから4年ぐらい、無収入で海外で、路上生活みたいな生活を海外で送ってた時はやっぱり一番困った。
[00:03:16.000 --> 00:03:18.000]  それはどちらの国にいらしたんですか?
[00:03:18.000 --> 00:03:19.000]  タイで。
[00:03:19.000 --> 00:03:24.000]  タイなんですね。ありがとうございます。その時はどういう風にして生活をしてらっしゃったんですか?
[00:03:24.000 --> 00:03:37.000]  タイのお寺で、テロワードのお寺にお坊さんと一緒に寝泊まりさせていただいて、お坊さんがいただいたタンブン、ヒンディバートっていうんですかね、お伏せで食べてました。
[00:03:37.000 --> 00:03:44.000]  急に、親が亡くなった時が一番きつかったですね。
[00:03:44.000 --> 00:03:49.000]  その時は何かたくさんお金の出費があったりしましたか?
[00:03:49.000 --> 00:03:53.000]  意外と、知人とか親族の支えがあったから。
[00:03:53.000 --> 00:04:01.000]  その時は持ち越せたから、やっぱり血のつながりってすごいなと思って。
[00:04:01.000 --> 00:04:17.000]  やっぱり受験。大学受験が一番お金がかかって、塾も通わないとやっぱり難しいので、入学にもすごいお金がかかりますし、受験が一番かかったなって思ってます。
[00:04:17.000 --> 00:04:22.000]  昔、家を借りる時にどこも高いなって困ってました。
[00:04:22.000 --> 00:04:24.000]  困ってました。
[00:04:24.000 --> 00:04:27.000]  その時はいくらぐらいが高いと感じましたか?
[00:04:27.000 --> 00:04:32.000]  一部屋で20万円とか。
[00:04:32.000 --> 00:04:36.000]  騙された。詐欺に。
[00:04:36.000 --> 00:04:40.000]  食べるもんもないんだよ。どうすんの?
[00:04:40.000 --> 00:04:44.000]  貧乏だった時の食べるもんとか、何食べてたんですか?
[00:04:44.000 --> 00:04:45.000]  聞きたい?
[00:04:45.000 --> 00:04:46.000]  はい。
[00:04:46.000 --> 00:04:50.000]  マックの捨てたやつを袋開けて食べた。
[00:04:50.000 --> 00:04:51.000]  こっち来るな。
[00:04:51.000 --> 00:04:59.000]  あと炊き出しって日本のシステムがある。月に2回とか公園でそれを食べた。生き延びた。
[00:04:59.000 --> 00:05:03.000]  そういった生活、どれくらいの期間続いたんですか?
[00:05:03.000 --> 00:05:05.000]  4ヶ月ぐらい。
[00:05:05.000 --> 00:05:06.000]  長いですね。
[00:05:06.000 --> 00:05:07.000]  そうそうそう。
[00:05:07.000 --> 00:05:14.000]  では、現在の日本の社会基準を持って自分は貧乏だと感じますか?
[00:05:14.000 --> 00:05:19.000]  いや、中間の辺なんじゃないかなって気はします。年齢的な平均でいくと。
[00:05:19.000 --> 00:05:30.000]  中の女王から付与している。本当に貧乏だったらもう生活できないじゃないですか。
[00:05:30.000 --> 00:05:33.000]  貧乏とは思わないかな。
[00:05:33.000 --> 00:05:35.000]  思わないです。
[00:05:35.000 --> 00:05:44.000]  思わないですね。ありがたいことに仕事もあって働く環境もあるので、貧乏とは思わないです。
[00:05:44.000 --> 00:05:45.000]  全く思わないです。
[00:05:45.000 --> 00:05:47.000]  ありましたね。子供の頃。
[00:05:47.000 --> 00:05:50.000]  その時はどういうことが貧乏だと感じましたか?
[00:05:50.000 --> 00:06:00.000]  貧乏だというか、日本全体が貧しかったんですよ。戦争に負けて。戦後すぐ、僕らは団塊世代って言って。
[00:06:00.000 --> 00:06:07.000]  戦後すぐに3年4年経ったぐらいにたくさんの子供が生まれたその真っ盛りだったんですね。
[00:06:07.000 --> 00:06:11.000]  貧乏ではないけれども、裕福ではないと思います。
[00:06:11.000 --> 00:06:14.000]  なぜそう感じますか?
[00:06:14.000 --> 00:06:16.000]  そうですね。
[00:06:16.000 --> 00:06:33.000]  まあ、困りはしないけど、やっぱりずっと先に貯金がどんどんできるかとかのイメージはちょっと難しそうだから、今は大丈夫だけど、先が心配っていう感じです。
[00:06:33.000 --> 00:06:42.000]  では、貧乏と感じるっていうと、人と比べてのことなのか、それとも日本で全体的に貧乏に日本人がなっているということでしょうか?
[00:06:42.000 --> 00:06:45.000]  うーん、全体的にやっぱり。
[00:06:45.000 --> 00:06:54.000]  やっぱり、毎日の食べ物買うときとかも、高いよねっていろんな人と話しするから、みんなかなって感じです。
[00:06:54.000 --> 00:07:08.000]  いや、やっぱり物価上がってて、給料が上がってないっていうところが主にあるんで、やっぱり経済的にというか、世の中的にどんどん貧乏になってるだろうなっていうのは直感、肌感で感じますね。
[00:07:08.000 --> 00:07:11.000]  どういうものが一番上がったと感じますか?
[00:07:11.000 --> 00:07:14.000]  食費ですね。
[00:07:14.000 --> 00:07:16.000]  全般的に。
[00:07:16.000 --> 00:07:19.000]  全般的に、もう交通費以外は大体上がってるみたいな感じですね。
[00:07:19.000 --> 00:07:25.000]  そういった現象って、いつから続いてると思いますか?
[00:07:25.000 --> 00:07:28.000]  物価が上がり始めたのがコロナじゃないですか。
[00:07:28.000 --> 00:07:31.000]  コロナの影響が大きいと思います。
[00:07:31.000 --> 00:07:36.000]  日本が平均的に貧乏になっていってる原因って何だと思いますか?
[00:07:36.000 --> 00:07:41.000]  今問題になってる、その政府の裏金とかで、福祉に回せる部分のお金が減ってて。
[00:07:41.000 --> 00:07:41.000]  まあ、今問題になってる、その政府の裏金とかで、福祉に回せる部分のお金が減ってて。
[00:07:41.000 --> 00:07:42.000]  まあ、今問題になってる、その政府の裏金とかで、福祉に回せる部分のお金が減ってて。
[00:07:42.000 --> 00:07:45.000]  まあ、今問題になってる、その政府の裏金とかで、福祉に回せる部分のお金が減ってて。
[00:07:45.000 --> 00:07:56.000]  福祉に回せる部分のお金が減ってるから、そこの生活出場品に使うお金が増えてることで、自由に使えるお金が少なくなって、貧乏に感じたり、貧乏になってるんじゃないかなっていうふうに思います。
[00:07:56.000 --> 00:08:03.000]  非正規の方ですね。方たちがすごく増えてる。
[00:08:03.000 --> 00:08:11.000]  上がれないですからね。一変、非正規で10年、20年過ごしてると、そこから正社員になるっていうシステムが日本にはないので、あまり。
[00:08:11.000 --> 00:08:16.000]  なくはないんですけど、なかなかそこからはい上がれないっていうところがやっぱり、それなのかなって思います。
[00:08:16.000 --> 00:08:28.000]  チャレンジする人が増えたんじゃないですかね。安定したアレがもらえるよりも、チャレンジして、少ないお金でも好きなものを突き詰める人が増えて、そう言われてるのかもしれないですね。
[00:08:28.000 --> 00:08:36.000]  YouTuberとか人気なんですよ、今。子供になりたい職業で、多いんで、そうなのかなーみたいな。わかんないですけど。
[00:08:36.000 --> 00:08:40.000]  日本人の東京での平均月収が35万円程度って言われてるんですけど。
[00:08:40.000 --> 00:08:46.000]  本当にそうだと思いますか?それとも、もらってるお給料、それより少ない人が多いんじゃないかなって思いますか?
[00:08:46.000 --> 00:08:47.000]  少ないんじゃない?
[00:08:47.000 --> 00:08:49.000]  少ないと思います。
[00:08:49.000 --> 00:08:54.000]  平均月収で、どれぐらいもらってると思いますか?人は。
[00:08:54.000 --> 00:08:56.000]  25ぐらい?
[00:08:56.000 --> 00:09:02.000]  25とかじゃない?多くて40で、少なくて25とかじゃない?
[00:09:02.000 --> 00:09:09.000]  まあ、これも年齢によるかなとは思ってて、その平均年収が多分40、50代の方とかも入ってるんであれば、それぐらいかなと思います。
[00:09:09.000 --> 00:09:15.000]  で、一番ビジネス層で20代から30代でいくと、35もらってない人の方が多いんじゃないかなと思いますね。
[00:09:15.000 --> 00:09:20.000]  日本で貧乏だと定義される月収っていくらぐらいだと思いますか?
[00:09:20.000 --> 00:09:22.000]  15万以下ぐらい。
[00:09:22.000 --> 00:09:25.000]  手取り20とか?
[00:09:25.000 --> 00:09:29.000]  自分が手取り20万の仕事してたら、私って貧乏だなって思いますか?
[00:09:29.000 --> 00:09:33.000]  節約しないとって感じじゃない?
[00:09:33.000 --> 00:09:36.000]  10万円前後じゃないですかね。
[00:09:36.000 --> 00:09:38.000]  10万円前後だと、東京で暮らしていくのは?
[00:09:38.000 --> 00:09:41.000]  東京で暮らしていくのは、ちょっとカツカツになりそうです。
[00:09:41.000 --> 00:09:42.000]  そうです、そうです。
[00:09:42.000 --> 00:09:49.000]  だから、ネットカフェとかああいうとこで寝泊まりしてる人、若い人、20代とか10代後半ぐらいの人、結構いるって話聞いてるんで、
[00:09:49.000 --> 00:09:57.000]  僕そういう人、10年、15年ぐらい前かな、何人かいたんで、ネットカフェでそういう生活してる方。
[00:09:57.000 --> 00:10:00.000]  だから、全然食べてないから、ガリガリみんな焦っちゃってて。
[00:10:00.000 --> 00:10:07.000]  で、今ちょっとアルバイトやって、パートタイムジョブやって、夜は寝泊まりできないから、ないからネットカフェでみんな寝泊まりしてる。
[00:10:07.000 --> 00:10:12.000]  今でも秋葉原、今のたくさんそういうネットカフェがたくさんありますけど。
[00:10:12.000 --> 00:10:18.000]  では、何の心配もなく、東京で快適に暮らすには、いくらぐらい必要だと思いますか?
[00:10:18.000 --> 00:10:22.000]  何の心配もなく、40万ぐらいはあった方がいいんじゃないですかね。
[00:10:22.000 --> 00:10:24.000]  どれぐらい必要だと思いますか?
[00:10:24.000 --> 00:10:28.000]  何の心配もなく、豊かな気持ち。
[00:10:28.000 --> 00:10:29.000]  100万円?
[00:10:29.000 --> 00:10:32.000]  そうですね、100万円。
[00:10:32.000 --> 00:10:33.000]  欲しいですよね。
[00:10:33.000 --> 00:10:36.000]  月いくらぐらいか。
[00:10:36.000 --> 00:10:40.000]  お子様がいる人として、どれぐらいが十分という感じでしょうか?
[00:10:40.000 --> 00:10:43.000]  60万ぐらい。
[00:10:43.000 --> 00:10:49.000]  マンションに住んでなのか、アパートに住んでなのかって、基準が分からないんですけど。
[00:10:49.000 --> 00:10:58.000]  高級マンションに住んでたら、それこそ100万でも50万でも必要だし、本当に低級のアパートだったら、20万、30万。
[00:10:58.000 --> 00:11:05.000]  もし、ご自身が東京で暮らす上で、全く何の問題もなく暮らすのだとすれば、いくらぐらい必要だと思いますか?
[00:11:05.000 --> 00:11:07.000]  20万円ぐらい。
[00:11:07.000 --> 00:11:13.000]  40万円、50万円ぐらいあれば、何の心配もないから。
[00:11:13.000 --> 00:11:17.000]  もし、今手元に50万円があったら、何を最初にしますか?
[00:11:17.000 --> 00:11:20.000]  家電を買い替えます。
[00:11:20.000 --> 00:11:23.000]  買い替えたい家電、何かありますか?
[00:11:23.000 --> 00:11:25.000]  エアコン、エアコン買い替えたいです。
[00:11:25.000 --> 00:11:30.000]  もし、今お金いっぱい持ってたら、最初に何したいですか?
[00:11:30.000 --> 00:11:33.000]  欲しいおもちゃ買いたい。
[00:11:33.000 --> 00:11:34.000]  どんなおもちゃが欲しいですか?
[00:11:34.000 --> 00:11:38.000]  隅っこのパソコン。
[00:11:38.000 --> 00:11:49.000]  ちょっと貯金をまずするかなって思って、20万ぐらい貯金して、15万は自分の好きなこととかに、趣味とかに使っていきたいなって思います。
[00:11:49.000 --> 00:12:00.000]  海外の観光客が、円安のお金で物がいっぱい安くて買えるっていう風に言って、自分が買えないようなものにたくさんお金を使っていたら、あなたはどう感じますか?
[00:12:00.000 --> 00:12:02.000]  別にどんどん使ってくださいって。
[00:12:02.000 --> 00:12:03.000]  嫌な気持ちはしない?
[00:12:03.000 --> 00:12:08.000]  嫌な気持ちはしないです。もっと味わってください。もっとディープに、ディープに。
[00:12:08.000 --> 00:12:22.000]  ありがとうございますって感じです。日本を、なんか、日本に来て楽しんでもらえればいいなと思うんで、それでなんか、日本人が何か買えなくなってるみたいなこともそんな、ないと思うんで、はい。
[00:12:22.000 --> 00:12:32.000]  だって3年間、僕、バックパッカーやってましたけど、海外でたくさんお金いろんなとこ落としてたんで、落とさないと、その自国のその人たちが潤わないじゃないですか、観光業って、観光業の人たちが。だから、それは僕、
[00:12:32.000 --> 00:12:42.000]  理論分かってるから、プロセス分かってるから、海外の人、お金たくさん落としてもらわないと、日本っていうのは結局ね、タクシーとか入ってこないんで、たくさん。
[00:12:42.000 --> 00:12:57.000]  そのシステム、プロセス、僕、よく理解してるんで、うらやましいってことされるのは自分なんですよ。20年前、30年前の自分のバックパッカーやってた時、タイでも、シンガポーでもたくさん落としましたから、それはその国のそのタイミングになったと思います。
[00:12:57.000 --> 00:13:00.000]  では、あなたは今貯金はできていますか?
[00:13:00.000 --> 00:13:01.000]  ないですね。
[00:13:01.000 --> 00:13:02.000]  ほぼないです。
[00:13:02.000 --> 00:13:04.000]  あんまりできてないです。
[00:13:04.000 --> 00:13:08.000]  じゃあ、貯金をすること自体には意味あると思いますか?
[00:13:08.000 --> 00:13:13.000]  そうですね。何か急に困った時に使えばいいので、ないよりはある方がいいと思います。
[00:13:13.000 --> 00:13:19.000]  お子様がいらっしゃる母として、どれぐらいの貯金があると安心だなと感じますか?
[00:13:19.000 --> 00:13:22.000]  3000万ぐらい。
[00:13:22.000 --> 00:13:24.000]  貯金はできていますか?
[00:13:24.000 --> 00:13:26.000]  まあ、そこそこ、はい。
[00:13:26.000 --> 00:13:30.000]  貯金すること自体に意味はあると思いますか?
[00:13:30.000 --> 00:13:38.000]  もちろん、当然。貯金というか、現金の貯金とは限らないですけど、子供の将来もあるので大事だと思います。
[00:13:38.000 --> 00:13:40.000]  いや、今はできてないですね。
[00:13:40.000 --> 00:13:43.000]  貯金はそもそも意味があると思いますか?
[00:13:43.000 --> 00:13:50.000]  意味はあると思いますが、日本円で貯金していくことに意味はあるのかなとは思っていて、
[00:13:50.000 --> 00:13:59.000]  まあ、いろんなことに今物価も上がっていく中で、円は安くなっていくってことなんで、日本円で貯金をしてても、10年後、今100万貯めてたら、
[00:13:59.000 --> 00:14:10.000]  10年後100万の価値があるかといえば、そうではないはずなので、もっと違うもので、要は下がらないものですよね。価値が下がらないもの。
[00:14:10.000 --> 00:14:17.000]  まあ、簡単に金とかって言っちゃいますけど、そういったもので、なんか貯めておく必要あるんじゃないかなと思いますね。
[00:14:17.000 --> 00:14:21.000]  貯金すること自体に意味はあると思いますか?
[00:14:21.000 --> 00:14:24.000]  問題ならば、しない方がいいと思います。
[00:14:24.000 --> 00:14:28.000]  あると、お金が停滞しちゃうんで。
[00:14:28.000 --> 00:14:34.000]  お金が停滞しちゃうんで、銀行になるべく貯めないように、循環させる方がいいんじゃないかなと思って。
[00:14:34.000 --> 00:14:43.000]  そうしましたら、貯金などがない場合に、他に何か頼れるものとか、生活環境を変えれることとかって日本にありますか?
[00:14:43.000 --> 00:14:52.000]  ありますよ。循環型社会のモデルがちゃんとしっかりできてるんで、日本の場合それも、モデル僕見たんですけど、2、3年前、ちゃんと。
[00:14:52.000 --> 00:14:57.000]  取り入れれば別に、日本って社会保障が充実してますから、ある程度、全然問題ないと思います。
[00:14:57.000 --> 00:15:11.000]  政府に頼るっていう手があると思うんですけど、やっぱり今いろいろ問題になって、政府に対するちょっと不信感があるので、あんまり頼りたくはないなっていうふうな気持ちです。
[00:15:11.000 --> 00:15:26.000]  年金生活に、今年の4月から、あ、今年じゃない、去年の4月から年金生活なんで、どのくらいですかね。あんまりはっきり把握してないけど、たかが知れてますよ、日本の年金はね。
[00:15:26.000 --> 00:15:32.000]  だから、あとそういうのとか、個人年金とかそういうのですからね。どうだろう。
[00:15:32.000 --> 00:15:34.000]  年金っていうのは何歳からもらえるものなんですか?
[00:15:34.000 --> 00:15:45.000]  あのね、日本はね、60、えっと65が基本なんですけど、えっと60からもらえるはずなんですよ。早く。でもそうすると減っちゃうのね。全体的には減る。
[00:15:45.000 --> 00:15:53.000]  で、私はまあ働いてたんで、74まで働いてたんで、ずっと遅らせて、75になったら受け取るっていう感じ。
[00:15:53.000 --> 00:15:54.000]  うん。
[00:15:54.000 --> 00:16:00.000]  日本ではみんなが裕福だっていうイメージを持っている海外の視聴者さんに何か言いたいことはありますか?
[00:16:00.000 --> 00:16:04.000]  日本は裕福ではありません。一部です。
[00:16:04.000 --> 00:16:05.000]  それ以外の人は?
[00:16:05.000 --> 00:16:14.000]  あの、フリをしてる。お金があるフリ。これ日本人の心。ご飯食べてなくても、侍とかはご飯食べてなくても、つま弁じって分かる?
[00:16:14.000 --> 00:16:15.000]  はい。
[00:16:15.000 --> 00:16:23.000]  食べた後にこうやってやるんですよ。ご飯3日ぐらい食べてなくても、つま弁じでこうやってやってる。そしたら見た人は、まあお腹いっぱい食べたんだなと思うけど、
[00:16:23.000 --> 00:16:28.000]  実際は食べてる。これ日本の心。
[00:16:28.000 --> 00:16:30.000]  そういったものは外に見せないようにしているだけ?
[00:16:30.000 --> 00:16:32.000]  そうです。そうです。
[00:16:32.000 --> 00:16:36.000]  なんで日本人はそういうのを外に見せないようにしてると思いますか?
[00:16:36.000 --> 00:16:38.000]  迷惑かかるじゃない。
[00:16:38.000 --> 00:16:47.000]  裕福じゃないけど、心は貧しくはないと思うので、まあバランスだと思います。
[00:16:47.000 --> 00:16:51.000]  すみません。じゃあ、心の貧しくないっていうのはどういうところにあると思いますか?
[00:16:51.000 --> 00:16:52.000]  そうですね。
[00:16:52.000 --> 00:17:03.000]  まあ別にお金かけなくても遊びに行ったりはできるので、お外に出て楽しいねって言ってるのもハッピーかなって思います。
[00:17:03.000 --> 00:17:04.000]  ありがとうございます。
[00:17:04.000 --> 00:17:15.000]  はい。

ffmpeg -i J -vn -ar 16000 -ac 2 -ab 160k poor.wav

./main -m models/ggml-large-v3.bin -f poor. -l ja poor.wav


みなさん(mi na san)

こんにちは(こんに　ちわ)


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

browsers desktop mobile edge
servers

traditional systems operating systems database systems ml sys distributed systems
multimedia audio video 
graphics rendering games
docs
llm
Programming languages js engine jvm cpython ruby luajit C# .NET go rust llvm
embedded mobile edge
security

wget https://developer.nvidia.com/downloads/compute/machine-learning/tensorrt/secure/8.6.1/tars/TensorRT-8.6.1.6.Linux.x86_64-gnu.cuda-11.8.tar.gz

tar xvf TensorRT-8.6.1.6.Linux.x86_64-gnu.cuda-11.8.tar.gz

sudo apt update && sudo apt install -y cmake g++ wget unzip
 
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
unzip opencv.zip
 
cmake -B build
cmake --build build -j15
cmake --install build


cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'


export https_proxy=http://10.90.39.224:7890
export http_proxy=http://10.90.39.224:7890

./main -m models/ggml-large-v3.bin -f jeff.wav

ffmpeg -i  -vn -ar 16000 -ac 2 -ab 160k jeff.wav

在没看到大体方向之前，对于一句话任意的过度解读都可能是错的。

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

[00:00:00.240 --> 00:00:02.400]  みなさんこんにちは、MijunbossのKです。
[00:00:02.400 --> 00:00:06.200]  たくさんの方が、私たち日本人の人々に
[00:00:06.200 --> 00:00:09.920]  最近のミス・ジャパンのコントローラーについて
[00:00:09.920 --> 00:00:12.000]  何かを聞きたいと思っています。
[00:00:12.000 --> 00:00:13.520]  特に、彼女は日本人にとっては伝統的に見えないからです。
[00:00:13.520 --> 00:00:17.320]  しかし、彼女はウクレレ生まれの自然な日本人です。
[00:00:17.320 --> 00:00:19.720]  そのため、私たちは東京の街を踏み出して、
[00:00:19.720 --> 00:00:22.720]  地域のインサイトを早く集めることにしました。
[00:00:22.720 --> 00:00:23.960]  でも、なぜか知っていますか?
[00:00:23.960 --> 00:00:26.400]  このビデオを発表する日に、
[00:00:26.400 --> 00:00:30.960]  彼女が伝統的な伝統的な事件によって伝統的に彼女の宝を与えることが発生しました。
[00:00:30.960 --> 00:00:32.760]  彼女のプライバシーを尊敬するために、
[00:00:32.760 --> 00:00:35.840]  私たちはこのコントローラーのアスペクトに入ることはできません。
[00:00:35.840 --> 00:00:38.200]  しかし、彼女がミス・ジャパンのタイトルを獲得したのは、
[00:00:38.200 --> 00:00:41.520]  多くの面白い文化的な質問です。
[00:00:41.520 --> 00:00:44.040]  アジアからもっと真実的なインサイトや
[00:00:44.040 --> 00:00:45.840]  独特のストリートインタビューがある場合、
[00:00:45.840 --> 00:00:48.360]  どこかでテーマを選択することができます。
[00:00:48.360 --> 00:00:50.240]  asianboss.ioをチェックしてください。
[00:00:50.240 --> 00:00:53.600]  そして、私たちの動きの一部に参加し、文化の間隔を広げることができます。
[00:00:53.600 --> 00:00:56.400]  短い時間で特別な供給ができます。
[00:00:56.400 --> 00:00:59.880]  詳細は下の説明欄のリンクからチェックしてください。
[00:00:59.880 --> 00:01:03.400]  では、日本の人たちが何を言うのか聞きましょう。
[00:01:03.400 --> 00:01:08.840]  まず、先週行われましたミス日本コンテストについてご存知ですか?
[00:01:08.840 --> 00:01:10.400]  いや、ご存知じゃないです。
[00:01:10.400 --> 00:01:11.560]  見たことないです。
[00:01:11.560 --> 00:01:13.600]  残念ですけど、知りませんでした。
[00:01:13.600 --> 00:01:18.280]  ミス日本は知ってますけど、見てはないですね。
[00:01:18.280 --> 00:01:19.720]  知らなかったです、私も。
[00:01:19.720 --> 00:01:22.360]  私、存じてます。
[00:01:22.360 --> 00:01:24.960]  見事グランプリに輝いたのがこちらの方です。
[00:01:24.960 --> 00:01:27.440]  めっちゃ綺麗。
[00:01:27.440 --> 00:01:32.760]  ちょっと感じ、目元とかはくっきりしてて、日本人っぽいなって思いました。
[00:01:32.760 --> 00:01:36.800]  ハーフっぽくて、ちょっと日本人っぽい感じですね。
[00:01:36.800 --> 00:01:39.400]  あ、すげえ。めっちゃ綺麗。
[00:01:39.400 --> 00:01:40.800]  えっ、かわいい。
[00:01:40.800 --> 00:01:42.720]  パッと見て、どういった印象を受けますか?
[00:01:42.720 --> 00:01:45.320]  え、すっごい綺麗です。なんか人形みたい。
[00:01:45.320 --> 00:01:48.000]  どの辺がすごい綺麗、印象に残る感じですか?
[00:01:48.000 --> 00:01:51.800]  肌の綺麗さと彫りの深さ。
[00:01:51.800 --> 00:01:53.800]  この二重が羨ましいです。
[00:01:53.800 --> 00:01:55.560]  日本感ゼロですよね。
[00:01:55.560 --> 00:01:56.760]  感じないです。
[00:01:56.760 --> 00:01:58.960]  どういった部分、なんでそう思われるんですか?
[00:01:58.960 --> 00:02:02.400]  でもなんか、見た目がもう、鼻が高いし、
[00:02:02.400 --> 00:02:02.720]  もうなんか、
[00:02:02.720 --> 00:02:03.840]  なんか、あれですよね。
[00:02:03.840 --> 00:02:05.840]  外国人って感じしますよね。
[00:02:05.840 --> 00:02:07.400]  ハーフ顔なんで。
[00:02:07.400 --> 00:02:10.240]  外国の方ですね。
[00:02:10.240 --> 00:02:14.720]  こちらの写真をパッと見て、どういう印象を受けますか?
[00:02:14.720 --> 00:02:19.800]  あ、あの、日本ミスグランプリですけど、
[00:02:19.800 --> 00:02:24.480]  日本人なのかなっていうか、東洋系の人かなと一瞬思ったんですが、
[00:02:24.480 --> 00:02:28.720]  でも私の考えとしては、外国の方でも誰でも、
[00:02:28.720 --> 00:02:31.960]  あの、今グローブがあれですから、いいと思います。
[00:02:31.960 --> 00:02:32.680]  綺麗な方です。
[00:02:32.680 --> 00:02:33.960]  そうですね。
[00:02:33.960 --> 00:02:37.920]  ミス日本の優勝者であるCのカロリーナさんっていう名前なんですけれども、
[00:02:37.920 --> 00:02:44.200]  あの、先ほども申し上げた通り、日本の血が全く入っていないウクライナ生まれの方でしたと。
[00:02:44.200 --> 00:02:51.080]  そんな彼女が日本を代表、日本代表として、世界的なミスコンに出場することについて、
[00:02:51.080 --> 00:02:53.400]  改めて、どう思われますか?
[00:02:53.400 --> 00:03:02.640]  日本人の血が無いっていうのも、まあ、一つの論争の点ではあるとは思うんですけど、でも、例えば、
[00:03:02.640 --> 00:03:11.000]  日本で育たれてとか、うちの子どもたちも出身は日本ではない、生まれは日本ではないので、
[00:03:11.000 --> 00:03:15.960]  なので、なんかよくその他、出身地その他とかってなっちゃうんですけど、
[00:03:15.960 --> 00:03:22.160]  でも、それもまた一つの個性でもあって、はい、日本ももっともっとこう、
[00:03:22.160 --> 00:03:32.600]  いろいろ受け入れていくことの、あの、一つのこう、最初のステップみたいな大きなステップになればいいかなって私は思います。
[00:03:32.600 --> 00:03:40.600]  パッと見、日本人だとは思わなかったので、なんか、どこの大会なのかなってちょっと思っちゃった。
[00:03:40.600 --> 00:03:45.360]  まあ、まあ、20年以上日本で暮らしてても、まあ、日本人としてはまあ、見難いって言いますか?
[00:03:45.360 --> 00:03:53.200]  いや、心が日本人であれば、同じ教育受けてれば、同じ思想でしょうし、日本人として問題ないと思いますけど。
[00:03:53.200 --> 00:04:02.560]  僕はまあ、一応、日本の、日本人の中でやってるんだったら、純、純日本人じゃないからば、
[00:04:02.560 --> 00:04:10.560]  きれいやけど、その、日本人ではまあ、ないので、それはちょっと違うかなとは思います。
[00:04:10.560 --> 00:04:17.560]  ウクライナ生まれって言いながらも、実は、あの、カロリーナさん、5歳の時に日本に来て、まあ、そっから20年以上日本で暮らし、
[00:04:17.560 --> 00:04:23.560]  まあ、日本語もすごい流暢に話せる方なんですけれども、まあ、これを聞いて、お考えの方は変わったりします?
[00:04:23.560 --> 00:04:41.560]  まあ、日本人、日本に住んでるから日本人なのはわかるんですけど、まあ、まあ、骨格とかが全然違うんで、それはいくら日本にいてもいなくても、日本人ではないんで、そこは変わらないですね。
[00:04:41.560 --> 00:04:45.560]  なるほど、お考えの方は変わらないですね。お友達の意見聞いてどう思います?
[00:04:45.560 --> 00:04:49.560]  侍スピリットを持ってたら、誰でも日本人やなと思いますけどね、はい。
[00:04:49.560 --> 00:05:00.000]  あの、スポーツの世界だったら、例えば、今だったら、日本代表を背負ってても、もうほぼほぼ海外だよねって人が出てると思うんですけど

./models/download-ggml-model.sh large-v3
./main -m models/ggml-base-q5_1.bin -f audio0.wav

ffmpeg -i  "Japanese React To Controversial Miss Japan Winner ｜ Street Interview.mp4" -ab 160k -ac 2 -ar 16000 -vn -f segment -segment_time 300 audio%d.wav


export https_proxy=http://10.90.200.209:7890
export http_proxy=http://10.90.200.209:7890

docker ci/cd pipeline github actions gitlab jekins


ffmpeg -i '0001_Part_1--[TutFlix.ORG]--.mp4' -ab 160k -ac 2 -ar 16000 -vn -f segment -segment_time 100 audio%d.wav

ffmpeg -i C:/test.mp4 -ab 160k -ac 2 -ar 16000 -vn -f segment -segment_time 100 audio%d.wav

sudo trace-bpfcc -UK "do_open" -a


我们每秒对声音采样上万次，获得上万个按照时间顺序排列的二进制数字。于是，我们就将连续变化不断的声音转化成了计算机可储存并识别的二进制数字。
PCM文件：原始采样值的音频数据。 pcm 文件内容不包含频率，位数，以及声道数。要播放pcm文件需要知道采样的频率，位数，以及声道数。

e

ffmpeg -i C:/test.mp4 -ab 160k -ac 2 -ar 44100 -vn -f segment -segment_time 10 audio%d.wav


人声通过空气使震膜振动，
切割形成微弱的波动电流。
电流输送到扩音器，
再以相反的过程把波动电流变成声音。


爱迪生在发明和开发电话的过程中，发现了录音设备。
电容式话筒是利用声音的大小产生忽变的压降然后经过放大到功放还原我们的声音

nc -l 0.0.0.0 1234 > docs.tar.gz
nc 192.168.43.1 1235 < docs.tar.gz

sovle your own problem

solve "researchers'" problem
solve "xxx's" problem

7 washing

注意: 这个系列不会从 print("Hello World") 开始, 毕竟 IO 很难的, 你看 Haskell 教程到什么地方才开始 Hello World.
等介绍到 Hello World 后面也没几页了.

。Snapshot是启动isolate
和context的缓存，⽤于快速启动。⾥⾯也包含了code。

sudo apt install bpfcc-tools

sudo stackcount-bpfcc -i 2 -p 4407 --debug "sock*"

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



ubuntu 22.04 LTS jammy

sudo vim /etc/apt/sources.list

# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse

deb http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse
# deb-src http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse
# # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse

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

what we should do

what we can do
what we know

https://groups.google.com/g/v8-users/search?q=Vyacheslav%20Egorov

sudo stackcount-bpfcc -i 2 -p 10257 --debug "*mprotect*"


rustup update

box2d Deltablue raytrace richards

"two guys in a dorm"

# 2024-3-16 0 | 0

H.264 NALU

ffmpeg -re -i "playlist.txt" -c copy -f flv "rtmp://127.0.0.1/stream/12345678"

https://gitlab.gnome.org/GNOME/gnome-terminal

https://gitlab.gnome.org/GNOME/nautilus/-/issues

sudo rsync --daemon

rsync 192.168.43.246::tmp/projects/mylinux.iso
rsync 192.168.43.95::tmp/projects/distro -r

```conf



```

sudo vim /etc/rsyncd.conf

rsync -r data tannal@192.168.43.246:/home/tannal/tannalwork/projects/postgres/_install/

tar -czvf archive_name.tar.gz directory1 directory2 directory3

about:config

# 2024-3-15 0 | 0

Attension is All you need Ashish Vaswani - Essential AI Noam Shazeer - Character.AI Niki Parmar - Essential AI Llion Jones - Sakana AI

しま 

とても (totemo) 非常

git clone https://github.com/nsqio/nsq
cd nsq
make

https://twitter.com/ID_AA_Carmack

Light Weight Process

1- Spare Renderer

Chromium tries to put each web site in its own process, as much as possible, for security. (The actual rules for how sites are assigned to processes are complicated, because there are a lot of tradeoffs to make between security and performance.) The "spare renderer" is a process that's kept around ready to load a site into, for faster startup.

2- Renderer

This is a process that's currently loaded one or more web sites.

3- utility: storage service

This process manages access to web features that store data on disk (eg. Local Storage, IndexedDB). At least, that's what I assume from the name. I'm not an expert on this.

4- Plugin Broker: Shockwave Flash [ I disabled flash ]

Chrome 88 has Flash removed entirely so I assume when you upgrade to that, this will go away completely. I'm surprised this was loaded with Flash disabled in older versions, but maybe it's normal to keep the broker loaded but just not doing anything.

5- utility: network service

Manages the HTTP stack. When you go to http://example.com, this process will contact the example.com server and fetch the bytes from the net, then pass them off to whichever renderer process handles example.com for parsing.

6- router service

This one I don't know.

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

企鹅影视 tencent
上海阅文影视文化传播有限公司
新丽电视
阿里大文娱


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

CSS Working Group

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

 大部分情况并不需要关心引入哪个头文件，而是保证头文件可以独立编译，即用一个空白CPP只引入一个头文件，也能编译成目标文件。编译器（预处理器）会管理好最被依赖的头文件最先被引入。我们只需要使用好include guard，保证不被重复引入。

table_page 
table_heap memory

acess method intermedia table temp space

20万元人民币的存款证明

如果想把留学签证换成工作签证，本科学历的情况下，只要找到可以接收的公司就行了（你到日本就可以开始转就职了）。语言学校随时可以申请退学。但是有的语言学校就职学费是不退的。所以说，你语言学校转就职很方便，但是学费可能就没了。建议还是找个学费可以半年一交的语言学校，这样损失不大。

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


clang++ -I/home/tannal/tannalwork/projects/v8/v8/ -I/home/tannal/tannalwork/projects/v8/v8/include main.cc -o main -fno-rtti -stdlib=libc++ -nostdinc++ -lv8  -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out/x64.debug/ -L/home/tannal/tannalwork/projects/v8/v8/out.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX -Wl,-rpath=/home/tannal/tannalwork/projects/v8/v8/out/x64.debug/


use_glib=false 


call gn gen out.gn/x64.release --args="is_debug=false use_glib=false is_component_build=true v8_use_external_startup_data=true v8_static_library=false is_clang = false v8_enable_i18n_support=false target_cpu=\"x64\""

这里显然是不一样的。也就是说ndk的libc++实际上更改了命名空间到__ndk这个前缀上，而v8进行编译时使用的libc++是
https://chromium.googlesource.com/chromium/llvm-project/libcxx
二者的命名空间显然是不同的。但为什么我编译使用的是buildtools/third_party/libc++而非thrid_party/android_ndk/cxx-stl/llvm-libc++？这个我还没有答案

clang++ -I/home/tannal/tannalwork/projects/v8/v8/ -I/home/tannal/tannalwork/projects/v8/v8/include main.cc -o main -fno-rtti -stdlib=libc++ -nostdinc++  -lv8  -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out/x64.debug/ -L/home/tannal/tannalwork/projects/v8/v8/out.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX -Wl,-rpath=/home/tannal/tannalwork/projects/v8/v8/out/x64.debug/


https://users.rust-lang.org/

ATA NVME SATA command Byte Block

tools/dev/v8gen.py x64.release.sample
gn args out.gn/x64.release.sample
ninja -C out.gn/x64.release.sample v8_monolith

g++ -I. -Iinclude samples/hello-world.cc -o hello_world -fno-rtti -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -Lout.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX

g++ -I/home/tannal/tannalwork/projects/v8/v8/ -I/home/tannal/tannalwork/projects/v8/v8/include main.cc -o main -fno-rtti -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX

g++ -I/home/tannal/tannalwork/projects/v8/v8/ -I/home/tannal/tannalwork/projects/v8/v8/include main.cc -o main -fno-rtti -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out/x64.debug/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX


g++ -I/home/tannal/tannalwork/projects/v8/v8/ -I/home/tannal/tannalwork/projects/v8/v8/include main.cc -o main -fno-rtti -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out/x64.debug/ -L/home/tannal/tannalwork/projects/v8/v8/out.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX



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

深度学习与NLP
​
在高中毕业后的间隔年里，我曾认真学过编程。我读过图灵的《计算机器与智能》一书，并深受启发：代码能理解那些编写代码者所不能理解的东西。于是我准备着手写一个聊天机器人。那么写出来有多难呢？我想创建的是能与人正常对话的机器人，但找了很久，似乎没有人能做出这种机器人。我很快便搁置了这个想法，转而专注于创建那些能真正产生影响的系统。

1大学研究项目

读大学时，我对编程语言很感兴趣，由此便进入了AI的大门。编译器和静态分析器能“理解”那些我理解不了的程序，于是我便常用其来做一些非常有用的事情，比如快速生成代码并检验其是否正确。我一直想潜下心来去做编程语言研究，却总是受到新的创业点子和新同事的影响。其实我的同事人都还不错，但这些创业想法可就不敢恭维了。无论在哈佛还是麻省理工，我都努力向那些优秀的人看齐，主动融入他们，并与之共建有用的东西。


大三那年，我发现在校创业没有意义，所以我就和那些创业者面谈，汲取经验。与此同时，我终于开始了编程语言研究之旅。我从一位教授那里获得了研究经费，并招募了一些朋友进行静态缓冲超时检测项目。几周后，帕洛阿托（Palo Alto）一家尚未启动的初创公司联系了我。一般情况我会直接删除这种邮件，但此时我也正准备与初创公司会面，所以我们团队就立即点开了邮件，此时我也发现，他们也正是我一直在寻找的那种人。于是我离开学校，这也意味着我们的缓冲超时检测项目就此搁置了。

2

Stripe生涯

那家公司就是现在的Stripe。在我的帮助下，公司规模从4人扩大到了250人；在我离开后的一年里，又继续扩大到了450人（当然，这份功劳与我无关）。此时公司的发展正蒸蒸日上，无论有我没我，都会继续继续做伟大的事情，所以我准备离开Stripe。我想做的是与优秀之人同行做些有意义的事情，但开发者基础架构并不是那个我想穷尽余生之力去解决的问题。然而，我终于还是找到了那个我想解决的问题：创造出安全的人类级别的AI（human-level AI）。只要这项技术能真正为人类所用，我想一定会引起轰动，并给世界带来积极影响。
（Greg Brockman与Sam Altman）

在我最终决定离职之前，Patrick说Sam Altman有很好的局外人视角，而且见过很多跟我情况类似的人，应该能给我一些好的建议，让我去和他谈谈。在与Sam交谈五分钟后，他说：看来你是完全准备好离职了，后续事宜有什么需要我帮助的吗？我说AI是我的首选（这绝对是我的人生目标），但还不确定现在是否就是做这件事的最佳时机，而且我也不知道最佳的贡献方式是什么。他回答：我们一直在考虑通过YC（译者注：Y Combinator，美国著名创业孵化器）建立一个AI实验室，你或许可以跟我们合作。

3

研究深度学习

大约在这一两周后，我就离开了Stripe，开始着手深入研究AI，想要更好地了解该领域正在发生的事情。仅从Hacker News上的帖子（例如http://karpathy.github.io/2015/05/21/rnn-effectiveness/）就可以看出：人们对AI尤其是对深度学习的关注度越来越高。但在进入该领域时，我仍然是持有合理怀疑的，在投身AI之前，我想确定一切都是可行的。我的第一个目标是弄清楚深度学习到底是什么。然而事实证明这并非易事。例如，http://deeplearning.net上只是说“深度学习是机器学习研究的一个新领域，引入深度学习的目的是使其更接近于最初的目标——人工智能”。虽然这听起来很令人兴奋，然而却并没有说清楚到底什么是深度学习。幸运的是，我有一些从事AI行业的朋友：Dario Amodei（曾任OpenAI研究主管，现Anthropic创始人和CEO）和Chris Olah（曾任OpenAI技术主管，现为Anthropic联合创始人）。我向他们征求了一些意见，他们给了我一些很好的入门资源，其中最有用的是Michael Nielsen写的书。我读完后还在Kaggle上练习了新学到的技能（在第一次比赛时我就拿到了第一名！）。一路走来，我不断遇到AI领域中那些超级聪明的人，并与我大学时最聪明的一些朋友重新建立了联系，例如现在在该领域工作的Paul Christiano（曾任OpenAI研究员，现Alignment Research Center创始人）和Jacob Steinhardt（加州伯克利分校助理教授）。我觉得这是一个强烈的信号。我了解得越多，就越相信AI已准备好散发自己的光芒。深度学习的能力简直令人难以置信，比如，我们现在可以极其准确地对图像中的目标进行分类（2014年的XKCD就已经实现），语音识别非常精准，还可以生成十分逼真的图像。不过虽然这些技术足够新，但到现在为止还没有改变人们的生活方式，它们如今的影响还仅限于支持某些产品实现特定功能。有一位朋友曾开发过Facebook News Feed。还记得我曾对他说过这样一句话：简单的算法，大量的数据。每个人都试图兜售很酷的新AI算法，但实际上只需要扩展逻辑回归（logistic regression）就会非常奏效。而他对此持怀疑态度。然后我就拿出了谷歌翻译App，将其设置为飞行模式，并向他演示了如何直接翻译图片上的文字。他对此印象颇深，并承认简单的算法对此无济于事（这背后主要是深度学习在发挥作用，不过这不是重点，重点是它有效。）

4

创业想法诞生

Sam Altman在2015年6月联系我，问我是否已经想好下一步该做什么了，我告诉他目前的计划是明年开一家AI公司。然后我们打了通电话，他提到他们正在推进YC的AI项目。我问：实验室的目的是什么？“建立安全的人类级AI”，他说。在那一刻我就知道，他很适合当我下一家公司的合作伙伴。现在很少有人敢于明确尝试构建人类级AI。我意识到，有时候一项成就只需要有个胆大的人宣布目标，然后合适的人就会加入其中。大约一个月后，Sam在门洛帕克（Menlo Park）举办了一场晚宴，参加宴会的有Dario、Chris、Paul、Ilya Sutskever、Elon Musk、Sam和其他一些人。我们讨论了AI领域的现状、目前离人类级AI还有多远以及实现人类级AI还需要的东西等等。整场对话围绕着“什么样的组织可以最好地确保AI的有益性”展开。答案很明显：必须是非营利组织，因为没有任何利益冲突来影响其使命。此外，这样组织还必须保持在研究的前沿（根据Alan Kay的名言，“预测未来的最好方法就是创造未来”）。为此，该组织需要有世界上最好的AI研究人员。所以问题就变成了：是否有可能从头开始创建一个拥有最优秀AI研究人员的实验室？我们的结论：还是有机会。这是我第一次见到Elon和Ilya，我对他们的印象非常深刻。Elon充满了好奇心，他真诚地征求他人意见并用心倾听每一份回答；而Ilya则是技术基础的源泉，他是一位头脑清晰的技术专家，知识广博，视野开阔，并且总是能够深入到当前系统局限性和功能的具体细节。我请Ilya对深度学习给出一个好的定义，以下是他的回答：有监督深度学习的目标是解决几乎所有“将X映射到Y”形式的问题。X包括图像、语音或文本，Y包括类别甚至句子。将图像映射到类别、将语音映射到文本、将文本映射到类别等等，如此种种，深度学习都是非常有用的，而且其他方法无法做到。深度学习一大吸引人的特点是它在很大程度上是独立于其他领域之外：在一个领域中学到的许多东西可以适用于其他领域。深度学习模型中建立了抽象层，这些抽象可以完成工作，但很难理解它们究竟是如何做到的。模型通过使用反向传播算法（简单且高效）逐渐改变神经网络的突触强度来学习。因此，我们可以用极少的代码来构建出大规模复杂的系统（因为我们只需要编写模型和学习算法的代码，而非最终结果）。晚宴结束后，Sam送我回城里。我们都认同值得在AI领域做点什么。我知道，只有当有人愿意全心全意地弄清楚这究竟是什么，谁又能够加入其中，我们的愿景才会成为现实。那就让我来当这样的人吧。所以，我明天又要构建一些有影响力的东西了。

5

OpenAI的愿景

那次晚宴上，我们谈论了成立OpenAI实验室。虽然每个来参加晚宴的人都各抒己见，但并没有一个清晰的愿景，而Elon和Sam则提出了自己的想法：OpenAI旨在构建安全的人工智能以造福人类。我也想尽可能贡献自己的力量，为了如愿以偿，便开始和Sam一起组建团队。不过我们缺少了一个核心要素，即一位AI技术远见者，其直觉和想法可以帮助我们取得突破。

（从左至右依次为Ilya Sutskever, Alex Krizhevsky, Geoffrey Hinton）

显然，Ilya Sutskever是最佳人选。Ilya可以说是一位艺术家，他常常通过机器学习来表达自己的感受（有时也会通过绘画来表达）。Geoffrey Hinton（深度学习教父）曾告诉我，AlexNet之所以能引发一场计算机视觉深度学习革命，在于Alex Krizhevsky高超的GPU编码技能及Ilya的信念，即深度神经网络必定会在ImageNet竞赛中获胜。（Geoff对自己贡献的管理技巧感到无比自豪。Alex非常讨厌写论文，Geoff告诉他，他在ImageNet上的性能每提高1%，他就可以把论文推迟一周。结果Alex拖延了15周。)一直以来，我都认为自己只能与相识多年的朋友共创公司。然而事实并非如此。八月下旬，我和Ilya在山景城共进晚餐，当时我就知道我们会一起合作，在此之前，我们也只在七月见过一次。我和Ilya聊得十分投机，尽管我对机器学习研究的了解不多，他对工程和团队建设的认识也没有那么深入，但我们对彼此的成就印象十分深刻，也希望能够相互学习。我们交流了彼此的看法、汲取了彼此的长处。Ilya认为，顶级研究人员希望在人工智能组织工作，而该组织致力于为世界创造最佳成果。在我看来，要想解决一些棘手问题，则需将私营企业的资源与学术界的使命相结合。若无外界干预，人工智能将会像自动驾驶汽车一样发挥自身的作用。一旦人工智能的潜力得以证实，人们就会与之展开合作，而后则是一场场技术竞赛。不过，人类级别的人工智能将会是一种与众不同的变革性技术，有其独特的风险和收益。我们看到了这一机遇：在人工智能领域展开合作，汇集众多顶尖研究人员，以取得史上最重大的科技突破。Ilya和我一直在讨论团队组建方案，直到该方案得以落实。期间，我们讨论了战略（即将从事什么工作）、文化（想雇用的人员，即同等重视工程和研究的人员）和策略（举办每日阅读小组）。Alan Kay与我们共进晚餐时，向我们讲述了施乐帕洛阿尔托研究中心（Xerox PARC）的故事，包括Alto的诞生及用硬件“在未来生存”，这些硬件在十年内将花费1000美元。事后，Ilya对用餐期间的谈话做了巧妙总结：“虽然Alan的话我只听懂了一半，但令人振奋不已。不过这顿饭帮我们验证了许多假设，即怎样才能构建一支能将工程与研究相结合的有影响力的团队。

6

早期团队的招募

由于Ilya还在谷歌工作，因此无法帮忙招聘，这一工作就落到了我身上。8月至11月，由我负责创办团队。不过，我对人工智能并不熟悉，不清楚如何招募优秀的研究人员。我首先关注的是7月参加过晚宴的人，但不能确认具体人选。下一步，便是通过人际网络与这些人取得联系，并依次寻求他们的推荐，这与我以往的招聘方式有所不同。对于初创公司而言，首要挑战总是要向候选人“兜售”使命，但在OpenAI，使命立刻引发大家的共鸣。于我而言，挑战在于如何说服候选人相信这个未成形的组织。




人工智能领域顶尖人才的人际网络对我帮助很大。一位朋友引荐我认识Andrej Karpathy和Wojciech Zaremba（OpenAI联合创始人），由于我并未从事该领域工作，他们对我说的话表示怀疑。Yoshua Bengio又将我引荐给Durk Kingma（曾任OpenAI研究科学家，现在谷歌研究团队），当时后者对于我的提议表示很感兴趣，不过这种兴趣转瞬即逝。真正的转折点是John Schulman（OpenAI联合创始人、研究科学家）的评价，我跟他聊到这一组织的成立，他表示这样的组织正是他所追寻的，能将学术界的开放与使命同私企的资源相结合，因此加入了我们。John的支持也引起了Andrej和Wojciech的关注。招聘工程师相对容易一些。Trevor Blackwell是一位机器人专家，也是YC的合伙人，他一直在与Sam讨论我们正在计划的疯狂想法。Vicki Cheung（现Gantry联合创始人）是在我们成立赞助机构“YC Research（现为OpenResearch）”之后申请加入的。那时，我们虽未表明研究领域是AI，但她深受YC Research构架的鼓舞，并表示很乐意参与我们团队的所有工作。11月初，虽然我们对创始团队有了更深入的了解，但仍然需要让大家正式加入进来。在Sam的建议下，我们邀请了所有候选人去户外漫步。期间，人人都真切地表达了内心想法、观点，才思泉涌（实际上，该地也是Andrej提出Universe之地）。回程中，一路上交通堵塞。不过几乎没人留意到这一点，因为大家聊得太投入了。

我们给此次活动的参与者都发了offer，并将offer的截止日期设置为12月1日，这样我们就可以在12月初的NIPS（NeurIPS）机器学习会议上发布成员加入的消息。“月末”就这样开始了。Sam、Elon还有我和每个人都聊了聊，主要是让大家相信这件事的真实性。除了一名完全无意涉足人工智能的工程师外，其他候选人都接受了我们的offer。Fred Brooks在《人月神话》一书中提及了Robert Heinlein的故事，该故事讲述了“登月”项目。该项目的总工程师总会被运营任务分散注意力，例如关于运输车或电话的决策，这种情况一直持续到他收到一份报告，据报告显示不再让他负责所有与技术无关的任务。这一故事给我留下了印象深刻，我认为它同样适用于构建人工智能的项目。技术领导除了做实际技术工作以外，同时还应该亲自做决策。我不知道自己的工程技能何时才能派上用场，不过在此期间，我决定尽我所能帮Ilya分担与研究无关的任务。2016年1月4日，我们整个团队来到第一间办公室（也就是我的公寓）开始工作。讨论中，John和Ilya转身打算在白板上写点些什么，却发现这儿没有白板。我立即给他们买了一块白板，还有一些办公用品。

我们的第一间办公室（配有白板）在一月剩下的时间里，我负责组织团队，帮忙确定哪些人负责哪些工作，以及团队想达成的目标。我们讨论了研究人员需要具备什么品质，践行公司理念，设计并确保面试顺利进行。此外，我们还谈论了愿景、工作方式以及想要达成的目标。我和Vicki购买了服务器，创建了Google Apps帐户，同时对我们12月启动的Kubernetes集群进行了维护。余下的时间，我阅读了Ian Goodfellow（GAN网络发明者）的深度学习书籍（并写下了书评，由于我的评论比其官方评审员的评论更加全面，给他留下了深刻印象。因此，这也不失为一种招聘策略）。

7

Gym库

比起使用新的数据集，使用一种新的算法通常能解决机器学习中的问题，Wojciech建议构建一个库来形成强化学习环境的标准（实际上是动态数据集），现在称之为Gym。这个代码库的质量很快成为我们迭代速度的高阶位（high-order bit）。二月底，我和John讨论了Gym的公开发布时间。按照目前的发展情况，他认为可能要到今年年底才能发布。

（我们正在用机器学习训练Fetch机器人。Gym支持控制物理机器人和模拟机器人。）一时之间，工程学成了研究进展的瓶颈。Ilya与我互换了角色，由他负责行政工作，这样我就可以专注于技术工作。和John考察了这项工作之后，我们知道在四月底之前就能构建好Gym。在Stripe时，我发现了一个能够直接创建软件系统的可重复模式，即专注于软件，排除一切干扰，从早工作到晚。这样一来便能激励大家贡献自己最好的作品（重要的是，是以输出质量来衡量而不是工作时间）。这是我感觉最有活力的时候：编程就如魔法变成现实一般，我所想象和描述的事情都将成为可能。这种模式产生了Stripe信用卡保险库（2010年构建完毕，也就是在我假期回家的两周内完成的）、信用卡授权流程（在三周内就能建成，而银行构建周期却需要6-12个月）和夺旗赛（通常我和其他人都要花三周的时间）。从战术上讲，我可以选择一个“试发行”日期和“正式”发布日期，间隔一两周；我从未选择过“试发行”日期，但从未错过“正式”发布日期。随之而来的是从未面临过的挑战。由于我并非该领域的专家，起初，引起了很多摩擦。我会构造一个抽象的框架来帮助Wojciech的工作顺利进行，而John会发现这一举动阻碍了他的工作进程。但很快，我就了解到哪些决定会影响研究的工作流程（例如人们如何记录指标）以及哪些细节研究人员不会关注（例如人们如何录制视频）。在确定了案例对研究的重要性之后，要保持一定的谦逊，才能做出最佳选择。我通常会提出五个可能的备选方案，John则会指出其中有四个方案都不行。但大多数设计决策可以通过软件工程的直觉做出，而无需深入了解相关领域。幸运的是，我不是一个人。大约在Gym发布的前六周，曾与我在Stripe一起研究CTF 3的Jonas Schneider联系了我。短短几天时间，我们就在Gym上建立了合作关系。因为他人在德国，所以我们通过每日交接最终成功地完成了该项目。对于已经建立好工作关系的人来说，这真的很奇妙，若一切从头开始，我们不会保持如此紧密的工作关系。

（Gym发布后不久，我们在ICLR（国际表征学习大会）上分发OpenAI的T恤。）

总的来说，机器学习系统可视为机器学习的核心之一——通常是一种高级算法，要想理解该算法，至少需要阅读过几章Ian的书——涉及大量软件工程的内容。工程可以围绕数据进行改组，提供输入和输出的封装器，或调度分布式代码，这些都会都以黑盒形式与核心（core）连接。我们在工程和研究方面作出的努力达到一定程度时，机器学习就会取得进步。工程方面每多一分努力（例如减少Universe延迟），我们的模型问题就会逐渐变得更容易，并且有机会完成当前研究。

8

Universe平台




在今年4月Gym上线后，我和Ilya开始调整组织流程。Sam和Elon都会到访公司，提出一些指导意见，我们会根据其指导来确定团队的结构及目标。

（团队在第一间办公室工作的场景。当时办公室有白板，只是图片中未显示。）

多样、复杂的AI环境是必不可少的。Andrej提出了一个不错的建议，即创建一个Agent来控制Web浏览器，但这与Selenium测试工具有所冲突。我开始考虑使用VNC，以允许Agent从像素驱动整个桌面。但我们发现，这种方法存在许多风险。例如，2013年DeepMind发布的Atari文章提出，他们花了50个小时从像素训练Pong游戏，我们的环境将比Pong更难。即使是做小规模的实验，我们也需要花几天时间，而且不会取得任何进展。因此，我们设定了一个降低内部风险的目标，即让Agent在一小时内学会Pong（如今我们已取得了突破：十分钟内便能解决Pong遇到的问题）。就像构建Gym时那样，我专注于构建VNC系统，现称之为Universe。与Gym不同的是，该项目并非旨在支持我们现有的研究方式，而是提出全新的问题。关于这一点，我们每个团队都有负责人，他们负责照顾自身团队的成员，我们的工程师Jie Tang已开始带头招聘。因此，行政这一重担并没有完全落在Ilya身上。这十分幸运，因为这样Ilya就能为该风险项目的首个版本构建Agent。

一个从整个动作空间随机抽样的Universe Agent（即随意点击、按键）。更多表现良好的Agent请参阅Universe发布的帖子。Universe项目耗时相当长，因此，需要合理分配时间来运营项目。我找到了一个平衡点，编码时，我会将时间进行划分。一次会议会扼杀整个上午/下午的生产力，若上午和下午都有会议，我将精疲力竭，从而导致晚间的编码效率大大降低。因此，我开始将会议时间限制在清晨或午餐后，且每天的会议次数低于三次，隔天的会议次数不超过一次。搭建Universe本身就是一项系统研究工作：虽然高级规范很简单（允许Agent使用键盘/鼠标/屏幕），但从来没有人尝试过构建类似的系统。长期以来，人类一直可以用VNC控制一台远程机器，但还无法实现以编程方式同时控制数十台机器。当我们需要衡量系统的端到端延迟时，Catherine Olsson和我构建了一个系统来将时间戳嵌入图像中。有时挑战不是技术上的：当研究因为训练数据有限而受阻时，Tom Brown在24小时内就组建了一个外包团队来玩游戏。有时候挑战也可能很难以理解，比如当Jonathan Gray注意到由于外包人员的笔记本电脑CPU较低端，游戏动态可能会与AI有所不同。一天，当我正在努力重组一些JSON基准规范时，我意识到：我们需要重新构建这些规范，因为没有人从未尝试过在数千个游戏中对单个Agent进行基准测试。在OpenAI，做艰苦的工作也是最基本的。在接下来的几个月里，由Dario Amodei和Rafał Józefowicz负责Universe的研究工作。他们都是夜猫子，我也和他们一起熬过了很多个夜晚，解决研究中遇到的问题。有时我也想躺在床上睡觉，但每修复一个Bug都会使研究加速几个小时。每个人的工作中都有一些非常有用的东西，能让研究人员提出人类此前从未有过的问题。

Universe团队在办公室开会到发布时，Universe团队已经有约20个人了。Universe现在是一个旗舰项目，也是我们研究战略的核心部分。Universe的例子恰好说明“工程”是如何成为当今ML研究的瓶颈，这也让我知道为什么有那么几天只想读Ian的书了。

9

下一步发展方向

我们现在是一个拥有四十人的公司，需要有人全力来优化团队。自OpenAI成立以来，我们一直在寻找合适的首任技术经理。几个月前，Sam向我介绍了一位特别出色的工程执行人：Erika Reinhardt。Erika曾在Planet Labs担任产品工程总监，现在在和Sam一起运营http://voteplz.org。在Planet Labs时，Erika是对端到端卫星成像系统了解最深的人之一。她工作努力，自驱力强，总能把事情做好，前同事都说她是所能遇到的最聪明的人。Sam和我就准备邀请她加入公司。

公司团建，2016年10月但在选举会和Universe发布会上与我们合作时才是她最具魅力的时刻，她发现她的领导技能在这种环境中非常适用。她告诉我：在看到OpenAI在参议院举办的首次AI听证会上发言的那一刻，她就下定决定要加入OpenAI。当时OpenAI说：我们正处于重大技术变革的开端，此时最重要就是要把握时机。

在Stripe时，Marc Hedlund和我常会遇到他在之前的许多公司中都遇到的问题，所以他喜欢开玩笑说所有公司都一样。就这一点而言，确实有现实依据：如果将范围缩小一点，就会发现公司都是围绕一个目标来把人组织起来。但每个公司要解决的问题又不一样，这又决定了公司之间会有所差异。大多数初创公司都是先创造出一种技术，然后随着时间的推移对其进行运营和扩展。OpenAI是创造新技术的工厂，这意味着我们必须构建公司来创造新事物。我们需要维护基础设施和大型代码库，但它们又满足了我们快速行动、创新和通过结合软件工程和机器学习研究来达到新高度的需求。在OpenAI当CTO的这段时光里，我做的正好是我最喜欢做的事：写代码。但即便如此，人仍然是我关注的焦点，所以我在OpenAI的故事是与社会的故事，而不是与技术的故事。

在未来，我们团队要继续携手并进，共同应对海因莱因短篇小说中“卡车或电话”的挑战，OpenAI才能持续发展。在此，我向Ilya、Sam、Elon以及为OpenAI付出过的每一个人表示衷心的感谢。

发布于 2023-03-17 20:19
​
赞同 30​
​
添加评论
​
分享
​
收藏
​
喜欢
​
收起​

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

sudo apt update
sudo apt install --reinstall build-essential libc6-dev libc6
sudo ninja install
sudo apt install mesa-utils
glxinfo | grep "OpenGL renderer"
getrandom v0.2.12
bytes v1.5.0
textwrap v0.11.0
tokio-rustls v0.24.1
subtle v2.5.0
futures-task v0.3.30
sentry v0.26.0
rustc-hash v1.1.0
futures-macro v0.3.30
glob v0.3.1
fslock v0.2.1
httparse v1.8.0
thread_local v1.1.8
async-stream v0.3.5
time-core v0.1.2
proc-macro-error-attr v1.0.4
peeking_take_while v0.1.2
tinyvec_macros v0.1.1
tinyvec v1.6.0
adler v1.0.2
powerfmt v0.2.0
tokio-stream v0.1.14
try-lock v0.2.5
openssl-macros v0.1.1
atty v0.2.14
sentry-panic v0.26.0
trackable_derive v1.0.0
alloc-stdlib v0.2.2
foreign-types-macros v0.2.3
rand_chacha v0.3.1
cmake v0.1.50
trackable v1.3.0
slab v0.4.9
signal-hook-registry v1.4.1
alloc-no-stdlib v2.0.4
generic-array v0.14.7
rand_core v0.6.4
futures-sink v0.3.30
form_urlencoded v1.2.1
crossbeam-queue v0.3.11
tokio-test v0.4.3
async-trait v0.1.77
ansi_term v0.12.1
async-compression v0.4.6
clang-sys v1.7.0
clap v2.34.0
bitflags v2.4.2
memchr v2.7.1
ipnet v2.9.0
tracing v0.1.40
indexmap v2.2.5
http v0.2.12
vcpkg v0.2.15
daemonize v0.5.0
crypto-common v0.1.6
url v2.5.0
vec_map v0.8.2
uuid v1.7.0
tokio-openssl v0.6.4
crc32fast v1.4.0
arrayvec v0.7.4
cexpr v0.6.0
hashbrown v0.12.3
h2 v0.4.2
memoffset v0.6.5
digest v0.10.7
miniz_oxide v0.7.2
h2 v0.3.24
unicode-segmentation v1.11.0
unicode-normalization v0.1.23
hashbrown v0.14.3
boring v4.5.0
gimli v0.28.1
semver v1.0.22
time v0.3.34
aho-corasick v1.1.2
futures-util v0.3.30
bitflags v1.3.2
scopeguard v1.2.0
untrusted v0.9.0
sct v0.7.1
tokio v1.36.0
sfv v0.9.4
nix v0.24.3
version_check v0.9.4
brotli-decompressor v2.5.1
yaml-rust v0.4.5
linked-hash-map v0.5.6
equivalent v1.0.1
thrift_codec v0.1.1
sentry-backtrace v0.26.0
sentry-core v0.26.0
tokio-macros v2.2.0
seize v0.2.5
brotli v3.4.0
autocfg v1.1.0
zstd v0.9.2+zstd.1.5.1
sentry-types v0.26.0
rustracing_jaeger v0.7.0
want v0.3.1
async-stream-impl v0.3.5
uname v0.1.1
openssl-probe v0.1.5
data-encoding v2.5.0
debugid v0.8.0
serde_derive v1.0.197
tower-service v0.3.2
deranged v0.3.11
fnv v1.0.7
mime v0.3.17
mio v0.8.11
foreign-types v0.3.2
futures-core v0.3.30
byteorder v1.5.0
num-conv v0.1.0
hex v0.4.3
block-buffer v0.10.4
futures-io v0.3.30
log v0.4.21
webpki-roots v0.25.4
httpdate v1.0.3
rmp-serde v1.1.2
parking_lot_core v0.9.9
minimal-lexical v0.2.1
ring v0.17.8
pin-utils v0.1.0
num_cpus v1.16.0
zerocopy v0.7.32
lazycell v1.3.0
foreign-types-shared v0.1.1
lock_api v0.4.11
pin-project-lite v0.2.13
parking_lot v0.12.1
protobuf v2.28.0
openssl-sys v0.9.101
percent-encoding v2.3.1
object v0.32.2
boring-sys v4.5.0
rustc_version v0.4.0
rustc-demangle v0.1.23
rust_decimal v1.34.3
rmp v0.8.12
base64 v0.21.7
regex v1.10.3
allocator-api2 v0.2.16
zstd-sys v1.6.2+zstd.1.5.1
regex-syntax v0.8.2
rustls-pemfile v1.0.4
ahash v0.8.11
match_cfg v0.1.0
lru v0.12.3
libloading v0.8.3
indexmap v1.9.3
hyper-rustls v0.24.2
hostname v0.3.1
rand v0.8.5
proc-macro-error v1.0.4
pkg-config v0.3.30
paste v1.0.14
num-traits v0.2.18
nom v7.1.3
encoding_rs v0.8.33
rustls v0.21.10
rustls-webpki v0.101.7
reqwest v0.11.25
jobserver v0.1.28
heck v0.3.3
openssl v0.10.64
arc-swap v1.7.0
regex-automata v0.4.6
trackable v0.2.24
unicode-bidi v0.3.15
unicase v2.7.0
serde_urlencoded v0.7.1
unicode-width v0.1.11
tracing-core v0.1.32
tokio-util v0.7.10
flurry v0.4.0
libz-ng-sys v1.1.15
openssl-src v300.2.3+3.2.1
http-body v0.4.6
fs_extra v1.3.0
typenum v1.17.0
flate2 v1.0.28
http v1.1.0
bindgen v0.68.1
hyper v0.14.28
strsim v0.8.0
serde_yaml v0.8.26
spin v0.9.8
shlex v1.3.0
rustracing v0.5.1
socket2 v0.5.6
syn v1.0.109
structopt v0.3.26
prometheus v0.13.3
zstd-safe v4.1.3+zstd.1.5.1
blake2 v0.10.6
cc v1.0.90
crossbeam-channel v0.5.12
crossbeam-utils v0.8.19
sentry-contexts v0.26.0
structopt-derive v0.4.18
addr2line v0.21.0
idna v0.5.0
sync_wrapper v0.1.2
futures v0.3.30
lazy_static v1.4.0
foreign-types-shared v0.3.1
foreign-types v0.5.0
futures-channel v0.3.30
futures-executor v0.3.30
backtrace v0.3.69
ahash v0.7.8
chrono v0.4.35
time-macros v0.2.17

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

```bash
libarchive 3.7.2

    regex support: glibc

mesa 24.1.0-devel

  Directories
    prefix                       : /usr/local
    libdir                       : lib/aarch64-linux-gnu
    includedir                   : include

  Common C and C++ arguments
    c_cpp_args                   :

  OpenGL
    OpenGL                       : YES
    ES1                          : YES
    ES2                          : YES
    Shared glapi                 : YES
    GLVND                        : NO

  DRI
    Platform                     : drm
    Driver dir                   : /usr/local/lib/aarch64-linux-gnu/dri

  GLX
    Enabled                      : YES
    Provider                     : dri

  EGL
    Enabled                      : YES
    Drivers                      : builtin:egl_dri2 builtin:egl_dri3
    Platforms                    : x11 wayland surfaceless drm xcb

  GBM
    Enabled                      : YES
    Backends path                : /usr/local/lib/aarch64-linux-gnu/gbm

  Vulkan
    Drivers                      : swrast intel
    Platforms                    : x11 wayland surfaceless drm xcb
    ICD dir                      : share/vulkan/icd.d
    Intel Ray tracing            : NO

  Video
    Codecs                       : av1dec av1enc vp9dec
    APIs                         : vulkan xa

  LLVM
    Enabled                      : YES
    Version                      : 16.0.6

  Gallium
    Enabled                      : YES
    Drivers                      : v3d vc4 freedreno etnaviv nouveau svga tegra
                                   virgl lima panfrost swrast iris zink
    Platforms                    : x11 wayland surfaceless drm xcb
    Frontends                    : mesa xa
    Off-screen rendering (OSMesa): NO
    HUD lm-sensors               : NO

  Perfetto
    Enabled                      : NO

  Teflon (TensorFlow Lite delegate)
    Enabled                      : NO

  Subprojects
    libarchive                   : YES
    lua                          : YES
    wayland-protocols            : YES

Found ninja-1.11.1 at /usr/bin/ninja
```

pip install meson -i https://mirrors.sustech.edu.cn/pypi/web/simple


https://github.com/ValveSoftware

sudo apt-get update

git clone https://gitlab.freedesktop.org/mesa/mesa.git
sudo apt install glslang-tools libclc-17-dev libdrm-dev libllvmspirvlib-16-dev libclang-dev libwayland-dev libwayland-egl-backend-dev libx11-dev libxext-dev libxfixes-dev

sudo apt install libx11-dev libxext-dev libxfixes-dev libx11-xcb-dev libxcb-keysyms1-dev libxcb-glx0-dev libxcb-dri2-0-dev libxcb-dri3-dev libxcb-present-dev libxcb-sync-dev libxcb-xfixes0-dev libxshmfence-dev libxxf86vm-dev libxrandr-dev

sudo apt install zypper
sudo zypper source-install --build-deps-only Mesa

glxinfo
glxgears


```bash
tannal@desktop:~/tannalwork/projects/v8/v8$ glxinfo | grep "OpenGL renderer"

OpenGL renderer string: AMD Radeon RX 460 Graphics (polaris11, LLVM 15.0.7, DRM 3.49, 6.2.0-39-generic)
```

```bash
tannal@desktop:~/tannalwork/projects/v8/v8$ lsmod | grep -i "amdgpu"
amdgpu              14540800  44
iommu_v2               24576  1 amdgpu
drm_buddy              20480  1 amdgpu
gpu_sched              61440  1 amdgpu
drm_ttm_helper         16384  1 amdgpu
ttm                   110592  2 amdgpu,drm_ttm_helper
drm_display_helper    212992  1 amdgpu
drm_kms_helper        249856  4 drm_display_helper,amdgpu
i2c_algo_bit           16384  1 amdgpu
drm                   700416  21 gpu_sched,drm_kms_helper,drm_display_helper,drm_buddy,amdgpu,drm_ttm_helper,ttm
video                  73728  2 asus_wmi,amdgpu

not open source
```



vkQueueSubmit
libvulkan.so
gdb ./build/bin/ssao

vkQueueSubmit

devices


rsync -r out/arm64.debug tannal@192.168.43.246:/home/tannal/tannalwork/projects/


queueMicrotask(() => console.log(2));

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

Enterprise Focus: Netscape Enterprise Server was developed by Netscape Communications Corporation. It was designed with an enterprise focus, aiming to meet the demands of large-scale websites and applications.
Dynamic Content: Netscape Enterprise Server supported dynamic content through technologies like Server-Side JavaScript (SSJS) and server-side includes (SSI).
CERN HTTPd:

Early Pioneer: CERN HTTPd, developed at CERN (European Organization for Nuclear Research), was one of the earliest web servers. It played a crucial role in the early development of the World Wide Web.
Single-Process Model: CERN HTTPd used a single-process, single-threaded model, handling one request at a time. While it was a simple and lightweight server, it had limitations in terms of scalability.

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

wasm-bindgen-shared v0.2.91
wasm-bindgen-macro v0.2.91
gloo-utils v0.2.0
smallstr v0.3.0
wasm-bindgen-backend v0.2.91
ppv-lite86 v0.2.17
wasm-bindgen-macro-support v0.2.91
atomic_refcell v0.1.13
thiserror v1.0.56
quote v1.0.35
getrandom v0.1.16
log v0.4.20
proc-macro2 v1.0.78
thiserror-impl v1.0.56
js-sys v0.3.68
serde_derive v1.0.196
serde_json v1.0.113
serde v1.0.196
syn v2.0.48
console_error_panic_hook v0.1.7
wasm-bindgen v0.2.91
libc v0.2.153
web-sys v0.3.68
unicode-ident v1.0.12
smallvec v1.13.1
ryu v1.0.16
rand_core v0.5.1
rand v0.7.3
once_cell v1.19.0
itoa v1.0.10
cfg-if v1.0.0
bumpalo v3.14.0
rand_chacha v0.2.2
arc-swap v1.6.0

sudo systemctl daemon-reload
sudo systemctl restart y-websocket

sudo vim /etc/systemd/system/y-websocket.service
[Unit]
# 服务名称，可自定义
Description = docs

[Service]
Type = simple
WorkingDirectory=/home/tannal/tannalwork/projects/yjs-demos/
ExecStart = /bin/bash -c 'PATH=/home/tannal/.nvm/versions/node/v20.11.1/bin/:$PATH pnpm start'
Restart=always

[Install]
WantedBy = multi-user.target


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

SOSP - Symposium on Operating Systems Principles
OSDI - Symposium on Operating Systems Design and Implementation
NSDI - Network Systems Design and Implementation
FAST - Conference on File and Storage Technologies
ASPLOS - Architectural Support for Programming Languages and Operating Systems
ATC - USENIX Annual Technical Conference
EuroSys
SIGCOMM - Computer Communication
SIGMETRICS - Computer/communication system performance
ISCA - International Symposium on Computer Architecture
HotOS - Hot Topics in Operating Systems Workshop
IEEE S&P - Security & Privacy
Usenix Security
ACM CCS - Computer and Communications Security


tannal@raspi:~/tannalwork/cans$ ls /dev/fuse 
/dev/fuse
tannal@raspi:~/tannalwork/cans$ lsmod | grep fuse
fuse                  159744  5
tannal@raspi:~/tannalwork/cans$

https://www.cnblogs.com/pdev/category/1510614.html

export https_proxy=http://10.90.143.252:7890
export http_proxy=http://10.90.143.252:7890

watch -d -n 0.5 nvidia-smi

web
GUI toolkit QT GTK & 3d rendering & Graphics & browser
window API glfw winit 
window system
drm
driver
hardware

https://github.com/pentium3/sys_reading

从动作中学习”（比如某个参数从小调到大）


libgobject

```

#2  0x00007ffff6b4dccd in g_thread_new () at /lib/x86_64-linux-gnu/libglib-2.0.so.0
#3  0x00007ffff6c73f2f in  () at /lib/x86_64-linux-gnu/libpangoft2-1.0.so.0
#4  0x00007ffff7f79f83 in g_type_create_instance () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#5  0x00007ffff7f610ed in  () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#6  0x00007ffff7f6234d in g_object_new_with_properties () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#7  0x00007ffff7f62e51 in g_object_new () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#8  0x00007ffff742134d in pango_cairo_font_map_get_default () at /lib/x86_64-linux-gnu/libpangocairo-1.0.so.0
#9  0x00007ffff7e7be2a in gdk_pango_context_get_for_screen () at /lib/x86_64-linux-gnu/libgdk-3.so.0
#10 0x00007ffff79a6ad5 in gtk_widget_create_pango_context () at /lib/x86_64-linux-gnu/libgtk-3.so.0
#11 0x00007ffff79a6bb0 in gtk_widget_get_pango_context () at /lib/x86_64-linux-gnu/libgtk-3.so.0
#12 0x00007ffff79a6c1e in gtk_widget_create_pango_layout () at /lib/x86_64-linux-gnu/libgtk-3.so.0
#13 0x00007ffff77babf7 in  () at /lib/x86_64-linux-gnu/libgtk-3.so.0
#14 0x00007ffff77bb0e8 in  () at /lib/x86_64-linux-gnu/libgtk-3.so.0
#15 0x00007ffff7f79fba in g_type_create_instance () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#16 0x00007ffff7f610ed in  () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#17 0x00007ffff7f6234d in g_object_new_with_properties () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#18 0x00007ffff7f62e51 in g_object_new () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#19 0x000055555555627d in activate (app=0x5555555720f0, user_data=0x0) at gtk.c:35
#20 0x00007ffff7f50d2f in g_closure_invoke () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#21 0x00007ffff7f6cc36 in  () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#22 0x00007ffff7f6e614 in g_signal_emit_valist () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#23 0x00007ffff7f6e863 in g_signal_emit () at /lib/x86_64-linux-gnu/libgobject-2.0.so.0
#24 0x00007ffff7507d68 in  () at /lib/x86_64-linux-gnu/libgio-2.0.so.0
#25 0x00007ffff7507f46 in g_application_run () at /lib/x86_64-linux-gnu/libgio-2.0.so.0
#26 0x000055555555659e in main (argc=1, argv=0x7fffffffdb38) at gtk.c:84

```

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

中国2月CPI同比数据

中国2月PPI同比数据

中国2月M0/ M1/ M2货币供应同比

中国2月社会融资规模增量(亿元人民币)

中国2月新增人民币贷款(亿元人民币)

nmap -sV -p- -T5 10.90.163.134

inet 10.68.136.133  netmask 255.255.255.128  broadcast 10.68.136.255

nmap -A -T4

nmap -sP 10.68.136.0/24  

export https_proxy=http://10.90.163.134:7890
export http_proxy=http://10.90.163.134:7890

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


vim /etc/conf/rsyncd.conf

```conf

### rsyncd.conf 文件的配置
[root@50_125 rsync]# vim rsyncd.conf
# /etc/rsyncd: configuration file for rsync daemon mode
# See rsyncd.conf man page for more options.
# 传输文件使用的用户和用户组，如果是从服务器=>客户端，要保证www用户对文件有读取的权限；如果是从客户端=>服务端，要保证www对文件有写权限。
uid = www
gid = www
# 允许chroot，提升安全性，客户端连接模块，首先chroot到模块path参数指定的目录下，chroot为yes时必须使用root权限，且不能备份path路径外的链接文件
use chroot = yes
# 只读
read only = no
# 只写
write only = no
# 设定白名单，可以指定IP段（172.18.50.1/255.255.255.0）,各个Ip段用空格分开
hosts allow = 172.18.50.110 172.18.50.111
hosts deny = *
# 允许的客户端最大连接数
max connections = 4
# 欢迎文件的路径，非必须
motd file = /etc/rsync/rsyncd.motd
# pid文件路径
pid file = /var/run/rsyncd.pid
# 记录传输文件日志
transfer logging = yes
# 日志文件格式
log format = %t %a %m %f %b
# 指定日志文件
log file = /var/log/rsync.log
# 剔除某些文件或目录，不同步
exclude = lost+found/
# 设置超时时间
timeout = 900
ignore nonreadable = yes
# 设置不需要压缩的文件
dont compress   = *.gz *.tgz *.zip *.z *.Z *.rpm *.deb *.bz2

# 模块，可以配置多个，使用如: sate@172.18.50.125::125to110
[125to110]
# 模块的根目录，同步目录，要注意权限
path = /tmp/nginx
# 是否允许列出模块内容
list = no
# 忽略错误
ignore errors
# 添加注释
comment = ftp export area
# 模块验证的用户名称，可使用空格或者逗号隔开多个用户名
auth users = sate
# 模块验证密码文件 可放在全局配置里
secrets file = /etc/rsync/rsyncd.secrets
# 剔除某些文件或目录，不同步
exclude = lost+found/ conf/ man/

```

pip install torch==2.0.0
pip install torchvision==0.14


```bash

(venv) [root@g08 starcoder2]# nvidia-smi
Thu Mar  7 20:29:37 2024       
+-----------------------------------------------------------------------------+
| NVIDIA-SMI 520.61.07    Driver Version: 520.61.07    CUDA Version: 11.8     |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
|                               |                      |               MIG M. |
|===============================+======================+======================|
|   0  NVIDIA GeForce ...  On   | 00000000:51:00.0 Off |                  Off |
| 30%   28C    P8    22W / 450W |      1MiB / 24564MiB |      0%      Default |
|                               |                      |                  N/A |
+-------------------------------+----------------------+----------------------+
                                                                               
+-----------------------------------------------------------------------------+
| Processes:                                                                  |
|  GPU   GI   CI        PID   Type   Process name                  GPU Memory |
|        ID   ID                                                   Usage      |
|=============================================================================|
|  No running processes found                                                 |
+-----------------------------------------------------------------------------+

```

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

export https_proxy=http://10.90.115.200:7890
export http_proxy=http://10.90.115.200:7890

git clone https://www.github.com/

pip install git+https://github.com/huggingface/transformers.git

python3 -m pip install virtualenv
virtualenv venv python=python3.11

export HF_TOKEN=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


const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
});

const inspector = require('inspector');

const debug = inspector.url() !== undefined

console.debug = (...args) => {
    if (debug) {
        console.log(...args)
    }
}

class Trie {
    constructor() {
        this.root = {}
    }

    insert(word) {
        let node = this.root
        for (let c of word) {
            if (!node[c]) {
                node[c] = {}
            }
            node = node[c]
        }
        // node['*'] = true
        node.count = (node.count || 0) + 1
    }

    search(word) {
        let node = this.root
        for (let c of word) {
            console.debug(node)
            if (!node[c]) {
                return false
            }
            node = node[c]
        }
        return node.count !== undefined
    }

    countPrefixes(prefix) {
        let node = this.root
        let count = 0
        for (let c of prefix) {
            console.debug(node)
            if (!node[c]) {
                return 0
            }
            count += node[c].count || 0
            node = node[c]
        }
        return count
    }
}

// Given N strings S1, S2…SN, then there will be M queries. For each query, a string T is given, and the task is to find out how many strings among S1 to SN are prefixes of T. The total length of the input strings does not exceed 106 and consists only of lowercase letters.
// A string S1 (let's assume its length is n) is called a prefix of another string S2 if and only if: the length of S2 is not less than n, and the string formed by the first n characters of S2 is completely identical to S1.
function solve(/** @type {string[]} */ players,/**@type {string[]} */ qeurys) {
    // console.debug(players, qeurys)
    const trie = new Trie();
    players.forEach(player => trie.insert(player));
    return qeurys.map(query => trie.countPrefixes(query)).join('\n');
}


// Given N strings S1, S2…SN, then there will be M queries. For each query, a string T is given, and the task is to find out how many strings among S1 to SN are prefixes of T. The total length of the input strings does not exceed 106 and consists only of lowercase letters.
// A string S1 (let's assume its length is n) is called a prefix of another string S2 if and only if: the length of S2 is not less than n, and the string formed by the first n characters of S2 is completely identical to S1.
// input
// 3 2
// ab
// bc
// abc
// abc
// efg
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

http.HandleFunc("/share", shareHandler(db))


func shareHandler(db *sql.DB) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		// Set CORS headers for the preflight request
		if r.Method == http.MethodOptions {
			w.Header().Set("Access-Control-Allow-Origin", "*")
			w.Header().Set("Access-Control-Allow-Methods", "GET")
			w.WriteHeader(http.StatusOK)
			return
		}

		// Set CORS headers for the main request
		w.Header().Set("Access-Control-Allow-Origin", "*")

		// get the share url from the request
		shareURL := r.URL.Query().Get("url")

		// Get the data from the OpenAI chat page
		client := &http.Client{}
		req, err := http.NewRequest("GET", shareURL, nil)
		if err != nil {
			log.Fatal(err)
		}
		resp, err := client.Do(req)
		if err != nil {
			log.Fatal(err)
		}
		defer resp.Body.Close()
		body, err := io.ReadAll(resp.Body)
		if err != nil {
			log.Fatal(err)
		}

		html := string(body)

		start := strings.LastIndex(html, ">{")

		end := strings.LastIndex(html, "}</script>")

		data := html[start+1 : end+1]

		var response Response
		err = json.Unmarshal([]byte(data), &response)
		if err != nil {
			panic(err)
		}

		var query string
		var answer string

		for i, linearConversation := range response.Props.PageProps.ServerResponse.Data.LinearConversation {
			for _, part := range response.Props.PageProps.ServerResponse.Data.Mapping[linearConversation.Id].Message.Content.Parts {
				if i%2 == 0 {
					query = part
				} else {
					answer = part
					fmt.Println(query, answer)
				}
			}
		}

		// Insert the data into the database
		if err := insertData(db, query, answer); err != nil {
			http.Error(w, err.Error(), http.StatusInternalServerError)
			return
		}

		// Send the data as the HTTP response
		w.Header().Set("Content-Type", "application/json")
		json.NewEncoder(w).Encode(data)
	}
}

package main

type Response struct {
	Props Props `json:"props"`
}

type Props struct {
	PageProps PageProps `json:"pageProps"`
}

type PageProps struct {
	ServerPrimedAllowBrowserStorageValue bool           `json:"serverPrimedAllowBrowserStorageValue"`
	IsStorageComplianceEnabled           bool           `json:"isStorageComplianceEnabled"`
	SharedConversationId                 string         `json:"sharedConversationId"`
	ServerResponse                       ServerResponse `json:"serverResponse"`
}

type ServerResponse struct {
	Type string `json:"type"`
	Data Data   `json:"data"`
}
type Data struct {
	Title                   string               `json:"title"`
	CreateTime              float64              `json:"create_time"`
	UpdateTime              float64              `json:"update_time"`
	Mapping                 map[string]Mapping   `json:"mapping"`
	ModerationResults       []interface{}        `json:"moderation_results"`
	CurrentNode             string               `json:"current_node"`
	ConversationId          string               `json:"conversation_id"`
	IsArchived              bool                 `json:"is_archived"`
	SafeUrls                []interface{}        `json:"safe_urls"`
	IsPublic                bool                 `json:"is_public"`
	LinearConversation      []LinearConversation `json:"linear_conversation"`
	HasUserEditableContext  bool                 `json:"has_user_editable_context"`
	ContinueConversationUrl string               `json:"continue_conversation_url"`
	Model                   Model                `json:"model"`
	ModerationState         ModerationState      `json:"moderation_state"`
}

type LinearConversation struct {
	Id       string   `json:"id"`
	Children []string `json:"children"`
}
type Model struct {
	Slug      string `json:"slug"`
	MaxTokens int    `json:"max_tokens"`
	Title     string `json:"title"`
}
type ModerationState struct {
	HasBeenModerated     bool `json:"has_been_moderated"`
	HasBeenBlocked       bool `json:"has_been_blocked"`
	HasBeenAccepted      bool `json:"has_been_accepted"`
	HasBeenAutoBlocked   bool `json:"has_been_auto_blocked"`
	HasBeenAutoModerated bool `json:"has_been_auto_moderated"`
}

type Mapping struct {
	Id       string   `json:"id"`
	Message  Message  `json:"message"`
	Parent   string   `json:"parent"`
	Children []string `json:"children"`
}

type Message struct {
	Id         string   `json:"id"`
	Author     Author   `json:"author"`
	CreateTime float64  `json:"create_time"`
	Content    Content  `json:"content"`
	Status     string   `json:"status"`
	Weight     int      `json:"weight"`
	Metadata   Metadata `json:"metadata"`
	Recipient  string   `json:"recipient"`
}

type Author struct {
	Role     string   `json:"role"`
	Metadata struct{} `json:"metadata"`
}

type Content struct {
	ContentType string   `json:"content_type"`
	Parts       []string `json:"parts"`
}

type Metadata struct {
	FinishDetails struct {
		Type       string `json:"type"`
		StopTokens []int  `json:"stop_tokens"`
	} `json:"finish_details"`
	Citations            []interface{} `json:"citations"`
	IsComplete           bool          `json:"is_complete"`
	ModelSlug            string        `json:"model_slug"`
	ParentId             string        `json:"parent_id"`
	RequestId            string        `json:"request_id"`
	Timestamp            string        `json:"timestamp_"`
	SharedConversationId string        `json:"shared_conversation_id"`
}



# 2024-3-6 | W


set debuginfod enabled on

sudo systemctl enable yjs.service



Every one says no way until you actually did it.

{
  content: [
    {
      query: '',
      answer: '',
    },
    {
      query: '',
      answer: '',
    },
  ]
}

CREATE TABLE chat (
  id INT PRIMARY KEY AUTO_INCREMENT,
  query TEXT,
  answer TEXT
);


interface Content {
  query: string;
  answer: string;
}

interface DataType {
  content: Content[];
}


{
  content: [
    {
      query: '',
      answer: '',
    },
    {
      query: '',
      answer: '',
    },
  ]
}

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

sudo systemctl daemon-reload
sudo systemctl restart yjs.service

systemctl status yjs.service
sudo journalctl -u yjs

sudo vim /etc/systemd/system/yjs.service

[Unit]
# 服务名称，可自定义
Description = docs

[Service]
Type = simple
WorkingDirectory=/home/tannal/tannalwork/projects/yjs-demos/
ExecStart = /bin/bash -c 'PATH=/home/tannal/.nvm/versions/node/v20.11.1/bin/:$PATH pnpm start'
Restart=always

[Install]
WantedBy = multi-user.target



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

edge case
tipical case


で(de)

チャットボット(chattobotto)

れ(re )
た(ta )
さ(sa )

によって(ni yotte by)
は(wa 是)

によって(ni yotte)

た(ta)


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

について (ni tsui te) 关于
調べ (shi ra be) 调查

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

block
threads
registers
shared memory

global memory

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

300000



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

@tencent - This is likely related to Tencent, a major Chinese technology company. The "@" prefix suggests that this could be a namespaced package, possibly from a package manager like npm (Node Package Manager) for JavaScript.

leveldown - This is typically associated with a low-level database binding for LevelDB, which is a fast key-value storage library written at Google that provides an ordered mapping from string keys to string values.

sqlite3
win-version-info - This directory could contain a library for retrieving Windows version information from an executable file in Node.js applications.

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


Lint is the computer science term for a static code analysis tool used to flag programming errors, bugs, stylistic errors and suspicious constructs. The term originates from a Unix utility that examined C language source code
Static Code Analysis tool is the analysis of computer programs performed without executing them
Dynamic Code Analysis on the other hand is performed during execution of the program (like Sanitizers, Code Coverage, Valgrind etc)


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

interface HTMLInputElement : HTMLElement {
  [HTMLConstructor] constructor();

  [CEReactions] attribute DOMString accept;
  [CEReactions] attribute DOMString alt;
  [CEReactions] attribute DOMString autocomplete;
  [CEReactions] attribute boolean defaultChecked;
  attribute boolean checked;
  [CEReactions] attribute DOMString dirName;
  [CEReactions] attribute boolean disabled;
  readonly attribute HTMLFormElement? form;
  attribute FileList? files;
  [CEReactions] attribute USVString formAction;
  [CEReactions] attribute DOMString formEnctype;
  [CEReactions] attribute DOMString formMethod;
  [CEReactions] attribute boolean formNoValidate;
  [CEReactions] attribute DOMString formTarget;
  [CEReactions] attribute unsigned long height;
  attribute boolean indeterminate;
  readonly attribute HTMLDataListElement? list;
  [CEReactions] attribute DOMString max;
  [CEReactions] attribute long maxLength;
  [CEReactions] attribute DOMString min;
  [CEReactions] attribute long minLength;
  [CEReactions] attribute boolean multiple;
  [CEReactions] attribute DOMString name;
  [CEReactions] attribute DOMString pattern;
  [CEReactions] attribute DOMString placeholder;
  [CEReactions] attribute boolean readOnly;
  [CEReactions] attribute boolean required;
  [CEReactions] attribute unsigned long size;
  [CEReactions] attribute USVString src;
  [CEReactions] attribute DOMString step;
  [CEReactions] attribute DOMString type;
  [CEReactions] attribute DOMString defaultValue;
  [CEReactions] attribute [LegacyNullToEmptyString] DOMString value;
  attribute object? valueAsDate;
  attribute unrestricted double valueAsNumber;
  [CEReactions] attribute unsigned long width;

  undefined stepUp(optional long n = 1);
  undefined stepDown(optional long n = 1);

  readonly attribute boolean willValidate;
  readonly attribute ValidityState validity;
  readonly attribute DOMString validationMessage;
  boolean checkValidity();
  boolean reportValidity();
  undefined setCustomValidity(DOMString error);

  readonly attribute NodeList? labels;

  undefined select();
  attribute unsigned long? selectionStart;
  attribute unsigned long? selectionEnd;
  attribute DOMString? selectionDirection;
  undefined setRangeText(DOMString replacement);
  undefined setRangeText(DOMString replacement, unsigned long start, unsigned long end, optional SelectionMode selectionMode = "preserve");
  undefined setSelectionRange(unsigned long start, unsigned long end, optional DOMString direction);

  undefined showPicker();

  // also has obsolete members
};


HTMLInputElement includes PopoverInvokerElement;

$env:PATH = "C:\Users\tannal\Downloads\LLVM-16.0.6-win64\lib\" + $env:PATH


http://ollehost.dk/blog/

https://github.com/bitshifter

https://github.com/SuperAuguste
https://github.com/rust-lang/rust/commits/master/
https://github.com/paperdave

C コード(ko-do)　と(to)　それに　対応　する　アセンブリ　コード　お　比較　して　みましょう

C　コンパイラ(konpaira compiler)　が(ga)　どの(dono)　よう(yo)　な(na)　出力(Shutsuryoku)　お(o) 生成(seisei)

して(shite)　いる(lru)　の(no)　か(ka)　と(to)　いう(lu)　イメージ(Imeji image)　お(o)　掴む(Tsukamu)

ため(tame)　に(ni)

簡単(kantan)　な例(narei 例子)

C と　それ(sore)　に(ni)　対応(taio 对应)　する(suru 　アセンブラ

アセンブラ と(to) は(wa ha)

アセンブラ(asenbura)　と　

CPU と メモリ(memori) cpu and memory memori

機械語　と(to) アセンブラ(asenbura) 机器语言 and assembler

著者　に　ついて　作者 に 关于

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

```bash

UID PID PPID C STIME TTY TIME CMD
root 1 0 0 22:43 ? 00:00:01 /sbin/init splash
root 2 0 0 22:43 ? 00:00:00 [kthreadd]
root 3 2 0 22:43 ? 00:00:00 [ksoftirqd/0]
root 4 2 0 22:43 ? 00:00:00 [kworker/0:0]
root 5 2 0 22:43 ? 00:00:00 [kworker/0:0H]
root 7 2 0 22:43 ? 00:00:01 [rcu_sched]
root 8 2 0 22:43 ? 00:00:00 [rcu_bh]
root 9 2 0 22:43 ? 00:00:00 [migration/0]
root 10 2 0 22:43 ? 00:00:00 [watchdog/0]
root 11 2 0 22:43 ? 00:00:00 [watchdog/1]
root 12 2 0 22:43 ? 00:00:00 [migration/1]
root 13 2 0 22:43 ? 00:00:00 [ksoftirqd/1]
root 15 2 0 22:43 ? 00:00:00 [kworker/1:0H]
root 16 2 0 22:43 ? 00:00:00 [watchdog/2]
root 17 2 0 22:43 ? 00:00:00 [migration/2]
root 18 2 0 22:43 ? 00:00:00 [ksoftirqd/2]
root 20 2 0 22:43 ? 00:00:00 [kworker/2:0H]
root 21 2 0 22:43 ? 00:00:00 [watchdog/3]
root 22 2 0 22:43 ? 00:00:00 [migration/3]
root 23 2 0 22:43 ? 00:00:00 [ksoftirqd/3]
root 25 2 0 22:43 ? 00:00:00 [kworker/3:0H]
root 26 2 0 22:43 ? 00:00:00 [kdevtmpfs]

```

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

する suru

想定 soutei 

はじめに 介绍

入門 nyuumon 介绍

作成　sakusei 创造

ため　tame 为了

人の　hito no

コンパイラ Konpaira compiler

低レイヤ Tei reiya

知りたい shiritai

https://people.eecs.berkeley.edu/~matei/#teaching

When you found a problem, the first thing you do is ask someone.

It's skill and connection issue to know someone who can answer your question.

Hard Work alone doesn't get you what you want.
You have to make something good.


```bash

objdump -d test/plus.run --disassemble=our_code_starts_here



```

Inter-Operator (Vertical)
```go
package main

import (
	"fmt"
	"sync"
)

// Define the structs for R and S relations
type R struct {
	id   int
	name string
}

type S struct {
	id    int
	value string
	cdate string
}

// Define the struct for the joined results
type JoinedResult struct {
	RId   int
	Name  string
	Value string
}

// Hash function to partition the relations
func hashFunction(id int, numPartitions int) int {
	return id % numPartitions
}

// Function to partition data
func partitionData[T any](data []T, numPartitions int, hashFunc func(int, int) int) [][]T {
	partitions := make([][]T, numPartitions)
	for i := 0; i < numPartitions; i++ {
		partitions[i] = []T{}
	}

	for _, item := range data {
		var id int
		switch v := any(item).(type) {
		case R:
			id = v.id
		case S:
			id = v.id
		default:
			panic("unknown data type")
		}
		partition := hashFunc(id, numPartitions)
		partitions[partition] = append(partitions[partition], item)
	}

	return partitions
}

// Parallel hash join
func parallelHashJoin(partitionsR [][]R, partitionsS [][]S, numPartitions int) []JoinedResult {
	var wg sync.WaitGroup
	results := make(chan JoinedResult, 10) // Buffered channel to collect results
	finalResults := []JoinedResult{}

	// Join partitions in parallel
	for i := 0; i < numPartitions; i++ {
		wg.Add(1)
		go func(partitionR []R, partitionS []S) {
			defer wg.Done()
			hashTableS := make(map[int]S)
			for _, s := range partitionS {
				hashTableS[s.id] = s
			}
			for _, r := range partitionR {
				if s, found := hashTableS[r.id]; found {
					results <- JoinedResult{RId: r.id, Name: r.name, Value: s.value}
				}
			}
		}(partitionsR[i], partitionsS[i])
	}

	// Close results channel when all goroutines are done
	go func() {
		wg.Wait()
		close(results)
	}()

	// Collect results
	for result := range results {
		finalResults = append(finalResults, result)
	}

	return finalResults
}

func main() {
	// Example relations
	relationR := []R{{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}}
	relationS := []S{{1, "Value1", "2024-02-20"}, {2, "Value2", "2024-02-21"}, {3, "Value3", "2024-02-22"}}

	// Number of partitions
	numPartitions := 2 // For simplicity

	// Partition data
	partitionsR := partitionData(relationR, numPartitions, hashFunction)
	partitionsS := partitionData(relationS, numPartitions, hashFunction)

	// Perform parallel hash join
	joinedResults := parallelHashJoin(partitionsR, partitionsS, numPartitions)

	// Print results
	for _, result := range joinedResults {
		fmt.Printf("RId: %d, Name: %s, Value: %s\n", result.RId, result.Name, result.Value)
	}
}

```

Intra-Operator (Horizontal)
```go
package main

import (
	"fmt"
	"sync"
)

// Define the structs for R and S relations
type R struct {
	id   int
	name string
}

type S struct {
	id    int
	value string
	cdate string
}

// Hash function to partition the relations
func hashFunction(id int, numPartitions int) int {
	return id % numPartitions
}

// Function to build the hash table from a relation R or S
func buildHashTable(relation interface{}, numPartitions int) []map[int]interface{} {
	hashTables := make([]map[int]interface{}, numPartitions)
	for i := range hashTables {
		hashTables[i] = make(map[int]interface{})
	}

	switch rel := relation.(type) {
	case []R:
		for _, tuple := range rel {
			partition := hashFunction(tuple.id, numPartitions)
			hashTables[partition][tuple.id] = tuple
		}
	case []S:
		for _, tuple := range rel {
			partition := hashFunction(tuple.id, numPartitions)
			hashTables[partition][tuple.id] = tuple
		}
	}

	return hashTables
}

// Worker to perform the join on one partition
func joinWorker(htR, htS map[int]interface{}, results chan<- []string) {
	for id, rTuple := range htR {
		if sTuple, exists := htS[id]; exists {
			// Assuming we want to join on the 'id' and print 'name' and 'value'
			r := rTuple.(R)
			s := sTuple.(S)
			results <- []string{r.name, s.value}
		}
	}
}

func main() {
	// Example relations
	// Create more test data to test the join
	relationR := []R{
		{1, "A"},
		{2, "B"},
		{3, "C"},
		{4, "D"},
		{5, "E"},
	}

	relationS := []S{
		{1, "X", "2020-01-01"},
		{2, "Y", "2020-01-02"},
		{3, "Z", "2020-01-03"},
		{4, "W", "2020-01-04"},
		{5, "V", "2020-01-05"},
	}

	// Number of partitions
	numPartitions := 2 // for simplicity

	// Build hash tables for each partition
	htR := buildHashTable(relationR, numPartitions)
	htS := buildHashTable(relationS, numPartitions)

	results := make(chan []string)
	var wg sync.WaitGroup

	// Launch a worker for each partition
	for i := 0; i < numPartitions; i++ {
		wg.Add(1)
		go func(partition int) {
			defer wg.Done()
			joinWorker(htR[partition], htS[partition], results)
		}(i)
	}

	// Close the results channel when all workers are done
	go func() {
		wg.Wait()
		close(results)
	}()

	// Collect results
	for result := range results {
		fmt.Println(result)
	}
}


```

https://www.twitch.tv/videos/2065150462

https://twitter.com/arighi

# 2024-2-19 | 

infinite cases
finite try
how to get something useful?

don't be fansion

大學不是職訓所, 未必要跟在企業後面跑, 基本功學扎實更能應付未來的新領域!

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


236964.57

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

open source guys
commercial guys
research guys



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


std::shared_mutex pthread_rwlock

https://www.cs.rit.edu/~ats/books/ooc.pdf

You do more things, which means you know more information.

You know more information, which means you can do more things.

pointer wizzling

open source guys Linux postgresql

commerical guys windows oracle

std::mutex pthread_mutex futex

fast user mutex or heavy mutex os



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


If your goal is to be good at LeetCode, then save yourself the time and just go straight to LeetCode. Nobody cares if you actually understand the stuff. They just want you to come in and do the dance (recognize the problem archetype, talk through your thought process for solving it, and adjust based on whatever twists they've thrown in).


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


```bash

wasmedge --dir .:. \
  --nn-preload default:GGML:AUTO:llama-2-7b-chat.Q5_K_M.gguf \
  wasmedge-ggml-llama-interactive.wasm default

```

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

# Build WasmT

```bash

git checkout upstream/hydai/0.13.5_ggml_lts

git status

cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Release -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF .

cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Debug -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF -DCMAKE_INSTALL_PREFIX=`pwd`/_install .

cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Debug -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF -DLLVM_DIR="C:\Users\tannal\Downloads\llvm-18.1.0rc2.src\llvm-18.1.0rc2.src\cmake" -DCMAKE_INSTALL_PREFIX=`pwd`/_install .


ninja -C build

cmake --install build

mkdir -p local

cd local/

curl -LO https://github.com/second-state/LlamaEdge/releases/latest/download/llama-api-server.wasm

curl -LO https://huggingface.co/second-state/Llama-2-7B-Chat-GGUF/resolve/main/Llama-2-7b-chat-hf-Q5_K_M.gguf

gdb wasmedge

b ggml.cpp:415

r --dir . --nn-preload default:GGML:AUTO:llama-2-7b-chat.Q5_K_M.gguf llama-api-server.wasm -p llama-2-chat

wasmedge --dir . --nn-preload default:GGML:AUTO:Llama-2-7b-chat-hf-Q5_K_M.gguf llama-api-server.wasm  -p llama-2-chat

apt update && apt install httpie lsof htop jq

apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r` 

http POST http://localhost:8080/v1/models Accept:application/json

echo '{
  "messages": [
    {
      "role": "system",
      "content": "You are a helpful assistant."
    },
    {
      "role": "user",
      "content": "Who is Taylor Swift?"
    }
  ],
  "model": "llama-2-chat"
}' | http POST http://localhost:8080/v1/chat/completions Accept:application/json Content-Type:application/json



echo '{"prompt":["To be or not to be, "], "model":"tinyllama"}' | http POST http://localhost:8080/v1/completions Accept:application/json Content-Type:application/json

```


```bash
$env:HTTP_PROXY = "http://192.168.43.1:7890"
$env:HTTPS_PROXY = "http://192.168.43.1:7890"


set http_proxy=http://192.168.43.1:7890
set https_proxy=http://192.168.43.1:7890

git clone https://github.com/WasmEdge/WasmEdge.git -b hydai/0.13.5_ggml_lts

$env:LLVM_DIR = "C:\\Program Files\\LLVM\\lib\\cmake"
$env:LLVM_DIR = "C:/Program Files/LLVM/lib/cmake"

cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Release -DWASMEDGE_PLUGIN_WASI_NN_BACKEND="GGML" -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_METAL=ON -DWASMEDGE_PLUGIN_WASI_NN_GGML_LLAMA_BLAS=OFF .

```


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


GitHub Copilot, Tabnine, AWS CodeWhisperer, Other (please specify), Synk Code, Codeium, Whispr AI, Replit Ghostwriter, Mintlify, Adrenaline, Rubber Duck.AI.

ChatGPT, Bing AI, WolframAlpha, Google Bard AI, Phind, You.com, Other (please specify), Perplexity AI, Quora Poe, Neeva AI, Andi, Metaphor.

Udemy Coursera Codecademy Pluralsight edX Udacity Skillsoft

PostgreSQL MySQL SQLite MongoDB Microsoft SQL Server Redis MariaDB Elasticsearch Oracle
Dynamodb BigQuery H2 Cosmos DB Supabase InfluxDB Cassandra Snowflake Neo4J IBM DB2
Solr Firebird Couch DB Clickhouse Cockroachdb Couchbase DuckDB Datomic RavenDB TiDB


Amazon Web Services (AWS), Microsoft Azure, Google Cloud, Firebase, Cloudflare, Digital Ocean, Heroku, Vercel, Netlify, VMware, Hetzner, Linode (now Akamai), Managed Hosting, OVH, Oracle Cloud Infrastructure (OCI), OpenShift, Fly.io, Vultr, Render, OpenStack, IBM Cloud Or Watson, Scaleway, Colocation.


Docker, npm, Pip, Homebrew, Yarn, Webpack, Make, Kubernetes, NuGet, Maven, Gradle, Vite, Visual Studio Solution, CMake, Cargo, GNU GCC, Terraform, MSBuild, Ansible, Chocolatey, Composer, LLVM's Clang, APT, Unity 3D, Pacman, pnpm, MSVC, Podman, Ninja, Unreal Engine, Godot, Ant, Google Test, Nix, Meson, QMake, Puppet, Dagger, Chef, Catch2, Pulumi, Bun, Wasmer, doctest, SCons, bandit, cppunit, Boost.Test, build2, tunit, lest, snitch, CUTE, ELFspy, liblittletest.


Visual Studio Code, Visual Studio, IntelliJ IDEA, Notepad++, Vim, Android Studio, PyCharm, Sublime Text, Jupyter Notebook/JupyterLab, Neovim, Xcode, Eclipse, Nano, WebStorm, PhpStorm, Rider, DataGrip, Atom, CLion, Emacs, IPython, Goland, VSCodium, Netbeans, Rad Studio (Delphi, C++ Builder), Qt Creator, RStudio, Fleet, Code::Blocks, RubyMine, Helix, Kate, Spyder, BBEdit, Geany, TextMate, Micro, Nova, condo.

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

```bash

git clone https://github.com/ggerganov/ggml
cmake -S . -B build -G Ninja

ninja -C build

```

Set-ExecutionPolicy Unrestricted

even-better-toml

New-Item -ItemType SymbolicLink -Name compile_commands.json -Target .\build\compile_commands.json

mklink /d compile_commands.json .\build\compile_commands.json

sudo vim /etc/systemd/system/docs.service

/proc/28647/environ

sudo systemctl daemon-reload
sudo systemctl restart docs.service

systemctl status docs.service
sudo journalctl -u docs


[Unit]
# 服务名称，可自定义
Description = docs

[Service]
Type = simple
WorkingDirectory=/home/tannal/tannalwork/projects/yjs-demos/
ExecStart = /bin/bash -c 'PATH=/home/tannal/.nvm/versions/node/v20.10.0/bin/:$PATH pnpm start'
Restart=always

[Install]
WantedBy = multi-user.target

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

```
#lang racket
(define email (foldl string-append "" '("me" "." "pm" "@" "ipnon")))

(define zero "If you can imagine a society in which the computer-robot is the only menial, you can imagine anything.")

(define one "War is the best game and the worst life.")

(define two "For I know of nothing as profoundly exciting as to glimpse for the first time some new and basic truth.")

(define three "When I got to Cambridge, I was faced with the problem of looking at a question to which no one knew the answer—but I wasn’t willing to face it. When I left Cambridge, I didn’t know how to face it very well, but I understood that this was my job; this was the change that occurred that year.")

(define four "So here is an even more striking statistic: 0% of that first batch had a terrible experience. They had ups and downs, like every startup, but I don't think any would have traded it for a job in a cubicle. And that statistic is probably not an anomaly. Whatever our long-term success rate ends up being, I think the rate of people who wish they'd gotten a regular job will stay close to 0%.")

(define five "They asked me how well I understood theoretical physics. I said I had a theoretical degree in physics. They said welcome aboard.")

(define six "Always with you what cannot be done.")

(define seven "But whoever is acquainted with such a change in men, and can render a man humid and dry, hot and cold by regimen, could also cure this disease, if he recognizes the proper season for administering his remedies, without minding purifications, spells, and all other illiberal practices of a like kind.")

(define eight "松茸やかぶれた程は松の形")

(define nine "This black sprite is called humanity, but little is known about its true nature. If the soul is the source of all life, then what distinguishes the humanity we hold within ourselves?")

(define ten "If you chase two rabbits, you will lose them both.")

(define eleven "Clear and plain and coming through fine. I'm coming through fine too, eh? Good, then. Well then as you say we're both coming through fine. Good. Well it's good that you're fine and I'm fine. I agree with you. It's great to be fine.")

(define twelve "And he came and found them asleep again: for their eyes were heavy.")

(define thirteen "I believe that men are here to grow themselves into the full, into the best good that they can be, at least this is what I want to do. This is my belief: We are supposed to, I'm supposed to grow into the best good that I can get to. As I'm going there, becoming this, and when I become and forever become, this will just come out of the horn. Whatever that's going to be, that's what it will be. I'm not so much interested in trying to say what it's going to be, I don't know, but I just hope; I realize good can only bring good.")

(define fourteen "You can always tell a Harvard man, but you can't tell him much.")

(define fifteen "Live in the future, then build what’s missing.")

(define sixteen "Don’t you find that there’s a certain mad beauty in unorthodoxy?")

(define seventeen "From the first day we met, it was surprising to find that there were so many similarities in our thinking … the day I met Isamu Noguchi I realized that he was a man who was nearly as strange and opinionated as I was.")

(define eighteen "Nothing can exist in isolation. Architecture and garden, garden and sculpture, sculpture and people, people and community … must each be closely and mutually related. In these connections may lie a new ethics for artists.")

(define nineteen "I solemnly swear that I am up to no good.")

(define twenty "Heaven forbid! That would be the greatest misfortune of all! To find a man agreeable whom one is determined to hate! Do not wish me such an evil.")

(define twenty-one "What good is a philosopher who doesn't hurt anybody's feelings?")

(define twenty-two "In my whole life, I have known no wise people (over a broad subject area) who didn't read all the time--none.")

(define twenty-three "Please put me out of my Missouri.")
```

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

type means which operation to apply and how much memory to allocate

```ave

(+ 5 10)

(set x 15)

(if (> x 10)

  (print "ok"))
  (print "err")

```

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

Github Actions can auto deploy my blog.

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

nn

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

struct file {
  struct paht f_path;

}

struct path {
  
}

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
```bash



```


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

国内APP不符合Android UI、基本像chao IOS 的设计。

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

```

argdist-bpfcc
bashreadline-bpfcc
bindsnoop-bpfcc
biolatency-bpfcc
biolatpcts-bpfcc
biopattern-bpfcc
biosnoop-bpfcc
biotop-bpfcc
bitesize-bpfcc
bpflist-bpfcc
btrfsdist-bpfcc
btrfsslower-bpfcc
cachestat-bpfcc
cachetop-bpfcc
capable-bpfcc
cobjnew-bpfcc
compactsnoop-bpfcc
cpudist-bpfcc
cpuunclaimed-bpfcc
criticalstat-bpfcc
dbslower-bpfcc
dbstat-bpfcc
dcsnoop-bpfcc
dcstat-bpfcc
deadlock-bpfcc
dirtop-bpfcc
drsnoop-bpfcc
execsnoop-bpfcc
exitsnoop-bpfcc
ext4dist-bpfcc
ext4slower-bpfcc
filegone-bpfcc
filelife-bpfcc
fileslower-bpfcc
filetop-bpfcc
funccount-bpfcc
funcinterval-bpfcc
funclatency-bpfcc
funcslower-bpfcc
gethostlatency-bpfcc
hardirqs-bpfcc
inject-bpfcc
javacalls-bpfcc
javaflow-bpfcc
javagc-bpfcc
javaobjnew-bpfcc
javastat-bpfcc
javathreads-bpfcc
killsnoop-bpfcc
klockstat-bpfcc
kvmexit-bpfcc
llcstat-bpfcc
mdflush-bpfcc
memleak-bpfcc
mountsnoop-bpfcc
mysqld_qslower-bpfcc
netqtop-bpfcc
nfsdist-bpfcc
nfsslower-bpfcc
nodegc-bpfcc
nodestat-bpfcc
offcputime-bpfcc
offwaketime-bpfcc
oomkill-bpfcc
opensnoop-bpfcc
perlcalls-bpfcc
perlflow-bpfcc
perlstat-bpfcc
phpcalls-bpfcc
phpflow-bpfcc
phpstat-bpfcc
pidpersec-bpfcc
ppchcalls-bpfcc
profile-bpfcc
pythoncalls-bpfcc
pythonflow-bpfcc
pythongc-bpfcc
pythonstat-bpfcc
readahead-bpfcc
reset-trace-bpfcc
rubycalls-bpfcc
rubyflow-bpfcc
rubygc-bpfcc
rubyobjnew-bpfcc
rubystat-bpfcc
runqlat-bpfcc
runqlen-bpfcc
runqslower-bpfcc
shmsnoop-bpfcc
slabratetop-bpfcc
sofdsnoop-bpfcc
softirqs-bpfcc
solisten-bpfcc
sslsniff-bpfcc
stackcount-bpfcc
statsnoop-bpfcc
syncsnoop-bpfcc
syscount-bpfcc
tclcalls-bpfcc
tclflow-bpfcc
tclobjnew-bpfcc
tclstat-bpfcc
tcpaccept-bpfcc
tcpcong-bpfcc
tcpconnect-bpfcc
tcpconnlat-bpfcc
tcpdrop-bpfcc
tcplife-bpfcc
tcpretrans-bpfcc
tcprtt-bpfcc
tcpstates-bpfcc
tcpsubnet-bpfcc
tcpsynbl-bpfcc
tcptop-bpfcc
tcptracer-bpfcc
threadsnoop-bpfcc
tplist-bpfcc
trace-bpfcc
ttysnoop-bpfcc
vfscount-bpfcc
vfsstat-bpfcc
virtiostat-bpfcc
wakeuptime-bpfcc
xfsdist-bpfcc
xfsslower-bpfcc
zfsdist-bpfcc
zfsslower-bpfcc

```

sudo systemctl start frpc
sudo apt install wiringpi
sudo gpio readall

がいこく　ひと

難民

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

#--------------------------------------------------------------------------
# .gitconfig
#	GIT global settings
#	Copyright (c) 2010-2024, Michael Paquier
#--------------------------------------------------------------------------
[alias]
	# Check whitespaces
	check-whitespace = !git diff-tree --check $(git hash-object -t tree /dev/null) HEAD
	# Shorten diff for copied, renamed and deleted files
	diff-short = diff --find-renames --irreversible-delete --break-rewrites --find-copies
	# Execution of raw command
	exec = "!exec "
	# Shorten copied, renamed and deleted files for a patch generated
	format-patch-short = format-patch --find-renames --irreversible-delete --break-rewrites --find-copies
	# Print graph of git commit history
	graph = log --graph --date-order -C -M --pretty=format:\"<%h> %cd [%cn] %Cgreen%d%Creset %s\" --all --date=short
	# List files part of a commit.  Can be easily combined with git add.
	# This needs a single commit number at its tail.
	list-files = diff-tree --no-commit-id --name-only -r
	# Shorten log information for copied, renamed and deleted files
	log-short = log --find-renames --irreversible-delete --break-rewrites --find-copies -p
	# Show top level repository
	root = rev-parse --show-toplevel
	# Remove last commit
	undo = reset --hard HEAD~1
	# Remove last commit
	undo-soft = reset --soft HEAD~1
[color]
	# Print output in color if possible
	ui = auto
[core]
	# 4 spaces per tab when using the pager
	pager = less --tabs=4
	# Exclusion of several file types
	excludesfile = ~/.gitconfig_excludes
[diff]
	# Detect files renamed as well as copies
	renames = copies
	algorithm = histogram
	# Ordering of files in diffs, for PostgreSQL
	# XXX: If this becomes annoying for other projects, this had better
	# live as a local setting.
	orderFile = ~/.gitconfig_orderfile
[format]
	pretty = format:%C(blue)commit: %<(14,trunc)%H%C(reset)%n%C(green)author: %aN <%aE>%C(reset)%n%C(green)date: %aD%C(reset)%n%C(yellow)committer: %cN <%ce>%C(reset)%n%C(yellow)date: %cD%C(reset)%n%B
[log]
	# Do not use any mailmap file to map author name and emails.
	mailmap = false
[push]
	# Push branches having same name remotely and locally
	default = matching
[include]
	# Private parameters, done at the end to override other values
	# if necessary
	path = .gitconfig_extra



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

rephrase this problem in a short and easy to understand way

728abdaa-e5af-4886-a19b-22f6d3ae144a

just one test

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

## .github/workflows/example.yml

name: Merge upstream branches
on:
  schedule:
     # actually, ~5 minutes is the highest
     # effective frequency you will get
    - cron:  '* * * * *'
jobs:
  merge:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - name: Merge upstream
        run: |
          git config --global user.name 'your-name'
          git config --global user.email 'your-username@users.noreply.github.com'

          # "git checkout master" is unnecessary, already here by default
          git pull --unshallow  # this option is very important, you would get
                                # complains about unrelated histories without it.
                                # (but actions/checkout@v2 can also be instructed
                                # to fetch all git depth right from the start)

          git remote add upstream https://github.com/example/test.git
          git fetch upstream

          # Neither forget the -b opt,
          # the feature/x ref is ambiguous at this stage
          git checkout -b feature/x origin/feature/x
          git merge --no-edit upstream/feature/x
          git push origin feature/x

          git checkout master
          git merge --no-edit upstream/master
          git push origin master

          # etc

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

export https_proxy=http://192.168.43.1:7890
export http_proxy=http://192.168.43.1:7890

export https_proxy=http://127.0.0.1:7890
export http_proxy=http://127.0.0.1:7890

cmake -S . -B build
cmake --build build


cmake -S . -B aarch64 -DCMAKE_CXX_FLAGS="-mtune=cortex-a76" -DCMAKE_C_FLAGS="-mtune=cortex-a76"
cmake --build aarch64 --config Release

dnf Fedora 

# 2024-1-16  | 1

https://www.youtube.com/watch?v=ttebJcN5bgQ

winget install --id=Mobatek.MobaXterm  -e
computer just do two things moving bits and flip bits

sudo apt install git-lfs

git lfs pull

git clone https://huggingface.co/PowerInfer/ReluLLaMA-7B-PowerInfer-GGUF

GIT_LFS_SKIP_SMUDGE=1


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

define api 

ShflLock google leveldb 

if you want contributors, a typical way is to add good first issue tag on some issues.
or even better you can write down how to fix (step by step) driectly for someone to actually create their first patch.
If someone make them first patch, it's a lot easier for them to contribute next patch.

I know why we need cross compile

git pull --ff-only
git pull --rebase

If you want something, you should ask for it.
don't wait someone to offer it to you.

If you done something well, find the sponsor to maintain the work.
If not, find the way to improve it or start over.

show the right work to the right person at the right time.

there aren't so many smart guy, and you don't need to be one to be sccessfully.
just show up, and do something useful to others

For everyone who want to contribute to open source projects
You just need to show up, and find a position in the community.
(anything else doesn't matter)

I know I never be able to create the prfect things.
I just need to know how i can built with these fasinating tools.

microservices grpc computing nodes shared network grpc trpc protocol buffers

buildah podman

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

ask question make them think.

you

smalltalk self strongtalk Java(hotspot engine)

v8 dart

toit

https://news.ycombinator.com/threads?id=mralephp

The biggest truth I found is that, there is no "truth". The world it's just random people doing random things.

find interesting projects and make it more useful impresive amazing beautiful.

We normal don't talk to users directly as a software engineer.

As a software engineer, we ususally talk to product manager or project manager, not the user.

open source project allow us to directly talk to our users and get feedback.

There are many books write by (technical) writer not engineers.

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

shared memory can be very large flush can cayse hugh IO (TB memory)

checkpoint

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

RAM

Disk

os (Linux/windows/macos)
DB 

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

bun to zig is like servo to rust

automate generation of instruction selectors code generation

javascript spidermoney javascriptcore v8 quickjs babel

typescript swc twc tsc

C/C++ gcc clang

rust rustcc

go go

markdown

HTML/CSS 

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

There is no perfect people.

sometimes ai knows, sometime ai doesn't, it's like human.

the future is the sum of all human behavior.

the stock market is a subset of the future.

what do we need around code?
1. how to change the code? implementation
2. how users can use the code? interface

it's all about communication, like docs, books, turtorial, community.

so the point is we need a community around the code itself. eg. mailing list, live chat, talks, conference, and connection (with people)

all way go down to it's all about connection with people.

more percisely is the connection between users(interface) and developers(implementation)

and the connection between users and users 

and the connection between developers and developers.

connections means flow, someone leave and someon join.

flow is life.

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

3 5 8 10

The better you design it when it's not large(there is no so much devs around this project) determine how far it can go.

w3c css working group whatwg

os syscall -> std library -> thirdparty library -> framework -> application C/C++/

os syscall -> prgramming language runtime -> std library -> thirdparty libarary -> framework -> application 

It's all about how much you can get. logical reasoning is useless, pointless, and useless.

```bash


> tannal-web-app@0.0.1 build /home/tannal/tannalwork/projects/tannal.web.app
> astro check && astro build

16:16:37 [check] Getting diagnostics for Astro files in /home/tannal/tannalwork/projects/tannal.web.app...
src/firebase/client.ts:21:7 - warning ts(6133): 'analytics' is declared but its value is never read.

21 const analytics = getAnalytics(app);
         ~~~~~~~~~

Result (13 files): 
- 0 errors
- 0 warnings
- 1 hint

16:16:39 [WARN] Unsupported file type /home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/LICENSE found. Prefix filename with an underscore (`_`) to ignore.
16:16:39 [WARN] Unsupported file type /home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/firebase-debug.log found. Prefix filename with an underscore (`_`) to ignore.
16:16:39 [WARN] Unsupported file type /home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/image-1.png found. Prefix filename with an underscore (`_`) to ignore.
16:16:39 [WARN] Unsupported file type /home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/image-2.png found. Prefix filename with an underscore (`_`) to ignore.
16:16:39 [WARN] Unsupported file type /home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/image-3.png found. Prefix filename with an underscore (`_`) to ignore.
16:16:39 [WARN] Unsupported file type /home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/image-4.png found. Prefix filename with an underscore (`_`) to ignore.
16:16:39 [WARN] Unsupported file type /home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/image.png found. Prefix filename with an underscore (`_`) to ignore.
16:16:39 [build] output: "static"
16:16:39 [build] directory: /home/tannal/tannalwork/projects/tannal.web.app/dist/
16:16:39 [build] Collecting build info...
16:16:39 [build] ✓ Completed in 15ms.
16:16:39 [build] Building static entrypoints...
[Shiki] The language "llvm" doesn't exist, falling back to "plaintext".
[Shiki] The language "patch" doesn't exist, falling back to "plaintext".
[Shiki] The language "llvm" doesn't exist, falling back to "plaintext".
16:16:42 [ERROR] [vite] [vite]: Rollup failed to resolve import "image-4.png" from "/home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/node.md".
This is most likely unintended because it can break your application at runtime.
If you do want to externalize this module explicitly add it to
`build.rollupOptions.external`
[vite]: Rollup failed to resolve import "image-4.png" from "/home/tannal/tannalwork/projects/tannal.web.app/src/pages/posts/node.md".
This is most likely unintended because it can break your application at runtime.
If you do want to externalize this module explicitly add it to
`build.rollupOptions.external`
  Stack trace:
    at viteWarn (file:///home/tannal/tannalwork/projects/tannal.web.app/node_modules/.pnpm/vite@5.0.10/node_modules/vite/dist/node/chunks/dep-R0I0XnyH.js:66953:27)
    at onwarn (file:///home/tannal/tannalwork/projects/tannal.web.app/node_modules/.pnpm/vite@5.0.10/node_modules/vite/dist/node/chunks/dep-R0I0XnyH.js:66698:13)
    at Object.logger [as onLog] (file:///home/tannal/tannalwork/projects/tannal.web.app/node_modules/.pnpm/rollup@4.9.0/node_modules/rollup/dist/es/shared/node-entry.js:19023:9)
    at file:///home/tannal/tannalwork/projects/tannal.web.app/node_modules/.pnpm/rollup@4.9.0/node_modules/rollup/dist/es/shared/node-entry.js:17927:26
 ELIFECYCLE  Command failed with exit code 1.

```

testing error handling logging 


astro vite rollup -> 

vscode ssh tunning port forwarding


focus on things change slowly in 3-5 years cuda pytorch stable things matter

Daniel Bevenius - Principal Software Engineer - Red Hat

highly care about 2024-2027 20-23 (*) and 2027-2030 23-26

There are "popular" things that died quickly.

focus on things change slowly in 3-5 years(more than three years life time after it get "popular") cuda pytorch stable things matter

don't working on things would complete change in a year(short life less than three years). eg. js frameworks 

low level language C and assembly and machine code (knowledge of computer systems)

high level language C++ Rust Golang (knowledge of language abstractions and computer systems)

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

haigui

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

How to raise money/funding for a product? 

```
Can you help me go through some of the most used feature about future in rust with a example.

explain the most important things, keep answer as short as posiible, please phrase your sentence well.

```

embedded networking linux kernel networking browser networking gaming networking datacenter networking

raw cpu computing os computing language abstraction programming framework programming application programming

parallel programming gpu programming graphics programming

often startup needs to talk to client frequently, they feedback quick.

and they will give talks about their product, which demenstrate the core ideas of the product(aka selling point)

in the case of open source junior can learn a lot from it.

CI has TIMEOUT [expected FAIL] which could be flake or CI problem.

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

all human inteligence is just a kind of memory, no logic, no "think", no anything.

There is no other things than memory.

It's all about how many and how fast you can "memory" things.

base cases -> plausible reasoning -> truth or false

self reference, recursion, and human brian

given something -> create more things


のみに　依存　する　仅仅依靠
nomini izon suru
じょうほう 情報
jo u ho u

nvidia dlss scaling to 4k 

CUDA/Shading cores run graphics rendering pipeline
ray tracing cores
tensor cores

ray tracing cores

Tensor Cores dlss

talk is cheap

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

```c

struct nsproxy {
        atomic_t                   count;                /*     0     4 */
        struct uts_namespace *     uts_ns;               /*     4     4 */
        struct ipc_namespace *     ipc_ns;               /*     8     4 */
        struct mnt_namespace *     mnt_ns;               /*    12     4 */
        struct pid_namespace *     pid_ns_for_children;  /*    16     4 */
        struct net *               net_ns;               /*    20     4 */
        struct time_namespace *    time_ns;              /*    24     4 */
        struct time_namespace *    time_ns_for_children; /*    28     4 */
        struct cgroup_namespace *  cgroup_ns;            /*    32     4 */

        /* size: 36, cachelines: 1, members: 9 */
        /* last cacheline: 36 bytes */
};

```

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

The code is sucks, the people are great. Always so, no matter in/out side cn.

We should always focus on people around.

Andreessen Horowitz, Kleiner Perkins, EQT, Bessemer, BOND and Menlo Ventures investor# 2024-1-8

https://www.usenix.org/system/files/conference/nsdi13/nsdi13-final170_update.pdf

how google use leveldb

Sanity cms

gif

https://www.vectorlogo.zone/

1. Open your image.
2. Select the area you want to make transparent.
Select the appropriate selection tool from the Tool window or the Tools – Selection Tools menu on the Layer window. I usually use the magic wand/fuzzy select (Select contiguous region) tool or the Select regions by color tool.
Click in the region you want selected. Use shift-click to add more regions/colors.Tip: It’s easier if you zoom in (View – Zoom menu) to see finer details of exactly what you’re selecting.
3. In the Layer window (the one showing your image), select Layer – Transparency – Add Alpha Channel.If this is blanked out then it’s already done. This makes sure your image can store transparency data
4. Select Edit – Clear. This makes the selection transparent.
5. Save the file. Note: If you save it as a PNG file, be sure to select the ‘Save colour values from transparent pixels’ option in the Save as PNG dialog box.

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

open mp

A: False, that is completely incorrect

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

Entry Level / Intern Embedded Linux / Yocto Engineer
Konsulko Group has an entry level or intern opening for an embedded Linux and/or Yocto build
system engineer. Join and learn from a team of Linux engineers with a history of Linux development
dating back to the mid 90s.
The position is ideally based at our engineering center in Sofia, Bulgaria, but other locations will be
considered as well.
Job Requirements:
• A Passion for Linux
• B.S. or MS in Computer Science or similar major
• Experience in using Linux as a development platform
• Proficient in C programming
• Some Yocto Project, bash, or Python experience a plus
• Bonus points for having developed or debugged any kernel drivers, and any community
contributions
• Familiarity with Git
• Strong analytical and problem-solving skills
• Good English verbal and written skills
Please send your CV or resume in pdf form to careers@konsulko.com. 

Senior Embedded Linux/Yocto Engineer
Konsulko Group is looking for an experienced candidate with background in embedded Linux and
Yocto/OE to help migrate, develop, and maintain Yocto-based platforms. The candidate will be
responsible for tracking Yocto Project, various versions and packages, as well as engage with the
Open Source community to upstream any specific changes. The candidate must have experience
with embedded systems, device drivers, kernel modifications, and boot loaders.
The position may be based at our engineering centers in Sofia, Bulgaria or Malmö, Sweden, or the
Senior Engineer may choose to live in his/her home country, or elsewhere in North America, Europe
or Asia.
Primary Responsibilities:
• Develop and migrate existing products to Yocto-based platforms.
• Work closely with Konsulko’s customers to track and integrate specific Linux/Kernel
infrastructure and any third-party drivers in their software stacks.
• Maintain and support Yocto build system in a continuous integration environment including
packaging and deployment of software images.
• Write and maintain scripts
• Configure, modify and integrate the kernel and embedded boot loaders.
Job Requirements:
• A Passion for Linux
• B.S. in Computer Science and 7 years related work, or M.S. in Computer Science and 5 years
related work experience.
• 3+ years of Embedded Linux Systems experience.
• Proficient in C programming.
• Substantial experience with Yocto Project
• Experience with Bash scripting and Python programming.
• Experience developing and debugging kernel drivers for Embedded Linux would be a plus
• Familiarity with Git.
• Strong analytical and problem-solving skills.
• Excellent English verbal, written, and documentation skills.
Please send your CV or resume in pdf form to careers@konsulko.com. 

sudo snap install go --classic

what you see is pointless. It's just what it is.

```bash

sudo update-alternatives --config java

Rust is bigger than Mozilla

```

web history

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

& in shell

LocalStorage SessionStorage leveldb instead of sqlite https://bugs.chromium.org/p/chromium/issues/detail?id=225934

concurrency is a way to structure the software, once you structure it properly, you can get parallesim for free.

go routine

select channel

async await

You don't need to accept it, but you need to understand it.

The sccessful of the go programming language

- schwag logo symbol community open

- cross platform

- backward compatibility

- library tools 

Software is for machine to run, not for people to read.

Don't try to read large project source code without a specific goal , it's basicaly a waste of time.

No one can understand every details in big projects like postgresql, linux kernel, eta.

If you want to learn something, try to communicate with someone who know/invent it.

Reading is communication, it's just one-way. 

But two-way, feedback-rich communication can help you more.



0.X breaking changes prototype creativity move fast and break things

1.0 stable compatibility don't break user's code

Rust Backward Compatibility

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

```bash

disassemble


info registers

   0x0000aaaaaaaa0774 <+0>:     stp     x29, x30, [sp, #-16]!
   0x0000aaaaaaaa0778 <+4>:     mov     x29, sp
=> 0x0000aaaaaaaa077c <+8>:     adrp    x0, 0xaaaaaaaa0000
   0x0000aaaaaaaa0780 <+12>:    add     x0, x0, #0x7b0
   0x0000aaaaaaaa0784 <+16>:    bl      0xaaaaaaaa0630 <puts@plt>
   0x0000aaaaaaaa0788 <+20>:    mov     w0, #0x0                        // #0
   0x0000aaaaaaaa078c <+24>:    ldp     x29, x30, [sp], #16
   0x0000aaaaaaaa0790 <+28>:    ret

  sp             0xffffffffeda0      0xffffffffeda0
  pc             0xaaaaaaaa077c      0xaaaaaaaa077c <main+8>
  cpsr           0x80001000          [ EL=0 BTYPE=0 SSBS N ]
  fpsr           0x0                 [ ]
  fpcr           0x0                 [ Len=0 Stride=0 RMode=0 ]
  tpidr          0xfffff7ff8600      0xfffff7ff8600
  tpidr2         0x0                 0x0

```

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

https://github.com/servo/servo/wiki/Servo-Layout-Engines-Report

sudo systemctl enable ssh

```bash

sudo systemctl enable ssh


```

```bash

gcc -fverbose-asm -S main.c

```
https://github.com/microsoft/winget-cli/issues/1812

gmail ajax

重型挖掘机玩泥巴

JCR Licklider Douglas Engelbart

postScript

Python, Scheme, Ruby, LuaJIT, GCC, LLVM, GDB, and Factor

Test262 conformance tests

A example of security bug v is that you can open jishiben in chrome using js

# 2024-1-3


```bash

sudo shutdown

```

I generated builds for node using default, ninja and ccache enabled, here is what I found:

command used: make -j6
physical cpu cores: 6

    default config: 27 minutes , incremental builds: ~21 seconds
    default config + ccache enabled: 52 minutes, incremental builds: ~22 seconds
    ninja: 31 minutes, incremental builds: ~1 second
    ninja + ccache enabled: 32 minutes, incremental builds: ~1 second


https://en.wikichip.org/wiki/arm_holdings/microarchitectures/cortex-a76

arm raspi5 arm cortext A76

https://github.com/octref
https://github.com/waldyrious

https://github.com/microsoft/vscode-docs

code analysis lsp highlighting eta

lsp is pretty damn important

c/c++ clangd compilation database bear/cmake compile_commads.json

python no idea

java no idea

go go

rust rust-analyer

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

posts

https://www.outreachy.org/alums/2023-12/

https://www.outreachy.org/docs/applicant/#outreachy-schedule

We understand you may be applying to many jobs. If you receive a job or internship offer, please notify Outreachy organizers immediately.

the exams for your last school term must end before Jan. 20, 2024. 

# 2024-1-2

https://github.com/nodejs/node/pull/50899/files

gitpod

```bash


c/c++ on windows

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

TODO

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

Realtime process 0-99

Normal process 100-139

Nice -20-19

PR_new = PR_old + Nice

Priority

python fabric


# 2023-12-29


https://www.collabora.com/careers.html

```bash

virtualenv --version

virtualenv mypython

source mypython/bin/activate

deactivate

pip freeze

```

buildroot openwrt yocto

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

buffer table & buffer descripter & buffer pool

every other line 每隔一行

String &str

vec! HashSet HashMap

{:?} debug print

.iter().count().sum().filter().for_each().collect()

enumerate skip take

push based pull based iterator & generator & iter() & collect()

push no collect

pull has collect manually

web intent

React/Next/Typescript Flux Redux BootStrap, ANT Design, Tailwind Babel, Webpack, NPM

Ideally worked on Web Applications like SaaS, doing React front-end components.

React, GitHub, Java, Gradle, Groovy, MySQL, Snowflake, Docker, AWS, Slack, and JIRA

NodeJS NestJS MySQL MongoDB ReactJS NextJS Bootstrap/Material REST APIs Docker TDD CI/CD JEST/ Mocha, Jenkins, Selenium Stripe, RabbitMQ, Redis, AWS Elasticsearch

Use of Docker in local and production environments

Python, Java, or C++ TensorFlow, Caffe, PyTorch, Keras, Scikit Learn, and Theano

Python, Ruby on Rails, React.js or React Native

Python, Django, React, AWS/OpenStack, MySQL, MongoDB, PostgreSQL, Debian Ubuntu Debian/Ubuntu servers, Terraform, Vault, Packer, Prometheus, ELK, Docker RabbitMQ, Redis & Elasticsearch IOS & Android

NodeJS/Rails/django/go/elixir/java/flask/laravel

Java, Kotlin and the Android SDK, Android Studio, Material Spec

.NET, C#, SQL Server, IIS

figma HTML CSS Next.js, Apollo GraphQL, React

AWS, Azure, Google Cloud

MySQL, PostgreSQL, MongoDB

JavaScript and TypeScript

Git Node.js Docker, Kubernetes

Four or more years of experience in two or more of the following skill sets:
Ruby (Rails)
Go and related tooling
JavaScript (React, TypeScript, Relay)
MySQL and database management
NodeJS development
Design and build REST and/or GraphQL APIs
Experience with CI/CD tools and automated pipelines
Preferred Qualifications
Experience with Git, GitHub , Actions & workflow platform for version control and collaborative development.
Internals of web development frameworks, tools, and client performance optimization.
Building developer tools and pipelines that streamline and automate software lifecycle, including development, testing and releasing, with focus on speed, reliability and scalability.
Excellent written and verbal communication via async collaboration, documentation, and visibility of work
Hands-on experience with distributed systems at global scale.
Experience working with a remote, distributed team.
Familiarity with SQL, Kusto Query Language, general database knowledge, Kubernetes, and/or cloud-native concepts
Passionate about fostering effective Engineering practices and processes and contribute to open source software, engage with maintainers, and actively participate in community curation.
Compensation Range: USD $104,400.00 - USD $276,900.00 /Yr.

In addition, certain roles also have the opportunity to earn sales incentives based on revenue or utilization, depending on the terms of the plan and the employee's role.


A bachelor/master in Informatics (or related);
Proven professional experience in OO programming and web development;
Attentive to details, delivering quality code which is maintainable, efficient and reliable;
Experienced in MySQL, or other relational databases;
Familiar with version-control and automated testing tools;
Used to work in JSON/XML/CSV formats and have no issues with HTML/CSS;
Experienced in Ruby or Ruby and Rails (the right candidate will be considered without this experience);
Good in English communication and teamwork.

1+ years of experience with a Javascript framework (VueJS, Alpine)

MySQL
Modern PHP: composer, PHPUnit, Laravel
Javascript: VueJS, Alpine JS, Webpack, NPM, Node
CSS, Tailwind
Familiarity working with Bash/Shell, Git, Docker, Kubernetes, testing frameworks

3+ years of software development experience
Strong computer science fundamentals and programing skills
Experience with IPASS platforms such as Mulesoft, Boomi and Workato
Experience managing software development in an agile environment with CI/CD and automated testing – CirlceCI, Jenkins, CodePipeline, ElasticBeanstalk, GitHub Actions
Proficiency in programming languages JavaScript/TypeScript, Python, SQL
Working knowledge of React and REST API’s
Strong experience developing large-scale modern architectures in AWS
Strong knowledge on RDMS and NoSQL database technologies in AWS
Experience in data strategy – warehousing, ELT – Snowflake, RedShift, BigQuery

Required

Bachelor's degree and less than 2 years related experience.
Knowledge of software QA / test methodologies and process.
Familiarity with Java, Maven and Selenium.
Familiarity with issue/bug tracking systems, such as JIRA.
Excellent oral and written communication skills.
Preferred

Familiarity with one or more of the followings: Javascript, DOM HTML and React Native (or AngularJS).
Knowledge of SQL, Shell scripting, Cloud platforms.
Knowledge of API testing.
Knowledge of working in agile product teams (Scrum and Kanban)

12.23 - 1.6 chrismas

discussion & docs & code review & fix bugs

impact > learning

most time in particip

Jamstack Story book React Style guidist React cosmos

Full Stack

less time in side project

wasm learning a lof of things from llvm

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

Convenience wrapper for compiling V8 with gn/ninja and running tests.
Sets up build output directories if they don't exist.
Produces simulator builds for non-Intel target architectures.
Uses Goma by default if it is detected (at output directory setup time).
Expects to be run from the root of a V8 checkout.

Usage:
    gm.py [<arch>].[<mode>[-<suffix>]].[<target>] [testname...] [--flag]

All arguments are optional. Most combinations should work, e.g.:
    gm.py ia32.debug x64.release x64.release-my-custom-opts d8
    gm.py android_arm.release.check --progress=verbose
    gm.py x64 mjsunit/foo cctest/test-bar/*

For a less automated experience, pass an existing output directory (which
must contain an existing args.gn), e.g.:
    gm.py out/foo unittests

Flags are passed unchanged to the test runner. They must start with -- and must
not contain spaces.

<arch> can be any of: ia32 x64 arm arm64 mips64el ppc ppc64 riscv32 riscv64 s390 s390x android_arm android_arm64 loong64 fuchsia_x64 fuchsia_arm64
<mode> can be any of: release rel debug dbg optdebug opt
<target> can be any of:
 - d8, cctest, v8_unittests, v8_fuzzers, wasm_api_tests, wee8, mkgrokdump, generate-bytecode-expectations, inspector-test, bigint_shell, wami (build respective binary)
 - all (build all binaries)
 - tests (build test binaries)
 - check (build test binaries, run most tests)
 - checkall (build all binaries, run more tests)

3 year experience of software 

postmaster dump

associate is automatic

logical -> imagination

Learn -> doing creating making impact

one way -> two way

linear -> exponential

general vague -> specilized highly needed

write perfect code -> make things happen quickly



# 2023-12-26

do things

rust From trait

https://github.com/rust-lang/rust/blob/f6456285ddca7db0ffc663d02d9ecaf22d1f0d82/library/core/src/convert/mod.rs#L579C1-L585C2

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/mm/fault.c#L1239

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/mm/memory-failure.c#L525

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/include/uapi/asm/signal.h#L4

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/include/asm/pgtable_types.h#L4

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/include/asm/pgtable.h

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/mm/pgprot.c#L5

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/mm/pgtable.c#L563

64bit 

2**40 TB

64 52 48 32 

Intel Core i7/Linux

tag index offset

page table entry -> pte -> unsigned long 

physical page number

63 62 52 51 12 11 9 8 7 6 5 4 3 2 1 0



# 2023-12-25

Buffer Management

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

remote & open source

# 2023-12-20

211 5%
people beijing 5%

1.412 billion

1412 000 000 * 5% = 70600000

6000 000 000 * 5% = 300000000

Logical Block Address

UART to USB converter

raspi3b

FAT NTFS 

ELF

https://github.com/torvalds/linux/blob/55cb5f43689d7a9ea5bf35ef050f12334f197347/fs/binfmt_elf.c#L843

https://github.com/torvalds/linux/blob/55cb5f43689d7a9ea5bf35ef050f12334f197347/fs/binfmt_elf.c#L855

# 2023-12-19

x86 is dead, long live arm (for me)

services on open source software (company idea)

what do we need to create bea drawings?
- line arrows text

Programming & CSAPP

Data Stucture & Alorithms & Computing theory (programming & computing)
OS DB Emebeded Distbuted PL VM APP Internet Systems (systems)

AI

Engineering & Research


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

switch vs if-else ?

bus transport blocks of words (32bit or 64bit)
cpu register size is a word

ISA vs Micro Architecture

OS/360 Multics Honeywell

An example of getpeername security problem in Freebsd

copy_from_kernel 

If a user space program see something it shouldn't see, then it is a security problem.

not matter if it's been used to "attack"

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


Android

Google Cloud

Google Search

Google AI

Google Chrome

Flutter Dart firebase Go Chromium LevelDB 

Human are not good at linear data, like lists or table.
People are good at graph data, like a network.


# 2023-12-16

https://docs.google.com/document/d/1peUSMsvFGvqD5yKh3GprskLC3KVdAlLGOsK6gFoEOD0/edit?resourcekey=0-bPajpoo9IBZpG__-uCBE6w#heading=h.34a91yqebirw

WebAssembly
WebGPU
Accessible Rich Internet Applications (ARIA) provides an ontology for enabling accessibility of arbitrary content.
WebHID

# ELF PE

Id Section
0 custom section
1 type section
2 import section
3 function section
4 table section
5 memory section
6 global section
7 export section
8 start section
9 element section
10 code section
11 data section
12 data count section

```cpp
struct ModuleDesc {
  std::vector<FuncType> func_types; // type section
  std::vector<ImportDesc> imports;
  std::vector<FuncDesc> funcs;
  std::vector<TableDesc> tables;
  std::vector<MemoryDesc> memories;
  std::vector<GlobalDesc> globals;
  std::vector<TagDesc> tags;
  std::vector<ExportDesc> exports;
  std::vector<StartDesc> starts;
  std::vector<ElemDesc> elems;
  std::vector<DataDesc> datas;
  Istream istream;
};


```

WebAssembly Module
- preamble
  - magic
  - version
  - sections
    - type
    - import
    - func
    - tablesec
    - memsec
    - globalsec
    - exportsec
    - startsec
    - elemsec
    - datacountsec
    - codesec
    - datasec
- 
```

> The Code section stores the local variables information and bytecode of the function. The Function section associates the code section with the type section.

projects/wabt/include/wabt/interp/interp.h


```cpp
  // Matches binary format, do not change.
  enum Enum : int32_t {
    I32 = -0x01,        // 0x7f
    I64 = -0x02,        // 0x7e
    F32 = -0x03,        // 0x7d
    F64 = -0x04,        // 0x7c
    V128 = -0x05,       // 0x7b
    I8 = -0x06,         // 0x7a  : packed-type only, used in gc and as v128 lane
    I16 = -0x07,        // 0x79  : packed-type only, used in gc and as v128 lane
    FuncRef = -0x10,    // 0x70
    ExternRef = -0x11,  // 0x6f
    Reference = -0x15,  // 0x6b
    Func = -0x20,       // 0x60
    Struct = -0x21,     // 0x5f
    Array = -0x22,      // 0x5e
    Void = -0x40,       // 0x40
    ___ = Void,         // Convenient for the opcode table in opcode.h

    Any = 0,   // Not actually specified, but useful for type-checking
    I8U = 4,   // Not actually specified, but used internally with load/store
    I16U = 6,  // Not actually specified, but used internally with load/store
    I32U = 7,  // Not actually specified, but used internally with load/store
  };
```

type sections stores function 

u32

# Section Type (id is 0x01)

overall number (vector length)

function type 0x60 , parameter length 0x03, parameters, result length 0x01, results

In this example. we only have function type in our type section.

# Section Import (id is 0x02)

length of section

length of module name, module name

length of import name, import name

importdesc 0x00 is typeidx followed by a typeidx


# Section Function (id is 0x03)

length of section

function indices point to type section

# Section Table (id is 4)

length of section

reftype (function ref 0x70)

limits (0x01 0x05 0x05 {min: 0x05, max: 0x05})

# Section Memory (id is 5)


limits of the number of pages

> page size in wasm is 64kb

# Section Global (id is 6)

type

0x00 const 0x01 var

initilize expr

```

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

sudo stackcount-bpfcc  t:sched:* -Pdp 71362
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
