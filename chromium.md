# inbox

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

tools/clang/scripts/generate_compdb.py -p out/Default > compile_commands.json

./out/Default/chrome --enable-logging=stderr --v=1

./out/Default/chrome --enable-logging=stderr --v=1 2>&1 | ts -s "%.S: " | tee /tmp/chrome_log.txt


./out/Default/chrome --headless --disable-gpu --remote-debugging-port=9222 https://www.chromestatus.com


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