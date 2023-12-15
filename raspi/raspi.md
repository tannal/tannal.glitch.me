# 


```sh

cp /usr/bin/raspi-config ~
sed -i 's/mmcblk0p2/sda2/' ~/raspi-config                                                                              
sed -i 's/mmcblk0/sda/' ~/raspi-config
sudo ~/raspi-config

```

https://forums.raspberrypi.com/viewtopic.php?p=129525#p129525

https://forums.raspberrypi.com/viewtopic.php?p=129525#p129525




```sh
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install gcc-9
```