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

# scheduler (cpu driver)

# networking stack

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

# tracing point

```bash

sudo ./kprobe -s 'p:__arm64_sys_brk'



sudo ./kprobe -s 'p:el0t_64_sync_handler'


```


