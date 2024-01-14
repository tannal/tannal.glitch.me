
$ v := vec(x_1, x_2, x_3) $


```bash

git clone https://github.com/servo/servo/

mach bootstrap

mach build

```




set MOZTOOLS_PATH=C:\Users\tannal\Downloads\moztools-4.0\moztools-4.0\bin
set MOZTOOLS_PATH=C:\Users\tannal\Downloads\moztools-4.0\moztools-4.0\
set LIBCLANG_PATH=C:\Program Files\LLVM\lib


C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\vcvars64

WebIDL

unsafe keyword in rust

https://github.com/servo/servo/issues/30862

In components/script, remove unsafe JS related code

 creating a rooted JSObject

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

# inbox

https://www.youtube.com/watch?v=PyfY82-NDCM




# Vscode setup

```json
// .vscode/settings.json
{
    "rust-analyzer.check.overrideCommand": [
        "./mach", "check", "--message-format=json" ],
    "rust-analyzer.cargo.buildScripts.overrideCommand": [
        "./mach", "check", "--message-format=json" ],
    "rust-analyzer.rustfmt.overrideCommand": [ "./mach", "fmt" ],
}

```

# servo people

igalia delan rego robinson

(ex-)mozilia

jdm


other contributors


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

E-candidate-for-mentoring

A-content/script

# issues

Implement ResizeObservers

```bash

./mach test-wpt --production _webgpu



```

https://servo.org/blog/

https://wpt.servo.org/

https://github.com/servo/servo/wiki/Servo-Layout-Engines-Report

cross platform windows linux macos android

embeddedable dioxus tauri Delta chat

servo is experimental

controlled environment

- Embeddedable

2012-2020 


- Memory Safe
- Independence
- 



```bash


sudo apt update

sudo apt install git

git clone https://www.github.com/tannal/tannalwork/

git submodule update --init .

git clone https://www.github.com/servo/servo


# sudo apt install python3-pip python-is-python3l

pip install virtualenv --break-system-packages
curl --proto 'ls=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

./mach bootstrap

sudo apt install m4

time ./mach build



# on my arm cortex A76 raspi 5

real	10m56.115s
user	32m57.548s
sys	3m14.510s


./mach build
./mach run


```

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



# GPT-QA

## CSS 2

style.rs: This file defines the core data structures and algorithms for CSS styling in Servo. Understanding how styles are computed and applied is crucial for adding new CSS2 features.

dom.rs: This file contains the implementation of the Document Object Model (DOM) in Servo. The DOM represents the structure of web pages, and modifying it correctly is essential for supporting new CSS2 features.

layout.rs: This file encompasses the layout engine of Servo. It handles the positioning and rendering of elements on the web page. Understanding layout is crucial for implementing new CSS2 features that affect the visual rendering of elements.

parser.rs: This file deals with parsing CSS and HTML in Servo. Familiarizing yourself with the parsing logic is important for correctly handling new CSS2 features in terms of syntax and structure.

properties.rs: This file defines the various CSS properties supported by Servo. Adding new CSS2 features often involves extending or modifying the existing property definitions.

style_traits.rs: This file contains trait definitions and helper functions for working with CSS styles in Servo. It provides a foundation for implementing and manipulating CSS2 features.

selectors.rs: This file handles CSS selector matching and specificity calculations. Understanding how selectors are processed is important for supporting new CSS2 selectors.

paint.rs: This file deals with painting and rendering operations in Servo. Depending on the CSS2 feature you want to add, you may need to modify the painting logic to achieve the desired visual effect.

computed_values.rs: This file defines the computed values for CSS properties. Understanding how computed values are derived and used is important for correctly implementing new CSS2 features.

style_builder.rs: This file contains the logic for building the style tree in Servo. It handles cascading, inheritance, and applying styles to elements. Understanding the style building process is crucial for correctly handling new CSS2 features.

## Multiple concurrent top-level browsing contexts

browser.rs: This file represents the browser context in Servo and manages the top-level browsing contexts. Understanding how the browser context is created, managed, and interacts with other components is crucial for implementing multiple concurrent top-level browsing contexts.

document.rs: This file represents the web document in Servo and handles the construction, modification, and layout of the document. Understanding how documents are managed and how they relate to browsing contexts is important for enabling multiple concurrent top-level browsing contexts.

frame_tree.rs: This file represents the frame tree structure in Servo, which organizes the hierarchy of frames within a browsing context. Understanding how frames are structured and how they relate to browsing contexts is crucial for implementing multiple concurrent top-level browsing contexts.

script_thread.rs: This file handles the execution of JavaScript and manages the event loop in Servo. Understanding how scripts are executed and how events are processed is important for enabling concurrent execution and event handling across multiple browsing contexts.

layout.rs: This file contains the layout engine of Servo, responsible for positioning and rendering elements. Understanding how layout is performed and how it interacts with browsing contexts is important for ensuring proper rendering across multiple concurrent top-level browsing contexts.

dom.rs: This file contains the implementation of the Document Object Model (DOM) in Servo. Familiarizing yourself with the DOM structure and how it relates to browsing contexts is crucial for enabling multiple concurrent top-level browsing contexts.

parser.rs: This file deals with parsing HTML and CSS in Servo. Understanding how parsing is performed and how it relates to browsing contexts is important for correctly handling and managing the creation of multiple concurrent top-level browsing contexts.

window.rs: This file represents the windowing system integration in Servo. Understanding how Servo interacts with the windowing system is important for managing multiple concurrent top-level browsing contexts and their associated windows.

ipc.rs: This file handles inter-process communication in Servo. Depending on the implementation approach for multiple concurrent top-level browsing contexts, you may need to modify the IPC mechanisms to ensure proper communication between the browsing contexts.

glue.rs: This file contains various glue code that connects different parts of Servo. Understanding the glue code related to browsing contexts and their interactions will help you grasp the overall architecture and integration of multiple concurrent top-level browsing contexts.

# code search

Matching complex selector

mach run

sudo apt install moreutils

RUST_LOG="debug" ./mach run -d -- -i -y 1 /tmp/a.html 2>&1 | ts -s "%.S: " | tee /tmp/log.txt

RUST_LOG="debug" ./mach run -d -- -i -y 1  2>&1 | ts -s "%.S: " | tee /tmp/log.txt


llvm git cmake python python-virtualenv wixtoolset ninja vs2019


sudo apt install libopts25-dev m4
sudo apt install libots-dev


```bash
// script_thread.rs
handle_resize_inactive_msg

```


build errors on windows


```bash


  --- stderr
  bash.exe: warning: could not find /tmp, please create!
  bash.exe: warning: could not find /tmp, please create!
  bash.exe: warning: could not find /tmp, please create!
  bash.exe: warning: could not find /tmp, please create!
  bash.exe: warning: could not find /tmp, please create!
  bash.exe: warning: could not find /tmp, please create!
  cat: config.log: No such file or directory
  mozmake: *** [C:\Users\tannal\.cargo\git\checkouts\mozjs-fa11ffc7d4f1cc2d\f452fb2\mozjs-sys\makefile.cargo:157: maybe-configure] Error 1
  thread 'main' panicked at 'assertion failed: result.success()', C:\Users\tannal\.cargo\git\checkouts\mozjs-fa11ffc7d4f1cc2d\f452fb2\mozjs-sys\build.rs:246:5
  note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace


```