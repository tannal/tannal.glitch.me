
# history

https://calendar.google.com/calendar/u/0/embed?src=c_16f0ae5d3a22625175d199dbdb1cac84c2d09eab7f173e94f558417cb5cdbfd8@group.calendar.google.com

module loading esm async or sync
https://github.com/nodejs/node-eps/pull/39#discussion-diff-76436912

# issues

buffer - 缓冲区相关
crypto - 加密模块
fs - 文件系统
http/https - HTTP/HTTPS 模块
net - 网络模块
stream - 流处理
vm - 虚拟机
worker - 工作线程

async_hooks - 异步钩子
esm - ES 模块系统
wasm - WebAssembly 支持
wasi - WebAssembly 系统接口
snapshot - 启动快照
realm - 领域/沙箱

windows - Windows 平台
linux - Linux 平台
macos - macOS 平台
android - Android 平台
wsl - Windows 子系统
freebsd - FreeBSD 平台

arm - ARM 架构
mips - MIPS 架构
ppc - Power 架构
riscv64 - RISC-V 64位
s390 - S390 架构

v8 engine - V8 引擎
libuv - libuv 库
openssl - OpenSSL 库
npm - NPM 包管理器
icu - 国际化支持库

good first issue - 适合新手的问题
help wanted - 需要帮助
wip - 进行中的工作
review wanted - 需要代码审查
needs-ci - 需要CI测试

semver-major - 主版本变更
semver-minor - 次版本变更
v18.x - 18.x版本相关
v20.x - 20.x版本相关
lts - 长期支持版本

bug - 程序错误
feature request - 功能请求
security - 安全问题
performance - 性能问题
regression - 回归问题

doc - 文档
typings - 类型定义
deprecations - 废弃特性

doc - 文档
typings - 类型定义
deprecations - 废弃特性

tsc-agenda - 技术指导委员会议程
modules-agenda - 模块工作组议程
next-10-agenda - 未来10年规划议程

# todo

这是 Node.js 的 GitHub Issues 列表，主要包含以下几类问题：
文档相关 (doc)
1. URL 类和 URLSearchParams 类的版本信息缺失 (#55806)
crypto.hash 文档位置混乱 (#55801)
zlib.crc32 文档章节位置错误 (#55800)
4. PerformanceResourceTiming 相关属性文档缺失 (#55793)
process.emit 文档缺失 (#55731)
功能问题/Bug
模块自定义钩子/加载器的异常行为 (#55808)
子进程命令执行中断 (#55802)
HTTP/S agents 的 keepAlive 选项默认值设置 (#55770)
fs.opendir 的 bufferSize 选项支持 (#55764)
Node 20+ 版本自定义 DNS 查找失败 (#55762)
性能优化
ESM Loader 同步化追踪 (#55782)
Pointer Compression 和 Isolate Groups (#55735)
node:test 模块的基准测试 (#55723)
API 设计/使用问题
AbortController 异常处理位置不当 (#55742)
napi_threadsafe_function 使用安全性问题 (#55706)
stream 的 readable 事件和 data 事件行为 (#55704)
工具链/开发相关
shared-libuv 依赖问题 (#55787)
TypeScript 文件的 lint 工具 (#55702)
这些问题反映了 Node.js 作为一个成熟的项目面临的各种挑战：
文档完善和维护
功能 bug 修复
性能优化
API 设计改进
开发工具链优化
大部分问题都很具体，涉及特定的 API 或功能模块，这有助于维护者快速定位和解决问题。

python tools/test.py  -p tap --logfile test.tap --mode=release --flaky-tests=keep_retrying -p actions --node-args='--test-reporter=spec' --node-args='--test-reporter-destination=stdout' --measure-flakiness 9 test/parallel/test-zlib-crc32.js

[] - xxhash

[] - // TODO(joyeecheung): use fast API

[x] - // TODO(@anonrig): Add V8 Fast API to the following function

# achievement

# checklist

CLANG_FORMAT_START=$(git merge-base HEAD main) make format-cpp
make lint-cpp

# dev

https://github.com/nodejs/node/pulls/joyeecheung

CC="/opt/llvm/bin/clang" CXX="/opt/llvm/bin/clang++" \
./configure \
  --ninja \
  --release \
  --prefix=/usr/local \
  --with-intl=full-icu \
  --shared-openssl \
  --shared-zlib \
  --shared-libuv \
  --experimental-http-parser \
  --dest-cpu=x64 \
  --openssl-use-def-ca-store \
  --node-builtin-modules-path $(pwd)

CFLAGS="-O3 -march=native -mtune=native -flto -fuse-ld=gold -fno-semantic-interposition" \
CXXFLAGS="-O3 -march=native -mtune=native -flto -fuse-ld=gold -fno-semantic-interposition" \
LDFLAGS="-O3 -march=native -mtune=native -flto -fuse-ld=gold -fno-semantic-interposition" \
make -j$(nproc)

CC="clang" CXX="clang++" ./configure --ninja --debug --v8-with-dchecks -C --node-builtin-modules-path $(pwd) --with-intl=full-icu --dest-cpu=x64

./configure --ninja --debug --v8-with-dchecks -C --node-builtin-modules-path $(pwd)

--with-intl=full-icu


export NODE_DEBUG_NATIVE=module
unset NODE_DEBUG_NATIVE

with fastapi

tannal@desktop:~/tannalwork/projects/node-new$ ./node benchmark/run.js --filter revoke -- url

url/url-blob-revoke.js
url/url-blob-revoke.js size=10 type="blob" n=100000: 217,463.47527505632
url/url-blob-revoke.js size=100 type="blob" n=100000: 217,691.65683946662
url/url-blob-revoke.js size=1000 type="blob" n=100000: 203,802.8237354051
url/url-blob-revoke.js size=10000 type="blob" n=100000: 132,876.6621123102

without fastapi

tannal@desktop:~/tannalwork/projects/node-new$ ./node benchmark/run.js --filter revoke -- url

url/url-blob-revoke.js
url/url-blob-revoke.js size=10 type="blob" n=100000: 217,931.99219917663
url/url-blob-revoke.js size=100 type="blob" n=100000: 211,260.86090765544
url/url-blob-revoke.js size=1000 type="blob" n=100000: 202,209.2836320385
url/url-blob-revoke.js size=10000 type="blob" n=100000: 133,015.48166659055
tannal@desktop:~/tannalwork/projects/node-new$ ./node benchmark/run.js --filter revoke -- url

url/url-blob-revoke.js
url/url-blob-revoke.js size=10 type="blob" n=100000: 217,527.17465842873
url/url-blob-revoke.js size=100 type="blob" n=100000: 215,842.70799369586
url/url-blob-revoke.js size=1000 type="blob" n=100000: 202,320.22902310028
url/url-blob-revoke.js size=10000 type="blob" n=100000: 130,602.28202281595
tannal@desktop:~/tannalwork/projects/node-new$ ./node benchmark/run.js --filter revoke -- url

url/url-blob-revoke.js
url/url-blob-revoke.js size=10 type="blob" n=100000: 217,290.88761545805
url/url-blob-revoke.js size=100 type="blob" n=100000: 214,186.14006713766
url/url-blob-revoke.js size=1000 type="blob" n=100000: 201,947.22726769978
url/url-blob-revoke.js size=10000 type="blob" n=100000: 132,759.6780564
tannal@desktop:~/tannalwork/projects/node-new$ ./node benchmark/run.js --filter revoke -- url

url/url-blob-revoke.js
url/url-blob-revoke.js size=10 type="blob" n=100000: 217,912.59248294868
url/url-blob-revoke.js size=100 type="blob" n=100000: 214,547.26533217568
url/url-blob-revoke.js size=1000 type="blob" n=100000: 199,789.60396553917
url/url-blob-revoke.js size=10000 type="blob" n=100000: 129,482.92161892606


# dev


https://www.yagiz.co/ aka anonrig

https://github.com/tannal/node/actions/runs/10382466923/job/28745595189

$env:NODE_PATH="node"

python tools/test.py  -p tap --logfile test.tap --mode=release --flaky-tests=keep_retrying -p actions --node-args='--test-reporter=spec' --node-args='--test-reporter-destination=stdout' --measure-flakiness 9 default pummel addons js-native-api node-api benchmark

<!--
Before submitting a pull request, please read:

- the CONTRIBUTING guide at https://github.com/nodejs/node/blob/HEAD/CONTRIBUTING.md
- the commit message formatting guidelines at
  https://github.com/nodejs/node/blob/HEAD/doc/contributing/pull-requests.md#commit-message-guidelines

For code changes:
1. Include tests for any bug fixes or new features.
2. Update documentation if relevant.
3. Ensure that `make -j4 test` (UNIX), or `vcbuild test` (Windows) passes.

If you believe this PR should be highlighted in the Node.js CHANGELOG
please add the `notable-change` label.
-->

### Description

This pull request merges the `ongc.js` file and the `gcUntil` function from `common/index.js` into a single file. This addresses the TODO comment

### Changes Made

1. Merged the contents of `ongc.js` and the `gcUntil` function from `common/index.js` into the `gc.js` file.
2. Updated any necessary imports or exports.
4. Removed the original `ongc.js` file.

### Tests

- [x] Added/updated tests for the merged functionality
- [x] Ensured all existing tests pass

### Documentation

- [x] Updated relevant documentation, if necessary

<!--
Developer's Certificate of Origin 1.1

By making a contribution to this project, I certify that:

(a) The contribution was created in whole or in part by me and I
    have the right to submit it under the open source license
    indicated in the file; or

(b) The contribution is based upon previous work that, to the best
    of my knowledge, is covered under an appropriate open source
    license and I have the right under that license to submit that
    work with modifications, whether created in whole or in part
    by me, under the same open source license (unless I am
    permitted to submit under a different license), as indicated
    in the file; or

(c) The contribution was provided directly to me by some other
    person who certified (a), (b) or (c) and I have not modified
    it.

(d) I understand and agree that this project and the contribution
    are public and that a record of the contribution (including all
    personal information I submit with  it, including my sign-off) is
    maintained indefinitely and may be redistributed consistent with
    this project or the open source license(s) involved.
-->

test: merge ongc and gcutil to gc.js

gh workflow run "Build Windows" --ref fix
gh workflow run "Test Macos" --ref fix
gh workflow run "Test Linux" --ref fix
gh workflow run "Coverage Winodws" --ref fix
gh workflow run "Coverage Linux" --ref fix
gh workflow run "Coverage Macos" --ref fix
gh workflow run "Linters" --ref fix

https://github.com/nodejs/node/pull/54288


node_task_runner.h

  // Represents PATH environment variable that contains
  // all subdirectory paths appended with node_modules/.bin suffix.
  std::string path_env_var_;

make lint-js

tools/test.py -m debug test/parallel/test-options.js --shell ./node_g  --report --node-args --track-heap-objects

export NODE_OPTIONS='--expose-internals'

./node --inspect-brk=0.0.0.0:9229 test/parallel/test-net-server-close-before-calling-lookup-callback.js

./node test/parallel/test-webstreams-clone-unref.js

./node --inspect-brk=0.0.0.0:9229-node local/fetch.mjs

source ~/tannalwork/projects/v8/v8/tools/gdbinit

# inbox

/opt/valgrind/bin/valgrind ~/tannalwork/projects/node/node_g ./out/typescript-bug-58369/node_modules/
typescript/lib/tsc.js

sudo perf record -F 99 --call-graph dwarf -p `pgrep -n node_g` -g -- sleep 30
sudo perf script > ./graph/out.nodestacks02

export FBASE=$WORK/projects/FlameGraph/
$FBASE/stackcollapse-perf.pl < $FBASE/graph/out.nodestacks02 | $FBASE/flamegraph.pl > $FBASE/graph/out.nodestacks02.svg


node::StreamBase::WriteString<(node::encoding)1>

Runtime_LoadPropertyWithInterceptor

sudo perf trace -e 'syscalls:sys_enter_read,syscalls:sys_exit_read,syscalls:sys_enter_write,syscalls:sys_exit_write' -p `pgrep -n node` -o io_events.trace sleep 30

https://stackoverflow.com/questions/27842281/unknown-events-in-nodejs-v8-flamegraph-using-perf-events

sudo perf record -F 99 -p `pgrep -n node` -g -- sleep 30
sudo perf script > out.nodestacks01

./stackcollapse-perf.pl < ~/tannalwork/projects/node/out.nodestacks01 | ./flamegraph.pl > ./out.nodestacks01.svg

./node_g --prof ~/tannalwork/cans/add.js

./node_g --prof-process isolate-*.log > processed.txt

jst jco job

Serilizer
HeapObject


# setup

```bash
git clone https://github.com/tannal/node.git

git remote add upstream https://github.com/nodejs/node
git fetch upstream v18.x

./configure --ninja --debug --v8-with-dchecks -C --node-builtin-modules-path $(pwd)
time make -j23

ninja -C out/Debug/ -t compdb > compile_commands.json


```bash
// .vscode/launch.json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(lldb) Launch",
      "type": "lldb",
      "request": "launch",
      "program": "${workspaceFolder}/out/Release/node",
      "args": [
        "--expose-internals",
        "test.js"
      ],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": true,
      "MIMode": "lldb"
    }
  ]
}
```

```bash
"compileCommands": "${workspaceFolder}/out/Debug/compile_commands.json"
```


# people

involves:joyeecheung
involves:targos
involves:anonrig
involves:aduh95
involves:tniessen
involves:RafaelGSS
involves:MoLow
involves:marco-ippolito
involves:legendecas
involves:cjihrig
involves:lpinca
involves:mhdawson
involves:atlowChemi
involves:panva
involves:richardlau
involves:Trott
involves:deokjinkim
involves:zcbenz
involves:GeoffreyBooth
involves:LiviaMedeiros
involves:ronag
involves:jasnell
involves:VoltrexKeyva
involves:theanarkh
involves:ShogunPanda
involves:mcollina
involves:daeyeon
involves:RaisinTen
involves:cola119
involves:benjamingr
involves:santigimeno
involves:bnoordhuis
involves:addaleax
involves:codebytere
involves:ruyadorno
involves:himself65
involves:gengjiawen
involves:juanarbol
involves:guybedford
involves:indutny
involves:cclauss
involves:Flarna
involves:mmarchini
involves:JacksonTian
involves:TimothyGu
involves:isaacs
involves:XadillaX
involves:fhinkel
involves:bengl
involves:srl295
involves:BethGriggs
involves:devsnek

involves:lundibundi

involves:ljharb
involves:jasnell
involves:theanarkh

involves:Qard
involves:joyeecheung
involves:isaacs
involves:izs
involves:mikeal
involves:ovflowd
involves:mhdawson
involves:mcollina
involves:mylesborins

# concurrent model

node has typically 4-6 platform worker thread
V8Platform -> NodePlatform class has a reference to worker_thread_task_runner_ which has a reference to threads_
NodeMainInstance has a reference to a MultiIsolatePlatform

node has a watchdog thread
node_watchdog.h

node has a inspector thread client server architecture just like gdb


# inbox

Debug() from src/debug_utils.h
NODE_DEBUG=

export TARGET_ARCH=x64
export BUILD_ARCH_TYPE=x64.debug

gn gen -v "out.gn/$BUILD_ARCH_TYPE" --args="is_component_build=false is_debug=true use_goma=false goma_dir=\"None\" use_custom_libcxx=false v8_target_cpu=\"$TARGET_ARCH\" target_cpu=\"$TARGET_ARCH\" v8_enable_backtrace=true"

export BUILD_ARCH_TYPE=x64.debug
export JOBS_ARG=22

ninja -v -C "out.gn/$BUILD_ARCH_TYPE" d8 cctest inspector-test

The __esModule property is commonly used to recognize transpiled ES modules in consuming code.

--expose-internals

git remote add upstream https://github.com/nodejs/node

git fetch upstream v18.x

./configure --ninja --debug --v8-with-dchecks
time make -j23

rb js-objects.cc:.

gdb --args node_g test/parallel/test-vm-context.js

nodejs performance team
https://github.com/search?q=involves%3Abenjamingr%20&type=issues
https://github.com/search?q=involves%3AMoLow%20&type=issues

ringbuffer

b MacrotaskQueue::RunMacrotasks

```cpp

void MicrotaskQueue::EnqueueMicrotask(Tagged<Microtask> microtask) {
  if (size_ == capacity_) {
    // Keep the capacity of |ring_buffer_| power of 2, so that the JIT
    // implementation can calculate the modulo easily.
    intptr_t new_capacity = std::max(kMinimumCapacity, capacity_ << 1);
    ResizeBuffer(new_capacity);
  }

  DCHECK_LT(size_, capacity_);
  ring_buffer_[(start_ + size_) % capacity_] = microtask.ptr();
  ++size_;
}

V8's micro task queue
  isolate->GetCurrentContext()->GetMicrotaskQueue()
      ->EnqueueMicrotask(isolate, args[0].As<Function>());


```

SourceTextModule->GetStalledTopLevelAwaitMessage

v8 module

src/node_contextify.cc
if (ProcessEmitWarningSync(env,
                            "(To load an ES module, set \"type\": "
                            "\"module\" in the package.json "
                            "or use the .mjs extension.)")

MaybeLocal<Value> LoadEnvironment(
    Environment* env,
    StartExecutionCallback cb) {
  env->InitializeLibuv();
  env->InitializeDiagnostics();

  return StartExecution(env, cb);
}

src: implement --trace-promises
https://github.com/nodejs/node/commit/1e31a01f898a3586faf01480928161f2f5ef965d

ln -sfn ./out/Release/compile_commands.json .

mksnapshot and requireBuiltin lib/internal/bootstrap/realm.js

Addons are dynamically-linked shared objects written in C++. The require() function can load addons as ordinary Node.js modules. Addons provide an interface between JavaScript and C/C++ libraries.

JNI in node binding.gyp

--inspect-brk-node

./configure --ninja --debug && make -j22


 make -j4 test (UNIX), or vcbuild test (Windows) passes
tests and/or benchmarks are includede
documentation is changed or added
commit message follows commit guidelines

git reset --soft ec6ddcecbfdbd66c96d6f40fda8da5162544093e


node threads
PlatformWorkerThread 5
node::WorkerThreadsTaskRunner::DelayedTaskScheduler::Start() 1

gdb ./node

r test/parallel/test-webstreams-clone-unref.js

[js] stream: fix cloned webstreams not being unref correctly
process doesn't exit
https://github.com/nodejs/node/blob/2a33e950937a2645da9679f19bbdfe18f881dfa6/src/node_main_instance.cc#L124

git commit --amend


tools/test.py test/parallel/test-stream2-transform.js



https://github.com/npm/

```cpp

if (env->options()->debug_options().break_first_line) {
  env->inspector_agent()->PauseOnNextJavascriptStatement("Break on start");
}

```

https://github.com/nodejs/node/pulls/joyeecheung

![Alt text](./image-4.png)
ECMAScript Spec

https://chat.openai.com/g/g-DTk1KpYjg-pdf-translator-gpt

nodejs bun deno

![Alt text](image-5.png)


```js

console.log('Hello World' + new Date().toISOString())

```

context isolate

global object set key value

Isolate* isolate = context->GetIsolate();
EscapableHandleScope handle_scope(isolate);

Local<Object> global = context->Global();

void Print(const v8::FunctionCallbackInfo<v8::Value>& info);

![Alt text](image-6.png)

Local<Value> arg = info[i];

```cpp

// src/util.cc
Local<v8::FunctionTemplate> NewFunctionTemplate(
    v8::Isolate* isolate,
    v8::FunctionCallback callback,
    Local<v8::Signature> signature,
    v8::ConstructorBehavior behavior,
    v8::SideEffectType side_effect_type,
    const v8::CFunction* c_function) {
  return v8::FunctionTemplate::New(isolate,
                                   callback,
                                   Local<v8::Value>(),
                                   signature,
                                   0,
                                   behavior,
                                   side_effect_type,
                                   c_function);
}

Local<FunctionTemplate> SocketAddressBlockListWrap::GetConstructorTemplate(
    Environment* env) {
  Local<FunctionTemplate> tmpl = env->blocklist_constructor_template();
  if (tmpl.IsEmpty()) {
    Isolate* isolate = env->isolate();
    tmpl = NewFunctionTemplate(isolate, SocketAddressBlockListWrap::New);
    tmpl->SetClassName(FIXED_ONE_BYTE_STRING(env->isolate(), "BlockList"));
    tmpl->InstanceTemplate()->SetInternalFieldCount(kInternalFieldCount);
    SetProtoMethod(isolate, tmpl, "addAddress", AddAddress);
    SetProtoMethod(isolate, tmpl, "addRange", AddRange);
    SetProtoMethod(isolate, tmpl, "addSubnet", AddSubnet);
    SetProtoMethod(isolate, tmpl, "check", Check);
    SetProtoMethod(isolate, tmpl, "getRules", GetRules);
    env->set_blocklist_constructor_template(tmpl);
  }
  return tmpl;
}

// Store primordials setup by the per-context script in the environment.
Local<Object> per_context_bindings =
    GetPerContextExports(ctx).ToLocalChecked();
Local<Value> primordials =
    per_context_bindings->Get(ctx, env_->primordials_string())
        .ToLocalChecked();
CHECK(primordials->IsObject());
set_primordials(primordials.As<Object>());

```



![Alt text](image-4.png)


node::inspector::NodeInspectorClient::runMessageLoopOnPause

node:internal/main/run_main_module

worker thread

'use strict';

// Flags: --expose-internals

require('../common');
const assert = require('node:assert');
const freelist = require('node:internal/freelist');

node lib module is lazy loaded when needing, so if you are not see the file when debugging.

It's beacause they are not loaded.


nodejs use openssl for web crypto api and tls connection https://github.com/openssl/openssl.git

```js
// nodejs dns lookup
// Easy DNS A/AAAA look up
// lookup(hostname, [options,] callback)
const validFamilies = [0, 4, 6];
function lookup(hostname, options, callback) {

uv__getaddrinfo_work

```

about:debugging

node env context

isolate

## testing

cctest

## debugging

> The source code of Node.js itself is primarily written in C++ and JavaScript. The JS part is mostly under the lib directory and the C++ part is mostly under the src directory. There are also a bunch of third-party dependencies like v8 or libuv which are placed under the deps directory.

> The Node.js release binaries do not strip the debug symbols (surprised?) so you don’t necessarily have to build a debug build to get meaningful C/C++ stack traces or to do step debugging in a native debugger like LLDB or GDB.



## lsp

clangd

TSServer

[error] TSServer exited. Code: null. Signal: SIGTERM


# community



# reference

https://joyeecheung.github.io/blog/2018/12/31/tips-and-tricks-node-core/

# appendix

 1: 0x55af33c8fd3c node::DumpNativeBacktrace(_IO_FILE*) [./node_g]
 2: 0x55af33ec0ca1  [./node_g]
 3: 0x55af33ec0cc5  [./node_g]
 4: 0x55af3659e692 V8_Fatal(char const*, int, char const*, ...) [./node_g]
 5: 0x55af3659e6db  [./node_g]
 6: 0x55af34475607 v8::internal::Debug::Break(v8::internal::JavaScriptFrame*, v8::internal::Handle<v8::internal::JSFunction>) [./node_g]
 7: 0x55af34df043f  [./node_g]
 8: 0x55af34df0a07 v8::internal::Runtime_DebugBreakOnBytecode(int, unsigned long*, v8::internal::Isolate*) [./node_g]
 9: 0x55aed5885476


  1: 0x56282d88fd3c node::DumpNativeBacktrace(_IO_FILE*) [./node_g]
 2: 0x56282dac0ca1  [./node_g]
 3: 0x56282dac0cc5  [./node_g]
 4: 0x56283019e692 V8_Fatal(char const*, int, char const*, ...) [./node_g]
 5: 0x56283019e6db  [./node_g]
 6: 0x56282ea85f44 v8::internal::DebugInfo::DebugBytecodeArray(v8::internal::Isolate*) [./node_g]
 7: 0x56282ea8b852 v8::internal::CodeSerializer::SerializeObjectImpl(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
 8: 0x56282eac18b5 v8::internal::Serializer::ObjectSerializer::VisitPointers(v8::internal::Tagged<v8::internal::HeapObject>, v8::internal::FullMaybeObjectSlot, v8::internal::FullMaybeObjectSlot) [./node_g]
 9: 0x56282e7c6c34 v8::internal::HeapObject::IterateBody(v8::internal::Tagged<v8::internal::Map>, int, v8::internal::ObjectVisitor*) [./node_g]
10: 0x56282eac27ea v8::internal::Serializer::ObjectSerializer::SerializeContent(v8::internal::Tagged<v8::internal::Map>, int) [./node_g]
11: 0x56282eac68ec v8::internal::Serializer::ObjectSerializer::Serialize(v8::internal::SerializerDeserializer::SlotType) [./node_g]
12: 0x56282ea8b06b v8::internal::CodeSerializer::SerializeGeneric(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
13: 0x56282ea8b27d v8::internal::CodeSerializer::SerializeObjectImpl(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
14: 0x56282eac18b5 v8::internal::Serializer::ObjectSerializer::VisitPointers(v8::internal::Tagged<v8::internal::HeapObject>, v8::internal::FullMaybeObjectSlot, v8::internal::FullMaybeObjectSlot) [./node_g]
15: 0x56282e7c6c34 v8::internal::HeapObject::IterateBody(v8::internal::Tagged<v8::internal::Map>, int, v8::internal::ObjectVisitor*) [./node_g]
16: 0x56282eac27ea v8::internal::Serializer::ObjectSerializer::SerializeContent(v8::internal::Tagged<v8::internal::Map>, int) [./node_g]
17: 0x56282eac68ec v8::internal::Serializer::ObjectSerializer::Serialize(v8::internal::SerializerDeserializer::SlotType) [./node_g]
18: 0x56282ea8b06b v8::internal::CodeSerializer::SerializeGeneric(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
19: 0x56282ea8b457 v8::internal::CodeSerializer::SerializeObjectImpl(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
20: 0x56282eac18b5 v8::internal::Serializer::ObjectSerializer::VisitPointers(v8::internal::Tagged<v8::internal::HeapObject>, v8::internal::FullMaybeObjectSlot, v8::internal::FullMaybeObjectSlot) [./node_g]
21: 0x56282e7c6c34 v8::internal::HeapObject::IterateBody(v8::internal::Tagged<v8::internal::Map>, int, v8::internal::ObjectVisitor*) [./node_g]
22: 0x56282eac27ea v8::internal::Serializer::ObjectSerializer::SerializeContent(v8::internal::Tagged<v8::internal::Map>, int) [./node_g]
23: 0x56282eac68ec v8::internal::Serializer::ObjectSerializer::Serialize(v8::internal::SerializerDeserializer::SlotType) [./node_g]
24: 0x56282ea8b06b v8::internal::CodeSerializer::SerializeGeneric(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
25: 0x56282ea8b600 v8::internal::CodeSerializer::SerializeObjectImpl(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
26: 0x56282eac18b5 v8::internal::Serializer::ObjectSerializer::VisitPointers(v8::internal::Tagged<v8::internal::HeapObject>, v8::internal::FullMaybeObjectSlot, v8::internal::FullMaybeObjectSlot) [./node_g]
27: 0x56282e7c6c34 v8::internal::HeapObject::IterateBody(v8::internal::Tagged<v8::internal::Map>, int, v8::internal::ObjectVisitor*) [./node_g]
28: 0x56282eac27ea v8::internal::Serializer::ObjectSerializer::SerializeContent(v8::internal::Tagged<v8::internal::Map>, int) [./node_g]
29: 0x56282eac68ec v8::internal::Serializer::ObjectSerializer::Serialize(v8::internal::SerializerDeserializer::SlotType) [./node_g]
30: 0x56282ea8b06b v8::internal::CodeSerializer::SerializeGeneric(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
31: 0x56282ea8b27d v8::internal::CodeSerializer::SerializeObjectImpl(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
32: 0x56282e7c6c34 v8::internal::HeapObject::IterateBody(v8::internal::Tagged<v8::internal::Map>, int, v8::internal::ObjectVisitor*) [./node_g]
33: 0x56282eac27ea v8::internal::Serializer::ObjectSerializer::SerializeContent(v8::internal::Tagged<v8::internal::Map>, int) [./node_g]
34: 0x56282eac68ec v8::internal::Serializer::ObjectSerializer::Serialize(v8::internal::SerializerDeserializer::SlotType) [./node_g]
35: 0x56282ea8b06b v8::internal::CodeSerializer::SerializeGeneric(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
36: 0x56282ea8b27d v8::internal::CodeSerializer::SerializeObjectImpl(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
37: 0x56282eac18b5 v8::internal::Serializer::ObjectSerializer::VisitPointers(v8::internal::Tagged<v8::internal::HeapObject>, v8::internal::FullMaybeObjectSlot, v8::internal::FullMaybeObjectSlot) [./node_g]
38: 0x56282e78f038  [./node_g]
39: 0x56282e7c6c34 v8::internal::HeapObject::IterateBody(v8::internal::Tagged<v8::internal::Map>, int, v8::internal::ObjectVisitor*) [./node_g]
40: 0x56282eac27ea v8::internal::Serializer::ObjectSerializer::SerializeContent(v8::internal::Tagged<v8::internal::Map>, int) [./node_g]
41: 0x56282eac68ec v8::internal::Serializer::ObjectSerializer::Serialize(v8::internal::SerializerDeserializer::SlotType) [./node_g]
42: 0x56282ea8b06b v8::internal::CodeSerializer::SerializeGeneric(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
43: 0x56282ea8b600 v8::internal::CodeSerializer::SerializeObjectImpl(v8::internal::Handle<v8::internal::HeapObject>, v8::internal::SerializerDeserializer::SlotType) [./node_g]
44: 0x56282eabf14b v8::internal::Serializer::VisitRootPointers(v8::internal::Root, char const*, v8::internal::FullObjectSlot, v8::internal::FullObjectSlot) [./node_g]
45: 0x56282ea8473d v8::internal::CodeSerializer::SerializeSharedFunctionInfo(v8::internal::Handle<v8::internal::SharedFunctionInfo>) [./node_g]
46: 0x56282ea861f7 v8::internal::CodeSerializer::Serialize(v8::internal::Isolate*, v8::internal::Handle<v8::internal::SharedFunctionInfo>) [./node_g]
47: 0x56282de00ff9 v8::ScriptCompiler::CreateCodeCacheForFunction(v8::Local<v8::Function>) [./node_g]
48: 0x56282d981553 node::builtins::BuiltinLoader::SaveCodeCache(char const*, v8::Local<v8::Function>) [./node_g]
49: 0x56282d981482 node::builtins::BuiltinLoader::LookupAndCompileInternal(v8::Local<v8::Context>, char const*, std::vector<v8::Local<v8::String>, std::allocator<v8::Local<v8::String> > >*, node::Realm*) [./node_g]
50: 0x56282d981a88 node::builtins::BuiltinLoader::LookupAndCompile(v8::Local<v8::Context>, char const*, node::Realm*) [./node_g]
51: 0x56282d9833c2 node::builtins::BuiltinLoader::CompileFunction(v8::FunctionCallbackInfo<v8::Value> const&) [./node_g]
52: 0x5627cf3d2ba2
Trace/breakpoint trap (core dumped)
