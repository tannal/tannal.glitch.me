# install and use ccache

```bash

sudo apt install ccache

export PATH="/usr/lib/ccache/:$PATH"

ccache --print-stat

strace -e execve cc

ccache --clear

```
