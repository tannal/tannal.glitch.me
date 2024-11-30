# Google Goma

need investigation


# distcc

## install (build from source)

```bash

git clone https://github.com/distcc/distcc

sudo apt-get install gcc make python3 python3-dev libiberty-dev autoconf

./autogen.sh

./configure

make -j8

update-distcc-symlinks

sudo make install

```

## start distccd on every machines

```bash

pkill distccd

distccd --daemon --allow 192.168.43.0/24 --listen 192.168.43.183 --log-level debug

distccd --daemon --allow 192.168.43.0/24 --listen 192.168.43.27 --log-level debug

distcc --show-hosts
pump make -j8 CC=distcc




```

## build using distcc

```bash
vim ~/.distcc/hosts

127.0.0.1,cpp,lzo 192.168.43.xxx,cpp,lzo

pump make -j8 CC=distcc


```