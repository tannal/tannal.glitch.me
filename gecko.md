
# Get the code, build, run, debug, logging, lsp

mercurial

mach


```bash

sudo apt-get install curl python3 python3-pip

python3 -m pip install --user mercurial

curl https://hg.mozilla.org/mozilla-central/raw-file/default/python/mozboot/bin/bootstrap.py -O
python3 bootstrap.py

cd mozilla-unified
hg up -C central
./mach build

./mach ide vscode


./mach build-backend --backend=CompileDB

./obj-x86_64-pc-linux-gnu/clangd/compile_commands.json

find . -name compile_commands.json

ln -s ./obj-x86_64-pc-linux-gnu/clangd/compile_commands.json compile_commands.json 

```



# directory structure

gfx/

servo/

python/


# community

https://chat.mozilla.org/#/room/#introduction:mozilla.org

