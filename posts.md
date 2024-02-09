
# 


# Build your own linux distribution

build glibc busybox linux kernel

rootfs sysroot

# Connect local networks via wireguard

sudo apt install wireguard-tools wireguard-go resolvconf

sudo vim /etc/wireguard/wg0.conf

wg-quick up wg0 #wg启动命令
wg-quick down wg0 #wg关闭命令

sudo vim /etc/sysctl.conf

net.ipv4.ip_forward = 1

sysctl -p /etc/sysctl.conf

```conf

[Interface]
PrivateKey = 8APocBKyPt185rC9a6Sn78jhJ/Uhsqt+REDXTH8mOUo=
Address = 10.0.8.1

PostUp   = iptables -A FORWARD -i wg0 -j ACCEPT; iptables -A FORWARD -o wg0 -j ACCEPT; iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
PostDown = iptables -D FORWARD -i wg0 -j ACCEPT; iptables -D FORWARD -o wg0 -j ACCEPT; iptables -t nat -D POSTROUTING -o eth0 -j MASQUERADE

ListenPort = 444
DNS = 8.8.8.8
MTU = 1500
[Peer]
PublicKey = pInyIleVxjBZU623GTlEzY92oSVUXKoDil5xaKVVJHA=

AllowedIPs = 10.0.8.10/32

[Peer]
PublicKey = Gv+dyaWWaxSsYjTe0p76+G6E9MyUyvRUYGg1Pl+6/k8=
AllowedIPs = 10.0.8.11/32

[Peer]
PublicKey = NNdpv5fx/V6fcExYQLQzhMHfnwmqYC7O0Y9UzrBTwQI=
AllowedIPs = 10.0.8.12/32

```