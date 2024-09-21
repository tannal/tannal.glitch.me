



# dev

PATH=~/bin:$PATH
curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
chmod a+x ~/bin/repo
git config --global user.name "tannal"
git config --global user.email "tannal2409@gmail.com"

repo init -u https://android.googlesource.com/platform/manifest

mkdir aosp

repo sync

source build/envsetup.sh

lunch
make -j 20

```bash

# 克隆仓库
git clone https://github.com/google/android-cuttlefish.git
cd android-cuttlefish

# 切换到 stable 分支
git checkout stable

# 编译生成 deb 包
tools/buildutils/build_packages.sh

# 安装 deb 包
sudo apt install ./cuttlefish-base_*.deb ./cuttlefish-user_*.deb

# 修改用户权限
sudo usermod -aG kvm,cvdnetwork,render $USER

# 重启系统
sudo reboot

# 在 AOSP 项目根目录执行
cvd create
cvd start --start_webrtc=true

export ANDROID_HOME=$HOME/Android/Sdk
export PATH=$PATH:$ANDROID_HOME/cmdline-tools/latest/bin:$ANDROID_HOME/platform-tools
adb connect localhost:6520

```



build completed successfully (01:58:12 (hh:mm:ss))


