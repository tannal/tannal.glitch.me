# notes on chromium

git checkout master
git pull --rebase

gclient sync

```bash

export PATH=/home/tannal/tannalwork/projects/depot_tools:$PATH


mkdir chromium && cd chromium

fetch chromium

cd src

./build/install-build-deps.sh

gn gen out/Default

time autoninja -C out/Default chrome

tools/clang/scripts/generate_compdb.py -p out/Default > compile_commands.json

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

