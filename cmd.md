# list all usb devices


wmic path Win32_USBControllerDevice get Dependent


# Software install

winget install -e --id JetBrains.Toolbox
winget uninstall -e --id JetBrains.Toolbox

winget install ffmpeg
winget install --id=Gyan.FFmpeg  -e
winget install --id=MiKTeX.MiKTeX  -e
winget install -e --id emqx.mqttx

winget install --id=Racket.Racket  -e

winget install --id=MSYS2.MSYS2  -e
winget install --id=mesonbuild.meson  -e
winget install -e --id StrawberryPerl.StrawberryPerl
winget install Helix.Helix
winget install --id Typst.Typst
winget install --id=TheDocumentFoundation.LibreOffice  -e
sudo apt install chromium

winget install -e --id GoLang.Go
winget install -e --id GoLang.Go.1.22
winget install --id=SoftwareFreedomConservancy.QEMU  -e
winget install -e --id Rustlang.Rustup
winget install -e --id TorProject.TorBrowser
winget install -e --id Google.Chrome.Canary
winget install --id=Kingsoft.WPSOffice  -e
winget install -e --id CoreyButler.NVMforWindows
winget install -e --id Google.Chrome
winget install --id Git.Git -e --source winget
# winget install -e --id Corel.WinZip
# winget uninstall -e --id Corel.WinZip
winget install -e --id RARLab.WinRAR
winget install -e --id Unity.Unity.2022
winget install -e --id Kitware.CMake
winget install -e --id Python.Python.3.10
winget install -e --id Python.Python.3.11
winget install ChristianSchenk.MiKTeX
winget install -e --id Logitech.OptionsPlus
winget install --id chocolatey.chocolatey
winget install -e --id Microsoft.VisualStudioCode
winget install -e --id Microsoft.VisualStudioCode.1.94.2
winget install -e --id Microsoft.vcpkg
winget install Microsoft.OpenJDK.21
winget install Microsoft.OpenJDK.17
winget install Microsoft.OpenJDK.11
winget install Microsoft.OpenJDK.8
winget install -e --id Unity.UnityHub
winget install dart-sdk
winget install -e --id GoLang.Go.1.20


sudo curl -fsSL https://get.docker.com |bash

curl -fsSL https://get.docker.com |bash
sudo groupadd docker
sudo usermod -aG docker $USER
docker run hello-world

winget install -e --id GoLang.Go

winget install Microsoft.OpenJDK.17
winget install Microsoft.OpenJDK.11

wget https://f-droid.org/F-Droid.apk

https://github.com/f-droid

curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

sudo apt install golang-go

winget install --id=Neovim.Neovim  -e

sudo apt-get install build-essential

curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash
nvm install 20.11.0
nvm ls-remote --lts

nvm install v20.11.1
corepack enable

winget install XAMPPRocky.tokei
tokei

winget install -e --id WireGuard.WireGuard

sudo apt update

sudo apt install liblld-16-dev

sudo rm /var/lib/apt/lists/* -vf
sudo apt-get update

# Symbol link

sudo ln -sfn aarch64-linux-gnu-ld /usr/bin/ld
sudo ln -sfn /usr/bin/lld /usr/bin/ld

# Powershell

Get-Content input | node vj.js
