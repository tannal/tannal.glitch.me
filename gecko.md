# inbox

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


hg pull && hg update

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


$env:RUST_LOG="debug"


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

https://survey.stackoverflow.co/2023/

mach


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




# directory structure

gfx/

servo/

python/


# community

https://chat.mozilla.org/#/room/#introduction:mozilla.org

https://codetribute.mozilla.org/projects/devtools

# reference

https://colin-cazabet.medium.com/how-to-start-contributing-to-firefox-ebad014d9f1