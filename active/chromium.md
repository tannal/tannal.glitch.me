
# New Porjects

z-index 处理DOM元素的遮挡顺序
overflow 属性控制内容遮挡
box-shadow 会考虑遮挡效果
opacity 会影响遮挡处理

git cl upload -b 385925149

gdb --args out/Default/chrome test.html


WebGPU
Project Fugu (Web Capabilities)
Privacy Sandbox
WebAssembly
Web Environment Integrity
Passkeys
WebGPU + WebNN

# 2025

Browser Process (主进程)
    |-> UI Thread (界面绘制)
    |-> Network Thread (网络请求)
    |-> Storage Thread (存储)
    |-> GPU Thread (GPU任务协调)
    |-> Plugin Thread (插件管理)
    |-> Extension Thread (扩展管理)
    ↓

Renderer Process (渲染进程, 每个标签页一个)
    |-> Main Thread (主线程)
        |-> Parsing (HTML解析)
        |-> DOM Tree Construction
        |-> Style Calculation
        |-> Layout
        |-> Paint
    |-> Compositor Thread (合成线程)
        |-> Layer Management
        |-> Frame Production
    |-> V8 Thread(s)
        |-> Main V8 Thread
        |-> GC Thread(s)
        |-> Compiler Thread(s)
            - JIT Compilation
            - Optimization
            - Deoptimization
    |-> Web Worker Thread(s)
    |-> Raster Thread(s)
    |-> IO Thread
    ↓

GPU Process (GPU进程, 整个浏览器共享)
    |-> Command Buffer
    |-> Hardware Acceleration
    |-> Compositing
    |-> Video Decode

其他进程:
- Plugin Process (插件进程)
- Utility Process (工具进程)
- Extension Process (扩展进程)
- Network Service Process (网络服务进程)

触摸/滚轮事件 -> 合成线程 -> GPU进程
                   |
                   不经过主线程

// 初始化时
Main Thread: 创建层树和事件区域
    ↓
Compositor: 获得独立的层信息和事件处理权限
    ↓
GPU Process: 维护实际图层和处理合成

// JS阻塞时
Main Thread: 阻塞 ❌
Compositor: 继续处理输入 ✅
GPU Process: 继续渲染和合成 ✅

无合成滚动:
JS -> Style -> Layout -> Paint -> Composite
                 ↑         ↑
            每帧都执行   每帧都执行

合成滚动:
JS -> Transform Update -> Composite
           ↑
      只更新矩阵

# Acsii

LayoutObject (基类)
    ^
    |
LayoutBox
    ^
    |
LayoutBlockFlow
    |
    +-- MultiColumnFlowThread
    +-- FirstChild
    +-- NextSibling

LayoutInputNode (基类)
    ^
    |
    +-- BlockNode
    +-- InlineNode

LayoutReplaced 对象布局示意图:

+------------------------------------------+
|             LayoutReplaced               |
|  +----------------------------------+    |
|  |        frame_location_           |    |
|  |     (x_=768, y_=768)            |    |
|  |  +----------------------------+  |    |
|  |  |      frame_size_          |  |    |
|  |  |   width=39168/64=612px    |  |    |
|  |  |   height=22032/64=344px   |  |    |
|  |  |                           |  |    |
|  |  |     Content Area          |  |    |
|  |  |                           |  |    |
|  |  |                           |  |    |
|  |  +----------------------------+  |    |
|  +----------------------------------+    |
|                                          |
|  intrinsic_size_:                       |
|  width=19200/64=300px                   |
|  height=9600/64=150px                   |
+------------------------------------------+

固定点数表示 (6位小数):
           整数部分        小数部分
    +----------------+----------------+
    |     26位      |      6位      |
    +----------------+----------------+

    例如: 768 (frame_location_.x_)
    二进制: 0000 0011 0000 0000
    实际值: 12px (768/64)

布局结果缓存:
    layout_results_
    +-------------+
    | LayoutResult|
    +-------------+
    | size = 1    |
    +-------------+

继承层次:
    LayoutObject
         ↓
    LayoutBoxModelObject
         ↓
    LayoutBox
         ↓
    LayoutReplaced

浮点矩形 (3.2, 2.7, 5.6, 4.1)
+------------------------+
|                        |
|    (3.2,2.7)          |
|        +------------+  |
|        |            |  |
|        |   RectF    |  |
|        |            |  |
|        +------------+  |
|                    (8.8,6.8)
|                        |
+------------------------+

包围矩形 (3,2, 6,5)
+------------------------+
|                        |
|    (3,2)              |
|    +----------------+  |
|    |                |  |
|    |  EnclosingRect |  |
|    |                |  |
|    +----------------+  |
|                    (9,7)
|                        |
+------------------------+

# cookie

Windows: %LocalAppData%\Google\Chrome\User Data\Default\Network\Cookies
Linux: ~/.config/google-chrome/Default/Cookies
Mac: ~/Library/Application Support/Google/Chrome/Default/Cookies

# dev

export CHROMIUM_BUILDTOOLS_PATH=/home/tannal/tannalwork/projects/chromium/src/buildtools

https://logs.chromium.org/logs/v8/buildbucket/cr-buildbucket/8738374914303998625/+/u/compile/stdout

'C:\b\s\w\ir\out\Release\chrome.exe': 这是 Chrome 可执行文件的路径，用于指定要运行的程序。
--allow-pre-commit-input: 参数用于允许预提交输入。
--autoplay-policy=no-user-gesture-required: 设置自动播放策略，不需要用户手势。
--crash-dumps-dir=C:\b\s\w\ir\out\Release\crash-dumps\reports: 指定崩溃报告的存储目录。
--disable-background-networking: 禁用后台网络。
--disable-backgrounding-occluded-windows: 禁用被遮挡窗口的后台化。
--disable-client-side-phishing-detection: 禁用客户端钓鱼检测。
--disable-default-apps: 禁用默认应用。
--disable-hang-monitor: 禁用卡顿监控。
--disable-infobars: 禁用信息栏。
--disable-popup-blocking: 禁用弹出式窗口阻止。
--disable-prompt-on-repost: 禁用重新提交时的提示。
--disable-sync: 禁用同步。
--enable-blink-features=DisableAhemAntialias,MojoJS,MojoJSTest: 启用 Blink 引擎功能。
--enable-blink-test-features: 启用 Blink 测试功能。
--enable-crash-reporter: 启用崩溃报告。
--enable-experimental-web-platform-features: 启用实验性 Web 平台功能。
--enable-features=...: 启用一系列功能，包括一些安全和性能特性。
--enable-logging=stderr: 启用日志记录到标准错误。
'--host-resolver-rules=MAP nonexistent.*.test ^NOTFOUND,MAP *.test 127.0.0.1, MAP *.test. 127.0.0.1': 主机解析规则，用于将域名映射到特定 IP 地址。
--ignore-certificate-errors-spki-list=...: 忽略证书错误的 SPKI 列表。
--ip-address-space-overrides=...: IP 地址空间覆盖设置。
--js-flags=--expose-gc: JavaScript 引擎标志，暴露垃圾回收功能。
--log-level=0: 日志级别设置为 0。
--no-first-run: 不运行第一次启动设置。
--no-service-autorun: 不自动运行服务。
--password-store=basic: 设置密码存储类型为基本。
--remote-debugging-port=0: 远程调试端口设置为 0。
--short-reporting-delay: 短报告延迟。
--test-type=webdriver: 测试类型设置为 webdriver。
--use-fake-device-for-media-stream: 使用虚拟设备进行媒体流测试。
--use-fake-ui-for-digital-identity: 使用虚拟 UI 进行数字身份测试。
--use-fake-ui-for-fedcm: 使用虚拟 UI 进行 FedCM 测试。
--use-fake-ui-for-media-stream: 使用虚拟 UI 进行媒体流测试。
--use-mock-keychain: 使用模拟 keychain。
'--user-data-dir=C:\Windows\SystemTemp\scoped_dir4724_1664688332': 用户数据目录设置。
--webtransport-developer-mode: Web 传输开发者模式设置。
https://web-platform.test:8444/secure-payment-confirmation/authentication-cross-origin.sub.https.html: 目标网址，一个测试的网页地址。

./out/Default/chrome --js-flags='--prof' --no-sandbox 'https://bilibili.com'

sudo perf record --call-graph dwarf -F 99 -p 174161 -g -- sleep 30
sudo perf script > ./graph/out.chromiumgpuprocstacks01
./stackcollapse-perf.pl < ./graph/out.chromiumstacks01 | ./flamegraph.pl > ./graph/out.chromiumstacks01.svg

./stackcollapse-perf.pl < ./graph/out.chromiumgpuprocstacks01 | ./flamegraph.pl > ./graph/out.chromiumgpuprocstacks01.svg


./out/Default/chrome bilibili.com
--enable-gpu-benchmarking --no-sandbox --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt

sudo perf record -F 99 -p 409806 -g -- sleep 30
sudo perf script > out.chromiumstacks01

sudo perf record -F 99 -p 409910 -g -- sleep 30
sudo perf script > out.chromiumwebprocstacks01


./stackcollapse-perf.pl < out.chromiumstacks01 | ./flamegraph.pl > ./out.chromiumstacks01.svg

./stackcollapse-perf.pl < out.chromiumwebprocstacks01 | ./flamegraph.pl > ./out.chromiumwebprocstacks01.svg


```

git checkout master
git pull --rebase

gclient sync
gclient sync -D

out/Default/chrome third_party/blink/web_tests/external/wpt/css/CSS2/normal-flow/unresolvable-max-height.html
out/Default/chrome third_party/blink/web_tests/external/wpt/css/css-multicol/crashtests/
inline-become-oof-container-make-oof-inflow.html

echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope

css/CSS2/normal-flow/unresolvable-max-height.html

out/Default/chrome third_party/blink/web_tests/external/wpt/css/CSS2/normal-flow/unresolvable-max-height.html --no-sandbox --renderer-cmd-prefix='xterm -title renderer -e gdb \
    -ex run --args'

export PATH=/home/tannal/tannalwork/projects/depot_tools:$PATH

autoninja -C out/Default chrome_wpt_tests
autoninja -C out/Default chrome

autoninja -C out/Default blink_unittests
out/Default/blink_unittests --gtest_filter='InlineNodeTest.SetTextWithOffsetWithTextTransform'
out/Default/blink_unittests --test-launcher-print-test-stdio='always' --gtest_filter='FormAutofillTest.*'
out/Default/blink_unittests --test-launcher-print-test-stdio='always' --gtest_filter='ListMarkerTest.FallbackToTextWhenImagesDisable'

```

# setup

set DEPOT_TOOLS_WIN_TOOLCHAIN=0

```bash

export PATH=/home/tannal/tannalwork/projects/depot_tools:$PATH
mkdir chromium && cd chromium
fetch chromium
cd src
./build/install-build-deps.sh

gn gen out/Default
time autoninja -C out/Default chrome

ninja: Entering directory `out/Default'
[57719/57719] LINK ./chrome

real	106m52.983s
user	2379m13.189s
sys	146m59.666s

tools/clang/scripts/generate_compdb.py -p out/Default > compile_commands.json

./out/Default/chrome --enable-logging=stderr --v=1

./out/Default/chrome --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt

./out/Default/chrome --headless --disable-gpu --remote-debugging-port=9222 https://www.chromestatus.com

tar -czvf ../../../build/chrome_x86-64_linux_debug_$(date +%Y%m%d-%H%M%S)_$(git rev-parse --short HEAD).tar.gz Default/

```


# inbox

LayoutUnit

Document::RegisterNodeList

printf "%s\n",  q_name.ToString().data()
printf "%s\n",  event_type.Latin1().data()
printf "%s\n",  data.Latin1().data()
printf "%s\n",  html.Latin1().data()


document.readystate -> parsing(dom loading) -> interactive (parse done) ->

Dom use Element
layout use Node

containing_block_

```
IsA<HTML check element type
```

ClearPaintFlags

LogicalSize -> WritingModeConverter -> physicalSize

https://github.com/w3c/css-houdini-drafts/blob/main/css-layout-api/EXPLAINER.md

fieldset
A fieldset is (almost) a regular block container, and should be treated as such.

label input textarea select checkbox radio button help
<form> <button> <input> <textarea> and <label>.

p layout_results_.size()

LayoutText can get orignal text
printf "%s\n",  text.Latin1().data()

#if DCHECK_IS_ON()
call ShowTree(GetNode())


text selection
OffsetMapping

dom/text element can get LayoutText Element

./out/Default/chrome bilibili.com --enable-gpu-benchmarking --no-sandbox --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt

python3 tools/clang/scripts/generate_compdb.py -p out/Default -o ./compile_commands.json --target_os=linux

source ~/tannalwork/projects/v8/v8/tools/gdbinit

source tools/gdb/gdbinit

rb js-objects.cc:.

jst

pn

./out/Default/chrome ~/tannalwork/cans/event.html --enable-gpu-benchmarking --no-sandbox --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt


LocalFrameView::DidChangeScrollOffset()

void LocalFrameView::ScheduleRelayoutOfSubtree(LayoutObject* relayout_root) {

Element is subclass ContainerNode which is subclass Node.

Element object has a reference of LayoutTreeBuilderForElement which is subclass of LayoutTreeBuilder

StyleEngine and document is a subclass of style_engine_ parsing_state_

LocalFrame has a reference of FrameSelection which is selection_

WebFrameWidgetImpl has a reference to WebView WebViewImpl
WebViewImpl has a reference to page
the page also has a FocusController

LinkStyle knows css parser and parser_context also the result of parsing which is style_sheet

the Resource will notify some ResourceClient when reousrce is loaded.
while LinkStyle is one of the ResourceClient. and it is also LinkResource

StyleSheetContents knows CSSParser::ParseSheet

CSSParserImpl has some knoledge of its document, document->view
also a reference to CSSParserImpl
also a reference to tokenizer
it can take CSSParserContext and css string to a StyleSheetContents which is style_sheet

```cpp

  CSSTokenizer tokenizer(string);
  CSSParserTokenStream stream(tokenizer);
  CSSParserImpl parser(context, style_sheet);

  parser.ConsumeRuleList
```

the page has a reference to a chrome_client_

start from LayoutView class
there is a super long extends chian
LayoutView -> LayoutNGBlockFlow -> LayoutBlockFlow -> LayoutBlock -> LayoutBox -> LayoutBoxModelObject -> LayoutObject and more.

layout_view_ has a reference to a ComputedStyle which is style_
it can apply the ComputedStyle to

the document object has a reference to a layout_view_

dom node object can find his document object by some tree_scope stuff.

the layoutObject base class has a reference to the dom node
so a layoutobject node can find which document it belongs to.



the document loader which also has a reference to LocalFrame
also has reference to DocumentParser
and the document loader knows nothing about v8

the document has a reference to LocalDOMWindow which has frame which has LocalFrameView



throttle debounce
ShouldThrottleRendering

LocalDOMWindow has the rendering information about the client's window.
also has a reference to document_ and DOMVisualViewport
just like dom window, all the layout scrolling information come from this object.
also has script_controller_

the LocalFrame has a reference to LocalDOMWindow
also a reference to a page
also a reference to a LayoutView

so the LocalFrameView has localframe and the LocalFrame has a view_
confusing

LocalFrameView has a reference to a localframe and things like scrolling
document and layout information is typically obatined by the localframe object.

LocalFrame knows some thing about LocalFrameView
actually a LocalFrameView is a full local frame plus some knowledge of the viewport

frameloader also has a reference to a LocalFrame which is frame_
in the code it is called the client
class CORE_EXPORT LocalFrameClientImpl final : public LocalFrameClient {

A LocalFrame has a reference to a frameloader which is loader_

WebLocalFrameImpl has a reference to LocalFrame which is frame_

RenderFrameImpl knows about WebLocalFrame which is WebLocalFrameImpl

AgentSchedulingGroup also knows about RenderFrameImpl which is RenderFrameImpl

AgentSchedulingGroup has a reference to render_thread_

rb skia_renderer.cc:.

printf "%s\n",  attr_name.Latin1().data()


WidgetInputHandlerManager has a reference to web_frame_widget_impl

web_frame_widget_impl has a reference to widget_event_handler

widget_event_handler has a reference to event_handler_

event_handler has a reference to pointer_event_manager
and mouse_event_manager_ keyboard_event_manager_

```cpp
EventHandler::EventHandler(LocalFrame& frame)
    : frame_(frame),
      selection_controller_(MakeGarbageCollected<SelectionController>(frame)),
      hover_timer_(frame.GetTaskRunner(TaskType::kUserInteraction),
                   this,
                   &EventHandler::HoverTimerFired),
      cursor_update_timer_(
          frame.GetTaskRunner(TaskType::kInternalUserInteraction),
          this,
          &EventHandler::CursorUpdateTimerFired),
      should_only_fire_drag_over_event_(false),
      event_handler_registry_(
          frame_->IsLocalRoot()
              ? MakeGarbageCollected<EventHandlerRegistry>(*frame_)
              : &frame_->LocalFrameRoot().GetEventHandlerRegistry()),
      scroll_manager_(MakeGarbageCollected<ScrollManager>(frame)),
      mouse_event_manager_(
          MakeGarbageCollected<MouseEventManager>(frame, *scroll_manager_)),
      mouse_wheel_event_manager_(
          MakeGarbageCollected<MouseWheelEventManager>(frame,
                                                       *scroll_manager_)),
      keyboard_event_manager_(
          MakeGarbageCollected<KeyboardEventManager>(frame, *scroll_manager_)),
      pointer_event_manager_(
          MakeGarbageCollected<PointerEventManager>(frame,
                                                    *mouse_event_manager_)),
      gesture_manager_(
          MakeGarbageCollected<GestureManager>(frame,
                                               *scroll_manager_,
                                               *mouse_event_manager_,
                                               *pointer_event_manager_,
                                               *selection_controller_)),
      active_interval_timer_(frame.GetTaskRunner(TaskType::kUserInteraction),
                             this,
                             &EventHandler::ActiveIntervalTimerFired) {}
```

There are some static methods in html_element.cc it's kind of strange.
eg HTMLElement::HandlePopoverLightDismiss

[domattribute]forbinding is a callback when js/v8 access a attribute of a dom object
rb local_frame_view.cc:.

printf "%s\n",  text.Latin1().data()

tokenizer has a state and buffer
the buffer is a substr of input at i, j
then state says what's in the buffer

```cpp

  enum State {
    kDataState,
    kCharacterReferenceInDataState,
    kRCDATAState,
    kCharacterReferenceInRCDATAState,
    kRAWTEXTState,
    kChildNodePartStartState,
    kChildNodePartEndState,
    kScriptDataState,
    kPLAINTEXTState,
    kTagOpenState,
    kEndTagOpenState,
    kTagNameState,
    kRCDATALessThanSignState,
    kRCDATAEndTagOpenState,
    kRCDATAEndTagNameState,
    kRAWTEXTLessThanSignState,
    kRAWTEXTEndTagOpenState,
    kRAWTEXTEndTagNameState,
    kScriptDataLessThanSignState,
    kScriptDataEndTagOpenState,
    kScriptDataEndTagNameState,
    kScriptDataEscapeStartState,
    kScriptDataEscapeStartDashState,
    kScriptDataEscapedState,
    kScriptDataEscapedDashState,
    kScriptDataEscapedDashDashState,
    kScriptDataEscapedLessThanSignState,
    kScriptDataEscapedEndTagOpenState,
    kScriptDataEscapedEndTagNameState,
    kScriptDataDoubleEscapeStartState,
    kScriptDataDoubleEscapedState,
    kScriptDataDoubleEscapedDashState,
    kScriptDataDoubleEscapedDashDashState,
    kScriptDataDoubleEscapedLessThanSignState,
    kScriptDataDoubleEscapeEndState,
    kBeforeAttributeNameState,
    kAttributeNameState,
    kAfterAttributeNameState,
    kBeforeAttributeValueState,
    kAttributeValueDoubleQuotedState,
    kAttributeValueSingleQuotedState,
    kAttributeValueUnquotedState,
    kCharacterReferenceInAttributeValueState,
    kAfterAttributeValueQuotedState,
    kSelfClosingStartTagState,
    kBogusCommentState,
    // The ContinueBogusCommentState is not in the HTML5 spec, but we use
    // it internally to keep track of whether we've started the bogus
    // comment token yet.
    kContinueBogusCommentState,
    kMarkupDeclarationOpenState,
    kCommentStartState,
    kCommentStartDashState,
    kCommentState,
    kCommentEndDashState,
    kCommentEndState,
    kCommentEndBangState,
    kDOCTYPEState,
    kBeforeDOCTYPENameState,
    kDOCTYPENameState,
    kAfterDOCTYPENameState,
    kAfterDOCTYPEPublicKeywordState,
    kBeforeDOCTYPEPublicIdentifierState,
    kDOCTYPEPublicIdentifierDoubleQuotedState,
    kDOCTYPEPublicIdentifierSingleQuotedState,
    kAfterDOCTYPEPublicIdentifierState,
    kBetweenDOCTYPEPublicAndSystemIdentifiersState,
    kAfterDOCTYPESystemKeywordState,
    kBeforeDOCTYPESystemIdentifierState,
    kDOCTYPESystemIdentifierDoubleQuotedState,
    kDOCTYPESystemIdentifierSingleQuotedState,
    kAfterDOCTYPESystemIdentifierState,
    kBogusDOCTYPEState,
    kCDATASectionState,
    kCDATASectionBracketState,
    kCDATASectionEndState,
  };

```

printf "%s\n",  decoded.Latin1().data()

the document parser hold a tokenier and the input stream

when some one give some code to parser the parser just (maybe decode it first)
then append it to the inputstream


ln -sfn out/Default/gen gen

HTMLTokenizer::NextToken takes a input source which is a segmentedString
first check state

document_loader has a reference to document

document has a reference to html_document_parser

html_document_parser has a refernce to html_tree_builder.cc

html_tree_builder -> HTMLTreeBuilder

HTMLTreeBuilder has a reference to html_document_parser

htmlDocumentParser has a reference to HTMLTokenizer

HTMLTokenizer is a simple class because it's constructor params doesn't contains any complex object(just a options).

it has some state
temporary_buffer_
buffered_end_tag_name_

set logging enabled on

we actaully think about things one object at a time.

object has state

if a method doesn't change the state of a object (const)
for complex operations the object state might change

when design programs
object state

then design a method

a method a both read the state of it and write the state of it.
also for functions input and output, the same, can both write it and read it.

A object is basic a turing machine with limited state.

all methods of the object are the actually program to run.

a special case is that the constructor method, in the constructor, the object has no state, so any constuctor of a object is just remember some state, which will be used in the further.

rb third_party/blink/renderer/core/html/parser/html_construction_site.cc:.

rb eventloop.cc:.

./out/Default/chrome ~/tannalwork/cans/event.html --enable-gpu-benchmarking --no-sandbox --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt


autoninja -C out/Default chrome
autoninja -C out/Default chrome_wpt_tests

tools/clang/scripts/generate_compdb.py -p out/Default > compile_commands.json

third_party/blink/tools/run_wpt_tests.py -t Default -p chrome third_party/blink/web_tests/external/wpt/css/CSS2/cascade/* -vv

chrome

./out/Default/chrome baidu.com --enable-gpu-benchmarking --no-sandbox

./out/Default/chrome ~/tannalwork/cans/sk.html --enable-gpu-benchmarking --no-sandbox --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt

chrome.gpuBenchmarking.printToSkPicture('/tmp/skiatest')
chrome.gpuBenchmarking

Builtins_CallApiCallbackGeneric

```

```

LOG(ERROR) << base::debug::StackTrace();


p *document->EventTypes().buffer_.Latin1().data()

p GetDocument().document_classes_

Base class for all LayoutNG algorithms.
LayoutAlgorithm
- const InputNodeType& Node() const { return node_; }
-

--nohooks --no-history

printf "%s\n",  element_id.Latin1().data()

./out/Default/chrome baidu.com --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt

Member<StyleSheetContents> -> .css file


printf "%s\n",  value.Latin1().data()



chrome command line options
https://peter.sh/experiments/chromium-command-line-switches/


*tests, tests, *_test.cc, *_unittest.cc, test, cctest, *browsertest.cc

gdb ./out/Default/chrome --args --js-flags="--trace-gc"


source tools/gdb/gdbinit
b HTMLFrameElementBase::OpenURL
handle all nostop

b WebFrameWidgetImpl::BeginMainFrame

printf "%s\n",  url->string_.Latin1().data()
b html_frame_owner_element.cc:802

./out/Default/chrome http://localhost:8001/html/browsers/browsing-the-web/navigating-across-documents/initial-empty-document/load-pageshow-events-iframe-contentWindow.html

out/Default/chrome --disable-hang-monitor third_party/blink/web_tests/external/wpt/workers/postMessage

find . -name run_wpt_tests.py

third_party/blink/tools/run_wpt_tests.py --release -p chrome third_party/blink/web_tests/external/wpt/html/dom

handle all nostop

./out/Default/chrome http://192.168.43.1:8080/quill.html --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt

MainThreadSchedulerImpl::OnTaskCompleted

指令集仿真器、二进制翻译
器、高级语言虚拟机

selectorList

void GL_APIENTRY glDrawArrays

void GL_APIENTRY GL_DrawArrays(GLenum mode, GLint first, GLsizei count)

sudo apt install generate-ninja
gn gen out/Default --export-rust-project

https://github.com/chromium/chromium/commits?author=hiroshige-g

b module_tree_linker.cc:472
b blink::ModuleTreeLinker::FetchDescendants

printf "%s\n",  request->url_->string_.Latin1().data()

./out/Default/chrome --trace-startup=file --trace-to-file=trace_output.json

./out/Default/chrome http://192.168.43.1:8080/quill.html --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt

element -> Executioncontext -> modulater(type="module" script)

importmap->resolve

source tools/gdb/gdbinit
b blink::DocumentModuleScriptFetcher::Fetch(blink::FetchParameters&, blink::ModuleType, blink::ResourceFetcher*, blink::ModuleGraphLevel, blink::ModuleScriptFetcher::Client*)
https://github.com/search?q=org%3Achromium+%22%5BImport+Maps%5D%22&type=commits

rbreak flex_layout_algorithm.cc:.

target_os = "android"
target_cpu = "arm"
is_debug = true

enable_incremental_javac = true
v8_use_external_startup_data = true
fieldtrial_testing_like_official_build = true
icu_use_data_file = false

is_component_build = true
symbol_level = 2

https://source.chromium.org/chromium/chromium/src/+/main:docs/website/site/chromium-os/obsolete/quiche-notes/index.md;l=80?q=ftrace&sq=&ss=chromium%2Fchromium%2Fsrc:docs%2F

printf "%s\n", html.Latin1().data()

rbreak html_tokenizer.cc:.

rbreak pthread_

source tools/gdb/gdbinit

(gdb) p this->tree_->parser_content_policy_
$10 = blink::kAllowScriptingContent

thread entry RunLoop::Run

libvpx Media Thread

vpx video decoder

https://github.com/search?q=repo%3Achromium%2Fchromium+Joe+Mason&type=commits

process browser(priviliged) gpu network storage audio spare renderer

gdb ./out/Default/chrome

b NeedsRotate


PrePaintTreeWalk

physical_fragment

displayItemList

https://github.com/chromium/chromium/commit/7238cb34fb8251d21662a0b5b23db7cf0e1a5f20
add css value

```cpp

// Tests that float children fragment correctly inside a parallel flow.
TEST_F(BlockLayoutAlgorithmTest, DISABLED_FloatFragmentationParallelFlows) {
  SetBodyInnerHTML(R"HTML(
    <!DOCTYPE html>
    <style>
      #container {
        width: 150px;
        height: 50px;
        display: flow-root;
      }
      #float1 {
        width: 50px;
        height: 200px;
        float: left;
      }
      #float2 {
        width: 75px;
        height: 250px;
        float: right;
        margin: 10px;
      }
    </style>
    <div id='container'>
      <div id='float1'></div>
      <div id='float2'></div>
    </div>
  )HTML");

  LayoutUnit kFragmentainerSpaceAvailable(150);

  BlockNode node(To<LayoutBlockFlow>(GetLayoutObjectByElementId("container")));
  ConstraintSpace space = ConstructBlockLayoutTestConstraintSpace(
      {WritingMode::kHorizontalTb, TextDirection::kLtr},
      LogicalSize(LayoutUnit(1000), kIndefiniteSize),
      /* stretch_inline_size_if_auto */ true,
      node.CreatesNewFormattingContext(), kFragmentainerSpaceAvailable);

  const PhysicalBoxFragment* fragment = RunBlockLayoutAlgorithm(node, space);
  EXPECT_EQ(PhysicalSize(150, 50), fragment->Size());
  EXPECT_TRUE(fragment->GetBreakToken());

  FragmentChildIterator iterator(To<PhysicalBoxFragment>(fragment));

  // First fragment of float1.
  PhysicalOffset offset;
  const auto* child = iterator.NextChild(&offset);
  EXPECT_EQ(PhysicalSize(50, 150), child->Size());
  EXPECT_EQ(PhysicalOffset(0, 0), offset);

  // First fragment of float2.
  child = iterator.NextChild(&offset);
  EXPECT_EQ(PhysicalSize(75, 150), child->Size());
  EXPECT_EQ(PhysicalOffset(65, 10), offset);

  space = ConstructBlockLayoutTestConstraintSpace(
      {WritingMode::kHorizontalTb, TextDirection::kLtr},
      LogicalSize(LayoutUnit(1000), kIndefiniteSize),
      /* stretch_inline_size_if_auto */ true,
      node.CreatesNewFormattingContext(), kFragmentainerSpaceAvailable);

  fragment = RunBlockLayoutAlgorithm(node, space, fragment->GetBreakToken());
  EXPECT_EQ(PhysicalSize(150, 0), fragment->Size());
  ASSERT_FALSE(fragment->GetBreakToken());

  iterator.SetParent(To<PhysicalBoxFragment>(fragment));

  // Second fragment of float1.
  child = iterator.NextChild(&offset);
  EXPECT_EQ(PhysicalSize(50, 50), child->Size());
  EXPECT_EQ(PhysicalOffset(0, 0), offset);

  // Second fragment of float2.
  child = iterator.NextChild(&offset);
  EXPECT_EQ(PhysicalSize(75, 100), child->Size());
  EXPECT_EQ(PhysicalOffset(65, 0), offset);
}

```

box model (top, left, width, height)

LayoutBox implements the full CSS box model.

https://github.com/search?q=repo%3Achromium%2Fchromium+Rune+Lillesveen&type=commits&p=2

search ::AttachLayoutTree(AttachContext& context)
ApplyTextTransform
UpdateStyleAndLayoutInternal

out/Default/chrome --disable-hang-monitor third_party/blink/web_tests/external/wpt/css/css-text/text-transform/math/text-transform-math-auto-001.html

third_party/blink/web_tests/external/wpt/css/css-text/text-transform/math/text-transform-math-auto-003-expected.txt

https://www.cnblogs.com/bigben0123

content::ClipboardHostImpl::WriteText
ClipboardHostImpl::WriteText


The browser process has full system privilge like host clipboard access

And the render process need to impc the browser process to get service (client server like)

blink::mojom::ClipboardHost::WriteText

ClipboardHost::WriteText

ls out/Default/gen/third_party/blink/renderer/bindings/modules/v8/v8_document.cc :7657


third_party/blink/renderer/core/dom/container_node.cc many dom api implemented here called by v8 document bindings

Document::UpdateStyleAndLayoutTreeForThisDocument

blink::WebFrameWidgetImpl::FocusChanged(blink::mojom::FocusState) IPC

third_party/blink/renderer/core/input/keyboard_event_manager.cc MapKeyCodeForScroll


printf "%s\n", text.Latin1().data()

git log --grep "David Awogbemila"

.Ascii().data()
.Ascii().data()

out/Default/chrome --disable-hang-monitor third_party/blink/web_tests/external/wpt/css/css-scroll-snap-2/snapchanging/snapchanging-after-layout-change.tentative.html


out/Default/chrome --disable-hang-monitor third_party/blink/web_tests/external/wpt/css/css-scroll-snap/snap-after-relayout/multiple-aligned-targets/positioned-target-iframe.html

StyleEngine take DOM CSSOM to ComputedStyle to the layoutobject in the layout tree GetDocument()

third_party/blink/renderer/core/input/keyboard_event_manager.cc KeyboardEventManager::KeyEvent
dispatch_result = node->DispatchEvent(*event);
EventTarget::FireEventListeners

blink::WebLocalFrame LocalFrame->GetDocument
Node->GetDocument


```cpp

const ComputedStyle& style = StyleRef();

const ComputedStyle& style = GetLayoutObject().StyleRef();
// A newly created snap container may need to be made aware of snap areas
// within it which are targeted or contain a targeted element. Such a
// container may also change the snap areas associated with snap containers
// higher in the DOM.
if (!style.GetScrollSnapType().is_none) {
    if (Element* css_target = GetLayoutObject().GetDocument().CssTarget()) {
    css_target->SetTargetedSnapAreaIdsForSnapContainers();
    }
}

```

blink::PaintLayerPainter::Paint(blink::GraphicsContext&, unsigned int)

paint layer compositor
renderer process handles rendering, animation, scrolling, and input for each website tab
Viz process aggregates compositing from multiple render processes

https://groups.google.com/a/chromium.org/g/blink-dev/search?q=Manuel%20Rego%20Casasnovas

https://github.com/chromium/chromium/blob/main/third_party/blink/renderer/core/layout/layout_box_model_object.cc



gtest
browser test
web platform test

third_party/WebKit/Source/core/layout/ng/ng_length_utils.cc

sqlite
perf
skia
tflite
devtools frontend
v8
dawn
webgpu-cts

angle vk gl
Chrome uses ANGLE for all graphics rendering on Windows, including the accelerated Canvas2D implementation and the Native Client sandbox environment.

https://issues.chromium.org/issues?q=is:open

WebAssembly WebGPU

WasmGC Wasm Multimemory

Clipboard API

https://www.theverge.com/

max redirect limit in chromium is 20 net::URLRequest::kMaxRedirects;

https://github.com/chromium/chromium/blob/371bdba790b9e1b96baf7dedc923237303274a28/net/url_request/url_request.h#L93

https://fetch.spec.whatwg.org/#http-redirect-fetch

Mark Larson, Brian Rakowski, Darin Fisher, and Ben Goodger

OS-level sandbox isolation between pages

Kasper Lund Lars Bak

Remove ben and darin from OWNERS files to make it clear they're not doing reviews.

https://html.spec.whatwg.org/C#event-loop third_party/blink/renderer/platform/scheduler/public/event_loop.h


```bash



LOG(INFO) << "Hello World" << std::endl;


```

## src/net/socket/ssl_client_socket_impl.cc

`DoHandshake` https handshake


## src/builtins/builtins-console.cc

`Formatter` console format specifiers parsing


Builtins_JSEntry

Builtins_JSEntryTrampoline

Builtins_CompileLazy

v8::internal::CheckObjectType



## github code search keywords

VariableDeclaration

## google search keywords


## further reading

# team

Animations Team
Binding Team
Device Team
DevTools
DOM Team
Ecosystem infra
Input Team
Layout Team
Paint Team (paint-dev)
Rendering Core
Speed Metrics Team
Style Team
Web Capabilities (Project Fugu 🐡)
Worker Team


# community

https://groups.google.com/a/chromium.org/g/chromium-dev

https://groups.google.com/a/chromium.org/g/blink-dev

https://groups.google.com/a/chromium.org/g/graphics-dev

# tokei

tannal@desktop:~/tannalwork/projects/chromium/src$ tokei .
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Language            Files        Lines         Code     Comments       Blanks
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 ABNF                    1           93           69            1           23
 AWK                     7          766          544          108          114
 Ada                     2          731          727            0            4
 Alex                    1           20           20            0            0
 Arduino C++             1           17            8            5            4
 Assembly              881       558261       489322        27397        41542
 GNU Style Assembly    962       767370       672601        26152        68617
 Autoconf             1815       311471       256287        23112        32072
 Automake              110        17500        14132         1557         1811
 BASH                  231        12133         7530         2936         1667
 Batch                 204         9452         6565         1283         1604
 Bazel                3177       573326       504976        30313        38037
 Bitbake               624       380670       369380         3439         7851
 C                   19208      8719829      6661888       974228      1083713
 C Header            85242     13053747      8536420      2688586      1828741
 CMake                 909       144578       113278        18638        12662
 C#                    335       173949       140561        19933        13455
 CodeQL                  8          270          155           76           39
 CoffeeScript           20         1850         1481          134          235
 Coq                     8           56           56            0            0
 C++                105582     33842532     26253786      3217090      4371656
 C++ Header            510       213505       177690        17152        18663
 CSS                  3397       384027       313656        22624        47747
 CUDA                   24         7288         5531          511         1246
 Cython                 62         7640         5075         1129         1436
 D                       5         1619         1016          423          180
 Dart                   95        23266        18327         2355         2584
 Dockerfile            175         9260         4564         3079         1617
 .NET Resource           2          274          156          118            0
 Dream Maker             1            1            1            0            0
 Ebuild                  1           54           38            4           12
 Emacs Lisp             16         2044         1360          417          267
 Elm                     4         1084          798           64          222
 FlatBuffers Schema    131        14949         8884         3780         2285
 Forge Config          670       204751       197948         5211         1592
 FORTRAN Legacy         51        37881        22531        15333           17
 F*                      2          445          445            0            0
 GDB Script              1           34           17           14            3
 GLSL                 9004       361212       333337         1070        26805
 Go                    541       229568       159159        51393        19016
 Groovy                  3         1939         1546          224          169
 Handlebars             31          763          716           12           35
 Happy                   9         5718         5265            0          453
 HICAD                  23         2920         2484            0          436
 HLSL                31175       967150       805494          126       161530
 INI                   121         1581         1281           79          221
 Java                11422      2347774      1683738       363625       300411
 JavaScript          44007      7699238      6022982      1057021       619235
 Jinja2                 26         1160          941           41          178
 JSON                13086      7259872      7258612            0         1260
 JSX                    78         4297         3610          163          524
 Kotlin                136        19695        14255         3744         1696
 Korn shell              1          308          223           47           38
 LLVM                    4          190          164            4           22
 LD Script              34          393          332           30           31
 LiveScript              1           70           18           28           24
 Lua                    53         6238         4646          599          993
 M4                    215        77322        51474        18934         6914
 Makefile              605        54987        38134         7511         9342
 Meson                 235        22659        18785         1578         2296
 Metal Shading Lan|    353        20193        18574          318         1301
 Module-Definition      65        35513        32196         1473         1844
 MSBuild                30         1423         1169          142          112
 Nim                    39         2684         2413           41          230
 Nix                     2          138           70           47           21
 NuGet Config            3           20           18            1            1
 Objective-C           448       128260        96509        15123        16628
 Objective-C++        6268      1298685       962061       141525       195099
 OpenType Feature |      1         3834         3110            1          723
 Pan                   140        23654        20818         1008         1828
 Perl                  255       115053        88151        14381        12521
 PHP                  1047        76588        44932        23243         8413
 PowerShell             22         1086          757          192          137
 Processing              9          845          724           89           32
 Prolog                  7          138          122            0           16
 Protocol Buffers     2406       280205       145115        93055        42035
 Python              17942      4213335      3306923       346807       559605
 R                       1          113           79           22           12
 RPM Specfile            2         1447         1278          127           42
 Rakefile               12          619          494           49           76
 ReScript               10         1450         1104          345            1
 ReStructuredText      770        99134        72314            0        26820
 Ruby                  181        26885        19383         4361         3141
 SRecode Template        6          271          228            0           43
 Sass                   82        13634        10210         1429         1995
 Scheme                  1          286          222           51           13
 Shell                1885       184874       122255        38946        23673
 SQL                   713        82194        65588        13349         3257
 SVG                  4467       381042       360715        12375         7952
 Swift                 271        39851        28638         6717         4496
 SWIG                    3         1720         1362           77          281
 TCL                    90        26209        20164         3621         2424
 TeX                     4         2044         1798          125          121
 Plain Text          34924      6511975            0      6273282       238693
 TOML                  285        28557        22672         2588         3297
 TypeScript          14658      2866935      1993283       580336       293316
 Unison                  1            4            4            0            0
 Vim Script              9          541          458           56           27
 Visual Studio Pro|     33        22214        22202           12            0
 Visual Studio Sol|     16         1119         1110            0            9
 WebGPU Shader Lan|  16116       616682       345854       190699        80129
 WebAssembly            20          276          249           10           17
 XSL                    93         3145         2860           90          195
 XAML                    6          191          108           60           23
 Xcode Config            3          115           21           85            9
 XML                  5079      1688852      1590414        38729        59709
 YAML                 2526      1542178      1524547         6384        11247
───────────────────────────────────────────────────────────────────────────────
 HTML               101241      2975955      2679623       112232       184100
 |- CSS              40621       613274       557574        12143        43557
 |- HTML              1243        21059        20633          199          227
 |- JavaScript       57601      2321928      1945428       117496       259004
 |- Plain Text          10           68            0           68            0
 (Total)                        5932284      5203258       242138       486888
───────────────────────────────────────────────────────────────────────────────
 Jupyter Notebooks      36         2060         1081          692          287
 |- Markdown            10          541            0          432          109
 |- Python              10         1519         1081          260          178
 (Total)                           4120         2162         1384          574
───────────────────────────────────────────────────────────────────────────────
 Markdown             9235      1103608            0       831876       271732
 |- ABNF                 1           54           34            9           11
 |- BASH               346         5062         4068          658          336
 |- Batch                2            5            5            0            0
 |- Bazel                3          201          165           24           12
 |- C                   42         2554         1885          303          366
 |- CMake               21          334          242           39           53
 |- C#                   2           32           24            8            0
 |- CoffeeScript         2            9            7            2            0
 |- C++                165        10608         7799         1675         1134
 |- CSS                 45          702          648           21           33
 |- Dart                 4           34           32            0            2
 |- GLSL                 1           12            9            0            3
 |- Go                   9          226          196           20           10
 |- Groovy               3           71           49           10           12
 |- HTML               149         2517         2225          135          157
 |- INI                  2            6            6            0            0
 |- Java                65         3008         2180          490          338
 |- JavaScript         199         6931         5031         1218          682
 |- JSON                94         2267         2259            0            8
 |- JSX                  1           18           12            2            4
 |- Kotlin               3          114           89           15           10
 |- Makefile             1           11           10            1            0
 |- Markdown            58         1184            0          795          389
 |- Meson                1           11           10            0            1
 |- Objective-C          4          107           76           12           19
 |- PHP                  3           20           19            1            0
 |- Python             434         6858         5550          455          853
 |- Ruby                13          161          116           31           14
 |- Rust                81         3160         2551          219          390
 |- Shell              195         2759         2327          290          142
 |- SQL                 19          552          434           87           31
 |- Swift               17          265          149           70           46
 |- TOML                46          213          178           22           13
 |- TSX                  2           32           25            3            4
 |- TypeScript          48         2147         1331          541          275
 |- XML                 28          864          810           33           21
 |- YAML                12          200          167           22           11
 (Total)                        1156917        40718       839087       277112
───────────────────────────────────────────────────────────────────────────────
 Rust                 3405      1277782      1146027        49369        82386
 |- Markdown          1556       142527         8361       107480        26686
 (Total)                        1420309      1154388       156849       109072
───────────────────────────────────────────────────────────────────────────────
 Svelte                  4           65           54            2            9
 |- JavaScript           4          109           87            0           22
 (Total)                            174          141            2           31
───────────────────────────────────────────────────────────────────────────────
 Vue                    61          419          278           49           92
 |- CSS                 15          443          363            7           73
 |- HTML                61         1101         1070           26            5
 |- JavaScript          51         1811         1531          174          106
 (Total)                           3774         3242          256          276
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Total              560571    107405586     78532204     17664518     11208864
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

# people

Blink (Google的渲染引擎):
Darin Fisher
Chrome的早期核心开发者
已离开Google，现在是Brave的CTO
Eric Seidel
Blink项目的创始人之一
已离开Google，现在是Replit的CTO
Chris Harrelson
现任Blink技术负责人
WebKit (Apple的渲染引擎):

Dave Hyatt
WebKit的创始人之一
仍在Apple工作
Sam Weinig
WebKit核心开发者
仍在Apple工作
Ryosuke Niwa
WebKit核心开发者
仍在Apple工作

involves:bpastene
involves:colinblundell
involves:agrieve
involves:freshp86
involves:leizleiz
involves:tkent-google
involves:ckitagawa-work
involves:pkasting
involves:schwering
involves:sdefresne
involves:tomasz-wiszkowski
involves:dtapuska
involves:zetafunction
involves:horo-t
involves:darrnshn
involves:danakj
involves:anastasi-google
involves:kojiishi
involves:bfgeek
involves:mstensho
involves:davidben
involves:wangxianzhu
involves:ArthurSonzogni
involves:bashi
involves:anforowicz
involves:nhiroki
involves:tgsergeant
involves:erikchen
involves:dalecurtis
involves:natechapin
involves:yuki3
involves:tanderson-google
involves:xchrdw
involves:hiroshige-g
involves:GregTho
involves:zmodem
involves:phuang
involves:iotitan
involves:mkruisselbrink
involves:alancutter
involves:clarkduvall
involves:pkotwicz
involves:yi-gu
involves:fdoray
involves:JinsukKim
involves:Gyuyoung
involves:yellowdoge
involves:jeremyroman
involves:mohamedamir
involves:mitoshima
involves:ccameron-chromium
involves:bokand
involves:caseq
involves:progers
involves:jkim-julie
involves:reillyeon
involves:toyoshim
involves:krockot
involves:nico
involves:vmpstr
involves:dtsengchromium
involves:xiaochengh
involves:khushalsagar
involves:chrishtr
involves:mlippautz
involves:kenrussell
involves:xhwang-chromium
involves:randomascii
involves:jabdelmalek
involves:rsesek
involves:tapted
involves:dpranke
involves:stevenjb
involves:tonikitoo
involves:tarunban
involves:zhenyao
involves:jdoerrie
involves:SergeyUlanov
involves:dgozman
