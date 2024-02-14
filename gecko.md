# inbox

Make use of Cargo dependencies, but vendor them in monorepo.

Continuous integration can't rely on external network.

Benjamin Smedberg

https://www.joshmatthews.net/fosdem/#slide-7

#developers - high traffic, general Gecko-related development
#jsapi - JavaScript engine development
#gfx - graphics/rendering discussion
#content - DOM implementation
#fx-team - Firefox frontend development
#necko - Networking stack development
#mobile - Firefox for Android development
#b2g - Firefox OS development

# Get the code, build, run, debug, logging, lsp

firefox use mercurial instead of git for versioning control.

https://survey.stackoverflow.co/2023/

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


RUST_LOG="debug" obj-x86_64-unknown-linux-gnu/dist/bin/firefox -no-remote -P

```




# directory structure

gfx/

servo/

python/


# community

https://chat.mozilla.org/#/room/#introduction:mozilla.org

https://codetribute.mozilla.org/projects/devtools

# reference

https://colin-cazabet.medium.com/how-to-start-contributing-to-firefox-ebad014d9f1