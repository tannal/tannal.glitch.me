# 2024-1-2

![Alt text](./image-2.png)

vcpkg cmake

devtContainers

vscode profiles

sudo apt-get install nethogs

sudo nethogs

set(CMAKE_PREFIX_PATH "C:/Users/tannal/tannalwork/projects/vcpkg/installed/x64-windows/share")

clangd indexer sucks not only eating CPU but also I/O network bandwidth needs improvement i think

https://github.com/endless-sky

https://endless-sky.github.io/


sudo apt update
sudo apt install gh
gh auth login

export https_proxy=http://192.168.43.1:7890
export http_proxy=http://192.168.43.1:7890

git config --global http.sslverify false 
git config --global imap.sslverify false

.\vcpkg\bootstrap-vcpkg.bat

.\vcpkg integrate install

vcpkg list raylib
vcpkg search raylib
vcpkg install raylib

https://github.com/Uchiha-Peng/lavender-sailfish-ubuntutouch

git clone https://github.com/microsoft/vcpkg.git

Extended Reality (XR)

Wolvic browser

mi spot is faster than router tplink ax3000 no idea why

solving puzzles is like hide and seek

npm install -g firebase-tools

firebase login

firebase init

https://console.firebase.google.com/project/tannal/settings/general/web:YzU4MmU4MWEtNjIwNS00OTcxLTg2NDEtYjkwNzFkMjc3YTBi

https://pagespeed.web.dev/analysis/https-tannal-web-app-posts-inbox/to312vfwgu?form_factor=mobile

firebase deploy --only hosting

curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash

git clone https://www.github.com/tannal/tannal.web.app

sudo tcpdump -w /tmp/memcached.pcap -i any -A -vv 'port 11211'

sudo tcpdump -i any -AX -vv 'port 11211'

netstat -tuln

sudo apt install socat

socat - TCP-LISTEN:2222,crlf

socat - TCP:localhost:2222

sudo tcpdump -i enp5s0 tcp port 11211

sudo tcpdump -Xi enp5s0 port 2222

# 2024-1-1

https://github.com/nodejs/node/blob/5fb630597196cd5f3a8b7febdea3108fb89f067b/src/node.cc#L784

qemu-system-riscv64 -machine virt -bios none -kernel kernel/kernel -m 128M -smp 3 -nographic -drive file=fs.img,if=none,format=raw,id=x0 -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0

sudo apt install qemu-system-misc gcc-aarch64-linux-gnu



https://vis.csail.mit.edu/classes/6.859/

https://www.cs171.org/2023/resources/

```py

// us_gdp.csv
// https://datahub.io/core/gdp-us#resource-yea  r
date,level-current,level-chained,change-current,change-chained
1930,92.2,966.7,-16.0,-6.4
1931,77.4,904.8,-23.1,-12.9
1932,59.5,788.2,-4.0,-1.3
1933,57.2,778.3,16.9,10.8
1934,66.8,862.2,11.1,8.9
1935,74.3,939.0,14.3,12.9
1936,84.9,1060.5,9.6,5.1
1937,93.0,1114.6,-6.1,-3.3
1938,87.4,1077.7,7.0,8.0
1939,93.5,1163.6,10.1,8.8
1940,102.9,1266.1,25.7,17.7
1941,129.4,1490.3,28.3,18.9
1942,166.0,1771.8,22.4,17.0
1943,203.1,2073.7,10.5,8.0
1944,224.6,2239.4,1.6,-1.0
1945,228.2,2217.8,-0.2,-11.6
1946,227.8,1960.9,9.7,-1.1
1947,249.9,1939.4,9.9,4.1
1948,274.8,2020.0,-0.7,-0.5
1949,272.8,2008.9,10.0,8.7
1950,300.2,2184.0,15.7,8.1
1951,347.3,2360.0,5.9,4.1
1952,367.7,2456.1,6.0,4.7
1953,389.7,2571.4,0.4,-0.6
1954,391.1,2556.9,9.0,7.1
1955,426.2,2739.0,5.6,2.1
1956,450.1,2797.4,5.5,2.1
1957,474.9,2856.3,1.5,-0.7
1958,482.0,2835.3,8.4,6.9
1959,522.5,3031.0,4.0,2.6
1960,543.3,3108.7,3.7,2.6
1961,563.3,3188.1,7.4,6.1
1962,605.1,3383.1,5.5,4.4
1963,638.6,3530.4,7.4,5.8
1964,685.8,3734.0,8.4,6.5
1965,743.7,3976.7,9.6,6.6
1966,815.0,4238.9,5.7,2.7
1967,861.7,4355.2,9.4,4.9
1968,942.5,4569.0,8.2,3.1
1969,1019.9,4712.5,5.5,0.2
1970,1075.9,4722.0,8.5,3.3
1971,1167.8,4877.6,9.8,5.2
1972,1282.4,5134.3,11.4,5.6
1973,1428.5,5424.1,8.4,-0.5
1974,1548.8,5396.0,9.0,-0.2
1975,1688.9,5385.4,11.2,5.4
1976,1877.6,5675.4,11.1,4.6
1977,2086.0,5937.0,13.0,5.6
1978,2356.6,6267.2,11.7,3.2
1979,2632.1,6466.2,8.8,-0.2
1980,2862.5,6450.4,12.2,2.6
1981,3211.0,6617.7,4.2,-1.9
1982,3345.0,6491.3,8.8,4.6
1983,3638.1,6792.0,11.1,7.3
1984,4040.7,7285.0,7.6,4.2
1985,4346.7,7593.8,5.6,3.5
1986,4590.2,7860.5,6.1,3.5
1987,4870.2,8132.6,7.9,4.2
1988,5252.6,8474.5,7.7,3.7
1989,5657.7,8786.4,5.7,1.9
1990,5979.6,8955.0,3.3,-0.1
1991,6174.0,8948.4,5.9,3.6
1992,6539.3,9266.6,5.2,2.7
1993,6878.7,9521.0,6.3,4.0
1994,7308.8,9905.4,4.9,2.7
1995,7664.1,10174.8,5.7,3.8
1996,8100.2,10561.0,6.3,4.5
1997,8608.5,11034.9,5.6,4.5
1998,9089.2,11525.9,6.3,4.7
1999,9660.6,12065.9,6.5,4.1
2000,10284.8,12559.7,3.3,1.0
2001,10621.8,12682.2,3.3,1.8
2002,10977.5,12908.8,4.9,2.8
2003,11510.7,13271.1,6.6,3.8
2004,12274.9,13773.5,6.7,3.3
2005,13093.7,14234.2,5.8,2.7
2006,13855.9,14613.8,4.5,1.8
2007,14477.6,14873.7,1.7,-0.3
2008,14718.6,14830.4,-2.0,-2.8
2009,14418.7,14418.7,3.8,2.5
2010,14964.4,14783.8,3.7,1.6
2011,15517.9,15020.6,4.1,2.2
2012,16155.3,15354.6,3.3,1.7
2013,16691.5,15612.2,4.4,2.6
2014,17427.6,16013.3,4.0,2.9
2015,18120.7,16471.5,2.8,1.5



// us_gdp.py
import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('us_gdp.csv')

# Extract the required columns
years = data['date']
current_levels = data['level-current']
chained_levels = data['level-chained']
change_current = data['change-current']
change_chained = data['change-chained']

# Create a line plot for current and chained levels
plt.plot(years, current_levels, label='Current Levels')
plt.plot(years, chained_levels, label='Chained Levels')

plt.xlabel('Year')
plt.ylabel('Level')
plt.title('Current and Chained Levels Over Time')
plt.legend()

plt.show()

# Create a bar plot for changes in current and chained levels
plt.bar(years, change_current, label='Change Current')
plt.bar(years, change_chained, label='Change Chained')

plt.xlabel('Year')
plt.ylabel('Change')
plt.title('Changes in Current and Chained Levels Over Time')
plt.legend()

plt.show()

```

https://github.com/jsdom/jsdom/blob/b7683ed68ebe259cd2c68e5faf12d484a785f45f/lib/jsdom/living/helpers/create-element.js#L168

pip install pandas matplotlib -i https://pypi.tuna.tsinghua.edu.cn/simple

nvm list available

winget install -e --id CoreyButler.NVMforWindows

nvm install 20.10.0

corepack enable

nvm use 20.10.0


# 2023-12-31

net user

net Administrator 123456789

按F1键，进入bios，把改Intel VMD Comtroller为disabled

sudo fdisk -l

sudo fdisk /dev/sda

sudo apt-get -y install m4
sudo apt install mesa-utils
DRI_PRIME=1 glxinfo | grep "OpenGL renderer" 

```bash

https://storage.googleapis.com/flutter_infra_release/releases/stable/windows/flutter_windows_3.16.5-stable.zip

android studio
cmdtools


flutter doctor --android-licenses


```

注意: The Chocolatey CLI MSI is intended for installation only! If upgrading from 5.x of Licensed Extension, or 1.x of other Chocolatey products, see the upgrade guide at https://ch0.co/upv2v6 before continuing. Otherwise, run `choco upgrade chocolatey`.

https://github.com/flutter/flutter/issues/57674

```bash

$env:HTTP_PROXY = "http://192.168.43.1:7890"
$env:HTTPS_PROXY = "http://192.168.43.1:7890"

set http_proxy=http://192.168.43.1:7890
set https_proxy=http://192.168.43.1:7890

$progressPreference = 'silentlyContinue'
Write-Information "Downloading WinGet and its dependencies..."
Invoke-WebRequest -Uri https://aka.ms/getwinget -OutFile Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle
Invoke-WebRequest -Uri https://aka.ms/Microsoft.VCLibs.x64.14.00.Desktop.appx -OutFile Microsoft.VCLibs.x64.14.00.Desktop.appx
Invoke-WebRequest -Uri https://github.com/microsoft/microsoft-ui-xaml/releases/download/v2.7.3/Microsoft.UI.Xaml.2.7.x64.appx -OutFile Microsoft.UI.Xaml.2.7.x64.appx
Add-AppxPackage Microsoft.VCLibs.x64.14.00.Desktop.appx
Add-AppxPackage Microsoft.UI.Xaml.2.7.x64.appx
Add-AppxPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle

winget install -e --id Google.Chrome
winget install --id Git.Git -e --source winget
# winget install -e --id Corel.WinZip
# winget uninstall -e --id Corel.WinZip
winget install -e --id RARLab.WinRAR
winget install -e --id Unity.Unity.2022
winget install -e --id Kitware.CMake
winget install -e --id Python.Python.3.10
winget install ChristianSchenk.MiKTeX
winget install -e --id Logitech.OptionsPlus
winget install --id chocolatey.chocolatey
winget install -e --id Microsoft.VisualStudioCode
winget install -e --id Microsoft.vcpkg
winget install Microsoft.OpenJDK.21

winget install -e --id Unity.UnityHub

winget install dart-sdk

winget install -e --id GoLang.Go.1.20

latex-utilities
latex-workshop

https://datsuka-qwerty.hatenablog.com/entry/latex/windows_install

https://tug.org/texlive/windows.html#install


```

# 2023-12-30

amdgpu-install -y --accept-eula --opencl=rocr --opengl=mesa --vulkan=pro

sudo update-grub2

shutdown -h 0

// main.cpp
#include <iostream>
#include <uv.h>
#include <v8.h>

void on_uv_walk(uv_handle_t* handle, void* arg) {
    if (!uv_is_closing(handle)) {
        uv_close(handle, nullptr);
    }
}

void on_uv_close(uv_handle_t* handle) {
    if (handle->data) {
        delete static_cast<v8::Isolate*>(handle->data);
        handle->data = nullptr;
    }
}

void on_uv_read(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
    if (nread > 0) {
        std::cout << "Received data: " << std::string(buf->base, nread) << std::endl;
    }
    if (nread < 0) {
        if (nread != UV_EOF) {
            std::cerr << "Read error: " << uv_strerror(nread) << std::endl;
        }
        uv_close(reinterpret_cast<uv_handle_t*>(stream), nullptr);
    }
    delete[] buf->base;
}

void on_uv_connection(uv_stream_t* server, int status) {
    if (status < 0) {
        std::cerr << "Connection error: " << uv_strerror(status) << std::endl;
        return;
    }

    uv_tcp_t* client = new uv_tcp_t;
    uv_tcp_init(uv_default_loop(), client);

    if (uv_accept(server, reinterpret_cast<uv_stream_t*>(client)) == 0) {
        uv_read_start(reinterpret_cast<uv_stream_t*>(client),
                      [](uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
                          *buf = uv_buf_init(new char[suggested_size], suggested_size);
                      },
                      on_uv_read);
    } else {
        uv_close(reinterpret_cast<uv_handle_t*>(client), nullptr);
        delete client;
    }
}

int main() {
    v8::V8::InitializeICUDefaultLocation("");
    v8::V8::InitializeExternalStartupData("");
    v8::V8::InitializePlatform(v8::platform::CreateDefaultPlatform());
    v8::V8::Initialize();

    v8::Isolate::CreateParams create_params;
    v8::Isolate* isolate = v8::Isolate::New(create_params);

    uv_tcp_t server;
    uv_tcp_init(uv_default_loop(), &server);

    sockaddr_in bind_addr;
    uv_ip4_addr("0.0.0.0", 3000, &bind_addr);
    uv_tcp_bind(&server, reinterpret_cast<const sockaddr*>(&bind_addr), 0);

    int res = uv_listen(reinterpret_cast<uv_stream_t*>(&server), 128, on_uv_connection);
    if (res < 0) {
        std::cerr << "Listen error: " << uv_strerror(res) << std::endl;
        return 1;
    }

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_walk(uv_default_loop(), on_uv_walk, nullptr);
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
    uv_loop_close(uv_default_loop());

    isolate->Dispose();
    v8::V8::Dispose();
    v8::V8::ShutdownPlatform();

    return 0;
}


include/v8.h

servo surfman webrender 

STM32MP1 platform boot

https://github.com/rust-lang/rust/blob/8d76d076665f862ec9619f2de68d6d9ca1db4601/library/core/src/option.rs#L570

2 copy 256kb

```bash

[[example]]
name = "example1"
path = "src/example1.rs"

```



```bash

git clone https://git.yoctoproject.org/poky -b dunfell

git clone -b dunfell \
    git://git.yoctoproject.org/poky.git

git clone -b dunfell \
    git://git.yoctoproject.org/meta-raspberrypi.git

git clone -b dunfell \
    git://git.openembedded.org/meta-openembedded

source poky/oe-init-build-env

```

telnet 127.0.0.1 11211

stats

^] ^D exit telnet

```bash

// TODO tcpdump wireshark 
set lisi 0 0  3    3       #插入一个数据
aaa              #插入的数据为aaa
STORED             #返回“STORED”则表示插入成功
get lisi                  #查询插入的数据
VALUE lisi 0 3          
aaa
END
set lisi 0 0 4          #修改“lisi”这个key的值为bbbb
bbbb
STORED
get lisi          #再次查看，确定更改成功
VALUE lisi 0 4
bbbb

```


```bash

sudo apt-get install build-essential kmod linux-headers-`uname -r`


obj-m += hello.o

.PHONY: build clean load unload

build:
	make -C /lib/modules/$(shell uname -r)/build modules M=$(shell pwd)

clean:
	make -C /lib/modules/$(shell uname -r)/build clean M=$(shell pwd)

load:
	sudo insmod hello.ko
unload:
	-sudo rmmod hello


#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int hello_init(void)
{
    printk(KERN_ALERT "Hello, world\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

```

singer keyboard guitar bass drummer

You need to fight with environment

It sucks, but everyone suffer from it


&self no mut

https://github.com/rust-lang/rust/blob/8d76d076665f862ec9619f2de68d6d9ca1db4601/library/core/src/option.rs#L570

https://llvm.org/OpenProjects.html#gsoc23

https://www.outreachy.org/

https://mentorship.lfx.linuxfoundation.org/#projects_accepting

https://www.igalia.com/coding-experience/

deno

servo

v8 llvm-project node linux



```bash

```

```bash

git clone https://github.com/MarybethGasman/tiktok.git

mvnw

chmod +x mvnw

./mvnw install
./mvnw deploy

```


```bash

git clone https://github.com/redis/redis.git
cd redis/
time make -j20

real	0m38.028s
user	2m28.108s
sys	0m17.239s

git clone https://github.com/memcached/memcached.git

sudo apt-get install autotools-dev automake libevent-dev

After that you can build memcached binary using automake

cd memcached
./autogen.sh
./configure
time make -j20

./memcached

real	0m1.496s
user	0m18.721s
sys	0m1.818s

make test

```

```bash

TODO

kubectl get node
E1230 10:07:55.915576   17811 memcache.go:265] couldn't get current server API group list: Get "https://192.168.49.2:8443/api?timeout=32s": context deadline exceeded - error from a previous attempt: EOF
E1230 10:08:27.917669   17811 memcache.go:265] couldn't get current server API group list: Get "https://192.168.49.2:8443/api?timeout=32s": context deadline exceeded - error from a previous attempt: EOF

sudo curl -fsSL https://get.docker.com |bash

sudo groupadd docker

sudo usermod -aG docker $USER

docker run hello-world

# k8s

curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl"

chmod +x kubectl
mkdir -p ~/.local/bin
mv ./kubectl ~/.local/bin/kubectl

# minikube

curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
sudo install minikube-linux-amd64 /usr/local/bin/minikube

minikube start --driver docker

minikube status

kubectl config view
minikube start

kubectl get node

oc get pods

kubctl get pods

```

```bash
sudo apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r`

```

Realtime process 0-99

Normal process 100-139

Nice -20-19

PR_new = PR_old + Nice

Priority

python fabric


# 2023-12-29


https://www.collabora.com/careers.html

```bash

virtualenv --version

virtualenv mypython

source mypython/bin/activate

deactivate

pip freeze

```

buildroot openwrt yocto

BuildRoot OpenWrt Yocto

LLVM IR 

instructions

basic block can have a label consists of list of instructions

last is terminator

```llvm

define i32 @foo(i32 %a) {
  entry:
    %sum = add i32 %a, 10
    %cond = icmp eq i32 %sum, 99
    br i1 %cond, label %bb1, label %bb2
  bb1:
    call void @use(i32 %sum, i32 %sum)
    ret i32 %sum
  bb2:
    ret i32 0
}

```

- opcode

%sum = add i32 %a, 10

call void @use(i32 %sum)

buffer table & buffer descripter & buffer pool

every other line 每隔一行

String &str

vec! HashSet HashMap

{:?} debug print

.iter().count().sum().filter().for_each().collect()

enumerate skip take

push based pull based iterator & generator & iter() & collect()

push no collect

pull has collect manually



### TypeScript setup

This should be easy enough. we will just use ts-node (feel free to use swc or
whatever you want)

```bash
npm init -y
npm install ts-node typescript @types/node
npx tsc --init
```

<br />

#### **Edit your tsconfig.json**

We want things to be strict, so don't forget to turn on all the things.

Here are my preferred settings

```json
"strict": true,
"noImplicitAny": true,
"strictNullChecks": true,
"strictFunctionTypes": true,
"strictBindCallApply": true,
"strictPropertyInitialization": true,
"noImplicitThis": true,
"useUnknownInCatchVariables": true,
"alwaysStrict": true,
"noUnusedLocals": true,
"noUnusedParameters": true,
"exactOptionalPropertyTypes": true,
"noImplicitReturns": true,
"noFallthroughCasesInSwitch": true,
"noUncheckedIndexedAccess": true,
"noImplicitOverride": true,
"noPropertyAccessFromIndexSignature": true,
```

web intent

React/Next/Typescript Flux Redux BootStrap, ANT Design, Tailwind Babel, Webpack, NPM

Ideally worked on Web Applications like SaaS, doing React front-end components.

React, GitHub, Java, Gradle, Groovy, MySQL, Snowflake, Docker, AWS, Slack, and JIRA

NodeJS NestJS MySQL MongoDB ReactJS NextJS Bootstrap/Material REST APIs Docker TDD CI/CD JEST/ Mocha, Jenkins, Selenium Stripe, RabbitMQ, Redis, AWS Elasticsearch

Use of Docker in local and production environments

Python, Java, or C++ TensorFlow, Caffe, PyTorch, Keras, Scikit Learn, and Theano

Python, Ruby on Rails, React.js or React Native

Python, Django, React, AWS/OpenStack, MySQL, MongoDB, PostgreSQL, Debian Ubuntu Debian/Ubuntu servers, Terraform, Vault, Packer, Prometheus, ELK, Docker RabbitMQ, Redis & Elasticsearch IOS & Android

NodeJS/Rails/django/go/elixir/java/flask/laravel

Java, Kotlin and the Android SDK, Android Studio, Material Spec

.NET, C#, SQL Server, IIS

figma HTML CSS Next.js, Apollo GraphQL, React

AWS, Azure, Google Cloud

MySQL, PostgreSQL, MongoDB

JavaScript and TypeScript

Git Node.js Docker, Kubernetes

Four or more years of experience in two or more of the following skill sets:
Ruby (Rails)
Go and related tooling
JavaScript (React, TypeScript, Relay)
MySQL and database management
NodeJS development
Design and build REST and/or GraphQL APIs
Experience with CI/CD tools and automated pipelines
Preferred Qualifications
Experience with Git, GitHub , Actions & workflow platform for version control and collaborative development.
Internals of web development frameworks, tools, and client performance optimization.
Building developer tools and pipelines that streamline and automate software lifecycle, including development, testing and releasing, with focus on speed, reliability and scalability.
Excellent written and verbal communication via async collaboration, documentation, and visibility of work
Hands-on experience with distributed systems at global scale.
Experience working with a remote, distributed team.
Familiarity with SQL, Kusto Query Language, general database knowledge, Kubernetes, and/or cloud-native concepts
Passionate about fostering effective Engineering practices and processes and contribute to open source software, engage with maintainers, and actively participate in community curation.
Compensation Range: USD $104,400.00 - USD $276,900.00 /Yr.

In addition, certain roles also have the opportunity to earn sales incentives based on revenue or utilization, depending on the terms of the plan and the employee's role.


A bachelor/master in Informatics (or related);
Proven professional experience in OO programming and web development;
Attentive to details, delivering quality code which is maintainable, efficient and reliable;
Experienced in MySQL, or other relational databases;
Familiar with version-control and automated testing tools;
Used to work in JSON/XML/CSV formats and have no issues with HTML/CSS;
Experienced in Ruby or Ruby and Rails (the right candidate will be considered without this experience);
Good in English communication and teamwork.

1+ years of experience with a Javascript framework (VueJS, Alpine)

MySQL
Modern PHP: composer, PHPUnit, Laravel
Javascript: VueJS, Alpine JS, Webpack, NPM, Node
CSS, Tailwind
Familiarity working with Bash/Shell, Git, Docker, Kubernetes, testing frameworks

3+ years of software development experience
Strong computer science fundamentals and programing skills
Experience with IPASS platforms such as Mulesoft, Boomi and Workato
Experience managing software development in an agile environment with CI/CD and automated testing – CirlceCI, Jenkins, CodePipeline, ElasticBeanstalk, GitHub Actions
Proficiency in programming languages JavaScript/TypeScript, Python, SQL
Working knowledge of React and REST API’s
Strong experience developing large-scale modern architectures in AWS
Strong knowledge on RDMS and NoSQL database technologies in AWS
Experience in data strategy – warehousing, ELT – Snowflake, RedShift, BigQuery

Required

Bachelor's degree and less than 2 years related experience.
Knowledge of software QA / test methodologies and process.
Familiarity with Java, Maven and Selenium.
Familiarity with issue/bug tracking systems, such as JIRA.
Excellent oral and written communication skills.
Preferred

Familiarity with one or more of the followings: Javascript, DOM HTML and React Native (or AngularJS).
Knowledge of SQL, Shell scripting, Cloud platforms.
Knowledge of API testing.
Knowledge of working in agile product teams (Scrum and Kanban)

```bash
No build type specified so assuming `--dev`.
Caught signal 11 in thread "main"
   0: servo::backtrace::print
             at /home/tannal/tannalwork/projects/servo/ports/servoshell/backtrace.rs:18:5
   1: servo::crash_handler::install::handler
             at /home/tannal/tannalwork/projects/servo/ports/servoshell/crash_handler.rs:38:21
   2: <unknown>
   3: wl_list_insert
   4: wl_proxy_create_wrapper
   5: <unknown>
   6: <unknown>
   7: <unknown>
   8: surfman::egl::Egl::Initialize
             at /home/tannal/tannalwork/projects/servo/target/debug/build/surfman-368674826c3bff34/out/egl_bindings.rs:471:156
   9: surfman::platform::unix::wayland::connection::Connection::from_wayland_display::{{closure}}
             at /home/tannal/.cargo/registry/src/index.crates.io-6f17d22bba15001f/surfman-0.8.0/src/platform/unix/wayland/connection.rs:140:22
  10: std::thread::local::LocalKey<T>::try_with
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/thread/local.rs:270:16
  11: std::thread::local::LocalKey<T>::with
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/thread/local.rs:246:9
  12: surfman::platform::unix::wayland::connection::Connection::from_wayland_display
             at /home/tannal/.cargo/registry/src/index.crates.io-6f17d22bba15001f/surfman-0.8.0/src/platform/unix/wayland/connection.rs:128:9
  13: surfman::platform::unix::wayland::connection::Connection::from_raw_display_handle
             at /home/tannal/.cargo/registry/src/index.crates.io-6f17d22bba15001f/surfman-0.8.0/src/platform/unix/wayland/connection.rs:189:13
  14: surfman::platform::unix::wayland::implementation::connection::<impl surfman::connection::Connection for surfman::platform::unix::wayland::connection::Connection>::from_raw_display_handle
             at /home/tannal/.cargo/registry/src/index.crates.io-6f17d22bba15001f/surfman-0.8.0/src/platform/unix/wayland/../../../implementation/connection.rs:87:9
  15: surfman::platform::generic::multi::connection::Connection<Def,Alt>::from_raw_display_handle
             at /home/tannal/.cargo/registry/src/index.crates.io-6f17d22bba15001f/surfman-0.8.0/src/platform/generic/multi/connection.rs:199:15
  16: <surfman::platform::generic::multi::connection::Connection<Def,Alt> as surfman::connection::Connection>::from_raw_display_handle
             at /home/tannal/.cargo/registry/src/index.crates.io-6f17d22bba15001f/surfman-0.8.0/src/platform/generic/multi/connection.rs:329:9
  17: surfman::platform::generic::multi::connection::Connection<Def,Alt>::from_raw_display_handle
             at /home/tannal/.cargo/registry/src/index.crates.io-6f17d22bba15001f/surfman-0.8.0/src/platform/generic/multi/connection.rs:199:15
  18: servo::headed_window::Window::new
             at /home/tannal/tannalwork/projects/servo/ports/servoshell/headed_window.rs:129:26
  19: servo::app::App::run
             at /home/tannal/tannalwork/projects/servo/ports/servoshell/app.rs:75:21
  20: servo::main2::main
             at /home/tannal/tannalwork/projects/servo/ports/servoshell/main2.rs:139:5
  21: servo::main
             at /home/tannal/tannalwork/projects/servo/ports/servoshell/main.rs:62:13
  22: core::ops::function::FnOnce::call_once
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/core/src/ops/function.rs:250:5
  23: std::sys_common::backtrace::__rust_begin_short_backtrace
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/sys_common/backtrace.rs:154:18
  24: std::rt::lang_start::{{closure}}
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/rt.rs:166:18
  25: core::ops::function::impls::<impl core::ops::function::FnOnce<A> for &F>::call_once
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/core/src/ops/function.rs:284:13
      std::panicking::try::do_call
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/panicking.rs:504:40
      std::panicking::try
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/panicking.rs:468:19
      std::panic::catch_unwind
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/panic.rs:142:14
      std::rt::lang_start_internal::{{closure}}
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/rt.rs:148:48
      std::panicking::try::do_call
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/panicking.rs:504:40
      std::panicking::try
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/panicking.rs:468:19
      std::panic::catch_unwind
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/panic.rs:142:14
      std::rt::lang_start_internal
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/rt.rs:148:20
  26: std::rt::lang_start
             at /rustc/a28077b28a02b92985b3a3faecf92813155f1ea1/library/std/src/rt.rs:165:17
  27: main
  28: __libc_start_call_main
             at ./csu/../sysdeps/nptl/libc_start_call_main.h:58:16
  29: __libc_start_main_impl
             at ./csu/../csu/libc-start.c:392:3
  30: _start
Servo was terminated by signal 11

```

12.23 - 1.6 chrismas

discussion & docs & code review & fix bugs

impact > learning

most time in particip

Jamstack Story book React Style guidist React cosmos

Full Stack

less time in side project

wasm learning a lof of things from llvm

# 2023-12-28


```bash

// CMake examples project every single file is a executable

cmake_minimum_required(VERSION 3.0)

project(MyProject)

set(CMAKE_CXX_STANDARD 11)

file(GLOB EXAMPLE_SOURCES "*.cc")

foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
endforeach()

```

Convenience wrapper for compiling V8 with gn/ninja and running tests.
Sets up build output directories if they don't exist.
Produces simulator builds for non-Intel target architectures.
Uses Goma by default if it is detected (at output directory setup time).
Expects to be run from the root of a V8 checkout.

Usage:
    gm.py [<arch>].[<mode>[-<suffix>]].[<target>] [testname...] [--flag]

All arguments are optional. Most combinations should work, e.g.:
    gm.py ia32.debug x64.release x64.release-my-custom-opts d8
    gm.py android_arm.release.check --progress=verbose
    gm.py x64 mjsunit/foo cctest/test-bar/*

For a less automated experience, pass an existing output directory (which
must contain an existing args.gn), e.g.:
    gm.py out/foo unittests

Flags are passed unchanged to the test runner. They must start with -- and must
not contain spaces.

<arch> can be any of: ia32 x64 arm arm64 mips64el ppc ppc64 riscv32 riscv64 s390 s390x android_arm android_arm64 loong64 fuchsia_x64 fuchsia_arm64
<mode> can be any of: release rel debug dbg optdebug opt
<target> can be any of:
 - d8, cctest, v8_unittests, v8_fuzzers, wasm_api_tests, wee8, mkgrokdump, generate-bytecode-expectations, inspector-test, bigint_shell, wami (build respective binary)
 - all (build all binaries)
 - tests (build test binaries)
 - check (build test binaries, run most tests)
 - checkall (build all binaries, run more tests)

3 year experience of software 

postmaster dump

associate is automatic

logical -> imagination

Learn -> doing creating making impact

one way -> two way

linear -> exponential

general vague -> specilized highly needed

write perfect code -> make things happen quickly



# 2023-12-26

do things

rust From trait

https://github.com/rust-lang/rust/blob/f6456285ddca7db0ffc663d02d9ecaf22d1f0d82/library/core/src/convert/mod.rs#L579C1-L585C2

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/mm/fault.c#L1239

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/mm/memory-failure.c#L525

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/include/uapi/asm/signal.h#L4

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/include/asm/pgtable_types.h#L4

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/include/asm/pgtable.h

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/mm/pgprot.c#L5

https://github.com/torvalds/linux/blob/fbafc3e621c3f4ded43720fdb1d6ce1728ec664e/arch/x86/mm/pgtable.c#L563

64bit 

2**40 TB

64 52 48 32 

Intel Core i7/Linux

tag index offset

page table entry -> pte -> unsigned long 

physical page number

63 62 52 51 12 11 9 8 7 6 5 4 3 2 1 0



# 2023-12-25

Buffer Management

https://github.com/postgres/postgres/tree/0a93f803f45f45f39473e2c61923c4b4777bc8a8/src/backend/storage/buffer

# 2023-12-24

![Toit language for IOT](./image-1.png)

```bash

cmake_minimum_required(VERSION 2.8.9)
project (myproject)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "*.cc")
file(GLOB LIBRARIES "lib/*.a")
message("LIBRARIES = ${LIBRARIES}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(myproject ${SOURCES})
target_link_libraries(myproject ${LIBRARIES})  


cmake -S . -B build
cmake --build build

ln -s build/compile_commands.json compile_commands.json 

```

# 2023-12-23


```bash

https://github.com/google/leveldb.git

mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && time cmake --build .

real    0m44.458s
user    0m40.343s
sys     0m4.054s

```

Eric Christopher

Johannes Dooerfert

Intro LLVM

llvm-project
llvm-project/clang
llvm-project/llvm
llvm-project/{lld, lldb, ...}

include/ lib/ tests/ utils/

clang AST

LLVM IR

Selection DAG

LLVM MIR

Machine code

clang opt llc llc llc Machine Code 


```bash
wabt
sudo make install
ninja -C out/clang/Debug/ install
ninja: Entering directory `out/clang/Debug/'
[25/26] Install the project...
-- Install configuration: "Debug"
-- Installing: /usr/local/lib/libwabt.a
-- Up-to-date: /usr/local/include
-- Installing: /usr/local/include/wabt
-- Installing: /usr/local/include/wabt/apply-names.h
-- Installing: /usr/local/include/wabt/generate-names.h
-- Installing: /usr/local/include/wabt/tracing.h
-- Installing: /usr/local/include/wabt/decompiler-ast.h
-- Installing: /usr/local/include/wabt/validator.h
-- Installing: /usr/local/include/wabt/resolve-names.h
-- Installing: /usr/local/include/wabt/expr-visitor.h
-- Installing: /usr/local/include/wabt/binary-writer.h
-- Installing: /usr/local/include/wabt/ir-util.h
-- Installing: /usr/local/include/wabt/lexer-source.h
-- Installing: /usr/local/include/wabt/binary-reader-ir.h
-- Installing: /usr/local/include/wabt/opcode.def
-- Installing: /usr/local/include/wabt/result.h
-- Installing: /usr/local/include/wabt/base-types.h
-- Installing: /usr/local/include/wabt/token.h
-- Installing: /usr/local/include/wabt/feature.h
-- Installing: /usr/local/include/wabt/cast.h
-- Installing: /usr/local/include/wabt/shared-validator.h
-- Installing: /usr/local/include/wabt/sha256.h
-- Installing: /usr/local/include/wabt/leb128.h
-- Installing: /usr/local/include/wabt/string-format.h
-- Installing: /usr/local/include/wabt/filenames.h
-- Installing: /usr/local/include/wabt/interp
-- Installing: /usr/local/include/wabt/interp/binary-reader-interp.h
-- Installing: /usr/local/include/wabt/interp/interp-wasi.h
-- Installing: /usr/local/include/wabt/interp/istream.h
-- Installing: /usr/local/include/wabt/interp/interp-inl.h
-- Installing: /usr/local/include/wabt/interp/interp-util.h
-- Installing: /usr/local/include/wabt/interp/interp.h
-- Installing: /usr/local/include/wabt/interp/interp-math.h
-- Installing: /usr/local/include/wabt/decompiler-ls.h
-- Installing: /usr/local/include/wabt/binary-reader-logging.h
-- Installing: /usr/local/include/wabt/c-writer.h
-- Installing: /usr/local/include/wabt/binary-reader-nop.h
-- Installing: /usr/local/include/wabt/type.h
-- Installing: /usr/local/include/wabt/utf8.h
-- Installing: /usr/local/include/wabt/common.h
-- Installing: /usr/local/include/wabt/range.h
-- Installing: /usr/local/include/wabt/error.h
-- Installing: /usr/local/include/wabt/option-parser.h
-- Installing: /usr/local/include/wabt/ir.h
-- Installing: /usr/local/include/wabt/token.def
-- Installing: /usr/local/include/wabt/opcode-code-table.h
-- Installing: /usr/local/include/wabt/string-util.h
-- Installing: /usr/local/include/wabt/lexer-source-line-finder.h
-- Installing: /usr/local/include/wabt/decompiler.h
-- Installing: /usr/local/include/wabt/opcode.h
-- Installing: /usr/local/include/wabt/binary-reader-stats.h
-- Installing: /usr/local/include/wabt/literal.h
-- Installing: /usr/local/include/wabt/wast-lexer.h
-- Installing: /usr/local/include/wabt/binary-writer-spec.h
-- Installing: /usr/local/include/wabt/binary-reader-objdump.h
-- Installing: /usr/local/include/wabt/wast-parser.h
-- Installing: /usr/local/include/wabt/binary-reader.h
-- Installing: /usr/local/include/wabt/feature.def
-- Installing: /usr/local/include/wabt/type-checker.h
-- Installing: /usr/local/include/wabt/error-formatter.h
-- Installing: /usr/local/include/wabt/stream.h
-- Installing: /usr/local/include/wabt/color.h
-- Installing: /usr/local/include/wabt/wat-writer.h
-- Installing: /usr/local/include/wabt/intrusive-list.h
-- Installing: /usr/local/include/wabt/binding-hash.h
-- Installing: /usr/local/include/wabt/decompiler-naming.h
-- Installing: /usr/local/include/wabt/binary.h
-- Up-to-date: /usr/local/include
-- Up-to-date: /usr/local/include/wabt
-- Installing: /usr/local/include/wabt/config.h
-- Installing: /usr/local/lib/libwasm-rt-impl.a
-- Installing: /usr/local/include/wasm-rt.h
-- Installing: /usr/local/include/wasm-rt-exceptions.h
-- Installing: /usr/local/share/wabt/wasm2c/wasm-rt-impl.h
-- Installing: /usr/local/share/wabt/wasm2c/wasm-rt-impl.c
-- Installing: /usr/local/share/wabt/wasm2c/wasm-rt-exceptions-impl.c
-- Installing: /usr/local/bin/wat2wasm
-- Installing: /usr/local/bin/wast2json
-- Installing: /usr/local/bin/wasm2wat
-- Installing: /usr/local/bin/wasm2c
-- Installing: /usr/local/bin/wasm-stats
-- Installing: /usr/local/bin/wasm-objdump
-- Installing: /usr/local/bin/wasm-interp
-- Installing: /usr/local/bin/spectest-interp
-- Installing: /usr/local/bin/wat-desugar
-- Installing: /usr/local/bin/wasm-validate
-- Installing: /usr/local/bin/wasm-strip
-- Installing: /usr/local/bin/wasm-decompile
-- Installing: /usr/local/share/man/man1
-- Installing: /usr/local/share/man/man1/wat-desugar.1
-- Installing: /usr/local/share/man/man1/wasm-validate.1
-- Installing: /usr/local/share/man/man1/wasm-interp.1
-- Installing: /usr/local/share/man/man1/wasm-stats.1
-- Installing: /usr/local/share/man/man1/spectest-interp.1
-- Installing: /usr/local/share/man/man1/wast2json.1
-- Installing: /usr/local/share/man/man1/wat2wasm.1
-- Installing: /usr/local/share/man/man1/wasm-strip.1
-- Installing: /usr/local/share/man/man1/wasm-decompile.1
-- Installing: /usr/local/share/man/man1/wasm2wat.1
-- Installing: /usr/local/share/man/man1/wasm-objdump.1
-- Installing: /usr/local/share/man/man1/wasm2c.1
-- Installing: /usr/local/lib/cmake/wabt/wabt-targets.cmake
-- Installing: /usr/local/lib/cmake/wabt/wabt-targets-debug.cmake
-- Installing: /usr/local/lib/cmake/wabt/wabt-config.cmake
-- Installing: /usr/local/lib/cmake/wabt/wabt-config-version.cmake

```
vmrss

# 2023-12-21



```bash

sudo vim /etc/default/grub

amdgpu.backlight=0

sudo update-grub

sudo reboot

```

servo docs need improvement

```bash
pip install virtualenv

# sudo apt install libc++-dev libc++abi-dev
# sudo apt install libc++-14-dev libc++abi-14-dev
# sudo ln -s /usr/lib/x86_64-linux-gnu/libstdc++.so.6 /usr/lib/x86_64-linux-gnu/libstdc++.so
# sudo ln -s /usr/bin/c++ /usr/bin/clang++-libc++


sudo apt install libstdc++-12-dev

```

remote & open source

# 2023-12-20

211 5%
people beijing 5%

1.412 billion

1412 000 000 * 5% = 70600000

6000 000 000 * 5% = 300000000

Logical Block Address


UART to USB converter

raspi3b

FAT NTFS 

ELF

https://github.com/torvalds/linux/blob/55cb5f43689d7a9ea5bf35ef050f12334f197347/fs/binfmt_elf.c#L843

https://github.com/torvalds/linux/blob/55cb5f43689d7a9ea5bf35ef050f12334f197347/fs/binfmt_elf.c#L855

# 2023-12-19

x86 is dead, long live arm (for me)

services on open source software (company idea)

what do we need to create bea drawings?
- line arrows text

Programming & CSAPP

Data Stucture & Alorithms & Computing theory (programming & computing)
OS DB Emebeded Distbuted PL VM APP Internet Systems (systems)

AI

Engineering & Research


# 2023-12-18

Username: pi
Password: raspberry

tar xvJf disk.xz
qemu raspi3b

https://farabimahmud.github.io/emulate-raspberry-pi3-in-qemu/

```bash
sudo apt install snapd
sudo snap install rpi-imager
sudo apt install rpi-imager

```

modern processor (many cores)

pipeline
TLB cache
branch prediction

storage systems (register L1 L2 L3 memory disk)

concurrency & paralleism (pros & cons)

function call?

calling convention

may push stack

jump 

switch vs if-else ?

bus transport blocks of words (32bit or 64bit)
cpu register size is a word

ISA vs Micro Architecture

OS/360 Multics Honeywell

An example of getpeername security problem in Freebsd

copy_from_kernel 

If a user space program see something it shouldn't see, then it is a security problem.

not matter if it's been used to "attack"

# 2023-12-17

micro is a modern and intuitive terminal-based text editor based on golang.



love2d is a 2d game engine

on my debian12, I stuck on build

```bash
run ./platform/unix/automagic

[automagic]  Copying files...
[automagic]  Running genmodules...
[automagic]  Running autoheader...
[automagic]  Running libtoolize...
[automagic]  Running aclocal...
[automagic]  Running autoconf...
configure.ac:38: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:38: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:38: the top level
configure.ac:46: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:46: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:46: the top level
configure.ac:62: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:62: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:62: the top level
configure.ac:63: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:63: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:63: the top level
configure.ac:118: warning: The macro `AC_HELP_STRING' is obsolete.
configure.ac:118: You should run autoupdate.
./lib/autoconf/general.m4:204: AC_HELP_STRING is expanded from...
configure.ac:118: the top level
configure:20637: error: possibly undefined macro: AM_PATH_SDL2
      If this token and others are legitimate, please use m4_pattern_allow.
      See the Autoconf documentation.
[automagic]  Failed, sadface.
[automagic]  This is generally a configuration error (I'm looking at you aclocal)

```


Android

Google Cloud

Google Search

Google AI

Google Chrome

Flutter Dart firebase Go Chromium LevelDB 

Human are not good at linear data, like lists or table.
People are good at graph data, like a network.


# 2023-12-16

https://docs.google.com/document/d/1peUSMsvFGvqD5yKh3GprskLC3KVdAlLGOsK6gFoEOD0/edit?resourcekey=0-bPajpoo9IBZpG__-uCBE6w#heading=h.34a91yqebirw

WebAssembly
WebGPU
Accessible Rich Internet Applications (ARIA) provides an ontology for enabling accessibility of arbitrary content.
WebHID

# ELF PE

Id Section
0 custom section
1 type section
2 import section
3 function section
4 table section
5 memory section
6 global section
7 export section
8 start section
9 element section
10 code section
11 data section
12 data count section

```cpp
struct ModuleDesc {
  std::vector<FuncType> func_types; // type section
  std::vector<ImportDesc> imports;
  std::vector<FuncDesc> funcs;
  std::vector<TableDesc> tables;
  std::vector<MemoryDesc> memories;
  std::vector<GlobalDesc> globals;
  std::vector<TagDesc> tags;
  std::vector<ExportDesc> exports;
  std::vector<StartDesc> starts;
  std::vector<ElemDesc> elems;
  std::vector<DataDesc> datas;
  Istream istream;
};


```

WebAssembly Module
- preamble
  - magic
  - version
  - sections
    - type
    - import
    - func
    - tablesec
    - memsec
    - globalsec
    - exportsec
    - startsec
    - elemsec
    - datacountsec
    - codesec
    - datasec
- 
```

> The Code section stores the local variables information and bytecode of the function. The Function section associates the code section with the type section.

projects/wabt/include/wabt/interp/interp.h


```cpp
  // Matches binary format, do not change.
  enum Enum : int32_t {
    I32 = -0x01,        // 0x7f
    I64 = -0x02,        // 0x7e
    F32 = -0x03,        // 0x7d
    F64 = -0x04,        // 0x7c
    V128 = -0x05,       // 0x7b
    I8 = -0x06,         // 0x7a  : packed-type only, used in gc and as v128 lane
    I16 = -0x07,        // 0x79  : packed-type only, used in gc and as v128 lane
    FuncRef = -0x10,    // 0x70
    ExternRef = -0x11,  // 0x6f
    Reference = -0x15,  // 0x6b
    Func = -0x20,       // 0x60
    Struct = -0x21,     // 0x5f
    Array = -0x22,      // 0x5e
    Void = -0x40,       // 0x40
    ___ = Void,         // Convenient for the opcode table in opcode.h

    Any = 0,   // Not actually specified, but useful for type-checking
    I8U = 4,   // Not actually specified, but used internally with load/store
    I16U = 6,  // Not actually specified, but used internally with load/store
    I32U = 7,  // Not actually specified, but used internally with load/store
  };
```

type sections stores function 

u32

# Section Type (id is 0x01)

overall number (vector length)

function type 0x60 , parameter length 0x03, parameters, result length 0x01, results

In this example. we only have function type in our type section.

# Section Import (id is 0x02)

length of section

length of module name, module name

length of import name, import name

importdesc 0x00 is typeidx followed by a typeidx


# Section Function (id is 0x03)

length of section

function indices point to type section

# Section Table (id is 4)

length of section

reftype (function ref 0x70)

limits (0x01 0x05 0x05 {min: 0x05, max: 0x05})

# Section Memory (id is 5)


limits of the number of pages

> page size in wasm is 64kb

# Section Global (id is 6)

type

0x00 const 0x01 var

initilize expr

```

a.out:	file format wasm 0x1

Contents of section Type:
000000a: 0960 037f 7f7f 017f 6003 7f7e 7f01 7e60  .`......`..~..~`
000001a: 037f 7f7f 0060 017f 017f 6002 7f7f 017f  .....`....`.....
000002a: 6004 7f7f 7f7f 017f 6004 7f7e 7f7f 017f  `.......`..~....
000003a: 6000 0060 027c 7f01 7c                   `..`.|..|

Contents of section Import:
0000046: 0416 7761 7369 5f73 6e61 7073 686f 745f  ..wasi_snapshot_
0000056: 7072 6576 6965 7731 0866 645f 636c 6f73  preview1.fd_clos
0000066: 6500 0316 7761 7369 5f73 6e61 7073 686f  e...wasi_snapsho
0000076: 745f 7072 6576 6965 7731 0d66 645f 6664  t_preview1.fd_fd
0000086: 7374 6174 5f67 6574 0004 1677 6173 695f  stat_get...wasi_
0000096: 736e 6170 7368 6f74 5f70 7265 7669 6577  snapshot_preview
00000a6: 3107 6664 5f73 6565 6b00 0616 7761 7369  1.fd_seek...wasi
00000b6: 5f73 6e61 7073 686f 745f 7072 6576 6965  _snapshot_previe
00000c6: 7731 0866 645f 7772 6974 6500 05         w1.fd_write..

Contents of section Function:
00000d5: 0f07 0300 0000 0103 0204 0805 0202 0200  ................

Contents of section Table:
00000e7: 0170 0105 05                             .p...

Contents of section Memory:
00000ee: 0100 02                                  ...

Contents of section Global:
00000f3: 017f 0141 a0a5 040b                      ...A....

Contents of section Export:
00000fd: 0206 6d65 6d6f 7279 0200 065f 7374 6172  ..memory..._star
000010d: 7400 04                                  t..

Contents of section Elem:
0000112: 0100 4101 0b04 0705 0809                 ..A.......

Contents of section DataCount:
000011e: 17                                       .

Contents of section Code:
0000122: 0fcb 0501 057f 41d0 1c28 0200 4504 4041  ......A..(..E.@A
0000132: d01c 4101 3602 0023 0041 106b 2203 2400  ..A.6..#.A.k".$.
0000142: 2003 4100 3602 0c23 0041 d001 6b22 0024   .A.6..#.A..k".$
0000152: 0020 0041 0036 02cc 0120 0041 c001 6a42  . .A.6... .A..jB
0000162: 0037 0300 2000 41b8 016a 4200 3703 0020  .7.. .A..jB.7.. 
0000172: 0041 b001 6a42 0037 0300 2000 4200 3703  .A..jB.7.. .B.7.
0000182: a801 2000 4200 3703 a001 2000 4100 3602  .. .B.7... .A.6.
0000192: c801 4100 2000 41c8 016a 2000 41d0 006a  ..A. .A..j .A..j
00001a2: 2000 41a0 016a 100e 4100 4804 7f41 7f05   .A..j..A.H..A..
00001b2: 41e0 1a28 0200 2101 419c 1b28 0200 4100  A..(..!.A..(..A.
00001c2: 4c04 4041 e01a 2001 415f 7136 0200 0b02  L.@A.. .A_q6....
00001d2: 7f02 4002 4041 8c1b 2802 0045 0440 418c  ..@.@A..(..E.@A.
00001e2: 1b41 d000 3602 0041 f81a 4100 3602 0041  .A..6..A..A.6..A
00001f2: f01a 4200 3703 0041 881b 2802 0021 0241  ..B.7..A..(..!.A
0000202: 881b 2000 3602 000c 010b 41f0 1a28 0200  .. .6.....A..(..
0000212: 0d01 0b41 7f41 e01a 100a 0d01 1a0b 41e0  ...A.A........A.
0000222: 1a20 0041 c801 6a20 0041 d000 6a20 0041  . .A..j .A..j .A
0000232: a001 6a10 0e0b 2104 2001 4120 7121 0120  ..j...!. .A q!. 
0000242: 0204 7f41 e01a 4100 4100 4180 1b28 0200  ...A..A.A.A..(..
0000252: 1100 001a 418c 1b41 0036 0200 4188 1b20  ....A..A.6..A.. 
0000262: 0236 0200 41f8 1a41 0036 0200 41f4 1a28  .6..A..A.6..A..(
0000272: 0200 1a41 f01a 4200 3703 0041 0005 2004  ...A..B.7..A.. .
0000282: 0b1a 41e0 1a41 e01a 2802 0020 0172 3602  ..A..A..(.. .r6.
0000292: 0041 000b 1a20 0041 d001 6a24 0020 0341  .A... .A..j$. .A
00002a2: 106a 2400 41e8 2428 0200 2200 0440 0340  .j$.A.$(.."..@.@
00002b2: 2000 2802 1420 0028 0218 4704 4020 0041   .(.. .(..G.@ .A
00002c2: 0041 0020 0028 0220 1100 001a 0b20 0028  .A. .(. ..... .(
00002d2: 0204 2201 2000 2802 0822 0247 0440 2000  ..". .(..".G.@ .
00002e2: 2001 2002 6bac 4101 2000 2802 2411 0100   . .k.A. .(.$...
00002f2: 1a0b 2000 2802 3422 000d 000b 0b02 4041  .. .(.4"......@A
0000302: ec24 2802 0022 0045 0d00 2000 2802 1420  .$(..".E.. .(.. 
0000312: 0028 0218 4704 4020 0041 0041 0020 0028  .(..G.@ .A.A. .(
0000322: 0220 1100 001a 0b20 0028 0204 2201 2000  . ..... .(..". .
0000332: 2802 0822 0246 0d00 2000 2001 2002 6bac  (..".F.. . . .k.
0000342: 4101 2000 2802 2411 0100 1a0b 0240 41d0  A. .(.$......@A.
0000352: 1b28 0200 2200 450d 0020 0028 0214 2000  .(..".E.. .(.. .
0000362: 2802 1847 0440 2000 4100 4100 2000 2802  (..G.@ .A.A. .(.
0000372: 2011 0000 1a0b 2000 2802 0422 0120 0028   ..... .(..". .(
0000382: 0208 2202 460d 0020 0020 0120 026b ac41  ..".F.. . . .k.A
0000392: 0120 0028 0224 1101 001a 0b02 4041 c81c  . .(.$......@A..
00003a2: 2802 0022 0045 0d00 2000 2802 1420 0028  (..".E.. .(.. .(
00003b2: 0218 4704 4020 0041 0041 0020 0028 0220  ..G.@ .A.A. .(. 
00003c2: 1100 001a 0b20 0028 0204 2201 2000 2802  ..... .(..". .(.
00003d2: 0822 0246 0d00 2000 2001 2002 6bac 4101  .".F.. . . .k.A.
00003e2: 2000 2802 2411 0100 1a0b 0f0b 000b 2000   .(.$......... .
00003f2: 2000 2802 3810 0041 ffff 0371 2200 047f   .(.8..A...q"...
0000402: 41d4 1c20 0036 0200 417f 0541 000b 0b57  A.. .6..A..A...W
0000412: 0102 7f23 0041 106b 2203 2400 417f 2104  ...#.A.k".$.A.!.
0000422: 0240 2002 4100 4804 4041 d41c 411c 3602  .@ .A.H.@A..A.6.
0000432: 000c 010b 2000 2001 2002 2003 410c 6a10  .... . . . .A.j.
0000442: 0341 ffff 0371 2202 0440 41d4 1c20 0236  .A...q"..@A.. .6
0000452: 0200 0c01 0b20 0328 020c 2104 0b20 0341  ..... .(..!.. .A
0000462: 106a 2400 2004 0b9e 0201 077f 2300 4110  .j$. .......#.A.
0000472: 6b22 0324 0020 0320 0236 020c 2003 2001  k".$. . .6.. . .
0000482: 3602 0820 0320 0028 0218 2201 3602 0020  6.. . .(..".6.. 
0000492: 0320 0028 0214 2001 6b22 0136 0204 4102  . .(.. .k".6..A.
00004a2: 2105 027f 2001 2002 6a22 0820 0028 0238  !... . .j". .(.8
00004b2: 2003 4102 1006 2201 4704 4020 0321 0403   .A...".G.@ .!..
00004c2: 4020 0141 0048 0440 2000 4100 3602 1820  @ .A.H.@ .A.6.. 
00004d2: 0042 0037 0310 2000 2000 2802 0041 2072  .B.7.. . .(..A r
00004e2: 3602 0041 0020 0541 0246 0d03 1a20 0220  6..A. .A.F... . 
00004f2: 0428 0204 6b0c 030b 2004 2001 2004 2802  .(..k... . . .(.
0000502: 0422 064b 2207 4103 746a 2209 2001 2006  .".K".A.tj". . .
0000512: 4100 2007 1b6b 2206 2009 2802 006a 3602  A. ..k". .(..j6.
0000522: 0020 0441 0c41 0420 071b 6a22 0420 0428  . .A.A. ..j". .(
0000532: 0200 2006 6b36 0200 2008 2001 6b22 0820  .. .k6.. . .k". 
0000542: 0028 0238 2009 2204 2005 2007 6b22 0510  .(.8 .". . .k"..
0000552: 0622 0147 0d00 0b0b 2000 2000 2802 2822  .".G.... . .(.("
0000562: 0136 0218 2000 2001 3602 1420 0020 0120  .6.. . .6.. . . 
0000572: 0028 022c 6a36 0210 2002 0b21 0120 0341  .(.,j6.. ..!. .A
0000582: 106a 2400 2001 0b83 0101 027f 2000 4101  .j$. ....... .A.
0000592: 3602 2002 4020 002d 0000 41c0 0071 0d00  6. .@ .-..A..q..
00005a2: 2000 2802 3821 0323 0041 206b 2204 2400   .(.8!.#.A k".$.
00005b2: 027f 0240 2003 2004 4108 6a10 0141 ffff  ...@ . .A.j..A..
00005c2: 0371 2203 0d00 413b 2103 2004 2d00 0841  .q"...A;!. .-..A
00005d2: 0247 0d00 2004 2d00 1041 2471 0d00 4101  .G.. .-..A$q..A.
00005e2: 0c01 0b41 d41c 2003 3602 0041 000b 2103  ...A.. .6..A..!.
00005f2: 2004 4120 6a24 0020 030d 0020 0041 7f36   .A j$. ... .A.6
0000602: 0240 0b20 0020 0120 0210 070b 5801 017f  .@. . . ....X...
0000612: 2000 2802 3821 0323 0041 106b 2200 2400   .(.8!.#.A.k".$.
0000622: 027e 2003 2001 2002 41ff 0171 2000 4108  .~ . . .A..q .A.
0000632: 6a10 0241 ffff 0371 2202 0440 41d4 1c41  j..A...q"..@A..A
0000642: c600 2002 2002 41cc 0046 1b36 0200 427f  .. . .A..F.6..B.
0000652: 0c01 0b20 0029 0308 0b21 0120 0041 106a  ... .)...!. .A.j
0000662: 2400 2001 0b59 0101 7f20 0020 0028 023c  $. ..Y... . .(.<
0000672: 2201 4101 6b20 0172 3602 3c20 0028 0200  ".A.k .r6.< .(..
0000682: 2201 4108 7104 4020 0020 0141 2072 3602  ".A.q.@ . .A r6.
0000692: 0041 7f0f 0b20 0042 0037 0204 2000 2000  .A... .B.7.. . .
00006a2: 2802 2822 0136 0218 2000 2001 3602 1420  (.(".6.. . .6.. 
00006b2: 0020 0120 0028 022c 6a36 0210 4100 0bbc  . . .(.,j6..A...
00006c2: 0101 047f 0240 2001 2002 2802 1022 0304  .....@ . .(.."..
00006d2: 7f20 0305 2002 100a 0d01 2002 2802 100b  . .. ..... .(...
00006e2: 2002 2802 1422 046b 4b04 4020 0220 0020   .(..".kK.@ . . 
00006f2: 0120 0228 0220 1100 001a 0f0b 0240 2002  . .(. .......@ .
0000702: 2802 4041 0048 0d00 2000 2105 4100 2103  (.@A.H.. .!.A.!.
0000712: 0340 2001 2003 460d 0120 0341 016a 2103  .@ . .F.. .A.j!.
0000722: 2005 4101 6b22 0520 016a 2206 2d00 0041   .A.k". .j".-..A
0000732: 0a47 0d00 0b20 0220 0020 0120 036b 4101  .G... . . . .kA.
0000742: 6a22 0020 0228 0220 1100 0020 0049 0d01  j". .(. ... .I..
0000752: 2003 4101 6b21 0120 0641 016a 2100 2002   .A.k!. .A.j!. .
0000762: 2802 1421 040b 2004 2000 2001 1011 2002  (..!.. . . ... .
0000772: 2002 2802 1420 016a 3602 140b 0ba6 0200   .(.. .j6.......
0000782: 2000 4504 4041 000f 0b20 0004 7f02 7f20   .E.@A... ..... 
0000792: 0141 ff00 4d04 4020 0020 013a 0000 4101  .A..M.@ . .:..A.
00007a2: 0c01 0b02 4041 f024 2802 0045 0440 2001  ....@A.$(..E.@ .
00007b2: 4180 7f71 4180 bf03 4704 4041 d41c 4119  A..qA...G.@A..A.
00007c2: 3602 000c 020b 2000 2001 3a00 0041 010c  6..... . .:..A..
00007d2: 020b 2001 41ff 0f4d 0440 2000 2001 413f  .. .A..M.@ . .A?
00007e2: 7141 8001 723a 0001 2000 2001 4106 7641  qA..r:.. . .A.vA
00007f2: c001 723a 0000 4102 0c02 0b20 0141 8040  ..r:..A.... .A.@
0000802: 7141 80c0 0347 2001 4180 b003 4f71 4504  qA...G .A...OqE.
0000812: 4020 0020 0141 3f71 4180 0172 3a00 0220  @ . .A?qA..r:.. 
0000822: 0020 0141 0c76 41e0 0172 3a00 0020 0020  . .A.vA..r:.. . 
0000832: 0141 0676 413f 7141 8001 723a 0001 4103  .A.vA?qA..r:..A.
0000842: 0c02 0b20 0141 8080 046b 41ff ff3f 4d04  ... .A...kA..?M.
0000852: 4020 0020 0141 3f71 4180 0172 3a00 0320  @ . .A?qA..r:.. 
0000862: 0020 0141 1276 41f0 0172 3a00 0020 0020  . .A.vA..r:.. . 
0000872: 0141 0676 413f 7141 8001 723a 0002 2000  .A.vA?qA..r:.. .
0000882: 2001 410c 7641 3f71 4180 0172 3a00 0141   .A.vA?qA..r:..A
0000892: 040c 020b 41d4 1c41 1936 0200 0b41 7f0b  ....A..A.6...A..
00008a2: 0541 010b 0b85 0102 017f 017e 2000 bd22  .A.........~ .."
00008b2: 0342 3488 a741 ff0f 7122 0241 ff0f 4704  .B4..A..q".A..G.
00008c2: 7c20 0245 0440 2000 4400 0000 0000 0000  | .E.@ .D.......
00008d2: 0061 0440 2001 4100 3602 0020 000f 0b20  .a.@ .A.6.. ... 
00008e2: 0044 0000 0000 0000 f043 a220 0110 0d21  .D.......C. ...!
00008f2: 0020 0120 0128 0200 4140 6a36 0200 2000  . . .(..A@j6.. .
0000902: 0f0b 2001 2002 41fe 076b 3602 0020 0342  .. . .A..k6.. .B
0000912: ffff ffff ffff ff87 807f 8342 8080 8080  ...........B....
0000922: 8080 80f0 3f84 bf05 2000 0b0b e143 0324  ....?... ....C.$
0000932: 7f02 7c02 7e41 b608 210a 2300 41f0 066b  ..|.~A..!.#.A..k
0000942: 2206 2400 2006 41d0 006a 2118 4190 7f20  ".$. .A..j!.A.. 
0000952: 066b 2120 2006 4194 1f6b 2121 2006 4137  .k!  .A..k!! .A7
0000962: 6a21 2220 0641 d000 6a41 7e73 2123 2006  j!" .A..jA~s!# .
0000972: 41cf 006a 2124 2006 41d0 006a 4108 7221  A..j!$ .A..jA.r!
0000982: 1f20 0641 d000 6a41 0972 211d 41b2 7f20  . .A..jA.r!.A.. 
0000992: 066b 2125 2006 41ce 006a 2126 2006 4138  .k!% .A..j!& .A8
00009a2: 6a21 1502 4002 4003 4002 4020 0a21 0920  j!..@.@.@.@ .!. 
00009b2: 0420 1241 ffff ffff 0773 4a0d 0020 0420  . .A.....sJ.. . 
00009c2: 126a 2112 0240 0240 0240 0240 0240 0240  .j!..@.@.@.@.@.@
00009d2: 0240 0240 2009 2d00 0022 0404 4003 4002  .@.@ .-.."..@.@.
00009e2: 4002 4020 0441 ff01 7122 0404 4020 0441  @.@ .A..q"..@ .A
00009f2: 2547 0d02 200a 2205 2104 0340 2004 2d00  %G.. .".!..@ .-.
0000a02: 0141 2547 0440 2004 210a 0c03 0b20 0541  .A%G.@ .!.... .A
0000a12: 016a 2105 2004 2d00 0221 0720 0441 026a  .j!. .-..!. .A.j
0000a22: 220a 2104 2007 4125 460d 000b 0c01 0b20  ".!. .A%F...... 
0000a32: 0a21 050b 2005 2009 6b22 0420 1241 ffff  .!.. . .k". .A..
0000a42: ffff 0773 2205 4a0d 0b02 4020 0045 0d00  ...s".J...@ .E..
0000a52: 2000 2d00 0041 2071 0d00 2009 2004 2000   .-..A q.. . . .
0000a62: 100b 0b20 040d 0c20 0a41 016a 2104 417f  ... ... .A.j!.A.
0000a72: 2110 0240 200a 2c00 0122 0841 306b 2207  !..@ .,..".A0k".
0000a82: 4109 4b0d 0020 0a2d 0002 4124 470d 0020  A.K.. .-..A$G.. 
0000a92: 0a41 036a 2104 200a 2c00 0321 0841 0121  .A.j!. .,..!.A.!
0000aa2: 1920 0721 100b 4100 210b 0240 2008 4120  . .!..A.!..@ .A 
0000ab2: 6b22 0a41 1f4b 0d00 4101 200a 7422 0a41  k".A.K..A. .t".A
0000ac2: 89d1 0471 450d 0020 0441 016a 2107 0340  ...qE.. .A.j!..@
0000ad2: 200a 200b 7221 0b20 0722 042c 0000 2208   . .r!. .".,..".
0000ae2: 4120 6b22 0a41 204f 0d01 2004 4101 6a21  A k".A O.. .A.j!
0000af2: 0741 0120 0a74 220a 4189 d104 710d 000b  .A. .t".A...q...
0000b02: 0b20 0841 2a46 0440 027f 0240 2004 2c00  . .A*F.@...@ .,.
0000b12: 0141 306b 220a 4109 4b0d 0020 042d 0002  .A0k".A.K.. .-..
0000b22: 4124 470d 0020 0320 0a41 0274 6a41 0a36  A$G.. . .A.tjA.6
0000b32: 0200 2004 4103 6a21 0741 0121 1920 042c  .. .A.j!.A.!. .,
0000b42: 0001 4103 7420 026a 4180 036b 2802 000c  ..A.t .jA..k(...
0000b52: 010b 2019 0d06 2004 4101 6a21 0720 0045  .. ... .A.j!. .E
0000b62: 0440 4100 2119 4100 210f 0c06 0b20 0120  .@A.!.A.!.... . 
0000b72: 0128 0200 220a 4104 6a36 0200 4100 2119  .(..".A.j6..A.!.
0000b82: 200a 2802 000b 220f 4100 4e0d 0441 0020   .(...".A.N..A. 
0000b92: 0f6b 210f 200b 4180 c000 7221 0b0c 040b  .k!. .A...r!....
0000ba2: 4100 210f 2008 4130 6b22 0a41 094b 0440  A.!. .A0k".A.K.@
0000bb2: 2004 2107 0c04 0b03 4020 0f41 cc99 b3e6   .!.....@ .A....
0000bc2: 004d 0440 417f 200f 410a 6c22 0720 0a6a  .M.@A. .A.l". .j
0000bd2: 200a 2007 41ff ffff ff07 734b 1b21 0f20   . .A.....sK.!. 
0000be2: 042c 0001 210a 2004 4101 6a22 0721 0420  .,..!. .A.j".!. 
0000bf2: 0a41 306b 220a 410a 490d 0120 0f41 0048  .A0k".A.I.. .A.H
0000c02: 0d0d 0c05 0b20 042c 0001 210a 417f 210f  ..... .,..!.A.!.
0000c12: 2004 4101 6a21 0420 0a41 306b 220a 410a   .A.j!. .A0k".A.
0000c22: 490d 000b 0c0b 0b20 0a2d 0001 2104 200a  I...... .-..!. .
0000c32: 4101 6a21 0a0c 000b 000b 2000 0d0b 2019  A.j!...... ... .
0000c42: 4504 4041 0021 120c 0c0b 0240 2003 2802  E.@A.!.....@ .(.
0000c52: 0422 0a45 0440 4101 210a 0c01 0b20 0241  .".E.@A.!.... .A
0000c62: 086a 200a 2001 100f 2003 2802 0822 0a45  .j . ... .(..".E
0000c72: 0440 4102 210a 0c01 0b20 0241 106a 200a  .@A.!.... .A.j .
0000c82: 2001 100f 2003 2802 0c22 0a45 0440 4103   ... .(..".E.@A.
0000c92: 210a 0c01 0b20 0241 186a 200a 2001 100f  !.... .A.j . ...
0000ca2: 2003 2802 1022 0a45 0440 4104 210a 0c01   .(..".E.@A.!...
0000cb2: 0b20 0241 206a 200a 2001 100f 2003 2802  . .A j . ... .(.
0000cc2: 1422 0a45 0440 4105 210a 0c01 0b20 0241  .".E.@A.!.... .A
0000cd2: 286a 200a 2001 100f 2003 2802 1822 0a45  (j . ... .(..".E
0000ce2: 0440 4106 210a 0c01 0b20 0241 306a 200a  .@A.!.... .A0j .
0000cf2: 2001 100f 2003 2802 1c22 0a45 0440 4107   ... .(..".E.@A.
0000d02: 210a 0c01 0b20 0241 386a 200a 2001 100f  !.... .A8j . ...
0000d12: 2003 2802 2022 0a45 0440 4108 210a 0c01   .(. ".E.@A.!...
0000d22: 0b20 0241 406b 200a 2001 100f 2003 2802  . .A@k . ... .(.
0000d32: 2422 0a45 0440 4109 210a 0c01 0b20 0241  $".E.@A.!.... .A
0000d42: c800 6a20 0a20 0110 0f41 0121 120c 0c0b  ..j . ...A.!....
0000d52: 200a 4102 7421 0a03 4020 0320 0a6a 2802   .A.t!..@ . .j(.
0000d62: 000d 0220 0a41 046a 220a 4128 470d 000b  ... .A.j".A(G...
0000d72: 4101 2112 0c0b 0b41 0021 0441 7f21 0802  A.!....A.!.A.!..
0000d82: 4020 072d 0000 412e 4704 4020 0721 0a41  @ .-..A.G.@ .!.A
0000d92: 0021 0c0c 010b 2007 2c00 0122 0841 2a46  .!.... .,..".A*F
0000da2: 0440 027f 0240 2007 2c00 0241 306b 220a  .@...@ .,..A0k".
0000db2: 4109 4b0d 0020 072d 0003 4124 470d 0020  A.K.. .-..A$G.. 
0000dc2: 0320 0a41 0274 6a41 0a36 0200 2007 4104  . .A.tjA.6.. .A.
0000dd2: 6a21 0a20 072c 0002 4103 7420 026a 4180  j!. .,..A.t .jA.
0000de2: 036b 2802 000c 010b 2019 0d03 2007 4102  .k(..... ... .A.
0000df2: 6a21 0a41 0020 0045 0d00 1a20 0120 0128  j!.A. .E... . .(
0000e02: 0200 2207 4104 6a36 0200 2007 2802 000b  ..".A.j6.. .(...
0000e12: 2208 417f 7341 1f76 210c 0c01 0b20 0741  ".A.sA.v!.... .A
0000e22: 016a 210a 2008 4130 6b22 0d41 094b 0440  .j!. .A0k".A.K.@
0000e32: 4101 210c 4100 2108 0c01 0b41 0021 1120  A.!.A.!....A.!. 
0000e42: 0a21 0703 4041 7f21 0820 1141 cc99 b3e6  .!..@A.!. .A....
0000e52: 004d 0440 417f 2011 410a 6c22 0a20 0d6a  .M.@A. .A.l". .j
0000e62: 200d 200a 41ff ffff ff07 734b 1b21 080b   . .A.....sK.!..
0000e72: 4101 210c 2007 2c00 0121 0d20 0821 1120  A.!. .,..!. .!. 
0000e82: 0741 016a 220a 2107 200d 4130 6b22 0d41  .A.j".!. .A0k".A
0000e92: 0a49 0d00 0b0b 0340 2004 2107 200a 2c00  .I.....@ .!. .,.
0000ea2: 0022 0441 fb00 6b41 4649 0d01 200a 4101  .".A..kAFI.. .A.
0000eb2: 6a21 0a20 0420 0741 3a6c 6a41 bf16 6a2d  j!. . .A:ljA..j-
0000ec2: 0000 2204 4101 6b41 0849 0d00 0b02 4002  ..".A.kA.I....@.
0000ed2: 4020 0441 1b47 0440 2004 450d 0320 1041  @ .A.G.@ .E.. .A
0000ee2: 004e 0440 2003 2010 4102 746a 2004 3602  .N.@ . .A.tj .6.
0000ef2: 0020 0620 0220 1041 0374 6a29 0300 3703  . . . .A.tj)..7.
0000f02: 380c 020b 2000 4504 4041 0021 120c 0e0b  8... .E.@A.!....
0000f12: 2006 4138 6a20 0420 0110 0f0c 020b 2010   .A8j . ...... .
0000f22: 4100 4e0d 020b 4100 2104 2000 450d 090b  A.N...A.!. .E...
0000f32: 200b 41ff ff7b 7122 1120 0b20 0b41 80c0   .A..{q". . .A..
0000f42: 0071 1b21 0e02 4002 4002 7f02 4002 4002  .q.!..@.@...@.@.
0000f52: 7f02 7f02 4002 4002 4002 4002 7f02 4002  ....@.@.@.@...@.
0000f62: 4002 4002 4002 4002 4020 0a41 016b 2c00  @.@.@.@.@ .A.k,.
0000f72: 0022 0441 5f71 2004 2004 410f 7141 0346  .".A_q . .A.qA.F
0000f82: 1b20 0420 071b 2213 41c1 006b 0e38 1113  . . ..".A..k.8..
0000f92: 0e13 1111 1113 1313 1313 1313 1313 1313  ................
0000fa2: 0d13 1313 1303 1313 1313 1313 1313 1113  ................
0000fb2: 0805 1111 1113 0513 1313 0901 0402 1313  ................
0000fc2: 0a13 0013 1303 130b 4100 210d 2006 2903  ........A.!. .).
0000fd2: 3821 2a41 8008 0c05 0b41 0021 0402 4002  8!*A.....A.!..@.
0000fe2: 4002 4002 4002 4002 4002 4020 0741 ff01  @.@.@.@.@.@ .A..
0000ff2: 710e 0800 0102 0304 1f05 061f 0b20 0628  q............ .(
0001002: 0238 2012 3602 000c 1e0b 2006 2802 3820  .8 .6..... .(.8 
0001012: 1236 0200 0c1d 0b20 0628 0238 2012 ac37  .6..... .(.8 ..7
0001022: 0300 0c1c 0b20 0628 0238 2012 3b01 000c  ..... .(.8 .;...
0001032: 1b0b 2006 2802 3820 123a 0000 0c1a 0b20  .. .(.8 .:..... 
0001042: 0628 0238 2012 3602 000c 190b 2006 2802  .(.8 .6..... .(.
0001052: 3820 12ac 3703 000c 180b 4108 2008 2008  8 ..7.....A. . .
0001062: 4108 4d1b 2108 200e 4108 7221 0e41 f800  A.M.!. .A.r!.A..
0001072: 2113 0b41 0021 0d41 8008 2110 2006 2903  !..A.!.A..!. .).
0001082: 3822 2a50 0440 2015 2109 0c04 0b20 1341  8"*P.@ .!.... .A
0001092: 2071 2107 2015 2109 0340 2009 4101 6b22   q!. .!..@ .A.k"
00010a2: 0920 2aa7 410f 7141 d01a 6a2d 0000 2007  . *.A.qA..j-.. .
00010b2: 723a 0000 202a 420f 5621 0420 2a42 0488  r:.. *B.V!. *B..
00010c2: 212a 2004 0d00 0b20 0e41 0871 450d 0320  !* .... .A.qE.. 
00010d2: 1341 0475 4180 086a 2110 4102 210d 0c03  .A.uA..j!.A.!...
00010e2: 0b20 1521 0920 0629 0338 222a 4200 5204  . .!. .).8"*B.R.
00010f2: 4003 4020 0941 016b 2209 202a a741 0771  @.@ .A.k". *.A.q
0001102: 4130 723a 0000 202a 4207 5621 0420 2a42  A0r:.. *B.V!. *B
0001112: 0388 212a 2004 0d00 0b0b 4100 210d 4180  ..!* .....A.!.A.
0001122: 0821 1020 0e41 0871 450d 0220 0820 1520  .!. .A.qE.. . . 
0001132: 096b 2204 4101 6a20 0420 0848 1b21 080c  .k".A.j . .H.!..
0001142: 020b 2006 2903 3822 2a42 0053 0440 2006  .. .).8"*B.S.@ .
0001152: 4200 202a 7d22 2a37 0338 4101 210d 4180  B. *}"*7.8A.!.A.
0001162: 080c 010b 200e 4180 1071 0440 4101 210d  .... .A..q.@A.!.
0001172: 4181 080c 010b 4182 0841 8008 200e 4101  A.....A..A.. .A.
0001182: 7122 0d1b 0b21 1002 4020 2a42 8080 8080  q"...!..@ *B....
0001192: 1054 0440 202a 212b 2015 2109 0c01 0b20  .T.@ *!+ .!.... 
00011a2: 1521 0903 4020 0941 016b 2209 202a 202a  .!..@ .A.k". * *
00011b2: 420a 8022 2b42 0a7e 7da7 4130 723a 0000  B.."+B.~}.A0r:..
00011c2: 202a 42ff ffff ff9f 0156 2104 202b 212a   *B......V!. +!*
00011d2: 2004 0d00 0b0b 202b a722 0445 0d00 0340   ..... +.".E...@
00011e2: 2009 4101 6b22 0920 0420 0441 0a6e 2207   .A.k". . .A.n".
00011f2: 410a 6c6b 4130 723a 0000 2004 4109 4b21  A.lkA0r:.. .A.K!
0001202: 0b20 0721 0420 0b0d 000b 0b20 0c41 0020  . .!. ..... .A. 
0001212: 0841 0048 1b0d 1120 0e41 ffff 7b71 200e  .A.H... .A..{q .
0001222: 200c 1b21 1102 4020 0629 0338 222a 4200   ..!..@ .).8"*B.
0001232: 520d 0041 0021 0b20 080d 0020 1522 0921  R..A.!. ... .".!
0001242: 040c 0d0b 2008 202a 5020 1520 096b 6a22  .... . *P . .kj"
0001252: 0420 0420 0848 1b21 0b20 1521 040c 0c0b  . . .H.!. .!....
0001262: 2006 2006 2903 383c 0037 4100 210d 4180   . .).8<.7A.!.A.
0001272: 0821 1041 0121 0b20 2221 0920 1521 040c  .!.A.!. "!. .!..
0001282: 0b0b 41d4 1c28 0200 2109 4188 2528 0200  ..A..(..!.A.%(..
0001292: 2204 047f 2004 0541 8825 41f0 2436 0200  "... ..A.%A.$6..
00012a2: 41f0 240b 2802 141a 2009 4100 2009 41cc  A.$.(... .A. .A.
00012b2: 004d 1b41 0174 41e0 156a 2f01 0041 c709  .M.A.tA..j/..A..
00012c2: 6a0c 010b 2006 2802 3822 0441 af08 2004  j... .(.8".A.. .
00012d2: 1b0b 2209 2104 41ff ffff ff07 2008 2008  ..".!.A..... . .
00012e2: 41ff ffff ff07 4f1b 2207 2210 4100 4721  A.....O.".".A.G!
00012f2: 0b02 4002 4002 4002 4020 0441 0371 450d  ..@.@.@.@ .A.qE.
0001302: 0020 1045 0d00 2004 2d00 0045 0440 2004  . .E.. .-..E.@ .
0001312: 210e 2010 210c 0c03 0b20 1041 016b 220c  !. .!.... .A.k".
0001322: 4100 4721 0b20 0441 016a 220e 4103 7145  A.G!. .A.j".A.qE
0001332: 0d01 200c 450d 0120 0e2d 0000 450d 0220  .. .E.. .-..E.. 
0001342: 1041 026b 220c 4100 4721 0b20 0441 026a  .A.k".A.G!. .A.j
0001352: 220e 4103 7145 0d01 200c 450d 0120 0e2d  ".A.qE.. .E.. .-
0001362: 0000 450d 0220 1041 036b 220c 4100 4721  ..E.. .A.k".A.G!
0001372: 0b20 0441 036a 220e 4103 7145 0d01 200c  . .A.j".A.qE.. .
0001382: 450d 0120 0e2d 0000 450d 0220 0441 046a  E.. .-..E.. .A.j
0001392: 210e 2010 4104 6b22 0c41 0047 210b 0c01  !. .A.k".A.G!...
00013a2: 0b20 1021 0c20 0421 0e0b 200b 450d 0102  . .!. .!.. .E...
00013b2: 4020 0e2d 0000 450d 0020 0c41 0449 0d00  @ .-..E.. .A.I..
00013c2: 0340 200e 2802 0022 1041 7f73 2010 4181  .@ .(..".A.s .A.
00013d2: 8284 086b 7141 8081 8284 7871 0d02 200e  ...kqA....xq.. .
00013e2: 4104 6a21 0e20 0c41 046b 220c 4103 4b0d  A.j!. .A.k".A.K.
00013f2: 000b 0b20 0c45 0d01 0b03 4020 0e20 0e2d  ... .E....@ . .-
0001402: 0000 450d 021a 200e 4101 6a21 0e20 0c41  ..E... .A.j!. .A
0001412: 016b 220c 0d00 0b0b 4100 0b22 0420 096b  .k".....A..". .k
0001422: 2007 2004 1b22 0b20 096a 2104 4100 210d   . ..". .j!.A.!.
0001432: 4180 0821 1020 0841 004e 0d07 2004 2d00  A..!. .A.N.. .-.
0001442: 0045 0d07 0c0c 0b20 0628 0238 2209 2008  .E..... .(.8". .
0001452: 0d01 1a41 0021 040c 020b 2006 4100 3602  ...A.!.... .A.6.
0001462: 0c20 0620 0629 0338 3e02 0820 0620 0641  . . .).8>.. . .A
0001472: 086a 3602 3841 7f21 0820 0641 086a 0b21  .j6.8A.!. .A.j.!
0001482: 0941 0021 0420 0921 0502 4003 4020 0528  .A.!. .!..@.@ .(
0001492: 0200 2207 450d 0102 4020 0641 046a 2007  ..".E...@ .A.j .
00014a2: 100c 2207 4100 4822 0b0d 0020 0720 0820  ..".A.H"... . . 
00014b2: 046b 4b0d 0020 0541 046a 2105 2008 2004  .kK.. .A.j!. . .
00014c2: 2007 6a22 044b 0d01 0c02 0b0b 200b 0d0c   .j".K...... ...
00014d2: 0b20 0441 0048 0d09 0b02 4020 0e41 80c0  . .A.H....@ .A..
00014e2: 0471 220b 0d00 2004 200f 4e0d 0020 0641  .q"... . .N.. .A
00014f2: f000 6a41 2020 0f20 046b 2205 4180 0220  ..jA  . .k".A.. 
0001502: 0541 8002 4922 071b 1012 1a20 0745 0440  .A..I"..... .E.@
0001512: 0340 2000 2d00 0041 2071 4504 4020 0641  .@ .-..A qE.@ .A
0001522: f000 6a41 8002 2000 100b 0b20 0541 8002  ..jA.. .... .A..
0001532: 6b22 0541 ff01 4b0d 000b 0b20 002d 0000  k".A..K.... .-..
0001542: 4120 710d 0020 0641 f000 6a20 0520 0010  A q.. .A..j . ..
0001552: 0b0b 0240 2004 450d 0041 0021 0503 4020  ...@ .E..A.!..@ 
0001562: 0928 0200 2207 450d 0120 0641 046a 2007  .(..".E.. .A.j .
0001572: 100c 2207 2005 6a22 0520 044b 0d01 2000  ..". .j". .K.. .
0001582: 2d00 0041 2071 4504 4020 0641 046a 2007  -..A qE.@ .A.j .
0001592: 2000 100b 0b20 0941 046a 2109 2004 2005   .... .A.j!. . .
00015a2: 4b0d 000b 0b02 4020 0b41 80c0 0047 0d00  K.....@ .A...G..
00015b2: 2004 200f 4e0d 0020 0641 f000 6a41 2020   . .N.. .A..jA  
00015c2: 0f20 046b 2205 4180 0220 0541 8002 4922  . .k".A.. .A..I"
00015d2: 071b 1012 1a20 0745 0440 0340 2000 2d00  ..... .E.@.@ .-.
00015e2: 0041 2071 4504 4020 0641 f000 6a41 8002  .A qE.@ .A..jA..
00015f2: 2000 100b 0b20 0541 8002 6b22 0541 ff01   .... .A..k".A..
0001602: 4b0d 000b 0b20 002d 0000 4120 710d 0020  K.... .-..A q.. 
0001612: 0641 f000 6a20 0520 0010 0b0b 200f 2004  .A..j . .... . .
0001622: 2004 200f 481b 2104 0c09 0b20 0c41 0020   . .H.!.... .A. 
0001632: 0841 0048 1b0d 0720 062b 0338 2128 2006  .A.H... .+.8!( .
0001642: 4100 3602 6c02 7f20 28bd 4200 5304 4020  A.6.l.. (.B.S.@ 
0001652: 289a 2128 4101 2117 418a 0821 1a41 000c  (.!(A.!.A..!.A..
0001662: 010b 200e 4180 1071 0440 4101 2117 418d  .. .A..q.@A.!.A.
0001672: 0821 1a41 000c 010b 4190 0841 8b08 200e  .!.A....A..A.. .
0001682: 4101 7122 171b 211a 2017 450b 211e 2028  A.q"..!. .E.!. (
0001692: 9944 0000 0000 0000 f07f 6345 0440 2017  .D........cE.@ .
00016a2: 4103 6a21 0502 4020 0e41 80c0 0071 0d00  A.j!..@ .A...q..
00016b2: 2005 200f 4e0d 0020 0641 f004 6a41 2020   . .N.. .A..jA  
00016c2: 0f20 056b 2204 4180 0220 0441 8002 4922  . .k".A.. .A..I"
00016d2: 071b 1012 1a20 0745 0440 0340 2000 2d00  ..... .E.@.@ .-.
00016e2: 0041 2071 4504 4020 0641 f004 6a41 8002  .A qE.@ .A..jA..
00016f2: 2000 100b 0b20 0441 8002 6b22 0441 ff01   .... .A..k".A..
0001702: 4b0d 000b 0b20 002d 0000 4120 710d 0020  K.... .-..A q.. 
0001712: 0641 f004 6a20 0420 0010 0b0b 2000 2802  .A..j . .... .(.
0001722: 0022 0441 2071 047f 2004 0520 1a20 1720  .".A q.. .. . . 
0001732: 0010 0b20 0028 0200 0b41 2071 4504 4041  ... .(...A qE.@A
0001742: 9d08 41a5 0820 1341 2071 2204 1b41 a108  ..A.. .A q"..A..
0001752: 41a9 0820 041b 2028 2028 621b 4103 2000  A.. .. ( (b.A. .
0001762: 100b 0b02 4020 0e41 80c0 0471 4180 c000  ....@ .A...qA...
0001772: 470d 0020 0520 0f4e 0d00 2006 41f0 046a  G.. . .N.. .A..j
0001782: 4120 200f 2005 6b22 0441 8002 2004 4180  A  . .k".A.. .A.
0001792: 0249 2207 1b10 121a 2007 4504 4003 4020  .I"..... .E.@.@ 
00017a2: 002d 0000 4120 7145 0440 2006 41f0 046a  .-..A qE.@ .A..j
00017b2: 4180 0220 0010 0b0b 2004 4180 026b 2204  A.. .... .A..k".
00017c2: 41ff 014b 0d00 0b0b 2000 2d00 0041 2071  A..K.... .-..A q
00017d2: 0d00 2006 41f0 046a 2004 2000 100b 0b20  .. .A..j . .... 
00017e2: 0520 0f20 0520 0f4a 1b21 040c 090b 027f  . . . .J.!......
00017f2: 0240 2028 2006 41ec 006a 100d 2228 2028  .@ ( .A..j.."( (
0001802: a022 2844 0000 0000 0000 0000 6204 4020  ."(D........b.@ 
0001812: 0620 0628 026c 2204 4101 6b36 026c 2013  . .(.l".A.k6.l .
0001822: 4120 7222 1641 e100 470d 010c 080b 2013  A r".A..G..... .
0001832: 4120 7222 1641 e100 460d 0720 0628 026c  A r".A..F.. .(.l
0001842: 2109 4106 2008 2008 4100 481b 0c01 0b20  !.A. . .A.H.... 
0001852: 0620 0441 1d6b 2209 3602 6c20 2844 0000  . .A.k".6.l (D..
0001862: 0000 0000 b041 a221 2841 0620 0820 0841  .....A.!(A. . .A
0001872: 0048 1b0b 210c 4100 41c8 0020 0941 0048  .H..!.A.A.. .A.H
0001882: 221b 1b41 0274 221c 2006 41f0 006a 6a22  "..A.t". .A..jj"
0001892: 1021 0503 4020 0502 7f20 2844 0000 0000  .!..@ ... (D....
00018a2: 0000 f041 6320 2844 0000 0000 0000 0000  ...Ac (D........
00018b2: 6671 0440 2028 ab0c 010b 4100 0b22 0436  fq.@ (....A..".6
00018c2: 0200 2005 4104 6a21 0520 2820 04b8 a144  .. .A.j!. ( ...D
00018d2: 0000 0000 65cd cd41 a222 2844 0000 0000  ....e..A."(D....
00018e2: 0000 0000 620d 000b 0240 2009 4100 4c04  ....b....@ .A.L.
00018f2: 4020 0521 0420 1021 070c 010b 2010 2107  @ .!. .!.... .!.
0001902: 0340 411d 2009 2009 411d 4e1b 2109 0240  .@A. . .A.N.!..@
0001912: 2005 4104 6b22 0420 0749 0d00 2009 ad21   .A.k". .I.. ..!
0001922: 2b42 0021 2a03 4020 0420 2a42 ffff ffff  +B.!*.@ . *B....
0001932: 0f83 2004 3502 0020 2b86 7c22 2a20 2a42  .. .5.. +.|"* *B
0001942: 8094 ebdc 0380 222a 4280 94eb dc03 7e7d  ......"*B.....~}
0001952: 3e02 0020 0441 046b 2204 2007 4f0d 000b  >.. .A.k". .O...
0001962: 202a a722 0445 0d00 2007 4104 6b22 0720   *.".E.. .A.k". 
0001972: 0436 0200 0b03 4020 0720 0522 0449 0440  .6....@ . .".I.@
0001982: 2004 4104 6b22 0528 0200 450d 010b 0b20   .A.k".(..E.... 
0001992: 0620 0628 026c 2009 6b22 0936 026c 2004  . .(.l .k".6.l .
00019a2: 2105 2009 4100 4a0d 000b 0b20 0941 0048  !. .A.J.... .A.H
00019b2: 0440 200c 4119 6a41 096e 4101 6a21 1403  .@ .A.jA.nA.j!..
00019c2: 4041 0941 0020 096b 2205 2005 4109 4e1b  @A.A. .k". .A.N.
00019d2: 2108 0240 2004 2007 4d04 4020 0728 0200  !..@ . .M.@ .(..
00019e2: 2105 0c01 0b41 8094 ebdc 0320 0876 2111  !....A..... .v!.
00019f2: 417f 2008 7441 7f73 210d 4100 2109 2007  A. .tA.s!.A.!. .
0001a02: 2105 0340 2005 2005 2802 0022 0b20 0876  !..@ . .(..". .v
0001a12: 2009 6a36 0200 200b 200d 7120 116c 2109   .j6.. . .q .l!.
0001a22: 2005 4104 6a22 0520 0449 0d00 0b20 0728   .A.j". .I... .(
0001a32: 0200 2105 2009 450d 0020 0420 0936 0200  ..!. .E.. . .6..
0001a42: 2004 4104 6a21 040b 2006 2006 2802 6c20   .A.j!.. . .(.l 
0001a52: 086a 2209 3602 6c20 1020 0720 0545 4102  .j".6.l . . .EA.
0001a62: 746a 2207 2016 41e6 0046 1b22 0520 1441  tj". .A..F.". .A
0001a72: 0274 6a20 0420 0420 056b 4102 7520 144a  .tj . . .kA.u .J
0001a82: 1b21 0420 0941 0048 0d00 0b0b 4100 210b  .!. .A.H....A.!.
0001a92: 0240 2004 2007 4d0d 0020 1020 076b 4102  .@ . .M.. . .kA.
0001aa2: 7541 096c 210b 2007 2802 0022 0941 0a49  uA.l!. .(..".A.I
0001ab2: 0d00 410a 2105 0340 200b 4101 6a21 0b20  ..A.!..@ .A.j!. 
0001ac2: 0920 0541 0a6c 2205 4f0d 000b 0b20 0c20  . .A.l".O.... . 
0001ad2: 0b41 0020 1641 e600 471b 6b20 1641 e700  .A. .A..G.k .A..
0001ae2: 4622 0d20 0c41 0047 716b 2205 2004 2010  F". .A.Gqk". . .
0001af2: 6b41 0275 4109 6c41 096b 4804 4020 0541  kA.uA.lA.kH.@ .A
0001b02: 80c8 006a 2209 4109 6d22 0841 0274 2227  ...j".A.m".A.t"'
0001b12: 2006 4101 41c9 0020 1b1b 4102 7422 1b6a   .A.A.. ..A.t".j
0001b22: 6a41 901f 6b21 1141 0a21 0502 4020 0920  jA..k!.A.!..@ . 
0001b32: 0841 096c 6b22 0841 074a 0d00 4108 2008  .A.lk".A.J..A. .
0001b42: 6b22 1441 0771 2109 2008 4101 6b41 074f  k".A.q!. .A.kA.O
0001b52: 0440 2014 4178 7121 0803 4020 0541 80c2  .@ .Axq!..@ .A..
0001b62: d72f 6c21 0520 0841 086b 2208 0d00 0b0b  ./l!. .A.k".....
0001b72: 2009 450d 0003 4020 0541 0a6c 2105 2009   .E...@ .A.l!. .
0001b82: 4101 6b22 090d 000b 0b02 4020 1128 0200  A.k"......@ .(..
0001b92: 2209 2009 2005 6e22 1620 056c 6b22 0845  ". . .n". .lk".E
0001ba2: 2011 4104 6a22 1420 0446 710d 0002 4020   .A.j". .Fq...@ 
0001bb2: 1641 0171 4504 4044 0000 0000 0000 4043  .A.qE.@D......@C
0001bc2: 2128 2005 4180 94eb dc03 470d 0120 0720  !( .A.....G.. . 
0001bd2: 114f 0d01 2011 4104 6b2d 0000 4101 7145  .O.. .A.k-..A.qE
0001be2: 0d01 0b44 0100 0000 0000 4043 2128 0b44  ...D......@C!(.D
0001bf2: 0000 0000 0000 e03f 4400 0000 0000 00f0  .......?D.......
0001c02: 3f44 0000 0000 0000 f83f 2004 2014 461b  ?D.......? . .F.
0001c12: 4400 0000 0000 00f8 3f20 0820 0541 0176  D.......? . .A.v
0001c22: 2214 461b 2008 2014 491b 2129 0240 201e  ".F. . .I.!).@ .
0001c32: 0d00 201a 2d00 0041 2d47 0d00 2029 9a21  .. .-..A-G.. ).!
0001c42: 2920 289a 2128 0b20 1120 0920 086b 2209  ) (.!(. . . .k".
0001c52: 3602 0020 2820 29a0 2028 610d 0020 1120  6.. ( ). (a.. . 
0001c62: 0520 096a 2205 3602 0020 0541 8094 ebdc  . .j".6.. .A....
0001c72: 034f 0440 2021 201b 2027 6a6a 2105 0340  .O.@ ! . 'jj!..@
0001c82: 2005 4104 6a41 0036 0200 2005 2007 4904   .A.jA.6.. . .I.
0001c92: 4020 0741 046b 2207 4100 3602 000b 2005  @ .A.k".A.6... .
0001ca2: 2005 2802 0041 016a 2209 3602 0020 0541   .(..A.j".6.. .A
0001cb2: 046b 2105 2009 41ff 93eb dc03 4b0d 000b  .k!. .A.....K...
0001cc2: 2005 4104 6a21 110b 2010 2007 6b41 0275   .A.j!.. . .kA.u
0001cd2: 4109 6c21 0b20 0728 0200 2209 410a 490d  A.l!. .(..".A.I.
0001ce2: 0041 0a21 0503 4020 0b41 016a 210b 2009  .A.!..@ .A.j!. .
0001cf2: 2005 410a 6c22 054f 0d00 0b0b 2011 4104   .A.l".O.... .A.
0001d02: 6a22 0520 0420 0420 054b 1b21 040b 2004  j". . . .K.!.. .
0001d12: 2020 6a20 1c6b 2105 0340 0240 2005 2109    j .k!..@.@ .!.
0001d22: 2004 2211 2007 4d22 080d 0020 0541 046b   .". .M"... .A.k
0001d32: 2105 2004 4104 6b22 0428 0200 450d 010b  !. .A.k".(..E...
0001d42: 0b02 4020 0d45 0440 200e 4108 7121 140c  ..@ .E.@ .A.q!..
0001d52: 010b 200b 417f 7341 7f20 0c41 0120 0c1b  .. .A.sA. .A. ..
0001d62: 2204 200b 4a20 0b41 7b4a 7122 051b 2004  ". .J .A{Jq".. .
0001d72: 6a21 0c41 7f41 7e20 051b 2013 6a21 1320  j!.A.A~ .. .j!. 
0001d82: 0e41 0871 2214 0d00 4177 2104 0240 2008  .A.q"...Aw!..@ .
0001d92: 0d00 2011 4104 6b28 0200 2208 450d 0041  .. .A.k(..".E..A
0001da2: 0021 0420 0841 0a70 0d00 410a 2105 0340  .!. .A.p..A.!..@
0001db2: 2004 4101 6b21 0420 0820 0541 0a6c 2205   .A.k!. . .A.l".
0001dc2: 7045 0d00 0b0b 2009 4102 7541 096c 4109  pE.... .A.uA.lA.
0001dd2: 6b21 0520 1341 5f71 41c6 0046 0440 4100  k!. .A_qA..F.@A.
0001de2: 2114 200c 2004 2005 6a22 0441 0020 0441  !. . . .j".A. .A
0001df2: 004a 1b22 0420 0420 0c4a 1b21 0c0c 010b  .J.". . .J.!....
0001e02: 4100 2114 200c 2005 200b 6a20 046a 2204  A.!. . . .j .j".
0001e12: 4100 2004 4100 4a1b 2204 2004 200c 4a1b  A. .A.J.". . .J.
0001e22: 210c 0b20 0c41 fdff ffff 0741 feff ffff  !.. .A.....A....
0001e32: 0720 0c20 1472 221e 1b4a 0d07 200c 201e  . . .r"..J.. . .
0001e42: 4100 476a 4101 6a21 1602 4020 1341 5f71  A.GjA.j!..@ .A_q
0001e52: 41c6 0047 221b 4504 4020 0b20 1641 ffff  A..G".E.@ . .A..
0001e62: ffff 0773 4a0d 0920 0b41 0020 0b41 004a  ...sJ.. .A. .A.J
0001e72: 1b21 040c 010b 0240 200b 4504 4020 1822  .!.....@ .E.@ ."
0001e82: 0921 050c 010b 200b 200b 411f 7522 0473  .!.... . .A.u".s
0001e92: 2004 6b21 0420 1822 0921 0503 4020 0541   .k!. .".!..@ .A
0001ea2: 016b 2205 2004 2004 410a 6e22 0841 0a6c  .k". . .A.n".A.l
0001eb2: 6b41 3072 3a00 0020 0941 016b 2109 2004  kA0r:.. .A.k!. .
0001ec2: 4109 4b21 0d20 0821 0420 0d0d 000b 0b20  A.K!. .!. ..... 
0001ed2: 1820 096b 4101 4c04 4020 0520 2620 096b  . .kA.L.@ . & .k
0001ee2: 6a22 0541 3020 0920 256a 1012 1a0b 2005  j".A0 . %j.... .
0001ef2: 4102 6b22 1c20 133a 0000 2005 4101 6b41  A.k". .:.. .A.kA
0001f02: 2d41 2b20 0b41 0048 1b3a 0000 2018 201c  -A+ .A.H.:.. . .
0001f12: 6b22 0420 1641 ffff ffff 0773 4a0d 080b  k". .A.....sJ...
0001f22: 2004 2016 6a22 0420 1741 ffff ffff 0773   . .j". .A.....s
0001f32: 4a0d 0720 0420 176a 210d 0240 200e 4180  J.. . .j!..@ .A.
0001f42: c004 7122 0e0d 0020 0d20 0f4e 0d00 2006  ..q"... . .N.. .
0001f52: 41f0 046a 4120 200f 200d 6b22 0441 8002  A..jA  . .k".A..
0001f62: 2004 4180 0249 2205 1b10 121a 2005 4504   .A..I"..... .E.
0001f72: 4003 4020 002d 0000 4120 7145 0440 2006  @.@ .-..A qE.@ .
0001f82: 41f0 046a 4180 0220 0010 0b0b 2004 4180  A..jA.. .... .A.
0001f92: 026b 2204 41ff 014b 0d00 0b0b 2000 2d00  .k".A..K.... .-.
0001fa2: 0041 2071 0d00 2006 41f0 046a 2004 2000  .A q.. .A..j . .
0001fb2: 100b 0b20 002d 0000 4120 7145 0440 201a  ... .-..A qE.@ .
0001fc2: 2017 2000 100b 0b02 4020 0e41 8080 0447   . .....@ .A...G
0001fd2: 0d00 200d 200f 4e0d 0020 0641 f004 6a41  .. . .N.. .A..jA
0001fe2: 3020 0f20 0d6b 2204 4180 0220 0441 8002  0 . .k".A.. .A..
0001ff2: 4922 051b 1012 1a20 0545 0440 0340 2000  I"..... .E.@.@ .
0002002: 2d00 0041 2071 4504 4020 0641 f004 6a41  -..A qE.@ .A..jA
0002012: 8002 2000 100b 0b20 0441 8002 6b22 0441  .. .... .A..k".A
0002022: ff01 4b0d 000b 0b20 002d 0000 4120 710d  ..K.... .-..A q.
0002032: 0020 0641 f004 6a20 0420 0010 0b0b 201b  . .A..j . .... .
0002042: 0d03 2010 2007 2007 2010 4b1b 220b 2108  .. . . . .K.".!.
0002052: 0340 0240 0240 0240 2008 2802 0022 0404  .@.@.@.@ .(.."..
0002062: 4041 0821 0503 4020 0641 d000 6a20 056a  @A.!..@ .A..j .j
0002072: 2004 2004 410a 6e22 0741 0a6c 6b41 3072   . .A.n".A.lkA0r
0002082: 3a00 0020 0541 016b 2105 2004 4109 4b21  :.. .A.k!. .A.K!
0002092: 0920 0721 0420 090d 000b 2005 4101 6a22  . .!. .... .A.j"
00020a2: 0720 0641 d000 6a6a 2104 2008 200b 4704  . .A..jj!. . .G.
00020b2: 4020 0541 026a 4102 480d 040c 030b 2005  @ .A.jA.H..... .
00020c2: 4108 470d 030c 010b 4109 2107 2008 200b  A.G.....A.!. . .
00020d2: 470d 010b 2006 4130 3a00 5820 1f21 040c  G... .A0:.X .!..
00020e2: 010b 2006 41d0 006a 2007 2006 41d0 006a  .. .A..j . .A..j
00020f2: 6a22 0541 016b 2204 2006 41d0 006a 2004  j".A.k". .A..j .
0002102: 491b 2204 4130 2005 2004 6b10 121a 0b20  I.".A0 . .k.... 
0002112: 002d 0000 4120 7145 0440 2004 201d 2004  .-..A qE.@ . . .
0002122: 6b20 0010 0b0b 2008 4104 6a22 0820 104d  k .... .A.j". .M
0002132: 0d00 0b02 4020 1e45 0d00 2000 2d00 0041  ....@ .E.. .-..A
0002142: 2071 0d00 41ad 0841 0120 0010 0b0b 0240   q..A..A. .....@
0002152: 2008 2011 4f04 4020 0c21 040c 010b 200c   . .O.@ .!.... .
0002162: 4100 4c04 4020 0c21 040c 010b 0340 0240  A.L.@ .!.....@.@
0002172: 0240 2008 2802 0022 0445 0440 201d 2205  .@ .(..".E.@ .".
0002182: 2107 0c01 0b20 1d22 0721 0503 4020 0541  !.... .".!..@ .A
0002192: 016b 2205 2004 2004 410a 6e22 0941 0a6c  .k". . .A.n".A.l
00021a2: 6b41 3072 3a00 0020 0741 016b 2107 2004  kA0r:.. .A.k!. .
00021b2: 4109 4b21 0b20 0921 0420 0b0d 000b 2005  A.K!. .!. .... .
00021c2: 2006 41d0 006a 4d0d 010b 2005 2006 41d0   .A..jM... . .A.
00021d2: 006a 6a20 076b 2205 4130 2007 2006 41d0  .jj .k".A0 . .A.
00021e2: 006a 6b10 121a 0b20 002d 0000 4120 7145  .jk.... .-..A qE
00021f2: 0440 2005 4109 200c 200c 4109 4e1b 2000  .@ .A. . .A.N. .
0002202: 100b 0b20 0c41 096b 2104 2008 4104 6a22  ... .A.k!. .A.j"
0002212: 0820 114f 0d01 200c 4109 4a21 0520 0421  . .O.. .A.J!. .!
0002222: 0c20 050d 000b 0b20 0020 0441 096a 4109  . ..... . .A.jA.
0002232: 1010 0c04 0b41 d41c 411c 3602 000c 080b  .....A..A.6.....
0002242: 4100 210d 4180 0821 1020 1521 0420 0e21  A.!.A..!. .!. .!
0002252: 1120 0821 0b0b 200b 2004 2009 6b22 0820  . .!.. . . .k". 
0002262: 0820 0b48 1b22 0c20 0d41 ffff ffff 0773  . .H.". .A.....s
0002272: 4a0d 0420 0f20 0c20 0d6a 2207 2007 200f  J.. . . .j". . .
0002282: 481b 2204 2005 4a0d 0402 4020 1141 80c0  H.". .J...@ .A..
0002292: 0471 2211 0d00 2007 200f 4e0d 0020 0641  .q"... . .N.. .A
00022a2: f000 6a41 2020 0420 076b 2205 4180 0220  ..jA  . .k".A.. 
00022b2: 0541 8002 4922 0e1b 1012 1a20 0e45 0440  .A..I"..... .E.@
00022c2: 0340 2000 2d00 0041 2071 4504 4020 0641  .@ .-..A qE.@ .A
00022d2: f000 6a41 8002 2000 100b 0b20 0541 8002  ..jA.. .... .A..
00022e2: 6b22 0541 ff01 4b0d 000b 0b20 002d 0000  k".A..K.... .-..
00022f2: 4120 710d 0020 0641 f000 6a20 0520 0010  A q.. .A..j . ..
0002302: 0b0b 2000 2d00 0041 2071 4504 4020 1020  .. .-..A qE.@ . 
0002312: 0d20 0010 0b0b 0240 2011 4180 8004 470d  . .....@ .A...G.
0002322: 0020 0720 0f4e 0d00 2006 41f0 006a 4130  . . .N.. .A..jA0
0002332: 2004 2007 6b22 0541 8002 2005 4180 0249   . .k".A.. .A..I
0002342: 220d 1b10 121a 200d 4504 4003 4020 002d  "..... .E.@.@ .-
0002352: 0000 4120 7145 0440 2006 41f0 006a 4180  ..A qE.@ .A..jA.
0002362: 0220 0010 0b0b 2005 4180 026b 2205 41ff  . .... .A..k".A.
0002372: 014b 0d00 0b0b 2000 2d00 0041 2071 0d00  .K.... .-..A q..
0002382: 2006 41f0 006a 2005 2000 100b 0b02 4020   .A..j . .....@ 
0002392: 0820 0b4e 0d00 2006 41f0 006a 4130 200c  . .N.. .A..jA0 .
00023a2: 2008 6b22 0541 8002 2005 4180 0249 220b   .k".A.. .A..I".
00023b2: 1b10 121a 200b 4504 4003 4020 002d 0000  .... .E.@.@ .-..
00023c2: 4120 7145 0440 2006 41f0 006a 4180 0220  A qE.@ .A..jA.. 
00023d2: 0010 0b0b 2005 4180 026b 2205 41ff 014b  .... .A..k".A..K
00023e2: 0d00 0b0b 2000 2d00 0041 2071 0d00 2006  .... .-..A q.. .
00023f2: 41f0 006a 2005 2000 100b 0b20 002d 0000  A..j . .... .-..
0002402: 4120 7145 0440 2009 2008 2000 100b 0b20  A qE.@ . . .... 
0002412: 1141 80c0 0047 0d05 2007 200f 4e0d 0520  .A...G.. . .N.. 
0002422: 0641 f000 6a41 2020 0420 076b 2205 4180  .A..jA  . .k".A.
0002432: 0220 0541 8002 4922 071b 1012 1a20 0745  . .A..I"..... .E
0002442: 0440 0340 2000 2d00 0041 2071 4504 4020  .@.@ .-..A qE.@ 
0002452: 0641 f000 6a41 8002 2000 100b 0b20 0541  .A..jA.. .... .A
0002462: 8002 6b22 0541 ff01 4b0d 000b 0b20 002d  ..k".A..K.... .-
0002472: 0000 4120 710d 0520 0641 f000 6a20 0520  ..A q.. .A..j . 
0002482: 0010 0b0c 050b 0240 200c 4100 480d 0020  .......@ .A.H.. 
0002492: 1120 0741 046a 2007 2011 491b 2111 2007  . .A.j . .I.!. .
00024a2: 2108 0340 027f 0240 2008 2802 0022 0445  !..@...@ .(..".E
00024b2: 0d00 4100 2105 0340 2005 2006 6a41 d800  ..A.!..@ . .jA..
00024c2: 6a20 0420 0441 0a6e 2209 410a 6c6b 4130  j . .A.n".A.lkA0
00024d2: 723a 0000 2005 4101 6b21 0520 0441 094b  r:.. .A.k!. .A.K
00024e2: 210b 2009 2104 200b 0d00 0b20 0545 0d00  !. .!. .... .E..
00024f2: 2005 2006 6a41 d900 6a0c 010b 2006 4130   . .jA..j... .A0
0002502: 3a00 5820 1f0b 2104 0240 2007 2008 4704  :.X ..!..@ . .G.
0002512: 4020 0420 0641 d000 6a4d 0d01 2006 41d0  @ . .A..jM.. .A.
0002522: 006a 4130 2004 2006 41d0 006a 6b10 121a  .jA0 . .A..jk...
0002532: 2006 41d0 006a 2104 0c01 0b20 002d 0000   .A..j!.... .-..
0002542: 4120 7145 0440 2004 4101 2000 100b 0b20  A qE.@ .A. .... 
0002552: 0441 016a 2104 2014 4520 0c41 004c 710d  .A.j!. .E .A.Lq.
0002562: 0020 002d 0000 4120 710d 0041 ad08 4101  . .-..A q..A..A.
0002572: 2000 100b 0b20 1d20 046b 2105 2000 2d00   .... . .k!. .-.
0002582: 0041 2071 4504 4020 0420 0c20 0520 0520  .A qE.@ . . . . 
0002592: 0c4a 1b20 0010 0b0b 200c 2005 6b21 0c20  .J. .... . .k!. 
00025a2: 0841 046a 2208 2011 4f0d 0120 0c41 004e  .A.j". .O.. .A.N
00025b2: 0d00 0b0b 2000 200c 4112 6a41 1210 1020  .... . .A.jA... 
00025c2: 002d 0000 4120 710d 0020 1c20 1820 1c6b  .-..A q.. . . .k
00025d2: 2000 100b 0b20 0e41 80c0 0047 0d01 200d   .... .A...G.. .
00025e2: 200f 4e0d 0120 0641 f004 6a41 2020 0f20   .N.. .A..jA  . 
00025f2: 0d6b 2204 4180 0220 0441 8002 4922 051b  .k".A.. .A..I"..
0002602: 1012 1a20 0545 0440 0340 2000 2d00 0041  ... .E.@.@ .-..A
0002612: 2071 4504 4020 0641 f004 6a41 8002 2000   qE.@ .A..jA.. .
0002622: 100b 0b20 0441 8002 6b22 0441 ff01 4b0d  ... .A..k".A..K.
0002632: 000b 0b20 002d 0000 4120 710d 0120 0641  ... .-..A q.. .A
0002642: f004 6a20 0420 0010 0b0c 010b 201a 2013  ..j . ...... . .
0002652: 411a 7441 1f75 4109 716a 2110 0240 2008  A.tA.uA.qj!..@ .
0002662: 410b 4b0d 0002 4041 0c20 086b 2204 4107  A.K...@A. .k".A.
0002672: 7122 0545 0440 4400 0000 0000 0030 4021  q".E.@D......0@!
0002682: 290c 010b 2008 410c 6b21 0444 0000 0000  )... .A.k!.D....
0002692: 0000 3040 2129 0340 2004 4101 6a21 0420  ..0@!).@ .A.j!. 
00026a2: 2944 0000 0000 0000 3040 a221 2920 0541  )D......0@.!) .A
00026b2: 016b 2205 0d00 0b41 0020 046b 2104 0b20  .k"....A. .k!.. 
00026c2: 0841 056b 4107 4f04 4003 4020 2944 0000  .A.kA.O.@.@ )D..
00026d2: 0000 0000 3040 a244 0000 0000 0000 3040  ....0@.D......0@
00026e2: a244 0000 0000 0000 3040 a244 0000 0000  .D......0@.D....
00026f2: 0000 3040 a244 0000 0000 0000 3040 a244  ..0@.D......0@.D
0002702: 0000 0000 0000 3040 a244 0000 0000 0000  ......0@.D......
0002712: 3040 a244 0000 0000 0000 3040 a221 2920  0@.D......0@.!) 
0002722: 0441 086b 2204 0d00 0b0b 2010 2d00 0041  .A.k"..... .-..A
0002732: 2d46 0440 2029 2028 9a20 29a1 a09a 2128  -F.@ ) (. )...!(
0002742: 0c01 0b20 2820 29a0 2029 a121 280b 027f  ... ( ). ).!(...
0002752: 0240 2006 2802 6c22 0b45 0d00 200b 200b  .@ .(.l".E.. . .
0002762: 411f 7522 0473 2004 6b21 0441 0021 0503  A.u".s .k!.A.!..
0002772: 4020 0520 066a 41cf 006a 2004 2004 410a  @ . .jA..j . .A.
0002782: 6e22 0741 0a6c 6b41 3072 3a00 0020 0541  n".A.lkA0r:.. .A
0002792: 016b 2105 2004 4109 4b21 0920 0721 0420  .k!. .A.K!. .!. 
00027a2: 090d 000b 2005 450d 0020 0520 066a 41d0  .... .E.. . .jA.
00027b2: 006a 0c01 0b20 0641 303a 004f 2024 0b21  .j... .A0:.O $.!
00027c2: 0420 1741 0272 210c 2013 4120 7121 0720  . .A.r!. .A q!. 
00027d2: 0441 026b 2211 2013 410f 6a3a 0000 2004  .A.k". .A.j:.. .
00027e2: 4101 6b41 2d41 2b20 0b41 0048 1b3a 0000  A.kA-A+ .A.H.:..
00027f2: 200e 4108 7121 0920 0641 d000 6a21 0503   .A.q!. .A..j!..
0002802: 4020 0522 0402 7f20 2899 4400 0000 0000  @ ."... (.D.....
0002812: 00e0 4163 0440 2028 aa0c 010b 4180 8080  ..Ac.@ (....A...
0002822: 8078 0b22 0541 d01a 6a2d 0000 2007 723a  .x.".A..j-.. .r:
0002832: 0000 2028 2005 b7a1 4400 0000 0000 0030  .. ( ...D......0
0002842: 40a2 2128 0240 2004 4101 6a22 0520 0641  @.!(.@ .A.j". .A
0002852: d000 6a6b 4101 470d 0002 4020 090d 0020  ..jkA.G...@ ... 
0002862: 0841 004a 0d00 2028 4400 0000 0000 0000  .A.J.. (D.......
0002872: 0061 0d01 0b20 0441 2e3a 0001 2004 4102  .a... .A.:.. .A.
0002882: 6a21 050b 2028 4400 0000 0000 0000 0062  j!.. (D........b
0002892: 0d00 0b41 fdff ffff 0720 1820 116b 220b  ...A..... . .k".
00028a2: 200c 6a22 046b 2008 480d 0120 0841 026a   .j".k .H.. .A.j
00028b2: 2005 2006 41d0 006a 6b22 0720 0520 236a   . .A..jk". . #j
00028c2: 2008 481b 2007 2008 1b22 0920 046a 210d   .H. . ..". .j!.
00028d2: 0240 200e 4180 c004 7122 050d 0020 0d20  .@ .A...q"... . 
00028e2: 0f4e 0d00 2006 41f0 046a 4120 200f 200d  .N.. .A..jA  . .
00028f2: 6b22 0441 8002 2004 4180 0249 2208 1b10  k".A.. .A..I"...
0002902: 121a 2008 4504 4003 4020 002d 0000 4120  .. .E.@.@ .-..A 
0002912: 7145 0440 2006 41f0 046a 4180 0220 0010  qE.@ .A..jA.. ..
0002922: 0b0b 2004 4180 026b 2204 41ff 014b 0d00  .. .A..k".A..K..
0002932: 0b0b 2000 2d00 0041 2071 0d00 2006 41f0  .. .-..A q.. .A.
0002942: 046a 2004 2000 100b 0b20 002d 0000 4120  .j . .... .-..A 
0002952: 7145 0440 2010 200c 2000 100b 0b02 4020  qE.@ . . .....@ 
0002962: 0541 8080 0447 0d00 200d 200f 4e0d 0020  .A...G.. . .N.. 
0002972: 0641 f004 6a41 3020 0f20 0d6b 2204 4180  .A..jA0 . .k".A.
0002982: 0220 0441 8002 4922 081b 1012 1a20 0845  . .A..I"..... .E
0002992: 0440 0340 2000 2d00 0041 2071 4504 4020  .@.@ .-..A qE.@ 
00029a2: 0641 f004 6a41 8002 2000 100b 0b20 0441  .A..jA.. .... .A
00029b2: 8002 6b22 0441 ff01 4b0d 000b 0b20 002d  ..k".A..K.... .-
00029c2: 0000 4120 710d 0020 0641 f004 6a20 0420  ..A q.. .A..j . 
00029d2: 0010 0b0b 2000 2d00 0041 2071 4504 4020  .... .-..A qE.@ 
00029e2: 0641 d000 6a20 0720 0010 0b0b 0240 2009  .A..j . .....@ .
00029f2: 2007 6b22 0441 004c 0d00 2006 41f0 046a   .k".A.L.. .A..j
0002a02: 4130 2004 4180 0220 0441 8002 4922 071b  A0 .A.. .A..I"..
0002a12: 1012 1a20 0745 0440 0340 2000 2d00 0041  ... .E.@.@ .-..A
0002a22: 2071 4504 4020 0641 f004 6a41 8002 2000   qE.@ .A..jA.. .
0002a32: 100b 0b20 0441 8002 6b22 0441 ff01 4b0d  ... .A..k".A..K.
0002a42: 000b 0b20 002d 0000 4120 710d 0020 0641  ... .-..A q.. .A
0002a52: f004 6a20 0420 0010 0b0b 2000 2d00 0041  ..j . .... .-..A
0002a62: 2071 4504 4020 1120 0b20 0010 0b0b 2005   qE.@ . . .... .
0002a72: 4180 c000 470d 0020 0d20 0f4e 0d00 2006  A...G.. . .N.. .
0002a82: 41f0 046a 4120 200f 200d 6b22 0441 8002  A..jA  . .k".A..
0002a92: 2004 4180 0249 2205 1b10 121a 2005 4504   .A..I"..... .E.
0002aa2: 4003 4020 002d 0000 4120 7145 0440 2006  @.@ .-..A qE.@ .
0002ab2: 41f0 046a 4180 0220 0010 0b0b 2004 4180  A..jA.. .... .A.
0002ac2: 026b 2204 41ff 014b 0d00 0b0b 2000 2d00  .k".A..K.... .-.
0002ad2: 0041 2071 0d00 2006 41f0 046a 2004 2000  .A q.. .A..j . .
0002ae2: 100b 0b20 0d20 0f20 0d20 0f4a 1b22 0441  ... . . . .J.".A
0002af2: 004e 0d01 0b0b 41d4 1c41 3d36 0200 0b41  .N....A..A=6...A
0002b02: 7f21 120b 2006 41f0 066a 2400 2012 0bc9  .!.. .A..j$. ...
0002b12: 0601 037f 0240 0240 0240 0240 0240 0240  .....@.@.@.@.@.@
0002b22: 0240 0240 0240 0240 0240 0240 0240 0240  .@.@.@.@.@.@.@.@
0002b32: 0240 0240 0240 0240 0240 2001 4109 6b0e  .@.@.@.@.@ .A.k.
0002b42: 1211 0001 0402 0305 0607 0809 0a0b 0c0d  ................
0002b52: 0e0f 1012 0b20 0220 0228 0200 2201 4104  ..... . .(..".A.
0002b62: 6a36 0200 2000 2001 3402 0037 0300 0f0b  j6.. . .4..7....
0002b72: 2002 2002 2802 0022 0141 046a 3602 0020   . .(..".A.j6.. 
0002b82: 0020 0135 0200 3703 000f 0b20 0220 0228  . .5..7.... . .(
0002b92: 0200 2201 4104 6a36 0200 2000 2001 3402  ..".A.j6.. . .4.
0002ba2: 0037 0300 0f0b 2002 2002 2802 0022 0141  .7.... . .(..".A
0002bb2: 046a 3602 0020 0020 0135 0200 3703 000f  .j6.. . .5..7...
0002bc2: 0b20 0220 0228 0200 4107 6a41 7871 2201  . . .(..A.jAxq".
0002bd2: 4108 6a36 0200 2000 2001 2903 0037 0300  A.j6.. . .)..7..
0002be2: 0f0b 2002 2002 2802 0022 0141 046a 3602  .. . .(..".A.j6.
0002bf2: 0020 0020 0132 0100 3703 000f 0b20 0220  . . .2..7.... . 
0002c02: 0228 0200 2201 4104 6a36 0200 2000 2001  .(..".A.j6.. . .
0002c12: 3301 0037 0300 0f0b 2002 2002 2802 0022  3..7.... . .(.."
0002c22: 0141 046a 3602 0020 0020 0130 0000 3703  .A.j6.. . .0..7.
0002c32: 000f 0b20 0220 0228 0200 2201 4104 6a36  ... . .(..".A.j6
0002c42: 0200 2000 2001 3100 0037 0300 0f0b 2002  .. . .1..7.... .
0002c52: 2002 2802 0041 076a 4178 7122 0141 086a   .(..A.jAxq".A.j
0002c62: 3602 0020 0020 0129 0300 3703 000f 0b20  6.. . .)..7.... 
0002c72: 0220 0228 0200 2201 4104 6a36 0200 2000  . .(..".A.j6.. .
0002c82: 2001 3502 0037 0300 0f0b 2002 2002 2802   .5..7.... . .(.
0002c92: 0041 076a 4178 7122 0141 086a 3602 0020  .A.jAxq".A.j6.. 
0002ca2: 0020 0129 0300 3703 000f 0b20 0220 0228  . .)..7.... . .(
0002cb2: 0200 4107 6a41 7871 2201 4108 6a36 0200  ..A.jAxq".A.j6..
0002cc2: 2000 2001 2903 0037 0300 0f0b 2002 2002   . .)..7.... . .
0002cd2: 2802 0022 0141 046a 3602 0020 0020 0134  (..".A.j6.. . .4
0002ce2: 0200 3703 000f 0b20 0220 0228 0200 2201  ..7.... . .(..".
0002cf2: 4104 6a36 0200 2000 2001 3502 0037 0300  A.j6.. . .5..7..
0002d02: 0f0b 2002 2002 2802 0041 076a 4178 7122  .. . .(..A.jAxq"
0002d12: 0141 086a 3602 0020 0020 012b 0300 3903  .A.j6.. . .+..9.
0002d22: 000f 0b41 bf08 2100 0340 2000 4105 6a21  ...A..!..@ .A.j!
0002d32: 0120 0041 046a 2100 2001 2802 0022 0141  . .A.j!. .(..".A
0002d42: 7f73 2001 4181 8284 086b 7141 8081 8284  .s .A....kqA....
0002d52: 7871 450d 000b 0340 2000 4101 6a22 002d  xqE....@ .A.j".-
0002d62: 0000 0d00 0b20 0041 c408 6b21 0141 c408  ..... .A..k!.A..
0002d72: 2102 0240 2001 41e8 1b28 0200 2200 047f  !..@ .A..(.."...
0002d82: 2000 0541 d81b 100a 0d01 41e8 1b28 0200   ..A......A..(..
0002d92: 0b41 ec1b 2802 0022 036b 4b04 4041 d81b  .A..(..".kK.@A..
0002da2: 41c4 0820 0141 f81b 2802 0011 0000 1a0c  A.. .A..(.......
0002db2: 010b 027f 2001 4198 1c28 0200 4100 480d  .... .A..(..A.H.
0002dc2: 001a 2001 41c4 086a 2104 4100 2100 0340  .. .A..j!.A.!..@
0002dd2: 2001 2000 2001 6a45 0d01 1a20 0041 016b   . . .jE... .A.k
0002de2: 2200 2004 6a22 052d 0000 410a 470d 000b  ". .j".-..A.G...
0002df2: 41d8 1b41 c408 2000 2001 6a41 016a 2201  A..A.. . .jA.j".
0002e02: 41f8 1b28 0200 1100 0020 0149 0d01 2005  A..(..... .I.. .
0002e12: 4101 6a21 0241 ec1b 2802 0021 0320 0041  A.j!.A..(..!. .A
0002e22: 7f73 0b21 0020 0320 0220 0010 1141 ec1b  .s.!. . . ...A..
0002e32: 41ec 1b28 0200 2000 6a36 0200 0b00 0b20  A..(.. .j6..... 
0002e42: 0220 0228 0200 2201 4104 6a36 0200 2000  . .(..".A.j6.. .
0002e52: 2001 2802 0036 0200 0b0b 7901 027f 2300   .(..6....y...#.
0002e62: 4180 026b 2203 2400 0240 2001 2002 4c0d  A..k".$..@ . .L.
0002e72: 0020 0341 3020 0120 026b 2202 4180 0220  . .A0 . .k".A.. 
0002e82: 0241 8002 4922 041b 1012 2101 2004 4504  .A..I"....!. .E.
0002e92: 4003 4020 002d 0000 4120 7145 0440 2001  @.@ .-..A qE.@ .
0002ea2: 4180 0220 0010 0b0b 2002 4180 026b 2202  A.. .... .A..k".
0002eb2: 41ff 014b 0d00 0b0b 2000 2d00 0041 2071  A..K.... .-..A q
0002ec2: 0d00 2001 2002 2000 100b 0b20 0341 8002  .. . . .... .A..
0002ed2: 6a24 000b c207 0103 7f02 4002 4020 0241  j$........@.@ .A
0002ee2: 204d 0440 2001 4103 7145 0d01 2002 450d   M.@ .A.qE.. .E.
0002ef2: 0120 0020 012d 0000 3a00 0020 0241 016b  . . .-..:.. .A.k
0002f02: 2105 2000 4101 6a21 0320 0141 016a 2204  !. .A.j!. .A.j".
0002f12: 4103 7145 0d02 2005 450d 0220 0020 012d  A.qE.. .E.. . .-
0002f22: 0001 3a00 0120 0241 026b 2105 2000 4102  ..:.. .A.k!. .A.
0002f32: 6a21 0320 0141 026a 2204 4103 7145 0d02  j!. .A.j".A.qE..
0002f42: 2005 450d 0220 0020 012d 0002 3a00 0220   .E.. . .-..:.. 
0002f52: 0241 036b 2105 2000 4103 6a21 0320 0141  .A.k!. .A.j!. .A
0002f62: 036a 2204 4103 7145 0d02 2005 450d 0220  .j".A.qE.. .E.. 
0002f72: 0020 012d 0003 3a00 0320 0241 046b 2105  . .-..:.. .A.k!.
0002f82: 2000 4104 6a21 0320 0141 046a 2104 0c02   .A.j!. .A.j!...
0002f92: 0b20 0020 0120 02fc 0a00 000f 0b20 0221  . . . ....... .!
0002fa2: 0520 0021 0320 0121 040b 0240 2003 4103  . .!. .!...@ .A.
0002fb2: 7122 0245 0440 0240 2005 4110 4904 4020  q".E.@.@ .A.I.@ 
0002fc2: 0521 020c 010b 2005 4110 6b22 0241 1071  .!.... .A.k".A.q
0002fd2: 4504 4020 0320 0429 0200 3702 0020 0320  E.@ . .)..7.. . 
0002fe2: 0429 0208 3702 0820 0341 106a 2103 2004  .)..7.. .A.j!. .
0002ff2: 4110 6a21 0420 0221 050b 2002 4110 490d  A.j!. .!.. .A.I.
0003002: 0020 0521 0203 4020 0320 0429 0200 3702  . .!..@ . .)..7.
0003012: 0020 0320 0429 0208 3702 0820 0320 0429  . . .)..7.. . .)
0003022: 0210 3702 1020 0320 0429 0218 3702 1820  ..7.. . .)..7.. 
0003032: 0341 206a 2103 2004 4120 6a21 0420 0241  .A j!. .A j!. .A
0003042: 206b 2202 410f 4b0d 000b 0b20 0241 084f   k".A.K.... .A.O
0003052: 0440 2003 2004 2902 0037 0200 2004 4108  .@ . .)..7.. .A.
0003062: 6a21 0420 0341 086a 2103 0b20 0241 0471  j!. .A.j!.. .A.q
0003072: 0440 2003 2004 2802 0036 0200 2004 4104  .@ . .(..6.. .A.
0003082: 6a21 0420 0341 046a 2103 0b20 0241 0271  j!. .A.j!.. .A.q
0003092: 0440 2003 2004 2f00 003b 0000 2004 4102  .@ . ./..;.. .A.
00030a2: 6a21 0420 0341 026a 2103 0b20 0241 0171  j!. .A.j!.. .A.q
00030b2: 450d 0120 0320 042d 0000 3a00 000f 0b02  E.. . .-..:.....
00030c2: 4002 4002 7f02 4020 0541 204f 0440 0240  @.@...@ .A O.@.@
00030d2: 0240 2002 4101 6b0e 0303 0001 070b 2003  .@ .A.k....... .
00030e2: 2004 2802 003b 0000 2003 2004 4102 6a28   .(..;.. . .A.j(
00030f2: 0100 3602 0220 0320 0441 066a 2901 0037  ..6.. . .A.j)..7
0003102: 0206 2004 4112 6a21 0141 0e21 0020 0441  .. .A.j!.A.!. .A
0003112: 0e6a 2801 0021 0441 0e21 0520 0341 126a  .j(..!.A.!. .A.j
0003122: 0c03 0b20 0320 0428 0200 3a00 0020 0320  ... . .(..:.. . 
0003132: 0441 016a 2800 0036 0201 2003 2004 4105  .A.j(..6.. . .A.
0003142: 6a29 0000 3702 0520 0441 116a 2101 410d  j)..7.. .A.j!.A.
0003152: 2100 2004 410d 6a28 0000 2104 410f 2105  !. .A.j(..!.A.!.
0003162: 2003 4111 6a0c 020b 027f 2005 4110 4904   .A.j..... .A.I.
0003172: 4020 0321 0220 040c 010b 2003 2004 2d00  @ .!. .... . .-.
0003182: 003a 0000 2003 2004 2800 0136 0001 2003  .:.. . .(..6.. .
0003192: 2004 2900 0537 0005 2003 2004 2f00 0d3b   .)..7.. . ./..;
00031a2: 000d 2003 2004 2d00 0f3a 000f 2003 4110  .. . .-..:.. .A.
00031b2: 6a21 0220 0441 106a 0b21 0120 0541 0871  j!. .A.j.!. .A.q
00031c2: 0d02 0c03 0b20 0320 0428 0200 2202 3a00  ..... . .(..".:.
00031d2: 0020 0320 0241 1076 3a00 0220 0320 0241  . . .A.v:.. . .A
00031e2: 0876 3a00 0120 0320 0441 036a 2800 0036  .v:.. . .A.j(..6
00031f2: 0203 2003 2004 4107 6a29 0000 3702 0720  .. . .A.j)..7.. 
0003202: 0441 136a 2101 410f 2100 2004 410f 6a28  .A.j!.A.!. .A.j(
0003212: 0000 2104 410d 2105 2003 4113 6a0b 2102  ..!.A.!. .A.j.!.
0003222: 2000 2003 6a20 0436 0200 0b20 0220 0129   . .j .6... . .)
0003232: 0000 3700 0020 0241 086a 2102 2001 4108  ..7.. .A.j!. .A.
0003242: 6a21 010b 2005 4104 7104 4020 0220 0128  j!.. .A.q.@ . .(
0003252: 0000 3600 0020 0241 046a 2102 2001 4104  ..6.. .A.j!. .A.
0003262: 6a21 010b 2005 4102 7104 4020 0220 012f  j!.. .A.q.@ . ./
0003272: 0000 3b00 0020 0241 026a 2102 2001 4102  ..;.. .A.j!. .A.
0003282: 6a21 010b 2005 4101 7145 0d00 2002 2001  j!.. .A.qE.. . .
0003292: 2d00 003a 0000 0b0b 8603 0203 7f01 7e20  -..:..........~ 
00032a2: 0241 214f 0440 2000 2001 2002 fc0b 0020  .A!O.@ . . .... 
00032b2: 000f 0b02 4020 0245 0d00 2000 2001 3a00  ....@ .E.. . .:.
00032c2: 0020 0020 026a 2203 4101 6b20 013a 0000  . . .j".A.k .:..
00032d2: 2002 4103 490d 0020 0020 013a 0002 2000   .A.I.. . .:.. .
00032e2: 2001 3a00 0120 0341 036b 2001 3a00 0020   .:.. .A.k .:.. 
00032f2: 0341 026b 2001 3a00 0020 0241 0749 0d00  .A.k .:.. .A.I..
0003302: 2000 2001 3a00 0320 0341 046b 2001 3a00   . .:.. .A.k .:.
0003312: 0020 0241 0949 0d00 2000 4100 2000 6b41  . .A.I.. .A. .kA
0003322: 0371 2205 6a22 0420 0141 ff01 7141 8182  .q".j". .A..qA..
0003332: 8408 6c22 0336 0200 2004 2002 2005 6b41  ..l".6.. . . .kA
0003342: 7c71 2201 6a22 0241 046b 2003 3602 0020  |q".j".A.k .6.. 
0003352: 0141 0949 0d00 2004 2003 3602 0820 0420  .A.I.. . .6.. . 
0003362: 0336 0204 2002 4108 6b20 0336 0200 2002  .6.. .A.k .6.. .
0003372: 410c 6b20 0336 0200 2001 4119 490d 0020  A.k .6.. .A.I.. 
0003382: 0420 0336 0218 2004 2003 3602 1420 0420  . .6.. . .6.. . 
0003392: 0336 0210 2004 2003 3602 0c20 0241 106b  .6.. . .6.. .A.k
00033a2: 2003 3602 0020 0241 146b 2003 3602 0020   .6.. .A.k .6.. 
00033b2: 0241 186b 2003 3602 0020 0241 1c6b 2003  .A.k .6.. .A.k .
00033c2: 3602 0020 0120 0441 0471 4118 7222 026b  6.. . .A.qA.r".k
00033d2: 2201 4120 490d 0020 03ad 4281 8080 8010  ".A I.. ..B.....
00033e2: 7e21 0620 0220 046a 2102 0340 2002 2006  ~!. . .j!..@ . .
00033f2: 3703 1820 0220 0637 0310 2002 2006 3703  7.. . .7.. . .7.
0003402: 0820 0220 0637 0300 2002 4120 6a21 0220  . . .7.. .A j!. 
0003412: 0141 206b 2201 411f 4b0d 000b 0b20 000b  .A k".A.K.... ..

Contents of section Data:
0003425: 1700 4180 080b d60d 2d2b 2020 2030 5830  ..A.....-+   0X0
0003435: 7800 2d30 582b 3058 2030 582d 3078 2b30  x.-0X+0X 0X-0x+0
0003445: 7820 3078 006e 616e 0069 6e66 004e 414e  x 0x.nan.inf.NAN
0003455: 0049 4e46 002e 0028 6e75 6c6c 2900 4865  .INF...(null).He
0003465: 6c6c 6f20 6672 6f6d 2043 2000 5375 7070  llo from C .Supp
0003475: 6f72 7420 666f 7220 666f 726d 6174 7469  ort for formatti
0003485: 6e67 206c 6f6e 6720 646f 7562 6c65 2076  ng long double v
0003495: 616c 7565 7320 6973 2063 7572 7265 6e74  alues is current
00034a5: 6c79 2064 6973 6162 6c65 642e 0a54 6f20  ly disabled..To 
00034b5: 656e 6162 6c65 2069 742c 2061 6464 202d  enable it, add -
00034c5: 6c63 2d70 7269 6e74 7363 616e 2d6c 6f6e  lc-printscan-lon
00034d5: 672d 646f 7562 6c65 2074 6f20 7468 6520  g-double to the 
00034e5: 6c69 6e6b 2063 6f6d 6d61 6e64 2e0a 0053  link command...S
00034f5: 7563 6365 7373 0049 6c6c 6567 616c 2062  uccess.Illegal b
0003505: 7974 6520 7365 7175 656e 6365 0044 6f6d  yte sequence.Dom
0003515: 6169 6e20 6572 726f 7200 5265 7375 6c74  ain error.Result
0003525: 206e 6f74 2072 6570 7265 7365 6e74 6162   not representab
0003535: 6c65 004e 6f74 2061 2074 7479 0050 6572  le.Not a tty.Per
0003545: 6d69 7373 696f 6e20 6465 6e69 6564 004f  mission denied.O
0003555: 7065 7261 7469 6f6e 206e 6f74 2070 6572  peration not per
0003565: 6d69 7474 6564 004e 6f20 7375 6368 2066  mitted.No such f
0003575: 696c 6520 6f72 2064 6972 6563 746f 7279  ile or directory
0003585: 004e 6f20 7375 6368 2070 726f 6365 7373  .No such process
0003595: 0046 696c 6520 6578 6973 7473 0056 616c  .File exists.Val
00035a5: 7565 2074 6f6f 206c 6172 6765 2066 6f72  ue too large for
00035b5: 2064 6174 6120 7479 7065 004e 6f20 7370   data type.No sp
00035c5: 6163 6520 6c65 6674 206f 6e20 6465 7669  ace left on devi
00035d5: 6365 004f 7574 206f 6620 6d65 6d6f 7279  ce.Out of memory
00035e5: 0052 6573 6f75 7263 6520 6275 7379 0049  .Resource busy.I
00035f5: 6e74 6572 7275 7074 6564 2073 7973 7465  nterrupted syste
0003605: 6d20 6361 6c6c 0052 6573 6f75 7263 6520  m call.Resource 
0003615: 7465 6d70 6f72 6172 696c 7920 756e 6176  temporarily unav
0003625: 6169 6c61 626c 6500 496e 7661 6c69 6420  ailable.Invalid 
0003635: 7365 656b 0043 726f 7373 2d64 6576 6963  seek.Cross-devic
0003645: 6520 6c69 6e6b 0052 6561 642d 6f6e 6c79  e link.Read-only
0003655: 2066 696c 6520 7379 7374 656d 0044 6972   file system.Dir
0003665: 6563 746f 7279 206e 6f74 2065 6d70 7479  ectory not empty
0003675: 0043 6f6e 6e65 6374 696f 6e20 7265 7365  .Connection rese
0003685: 7420 6279 2070 6565 7200 4f70 6572 6174  t by peer.Operat
0003695: 696f 6e20 7469 6d65 6420 6f75 7400 436f  ion timed out.Co
00036a5: 6e6e 6563 7469 6f6e 2072 6566 7573 6564  nnection refused
00036b5: 0048 6f73 7420 6973 2075 6e72 6561 6368  .Host is unreach
00036c5: 6162 6c65 0041 6464 7265 7373 2069 6e20  able.Address in 
00036d5: 7573 6500 4272 6f6b 656e 2070 6970 6500  use.Broken pipe.
00036e5: 492f 4f20 6572 726f 7200 4e6f 2073 7563  I/O error.No suc
00036f5: 6820 6465 7669 6365 206f 7220 6164 6472  h device or addr
0003705: 6573 7300 4e6f 2073 7563 6820 6465 7669  ess.No such devi
0003715: 6365 004e 6f74 2061 2064 6972 6563 746f  ce.Not a directo
0003725: 7279 0049 7320 6120 6469 7265 6374 6f72  ry.Is a director
0003735: 7900 5465 7874 2066 696c 6520 6275 7379  y.Text file busy
0003745: 0045 7865 6320 666f 726d 6174 2065 7272  .Exec format err
0003755: 6f72 0049 6e76 616c 6964 2061 7267 756d  or.Invalid argum
0003765: 656e 7400 4172 6775 6d65 6e74 206c 6973  ent.Argument lis
0003775: 7420 746f 6f20 6c6f 6e67 0053 796d 626f  t too long.Symbo
0003785: 6c69 6320 6c69 6e6b 206c 6f6f 7000 4669  lic link loop.Fi
0003795: 6c65 6e61 6d65 2074 6f6f 206c 6f6e 6700  lename too long.
00037a5: 546f 6f20 6d61 6e79 206f 7065 6e20 6669  Too many open fi
00037b5: 6c65 7320 696e 2073 7973 7465 6d00 4e6f  les in system.No
00037c5: 2066 696c 6520 6465 7363 7269 7074 6f72   file descriptor
00037d5: 7320 6176 6169 6c61 626c 6500 4261 6420  s available.Bad 
00037e5: 6669 6c65 2064 6573 6372 6970 746f 7200  file descriptor.
00037f5: 4e6f 2063 6869 6c64 2070 726f 6365 7373  No child process
0003805: 0042 6164 2061 6464 7265 7373 0046 696c  .Bad address.Fil
0003815: 6520 746f 6f20 6c61 7267 6500 546f 6f20  e too large.Too 
0003825: 6d61 6e79 206c 696e 6b73 004e 6f20 6c6f  many links.No lo
0003835: 636b 7320 6176 6169 6c61 626c 6500 5265  cks available.Re
0003845: 736f 7572 6365 2064 6561 646c 6f63 6b20  source deadlock 
0003855: 776f 756c 6420 6f63 6375 7200 5374 6174  would occur.Stat
0003865: 6520 6e6f 7420 7265 636f 7665 7261 626c  e not recoverabl
0003875: 6500 5072 6576 696f 7573 206f 776e 6572  e.Previous owner
0003885: 2064 6965 6400 4f70 6572 6174 696f 6e20   died.Operation 
0003895: 6361 6e63 656c 6564 0046 756e 6374 696f  canceled.Functio
00038a5: 6e20 6e6f 7420 696d 706c 656d 656e 7465  n not implemente
00038b5: 6400 4e6f 206d 6573 7361 6765 206f 6620  d.No message of 
00038c5: 6465 7369 7265 6420 7479 7065 0049 6465  desired type.Ide
00038d5: 6e74 6966 6965 7220 7265 6d6f 7665 6400  ntifier removed.
00038e5: 4c69 6e6b 2068 6173 2062 6565 6e20 7365  Link has been se
00038f5: 7665 7265 6400 5072 6f74 6f63 6f6c 2065  vered.Protocol e
0003905: 7272 6f72 0042 6164 206d 6573 7361 6765  rror.Bad message
0003915: 004e 6f74 2061 2073 6f63 6b65 7400 4465  .Not a socket.De
0003925: 7374 696e 6174 696f 6e20 6164 6472 6573  stination addres
0003935: 7320 7265 7175 6972 6564 004d 6573 7361  s required.Messa
0003945: 6765 2074 6f6f 206c 6172 6765 0050 726f  ge too large.Pro
0003955: 746f 636f 6c20 7772 6f6e 6720 7479 7065  tocol wrong type
0003965: 2066 6f72 2073 6f63 6b65 7400 5072 6f74   for socket.Prot
0003975: 6f63 6f6c 206e 6f74 2061 7661 696c 6162  ocol not availab
0003985: 6c65 0050 726f 746f 636f 6c20 6e6f 7420  le.Protocol not 
0003995: 7375 7070 6f72 7465 6400 4e6f 7420 7375  supported.Not su
00039a5: 7070 6f72 7465 6400 4164 6472 6573 7320  pported.Address 
00039b5: 6661 6d69 6c79 206e 6f74 2073 7570 706f  family not suppo
00039c5: 7274 6564 2062 7920 7072 6f74 6f63 6f6c  rted by protocol
00039d5: 0041 6464 7265 7373 206e 6f74 2061 7661  .Address not ava
00039e5: 696c 6162 6c65 004e 6574 776f 726b 2069  ilable.Network i
00039f5: 7320 646f 776e 004e 6574 776f 726b 2075  s down.Network u
0003a05: 6e72 6561 6368 6162 6c65 0043 6f6e 6e65  nreachable.Conne
0003a15: 6374 696f 6e20 7265 7365 7420 6279 206e  ction reset by n
0003a25: 6574 776f 726b 0043 6f6e 6e65 6374 696f  etwork.Connectio
0003a35: 6e20 6162 6f72 7465 6400 4e6f 2062 7566  n aborted.No buf
0003a45: 6665 7220 7370 6163 6520 6176 6169 6c61  fer space availa
0003a55: 626c 6500 536f 636b 6574 2069 7320 636f  ble.Socket is co
0003a65: 6e6e 6563 7465 6400 536f 636b 6574 206e  nnected.Socket n
0003a75: 6f74 2063 6f6e 6e65 6374 6564 004f 7065  ot connected.Ope
0003a85: 7261 7469 6f6e 2061 6c72 6561 6479 2069  ration already i
0003a95: 6e20 7072 6f67 7265 7373 004f 7065 7261  n progress.Opera
0003aa5: 7469 6f6e 2069 6e20 7072 6f67 7265 7373  tion in progress
0003ab5: 0053 7461 6c65 2066 696c 6520 6861 6e64  .Stale file hand
0003ac5: 6c65 0051 756f 7461 2065 7863 6565 6465  le.Quota exceede
0003ad5: 6400 4d75 6c74 6968 6f70 2061 7474 656d  d.Multihop attem
0003ae5: 7074 6564 0043 6170 6162 696c 6974 6965  pted.Capabilitie
0003af5: 7320 696e 7375 6666 6963 6965 6e74 0041  s insufficient.A
0003b05: e215 0bdf 0175 024e 00d6 01e2 04b9 0418  .....u.N........
0003b15: 018e 05ed 0216 04f2 0097 0301 0338 05af  .............8..
0003b25: 0182 014f 032f 041e 00d4 05a2 0012 031e  ...O./..........
0003b35: 03c2 01de 0308 00ac 0500 0164 02f1 0165  ...........d...e
0003b45: 0534 028c 02cf 022d 034c 04e3 059f 02f8  .4.....-.L......
0003b55: 041c 0508 05b1 024b 0515 0278 0052 023c  .......K...x.R.<
0003b65: 03f1 03e4 00c3 037d 04cc 00aa 0379 0524  .......}.....y.$
0003b75: 026e 016d 0322 04ab 0444 00fb 01ae 0083  .n.m."...D......
0003b85: 0360 00e5 0107 0494 045e 042b 0058 0139  .`.......^.+.X.9
0003b95: 0192 00c2 059b 0143 0246 01f6 0500 0000  .......C.F......
0003ba5: 0000 0019 000a 0019 1919 0000 0000 0500  ................
0003bb5: 0000 0000 0009 0000 0000 0b00 0000 0000  ................
0003bc5: 0000 0019 0011 0a19 1919 030a 0700 011b  ................
0003bd5: 090b 1800 0009 060b 0000 0b00 0619 0000  ................
0003be5: 0019 1919 0041 d117 0b21 0e00 0000 0000  .....A...!......
0003bf5: 0000 0019 000a 0d19 1919 000d 0000 0200  ................
0003c05: 090e 0000 0009 000e 0000 0e00 418b 180b  ............A...
0003c15: 010c 0041 9718 0b15 1300 0000 0013 0000  ...A............
0003c25: 0000 090c 0000 0000 000c 0000 0c00 41c5  ..............A.
0003c35: 180b 0110 0041 d118 0b15 0f00 0000 040f  .....A..........
0003c45: 0000 0000 0910 0000 0000 0010 0000 1000  ................
0003c55: 41ff 180b 0112 0041 8b19 0b1e 1100 0000  A......A........
0003c65: 0011 0000 0000 0912 0000 0000 0012 0000  ................
0003c75: 1200 001a 0000 001a 1a1a 0041 c219 0b0e  ...........A....
0003c85: 1a00 0000 1a1a 1a00 0000 0000 0009 0041  ...............A
0003c95: f319 0b01 1400 41ff 190b 1517 0000 0000  ......A.........
0003ca5: 1700 0000 0009 1400 0000 0000 1400 0014  ................
0003cb5: 0041 ad1a 0b01 1600 41b9 1a0b 2715 0000  .A......A...'...
0003cc5: 0000 1500 0000 0009 1600 0000 0000 1600  ................
0003cd5: 0016 0000 3031 3233 3435 3637 3839 4142  ....0123456789AB
0003ce5: 4344 4546 0041 e01a 0b01 0500 41ec 1a0b  CDEF.A......A...
0003cf5: 0102 0041 801b 0b0e 0300 0000 0400 0000  ...A............
0003d05: 680e 0000 0004 0041 981b 0b09 0100 0000  h......A........
0003d15: 0000 0000 0a00 41d0 1b0b 0960 0d00 0000  ......A....`....
0003d25: 0000 0005 0041 e41b 0b01 0200 41f8 1b0b  .....A......A...
0003d35: 0a01 0000 0004 0000 0094 1200 4190 1c0b  ............A...
0003d45: 0c02 0000 0000 0000 00ff ffff ff00 41c8  ..............A.
0003d55: 1c0b 02d8 0d                             .....

Contents of section Custom:
0003d5c: 0970 726f 6475 6365 7273 010c 7072 6f63  .producers..proc
0003d6c: 6573 7365 642d 6279 0205 636c 616e 6706  essed-by..clang.
0003d7c: 3136 2e30 2e30 0c44 6562 6961 6e20 636c  16.0.0.Debian cl
0003d8c: 616e 6706 3134 2e30 2e36                 ang.14.0.6

Contents of section Custom:
0003d98: 0f74 6172 6765 745f 6665 6174 7572 6573  .target_features
0003da8: 032b 0f6d 7574 6162 6c65 2d67 6c6f 6261  .+.mutable-globa
0003db8: 6c73 2b0b 6275 6c6b 2d6d 656d 6f72 792b  ls+.bulk-memory+
0003dc8: 0873 6967 6e2d 6578 74                   .sign-ext

```

Key Value Store

WebAssembly Binary Size

Syntax Highlighting

https://xuanwo.io/reports/2022-21/

# 2023-12-15

# 2023-12-14
#!/bin/bash

```bash

tree -L 2 .  

git init

```

solve a problem

explore & discovery some fact

distcc

# 2023-12-13

```bash

sudo apt install linux-perf


git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git

export PATH=/home/tannal/tannalwork/projects/depot_tools:$PATH


```


```bash

du -sh WebKitBuild

time tar -c -I 'xz -9 -T20' -f WebKitBuild_x86_linux.tar.gz WebKitBuild/

sudo apt install openssh-server

sudo systemctl start ssh

```

https://askahh.com/archives/26/

```bash
Tools/Scripts/run-webkit-tests --gtk  http/tests/media/video-play-stall.html
16:17
MaybeParseValue
CSSParserToken

10-22
sudo apt-get install linux-tools-common linux-tools-generic

Tools/Scripts/run-webkit-tests --gtk  http/tests/media/video-play-stall.html

fix(ext/console): log format specifiers parsing

LocalAllocator::allocateSlowCase

com.apple.WebKit.WebContent.Development


void* JSC::allocateCell<


LD_LIBRARY_PATH=/usr/local/lib

Tools/Scripts/update-webkitwpe-libs

sudo ./stackcount  t:sched:sched_switch -P -dp 1873079
```

```bash

tar -cf - test | xz - -9 -e > test.tar.gz

```

research compress algorithm or software might be good.

research regular expression & markdown parsing might be good.

Chinese are good at analysis, but sucks on creativity.

# 2023-12-12


## software i use

windows, winzip, chrome, firefox, vscode, clash, clash-for-windows, video player

raylib, glfw, suspbase, x11, wayland, gnome, vim, neovim, lua, bash, sh

python, golang, rust, gcc, g++, gdb, make, cmake, ninja, auto-ninja


openjdk, libuv, tokio, rust-lang, graphql, webassembly

webkit, servo, deno, node, npm, yarn, pnpm

postgresql

ccache, sccache


## suspbase




## webassembly runtime open source

https://github.com/wasmerio/wasmer

https://github.com/WasmEdge/WasmEdge

https://github.com/wasm3/wasm3/

https://github.com/WebAssembly/wabt

https://github.com/bytecodealliance/wasm-micro-runtime



```bash

架构：                   x86_64
  CPU 运行模式：         32-bit, 64-bit
  Address sizes:         46 bits physical, 48 bits virtual
  字节序：               Little Endian
CPU:                     24
  在线 CPU 列表：        0-23
厂商 ID：                GenuineIntel
  型号名称：             12th Gen Intel(R) Core(TM) i9-12900K
    CPU 系列：           6
    型号：               151
    每个核的线程数：     2
    每个座的核数：       16
    座：                 1
    步进：               2
    CPU 最大 MHz：       5200.0000
    CPU 最小 MHz：       800.0000
    BogoMIPS：           6374.40
    标记：               fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon
                          pebs bts rep_good nopl xtopology nonstop_tsc cpuid aperfmperf tsc_known_freq pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2
                          x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb cat_l2 invpcid_single cdp_l2 ssbd ibrs ibpb stibp ibrs_enhanced tpr_sh
                         adow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid rdt_a rdseed adx smap clflushopt clwb intel_pt sha_ni xsaveopt xsavec xgetbv1 xsaves s
                         plit_lock_detect avx_vnni dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp hwp_pkg_req hfi umip pku ospke waitpkg gfni vaes vpclmulqdq tme rdpid movdiri movdir64b fs
                         rm md_clear serialize pconfig arch_lbr ibt flush_l1d arch_capabilities
Virtualization features: 
  虚拟化：               VT-x
Caches (sum of all):     
  L1d:                   640 KiB (16 instances)
  L1i:                   768 KiB (16 instances)
  L2:                    14 MiB (10 instances)
  L3:                    30 MiB (1 instance)
NUMA:                    
  NUMA 节点：            1
  NUMA 节点0 CPU：       0-23
Vulnerabilities:         
  Itlb multihit:         Not affected
  L1tf:                  Not affected
  Mds:                   Not affected
  Meltdown:              Not affected
  Mmio stale data:       Not affected
  Retbleed:              Not affected
  Spec store bypass:     Mitigation; Speculative Store Bypass disabled via prctl
  Spectre v1:            Mitigation; usercopy/swapgs barriers and __user pointer sanitization
  Spectre v2:            Mitigation; Enhanced IBRS, IBPB conditional, RSB filling, PBRSB-eIBRS SW sequence
  Srbds:                 Not affected
  Tsx async abort:       Not affected


# qemu

time make -j22

```

# 2023-12-11



```bash
cmake -G"Unix Makefiles" -DBUILD_SHARED_LIBS=ON
```

wasm binary rewriter

rewrite wasm binary

decrease size

performance improvement

```bash

sudo apt-get install gcc-multilib

# whereis llvm

dpkg -L llvm

```


# 2023-12-10

# 理发师悖论

Q: 你为哪些人理发？

q: 你是否为自己理发？

lemma：q是Q的子问题

A: 我为那些不自己理发的人理发

Statement A is equalvalent with the following.

1. 如果我为我理发，则我不会为我理发
2. 如果我不为我理发，则我会为我理发

The truth value of statement A is not decidable using traditional logic.
Because It doesn't obey the law of contradiction.



A2：我为那些自己理发的人理发

1. 如果我为我理发，则我会为我理发
2. 如果我不为自己理发，则我不会为我理发

A2 does obey the law of contrdiction, So Statement A2 is decidable in traditional logic.

A2 is true. XD



```bash
4.0K drwxrwxr-x  20 a48 a48 4.0K 12月  8 21:08 bcc
4.0K drwxrwxr-x   4 a48 a48 4.0K 11月 22 15:37 chromium
4.0K drwxrwxr-x  59 a48 a48 4.0K 11月 22 13:34 chromium-clone
4.0K drwxrwxr-x   5 a48 a48 4.0K 12月  7 21:55 course-compiler
4.0K drwxrwxr-x  18 a48 a48 4.0K 12月  6 08:42 deno
 12K drwxrwxr-x  24 a48 a48  12K 11月 24 14:46 depot_tools
4.0K drwxrwxr-x   4 a48 a48 4.0K 11月 24 15:05 engine
4.0K drwxrwxr-x  20 a48 a48 4.0K 11月 24 16:28 filament
4.0K drwxrwxr-x   9 a48 a48 4.0K 12月  2 15:07 flutter
4.0K drwxrwxr-x  43 a48 a48 4.0K 11月 24 22:30 gcc
4.0K drwxrwxr-x  12 a48 a48 4.0K 12月 10 15:32 go
4.0K drwxrwxr-x  19 a48 a48 4.0K 12月 10 07:16 godot
4.0K drwxrwxr-x  11 a48 a48 4.0K 12月  6 19:31 jdk
4.0K drwxrwxr-x   7 a48 a48 4.0K 11月 23 19:48 kerneldev
4.0K -rw-rw-r--   1 a48 a48  484 11月 23 16:14 lk.js
4.0K drwxrwxr-x  14 a48 a48 4.0K 11月 23 09:17 mesa
4.0K drwxrwxr-x  55 a48 a48 4.0K 11月 27 15:37 mozilla-unified
4.0K drwxrwxr-x   7 a48 a48 4.0K 11月 27 14:26 MyTestApp
4.0K drwxrwxr-x  33 a48 a48 4.0K 12月  2 14:39 ocaml
4.0K drwxrwxr-x  16 a48 a48 4.0K 12月  8 20:04 perf-tools
4.0K drwxrwxr-x   7 a48 a48 4.0K 12月 10 15:36 postgres
4.0K drwxrwxr-x  28 a48 a48 4.0K 11月 27 14:18 pytorch
4.0K drwxrwxr-x   7 a48 a48 4.0K 12月  7 12:53 racket
4.0K drwxrwxr-x  17 a48 a48 4.0K 12月 10 16:57 rhino
4.0K drwxrwxr-x  11 a48 a48 4.0K 12月 10 15:22 rust
4.0K drwxrwxr-x  16 a48 a48 4.0K 12月  1 18:23 servo
4.0K drwxrwxr-x  14 a48 a48 4.0K 11月 24 17:10 virgil
4.0K drwxrwxr-x  19 a48 a48 4.0K 11月 27 11:50 vscode
4.0K drwxrwxr-x  15 a48 a48 4.0K 12月  3 19:32 wabt
4.0K drwxrwxr-x  17 a48 a48 4.0K 11月 28 09:25 wasmtime
4.0K drwxrwxr-x  18 a48 a48 4.0K 12月  6 17:01 WebKit
4.0K drwxrwxr-x  16 a48 a48 4.0K 11月 30 19:13 winit
4.0K drwxrwxr-x  11 a48 a48 4.0K 11月 24 17:11 wizard-engine
 12K drwxrwxr-x 276 a48 a48  12K 11月 30 21:55 wpt

sudo update-alternatives --config java

# gradle.properties proxy
systemProp.http.proxyHost=127.0.0.1
systemProp.http.proxyPort=7890
systemProp.https.proxyHost=127.0.0.1
systemProp.https.proxyPort=7890

initdb -d data

./postgres -D data/

ps -aux | grep postgres

./psql -U a48 -w -d postgres

```

https://www.scattered-thoughts.net/writing/reflections-on-a-decade-of-coding/

# 2023-12-09

https://remotely.routemehome.org/RemoteControl/Viewer?sessionId=889717405

# 



# webassembly is new docker

warning: variable does not need to be mutable
  --> third_party/webrender/webrender_api/src/display_item_cache.rs:61:13
   |
61 |         let mut entry = &mut self.entries[key as usize];
   |             ----^^^^^
   |             |
   |             help: remove this `mut`
   |
   = note: `#[warn(unused_mut)]` on by default

warning: variable does not need to be mutable
  --> third_party/webrender/webrender_api/src/display_item_cache.rs:67:13
   |
67 |         let mut entry = &mut self.entries[key as usize];
   |             ----^^^^^
   |             |
   |             help: remove this `mut`


# 2023-12-08

```bash
# switch master to main
git branch -m master main
git fetch origin
git branch -u origin/main main
git remote set-head origin -a

```


## webassembly talks

https://twitter.com/tomayac webassembly & project fugu @chrome

git submodule update --init --recursive

WebAssembly beyond the browser by Mete Atamel

## rust webassembly

rustup target add wasm32-wasi
cargo build --target wasm32-wasi --release

## sigplan research ideas

https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/debian-12.2.0-amd64-netinst.iso

https://iso.pop-os.org/20.04/amd64/nvidia/39/pop-os_20.04_amd64_nvidia_39.iso

- parallelizing compilers

- parallel systems

- memory management

Memory allocation

Garbage Collection

The Immix mark-region garbage collector

type system
module system design, 
efficient compilation of functional programming languages, 
bytecode verification, 
verified compilation, and 
verified static analysis.



# 2023-12-07

## functional programming in racket

(functionname param1 param2 ...)

(define eight 8)

(struct Int (field1 field2 ...))

(Int-field1 ) access struct field

(list ) make a list


- haoranxu 

Garbage Collection in webkit

Just in time compilation

https://sillycross.github.io/2022/06/02/2022-06-02/

# 2023-12-06

## QEMU

binary translation

virtualize cpu & device

## docker

chroot 

security


# 2023-12-05


## daft papers

A Tour of Webassembly

https://www.tannal.glitch.me/papers/survey.html

- A Tour of Tensorflow https://arxiv.org/pdf/1610.01178.pdf

## contents we can create

- blog post tutorial survey paper books
- video & vlog & streaming & education
- music
- class
- code & program & project & system & app & product

Survey examples

https://www.igalia.com/downloads/2023-cross-platform-mobile-app-frameworks.pdf

How to write a good research paper

https://www.youtube.com/watch?v=MXIXkVMbUuA&list=PLyrlk8Xaylp60H6hgCjcRengd2O1DoS3E&index=6

Research & Industry Diverse on PL

https://slideplayer.com/slide/3855960/

## SigPLAN

### complication

### language design

### static analysis

### concurrency

### program synthesis

### category theory

### Webassembly



# 2023-12-04

## Researchers to learn from around sigplan

- Sam Westrick https://www.cs.cmu.edu/~swestric/

  phd thesis implement a compiler
  
  currently CMU postdoc 
  
  known from [PLMW@ICFP'23] How to Thrive as a PhD student in PL
  
  https://www.youtube.com/watch?v=Nn729OkfzBQ&list=PLyrlk8Xaylp60H6hgCjcRengd2O1DoS3E&index=1


- Jeremy Siek https://wphomes.soic.indiana.edu/jsiek/

a book for compiler


## invariant - the heart of imperitive programming

## General Research ideas

## Survey

## Case Study

## Empricial Study

# 2023-12-03

## main problems in wasm

![](https://cdn.glitch.global/c8d57c73-6044-4741-a71a-82aa74f41701/9764c69a-3427-4a00-a19a-35aaf6d50f01.image.png?v=1701562791275)

https://docs.google.com/presentation/d/1RKRNnFrI8xPvEFfTao40WqqAd6NWuPET8qR5FIKHEEA/edit#slide=id.g1733516d4b3_4_101

# paper title

A implementation of [problem] in [env]

Evaluation and optimizing [metrics] in [tech]

A study of [tech] for [appliaction]


# 2023-12-02

## reading a paper

https://cseweb.ucsd.edu//~wgg/CSE210/howtoread.html

## writing a paper

https://www.cs.columbia.edu/~hgs/etc/writing-style.html

## Research ideas on WebAssembly

### backgrouond

Webassembly is a solution not a problem.

I think the main reason wasm exists is that

People don't write javascript today. 

People write their code in other languages like typescript or Java, then compile to javascript.

But javascript is designed for people to program.

Javascipt is not designed as a compilation target.

"We don't blame users" as we all know.

So browser vendor come up wasm as a compilation target that are better than javascript.

But it try to solve some problems describle below.

So we want to do research around webassembly.

We are essentially built research upon the webassembly paper(2017).

We also assume many things:

1. The problems that webassembly try to solve is valid, important, and valuable.

2. The solutions(aka wasm) is approaching the goals it set.(We shouldn't care about wasm if it doesn't solve the problems)

Why we assume them is true? Beacause it's widely support in all major browers and nobody disprove them.(may be you can try and i think it's hard)

So our goals are simple. Just make wasm meet their goals.(or help others make wasm meet the goals)

There are possible ideas for reasearch papers in webassembly.

- Investiage how much does the goal achieved in 2023? aka the status of webassembly

- Analysis memory leaking/consuming in webassembly (and compare to js)

- What language should you choose when you want you apps/systems to target webassembly?

- webassembly js coummications

- how it be used today and how it can be used in the future

### Problems (the goal of wasm)

- performance improvement

- run C/C++/Rust/Go any languages in the web.

- runtime itself is embededable

- wasm on server side

- sandbox & safety grant

#### make web faster

#### make web protable further

#### safe by design


### Solutions



## research idea

- area summary collecting problems and solutions that already exists. Try to challage it.

- case study to verify some guess or opinion.

- propose a idea/system to solve a problem.

- analysis/benmark/compare the existing solutions to better understand what's going on? .

- find problems in existing solutions.

- Come up problems and show it's not solved and show it is important and attempt to solve it.

## A problems & solutions perspective

### problem side

What are the problems researchers/industry/developers/normal people already care about?

Once you have problems, ask

Are they valid? important? valuable?

Are they solved?

Are they

what are the problems they should care?

what are the problems they shouldn't care?

### solution side

How the currently solutions works?

Can you generlize the idea of the solution?

What's the limitations of the current solutions?

How can you build upon the solutions? 


# 2023-12-01

## how browser works

- page refresh path / main path / fast path

what happens loading a page?

After main path the system switched to event driven "server" mode

Events typical two forms

- js running render process

- user event trigger

- networking




### WASM research groups

- CMU Webassembly group @Ben L. Titzer

- fastly research

- Quentin Stiévenart

https://qstievenart.gitlab.io/

- Coen De Roover

http://soft.vub.ac.be/~cderoove/

# 2023-11-29

## WASM


### Features

- Static Stack-Preserving Intra-Procedural Slicing of WebAssembly Binaries.

- Continuing WebAssembly with Effect Handlers.

implement non-local control flow features such as async/await, generators/iterators, lightweight threads, first-class
continuations, etc for wasm.

### reports, talks, notes, books

- Program analysis of WebAssembly binaries.

- Foundations of WebAssembly (Dagstuhl Seminar 23101).

### Developer Experience

- Understanding the Issues and Causes in WebAssembly Application Development: A Mining-based Study. [*]

### Effeciency

- WebAssembly versus JavaScript: Energy and Runtime Performance.

- Comparing the Energy Efficiency of WebAssembly and JavaScript in Web Applications on Android Mobile Devices.
  JS vs Wasm with Energy Efficiency  on mobile

- A Fast In-Place Interpreter for WebAssembly.

- Revealing Performance Issues in Server-side WebAssembly Runtimes via Differential Testing.

benchmark suits

- WasmSlim: Optimizing WebAssembly Binary Distribution via Automatic Module Splitting.

reduce startup time and binary size

- Revealing Performance Issues in Server-side WebAssembly Runtimes via Differential Testing.

- Exploring Missed Optimizations in WebAssembly Optimizers

- Demystifying Web-based Mobile Extended Reality Accelerated by
WebAssembly.

performance improvement in WebXR using wasm

- A Systematic Review of WebAssembly VS Javascript Performance Comparison. 

- Preventing EFail Attacks with Client-Side WebAssembly: The Case of Swiss Post’s IncaMail.

repalce js to wasm gained up to 14x performance improvement


### Safety

- Developers Struggle with Authentication in Blazor WebAssembly.

- WATZ: A Trusted WebAssembly Runtime Environment with Remote Attestation for TrustZone.

- Towards securely migrating webassembly enclaves.

- Avengers, Assemble! Survey of WebAssembly Security Solutions.

- Isolation without Taxation Near-Zero-Cost Transitions for WebAssembly and SFI.

- A Study of Timing Side-Channel Attacks and Countermeasures on JavaScript and WebAssembly.

- Wasmati: An efficient static vulnerability scanner for WebAssembly.

- Static Semantics Reconstruction for Enhancing JavaScript-WebAssembly Multilingual Malware Detection.

- WASM-MUTATE: Fast and Effective Binary Diversification for WebAssembly.

- WASMixer: Binary Obfuscation for WebAssembly.

Wasm binary obfuscator

- Characterizing and Detecting WebAssembly Runtime Bugs

- A Comprehensive Study of WebAssembly Runtime Bugs.

- User Models as Digital Twins: Using Webassembly Techniques to ensure Privacy, Transparency and Control in Personalization.

- WaVe: a verifiably secure WebAssembly sandboxing runtime

wasi secure, isolation impl for os resources like fs socket etc.

- Comparing Security in eBPF and WebAssembly.

- POSTER: Leveraging eBPF to enhance sandboxing of WebAssembly runtimes. FileSystem Access Control

- malicious site detection A Tool for generating wasm dataset from real world websites
JABBERWOCK: A Tool for WebAssembly Dataset Generation towards Malicious Website Detection.


### Mechanising and Verifying and implementing the WebAssembly Specification

- WasmRef-Isabelle: A Verified Monadic Interpreter and Industrial Fuzzing Oracle for WebAssembly.

### Program analysis

![](https://cdn.glitch.global/c8d57c73-6044-4741-a71a-82aa74f41701/thumbnails%2F4f904f5e-217b-4a82-9c75-d861e0b8f9fc.image.png?1701242907364)

- REWasm: A General Static Binary Rewriting Framework for WebAssembly. 

#### Formal Verification

- Iris-Wasm: Robust and Modular Verification of WebAssembly Programs.

formally verify functional correctness of WebAssembly programs

#### Static Analysis

- WasmA: A Static WebAssembly Analysis Framework for Everyone.

- Modular Abstract Definitional Interpreters for WebAssembly. 

static analysis for webassembly binaries (improve performance and secure programs against vulnerabilities)

- That's a Tough Call: Studying the Challenges of Call Graph Construction for WebAssembly.

call graph construction

- Eunomia: Enabling User-specified Fine-Grained Search in
Symbolically Executing WebAssembly Binaries

symbolically executing

### Application


#### High performance Computing

- Exploring the Use of WebAssembly in HPC.

#### Embedded Systems

- Support for Just-in-Time Compilation of WebAssembly for Embedded Systems.

#### IOT

- WebAssembly in IoT: Beyond Toy Examples. 

Explore Wasm in IoT

- On the Energy Consumption and Performance of WebAssembly
Binaries across Programming Languages and Runtimes in IoT.

- Autonomous Choreography of WebAssembly Workloads in the Federated Cloud-Edge-IoT Continuum.

#### serveless

- WebAssembly as a Common Layer for the Cloud-edge Continuum. 

- Pushing Serverless to the Edge with WebAssembly Runtimes.

- WebAssembly for Edge Computing: Potential and Challenges.

- Wasm as a runtime in serverless computing.

- WebAssembly Orchestration in the Context of Serverless Computing.

- WebAssembly as an Enabler for Next Generation Serverless Computing.

https://fanpu.io/blog/2023/advanced-operating-systems-course-review/

https://enr-apps.as.cmu.edu/open/SOC/SOCServlet/search

### App

Domain Specific Application developed by Wasm

- Rendering Medical Images using WebAssembly.

- WebAssembly-based Delta Sync for Cloud Storage Services.

- Powering single-cell analyses in the browser with WebAssembly.



#### misc

- Automated WebAssembly Function Purpose Identification With Semantics-Aware Analysis.

- Wasmizer: Curating WebAssembly-driven Projects on GitHub.

- User Models as Digital Twins: Using Webassembly Techniques to ensure Privacy, Transparency and Control in Personalization.

create webassembly dataset from github

# 2023-11-28

```bash
# find all plain texts file in the current directory while exclude some subfixs
find . -type f ! \( -name "*.pdf" -o -name "*.docx" -o -name "*.xlsx" \) -exec file {} \; | grep "text"

# find all executable files in the current directory recursively
find . -type f -executable
```

This post is part of the series “A trip through the Graphics Pipeline 2011”.

https://fgiesen.wordpress.com/2011/07/09/a-trip-through-the-graphics-pipeline-2011-index/

https://bartoszmilewski.com/2014/11/24/types-and-functions/

japan https://www.jetro.go.jp/sc/invest/setting_up/section2/page11/

https://www.isinj.com/mt-usamo/Mathematics%20and%20Plausible%20Reasoning%20I%20-%20Polya%20G.pdf

https://www.isinj.com/mt-usamo/Mathematics%20and%20Plausible%20Reasoning%20II%20(2nd%20edition)%20-%20Polya%20G.pdf

## deno

- 

## servo




https://docs.google.com/document/d/1JwwLYxFMDwuxX4Sc3znE-8jVIQMW1LWjuvYeLpiVf_8/edit

https://www.pbr-book.org/

https://natureofcode.com/

https://t5k.org/

https://servo.zulipchat.com/#narrow/stream/263398-general/topic/TSC.20Meeting.20December.202023

https://www.usenix.org/conferences

https://swtch.com/~rsc/regexp/regexp1.html

pip install not in PATH

export PATH="$HOME/.local/bin:$PATH"

https://www.interdb.jp/pg/

https://www.jayconrod.com/posts/55/a-tour-of-v8--garbage-collection

https://sites.cs.ucsb.edu/~lingqi/teaching/cs291a.html

https://fgiesen.wordpress.com/2011/07/01/a-trip-through-the-graphics-pipeline-2011-part-1/

# better explained

https://aha.betterexplained.com/

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

git config --global http.sslVerify false
git config --global imap.sslverify false

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



