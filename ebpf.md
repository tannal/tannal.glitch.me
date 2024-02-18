
# bpfcc-tools

```bash

git clone https://github.com/iovisor/bcc.git


```


```bash

sudo apt-get install bpfcc-tools linux-headers-6.1.0-18-amd64 

sudo apt-get install bpfcc-tools linux-headers-$(uname -r)
sudo stackcount-bpfcc  "simple_lookup" -Pd -i 1

sudo apt install linux-tools-common
sudo apt install bpftrace

sudo cat /sys/kernel/debug/tracing/events/tcp/tcp_retransmit_skb/format

sudo bpftrace -e '
tracepoint:tcp:tcp_retransmit_skb {
    // Access fields using tracepoint:tcp:tcp_retransmit_skb format
    // Replace 'field1', 'field2', etc., with actual field names
    printf("TCP retransmit - field1: %d, field2: %d\n", args->state, args->family);
}
'

git clone --depth 1 https://github.com/brendangregg/perf-tools


cd ~/tannalwork/projects/perf-tools/bin
cd perf-tools/bin

cat /proc/kallsyms

sudo cat /sys/kernel/debug/tracing/available_filter_functions | grep tcp_recv


sudo ./kprobe -p 43077 r:ksys_write

sudo ./funcgraph -p 43077 ksys_write -m 2

sudo cat /sys/kernel/debug/tracing/available_filter_functions | grep write

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



# traceable function easy to hit

```bash
sudo ./kprobe -s 'p:submit_bio'

```


