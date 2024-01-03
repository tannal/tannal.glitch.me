# Webkit


```bash

====================================================================
 WebKit is now built (26m:16s). 
 To run MiniBrowser with this newly-built code, use the
 "Tools/Scripts/run-minibrowser" script.
====================================================================

real	26m16.267s
user	0m0.365s
sys	0m0.111s

sudo apt-get -y install ninja-build

git clone https://github.com/WebKit/WebKit

# install or upgrade flatpak
sudo apt install flatpak

./Tools/Scripts/update-webkit-flatpak

./Tools/Scripts/update-webkitgtk-libs

./Tools/Scripts/build-webkit --gtk --debug --export-compile-commands 

./Tools/Scripts/run-minibrowser

```

The hard part of learning is the "bootstrap" problem (like compilers).

These series tell you some part of webkit project on how it works.

And How it interract with other parts?

I think the existing knowledge can lead you learn more.

## WebKit/Source/JavaScriptCore/heap/LocalAllocator.cpp

This is webkit memory allocator

## heap/ -> runtime/

js Runtime use allocateCell to allocate memory for js objects

runtime/ include allocateCell

There is a common practice that member variable with prefix 'm_' which indicates it's scope.

## runtime/

vmEntryToJavaScript

js_trampoline_op_call

heap::addToRememberedSet

for minor gc add old space objects with hold reference to the eden space, we need these objects be treated like gc roots.