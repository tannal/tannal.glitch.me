

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



# code search

Matching complex selector

mach run

sudo apt install moreutils

RUST_LOG="debug" ./mach run -d -- -i -y 1 /tmp/a.html 2>&1 | ts -s "%.S: " | tee /tmp/log.txt


llvm git cmake python python-virtualenv wixtoolset ninja vs2019


sudo apt install libopts25-dev


```bash
// script_thread.rs
handle_resize_inactive_msg

```

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