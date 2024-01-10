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