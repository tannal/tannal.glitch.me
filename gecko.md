# dev

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

https://chat.mozilla.org/#/room/#introduction:mozilla.org

https://codetribute.mozilla.org/projects/devtools

https://nnethercote.github.io/about-me.html

https://blog.mozilla.org/javascript/

# reference

https://colin-cazabet.medium.com/how-to-start-contributing-to-firefox-ebad014d9f1