# people

involves:ljharb

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
NODE_DEBUG

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

./node --inspect-brk=0.0.0.0:9229 test/parallel/test-net-server-close-before-calling-lookup-callback.js

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

./node test/parallel/test-webstreams-clone-unref.js

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

./node --inspect-brk=0.0.0.0:9229-node local/fetch.mjs

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


# Get the Code, build, running, testing, logging and lsp

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

```bash

./configure --ninja --debug -C

time make -j22

real    14m31.301s
user    265m47.070s
sys     12m22.725s

ninja -C out/Debug/ -t compdb > compile_commands.json


```

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

