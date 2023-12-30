```bash

git clone https://git.buildroot.net/buildroot

cd buildroot

ls configs

make raspberrypi3_64_defconfig -j20


make menuconfig

time make -j20

ls -la output/images/

lsblk

sudo dd if=output/images/sdcard.img of=/dev/mmcblk2 bs=1M

```