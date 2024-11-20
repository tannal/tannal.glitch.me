

# a13

## Social-app

sudo apt-get update
sudo apt-get install -y build-essential libvips-dev
yarn cache clean

rm -rf node_modules
rm yarn.lock

yarn config set https-proxy http://10.90.92.225:7890


## Graphite



## LadyBird



## Proton

- [] build error

## music-cnn


## folk-rnn

- [] write a pytorch version submit homework

## llm.c

## llama.cpp

## whisper.cpp

## ffmpeg

## Gstreamer


# a17

## rnn-music-generator

## talk-android

- [] build for android.injected.testOnly=false
- []


## zulip

- [] https://github.com/zulip/zulip/pull/32200

## zulip-deskop

## zulip-flutter

"very_active": 98  // 每3周至少1个PR

```json
issue_labels = {
    "功能模块标签": {
        "a-api": "实现Zulip服务器API相关",
        "a-compose": "消息编辑器、自动完成、文件/图片附件",
        "a-content": "解析和渲染Zulip HTML内容，特别是消息内容",
        "a-home": "应用主页面、查找和开始对话",
        "a-msglist": "消息列表界面",
        "a-model": "数据模型实现(PerAccountStore等)",
        "a-sync": "事件队列、重试、本地回显、竞态处理",
        "a-notifications": "通知相关功能"
    },

    "平台相关": {
        "a-Android": "Android特定问题或工作",
        "a-iOS": "iOS特定问题或工作"
    },

    "横切关注点": {
        "a-a11y": "无障碍功能",
        "a-i18n": "翻译和国际化",
        "a-design": "视觉和用户体验设计",
        "a-documentation": "文档相关",
        "performance": "性能优化、修复卡顿"
    },

    "流程标签": {
        "good first issue": "适合新手的问题",
        "help wanted": "需要帮助",
        "design review": "等待设计审查",
        "maintainer review": "等待维护者审查",
        "duplicate": "重复问题"
    }
}
```

# desktop

## Parley

## Xliem

## Vello

## Simple



## linux

make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j$(nproc)

## u-boot

sd.img drive

## jitsi-meet

bun install

## circle

## llvm-project

## WasmEdge

## Wasmtime

## zed

## graphite

## deno

## node-new

https://github.com/nodejs/node/pull/55698/files#diff-5b5902273122e094ff474fda358605ffa45a4a58b51cd0bf4c1acb93779df142


https://github.com/nodejs/node/issues/55782
https://github.com/nodejs/loaders/blob/main/doc/design/proposal-synchronous-hooks.md

## jitsi-meet

#errors_common_system_errors)
<e> [webpack-dev-server] [HPM] Error occurred while proxying request 127.0.0.1:8080/hihao to https://alpha.jitsi.net/ [ETIMEDOUT] (https://nodejs.org/api/errors.html#errors_common_system_errors)
<e> [webpack-dev-server] [HPM] Error occurred while proxying request 127.0.0.1:8080/hihao to https://alpha.jitsi.net/ [ETIMEDOUT] (https://nodejs.org/api/errors.html#errors_common_system_errors)
<e> [webpack-dev-server] [HPM] Error occurred while proxying request 127.0.0.1:8080/hihao to https://alpha.jitsi.net/ [ETIMEDOUT] (https://nodejs.org/api/errors.html#errors_common_system_errors)
<e> [webpack-dev-server] [HPM] Error occurred while proxying request 127.0.0.1:8080/hihao to https://alpha.jitsi.net/ [ETIMEDOUT] (https://nodejs.org/api/errors.html#errors_common_system_errors)
^C<i> [webpack-dev-server] Gracefully shutting down. To force exit, press ^C again. Please wait...
<i> [webpack-dev-server] [HPM] server close signal received: closing proxy server

tannal@desktop:~/tannalwork/projects/jitsi-meet$

## bun

git bisect start
git bisect bad
git bisect good <commit-hash>

https://github.com/oven-sh/bun/pull/11917

fetch] handleResponseMetadata: content_length is null and transfer_encoding src.http.Encoding.identity
src.install.install.PackageManager.runTasks__anon_146165
/home/tannal/tannalwork/projects/bun/src/install/install.zig:6768:87

src.install.install.PackageManager.installWithManager__anon_82882__struct_83392.runAndWaitFn__anon_83395__struct_105788.isDone
/home/tannal/tannalwork/projects/bun/src/install/install.zig:14337:42

src.bun.js.event_loop.MiniEventLoop.tick__anon_162824
/home/tannal/tannalwork/projects/bun/src/bun.js/event_loop.zig:1909:23

src.bun.js.event_loop.AnyEventLoop.tick__anon_146167
/home/tannal/tannalwork/projects/bun/src/bun.js/event_loop.zig:2084:31

src.install.install.PackageManager.sleepUntil__anon_123853
/home/tannal/tannalwork/projects/bun/src/install/install.zig:3106:29

src.install.install.PackageManager.installWithManager__anon_82882__struct_83392.runAndWaitFn__anon_83395__struct_105788.runAndWait
/home/tannal/tannalwork/projects/bun/src/install/install.zig:14380:44

src.install.install.PackageManager.installWithManager__anon_82882
/home/tannal/tannalwork/projects/bun/src/install/install.zig:14399:49

src.install.install.PackageManager.install
/home/tannal/tannalwork/projects/bun/src/install/install.zig:11960:66

src.cli.install_command.InstallCommand.exec
/home/tannal/tannalwork/projects/bun/src/cli/install_command.zig:7:31

src.cli.Command.start
/home/tannal/tannalwork/projects/bun/src/cli.zig:1691:40

bun-debug

## src

## gecko

- On branch cookie-count

moz-phab submit --no-wip
--jsdebugger
git worktree add -b cookie-count ../gecko-cookie-main
./mach try fuzzy --stage-changes
Differential Revision: https://phabricator.services.mozilla.com/D227349
Bug 1924567 - Remove  r?emilio

Differential Revision: https://phabricator.services.mozilla.com/D225966

TEST-UNEXPECTED-FAIL | toolkit/components/extensions/test/mochitest/test_ext_cookies_permissions_good.html | got no eviction event
TEST-UNEXPECTED-FAIL | toolkit/components/extensions/test/mochitest/test_ext_cookies_permissions_bad.html | expected two cookies for host - 1 == 2 - got 1, expected 2 (operator ==)
TEST-UNEXPECTED-FAIL | xpcshell.toml:toolkit/mozapps/extensions/test/xpcshell/test_sideloads_after_rebuild.js | xpcshell return code: 0
TEST-UNEXPECTED-FAIL | devtools/client/responsive/test/browser/browser_touch_event_iframes.js | ID 24 - untranslated iframe with DPR 2 and path http://example.com/browser/devtools/client/responsive/test/browser/ got click at close enough X 52, screen is 732. - 52 == 100 -
TEST-UNEXPECTED-FAIL | toolkit/components/resistfingerprinting/tests/browser/browser_service_worker_overrides.js | Timezone offset should be 420 in the service worker - Got 480, expected 420

LazyLogModule
[] fix failing tests
https://bugzilla.mozilla.org/show_bug.cgi?id=1845870
./mach mochitest -f browser netwerk/test/browser/browser*cookie* --headless
./mach gtest TestCookie.*

./mach run https://example.org/

export MOZ_LOG="cookie:3"


https://treeherder.mozilla.org/jobs?repo=try

- On branch color-theme
[] remove meidia query

```cpp
void ParallelMarker::donateWorkFrom(GCMarker* src) {
  if (!gHelperThreadLock.tryLock()) {
    return;
  }

  // Check there are tasks waiting for work while holding the lock.
  if (waitingTaskCount == 0) {
    gHelperThreadLock.unlock();
    return;
  }

  // Take the first waiting task off the list.
  ParallelMarkTask* waitingTask = waitingTasks.ref().popFront();
  waitingTaskCount--;

  // |task| is not running so it's safe to move work to it.
  MOZ_ASSERT(waitingTask->isWaiting);

  gHelperThreadLock.unlock();

  // Move some work from this thread's mark stack to the waiting task.
  MOZ_ASSERT(!waitingTask->hasWork());
  GCMarker::moveWork(waitingTask->marker, src);

  gc->stats().count(gcstats::COUNT_PARALLEL_MARK_INTERRUPTIONS);

  GeckoProfilerRuntime& profiler = gc->rt->geckoProfiler();
  if (profiler.enabled()) {
    profiler.markEvent("Parallel marking donated work", "");
  }

  // Resume waiting task.
  waitingTask->resume();
}

```

https://treeherder.mozilla.org/jobs?repo=try&revision=dee049bd1f29f6f5bd74e80537c36f50025d4cf8&selectedTaskRun=MprGTxjNTIGX_ir40zJCcA.0


## WebKit

export PATH=/opt/llvm-17/bin:$PATH
export CC=clang
export CXX=clang++
Tools/Scripts/build-jsc --jsc-only --debug

set disassembly-flavor intel

llint_op_mov
llint_op_stricteq
slow_path_stricteq


- [] Implment WASM Relaxed SIMD proposal
Air BBQ B3
[] Impment SIMD relaxed for wasm in JSC webkit relaxed simi pr fmsub fnmsub
see https://github.com/WebKit/WebKit/pull/14937/files
https://github.com/WebAssembly/relaxed-simd/issues/27
https://github.com/WebKit/WebKit/wiki/Tasks-for-new-contributors
tannal@desktop:~/tannalwork/projects/webkit-wasm-relaxed-min-max$ ./WebKitBuild/JSCOnly/Debug/bin/jsc --module-file=JSTests/wasm/stress/simd-const-relaxed-f32-min-max.js
WARNING: Not running inside JSC test harness
WARNING: Not running inside JSC test harness
Test failed with exception:  CompileError: WebAssembly.Module doesn't parse at byte 40: invalid extended simd op 269, in function at index 0 (evaluating 'new WebAssembly.Module(binaryResult.buffer)')
Module@[native code]
@/home/tannal/tannalwork/projects/webkit-wasm-relaxed-min-max/JSTests/wasm/wabt-wrapper.js:16:34
object

- []



# windows



# Rasberry Pi 5 Aarch64
