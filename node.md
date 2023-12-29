# 


```bash

./configure

./configure -C --debug-node

make -j20

ln -s ./out/Release/compile_commands.json .

```

node env context

isolate

# testing

cctest

# debugging

> The source code of Node.js itself is primarily written in C++ and JavaScript. The JS part is mostly under the lib directory and the C++ part is mostly under the src directory. There are also a bunch of third-party dependencies like v8 or libuv which are placed under the deps directory.

> The Node.js release binaries do not strip the debug symbols (surprised?) so you don’t necessarily have to build a debug build to get meaningful C/C++ stack traces or to do step debugging in a native debugger like LLDB or GDB.


# reference

https://joyeecheung.github.io/blog/2018/12/31/tips-and-tricks-node-core/