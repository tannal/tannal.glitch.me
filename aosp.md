# potential mentors


# dev

repo start static-check art

./gradlew test

mm tests

repo branch
repo list

repo forall -c 'git diff --cached | $(git rev-parse --show-toplevel)/presubmit-hooks/pre-commit.py'

./gradlew lint

adb shell pm list packages | grep google

    在输出结果中，寻找类似以下的包名：
        com.google.android.gms (Google Play服务)
        com.google.android.gsf (Google服务框架)


    确定了包名后，使用以下命令获取APK路径：

adb shell pm path com.google.android.gsf

    得到路径后，使用以下命令提取APK：

pm path com.android.vending
pm path com.google.android.gms
pm path com.google.android.gsf

adb pull /path/to/base.apk


# working on

AOSP (Android Open Source Project) 的 bug 追踪和代码贡献流程相对复杂，但也很系统化。以下是主要的 bug tracer 和贡献代码的流程：

Bug Tracers:
a) Google Issue Tracker:

链接：https://issuetracker.google.com/
这是 Android 项目的主要 bug 追踪系统
你可以在这里报告和追踪 AOSP 相关的 bugs
b) Android Open Source Project Gerrit:

链接：https://android-review.googlesource.com/
虽然主要用于代码审查，但也可以用来追踪变更和相关讨论
贡献代码和测试的流程：
a) 准备工作：

阅读 AOSP 贡献指南：https://source.android.com/setup/contribute
签署贡献者许可协议 (CLA)
b) 设置开发环境：

按照 AOSP 文档设置您的开发环境
下载 AOSP 源代码
c) 创建修复或新功能：

在本地创建一个新的分支
进行代码修改
遵循 AOSP 编码规范
d) 测试您的更改：

运行相关的单元测试
如果是新功能，编写新的测试用例
在模拟器或实际设备上测试
e) 创建变更列表：

使用 repo upload 命令上传您的更改到 Gerrit
f) 代码审查：

在 Gerrit 上等待代码审查
根据审查者的反馈进行修改
g) 提交测试结果：

在 Gerrit 的变更列表中提供测试结果和日志
h) 持续集成：

您的代码会自动经过 AOSP 的 CI 系统测试
i) 最终合并：

一旦代码审查通过并且所有测试都成功，您的代码将被合并到主分支
找到 bugs 和贡献机会：
a) 查看 Issue Tracker:

搜索开放的 issues
关注特定的组件或标签
b) 订阅 AOSP 邮件列表:

https://groups.google.com/g/android-building
c) 参与 AOSP 项目讨论:

https://android.googlesource.com/
d) 关注 Android 开发者博客:

https://android-developers.googleblog.com/



# dev


root android phone setup adb server 

```bash
setprop service.adb.tcp.port 5555
stop adbd
start adbd
```

PATH=~/bin:$PATH
curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
chmod a+x ~/bin/repo
git config --global user.name "tannal"
git config --global user.email "tannal2409@gmail.com"


mkdir aosp

repo init -u https://android.googlesource.com/platform/manifest
repo sync

source build/envsetup.sh

lunch
make -j 22

cvd create


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
export ANDROID_NDK_HOME=$ANDROID_HOME/ndk/26.1.10909125/
export PATH=$PATH:$ANDROID_HOME/cmdline-tools/latest/bin:$ANDROID_HOME/platform-tools
adb -s 0.0.0.0:6520 shell
adb -s 10.90.26.12:5555 shell

```



build completed successfully (01:58:12 (hh:mm:ss))


