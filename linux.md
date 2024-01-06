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