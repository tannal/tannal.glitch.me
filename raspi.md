
# boot

sequenceDiagram
    participant SD as SD卡
    participant GPU as VideoCore GPU
    participant CPU as ARM CPU
    participant Mem as 内存
    Note over GPU,CPU: 1. 上电启动
    GPU->>SD: 读取bootcode.bin
    GPU->>Mem: 加载firmware到0x0
    Note over GPU: 2. 加载第一阶段
    GPU->>SD: 读取start*.elf
    GPU->>Mem: 加载kernel.img到0x80000
    Note over GPU: 3. 配置硬件
    GPU->>CPU: 释放CPU复位
    Note over CPU: 4. CPU开始执行
    CPU->>Mem: 从0x0开始执行
    Note over CPU: 5. 跳转到内核
    CPU->>Mem: 跳转到0x80000

启动顺序详解:
第一阶段(GPU):
bootcode.bin (GPU固件)
- GPU首先执行
- 初始化SDRAM
- 加载start*.elf
第二阶段(GPU):
start*.elf (GPU系统)
- 读取config.txt配置
- 加载firmware.bin到0x0
- 加载kernel.img到0x80000
第三阶段(CPU):
firmware.bin (ARM固件)
- 从0x0开始执行
- 设置CPU状态
- 配置时钟/外设
- 跳转到0x80000
第四阶段(CPU):
kernel.img (内核)
- 从0x80000开始执行
- 完成内核初始化
- 启动操作系统
必要的文件:
SD卡根目录:
├── bootcode.bin    # GPU引导程序
├── start*.elf      # GPU系统
├── fixup*.dat      # GPU内存分配
├── config.txt      # 配置文件
├── firmware.bin    # ARM固件
└── kernel.img      # 内核镜像
这种设计的原因:
历史原因: 树莅派最初设计为媒体播放器
硬件限制: ARM CPU不能直接访问SD卡
灵活性: GPU可以灵活配置系统参数
兼容性: 支持不同版本的ARM处理器
注意事项:
GPU和CPU共享内存
内存分配受config.txt控制
固件版本需要匹配
启动文件名称固定


# dev

export PREFIX=aarch64-linux-gnu-
export AARCH=64
export RASPPI=3
./configure --qemu -r 3 --prefix aarch64-linux-gnu-

// aarch64-linux-gnu-gcc -c a.S
// a.S
.section ".text"
_start:
  wfe
  b _start

// linker.ld
SECTIONS

{

  . = 0x80000;

  .text : { *(.text) }

}

.c .S -> .o -> elf -> img

aarch64-linux-gnu-objcopy -O binary kernel8.elf kernel8.img
aarch64-linux-gnu-ld -T linker.ld -o kernel8.elf a.o
qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -S -s

# people




# inbox

```bash

sudo apt install qemu-system-arm gcc-aarch64-linux-gnu

git clone https://git.busybox.net/busybox
cd busybox
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- defconfig
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- menuconfig
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j20
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- install

$ ls -l _install/
total 12
drwxr-xr-x 2 zack zack 4096 Jun  5 12:06 bin
lrwxrwxrwx 1 zack zack   11 Jun  5 12:06 linuxrc -> bin/busybox
drwxr-xr-x 2 zack zack 4096 Jun  5 12:06 sbin
drwxr-xr-x 4 zack zack 4096 Jun  5 12:06 usr

cd ..
mkdir -p ./qemu-images/
dd if=/dev/zero of=./qemu-images/simple-busybox.img bs=8M count=16

fdisk -l ./qemu-images/simple-busybox.img

mkfs.vfat -v --offset=2048 ./qemu-images/simple-busybox.img $((100*1024*1024/1024))

mkfs.ext4 -E offset=$((512*206848)) ./qemu-images/simple-busybox.img

sudo mount -o offset=$((512*206848)) ./qemu-images/simple-busybox.img /mnt/

cd busybox
sudo cp -r _install/* /mnt/
sudo mkdir -p /mnt/etc
sudo mkdir -p /mnt/etc/init.d
sudo mkdir -p /mnt/proc
sudo mkdir -p /mnt/sys
sudo mkdir -p /mnt/dev
sudo mkdir -p /mnt/tmp
sudo mkdir -p /mnt/root
sudo mkdir -p /mnt/var
sudo mkdir -p /mnt/lib
sudo mkdir -p /mnt/mnt
sudo mkdir -p /mnt/boot
ls -l /mnt/
total 15
drwxr-xr-x 2 root root 3072 Apr  5 22:39 bin
drwxr-xr-x 2 root root 1024 Apr  5 22:41 boot
drwxr-xr-x 2 root root 1024 Apr  5 22:41 dev
drwxr-xr-x 3 root root 1024 Apr  5 22:41 etc
lrwxrwxrwx 1 root root   11 Apr  5 22:39 linuxrc -> bin/busybox
drwxr-xr-x 2 root root 1024 Apr  5 22:41 mnt
drwxr-xr-x 2 root root 1024 Apr  5 22:41 proc
drwxr-xr-x 2 root root 1024 Apr  5 22:41 root
drwxr-xr-x 2 root root 3072 Apr  5 22:39 sbin
drwxr-xr-x 2 root root 1024 Apr  5 22:41 sys
drwxr-xr-x 2 root root 1024 Apr  5 22:41 tmp
drwxr-xr-x 4 root root 1024 Apr  5 22:39 usr
drwxr-xr-x 2 root root 1024 Apr  5 22:41 var

sudo install ./examples/inittab /mnt/etc/inittab

## Install udhcpc script for obtaining & setting IP to interface
## http://dannysun-unknown.blogspot.com/2018/08/busybox-udhcpc-ipip.html
sudo install -d /mnt/usr/share/udhcpc
sudo install examples/udhcp/simple.script /mnt/usr/share/udhcpc/default.script
echo "nameserver 8.8.8.8" | sudo tee -a /mnt/etc/resolv.conf # Maybe not
## Set host name
echo "busybox-arm64" | sudo tee -a /mnt/etc/hostname
## Initial script
cat /mnt/etc/init.d/rcS

#!/bin/sh
mount -a
ip link set eth0 up
udhcpc
hostname -F /etc/hostname
ntpd -n -q -p time.stdtime.gov.tw
sudo chmod +x /mnt/etc/init.d/rcS
## User list
echo "root:x:0:0::/root:/bin/sh" | sudo tee -a /mnt/etc/passwd
echo "root::18541::::::" | sudo tee -a /mnt/etc/shadow



git checkout tags/v5.15.24
cp arch/arm/configs/vexpress_defconfig .config
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- menuconfig # Leave ARMv8 software model (Versatile Express) only
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j20

qemu-system-aarch64 -smp 2 -M virt -cpu cortex-a57 -m 1G -kernel ./linux/arch/arm64/boot/Image --append "console=ttyAMA0 root=/dev/vda2 rw rootfstype=ext4" -hda ./qemu-images/simple-busybox.img -nographic

```
RX TX GAND

https://forums.raspberrypi.com/viewtopic.php?t=42279

qemu-img resize disk.img +16G

```bash

cp /usr/bin/raspi-config ~
sed -i 's/mmcblk0p2/sda2/' ~/raspi-config
sed -i 's/mmcblk0/sda/' ~/raspi-config
sudo ~/raspi-config

```

https://forums.raspberrypi.com/viewtopic.php?p=129525#p129525

https://forums.raspberrypi.com/viewtopic.php?p=129525#p129525




```bash
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install gcc-9
```


# PC vs rspberry pi


```bash
# PC
sequenceDiagram
    participant CPU as CPU
    participant ROM as ROM/Flash
    participant RAM as RAM
    participant Disk as 硬盘

    Note over CPU: 1. 加电自检(POST)
    CPU->>ROM: 执行固件(UEFI/BIOS)
    ROM->>RAM: 加载固件服务
    Note over CPU: 2. 初始化硬件
    CPU->>Disk: 寻找引导设备
    Disk->>RAM: 加载引导程序
    Note over CPU: 3. 引导加载
    CPU->>RAM: 执行bootloader
    RAM->>Disk: 加载操作系统
    Note over CPU: 4. 启动系统
```
