
# commands

```bash
#nvm 和 nodejs
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.3/install.sh | bash

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

nvm ls-remote --lts

nvm list available

#pnpm
corepack enable

#deno
curl -fsSL https://deno.land/x/install/install.sh | sh
#国内
curl -fsSL https://x.deno.js.cn/install.sh | sh
export DENO_INSTALL="/home/ubuntu/.deno"
export PATH="$DENO_INSTALL/bin:$PATH"


#配置git
git config --global user.name "MarybethGasman"
git config --global user.email "2934482133@qq.com"

git config --global user.name "tannal"
git config --global user.email "tannal2409@gmail.com"

# clangd server
sudo apt-get install clangd-12

sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-12 100


#Linux kernel 国内镜像git，非常快
https://kernel.source.codeaurora.cn/

#最新jdk
wget https://download.oracle.com/java/19/latest/jdk-19_linux-x64_bin.deb

sudo apt-get -qqy install ./jdk-19_linux-x64_bin.deb

sudo update-alternatives --install /usr/bin/java java /usr/lib/jvm/jdk-19/bin/java 1919

# Mysql
sudo apt install mysql-server
CREATE USER 'tan'@'%' IDENTIFIED WITH mysql_native_password BY 'tanm146';
GRANT CREATE, ALTER, DROP, INSERT, UPDATE, INDEX, DELETE, SELECT, REFERENCES, RELOAD on *.* TO 'tan'@'%' WITH GRANT OPTION;
## Mysql改配置
sudo vim /etc/mysql/mysql.conf.d/mysqld.cnf
# 重启mysql
sudo systemctl restart mysql
# 关闭mysql
sudo /etc/init.d/mysql stop

#Go的开发环境
sudo snap install go --classic
go env -w GOPROXY=https://goproxy.cn


# trace-cmd
git clone https://kernel.source.codeaurora.cn/pub/scm/utils/trace-cmd/trace-cmd.git


# 编译linux内核安装
sudo apt-get install libssl-dev bison flex libelf-dev

# git pull (would clobber existing tag)
git fetch --tags --force


#编译内核的权限key问题
https://blog.csdn.net/qq_36393978/article/details/118157426

https://blog.csdn.net/m0_47696151/article/details/121574718

#新建swap分区
sudo fallocate -l 3G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
sudo swapon --show


#qemu
qemu-system-x86_64 -nographic -m 1024 \
    -kernel arch/x86_64/boot/bzImage \
    -initrd initramfs.img \
    -append 'console=ttyS0' \
    -nographic

# rust
export RUSTUP_DIST_SERVER=https://mirrors.ustc.edu.cn/rust-static
export RUSTUP_UPDATE_ROOT=https://mirrors.ustc.edu.cn/rust-static/rustup
curl https://sh.rustup.rs -sSf | sh
source $HOME/.cargo/env

code ~/.cargo/config

[source.crates-io]
registry = "https://github.com/rust-lang/crates.io-index"
replace-with = 'ustc'
[source.ustc]
registry = "git://mirrors.ustc.edu.cn/crates.io-index"



# npm 腾讯云
npm config set registry http://mirrors.cloud.tencent.com/npm/

# 一些环境变量的配置
sudo update-alternatives --config java

# android sdk
sudo apt install sdkmanager
sudo sdkmanager "platform-tools;34.0.3" "build-tools;33.0.2" "platforms;android-28" "tools;26.1.1"
sudo sdkmanager "build-tools;28.0.3" "platforms;android-29"
mv $ANDROID_HOME/tools $ANDROID_HOME/cmdline-tools/latest/
sudo chown -R ubuntu /opt/android-sdk/
export ANDROID_HOME="/opt/android-sdk/"
export PATH="$PATH:$ANDROID_HOME/tools/bin"
export NO_PROXY=localhost,127.0.0.1,::1
flutter doctor --android-licenses

# flutter release
systemProp.http.proxyHost=127.0.0.1
systemProp.http.proxyPort=7890
systemProp.https.proxyHost=127.0.0.1
systemProp.https.proxyPort=7890

#java
sudo apt install openjdk-17-jdk

# bpf
sudo apt install libbpf-dev llvm linux-tools-5.15.0-56-generic
## 编译安装bpftool
git clone https://github.com/libbpf/bpftool.git
git submodule update --init
cd src && make
sudo make install


#android
https://juejin.cn/post/7019992544444416037#heading-5



#git clone慢
git config --global url."https://gitclone.com/".insteadOf https://

git config --global --unset url."https://gitclone.com/"


# nvim

wget https://github.com/neovim/neovim/releases/download/nightly/nvim.appimage
./nvim.appimage --appimage-extract
alias vim=~/tannalwork/squashfs-root/usr/bin/nvim

# clash网页

git clone -b gh-pages --depth 1 https://github.com/Dreamacro/clash-dashboard
external-ui: clash-dashboard/



# docker


sudo curl -fsSL https://get.docker.com |bash

sudo groupadd docker
sudo usermod -aG docker $USER

# docker-compose

sudo apt  install docker-compose

# docker管理

docker run -d -p 8000:8000 -p 9000:9000 --name=portainer --restart=always -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data portainer/portainer-ce


#  Nginx Proxy Manager

docker-compose up -d

version: '3.8'
services:
  app:
    image: 'jc21/nginx-proxy-manager:latest'
    restart: unless-stopped
    ports:
      - '80:80'
      - '81:81'
      - '443:443'
    volumes:
      - ./data:/data
      - ./letsencrypt:/etc/letsencrypt

# vaultwarden密码管理工具

docker run -d --name vaultwarden -v /vw-data/:/data/ -p 82:80 vaultwarden/server:latest

# uptime 网页可用性监控

docker run -d --restart=always -p 3001:3001 -v uptime-kuma:/app/data --name uptime-kuma louislam/uptime-kuma:1

# dashy
docker run -p 8080:80 lissy93/dashy



# vscode 导出扩展

code --list-extensions | xargs -L 1

# 推荐拓展
"remote.SSH.defaultExtensions": [
  "bradlc.vscode-tailwindcss",
  "christian-kohler.npm-intellisense",
  "christian-kohler.path-intellisense",
  "eamodio.gitlens",
  "golang.go",
  "Gruntfuggly.todo-tree",
  "llvm-vs-code-extensions.vscode-clangd",
  "MS-CEINTL.vscode-language-pack-zh-hans",
  "ms-python.isort",
  "ms-python.python",
  "ms-python.vscode-pylance",
  "ms-toolsai.jupyter",
  "ms-toolsai.jupyter-keymap",
  "ms-toolsai.jupyter-renderers",
  "ms-toolsai.vscode-jupyter-cell-tags",
  "ms-toolsai.vscode-jupyter-slideshow",
  "ms-vscode.hexeditor",
  "mutantdino.resourcemonitor",
  "ocamllabs.ocaml-platform",
  "PolyMeilex.wgsl",
  "redhat.java",
  "rust-lang.rust-analyzer",
  "vadimcn.vscode-lldb",
  "VisualStudioExptTeam.intellicode-api-usage-examples",
  "VisualStudioExptTeam.vscodeintellicode",
  "vscjava.vscode-java-debug",
  "vscjava.vscode-java-dependency",
  "vscjava.vscode-java-pack",
  "vscjava.vscode-java-test",
  "vscjava.vscode-maven",
  "Vue.volar",
  "Vue.vscode-typescript-vue-plugin",
  "ziglang.vscode-zig"
];


# 下载google drive里的文件
pip install gdown -i https://pypi.tuna.tsinghua.edu.cn/simple



export PATH="$HOME/.local/bin:$PATH"



gdown --id 11DcV01Xjy1HA-nFR3HmDcFM_udWwmQ9l

# 无GUI的chrome

sudo apt-get -y install libxss1 libappindicator1 libindicator7
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome*.deb  # Might show "errors", fixed by next line
sudo apt-get install -f



# Selenium WebDriver for JavaScript


sudo apt install chromium-chromedrivers



# install fastline for reactnative
sudo apt-get update
sudo apt -y install build-essential ruby ruby-dev

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
sudo gem install google-api-client
sudo gem install fastlane -NV


# traggo

docker run -p 80:3030 -v /opt/traggo/data:/opt/traggo/data traggo/server:latest --env TRAGGO_DEFAULT_USER_NAME=admin -e TRAGGO_DEFAULT_USER_PASS=admin


# ReactNative build

npm install --global expo-cli eas-cli
expo login
"start": "expo start",
"android": "expo start --android",
"ios": "expo start --ios",
"web": "expo start --web",




# flutter
sudo snap install flutter --classic

# release apk
flutter build apk --release

flutter run -d web-server --web-hostname 0.0.0.0 --web-port 3000

sudo apt-get install clang cmake ninja-build pkg-config libgtk-3-dev liblzma-dev

sudo apt install -y openjdk-11-jdk

sudo add-apt-repository ppa:maarten-fonville/android-studio

sudo apt update

sudo apt install android-studio -y

# cmdtools
wget https://dl.google.com/android/repository/commandlinetools-linux-6609375_latest.zip ~/Android
unzip commandlinetools-linux-6609375_latest.zip && mv tools cmdline-tools
export ANDROID_HOME="/home/ubuntu/Android"
mkdir -p $ANDROID_HOME
export PATH="$ANDROID_HOME/cmdline-tools/bin/:$PATH"
export PATH="$ANDROID_HOME/emulator/:$PATH"
export PATH="$ANDROID_HOME/platform-tools/:$PATH"


# sdkmanager

sudo apt install sdkmanager



# netlify

npm install netlify-cli -g
netlify deploy --prod
netlify dev
netlify dev --edgeInspect
netlify dev --edgeInspect=127.0.0.1:9229
netlify dev --edgeInspectBrk
netlify dev --edgeInspectBrk=127.0.0.1:9229


# 除去零长字符

sed -i "s/$(echo -ne '\u200b')//g" input


sudo apt install opam


# risc-v

wget https://github.com/stnolting/riscv-gcc-prebuilt/releases/download/rv32i-4.0.0/riscv32-unknown-elf.gcc-12.1.0.tar.gz
sudo mkdir /opt/riscv

sudo tar -xzf riscv32-unknown-elf.gcc-12.1.0.tar.gz -C /opt/riscv/
export PATH=$PATH:/opt/riscv/bin


# cloudfare pages cli
npx wrangler pages deploy <directory>


# powershell http proxy
$env:HTTP_PROXY = "http://localhost:7890"
$env:HTTPS_PROXY = "http://localhost:7890"

# windows cmd proxy

set http_proxy=http://127.0.0.1:7890
set https_proxy=http://127.0.0.1:7890

```

![](https://cdn.glitch.global/c8d57c73-6044-4741-a71a-82aa74f41701/341a5aa7-9173-4257-bc96-b52001cd033b.image.png?v=1701158847856)
