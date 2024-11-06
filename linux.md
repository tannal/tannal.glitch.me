
# inbox

https://www.eet-china.com/mp/u3946005

字节跳动系统技术与工程团队一直致力于操作系统内核与虚拟化、系统基础软件与基础库的构建和性能优化、超大规模数据中心的稳定性和可靠性建设、新硬件与软件的协同设计等基础技术领域的研发与工程化落地，具备全面的基础软件工程能力，为字节上层业务保驾护航。

同时，团队积极关注社区技术动向，拥抱开源和标准。欢迎更多有志之士加入，如有意向可发送简历至sysrecruitment@bytedance.com。

宋牧春
宋宝华
段熊春


https://lore.kernel.org/lkml/?q=smuchun
https://lore.kernel.org/lkml/?q=smuchun



# people

involves:torvalds
involves:ukleinek
involves:krzk
involves:arndb
involves:kuba-moo
involves:broonie
involves:captain5050
involves:andy-shev
involves:robherring
involves:lumag
involves:jmberg-intel
involves:jwrdegoede
involves:geertu
involves:davem330
involves:sean-jc
involves:kees
involves:tiwai
involves:rafaeljw
involves:tititiou36
involves:chucklever
involves:vsyrjala
involves:rddunlap
involves:masahir0y
involves:dhowells
involves:linusw
involves:airlied
involves:jnikula
involves:jtlayton
involves:axboe
involves:morimoto
involves:gregkh
involves:plbossart
involves:jhovold
involves:bjorn-helgaas
involves:bvanassche
involves:rostedt
involves:namhyung
involves:anakryiko
involves:herbertx
involves:bonzini
involves:pinchartl
involves:chleroy
involves:vladimiroltean
involves:alexdeucher
involves:idosch
involves:mpe
involves:acmel
involves:bebarino
involves:jankara
involves:isilence
involves:ummakynes
involves:ebiggers
involves:kdave
involves:LorenzoBianconi
involves:htejun
involves:mripard
involves:hkallweit
involves:GustavoARSilva
involves:djbw
involves:tmlind
involves:thierryreding
involves:olsajiri
involves:dtor
involves:neilbrown
involves:tomba
involves:danvet
involves:ahunter6
involves:npiggin
involves:borkmann
involves:ffainelli
involves:jic23
involves:ChristianKoenigAMD
involves:groeck
involves:vireshk
involves:larsclausen
involves:alexandrebelloni
involves:alexelder
involves:JuliaLawall
involves:AlanStern
involves:ian-abbott
involves:mchehab
involves:lwfinger
involves:lenb
involves:hverkuil
involves:koverstreet
involves:AxelLin
involves:ickle
involves:ebiederm
involves:JoePerches


# inbox

c and assembly and calling convention x86 arm risc etc. computer architecture
system boot memory management protection ring page table
process management timer interrupt scheduling
file system disk management
usb/serial io/wifi/802.11
networking tcp/ip stack implementation
device driver pci pcie 
audio video framework
camera 
power management


desktop Linux
graphics stack driver window system ioctl framebuffer drm
audio video microphine


pagemon
https://github.com/ColinIanKing

p current->files->fdt->fd[i]->f_path.dentry->d_name.name

ctrl x + o

x/16xb $edx+0x14
layout asm
macro expand *current*
info macro *macro name*

qemu-system-x86_64 -kernel bzImage-debug -m 3G -initrd root.cpio.gz -append "console=ttyS0 console=tty0 root=/dev/ram ip=dhcp" -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=hostshare -fsdev local,security_model=passthrough,id=fsdev0,path=share

mount -t 9p -o trans=virtio,version=9p2000.L hostshare ~/share

qemu-system-x86_64 linux.iso -m 2G


traps.h#L27

https://github.com/torvalds/linux/blob/master/arch/x86/include/asm/trapnr.h

ext4_file_write_iter

git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/

https://github.com/search?q=repo%3Atorvalds%2Flinux%20Kmemleak&type=code

kernel selftests

```bash

make -C tools/testing/selftests

make -C tools/testing/selftests run_tests

make kselftest

```

```c
printk(KERN_INFO "Dumping call stack:\n");
dump_stack();
pr_info("Entering tcp_rcv_state_process, sk_state: %d, sk: %p\n", sk->sk_state, sk);
pr_info("Socket refcount: %d, flags: %lx\n", refcount_read(&sk->sk_refcnt), sk->sk_flags);

```

interface high level desc nature language

implementation details class/structs property/function data structure algorithms

name space wrap some system global resource to provide resource isolation


hostname uname syscall
mount point list
ipc
pid namespace


ETIMEDOUT

ECONNREFUSED

p sk->__sk_common->skc_state

if (th->rst) {
			tcp_reset(sk, skb);
consume:
			__kfree_skb(skb);
			return 0;
		}

tcp_v4_connect
	tcp_set_state(sk, TCP_SYN_SENT);

tcp_finish_connect
    tcp_set_state(sk, TCP_ESTABLISHED);



tcp_reset
tcp_done
	tcp_set_state(sk, TCP_CLOSE);


hash value of
source and destination IP addresses, source and destination port numbers, and the transport protocol (e.g., TCP, UDP).

__inet_lookup_skb  函数首先查找连接建立状态的socket（__inet_lookup_established）
 在没有命中的情况下，才会查找监听套接口 _inet_lookup_listener

根据目的地址和目的端口算出一个哈希值，然后在哈希表找到对应监听该端口的 socket

tcpv4_send_reset

Luis Chamberlain Qualcomm

Pankaj Raghav Samsung Electronics

SGI Christoph Lameter

Ryan Roberts - Director of Software Architecture - Arm

https://github.com/ChinaLinuxKernel



NACk

Russell King ARM Linux

linaro 

https://lore.kernel.org/lkml/20231111024835.2164816-1-tj@kernel.org/

active directory fs/ include/linux/ include/net/ kernel/cgroup/ kernel/ mm/ net/ tools/testing/selftests/ sound/soc/ io_uring/

drivers/ arch/ Documentation/

# dev

sudo stackcount-bpfcc -p 6970 -i 2 --debug "*switch*"
sudo stackcount-bpfcc -p 6970 -i 2 --debug "*timer_interrupt*"

sudo trace-cmd list -e
sudo trace-cmd list -f

sudo trace-cmd record -p function_graph dd if=/dev/mmcblk0 of=out bs=512 count=

sudo trace-cmd report

perf trace -e "net:*" ping -c 1 192.168.43.1

perf probe --source=. -x ./a.out -F
perf probe --source=. -x ./a.out -L callee
perf probe -x /lib/x86_64-linux-gnu/libc.so.6 printf
perf record -e probe_libc:printf -aR sleep 1
perf probe -x a.out callee:3 myptr
perf probe -x ./a.out callee%return ret=%0

perf record -e probe_app:callee -e probe_libc:printf


# build linux kernel


https://blog.jm233333.com/linux-kernel/build-and-run-a-tiny-linux-kernel-on-qemu/#generate-a-initramfs-with-busybox

https://kdlp.underground.software/course/spring2023/assignments/A3.md

https://farabimahmud.github.io/emulate-raspberry-pi3-in-qemu/

```bash

git clone https://github.com/torvalds/linux.git

sudo apt-get install -y bison flex libelf-dev cpio build-essential libssl-dev
cp /boot/config-$(uname -r)* .config
make olddefconfig
make kernelversion

CONFIG_SYSTEM_TRUSTED_KEYS=""
CONFIG_SYSTEM_REVOCATION_KEYS=""


time make -j20

scripts/clang-tools/gen_compile_commands.py

new features

custom driversz

custom security & access control

fix bugs & vulnerabilities

optimize for specific harware

debugging

```


# qemu launch kernel

```bash

export BUSYBOX_VERSION=1.35.0
wget -q -c https://busybox.net/downloads/busybox-$BUSYBOX_VERSION.tar.bz2
[ -e busybox-$BUSYBOX_VERSION ] || tar xjf busybox-$BUSYBOX_VERSION.tar.bz2

make -C busybox-$BUSYBOX_VERSION defconfig
sed -i 's/# CONFIG_STATIC is not set/CONFIG_STATIC=y/g' busybox-$BUSYBOX_VERSION/.config
make -C busybox-$BUSYBOX_VERSION -j20
make -C busybox-$BUSYBOX_VERSION install

# cpio_list

dir /dev 0755 0 0
nod /dev/console 0600 0 0 c 5 1
dir /root 0700 0 0

nod /dev/null 0666 0 0 c 1 3
nod /dev/zero 0666 0 0 c 1 5

dir /proc 0755 0 0
dir /sys  0755 0 0
dir /mnt  0755 0 0

file /init ./init.sh 0755 0 0

# initramfs.sh

export BUSYBOX_VERSION=1.35.0
mkdir -p fs
mkdir -p share
cd fs
mkdir -p bin sbin etc proc sys usr/bin usr/sbin root home/tan
cd ..
cp -a busybox-$BUSYBOX_VERSION/_install/* fs

#
# modules
#

# echo "[+] Building modules..."
# cd src
# make
# cd ..
# cp src/*.ko fs/

cd ../linux
cp ../kerneldev/init.sh .
chmod +x init.sh
./usr/gen_initramfs.sh -o ../kerneldev/initramfs.img ../kerneldev/fs ../kerneldev/cpio_list
../linux/usr/gen_initramfs.sh -o ./initramfs.img ./fs ./cpio_list

ln -s ../linux ./linux

cd ../kerneldev/

# sudo apt-get update
# sudo apt-get install -y bison flex libelf-dev cpio build-essential libssl-dev qemu-system-x86
# launch
qemu-system-x86_64 \
    -kernel ../linux/arch/x86/boot/bzImage \
    -initrd initramfs.img \
	-append "console=ttyS0 root=/dev/sr0 ip=dhcp" \
    -fsdev local,security_model=passthrough,id=fsdev0,path=share \
    -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=hostshare \
    -m 4G \
	-nographic 

# debug
# target remote 127.0.0.1:6666
qemu-system-x86_64 \
    -kernel ../linux/arch/x86/boot/bzImage \
    -initrd initramfs.img \
    -append "console=ttyS0 root=/dev/ram ip=dhcp" \
    -fsdev local,security_model=passthrough,id=fsdev0,path=share \
    -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=hostshare \
	-nographic \
	-monitor none \
	-S -gdb tcp::6666 -append "console=ttyS0 nokaslr ip=dhcp" \
	-m 4G \
    -serial mon:stdio


qemu-img create -f qcow2 mydisk.img 20G
qemu-img create -f qcow2 mydisk.img 10G


qemu-system-x86_64 \
    -kernel ../linux/arch/x86/boot/bzImage \
    -initrd initramfs.img \
    -append "console=ttyS0 root=/dev/ram ip=dhcp" \
    -fsdev local,security_model=passthrough,id=fsdev0,path=share \
    -device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=hostshare \
    -nographic \
    -monitor none \
    -S -gdb tcp::6666 -append "console=ttyS0 nokaslr ip=dhcp" \
    -m 4G \
    -serial mon:stdio \
    -drive file=mydisk.img,format=qcow2


# share.sh

mkdir -p /share
mount -t 9p -o trans=virtio,version=9p2000.L hostshare /share



```

# kernel config

```bash

make menuconfig

make xconfig

make oldconfig

make defconfig

make kernelversion

```

# Testing and Debugging

printk dmesg logs

https://github.com/linux-test-project/ltp

Linux Kernel Selftests (kselftests) part of the Linux Kernel

```bash

git clone https://github.com/linux-test-project/ltp.git
cd ltp
make autotools
./configure

./build.sh

cd testcases/kernel/syscalls/
make
PATH=$PATH:$PWD ./foo01

```

# memory management (memory driver)

M = N / PAGE_SIZE


handle_mm_fault page fault

user space memory mapping is changed when context switching

0x C000 0000 CONFIG_PAGE_OFFSET CONFIG_MEMORY_START

CONFIG_VMSPLIT_

kernel logical address kmalloc() fixed offset from 0xc0000000 -> 0x00000000

vmalloc() ioremap() kmap() PCI PCIE SoC IP Blocks ioremap() kmap()


__pa(x) __va(x) 


0xffffffff

PAGE_OFFSET 0xfffffc0000000000UL

0x00000000


0xffffffff
kernel virtual address

kernel logical address non contiuous module install ioremap

--- PAGE_OFFSET ---

user virtual address task_struct struct mm
0x00000000

A page is a unit of memory sized and aligned at the page size.

User space memory can not typically be used for DMA.

# Interrupt & Exception

void handle_IPI(int ipinr, struct pt_regs *regs)

non-maskable interrupt 

arm fast interrupt reQuest dedicated registers

fiq_debugger

ps axl | grep irq

General power controller

generic interrupt controller

gpio-mxc

inter processor interrupt

IRQS head-IRQ softirqs tasklets RT vs no-RT kprobes event tracing mpstat ebpf

NAPI vs eth IRQS

```bash
# raspi5 Linux tannal-desktop 6.5.0-1008-raspi #11-Ubuntu SMP PREEMPT_DYNAMIC Wed Nov 22 19:08:26 UTC 2023 aarch64 aarch64 aarch64 GNU/Linux

cat /proc/interrupts

sudo apt install sysstat

mpstat -A

top half the hard IRQ

IR interruput Q 

arch/x86/kernel/irq.c


bottom half the soft IRQ

# IPIS NMIS atomic operations softirqs rt current task in softirq

# threaded IRQS hard IRQ NAPI



           CPU0       CPU1       CPU2       CPU3       
  9:          0          0          0          0     GICv2  25 Level     vgic
 11:          0          0          0          0     GICv2  30 Level     kvm guest ptimer
 12:          0          0          0          0     GICv2  27 Level     kvm guest vtimer
 13:     130282     239972     132960     173648     GICv2  26 Level     arch_timer
 14:      34307          0          0          0     GICv2  65 Level     107c013880.mailbox
 21:          0          0          0          0     GICv2 118 Level     DMA IRQ
 22:          0          0          0          0     GICv2 119 Level     DMA IRQ
 23:          0          0          0          0     GICv2 120 Level     DMA IRQ
 24:          0          0          0          0     GICv2 121 Level     DMA IRQ
 33:          0          0          0          0     GICv2  48 Level     arm-pmu
 34:          0          0          0          0     GICv2  49 Level     arm-pmu
 35:          0          0          0          0     GICv2  50 Level     arm-pmu
 36:          0          0          0          0     GICv2  51 Level     arm-pmu
 37:          0          0          0          0  intc@7d508380   1 Level     107d508200.i2c
 39:          0          0          0          0  intc@7d508380   2 Level     107d508280.i2c
 40:          0          0          0          0  107d508500.gpio  20 Edge      pwr_button
 41:       2655          0          0          0     GICv2 308 Level     ttyS0
 42:          0          0          0          0     GICv2 150 Level     107d004000.spi
 44:          0          0          0          0     GICv2 261 Level     PCIe PME, aerdrv
112:          0          0          0          0  rp1_irq_chip   6 Level     eth0
114:          0          0          0          0  rp1_irq_chip   8 Level     1f00074000.i2c
137:       1315          0          0          0  rp1_irq_chip  31 Edge      xhci-hcd:usb1
142:          0          0          0          0  rp1_irq_chip  36 Edge      xhci-hcd:usb3
167:     330042          0          0          0     GICv2 306 Level     mmc1
168:      63698          0          0          0     GICv2 305 Level     mmc0
169:          0          0          0          0     GICv2 281 Level     v3d_core0
170:          0          0          0          0     GICv2 282 Level     v3d_hub
171:          0          0          0          0     GICv2 104 Level     pispbe
172:          0          0          0          0     GICv2 130 Level     1000800000.codec
173:          0          0          0          0  interrupt-controller@7c502000   2 Level     107c580000.hvs
174:          0          0          0          0  interrupt-controller@7c502000   9 Level     107c580000.hvs
175:          0          0          0          0  interrupt-controller@7c502000  16 Level     107c580000.hvs
176:          0          0          0          0  interrupt-controller@7d510600   7 Level     vc4 hdmi hpd connected
177:          0          0          0          0  interrupt-controller@7d510600   8 Level     vc4 hdmi hpd disconnected
178:          0          0          0          0  interrupt-controller@7d510600   2 Level     vc4 hdmi cec rx
179:          0          0          0          0  interrupt-controller@7d510600   1 Level     vc4 hdmi cec tx
180:          0          0          0          0  interrupt-controller@7d510600  14 Level     vc4 hdmi hpd connected
181:          0          0          0          0  interrupt-controller@7d510600  15 Level     vc4 hdmi hpd disconnected
182:          0          0          0          0  interrupt-controller@7d510600  12 Level     vc4 hdmi cec rx
183:          0          0          0          0  interrupt-controller@7d510600  11 Level     vc4 hdmi cec tx
184:          0          0          0          0  interrupt-controller@7c502000   1 Level     107c500000.mop
185:          0          0          0          0  interrupt-controller@7c502000   0 Level     107c501000.moplet
186:          0          0          0          0     GICv2 133 Level     vc4 crtc
187:          0          0          0          0     GICv2 142 Level     vc4 crtc
IPI0:      2854       4059       3773       4542       Rescheduling interrupts
IPI1:     70366     178796     121577     102446       Function call interrupts
IPI2:         0          0          0          0       CPU stop interrupts
IPI3:         0          0          0          0       CPU stop (for crash dump) interrupts
IPI4:         0          0          0          0       Timer broadcast interrupts
IPI5:     40208      zonzon      44032      51457       IRQ work interrupts
IPI6:         0          0          0          0       CPU wake-up interrupts
Err:          0



```

# Real Time Linux

# Kernel Virtual Machine

since 2.6.20

every vm is a regular linux process.

scheduled by the standard linux scheduler

qemu is part of kvm tiny code generator or kvm

domain0 privileged domU user

egrep --count '^flags.*(vmx|svm)' /proc/cpuinfo


```bash

sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils

systemctl start libvirtd

lsmod | egrep 'kvm_*(amd|intel)'

sudo usermod --append --groups=kvm,libvirt ${USER}

cat /etc/group | egrep "^(kvm|libvirt).*${USER}"

cp /etc/libvirt/qemu.conf /etc/libvirt/qemu.conf.original

sed --in-place \
	

systemctl enable libvirtd

```


# rust for linux kernel

```bash

make LLVM=1 rustavailable -j20


```

# EBPF & tracing

# file system (disk driver)
# virtual file system

# process management scheduler (cpu driver)

## process

```c
for_each_process(task) {
	
}
// get task from pid
task = get_pid_task(hpriv->taskpid, PIDTYPE_PID);

// current macro get current task on this cpu
// 
static inline struct task_struct *get_task_struct(struct task_struct *t)
{
	refcount_inc(&t->usage);
	return t;
}

set_current_state(TASK_RUNNING);

prev->__state

// get running queue on 
cpu = smp_processor_id();
rq = cpu_rq(cpu);
prev = rq->curr;

/* Context switch counts: */
unsigned long			nvcsw;
unsigned long			nivcsw;


```

## scheduler

cpu bound process scheduler

  b'update_curr'
  b'update_curr'
  b'task_tick_fair'
  b'scheduler_tick'
  b'update_process_times'
  b'tick_sched_handle'
  b'tick_sched_timer'
  b'__hrtimer_run_queues'
  b'hrtimer_interrupt'
  b'__sysvec_apic_timer_interrupt'
  b'sysvec_apic_timer_interrupt'
  b'asm_sysvec_apic_timer_interrupt'
    --
    b'clang++' [145292]
    305

# data structures

radixtree

rbtree

queue




An address space task->mm
One or more threads
Opened files	task->files
Sockets
Semaphores
Shared memory regions
Timers
Signal handlers 	task->signal
Many other resources and status information

# networking stack

# arch specific logic

# Linux Kernel Device Driver

include/linux/netdevice.h

include/linux/device.h@device

register_blkdev register_chrdev 

include/linux/blkdev.h@block_device_operations


kobjects

ktypes

ksets

device driver is abstrations to a piece of hardware

device driver can run in user space (UIO I2CDEV)

communicate with a device is just like r/w files.

ttyprintk

char device & block device & network interface

## Hardware access MMIO/gpiolib



```patch

diff --git a/include/uapi/linux/sysinfo.h b/include/uapi/linux/sysinfo.h
index 435d5c23f0c0..c1a57491f1a4 100644
--- a/include/uapi/linux/sysinfo.h
+++ b/include/uapi/linux/sysinfo.h
@@ -12,6 +12,7 @@ struct sysinfo {
        __kernel_ulong_t freeram;       /* Available memory size */
        __kernel_ulong_t sharedram;     /* Amount of shared memory */
        __kernel_ulong_t bufferram;     /* Memory used by buffers */
+       __kernel_ulong_t cacheram;      /* Memory used by caches */
        __kernel_ulong_t totalswap;     /* Total swap space size */
        __kernel_ulong_t freeswap;      /* swap space still available */
        __u16 procs;                    /* Number of current processes */
diff --git a/kernel/sys.c b/kernel/sys.c
index e219fcfa112d..bd402c7c8209 100644
--- a/kernel/sys.c
+++ b/kernel/sys.c
@@ -2825,6 +2825,7 @@ static int do_sysinfo(struct sysinfo *info)
        info->freeswap <<= bitcount;
        info->totalhigh <<= bitcount;
        info->freehigh <<= bitcount;
+       info->cacheram = 42;
 
 out:
        return 0;


```

# common name for specific type

fops file_operations

struct mm_struct *mm = current->mm;
struct vm_area_struct * vma;
pgtable_t pgtable aka struct page *pgtable


# appendix


kvm_reset_vcpu

```c

static struct cachepolicy cache_policies[] __initdata = {
	{
		.policy		= "uncached",
		.cr_mask	= CR_W|CR_C,
		.pmd		= PMD_SECT_UNCACHED,
		.pte		= L_PTE_MT_UNCACHED,
	}, {
		.policy		= "buffered",
		.cr_mask	= CR_C,
		.pmd		= PMD_SECT_BUFFERED,
		.pte		= L_PTE_MT_BUFFERABLE,
	}, {
		.policy		= "writethrough",
		.cr_mask	= 0,
		.pmd		= PMD_SECT_WT,
		.pte		= L_PTE_MT_WRITETHROUGH,
	}, {
		.policy		= "writeback",
		.cr_mask	= 0,
		.pmd		= PMD_SECT_WB,
		.pte		= L_PTE_MT_WRITEBACK,
	}, {
		.policy		= "writealloc",
		.cr_mask	= 0,
		.pmd		= PMD_SECT_WBWA,
		.pte		= L_PTE_MT_WRITEALLOC,
	}
};

```

send_sig_fault

faultin_page

inetsw_array

tcp_v4_rcv

_operations in linux kernel

smp_operations

cpu_operations hot pluging cpu

seq_operations

file_operations

vm_operations_struct

configfs

damon_operations

dax_operations

dentry_operations

export_operations

inode_operations

super_operations

address_space_operations

# community

messages for searching

https://lore.kernel.org/lkml/?q=the+scheduler

https://bugzilla.kernel.org/show_bug.cgi?id=218334

https://subspace.kernel.org/vger.kernel.org.html


# team lead

Greg Kroah-Hartman device driver

linus torvalds

# reference

https://patchwork.kernel.org/project/linux-kbuild/patch/20181206222318.218157-1-tmroeder@google.com/

https://nxw.name/2022/linux-network-stack

https://linux-kernel-labs.github.io/refs/heads/master/so2/lec3-processes.html#processes-and-threads

https://kernelnewbies.org/KernelBuild

https://courses.cs.washington.edu/courses/cse451/01wi/TLKCopy/tlk.html


# linux kernel labs

```bash

git clone https://github.com/linux-kernel-labs/linux.git

cd tools/labs

make docker-docs

make -j20

sudo apt install screen

screen /dev/pts/8


```

# build your own linux distro

```bash


wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.7.tar.xz

tar xvf linux-6.7.tar.xz

cd linux-6.7

https://github.com/maksimKorzh/msmd-linux/blob/main/config/kernel.cfg

make oldconfig

# glibc

wget https://ftp.gnu.org/gnu/glibc/glibc-2.38.tar.gz

tar xvf glibc-2.38.tar.gz

cd glibc-2.38

mkdir build
mkdir GLIBC

cd build

sudo apt install gawk

# llvm lld is not support for compiling glic
sudo rm /usr/bin/ld
sudo ln -s x86_64-linux-gnu-ld /usr/bin/ld


../configure --prefix=`pwd`/GLIBC
../configure --prefix=

make -j20

make install DESTDIR=../GLIBC

# sysroot

cd /home/tannal/tannalwork/projects/distro

mkdir sysroot

cd sysroot

mkdir usr

cd ..

cp -r glibc-2.38/GLIBC/* sysroot/

ls sysroot/
bin  etc  include  lib  libexec  sbin  share  var

cp -r GLIBC/include/* sysroot/include/
cp -r GLIBC/lib/* sysroot/lib/

mkdir sysroot/usr
rsync -a /usr/include sysroot

sudo apt-get install rsync

ln -s ../include sysroot/usr/include
ln -s ../lib sysroot/usr/lib

cd /home/tannal/tannalwork/projects/distro


git clone https://git.busybox.net/busybox/

https://busybox.net/downloads/

wget https://git.busybox.net/busybox/snapshot/busybox-1_36_1.tar.bz2

tar xvjf busybox-1_36_1.tar.bz2

cd busybox-1_36_1

make defconfig

CONFIG_SYSROOT="../sysroot"
CONFIG_EXTRA_CFLAGS="-L../sysroot/lib"

make CONFIG_PREFIX=$PWD/BUSYBOX install

cd /home/tannal/tannalwork/projects/distro
mkdir root

cp -r sysroot/* root/


rsync -a busybox-1_36_1/BUSYBOX/ root
# rsync -a busybox-1_36_1/_install/ root

rsync -a busybox-1.35.0/_install/ root

cd root
vim usr/bin/ldd

#!/bin/sh

rm linuxrc

mkdir dev proc sys

vim init

cd etc

vim network.sh
touch inittab
touch shell.sh
touch resolv.conf
history

```bash
# root/init
#!/bin/sh

dmesg -n 1

clear

echo "hello from init"

mount -t devtmpfs none /dev
mount -t proc none /proc
mount -t sysfs none /sys

for NETDEV in /sys/class/net/* ; do
    DEV_NAME=$(basename "$NETDEV")
    echo "Found network device $DEV_NAME"
    ip link set "$DEV_NAME" up
    [ "$DEV_NAME" != "lo" ] && udhcpc -b -i "$DEV_NAME" -s /etc/network.sh
done

exec /sbin/init


# etc/network.sh

#!/bin/sh

ip addr add $ip/$mask dev $interface
if [ "$router" ]; then
	ip route add default via $router dev $interface
fi

if [ "$ip" ]; then
	echo -e "DHCP configuration for device $interface"
	echo -e "IP: \\e[1m$ip\\e[0m"
	echo -e "mask: \\e[1m$mask\\e[0m"
	echo -e "router: \\e[1m$router\\e[0m"
fi


# etc/inittab

::sysinit:cat /etc/logo.txt
::restart:/sbin/init
::shutdown:sync
::shutdown:umount -a
::ctrlaltdel:/sbin/reboot
::respawn:/bin/cttyhack /etc/shell.sh

# etc/shell.sh

sh

# etc/resolv.conf
namesever 8.8.8.8
namesever 8.8.4.4
nameserver 202.102.192.68
nameserver 202.102.192.69

ln -s lib lib64

# grub

mkdir -p iso/boot/grub
touch iso/boot/grub/grub.cfg

# grub.cfg

set default=0
set timeout=10
insmod efi_gop
insmod font
if loadfont /boot/grub/fonts/unicode.pf2
then
  insmod gfxterm
  set gfxmode-auto
  set gfxpayload=keep
  terminal_output gfxterm
fi
menuentry 'MONKEY SEE, MONKEY DO LINUX' --class os {
  insmod gzio
  insmod part_msdos
  linux /boot/bzImage
  initrd /boot/root.cpio.gz
}

cp linux-6.7/arch/x86_64/boot/bzImage iso/boot/

cd root

find . | cpio -o -H newc | gzip > ../iso/boot/root.cpio.gz


cd ..

sudo apt install xorriso mtools qemu-system-x86

grub-mkrescue -o mylinux-core-glibc.iso ./iso

qemu-system-x86_64 -boot d -cdrom mylinux-core-glibc.iso -enable-kvm -m 4G

qemu-system-x86_64 -boot d -cdrom mylinux-core-glibc.iso -enable-kvm -m 4G -S -gdb tcp::6666

 -append "nokaslr"

gdb ./linux-6.7/vmlinux

target remote localhost:6666


CONFIG_GDB_SCRIPTS=y
CONFIG_DEBUG_INFO=y
CONFIG_DEBUG_INFO_REDUCED=n
CONFIG_DEBUG_INFO_SPLIT=n
CONFIG_DEBUG_FS=y
CONFIG_DEBUG_INFO_DWARF4=y
CONFIG_DEBUG_INFO_BTF=y
CONFIG_FRAME_POINTER=y


```

```

# tracing point

```bash

sudo ./kprobe -s 'p:__arm64_sys_brk'



sudo ./kprobe -s 'p:el0t_64_sync_handler'


```

# tokei

(base) a13@13:~/tannalwork/projects/linux$ tokei 
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Language              Files        Lines         Code     Comments       Blanks
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 AWK                      11         2501         1697          473          331
 Alex                      1           36           32            0            4
 ASN.1                    15          656          441           87          128
 Assembly                  6         3869         3594            0          275
 GNU Style Assembly     1332       372449       271685        56364        44400
 Autoconf                  5          433          377           26           30
 Automake                  3           31           23            3            5
 BASH                     59         2033         1372          352          309
 Bazel                    86         1169          991           22          156
 Bitbake                  21         2945          681         1951          313
 C                     34659     24594562     18300364      2750917      3543281
 C Header              25292     10054625      7804093      1500872       749660
 C++                       7         2350         2024           85          241
 C++ Header                2          125           59           55           11
 CSS                       3          295          172           69           54
 Device Tree            5329      1645188      1349974        79667       215547
 Forge Config             15         1351          320          744          287
 Gherkin (Cucumber)        1          311          212           62           37
 Happy                    10         6081         5360            0          721
 HEX                       2          173          173            0            0
 INI                       2           13            6            5            2
 Jinja2                  127         1042          854          123           65
 JSON                    866       537433       537431            0            2
 Lex                      10         2980         2274          336          370
 LD Script                13          537          413           40           84
 Makefile               3036        80813        55648        12957        12208
 Module-Definition         2          128          113            0           15
 Objective-C               1           89           72            0           17
 Pacman's makepkg          1          132           90           13           29
 Perl                     62        44034        34265         3967         5802
 PO File                   6         5769         2885         1936          948
 Python                  272        81834        64974         5067        11793
 RPM Specfile              1          131          111            2           18
 ReStructuredText       3598       745443       565320            0       180123
 Ruby                      1           29           25            0            4
 Shell                   953       183665       127736        23365        32564
 Snakemake                 4          116           90           13           13
 SVG                      77        50659        49268         1301           90
 SWIG                      1          247          150           27           70
 TeX                       1          234          155           73            6
 Plain Text             1511       136757            0       112034        24723
 TOML                      1           12            2            9            1
 Unreal Script             5          671          415          158           98
 Apache Velocity           1           12           12            0            0
 Vim Script                1           42           33            6            3
 XSL                      10          200          122           52           26
 XML                      23        22150        19839         1348          963
 YAML                   4388       491241       399495        18593        73153
─────────────────────────────────────────────────────────────────────────────────
 HTML                      2           28           22            3            3
 |- JavaScript             1            7            7            0            0
 (Total)                               35           29            3            3
─────────────────────────────────────────────────────────────────────────────────
 Markdown                  1          248            0          177           71
 |- BASH                   1            2            2            0            0
 |- C                      1           20           12            6            2
 (Total)                              270           14          183           73
─────────────────────────────────────────────────────────────────────────────────
 Rust                     76        12370         8982         1819         1569
 |- Markdown              70         6425          772         4247         1406
 (Total)                            18795         9754         6066         2975
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Total                 81912     39096696     29615239      4579426      4902031
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
