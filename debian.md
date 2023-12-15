

```bash

sudo mkdir -p /var/lib/shim-signed/mok/

cd /var/lib/shim-signed/mok/


sudo openssl req -new -x509 -newkey rsa:2048 -keyout MOK.priv -outform DER -out MOK.der -days 36500 -subj "/CN=tannal/"

sudo openssl x509 -inform der -in MOK.der -out MOK.pem

sudo mokutil --import /var/lib/shim-signed/mok/MOK.der # prompts for one-time password

sudo vim /etc/dkms/framework.conf

mok_signing_key="/var/lib/shim-signed/mok/MOK.priv"
mok_certificate="/var/lib/shim-signed/mok/MOK.der"


sudo vim /etc/dkms/sign_helper.sh

/lib/modules/"$1"/build/scripts/sign-file sha512 /root/.mok/client.priv /root/.mok/client.der "$2"


VERSION="$(uname -r)"
SHORT_VERSION="$(uname -r | cut -d . -f 1-2)"
MODULES_DIR=/lib/modules/$VERSION
KBUILD_DIR=/usr/lib/linux-kbuild-$SHORT_VERSION

sudo apt install sbsigntool

# sign kernel
sbsign --key MOK.priv --cert MOK.pem "/boot/vmlinuz-$VERSION" --output "/boot/vmlinuz-$VERSION.tmp"
sudo mv "/boot/vmlinuz-$VERSION.tmp" "/boot/vmlinuz-$VERSION"

# sign moduls

cd "$MODULES_DIR/updates/dkms" # For dkms packages

echo -n "Passphrase for the private key: "
read -s KBUILD_SIGN_PIN
export KBUILD_SIGN_PIN


# sudo --preserve-env=KBUILD_SIGN_PIN "$KBUILD_DIR"/scripts/sign-file sha256 /var/lib/shim-signed/mok/MOK.priv /var/lib/shim-signed/mok/MOK.der nvidia-current-peermem.ko

find -name \*.ko | while read i; do sudo --preserve-env=KBUILD_SIGN_PIN "$KBUILD_DIR"/scripts/sign-file sha256 /var/lib/shim-signed/mok/MOK.priv /var/lib/shim-signed/mok/MOK.der "$i" || break; done

mokutil --enable-validation



```

BIOS security boot and guard will impact touchpad


```bash
#deb cdrom:[Debian GNU/Linux 12.2.0 _Bookworm_ - Official amd64 NETINST with firmware 20231007-10:28]/ bookworm main non-free-firmware

deb http://deb.debian.org/debian/ bookworm main contrib non-free non-free-firmware
deb-src http://deb.debian.org/debian/ bookworm main contrib non-free non-free-firmware

deb http://security.debian.org/debian-security bookworm-security main contrib non-free non-free-firmware
deb-src http://security.debian.org/debian-security bookworm-security main contrib non-free non-free-firmware

# bookworm-updates, to get updates before a point release is made;
# see https://www.debian.org/doc/manuals/debian-reference/ch02.en.html#_updates_and_backports
deb http://deb.debian.org/debian/ bookworm-updates main contrib non-free non-free-firmware
deb-src http://deb.debian.org/debian/ bookworm-updates main contrib non-free non-free-firmware

# This system was installed using small removable media
# (e.g. netinst, live or single CD). The matching "deb cdrom"
# entries were disabled at the end of the installation process.
# For information about how to configure apt package sources,
# see the sources.list(5) manual.

```


```bash

deb http://mirrors.163.com/debian/ bookworm main non-free non-free-firmware contrib

sudo usermod -aG sudo username

sudo apt install nvidia-detect nvidia-driver

dpkg-reconfigure nvidia-kernel-dkms

sudo update-initramfs -u

nvidia-detect

lspci -nn | egrep -i "3d|display|vga"

nvidia-smi

sudo apt install nvidia-cuda-dev nvidia-cuda-toolkit


```



```bash

curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

sudo apt install python3-pip python3.11-venv

# python-is-python3

cd servo

./mach bootstrap

```