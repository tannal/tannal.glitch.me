# 


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