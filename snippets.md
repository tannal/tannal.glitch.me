
# express server nodejs

corepack enable

sudo ./funcgraph -p 47889 tcp_update_skb_after_send -m 2


pnpm init -y
pnpm i express


const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => {
    console.log('Hello')
    res.send('Hello World!')
})

app.listen(port, () => {

    console.log(`Example app listening on port ${port}`)
})

if (process.pid) {
    console.log('This process is your pid ' + process.pid);
}


# vjudge in nodejs

```js
#!/home/tannal/.nvm/versions/node/v20.10.0/bin/node

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
});

const inspector = require('inspector');
const debug = inspector.url() !== undefined

console.debug = (...args) => {
  if (debug) {
    console.log(...args)
  }
}

function solve(/** @type {number[]} */ balloons) {
  console.debug(balloons)
  let count = 0

  let current = []

  for(let i = 0; i < balloons.length; i++) {
    if(current.some(v => v === balloons[i])) {  
      let idx = current.findIndex(v => v === balloons[i])
      current[idx]--
    }else {   
      count++
      current.push(balloons[i] - 1)
    }
  }
  console.log(count)
}

const processInput = (lines) => {
    let n = +lines.shift()
    let balloons = lines.shift()
    solve(balloons.split(' ').map(v => +v))
};

const readInputLines = async () => {
  const lines = [];
  for await (const line of rl) {
    lines.push(line);
  }
  return lines;
};

readInputLines().then(lines => {
  processInput(lines);
});

```


# python plt 

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


# winget setup in powershell

```powershell

$progressPreference = 'silentlyContinue'
Write-Information "Downloading WinGet and its dependencies..."
Invoke-WebRequest -Uri https://aka.ms/getwinget -OutFile Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle
Invoke-WebRequest -Uri https://aka.ms/Microsoft.VCLibs.x64.14.00.Desktop.appx -OutFile Microsoft.VCLibs.x64.14.00.Desktop.appx
Invoke-WebRequest -Uri https://github.com/microsoft/microsoft-ui-xaml/releases/download/v2.7.3/Microsoft.UI.Xaml.2.7.x64.appx -OutFile Microsoft.UI.Xaml.2.7.x64.appx
Add-AppxPackage Microsoft.VCLibs.x64.14.00.Desktop.appx
Add-AppxPackage Microsoft.UI.Xaml.2.7.x64.appx
Add-AppxPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle

```

# Libuv V8

```cpp
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

```
# TypeScript setup

```bash
npm init -y
npm install ts-node typescript @types/node
npx tsc --init
```

tsconfig.json

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

# cmake project starter

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

# systemd service

sudo vim /etc/systemd/system/docs.service

[Unit]
# 服务名称，可自定义
Description = docs

[Service]
Type = simple
WorkingDirectory=/home/tannal/tannalwork/projects/yjs-demos/
ExecStart = /bin/bash -c 'PATH=/home/tannal/.nvm/versions/node/v20.11.0/bin/:$PATH pnpm start'
Restart=always

[Install]
WantedBy = multi-user.target

# create n thread print 1..n in golang

```go

package main

import (
	"fmt"
	"sync"
	"time"
)

func wait(seconds int, wg *sync.WaitGroup) {
	defer wg.Done()

	time.Sleep(time.Duration(seconds) * time.Second)
	fmt.Println("Slept ", seconds, " seconds ..")
}

func main() {
	var wg sync.WaitGroup

	for i := 0; i <= 5; i++ {
		wg.Add(1)
		go wait(i, &wg)
	}
	wg.Wait()
}

```



# hello world linux module

make

sudo make load

sudo make unload

sudo dmesg

```c
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
```Makefile

obj-m += hello.o

.PHONY: build clean load unload

build:
	make -C /lib/modules/$(shell uname -r)/build modules M=$(shell pwd)

clean:
	make -C /lib/modules/$(shell uname -r)/build clean M=$(shell pwd)

load:
	sudo insmod hello.ko
unload:
	sudo rmmod hello
```

# cmake print variable

include(CMakePrintHelpers)

cmake_print_variables(LLD_DIR)


# git config for git send mail with gmail

```
[user]
    name = Meng Tan
    email = tannal2409@gmail.com
[sendemail]
    smtpServer = smtp.gmail.com
    smtpServerPort = 587
    smtpEncryption = tls
    smtpUser = tannal2409@gmail.com
    # (Optional: we'll leave this commented out and use a different way)
    # smtpPass = PASSWORD
[credential]
    helper = store
```

# configuration for wifi auto connect when boot raspi

sudo vim /etc/network/interfaces

auto wlan0
iface wlan0 inet static
address 192.168.43.246
netmask 255.255.255.0
gateway 192.168.43.1
wireless-essid 小米手机
wireless-key 9711eeb1f089