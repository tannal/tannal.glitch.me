# Webkit


flatpak


```bash

// settings

{
    "clangd.path": "/home/tannal/tannalwork/clangd"
}

// clangd
#!/bin/bash
set -eu
# https://stackoverflow.com/a/17841619
function join_by { local d=${1-} f=${2-}; if shift 2; then printf %s "$f" "${@/#/$d}"; fi; }

local_webkit=/home/tannal/tannalwork/projects/WebKit
include_path=("$local_webkit"/WebKitBuild/UserFlatpak/runtime/org.webkit.Sdk/x86_64/*/active/files/include)
if [ ! -f "${include_path[0]}/stdio.h" ]; then
  echo "Couldn't find the directory hosting the /usr/include of the flatpak SDK."
  exit 1
fi
include_path="${include_path[0]}"
mappings=(
  "$local_webkit/WebKitBuild/GTK/Debug=/app/webkit/WebKitBuild/Debug"
  "$local_webkit/WebKitBuild/GTK/Release=/app/webkit/WebKitBuild/Release"
  "$local_webkit=/app/webkit"
  "$include_path=/usr/include"
)

exec "$local_webkit"/Tools/Scripts/webkit-flatpak --gtk --debug run -c clangd --path-mappings="$(join_by , "${mappings[@]}")" "$@"

```

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

./Tools/Scripts/build-webkit --gtk --debug --export-compile-commands WK_USE_CCACHE=YES
./Tools/Scripts/build-webkit --gtk --debug WK_USE_CCACHE=YES

usage: 
                  make r EXPORT_COMPILE_COMMANDS=YES
                  generate-compile-commands WebKitBuild/Release

                  https://docs.webkit.org/Build%20%26%20Debug/BuildOptions.html#building-with-compile_commandsjson
                  
generate-compile-commands: error: the following arguments are required: built-products-dir

./Tools/Scripts/run-minibrowser --gtk --debug


ln -s WebKitBuild/GTK/Debug/compile_commands.json compile_commands.json 

rm compile_commands.json 

ln -s ./WebKitBuild/GTK/Debug/DeveloperTools/compile_commands.json compile_commands.json 

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




# reference

https://blogs.igalia.com/aboya/2021/10/02/setting-up-visualstudio-code-to-work-with-webkitgtk-using-clangd/