
```bash

git clone --depth 1 https://github.com/brendangregg/perf-tools

cd perf-tools/bin

cat /proc/kallsyms

sudo cat /sys/kernel/debug/tracing/available_filter_functions | grep tcp_recv

sudo ./kprobe -s 'p:icmp_out_count type=%si'



sudo apt install cscope

cscope -R

# this trick needs kernel debuginfo
sudo /usr/lib/linux-tools/5.19.0-50-generic/perf probe -nv 'icmp_out_count net->ifindex'

# ftrace stuff
sudo ls /sys/kernel/debug/tracing/


# install kernel debuginfo on ubuntu

echo "deb http://ddebs.ubuntu.com $(lsb_release -cs) main restricted universe multiverse" | sudo tee /etc/apt/sources.list.d/ddebs.list

wget -O - http://ddebs.ubuntu.com/dbgsym-release-key.asc | sudo apt-key add -

sudo apt-get update

sudo apt-get install linux-image-`uname -r`-dbgsym



# perf

sudo /usr/lib/linux-tools/5.19.0-50-generic/perf record -F 99 -a -g -- sleep 5

sudo /usr/lib/linux-tools/5.19.0-50-generic/perf script


# bcc ebpf

sudo apt install libdebuginfod-dev libclang-14-dev

cmake .. -DPYTHON_CMD=python3

make

sudo make install

cd /usr/share/bcc/tools

sudo ./stackcount -P -p 1873079 "tcp*"

```



## talks

Into the hive of eBPF By Mohammed Aboullaite

https://www.youtube.com/watch?v=GsMs3n8CB6g


## papers


## turtorials

cscope c symbols jumping

https://cscope.sourceforge.net/large_projects.html


## people

Brendan Gregg


## Further learning



