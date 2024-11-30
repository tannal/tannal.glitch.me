# dev

./mach test-wpt ./tests/wpt/tests/css/css-flexbox/flex-factor-less-than-one.html
# tests

http://lobste.rs
radicle.xyz


./mach run --bin target/profiling/servo -p 5 https://www.cnn.com/
./mach run --bin target/profiling/servo -p 5 https://lobste.rs

Error initializing controller for "section" on "<div data-uri="cms.cnn.com/_components/section/instances/clg35wfxm004z47qb0l3pcubw@published" class="section" role="main" data-drag-disable="true" data-unselectable="true">" (new ReferenceError("IntersectionObserver is not defined", "https://edition.cnn.com/", 13024))
[2024-10-15T14:44:20Z ERROR script::dom::bindings::error] Error at https://edition.cnn.com/:12908:456 ResizeObserver is not defined
ModuleFlags:  {"DOM": 1, "INTL": 2, "ADF": 4}
ad-slot: Failed to request ads - (new ReferenceError("IntersectionObserver is not defined", "https://edition.cnn.com/", 12828))
collectorUrl //collector.cdp.cnn.com
[2024-10-15T14:44:22Z ERROR script::dom::bindings::error] Error at https://ads.stickyadstv.com/auto-user-sync:1:7 illegal character U+0001
[2024-10-15T14:44:22Z ERROR script::dom::bindings::error] Error at https://edition.cnn.com/:2:24135 s.manageVars is not a function
[2024-10-15T14:44:22Z ERROR script::dom::htmlmediaelement] Player error: "Error from element /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin3/GstDecodeBin:decodebin3/avdec_h264:avdec_h264-0: Could not decode stream.\nNo valid frames decoded before end of stream\n../gst-libs/gst/video/gstvideodecoder.c(1416): gst_video_decoder_sink_event_default (): /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin3/GstDecodeBin:decodebin3/avdec_h264:avdec_h264-0:\nno valid frames found"
[2024-10-15T14:44:22Z ERROR script::dom::htmlmediaelement] Player error: "Error from element /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin4/GstDecodeBin:decodebin4/avdec_h264:avdec_h264-1: Could not decode stream.\nNo valid frames decoded before end of stream\n../gst-libs/gst/video/gstvideodecoder.c(1416): gst_video_decoder_sink_event_default (): /GstPlayBin:playbin/GstURIDecodeBin:uridecodebin4/GstDecodeBin:decodebin4/avdec_h264:avdec_h264-1:\nno valid frames found"
[GPT] Legacy browser does not support intersection observer causing lazy render/fetch as well as viewability events not to work properly.
https://goo.gle/gpt-message#150
[2024-10-15T14:44:24Z ERROR script::dom::bindings::error] Error at https://1f2e7.v.fwmrm.net/ad/u?nw=127719&dpid=127719&token=b8ce708402a6286faf64c964294f2046&gif=1&buid=b2231b5accf50d6c24cf6f326c10fc&_fw_gdpr=0&_fw_gdpr_consent=&_fw_gdpr=0&_fw_gdpr_consent=:1:7 illegal character U+0001


ResizeObserver
IntersectionObserver

## Text Selection in servo

https://github.com/servo/servo/issues/4409

## HTML5 forms in servo


./mach run ./tests/wpt/tests/css/css-tables/border-collapse-dynamic-section.html -- --debug trace-layout
./mach run --debugger --devtools=6080 ./tests/wpt/tests/css/css-tables/border-collapse-dynamic-section.html -- --debug dump-display-list

./mach test-wpt ./tests/wpt/tests/css/css-tables/border-collapse-dynamic-row-001


./mach run -d -- ./tests/wpt/tests/css/css-tables/border-collapse-dynamic-row-001

./mach try

RUST_BACKTRACE=1

unused pref

webrender

RUST_LOG="debug" ./mach run /home/tannal/ -i -y 1 /tmp/a.html 2>&1 | ts -s "%.S: " | tee /tmp/log.txt

servo book
cargo install mdbook
cargo install mdbook-mermaid
mdbook serve --open

RUST_LOG="debug" ./mach run --pref dom.webgpu.enabled https://browserbench.org/ 
RUST_LOG="debug" ./mach run --pref dom.webgpu.enabled https://browserbench.org/MotionMark1.3 -i -y 1 /tmp/a.html 2>&1 | ts -s "%.S: " | tee /tmp/log.txt


https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf.tar.xz

export PKG_CONFIG_SYSROOT_DIR=/usr/aarch64-linux-gnu/
./mach build -t aarch64-unknown-linux-gnu

./mach run --pref dom.webgpu.enabled https://demo.servo.org/experiments/webgpu-game-of-life/

./mach run http://browserbench.org/Speedometer/

sudo perf record -F 99 -p `pgrep -n servo` -g -- sleep 30
sudo perf script > out.servostacks01

./stackcollapse-perf.pl < out.servostacks01 | ./flamegraph.pl > ./out.servostacks01.svg


```md
<!-- Please describe your changes on the following line: -->
''=

---
<!-- Thank you for contributing to Servo! Please replace each `[ ]` by `[X]` when the step is complete, and replace `___` with appropriate data: -->
- [ ] `./mach build -d` does not report any errors
- [ ] `./mach test-tidy` does not report any errors
- [ ] These changes fix #___ (GitHub issue number if applicable)

<!-- Either: -->
- [ ] There are tests for these changes OR
- [ ] These changes do not require tests because ___

<!-- Also, please make sure that "Allow edits from maintainers" checkbox is checked, so that we can help you if you get stuck somewhere along the way.-->

<!-- Pull requests that do not address these steps are welcome, but they will require additional verification as part of the review process. -->

```

./mach run -d -- --debug help

$env:RUST_LOG="debug" # Setting environment variable

rust-gdb ./target/debug/servo

./target/debug/servo ./tests/wpt/tests/css/css-text/text-transform/math/text-transform-math-auto-001.html
r ./tests/wpt/tests/css/css-text/text-transform/math/text-transform-math-auto-001.html
./mach run -d -- ./tests/wpt/tests/css/css-text/text-transform/math/text-transform-math-auto-001.html
./mach run -d -- ./tests/wpt/tests/css/css-tables/tentative/table-width-redistribution.html

r ./tests/wpt/tests/css/css-tables/tentative/table-width-redistribution.html

b components/layout_2020/table/layout.rs:411

./mach run --debugger=rr -- ./tests/wpt/tests/css/css-tables/tentative/table-width-redistribution.html

./mach run -d -- --debug dump-display-list test.html -z
./mach run -d -- --debug show-fragment-borders servo.org -z

./mach run --pref dom.svg.enabled https://vuejsfeed.com/
./mach run --pref dom.svg.enabled https://hn.algolia.com/ -i -y 1 2>&1 | % {
    # Adding timestamp using Get-Date and formatting output
    "$(Get-Date -Format "HH:mm:ss.fff"): $_"
} | Out-File -FilePath "log.txt"

./mach test-tidy --no-progress --all

RUST_LOG="debug" ./mach run -d -- http://192.168.43.1:8080/quill.html -i -y 1 /tmp/a.html 2>&1 | ts -s "%.S: " | tee /tmp/log.txt

RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb ~/tannalwork/cans/test.html 2>&1 | tee /tmp/log.txt
./mach run ~/tannalwork/cans/test.html 


./mach test-wpt --debugger=rust-gdb ./tests/wpt/tests/css/css-values/calc-size/animatio
n/calc-size-height-interpolation.tentative.html

./mach run --debugger-cmd=rust-gdb ~/tannalwork/cans/test.html

./mach test-wpt ./tests/wpt/tests/css/css-values/calc-size/animation/calc-size-height-interpolation.tentative.html
./mach test-wpt ./tests/wpt/tests/css/css-borders/tentative/parsing/border-bottom-radius-valid.html


RUST_LOG="debug" ./mach run about:blank --debugger-cmd=rust-gdb -i -y 1 /tmp/a.html 2>&1 | tee /tmp/log.txt

RUST_LOG="debug" ./mach run about:blank -i -y 1 /tmp/a.html 2>&1 | ts -s "%.S: " | tee /tmp/log.txt

RUST_LOG="debug" ./mach test-wpt --debugger=rust-gdb ./tests/wpt/tests/html/browsers/browsing-the-web/navigating-across-documents/initial-empty-document/load-pageshow-events-iframe-contentWindow.html

./mach test-wpt ./tests/wpt/tests/html/browsers/browsing-the-web/navigating-across-documents/initial-empty-document/load-pageshow-events-iframe-contentWindow.html

./mach test-wpt ./tests/wpt/tests/workers/postMessage*
./mach test-wpt --debugger=rust-gdb ./tests/wpt/tests/workers/postMessage*

RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb  -- -Z dump-style-tree ~/tannalwork/cans/whitespace.html -i -y 1 /tmp/a.html 2>&1 | tee /tmp/log.txt

./mach test-unit --nocapture -- test_column_width


./mach run -d -- -Z dump-style-tree
./mach run -d -- -Z help
./mach test-wpt ./tests/wpt/tests/css/CSS2/text/text-indent*
./mach test-wpt ./tests/wpt/tests/css/CSS2/text/text-transform* 
RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb https://www.baidu.com 2>&1 | tee /tmp/log.txt
RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb https://youtube.com
RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb http://browserbench.org/Speedometer/
RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb http://localhost:8000/css/CSS2/cascade/inherit-computed-001.html
RUST_LOG="debug" ./mach test-wpt --debugger=rust-gdb ./tests/wpt/tests/html/semantics/embedded-content/the-video-element/video_size_preserved_after_ended.html 2>&1 | tee /tmp/log.txt
RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb ./tests/wpt/tests/html/semantics/embedded-content/the-video-element/video_size_preserved_after_ended.html 2>&1 | tee /tmp/log.txt
RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb ~/tannalwork/cans/event.html 
RUST_LOG="debug" ./mach test-wpt --debugger=rust-gdb ./tests/wpt/tests/css/CSS2/cascade/inherit-computed-001.html
RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb ~/tannalwork/cans/css-tables-example8.html

RUST_LOG="debug" ./mach run --debugger-cmd=rust-gdb  -- -Z dump-style-tree ~/tannalwork/cans/parser.html -i -y 1 /tmp/a.html 2>&1 | tee /tmp/log.txt
RUST_LOG="debug" ./mach test-wpt --debugger=rust-gdb ./tests/wpt/tests/css/CSS2/tables/empty-cells-no-interpolation.html
RUST_LOG="debug" ./mach test-wpt --debugger=rust-gdb ./tests/wpt/tests/xhr/send-redirect.htm
RUST_LOG="debug" ./mach run baidu.com --debugger-cmd=rust-gdb -i -y 1 /tmp/a.html 2>&1 | tee /tmp/log.txt


# setup

    Updating git repository `https://github.com/servo/media`
    Updating git repository `https://github.com/servo/webxr`
    Updating git repository `https://github.com/servo/stylo`
    Updating git repository `https://github.com/servo/webrender`
    Updating git repository `https://github.com/servo/rust-cssparser`
    Updating git repository `https://github.com/servo/fontsan`
    Updating git repository `https://github.com/pcwalton/signpost.git`
    Updating git repository `https://github.com/gfx-rs/wgpu`
    Updating git repository `https://github.com/servo/mozjs`

```bash

git clone https://github.com/servo/servo/
sudo apt install python3.10-venv
export PIP_EXTRA_INDEX_URL=https://pypi.tuna.tsinghua.edu.cn/simple
pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
mach bootstrap
mach build

sudo apt update && sudo apt install git python3-pip m4
git clone https://www.github.com/servo/servo
pip install virtualenv --break-system-packages
curl --proto 'ls=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

./mach bootstrap

time ./mach build


```

```json
// .vscode/settings.json
{
    "rust-analyzer.check.overrideCommand": [
        "./mach", "check", "--message-format=json" ],
    "rust-analyzer.cargo.buildScripts.overrideCommand": [
        "./mach", "check", "--message-format=json" ],
    "rust-analyzer.rustfmt.overrideCommand": [ "./mach", "fmt" ],
}


{
    "rust-analyzer.check.overrideCommand": [
        "./mach.bat", "check", "--message-format=json" ],
    "rust-analyzer.cargo.buildScripts.overrideCommand": [
        "./mach.bat", "check", "--message-format=json" ],
    "rust-analyzer.rustfmt.overrideCommand": [ "./mach.bat", "fmt" ],
}


```



# people

Daniel Adams

involves:nicoburns
involves:sagudev
involves:wusyong
involves:gterzian
involves:jdm

involves:delan
involves:mrobinson
involves:mrego
involves:atbrakhi
involves:Loirooriol
involves:cathiechen

involves:mrego
involves:mrobinson
involves:jdm
involves:kvark
involves:mukilan
involves:SimonSapin
involves:asajeffrey
involves:delan
involves:emilio
involves:Manishearth
involves:glennw
involves:pshaughn
involves:gterzian
involves:CYBAI
involves:sagudev
involves:atbrakhi


# inbox

set logging enabled on

set breakpoint pending on
rb ::*

A Pipeline is the constellation's view of a Window. Each pipeline has an event loop (executed by a script thread). A script thread may be responsible for many pipelines.

since change
layout
https://github.com/servo/servo/commit/9c0561536d37f64c028d67648091a314b5b88f6f

App->servo will create_constellation in other threads

constellation will new_pipeline append it to pipelines

```rs
pub struct App {
    servo: Option<Servo<dyn WindowPortsMethods>>,
    webviews: RefCell<WebViewManager<dyn WindowPortsMethods>>,
    event_queue: RefCell<Vec<EmbedderEvent>>,
    suspended: Cell<bool>,
    windows: HashMap<WindowId, Rc<dyn WindowPortsMethods>>,
    minibrowser: Option<RefCell<Minibrowser>>,
}
```
App->servo->

App->minibrwser->
embedder

pub use crate::compositor::{CompositeTarget, IOCompositor, ShutdownState};


window
- compositor
- constellation_chan
- embedder_receiver


pub struct Reflector {
    #[ignore_malloc_size_of = "defined and measured in rust-mozjs"]
    object: Heap<*mut JSObject>,
}

FlexFlow
- Vec<FlexItem>
- Vec<FlexLine>


style
gfx
webrender
script
surfman

b document.rs:666



https://groups.google.com/g/mozilla.dev.servo

https://github.com/servo/servo/ m1[00/20218

```
<script>
    setTimeout(_=>{
      document.createRange().insertNode(document.createElement("a"));
      document.writeln("tanmeng");


      document.close();
    });
    </script>
```



Pipeline
-EventLoop
BrowserContext
Document


modified:   tests/wpt/meta/workers/postMessage_block.https.html.ini

IntersectionObserver
Navigation API



[2024-04-04T00:54:36Z ERROR script::dom::bindings::error] Error at file:///home/tannal/tannalwork/cans/whitespace.html:15:5 navigation is not defined

larsberg, jdm, pcwalton, jack, simonsapin, nox, ms2ger, mbrubeck, edunham, ajeffrey, till

matching CSS selectors
laying out general elements
text processing

https://github.com/servo/servo/issues/2382

servo research 
https://lmeyerov.github.io/
https://www.rohitzambre.com/

servo founders
Lars Bergstrom 
involves:larsbergstrom
Brian Anderson
involves:brson
Manish Goregaokar 
involves:Manishearth


Keegan McAllister https://github.com/kmcallister
invovles:kmcallister
SharedArrayBuffer


script thread 
#[derive(Debug)]
enum MixedMessage {
    FromConstellation(ConstellationControlMsg),
    FromScript(MainThreadScriptMsg),
    FromDevtools(DevtoolScriptControlMsg),
    FromImageCache((PipelineId, PendingImageResponse)),
    FromWebGPUServer(WebGPUMsg),
}

Constellation handle msg from script thread and layout thread



EmbedderEvent send event to compositor handle hittest

compositor send event to Constellation

Constellation forward event to script 

set logging enabled on


tokio thread tokio::runtime::blocking::pool::Spawner::spawn_thread


cookie
https://github.com/servo/servo/issues/8700

ResizeObserver
https://github.com/ResponsiveImagesCG/newsletters/issues/301
https://github.com/servo/servo/pull/31108


https://github.com/servo/servo/issues/17715

https://github.com/servo/servo/issues/31807

https://github.com/servo/servo/issues/2382

https://github.com/servo/media/issues/309
https://github.com/servo/servo/issues/24211

https://github.com/servo/servo/issues/24759
https://github.com/servo/servo/issues/26700
https://github.com/servo/servo/issues/15043

https://github.com/servo/servo/issues/23865
https://github.com/servo/servo/issues/24901
https://github.com/servo/servo/issues/25514


	bubble-inline-sizes-separately      Bubble intrinsic widths separately like other engines.
	convert-mouse-to-touch              Send touch events instead of mouse events
	disable-canvas-aa                   Disable antialiasing on the HTML canvas element.
	disable-share-style-cache           Disable the style sharing cache.
	disable-subpixel-aa                 Disable subpixel text antialiasing overriding preference.
	disable-text-aa                     Disable antialiasing of rendered text.
	dump-stacking-context-tree          Print the stacking context tree after each layout.
	dump-display-list                   Print the display list after each layout.
	dump-display-list-json              Print the display list in JSON form.
	dump-flow-tree                      Print the flow tree (Layout 2013) or fragment tree (Layout 2020) after each layout.
	dump-rule-tree                      Print the style rule tree after each layout.
	dump-style-tree                     Print the DOM with computed styles after each restyle.
	dump-style-stats                    Print style statistics each restyle.
	gc-profile                          Log GC passes and their durations.
	load-webfonts-synchronously         Load web fonts synchronously to avoid non-deterministic network-driven reflows
	parallel-display-list-building      Build display lists in parallel.
	precache-shaders                    Compile all shaders during init.
	profile-script-events               Enable profiling of script-related events.
	relayout-event                      Print notifications when there is a relayout.
	replace-surrogates                  Replace unpaires surrogates in DOM strings with U+FFFD. See https://github.com/servo/servo/issues/6564
	show-fragment-borders               Paint borders along fragment boundaries.
	show-parallel-layout                Mark which thread laid each flow out with colors.
	signpost                            Emit native OS signposts for profile events (currently macOS only)
	trace-layout                        Write layout trace to an external file for debugging.
	wr-stats                            Show WebRender profiler on screen.



canvas/offscreen

libaom

b handle_stylesheet_url

document_from_node


cssparser
    tokenizer


rust-gdb /vagrant/target/debug/deps/libzfs-37d0dad38d98d030

r --test



servo

impl CompositorReceiver {
    pub fn try_recv_compositor_msg(&mut self) -> Option<CompositorMsg> {
        self.receiver.try_recv().ok()
    }
    pub fn recv_compositor_msg(&mut self) -> CompositorMsg {
        self.receiver.recv().unwrap()
    }
}



lazy_static

https://github.com/servo/servo/issues/31648



Windowproxy
#[no_trace]
[allow(unsafe_code)]

p *(char*)buf

Promise.resolve()
    .then(() => console.log(1));

queueMicrotask(() => console.log(2));

setTimeout(() => console.log(3), 0);

console.log(4);

new Promise(() => console.log(5));

(async () => console.log(6))();

b __libc_write if fd < 3

Fix support for the DevTools protocol in Servo


Add support for language-specific `text-transform` behavior
https://drafts.csswg.org/css-text/#text-transform
https://github.com/chromium/chromium/commits?author=tkent-google
https://github.com/search?q=repo%3Achromium%2Fchromium+text-transform&type=commits


https://github.com/servo/servo/commits?author=sagudev CI


rust default allocator is jemalloc

The reference to use-system-allocator = ["libc"] seems to be a configuration snippet possibly from a Cargo.toml file for a Rust project, specifying a dependency feature. In Rust projects, this line would indicate that a crate is configured to use the system's allocator (typically provided by libc) instead of Rust's default allocator. 

https://github.com/servo/servo/commits/?author=atbrakhi

#[dom_struct]
pub struct Event {
    reflector_: Reflector,
    current_target: MutNullableDom<EventTarget>,
    target: MutNullableDom<EventTarget>,
}

constellation send event to script thread

script_thread handle_event -> document.dispatch

Event self.getTarget -> Node -> Node -> VirtualMethod -> htmlinputelement


rust-gdb

script::dom::htmlinputelement::HTMLInputElement
script::script_thread::ScriptThread::handle_msgs


https://github.com/search?q=repo%3Aservo%2Fservo%20pub%20struct%20EventTarget&type=code

pub struct Element {
    node: Node,

}

pub struct Node {
    /// The JavaScript reflector for this node.
    eventtarget: EventTarget,


C:\Users\tannal\tannalwork\projects\servo\components\shared\embedder\lib.rs
impl EmbedderProxy {
    pub fn send(&self, msg: (Option<TopLevelBrowsingContextId>, EmbedderMsg)) {
        // Send a message and kick the OS event loop awake.
        if let Err(err) = self.sender.send(msg) {
            warn!("Failed to send response ({:?}).", err);
        }
        self.event_loop_waker.wake();
    }
}

script_thread handle_msg from xxx 



sudo apt install moreutils

servo/components/shared/embedder
/resources.rs

HTML5 Forms

HTMLInputElement

components\script\dom\htmlinputelement.rs



box and interator in rust

Top level functions & functions always appear in the bottom callstack
components/layout_2020/flow/construct.rs BlockContainer Builder finish()

let collapsed_string: String = collapsed.collect();

ifc Inline formating context

components\style\values\specified\text.rs

match_ignore_ascii_case!

./mach run -d -- -i -y 1 2>&1 | % {
    # Adding timestamp using Get-Date and formatting output
    "$(Get-Date -Format "HH:mm:ss.fff"): $_"
} | Out-File -FilePath "log.txt"


$env:RUST_LOG="debug" # Setting environment variable
./mach run -d -- ./tests/wpt/tests/css/CSS2/text/text-transform-001.xht -i -y 1 2>&1 | % {
    # Adding timestamp using Get-Date and formatting output
    "$(Get-Date -Format "HH:mm:ss.fff"): $_"
} | Tee-Object -FilePath "log.txt"

./mach run -d -- ./tests/wpt/tests/css/CSS2/linebox/crashtests/dir-change-simplifed-crash.html

./mach run -d -- ./tests/wpt/tests/html/semantics/embedded-content/the-video-element/intrinsic_sizes.htm

./mach run -d -- ./tests/wpt/tests/html/canvas/element/text/parent-style-relative-units.htm



CodegenRust.py

Custom Attribute

https://github.com/servo/servo/issues/30822

pgrep -l servo
pstree -p 29349
ps -T -p 29349

LayoutPipeLine

session history chrome://history/

00.376324:  [2024-01-19T05:42:55Z DEBUG constellation::constellation] Pipeline(1,1): Creating new pipeline in BrowsingContext(0,1)

https://www.youtube.com/watch?v=PyfY82-NDCM

https://github.com/servo/servo/issues/30862

# threads & subproccesses

```
"servo" 
"servo:cs0"
"servo:disk$0"
"servo:sh0"   
"servo:shlo0" 
"servo:gdrv0" 
"servo:sh1"   
"servo:sh2" 
```

![Alt text](./image-10.png)
components/layout_thread_2020/lib.rs:261 layout thread
components/script/script_thread.rs:840 script thread
components/style/global_style_data.rs:64
mozjs thread jsHelper
servo media gstreamer
components/net/resource_thread.rs resource manager

components/background_hang_monitor/background_hang_monitor.rs
detect when these background tasks become unresponsive or "hang."

components/bluetooth/lib.rs

third_party/webrender/webrender/src/renderer/mod.rs:1269 web render thread

third_party/webrender/webrender/src/renderer/mod.rs:1191 web render scene builder

webrender worker thread same as the core number



# types

A strong reference to a rule node.
use crate::rule_tree::StrongRuleNode; style crate rule_tree module type StrongRuleNode

ScriptThread
LayoutThread

ScriptThread
 - handle_msgs
 - 


# dependency

url 2.5.0

```
pub enum Host<S = String> {
    Domain(S),
    Ipv4(Ipv4Addr),
    Ipv6(Ipv6Addr),
}

```

## windows

```
choco install python311

setx PYTHON3 "C:\Python11\python.exe" /m

setx PYTHON3 "C:\Python12\python.exe" /m

vs_BuildTools.exe^
    --add Microsoft.VisualStudio.Component.Roslyn.Compiler^
    --add Microsoft.Component.MSBuild^
    --add Microsoft.VisualStudio.Component.CoreBuildTools^
    --add Microsoft.VisualStudio.Workload.MSBuildTools^
    --add Microsoft.VisualStudio.Component.Windows10SDK^
    --add Microsoft.VisualStudio.Component.Windows10SDK.20348^
    --add Microsoft.VisualStudio.Component.VC.CoreBuildTools^
    --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64^
    --add Microsoft.VisualStudio.Component.VC.Redist.14.Latest^
    --add Microsoft.VisualStudio.Component.VC.ATL^
    --add Microsoft.VisualStudio.Component.VC.ATLMFC^
    --add Microsoft.VisualStudio.Component.TextTemplating^
    --add Microsoft.VisualStudio.Component.VC.CoreIde^
    --add Microsoft.VisualStudio.ComponentGroup.NativeDesktop.Core^
    --add Microsoft.VisualStudio.Workload.VCTools


$ v := vec(x_1, x_2, x_3) $





https://starters.servo.org/

set MOZTOOLS_PATH=C:\Users\tannal\Downloads\moztools-4.0\moztools-4.0\
set LIBCLANG_PATH=C:\Program Files\LLVM\lib

```


WebIDL

unsafe keyword in rust

https://github.com/servo/servo/issues/30862

In components/script, remove unsafe JS related code

 creating a rooted JSObject



# layout 2020


box tree
                -> stacking context tree -> WebRender display list
fragment tree

For example, when a text sequence is broken into multiple lines or a block is broken across columns or pages, it yields multiple fragments in the tree.

```rust

pub struct DisplayList {
    pub list: Vec<DisplayItem>,
    pub clip_scroll_nodes: Vec<ClipScrollNode>,
}
```

# servo docs/wiki is outdated

many errors and troubleshooting need to do when go through the docs on computer.

I'm planning to improve some docs.

need some feedback from the servo team.

# good first issues

https://github.com/servo/servo/issues/31006 

https://github.com/servo/servo/issues/31007

# issue tags

E-candidate-for-mentoring https://github.com/servo/servo/labels/E-candidate-for-mentoring

A-content/script https://github.com/servo/servo/labels/A-content%2Fscript

# issues

Implement ResizeObservers

```bash

./mach test-wpt --production _webgpu

./mach test-wpt tests/wpt/tests/dom/events/relatedTarget.window.js

./mach test-wpt tests/wpt/tests/dom/events/relatedTarget.window.js

./mach test-wpt ./tests/wpt/meta/css/CSS2/text/text-transform* 

```

https://servo.org/blog/

https://wpt.servo.org/

https://github.com/servo/servo/wiki/Servo-Layout-Engines-Report

cross platform windows linux macos android

embeddedable dioxus tauri Delta chat

dependency bot update dependecies version

jsdom jest

take advantage of dom implementation of servo

create 

Q: Where does the code change window sizing

window
  headed_window
  headless_window

browser
  window: Rc<Window>

compositor
  window: Rc<Window, Global>


constellation: Constellation<Message, LTF, STF, SWF>
  window_size: 
  shutting_down:
  get_event_loop()
  new_pipeline()

```rust
#0  servo::headed_window::Window::new
    (win_size=..., events_loop=0x7fffffff8290, no_native_titlebar=false, device_pixel_ratio_override=...) at ports/servoshell/headed_window.rs:145
#1  0x0000555556085f98 in servo::app::App::run
    (no_native_titlebar=false, device_pixel_ratio_override=..., user_agent=..., url=...) at ports/servoshell/app.rs:75
#2  0x000055555609360d in servo::main2::main ()
    at ports/servoshell/main2.rs:139
#3  0x0000555556164c16 in servo::main () at ports/servoshell/main.rs:62

```

components/servo/lib.rs

style/

script/ mozjs

constellation/

layout_thread_2020/

# servo architecture

event system

native fullscreen

fullscreen web api

# code search

Matching complex selector

mach run

sudo apt install moreutils

RUST_LOG="debug" ./mach run -d -- -i -y 1 /tmp/a.html 2>&1 | ts -s "%.S: " | tee /tmp/log.txt

RUST_LOG="debug" ./mach run -d -- -i -y 1  2>&1 | ts -s "%.S: " | tee /tmp/log.txt

$env:RUST_LOG="debug" # Setting environment variable
./mach run -d -- -i -y 1 2>&1 | % {
    # Adding timestamp using Get-Date and formatting output
    "$(Get-Date -Format "HH:mm:ss.fff"): $_"
} | Tee-Object -FilePath "log.txt"


./mach test-wpt tests/wpt/tests/dom/events/relatedTarget.window.js

llvm git cmake python python-virtualenv wixtoolset ninja vs2019

sudo apt install libopts25-dev m4
sudo apt install libots-dev


```bash
// script_thread.rs
handle_resize_inactive_msg

```

author:mrobinson
author:bors-servo
author:Loirooriol
author:emilio
author:sagudev
author:mukilan
author:delan
author:jdm
author:atbrakhi
author:servo-wpt-sync
author:eerii
author:atouchet
author:BorisChiou
author:oluwatobiss
author:jschwe
author:Taym95
author:michaelgrigoryan25
author:jfkthame
author:yvt
author:stshine
author:dshin-moz
author:CYBAI
author:gterzian
author:aethanyc
author:fabricedesre
author:canova
author:KiChjang
author:Manishearth
author:frewsxcv
author:upsuper


speedmeter
author:flashdesignory
author:camillobruni
author:julienw
author:rniwa
author:bgrins
author:lpardosixtosMs
author:issackjohn
author:squarewave
author:rictic
author:sulekhark
author:danielroe
author:mstange
author:mroderick
author:ZevEisenberg
author:kkuegler
author:dholbert
author: