# inbox

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

APIs, & HTML/CSS parsing

Input: HTML, CSS, JavaScript, other resources.
Output: DOM, Stylesheets.
DOM (Document Object Model)

Input: HTML after being parsed.
Output: A tree structure that represents the content of the page.
Stylesheets

Input: CSS after being parsed.
Output: CSSOM (CSS Object Model), a tree structure that represents the style information for the page.
Animate

Input: DOM, CSSOM, and animation definitions (e.g., from CSS animations or Web Animations API).
Output: Changes to properties over time that should be reflected in the style and layout.
Style

Input: DOM, CSSOM.
Output: Computed Styles, which are the styles that are actually applied to the DOM elements after resolving all the CSS rules.
Layout

Input: DOM, Computed Styles.
Output: Layout tree (also known as a box tree or render tree), which is a representation of the layout boxes for each DOM element with size and position information.
Pre-paint

Input: Layout tree, any pending style changes or updates.
Output: Paint records (instructions for painting) and updates to the Property Trees if necessary.
Scroll

Input: User interaction, current scroll position.
Output: Updated scroll position that will be reflected in the layout and paint.
Paint

Input: Paint records, images, and other resources.
Output: Draw commands that are ready to be rasterized.
Commit

Input: Draw commands, any updates that require synchronizing with the compositor.
Output: Layers prepared and sent to the compositor for the final screen rendering.
Layerize

Input: Layers that need to be composited, possibly from different parts of the rendering pipeline.
Output: A layer list that the compositor can work with to produce the final image.
Property Trees

Input: Hierarchical properties such as transforms, clips, effects.
Output: A set of property trees (transform tree, clip tree, effect tree) that are used to efficiently manage these properties across the rendering pipeline.
Composited Layer List

Input: The layers that have been prepared during the commit phase.
Output: A list of layers in the order they should be composited to create the final frame.
Immutable Fragment Tree

Input: Output from the layout phase.
Output: A tree structure that represents parts of the page that do not change, which allows for optimization in the rendering process.
Decoded & Sized Textures

Input: Raw image data and videos.
Output: Images and videos that have been decoded, sized, and formatted into textures for use by the GPU.
Display Lists

Input: All the painting commands that have been generated.
Output: A list of instructions that the GPU will use to draw the final image to the screen.

blink::PaintLayerPainter::Paint(blink::GraphicsContext&, unsigned int)

paint layer compositor
renderer process handles rendering, animation, scrolling, and input for each website tab
Viz process aggregates compositing from multiple render processes

https://groups.google.com/a/chromium.org/g/blink-dev/search?q=Manuel%20Rego%20Casasnovas

https://github.com/chromium/chromium/blob/main/third_party/blink/renderer/core/layout/layout_box_model_object.cc

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

git checkout master
git pull --rebase

gclient sync

gclient sync -D

skia

blink::WebInputEvent

html_div_element.h


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

ninja: Entering directory `out/Default'
[0/1] Regenerating ninja files
[53694/53694] LINK ./chrome

real    102m34.204s
user    2292m7.163s
sys     142m41.843s

tools/clang/scripts/generate_compdb.py -p out/Default > compile_commands.json

./out/Default/chrome --enable-logging=stderr --v=1

./out/Default/chrome --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt


./out/Default/chrome --headless --disable-gpu --remote-debugging-port=9222 https://www.chromestatus.com

tar -czvf ../../../build/chrome_x86-64_linux_debug_$(date +%Y%m%d-%H%M%S)_$(git rev-parse --short HEAD).tar.gz Default/


```

class Document
provided by "third_party/blink/renderer/core/dom/document.h"

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



# community

https://groups.google.com/a/chromium.org/g/chromium-dev

https://groups.google.com/a/chromium.org/g/blink-dev