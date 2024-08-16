# dev

https://bugzilla.mozilla.org/show_bug.cgi?id=790194
这是一个关于在Mozilla Firefox代码库中替换一些字符串转数字函数的bug。主要内容如下:

最初的问题是要替换atoi()函数,因为它没有错误检查。
后来发现strtol()/strtoul()也不安全,因为它们受locale影响。
提议使用glib的g_ascii_strtoll()等函数,但这些函数在Windows等平台上不可用。
考虑使用PR_sscanf()作为替代,因为它不受locale影响。
但PR_sscanf()也有问题:缺乏格式字符串检查,依赖NSPR库。
另一个建议是使用strtol_l()等支持明确locale的函数,但它们可能不是所有平台都支持。
最终的方案似乎是创建包装函数,内部使用PR_sscanf()来解析数字,以替换atoi/strtol/strtoul的使用。
代码位置从media/webrtc/signaling移动到了dom/media/webrtc。
最后有人质疑PR_sscanf是否真的locale无关,因为它内部使用了isspace/isdigit等函数。
核心问题是要找到一个安全、跨平台、不受locale影响的字符串转数字函数来替换现有的atoi/strtol/strtoul。这个问题比预想的要复杂,需要权衡各种因素。

Bug 1841061 - Remove network.compress.allow_truncated_empty_brotli pref r?gregp

Bug 1913213 - Remove unused nsDisplayListBuilder::SubtractFromVisibleRegion r?gregp


https://bugzilla.mozilla.org/show_bug.cgi?id=1437885
问题描述:
在Windows系统上,当操作系统级别的位置服务被关闭时,Firefox浏览器中使用位置权限的扩展会反复弹出请求启用位置服务的对话框。
原因分析:
Firefox使用Windows的原生位置API来获取位置信息。
当位置服务关闭时,Windows API会返回错误,但Firefox没有正确处理这个错误状态。
Firefox没有记住用户拒绝位置请求的决定,导致重复弹出对话框。
解决思路:
在WindowsLocationProvider类中添加一个布尔标志,用来记录用户是否已经拒绝了位置请求。
修改WindowsLocationProvider::Startup()方法,检查Windows API返回的错误码。
如果返回ERROR_ACCESS_DENIED,说明位置服务被禁用,设置标志并避免再次调用RequestPermissions。
在后续的位置请求中,先检查这个标志,如果已被拒绝就直接返回,不再弹出对话框。
具体实现:
在WindowsLocationProvider类中添加bool成员变量mDenied。
在Startup()方法中,调用RequestPermissions后检查返回值:
cpp

复制
if (FAILED(location->RequestPermissions(...))) {
  if (GetLastError() == ERROR_ACCESS_DENIED) {
    mDenied = true;
    return NS_ERROR_FAILURE;
  }
}
在Startup()方法开始处添加检查:
cpp

复制
if (mDenied) {
  return NS_ERROR_FAILURE;
}
后续优化:
考虑使用GetReportStatus来获取当前状态,以适应用户可能在系统设置中启用位置服务的情况。
如果GetReportStatus返回REPORT_ACCESS_DENIED等错误状态,可以考虑切换到MLS(Mozilla Location Service)作为备选。
最新进展:
根据最近的评论,这个问题可能已经在新版本的Windows和Firefox中得到了改善或修复。建议在最新的Windows 11和Firefox版本上重新验证这个问题是否仍然存在。

https://bugzilla.mozilla.org/show_bug.cgi?id=943410
这个bug讨论了在JavaScript引擎IonMonkey中改进无符号除法和取模操作的范围分析优化。主要过程如下:

最初的目标是使用范围分析来消除不必要的bailout(回退到解释器执行)。
讨论集中在改进MDiv(除法指令)的fallible()方法,使其更精确地判断何时需要bailout。
分析了代码生成器中导致bailout的各种条件,总结为几种情况。
提出了为MDiv添加专门的fallible检查方法的方案:
fallibleDivU()
fallibleDivPowTwoI()
fallibleDivConstantI()
fallibleDivI()
实现了这些专门的fallible方法,并修改了Lowering阶段对应的调用。
提交patch进行try测试,发现很多测试用例失败。
分析失败原因,发现与寄存器分配器的选择有关,导致fallible检查没有按预期执行。
继续分析其他失败用例,寻找共同问题。
核心的改动是在MDiv类中添加了更精细的fallible判断,以减少不必要的bailout,提高JIT代码的效率。但实际执行中遇到了一些意外情况,需要进一步分析和调整。

这个讨论展示了JIT编译器优化的复杂性,以及如何通过静态分析来改进动态执行性能

Bug 1898653 Remove layout.css.inline-style-caching.always-enabled pref r?emilio

Bug 1906157 Use AsyncPanZoomController::ToCSSPixel in more places r?ajakobi


python ./mach lint -l clippy toolkit/components/glean/api/src/ -W -v    

python.exe ./mach lint --warnings

Bug 1900643 Remove unused variable `purgedSiteHosts` in BounceTrackingProtection.cpp r?manuel



Bug 1911935 - Remove network.IDN_show_punycode pref r?gregp

python ./mach lint --ongoing

Bug 1886716 - Remove reference to nonexistent nsIPointerEvent.idl


Bug 1853548 - Remove dom.no_unknown_protocol_error.enabled pref


git diff-tree -p c9e2aa1002d8

Bug 1842458 - Remove dom.window.event.enabled pref r?gregp


git branch -D window-event
git branch -d window-event

git pull --rebase

./mach static-analysis check --outgoing

Bug 1892347 - Remove nsIDOMWindowUtils.isPartOfOpaqueLayer r?gregp


Bug 1895391 - Remove widget.non-native-theme.solid-outline-style pref

./mach lint --fix
./mach build

https://codepen.io/juliemoynat/pen/PoRYWoN

hg pull central --rebase

hg pull --rebase

moz-phab submit --no-wip

./mach clobber

hg strip --keep -r . # --keep optional
hg update --clean    # reset to last commit

hg pull central
hg up central

moz-phab submit

./mach lint --fix

Bug 1895530 - Remove security.allow_disjointed_external_uri_loads pref

hg commit
hg revert js/src/jit/ExecutableAllocator.cpp

./mach try auto


hg diff
hg remove -f

Bug 1868293 - Fix clippy warnings in glean-ffi r=sylvestre

./mach lint modules/libpref/init/StaticPrefList.yaml -W -v    
./mach lint uriloader/exthandler/nsExternalHelperAppService.cpp -W -v    

this->mContentType->mData

export MOZ_LOG="example_logger:3"

nsUnknownDecoder::LastDitchSniff

RUST_LOG="debug" ./mach run --debugger=gdb /home/tannal/tannalwork/cans/baseline.html


```
$env:RUST_LOG="debug"

hg pull && hg update

```

# inbox

sudo perf record --call-graph dwarf -F 99 -p 182782 -g -- sleep 30
sudo perf script > ./graph/out.firefoxgpustacks01
./stackcollapse-perf.pl < ./graph/out.firefoxgpustacks01 | ./flamegraph.pl > ./graph/out.firefoxgpustacks01.svg

# setup

cargo install --git https://github.com/glandium/git-cinnabar
git cinnabar setup


git clone hg::https://hg.mozilla.org/mozilla-unified gecko && cd gecko
git config fetch.prune true
git cinnabar fetch --tags

mv .git/hooks/fsmonitor-watchman.sample .git/hooks/query-watchman
git config core.fsmonitor .git/hooks/query-watchman

```bash

sudo apt-get install curl python3 python3-pip
python3 -m pip install --user mercurial
curl https://hg.mozilla.org/mozilla-central/raw-file/default/python/mozboot/bin/bootstrap.py -O
python3 bootstrap.py

cd mozilla-unified
hg up -C central

./mach build
./mach ide vscode


./mach build-backend --backend=CompileDB
./obj-x86_64-pc-linux-gnu/clangd/compile_commands.json

find . -name compile_commands.json

ln -s ./obj-x86_64-pc-linux-gnu/clangd/compile_commands.json compile_commands.json 

RUST_LOG="debug" obj-x86_64-unknown-linux-gnu/dist/bin/firefox -no-remote -P
RUST_LOG="debug" obj-x86_64-pc-windows-msvc/dist/bin/firefox -no-remote -P

```


# people

spidermonkey
involves:ptomato
involves:moztcampbell
involves:hotsphink
involves:xry111
involves:arai-a
involves:yurydelendik
involves:mgaudet
involves:tynopex
involves:evilpie
involves:jandem
involves:sagudev

involves:ehsan
involves:gregorypappas
involves:emilio

# inbox


spidermonkey
export MOZCONFIG=$HOME/mozconfigs/debug

webrender issue tracker
https://bugzilla.mozilla.org/buglist.cgi?product=Core&component=Graphics%3A%20WebRender&resolution=---


servo crates that firefox use
webrender
glean
html5ever
freetype
stylo
https://github.com/servo/rust-url
https://github.com/servo/euclid


b nsRetrievalContextX11::WaitForClipboardData

b /home/tannal/tannalwork/projects/mozilla-unified/widget/gtk/nsClipboard.cpp:606

b nsRetrievalContextX11::GetClipboardText



https://bugs.eclipse.org/bugs/show_bug.cgi?id=528691

RUST_LOG="debug" ./mach run --debugger=gdb translate.google.com


RUST_LOG="debug" ./mach wpt --debugger=gdb ./testing/web-platform/tests/css/CSS2/cascade/inherit-computed-001.html
RUST_LOG="debug" ./mach wpt ./testing/web-platform/tests/css/CSS2/cascade/inherit-computed-001.html


The Firefox layout team


spidermonkey team
https://github.com/mozilla-spidermonkey
gfx team
https://mozillagfx.wordpress.com/

gecko layout team meeting notes https://docs.google.com/document/d/1BbKGHgmDjD87f6Dt4mMXrZysch5END7AoCIY1cwGSdY/edit

 ./mach run -- -layoutdebug -no-remote.

https://groups.google.com/

sylvestre

involves:flackr chromium compositor owner https://philiprogers.com/resume.html


moz-phab

./mach install-moz-phab

hg uncommit

hg rollback

./mach lint toolkit/components/glean/api/src/ffi/event.rs


./mach lint -l clippy toolkit/components/glean/api/src/ -W -v    



  b'finish_task_switch.isra.0'
  b'schedule'
  b'futex_wait_queue'
  b'futex_wait'
  b'do_futex'
  b'__x64_sys_futex'
  b'do_syscall_64'
  b'entry_SYSCALL_64_after_hwframe'
  b'__GI___lll_lock_wait'
  b'mozilla::UniquePtr<js::jit::InliningRoot, JS::DeletePolicy<js::jit::InliningRoot> >::reset(js::jit::InliningRoot*)'
  b'js::jit::JitScript::~JitScript()'
  b'JSScript::releaseJitScript(JS::GCContext*)'
  b'JS::Zone::forceDiscardJitCode(JS::GCContext*, JS::Zone::DiscardOptions const&)'
  b'js::gc::GCRuntime::discardJITCodeForGC()'
  b'js::gc::GCRuntime::endPreparePhase(JS::GCReason)'
  b'js::gc::GCRuntime::incrementalSlice(js::SliceBudget&, JS::GCReason, bool)'
  b'js::gc::GCRuntime::gcCycle(bool, js::SliceBudget const&, JS::GCReason)'
  b'js::gc::GCRuntime::collect(bool, js::SliceBudget const&, JS::GCReason)'
  b'GarbageCollectImpl(JS::GCReason, nsJSContext::IsShrinking, js::SliceBudget const&)'
  b'nsJSContext::RunIncrementalGCSlice(JS::GCReason, nsJSContext::IsShrinking, js::SliceBudget&)'
  b'mozilla::CCGCScheduler::GCRunnerFiredDoGC(mozilla::TimeStamp, mozilla::GCRunnerStep const&)'
  b'mozilla::CCGCScheduler::GCRunnerFired(mozilla::TimeStamp)'
  b'mozilla::IdleTaskRunner::Run()'
  b'mozilla::IdleTaskRunnerTask::Run()'
  b'mozilla::TaskController::DoExecuteNextTaskOnlyMainThreadInternal(mozilla::detail::BaseAutoLock<mozilla::Mutex&> const&)'
  b'mozilla::TaskController::ExecuteNextTaskOnlyMainThreadInternal(mozilla::detail::BaseAutoLock<mozilla::Mutex&> const&)'
  b'mozilla::TaskController::ProcessPendingMTTask(bool)'
  b'mozilla::detail::RunnableFunction<mozilla::TaskController::TaskController()::$_0>::Run()'
  b'nsThread::ProcessNextEvent(bool, bool*)'
  b'NS_ProcessNextEvent(nsIThread*, bool)'
  b'mozilla::ipc::MessagePump::Run(base::MessagePump::Delegate*)'
  b'MessageLoop::Run()'
  b'nsBaseAppShell::Run()'
  b'nsAppShell::Run()'
  b'nsAppStartup::Run()'
  b'XREMain::XRE_mainRun()'
  b'XREMain::XRE_main(int, char**, mozilla::BootstrapConfig const&)'
  b'XRE_main(int, char**, mozilla::BootstrapConfig const&)'
  b'main'
  b'__libc_start_call_main'

sudo stackcount-bpfcc -i 2 -p 152169 --debug "*switch*"

nsHtml5Tokenizer::tokenizeBuffer

nsHtml5AttributeName
nsHtml5String

b nsHtml5Tokenizer.cpp:906


gdb /home/tannal/tannalwork/projects/mozilla-unified/obj-x86_64-pc-linux-gnu/dist/bin/firefox

set MOZ_LOG="example_logger:3"
export MOZ_LOG="example_logger:3"
MOZ_LOG="example_logger:3" ./mach run

parser
 mTreeBuilder
  tokenizer

nsLayoutUtils::PaintFrame

PR_Sleep(PR_MillisecondsToInterval(1));


b nsHtml5StreamParser::DoDataAvailableBuffer

handle all nostop

 : public Runnable

b nsHtml5StreamParser::OnDataAvailable
parser/html/nsHtml5StreamParser.cpp

set follow-fork-mode child

b DrainDirectTasks thread 13
break locspec thread thread-id

b nsHtml5Parser.cpp:311
b nsThread.cpp:1137
b nsSocketTransport2.cpp:394

./mach clobber

https://github.com/mozilla/gecko-dev/commits?author=cathiechen


https://hg.mozilla.org/mozilla-central/rev/dd251ff8689542fbefadb663a6dfc26afb21b02f

  b'__libc_pwrite'
  b'(anonymous namespace)::BaseWrite(sqlite3_file*, void const*, int, long long)'
  b'walWriteOneFrame'
  b'pagerWalFrames'
  b'sqlite3PagerCommitPhaseOne'
  b'sqlite3BtreeCommitPhaseOne'
  b'vdbeCommit'
  b'sqlite3VdbeHalt'
  b'sqlite3VdbeExec'
  b'sqlite3_step'
  b'mozilla::storage::Connection::stepStatement(sqlite3*, sqlite3_stmt*)'
  b'mozilla::storage::AsyncExecuteStatements::executeStatement(mozilla::storage::StatementData&)'
  b'mozilla::storage::AsyncExecuteStatements::executeAndProcessStatement(mozilla::storage::StatementData&, bool)'
  b'mozilla::storage::AsyncExecuteStatements::Run()'
  b'nsThread::ProcessNextEvent(bool, bool*)'
  b'NS_ProcessNextEvent(nsIThread*, bool)'
  b'mozilla::ipc::MessagePumpForNonMainThreads::Run(base::MessagePump::Delegate*)'
  b'MessageLoop::Run()'
  b'nsThread::ThreadFunc(void*)'
  b'_pt_root'
  b'set_alt_signal_stack_and_start(PthreadCreateParams*)'
  b'start_thread'

  b'entry_SYSCALL_64_after_hwframe'
  b'__xstat64'
  b'unixClose'
  b'(anonymous namespace)::QuotaClose(sqlite3_file*)'
  b'sqlite3PagerClose'
  b'sqlite3BtreeClose'
  b'sqlite3LeaveMutexAndCloseZombie'
  b'sqlite3Close'
  b'mozilla::storage::Connection::internalClose(sqlite3*)'
  b'mozilla::dom::quota::CachingDatabaseConnection::Close()'
  b'mozilla::dom::indexedDB::(anonymous namespace)::ConnectionPool::CloseConnectionRunnable::Run()'
  b'nsThread::ProcessNextEvent(bool, bool*)'
  b'NS_ProcessNextEvent(nsIThread*, bool)'
  b'mozilla::dom::indexedDB::(anonymous namespace)::ConnectionPool::ThreadRunnable::Run()'
  b'nsThread::ProcessNextEvent(bool, bool*)'
  b'NS_ProcessNextEvent(nsIThread*, bool)'
  b'mozilla::ipc::MessagePumpForNonMainThreads::Run(base::MessagePump::Delegate*)'
  b'MessageLoop::Run()'
  b'nsThread::ThreadFunc(void*)'
  b'_pt_root'
  b'set_alt_signal_stack_and_start(PthreadCreateParams*)'
  b'start_thread'

sudo stackcount-bpfcc -i 2 -p 152169 --debug "*amdgpu*"
sudo stackcount-bpfcc -i 2 -p 152169 --debug "*tcp_recv*"

sudo stackcount-bpfcc -p 152169 --debug "*tcp_connect*"

info proc
shell ls /proc/134785/fd/ -l
head -n 1 /proc/134785/net/tcp; grep 526689 /proc/134785/net/tcp

./mach run --debug

PR_Sleep(PR_SecondsToInterval(10));

nsHtml5Parser

mk_add_options AUTOCLOBBER=1
vim mozconfig

touch /home/tannal/tannalwork/projects/mozilla-unified/obj-x86_64-pc-linux-gnu/CLOBBER

https://github.com/mozilla/gecko-dev/commits?author=emilio

https://github.com/mozilla/gecko-dev/commits?author=tiaanl

65:42.06 If you are building Firefox often, SCCache can save you a lot of time. You can learn more h
ere: https://firefox-source-docs.mozilla.org/setup/configuring_build_options.html#sccache
To take your build for a test drive, run: |mach run|
For more information on what to do now, see https://firefox-source-docs.mozilla.org/setup/contributi
ng_code.html

Make use of Cargo dependencies, but vendor them in monorepo.

Continuous integration can't rely on external network.

Benjamin Smedberg

https://www.joshmatthews.net/fosdem/#slide-7

#developers - high traffic, general Gecko-related development
#jsapi - JavaScript engine development
#gfx - graphics/rendering discussion
#content - DOM implementation
#fx-team - Firefox frontend development
#necko - Networking stack development
#mobile - Firefox for Android development
#b2g - Firefox OS development

# Get the code, build, run, debug, logging, lsp

firefox use mercurial instead of git for versioning control.

# community

https://groups.google.com/a/mozilla.org/g/firefox-dev

https://chat.mozilla.org/#/room/#introduction:mozilla.org

https://codetribute.mozilla.org/projects/devtools

https://nnethercote.github.io/about-me.html

https://blog.mozilla.org/javascript/

# reference

https://colin-cazabet.medium.com/how-to-start-contributing-to-firefox-ebad014d9f1