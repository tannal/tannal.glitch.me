```bash

git clone https://git.buildroot.net/buildroot

cd buildroot

ls configs

make raspberrypi3_64_defconfig -j20
make qemu_x86_64_defconfig


make menuconfig

time make -j20

real	24m45.377s
user	151m31.696s
sys	17m41.751s

ls -la output/images/

lsblk

sudo dd if=output/images/sdcard.img of=/dev/mmcblk2 bs=1M

```

```bash

Yocto Project

sudo apt install -y bc build-essential chrpath cpio diffstat gawk git texinfo wget gdisk python3 python3-pip libssl-dev

sudo apt install python-is-python3

git clone https://git.yoctoproject.org/poky.git

cd poky



```