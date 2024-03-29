# inbox

ringbuffer 

b MacrotaskQueue::RunMacrotasks
b MicrotaskQueue::RunMicrotasks

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

make -C out BUILDTYPE=Release V=0 -j22
make -C out BUILDTYPE=Debug V=0 -j22



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

Event Loop is single thread

does node core developer handle multi threads? no, libuv handle it.
does deno developer handle rust threading ? no, tokio handle it.
does node impl AES tls alogrithm? no, openssl's job

parsing running js? JIT compilation? no, It's all v8's job.
why node so successful? 

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

./configure

./configure -C --debug-node

time make -j20

real    14m31.301s
user    265m47.070s
sys     12m22.725s

ln -s ./out/Release/compile_commands.json .

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

