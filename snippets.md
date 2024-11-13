# vscode user settings



user
```
{
    "workbench.sideBar.location": "right",
    "workbench.iconTheme": "material-icon-theme",
    "dart.flutterSdkPath": "C:\\Users\\tannal\\Downloads\\flutter_windows_3.16.5-stable\\flutter",
    "remote.SSH.remotePlatform": {
        "4090": "linux",
        "13700kf": "linux",
        "raspi5": "linux",
        "tc": "linux",
        "10.68.136.132": "linux",
        "10.68.136.134": "linux"
    },
    "cmake.configureSettings": {
        "CMAKE_TOOLCHAIN_FILE": "C:/Users/tannal/tannalwork/projects/vcpkg/scripts/buildsystems/vcpkg.cmake",
        "VCPKG_TARGET_TRIPLET": "x64-windows"
    },
    "C_Cpp.default.compilerPath": "cl.exe",
    "http.proxySupport": "on",
    "[jsonc]": {
        "editor.defaultFormatter": "vscode.json-language-features"
    },
    "gitlens.ai.experimental.provider": "openai",
    "gitlens.ai.experimental.openai.model": "gpt-4-1106-preview",
    "github.copilot.enable": {
        "*": true,
        "plaintext": false,
        "markdown": false,
        "scminput": false
    },
    "[javascript]": {
        "editor.defaultFormatter": "vscode.typescript-language-features"
    },
    "js/ts.implicitProjectConfig.checkJs": true,
    "[javascriptreact]": {
        "editor.defaultFormatter": "vscode.typescript-language-features"
    },
    "[typescript]": {
        "editor.defaultFormatter": "vscode.typescript-language-features"
    },
    "[typescriptreact]": {
        "editor.defaultFormatter": "esbenp.prettier-vscode"
    }
}
```


# swap file

sudo fallocate -l 64G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
sudo swapon --show
sudo swapoff -a

cat /proc/sys/vm/swappiness
sudo sysctl vm.swappiness=10
sudo vim /etc/sysctl.conf
vm.swappiness=10

# Relational Operator in golang

```go
package main

import (
	"fmt"
	"sync"
)

// Define the structs for R and S relations
type R struct {
	id   int
	name string
}

type S struct {
	id    int
	value string
	cdate string
}

// Define the struct for the joined results
type JoinedResult struct {
	RId   int
	Name  string
	Value string
}

// Hash function to partition the relations
func hashFunction(id int, numPartitions int) int {
	return id % numPartitions
}

// Function to partition data
func partitionData[T any](data []T, numPartitions int, hashFunc func(int, int) int) [][]T {
	partitions := make([][]T, numPartitions)
	for i := 0; i < numPartitions; i++ {
		partitions[i] = []T{}
	}

	for _, item := range data {
		var id int
		switch v := any(item).(type) {
		case R:
			id = v.id
		case S:
			id = v.id
		default:
			panic("unknown data type")
		}
		partition := hashFunc(id, numPartitions)
		partitions[partition] = append(partitions[partition], item)
	}

	return partitions
}

// Parallel hash join
func parallelHashJoin(partitionsR [][]R, partitionsS [][]S, numPartitions int) []JoinedResult {
	var wg sync.WaitGroup
	results := make(chan JoinedResult, 10) // Buffered channel to collect results
	finalResults := []JoinedResult{}

	// Join partitions in parallel
	for i := 0; i < numPartitions; i++ {
		wg.Add(1)
		go func(partitionR []R, partitionS []S) {
			defer wg.Done()
			hashTableS := make(map[int]S)
			for _, s := range partitionS {
				hashTableS[s.id] = s
			}
			for _, r := range partitionR {
				if s, found := hashTableS[r.id]; found {
					results <- JoinedResult{RId: r.id, Name: r.name, Value: s.value}
				}
			}
		}(partitionsR[i], partitionsS[i])
	}

	// Close results channel when all goroutines are done
	go func() {
		wg.Wait()
		close(results)
	}()

	// Collect results
	for result := range results {
		finalResults = append(finalResults, result)
	}

	return finalResults
}

func main() {
	// Example relations
	relationR := []R{{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}}
	relationS := []S{{1, "Value1", "2024-02-20"}, {2, "Value2", "2024-02-21"}, {3, "Value3", "2024-02-22"}}

	// Number of partitions
	numPartitions := 2 // For simplicity

	// Partition data
	partitionsR := partitionData(relationR, numPartitions, hashFunction)
	partitionsS := partitionData(relationS, numPartitions, hashFunction)

	// Perform parallel hash join
	joinedResults := parallelHashJoin(partitionsR, partitionsS, numPartitions)

	// Print results
	for _, result := range joinedResults {
		fmt.Printf("RId: %d, Name: %s, Value: %s\n", result.RId, result.Name, result.Value)
	}
}

```

Intra-Operator (Horizontal)
```go
package main

import (
	"fmt"
	"sync"
)

// Define the structs for R and S relations
type R struct {
	id   int
	name string
}

type S struct {
	id    int
	value string
	cdate string
}

// Hash function to partition the relations
func hashFunction(id int, numPartitions int) int {
	return id % numPartitions
}

// Function to build the hash table from a relation R or S
func buildHashTable(relation interface{}, numPartitions int) []map[int]interface{} {
	hashTables := make([]map[int]interface{}, numPartitions)
	for i := range hashTables {
		hashTables[i] = make(map[int]interface{})
	}

	switch rel := relation.(type) {
	case []R:
		for _, tuple := range rel {
			partition := hashFunction(tuple.id, numPartitions)
			hashTables[partition][tuple.id] = tuple
		}
	case []S:
		for _, tuple := range rel {
			partition := hashFunction(tuple.id, numPartitions)
			hashTables[partition][tuple.id] = tuple
		}
	}

	return hashTables
}

// Worker to perform the join on one partition
func joinWorker(htR, htS map[int]interface{}, results chan<- []string) {
	for id, rTuple := range htR {
		if sTuple, exists := htS[id]; exists {
			// Assuming we want to join on the 'id' and print 'name' and 'value'
			r := rTuple.(R)
			s := sTuple.(S)
			results <- []string{r.name, s.value}
		}
	}
}

func main() {
	// Example relations
	// Create more test data to test the join
	relationR := []R{
		{1, "A"},
		{2, "B"},
		{3, "C"},
		{4, "D"},
		{5, "E"},
	}

	relationS := []S{
		{1, "X", "2020-01-01"},
		{2, "Y", "2020-01-02"},
		{3, "Z", "2020-01-03"},
		{4, "W", "2020-01-04"},
		{5, "V", "2020-01-05"},
	}

	// Number of partitions
	numPartitions := 2 // for simplicity

	// Build hash tables for each partition
	htR := buildHashTable(relationR, numPartitions)
	htS := buildHashTable(relationS, numPartitions)

	results := make(chan []string)
	var wg sync.WaitGroup

	// Launch a worker for each partition
	for i := 0; i < numPartitions; i++ {
		wg.Add(1)
		go func(partition int) {
			defer wg.Done()
			joinWorker(htR[partition], htS[partition], results)
		}(i)
	}

	// Close the results channel when all workers are done
	go func() {
		wg.Wait()
		close(results)
	}()

	// Collect results
	for result := range results {
		fmt.Println(result)
	}
}


```

# rsync

vim /etc/conf/rsyncd.conf

```conf

### rsyncd.conf 文件的配置
[root@50_125 rsync]# vim rsyncd.conf
# /etc/rsyncd: configuration file for rsync daemon mode
# See rsyncd.conf man page for more options.
# 传输文件使用的用户和用户组，如果是从服务器=>客户端，要保证www用户对文件有读取的权限；如果是从客户端=>服务端，要保证www对文件有写权限。
uid = www
gid = www
# 允许chroot，提升安全性，客户端连接模块，首先chroot到模块path参数指定的目录下，chroot为yes时必须使用root权限，且不能备份path路径外的链接文件
use chroot = yes
# 只读
read only = no
# 只写
write only = no
# 设定白名单，可以指定IP段（172.18.50.1/255.255.255.0）,各个Ip段用空格分开
hosts allow = 172.18.50.110 172.18.50.111
hosts deny = *
# 允许的客户端最大连接数
max connections = 4
# 欢迎文件的路径，非必须
motd file = /etc/rsync/rsyncd.motd
# pid文件路径
pid file = /var/run/rsyncd.pid
# 记录传输文件日志
transfer logging = yes
# 日志文件格式
log format = %t %a %m %f %b
# 指定日志文件
log file = /var/log/rsync.log
# 剔除某些文件或目录，不同步
exclude = lost+found/
# 设置超时时间
timeout = 900
ignore nonreadable = yes
# 设置不需要压缩的文件
dont compress   = *.gz *.tgz *.zip *.z *.Z *.rpm *.deb *.bz2

# 模块，可以配置多个，使用如: sate@172.18.50.125::125to110
[125to110]
# 模块的根目录，同步目录，要注意权限
path = /tmp/nginx
# 是否允许列出模块内容
list = no
# 忽略错误
ignore errors
# 添加注释
comment = ftp export area
# 模块验证的用户名称，可使用空格或者逗号隔开多个用户名
auth users = sate
# 模块验证密码文件 可放在全局配置里
secrets file = /etc/rsync/rsyncd.secrets
# 剔除某些文件或目录，不同步
exclude = lost+found/ conf/ man/

```

# academic conference

SOSP - Symposium on Operating Systems Principles
OSDI - Symposium on Operating Systems Design and Implementation
NSDI - Network Systems Design and Implementation
FAST - Conference on File and Storage Technologies
ASPLOS - Architectural Support for Programming Languages and Operating Systems
ATC - USENIX Annual Technical Conference
EuroSys
SIGCOMM - Computer Communication
SIGMETRICS - Computer/communication system performance
ISCA - International Symposium on Computer Architecture
HotOS - Hot Topics in Operating Systems Workshop
IEEE S&P - Security & Privacy
Usenix Security
ACM CCS - Computer and Communications Security

# leveldb

git clone https://github.com/google/leveldb.git
git submodule update --init
cmake -B build -G Ninja -DBUILD_SHARED_LIBS=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'
time cmake --build build

https://github.com/google/leveldb.git

mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release .. && time cmake --build .


# skia

git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
export PATH="$PATH":`pwd`/depot_tools

mkdir skia
cd skia

gclient config https://skia.googlesource.com/skia.git
gclient sync

python3 tools/git-sync-deps
bin/gn gen out/Shared --args='is_official_build=true is_component_build=true'
bin/gn gen out/Debug
ninja -C out/Debug
ninja -C out/Debug/ -t compdb > compile_commands.json

# yjs-demons systemd

sudo systemctl daemon-reload
sudo systemctl restart docs.service

systemctl status docs.service
sudo journalctl -u docs

```
[Unit]
# 服务名称，可自定义
Description = docs

[Service]
Type = simple
WorkingDirectory=/home/tannal/tannalwork/projects/yjs-demos/
ExecStart = /bin/bash -c 'PATH=/home/tannal/.nvm/versions/node/v20.10.0/bin/:$PATH pnpm start'
Restart=always

[Install]
WantedBy = multi-user.target

```

# .gitconfig

```
#--------------------------------------------------------------------------
# .gitconfig
#	GIT global settings
#	Copyright (c) 2010-2024, Michael Paquier
#--------------------------------------------------------------------------
[alias]
	# Check whitespaces
	check-whitespace = !git diff-tree --check $(git hash-object -t tree /dev/null) HEAD
	# Shorten diff for copied, renamed and deleted files
	diff-short = diff --find-renames --irreversible-delete --break-rewrites --find-copies
	# Execution of raw command
	exec = "!exec "
	# Shorten copied, renamed and deleted files for a patch generated
	format-patch-short = format-patch --find-renames --irreversible-delete --break-rewrites --find-copies
	# Print graph of git commit history
	graph = log --graph --date-order -C -M --pretty=format:\"<%h> %cd [%cn] %Cgreen%d%Creset %s\" --all --date=short
	# List files part of a commit.  Can be easily combined with git add.
	# This needs a single commit number at its tail.
	list-files = diff-tree --no-commit-id --name-only -r
	# Shorten log information for copied, renamed and deleted files
	log-short = log --find-renames --irreversible-delete --break-rewrites --find-copies -p
	# Show top level repository
	root = rev-parse --show-toplevel
	# Remove last commit
	undo = reset --hard HEAD~1
	# Remove last commit
	undo-soft = reset --soft HEAD~1
[color]
	# Print output in color if possible
	ui = auto
[core]
	# 4 spaces per tab when using the pager
	pager = less --tabs=4
	# Exclusion of several file types
	excludesfile = ~/.gitconfig_excludes
[diff]
	# Detect files renamed as well as copies
	renames = copies
	algorithm = histogram
	# Ordering of files in diffs, for PostgreSQL
	# XXX: If this becomes annoying for other projects, this had better
	# live as a local setting.
	orderFile = ~/.gitconfig_orderfile
[format]
	pretty = format:%C(blue)commit: %<(14,trunc)%H%C(reset)%n%C(green)author: %aN <%aE>%C(reset)%n%C(green)date: %aD%C(reset)%n%C(yellow)committer: %cN <%ce>%C(reset)%n%C(yellow)date: %cD%C(reset)%n%B
[log]
	# Do not use any mailmap file to map author name and emails.
	mailmap = false
[push]
	# Push branches having same name remotely and locally
	default = matching
[include]
	# Private parameters, done at the end to override other values
	# if necessary
	path = .gitconfig_extra

```

# projects

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

```


# 12900kf

```
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



```
# elf

```
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

# y-websocket systemd

sudo vim /etc/systemd/system/y-websocket.service
[Unit]
# 服务名称，可自定义
Description = docs

[Service]
Type = simple
WorkingDirectory=/home/tannal/tannalwork/projects/yjs-demos/
ExecStart = /bin/bash -c 'PATH=/home/tannal/.nvm/versions/node/v20.11.1/bin/:$PATH pnpm start'
Restart=always

[Install]
WantedBy = multi-user.target


# Greg Brockman bio

深度学习与NLP
​
在高中毕业后的间隔年里，我曾认真学过编程。我读过图灵的《计算机器与智能》一书，并深受启发：代码能理解那些编写代码者所不能理解的东西。于是我准备着手写一个聊天机器人。那么写出来有多难呢？我想创建的是能与人正常对话的机器人，但找了很久，似乎没有人能做出这种机器人。我很快便搁置了这个想法，转而专注于创建那些能真正产生影响的系统。

1大学研究项目

读大学时，我对编程语言很感兴趣，由此便进入了AI的大门。编译器和静态分析器能“理解”那些我理解不了的程序，于是我便常用其来做一些非常有用的事情，比如快速生成代码并检验其是否正确。我一直想潜下心来去做编程语言研究，却总是受到新的创业点子和新同事的影响。其实我的同事人都还不错，但这些创业想法可就不敢恭维了。无论在哈佛还是麻省理工，我都努力向那些优秀的人看齐，主动融入他们，并与之共建有用的东西。


大三那年，我发现在校创业没有意义，所以我就和那些创业者面谈，汲取经验。与此同时，我终于开始了编程语言研究之旅。我从一位教授那里获得了研究经费，并招募了一些朋友进行静态缓冲超时检测项目。几周后，帕洛阿托（Palo Alto）一家尚未启动的初创公司联系了我。一般情况我会直接删除这种邮件，但此时我也正准备与初创公司会面，所以我们团队就立即点开了邮件，此时我也发现，他们也正是我一直在寻找的那种人。于是我离开学校，这也意味着我们的缓冲超时检测项目就此搁置了。

2

Stripe生涯

那家公司就是现在的Stripe。在我的帮助下，公司规模从4人扩大到了250人；在我离开后的一年里，又继续扩大到了450人（当然，这份功劳与我无关）。此时公司的发展正蒸蒸日上，无论有我没我，都会继续继续做伟大的事情，所以我准备离开Stripe。我想做的是与优秀之人同行做些有意义的事情，但开发者基础架构并不是那个我想穷尽余生之力去解决的问题。然而，我终于还是找到了那个我想解决的问题：创造出安全的人类级别的AI（human-level AI）。只要这项技术能真正为人类所用，我想一定会引起轰动，并给世界带来积极影响。
（Greg Brockman与Sam Altman）

在我最终决定离职之前，Patrick说Sam Altman有很好的局外人视角，而且见过很多跟我情况类似的人，应该能给我一些好的建议，让我去和他谈谈。在与Sam交谈五分钟后，他说：看来你是完全准备好离职了，后续事宜有什么需要我帮助的吗？我说AI是我的首选（这绝对是我的人生目标），但还不确定现在是否就是做这件事的最佳时机，而且我也不知道最佳的贡献方式是什么。他回答：我们一直在考虑通过YC（译者注：Y Combinator，美国著名创业孵化器）建立一个AI实验室，你或许可以跟我们合作。

3

研究深度学习

大约在这一两周后，我就离开了Stripe，开始着手深入研究AI，想要更好地了解该领域正在发生的事情。仅从Hacker News上的帖子（例如http://karpathy.github.io/2015/05/21/rnn-effectiveness/）就可以看出：人们对AI尤其是对深度学习的关注度越来越高。但在进入该领域时，我仍然是持有合理怀疑的，在投身AI之前，我想确定一切都是可行的。我的第一个目标是弄清楚深度学习到底是什么。然而事实证明这并非易事。例如，http://deeplearning.net上只是说“深度学习是机器学习研究的一个新领域，引入深度学习的目的是使其更接近于最初的目标——人工智能”。虽然这听起来很令人兴奋，然而却并没有说清楚到底什么是深度学习。幸运的是，我有一些从事AI行业的朋友：Dario Amodei（曾任OpenAI研究主管，现Anthropic创始人和CEO）和Chris Olah（曾任OpenAI技术主管，现为Anthropic联合创始人）。我向他们征求了一些意见，他们给了我一些很好的入门资源，其中最有用的是Michael Nielsen写的书。我读完后还在Kaggle上练习了新学到的技能（在第一次比赛时我就拿到了第一名！）。一路走来，我不断遇到AI领域中那些超级聪明的人，并与我大学时最聪明的一些朋友重新建立了联系，例如现在在该领域工作的Paul Christiano（曾任OpenAI研究员，现Alignment Research Center创始人）和Jacob Steinhardt（加州伯克利分校助理教授）。我觉得这是一个强烈的信号。我了解得越多，就越相信AI已准备好散发自己的光芒。深度学习的能力简直令人难以置信，比如，我们现在可以极其准确地对图像中的目标进行分类（2014年的XKCD就已经实现），语音识别非常精准，还可以生成十分逼真的图像。不过虽然这些技术足够新，但到现在为止还没有改变人们的生活方式，它们如今的影响还仅限于支持某些产品实现特定功能。有一位朋友曾开发过Facebook News Feed。还记得我曾对他说过这样一句话：简单的算法，大量的数据。每个人都试图兜售很酷的新AI算法，但实际上只需要扩展逻辑回归（logistic regression）就会非常奏效。而他对此持怀疑态度。然后我就拿出了谷歌翻译App，将其设置为飞行模式，并向他演示了如何直接翻译图片上的文字。他对此印象颇深，并承认简单的算法对此无济于事（这背后主要是深度学习在发挥作用，不过这不是重点，重点是它有效。）

4

创业想法诞生

Sam Altman在2015年6月联系我，问我是否已经想好下一步该做什么了，我告诉他目前的计划是明年开一家AI公司。然后我们打了通电话，他提到他们正在推进YC的AI项目。我问：实验室的目的是什么？“建立安全的人类级AI”，他说。在那一刻我就知道，他很适合当我下一家公司的合作伙伴。现在很少有人敢于明确尝试构建人类级AI。我意识到，有时候一项成就只需要有个胆大的人宣布目标，然后合适的人就会加入其中。大约一个月后，Sam在门洛帕克（Menlo Park）举办了一场晚宴，参加宴会的有Dario、Chris、Paul、Ilya Sutskever、Elon Musk、Sam和其他一些人。我们讨论了AI领域的现状、目前离人类级AI还有多远以及实现人类级AI还需要的东西等等。整场对话围绕着“什么样的组织可以最好地确保AI的有益性”展开。答案很明显：必须是非营利组织，因为没有任何利益冲突来影响其使命。此外，这样组织还必须保持在研究的前沿（根据Alan Kay的名言，“预测未来的最好方法就是创造未来”）。为此，该组织需要有世界上最好的AI研究人员。所以问题就变成了：是否有可能从头开始创建一个拥有最优秀AI研究人员的实验室？我们的结论：还是有机会。这是我第一次见到Elon和Ilya，我对他们的印象非常深刻。Elon充满了好奇心，他真诚地征求他人意见并用心倾听每一份回答；而Ilya则是技术基础的源泉，他是一位头脑清晰的技术专家，知识广博，视野开阔，并且总是能够深入到当前系统局限性和功能的具体细节。我请Ilya对深度学习给出一个好的定义，以下是他的回答：有监督深度学习的目标是解决几乎所有“将X映射到Y”形式的问题。X包括图像、语音或文本，Y包括类别甚至句子。将图像映射到类别、将语音映射到文本、将文本映射到类别等等，如此种种，深度学习都是非常有用的，而且其他方法无法做到。深度学习一大吸引人的特点是它在很大程度上是独立于其他领域之外：在一个领域中学到的许多东西可以适用于其他领域。深度学习模型中建立了抽象层，这些抽象可以完成工作，但很难理解它们究竟是如何做到的。模型通过使用反向传播算法（简单且高效）逐渐改变神经网络的突触强度来学习。因此，我们可以用极少的代码来构建出大规模复杂的系统（因为我们只需要编写模型和学习算法的代码，而非最终结果）。晚宴结束后，Sam送我回城里。我们都认同值得在AI领域做点什么。我知道，只有当有人愿意全心全意地弄清楚这究竟是什么，谁又能够加入其中，我们的愿景才会成为现实。那就让我来当这样的人吧。所以，我明天又要构建一些有影响力的东西了。

5

OpenAI的愿景

那次晚宴上，我们谈论了成立OpenAI实验室。虽然每个来参加晚宴的人都各抒己见，但并没有一个清晰的愿景，而Elon和Sam则提出了自己的想法：OpenAI旨在构建安全的人工智能以造福人类。我也想尽可能贡献自己的力量，为了如愿以偿，便开始和Sam一起组建团队。不过我们缺少了一个核心要素，即一位AI技术远见者，其直觉和想法可以帮助我们取得突破。

（从左至右依次为Ilya Sutskever, Alex Krizhevsky, Geoffrey Hinton）

显然，Ilya Sutskever是最佳人选。Ilya可以说是一位艺术家，他常常通过机器学习来表达自己的感受（有时也会通过绘画来表达）。Geoffrey Hinton（深度学习教父）曾告诉我，AlexNet之所以能引发一场计算机视觉深度学习革命，在于Alex Krizhevsky高超的GPU编码技能及Ilya的信念，即深度神经网络必定会在ImageNet竞赛中获胜。（Geoff对自己贡献的管理技巧感到无比自豪。Alex非常讨厌写论文，Geoff告诉他，他在ImageNet上的性能每提高1%，他就可以把论文推迟一周。结果Alex拖延了15周。)一直以来，我都认为自己只能与相识多年的朋友共创公司。然而事实并非如此。八月下旬，我和Ilya在山景城共进晚餐，当时我就知道我们会一起合作，在此之前，我们也只在七月见过一次。我和Ilya聊得十分投机，尽管我对机器学习研究的了解不多，他对工程和团队建设的认识也没有那么深入，但我们对彼此的成就印象十分深刻，也希望能够相互学习。我们交流了彼此的看法、汲取了彼此的长处。Ilya认为，顶级研究人员希望在人工智能组织工作，而该组织致力于为世界创造最佳成果。在我看来，要想解决一些棘手问题，则需将私营企业的资源与学术界的使命相结合。若无外界干预，人工智能将会像自动驾驶汽车一样发挥自身的作用。一旦人工智能的潜力得以证实，人们就会与之展开合作，而后则是一场场技术竞赛。不过，人类级别的人工智能将会是一种与众不同的变革性技术，有其独特的风险和收益。我们看到了这一机遇：在人工智能领域展开合作，汇集众多顶尖研究人员，以取得史上最重大的科技突破。Ilya和我一直在讨论团队组建方案，直到该方案得以落实。期间，我们讨论了战略（即将从事什么工作）、文化（想雇用的人员，即同等重视工程和研究的人员）和策略（举办每日阅读小组）。Alan Kay与我们共进晚餐时，向我们讲述了施乐帕洛阿尔托研究中心（Xerox PARC）的故事，包括Alto的诞生及用硬件“在未来生存”，这些硬件在十年内将花费1000美元。事后，Ilya对用餐期间的谈话做了巧妙总结：“虽然Alan的话我只听懂了一半，但令人振奋不已。不过这顿饭帮我们验证了许多假设，即怎样才能构建一支能将工程与研究相结合的有影响力的团队。

6

早期团队的招募

由于Ilya还在谷歌工作，因此无法帮忙招聘，这一工作就落到了我身上。8月至11月，由我负责创办团队。不过，我对人工智能并不熟悉，不清楚如何招募优秀的研究人员。我首先关注的是7月参加过晚宴的人，但不能确认具体人选。下一步，便是通过人际网络与这些人取得联系，并依次寻求他们的推荐，这与我以往的招聘方式有所不同。对于初创公司而言，首要挑战总是要向候选人“兜售”使命，但在OpenAI，使命立刻引发大家的共鸣。于我而言，挑战在于如何说服候选人相信这个未成形的组织。




人工智能领域顶尖人才的人际网络对我帮助很大。一位朋友引荐我认识Andrej Karpathy和Wojciech Zaremba（OpenAI联合创始人），由于我并未从事该领域工作，他们对我说的话表示怀疑。Yoshua Bengio又将我引荐给Durk Kingma（曾任OpenAI研究科学家，现在谷歌研究团队），当时后者对于我的提议表示很感兴趣，不过这种兴趣转瞬即逝。真正的转折点是John Schulman（OpenAI联合创始人、研究科学家）的评价，我跟他聊到这一组织的成立，他表示这样的组织正是他所追寻的，能将学术界的开放与使命同私企的资源相结合，因此加入了我们。John的支持也引起了Andrej和Wojciech的关注。招聘工程师相对容易一些。Trevor Blackwell是一位机器人专家，也是YC的合伙人，他一直在与Sam讨论我们正在计划的疯狂想法。Vicki Cheung（现Gantry联合创始人）是在我们成立赞助机构“YC Research（现为OpenResearch）”之后申请加入的。那时，我们虽未表明研究领域是AI，但她深受YC Research构架的鼓舞，并表示很乐意参与我们团队的所有工作。11月初，虽然我们对创始团队有了更深入的了解，但仍然需要让大家正式加入进来。在Sam的建议下，我们邀请了所有候选人去户外漫步。期间，人人都真切地表达了内心想法、观点，才思泉涌（实际上，该地也是Andrej提出Universe之地）。回程中，一路上交通堵塞。不过几乎没人留意到这一点，因为大家聊得太投入了。

我们给此次活动的参与者都发了offer，并将offer的截止日期设置为12月1日，这样我们就可以在12月初的NIPS（NeurIPS）机器学习会议上发布成员加入的消息。“月末”就这样开始了。Sam、Elon还有我和每个人都聊了聊，主要是让大家相信这件事的真实性。除了一名完全无意涉足人工智能的工程师外，其他候选人都接受了我们的offer。Fred Brooks在《人月神话》一书中提及了Robert Heinlein的故事，该故事讲述了“登月”项目。该项目的总工程师总会被运营任务分散注意力，例如关于运输车或电话的决策，这种情况一直持续到他收到一份报告，据报告显示不再让他负责所有与技术无关的任务。这一故事给我留下了印象深刻，我认为它同样适用于构建人工智能的项目。技术领导除了做实际技术工作以外，同时还应该亲自做决策。我不知道自己的工程技能何时才能派上用场，不过在此期间，我决定尽我所能帮Ilya分担与研究无关的任务。2016年1月4日，我们整个团队来到第一间办公室（也就是我的公寓）开始工作。讨论中，John和Ilya转身打算在白板上写点些什么，却发现这儿没有白板。我立即给他们买了一块白板，还有一些办公用品。

我们的第一间办公室（配有白板）在一月剩下的时间里，我负责组织团队，帮忙确定哪些人负责哪些工作，以及团队想达成的目标。我们讨论了研究人员需要具备什么品质，践行公司理念，设计并确保面试顺利进行。此外，我们还谈论了愿景、工作方式以及想要达成的目标。我和Vicki购买了服务器，创建了Google Apps帐户，同时对我们12月启动的Kubernetes集群进行了维护。余下的时间，我阅读了Ian Goodfellow（GAN网络发明者）的深度学习书籍（并写下了书评，由于我的评论比其官方评审员的评论更加全面，给他留下了深刻印象。因此，这也不失为一种招聘策略）。

7

Gym库

比起使用新的数据集，使用一种新的算法通常能解决机器学习中的问题，Wojciech建议构建一个库来形成强化学习环境的标准（实际上是动态数据集），现在称之为Gym。这个代码库的质量很快成为我们迭代速度的高阶位（high-order bit）。二月底，我和John讨论了Gym的公开发布时间。按照目前的发展情况，他认为可能要到今年年底才能发布。

（我们正在用机器学习训练Fetch机器人。Gym支持控制物理机器人和模拟机器人。）一时之间，工程学成了研究进展的瓶颈。Ilya与我互换了角色，由他负责行政工作，这样我就可以专注于技术工作。和John考察了这项工作之后，我们知道在四月底之前就能构建好Gym。在Stripe时，我发现了一个能够直接创建软件系统的可重复模式，即专注于软件，排除一切干扰，从早工作到晚。这样一来便能激励大家贡献自己最好的作品（重要的是，是以输出质量来衡量而不是工作时间）。这是我感觉最有活力的时候：编程就如魔法变成现实一般，我所想象和描述的事情都将成为可能。这种模式产生了Stripe信用卡保险库（2010年构建完毕，也就是在我假期回家的两周内完成的）、信用卡授权流程（在三周内就能建成，而银行构建周期却需要6-12个月）和夺旗赛（通常我和其他人都要花三周的时间）。从战术上讲，我可以选择一个“试发行”日期和“正式”发布日期，间隔一两周；我从未选择过“试发行”日期，但从未错过“正式”发布日期。随之而来的是从未面临过的挑战。由于我并非该领域的专家，起初，引起了很多摩擦。我会构造一个抽象的框架来帮助Wojciech的工作顺利进行，而John会发现这一举动阻碍了他的工作进程。但很快，我就了解到哪些决定会影响研究的工作流程（例如人们如何记录指标）以及哪些细节研究人员不会关注（例如人们如何录制视频）。在确定了案例对研究的重要性之后，要保持一定的谦逊，才能做出最佳选择。我通常会提出五个可能的备选方案，John则会指出其中有四个方案都不行。但大多数设计决策可以通过软件工程的直觉做出，而无需深入了解相关领域。幸运的是，我不是一个人。大约在Gym发布的前六周，曾与我在Stripe一起研究CTF 3的Jonas Schneider联系了我。短短几天时间，我们就在Gym上建立了合作关系。因为他人在德国，所以我们通过每日交接最终成功地完成了该项目。对于已经建立好工作关系的人来说，这真的很奇妙，若一切从头开始，我们不会保持如此紧密的工作关系。

（Gym发布后不久，我们在ICLR（国际表征学习大会）上分发OpenAI的T恤。）

总的来说，机器学习系统可视为机器学习的核心之一——通常是一种高级算法，要想理解该算法，至少需要阅读过几章Ian的书——涉及大量软件工程的内容。工程可以围绕数据进行改组，提供输入和输出的封装器，或调度分布式代码，这些都会都以黑盒形式与核心（core）连接。我们在工程和研究方面作出的努力达到一定程度时，机器学习就会取得进步。工程方面每多一分努力（例如减少Universe延迟），我们的模型问题就会逐渐变得更容易，并且有机会完成当前研究。

8

Universe平台




在今年4月Gym上线后，我和Ilya开始调整组织流程。Sam和Elon都会到访公司，提出一些指导意见，我们会根据其指导来确定团队的结构及目标。

（团队在第一间办公室工作的场景。当时办公室有白板，只是图片中未显示。）

多样、复杂的AI环境是必不可少的。Andrej提出了一个不错的建议，即创建一个Agent来控制Web浏览器，但这与Selenium测试工具有所冲突。我开始考虑使用VNC，以允许Agent从像素驱动整个桌面。但我们发现，这种方法存在许多风险。例如，2013年DeepMind发布的Atari文章提出，他们花了50个小时从像素训练Pong游戏，我们的环境将比Pong更难。即使是做小规模的实验，我们也需要花几天时间，而且不会取得任何进展。因此，我们设定了一个降低内部风险的目标，即让Agent在一小时内学会Pong（如今我们已取得了突破：十分钟内便能解决Pong遇到的问题）。就像构建Gym时那样，我专注于构建VNC系统，现称之为Universe。与Gym不同的是，该项目并非旨在支持我们现有的研究方式，而是提出全新的问题。关于这一点，我们每个团队都有负责人，他们负责照顾自身团队的成员，我们的工程师Jie Tang已开始带头招聘。因此，行政这一重担并没有完全落在Ilya身上。这十分幸运，因为这样Ilya就能为该风险项目的首个版本构建Agent。

一个从整个动作空间随机抽样的Universe Agent（即随意点击、按键）。更多表现良好的Agent请参阅Universe发布的帖子。Universe项目耗时相当长，因此，需要合理分配时间来运营项目。我找到了一个平衡点，编码时，我会将时间进行划分。一次会议会扼杀整个上午/下午的生产力，若上午和下午都有会议，我将精疲力竭，从而导致晚间的编码效率大大降低。因此，我开始将会议时间限制在清晨或午餐后，且每天的会议次数低于三次，隔天的会议次数不超过一次。搭建Universe本身就是一项系统研究工作：虽然高级规范很简单（允许Agent使用键盘/鼠标/屏幕），但从来没有人尝试过构建类似的系统。长期以来，人类一直可以用VNC控制一台远程机器，但还无法实现以编程方式同时控制数十台机器。当我们需要衡量系统的端到端延迟时，Catherine Olsson和我构建了一个系统来将时间戳嵌入图像中。有时挑战不是技术上的：当研究因为训练数据有限而受阻时，Tom Brown在24小时内就组建了一个外包团队来玩游戏。有时候挑战也可能很难以理解，比如当Jonathan Gray注意到由于外包人员的笔记本电脑CPU较低端，游戏动态可能会与AI有所不同。一天，当我正在努力重组一些JSON基准规范时，我意识到：我们需要重新构建这些规范，因为没有人从未尝试过在数千个游戏中对单个Agent进行基准测试。在OpenAI，做艰苦的工作也是最基本的。在接下来的几个月里，由Dario Amodei和Rafał Józefowicz负责Universe的研究工作。他们都是夜猫子，我也和他们一起熬过了很多个夜晚，解决研究中遇到的问题。有时我也想躺在床上睡觉，但每修复一个Bug都会使研究加速几个小时。每个人的工作中都有一些非常有用的东西，能让研究人员提出人类此前从未有过的问题。

Universe团队在办公室开会到发布时，Universe团队已经有约20个人了。Universe现在是一个旗舰项目，也是我们研究战略的核心部分。Universe的例子恰好说明“工程”是如何成为当今ML研究的瓶颈，这也让我知道为什么有那么几天只想读Ian的书了。

9

下一步发展方向

我们现在是一个拥有四十人的公司，需要有人全力来优化团队。自OpenAI成立以来，我们一直在寻找合适的首任技术经理。几个月前，Sam向我介绍了一位特别出色的工程执行人：Erika Reinhardt。Erika曾在Planet Labs担任产品工程总监，现在在和Sam一起运营http://voteplz.org。在Planet Labs时，Erika是对端到端卫星成像系统了解最深的人之一。她工作努力，自驱力强，总能把事情做好，前同事都说她是所能遇到的最聪明的人。Sam和我就准备邀请她加入公司。

公司团建，2016年10月但在选举会和Universe发布会上与我们合作时才是她最具魅力的时刻，她发现她的领导技能在这种环境中非常适用。她告诉我：在看到OpenAI在参议院举办的首次AI听证会上发言的那一刻，她就下定决定要加入OpenAI。当时OpenAI说：我们正处于重大技术变革的开端，此时最重要就是要把握时机。

在Stripe时，Marc Hedlund和我常会遇到他在之前的许多公司中都遇到的问题，所以他喜欢开玩笑说所有公司都一样。就这一点而言，确实有现实依据：如果将范围缩小一点，就会发现公司都是围绕一个目标来把人组织起来。但每个公司要解决的问题又不一样，这又决定了公司之间会有所差异。大多数初创公司都是先创造出一种技术，然后随着时间的推移对其进行运营和扩展。OpenAI是创造新技术的工厂，这意味着我们必须构建公司来创造新事物。我们需要维护基础设施和大型代码库，但它们又满足了我们快速行动、创新和通过结合软件工程和机器学习研究来达到新高度的需求。在OpenAI当CTO的这段时光里，我做的正好是我最喜欢做的事：写代码。但即便如此，人仍然是我关注的焦点，所以我在OpenAI的故事是与社会的故事，而不是与技术的故事。

在未来，我们团队要继续携手并进，共同应对海因莱因短篇小说中“卡车或电话”的挑战，OpenAI才能持续发展。在此，我向Ilya、Sam、Elon以及为OpenAI付出过的每一个人表示衷心的感谢。

发布于 2023-03-17 20:19


# ubuntu source.lists

ubuntu 22.04 LTS jammy
sudo vim /etc/apt/sources.list
```
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse

deb http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse
# deb-src http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse
# # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse
```

# japanese

[00:00:00.240 --> 00:00:02.400]  みなさんこんにちは、MijunbossのKです。
[00:00:02.400 --> 00:00:06.200]  たくさんの方が、私たち日本人の人々に
[00:00:06.200 --> 00:00:09.920]  最近のミス・ジャパンのコントローラーについて
[00:00:09.920 --> 00:00:12.000]  何かを聞きたいと思っています。
[00:00:12.000 --> 00:00:13.520]  特に、彼女は日本人にとっては伝統的に見えないからです。
[00:00:13.520 --> 00:00:17.320]  しかし、彼女はウクレレ生まれの自然な日本人です。
[00:00:17.320 --> 00:00:19.720]  そのため、私たちは東京の街を踏み出して、
[00:00:19.720 --> 00:00:22.720]  地域のインサイトを早く集めることにしました。
[00:00:22.720 --> 00:00:23.960]  でも、なぜか知っていますか?
[00:00:23.960 --> 00:00:26.400]  このビデオを発表する日に、
[00:00:26.400 --> 00:00:30.960]  彼女が伝統的な伝統的な事件によって伝統的に彼女の宝を与えることが発生しました。
[00:00:30.960 --> 00:00:32.760]  彼女のプライバシーを尊敬するために、
[00:00:32.760 --> 00:00:35.840]  私たちはこのコントローラーのアスペクトに入ることはできません。
[00:00:35.840 --> 00:00:38.200]  しかし、彼女がミス・ジャパンのタイトルを獲得したのは、
[00:00:38.200 --> 00:00:41.520]  多くの面白い文化的な質問です。
[00:00:41.520 --> 00:00:44.040]  アジアからもっと真実的なインサイトや
[00:00:44.040 --> 00:00:45.840]  独特のストリートインタビューがある場合、
[00:00:45.840 --> 00:00:48.360]  どこかでテーマを選択することができます。
[00:00:48.360 --> 00:00:50.240]  asianboss.ioをチェックしてください。
[00:00:50.240 --> 00:00:53.600]  そして、私たちの動きの一部に参加し、文化の間隔を広げることができます。
[00:00:53.600 --> 00:00:56.400]  短い時間で特別な供給ができます。
[00:00:56.400 --> 00:00:59.880]  詳細は下の説明欄のリンクからチェックしてください。
[00:00:59.880 --> 00:01:03.400]  では、日本の人たちが何を言うのか聞きましょう。
[00:01:03.400 --> 00:01:08.840]  まず、先週行われましたミス日本コンテストについてご存知ですか?
[00:01:08.840 --> 00:01:10.400]  いや、ご存知じゃないです。
[00:01:10.400 --> 00:01:11.560]  見たことないです。
[00:01:11.560 --> 00:01:13.600]  残念ですけど、知りませんでした。
[00:01:13.600 --> 00:01:18.280]  ミス日本は知ってますけど、見てはないですね。
[00:01:18.280 --> 00:01:19.720]  知らなかったです、私も。
[00:01:19.720 --> 00:01:22.360]  私、存じてます。
[00:01:22.360 --> 00:01:24.960]  見事グランプリに輝いたのがこちらの方です。
[00:01:24.960 --> 00:01:27.440]  めっちゃ綺麗。
[00:01:27.440 --> 00:01:32.760]  ちょっと感じ、目元とかはくっきりしてて、日本人っぽいなって思いました。
[00:01:32.760 --> 00:01:36.800]  ハーフっぽくて、ちょっと日本人っぽい感じですね。
[00:01:36.800 --> 00:01:39.400]  あ、すげえ。めっちゃ綺麗。
[00:01:39.400 --> 00:01:40.800]  えっ、かわいい。
[00:01:40.800 --> 00:01:42.720]  パッと見て、どういった印象を受けますか?
[00:01:42.720 --> 00:01:45.320]  え、すっごい綺麗です。なんか人形みたい。
[00:01:45.320 --> 00:01:48.000]  どの辺がすごい綺麗、印象に残る感じですか?
[00:01:48.000 --> 00:01:51.800]  肌の綺麗さと彫りの深さ。
[00:01:51.800 --> 00:01:53.800]  この二重が羨ましいです。
[00:01:53.800 --> 00:01:55.560]  日本感ゼロですよね。
[00:01:55.560 --> 00:01:56.760]  感じないです。
[00:01:56.760 --> 00:01:58.960]  どういった部分、なんでそう思われるんですか?
[00:01:58.960 --> 00:02:02.400]  でもなんか、見た目がもう、鼻が高いし、
[00:02:02.400 --> 00:02:02.720]  もうなんか、
[00:02:02.720 --> 00:02:03.840]  なんか、あれですよね。
[00:02:03.840 --> 00:02:05.840]  外国人って感じしますよね。
[00:02:05.840 --> 00:02:07.400]  ハーフ顔なんで。
[00:02:07.400 --> 00:02:10.240]  外国の方ですね。
[00:02:10.240 --> 00:02:14.720]  こちらの写真をパッと見て、どういう印象を受けますか?
[00:02:14.720 --> 00:02:19.800]  あ、あの、日本ミスグランプリですけど、
[00:02:19.800 --> 00:02:24.480]  日本人なのかなっていうか、東洋系の人かなと一瞬思ったんですが、
[00:02:24.480 --> 00:02:28.720]  でも私の考えとしては、外国の方でも誰でも、
[00:02:28.720 --> 00:02:31.960]  あの、今グローブがあれですから、いいと思います。
[00:02:31.960 --> 00:02:32.680]  綺麗な方です。
[00:02:32.680 --> 00:02:33.960]  そうですね。
[00:02:33.960 --> 00:02:37.920]  ミス日本の優勝者であるCのカロリーナさんっていう名前なんですけれども、
[00:02:37.920 --> 00:02:44.200]  あの、先ほども申し上げた通り、日本の血が全く入っていないウクライナ生まれの方でしたと。
[00:02:44.200 --> 00:02:51.080]  そんな彼女が日本を代表、日本代表として、世界的なミスコンに出場することについて、
[00:02:51.080 --> 00:02:53.400]  改めて、どう思われますか?
[00:02:53.400 --> 00:03:02.640]  日本人の血が無いっていうのも、まあ、一つの論争の点ではあるとは思うんですけど、でも、例えば、
[00:03:02.640 --> 00:03:11.000]  日本で育たれてとか、うちの子どもたちも出身は日本ではない、生まれは日本ではないので、
[00:03:11.000 --> 00:03:15.960]  なので、なんかよくその他、出身地その他とかってなっちゃうんですけど、
[00:03:15.960 --> 00:03:22.160]  でも、それもまた一つの個性でもあって、はい、日本ももっともっとこう、
[00:03:22.160 --> 00:03:32.600]  いろいろ受け入れていくことの、あの、一つのこう、最初のステップみたいな大きなステップになればいいかなって私は思います。
[00:03:32.600 --> 00:03:40.600]  パッと見、日本人だとは思わなかったので、なんか、どこの大会なのかなってちょっと思っちゃった。
[00:03:40.600 --> 00:03:45.360]  まあ、まあ、20年以上日本で暮らしてても、まあ、日本人としてはまあ、見難いって言いますか?
[00:03:45.360 --> 00:03:53.200]  いや、心が日本人であれば、同じ教育受けてれば、同じ思想でしょうし、日本人として問題ないと思いますけど。
[00:03:53.200 --> 00:04:02.560]  僕はまあ、一応、日本の、日本人の中でやってるんだったら、純、純日本人じゃないからば、
[00:04:02.560 --> 00:04:10.560]  きれいやけど、その、日本人ではまあ、ないので、それはちょっと違うかなとは思います。
[00:04:10.560 --> 00:04:17.560]  ウクライナ生まれって言いながらも、実は、あの、カロリーナさん、5歳の時に日本に来て、まあ、そっから20年以上日本で暮らし、
[00:04:17.560 --> 00:04:23.560]  まあ、日本語もすごい流暢に話せる方なんですけれども、まあ、これを聞いて、お考えの方は変わったりします?
[00:04:23.560 --> 00:04:41.560]  まあ、日本人、日本に住んでるから日本人なのはわかるんですけど、まあ、まあ、骨格とかが全然違うんで、それはいくら日本にいてもいなくても、日本人ではないんで、そこは変わらないですね。
[00:04:41.560 --> 00:04:45.560]  なるほど、お考えの方は変わらないですね。お友達の意見聞いてどう思います?
[00:04:45.560 --> 00:04:49.560]  侍スピリットを持ってたら、誰でも日本人やなと思いますけどね、はい。
[00:04:49.560 --> 00:05:00.000]  あの、スポーツの世界だったら、例えば、今だったら、日本代表を背負ってても、もうほぼほぼ海外だよねって人が出てると思うんですけど

https://www.youtube.com/watch?v=Nwg8ZxycA1s&t=75s

[00:00:00.000 --> 00:00:04.440]  今の月々または1日のお給料を教えていただくことは可能でしょうか?
[00:00:04.440 --> 00:00:05.000]  大丈夫です。
[00:00:05.000 --> 00:00:08.420]  23から5くらい。
[00:00:08.420 --> 00:00:10.200]  20くらいです。
[00:00:10.200 --> 00:00:13.160]  お仕事は何をされていらっしゃいますか?
[00:00:13.160 --> 00:00:16.380]  ジュエリー系メーカーです。
[00:00:16.380 --> 00:00:19.440]  好きだと37くらいですね。
[00:00:19.440 --> 00:00:20.360]  ありがとうございます。
[00:00:20.360 --> 00:00:22.360]  お仕事は何をなされているんですか?
[00:00:22.360 --> 00:00:23.960]  広告代理店ですね。
[00:00:23.960 --> 00:00:26.460]  会社員なんですけど企画職ですね。
[00:00:26.460 --> 00:00:27.740]  50万円くらいかな。

[00:00:27.740 --> 00:00:28.860]  ありがとうございました。
[00:00:28.860 --> 00:00:31.480]  私は母なので。

[00:00:31.480 --> 00:00:38.260]  月々、毎月だと40万くらいですかね。
[00:00:38.260 --> 00:00:40.720]  トレーディングカンパニー的な感じです。

[00:00:40.720 --> 00:00:49.060]  今はレストランでやっていて、ホールでいろんな人とお話をしています。
[00:00:49.060 --> 00:00:51.120]  ウイトレスさんということで。
[00:00:51.120 --> 00:00:56.720]  週に2、3回とかで、1、2回かな。
[00:00:56.720 --> 00:00:58.840]  先月は2万5千円。
[00:00:59.060 --> 00:01:00.160]  はい、5千円でしたね。


[00:01:00.160 --> 00:01:03.060]  教職ですかね。
[00:01:03.060 --> 00:01:05.060]  1000万円くらいかな。
[00:01:05.060 --> 00:01:07.440]  年収で。
[00:01:07.440 --> 00:01:13.280]  20万以上くらいだから、生活はできています。
[00:01:13.280 --> 00:01:16.220]  お仕事はどういうものをされているんですか?
[00:01:16.220 --> 00:01:17.960]  介護系です。


[00:01:17.960 --> 00:01:19.240]  バイト?
[00:01:19.240 --> 00:01:20.440]  バイトで大丈夫。
[00:01:20.440 --> 00:01:23.260]  だいたい7万円くらい。
[00:01:23.260 --> 00:01:23.760]  月で。
[00:01:23.760 --> 00:01:24.260]  月。
[00:01:24.260 --> 00:01:26.560]  12万とか。
[00:01:26.560 --> 00:01:28.680]  飲食店で働いています。
[00:01:28.680 --> 00:01:30.680]  1万円飲食店です。
[00:01:30.680 --> 00:01:32.680]  5桁の後半、毎日。


[00:01:32.680 --> 00:01:34.680]  お仕事はなにをなされていますか?
[00:01:34.680 --> 00:01:36.680]  刀の職人。
[00:01:36.680 --> 00:01:40.000]  刀の職人さんは、どれくらいやってるんですか?
[00:01:40.000 --> 00:01:53.000]  そうね、まだでもそんな、でもね、昔からだけど、時々辞めたり、時々悪の道に走ったり、マフィアになったり、だから10年くらいかな。
[00:01:53.000 --> 00:01:54.000]  30万くらい。
[00:01:54.000 --> 00:01:57.000]  メーカーの勤務です。
[00:01:57.000 --> 00:02:06.000]  東京はアジアの中でも、生活費が高い都市とされているんですけれども、その東京での生活をしていくのに、現在の収入は十分だと感じますか?
[00:02:06.000 --> 00:02:07.000]  思わないです。
[00:02:07.000 --> 00:02:09.000]  不十分だと思います。
[00:02:09.000 --> 00:02:18.000]  今、実家暮らしなんで、十分と感じてるんですけど、一人暮らし始めたら、足りないかなって感じです。
[00:02:18.000 --> 00:02:20.000]  一人暮らしでいらっしゃいますか?
[00:02:20.000 --> 00:02:24.000]  いや、実家なんで、実家でもちょっと不十分だなと思います。
[00:02:24.000 --> 00:02:26.000]  どういうところが足りないと感じますか?
[00:02:26.000 --> 00:02:36.000]  いや、なんていうんだろうな、もう本当に、例えばこうやって飲む生活とか土日にあった、それが毎週繰り返すってなったら、生活は厳しいかなって思うんで。
[00:02:36.000 --> 00:02:49.000]  足りてはいますけど、例えば遊びとか、少し遠出、日本の地方に行くときは、お金が少し足りないかなと思うんですけど、生活する分には別に全然足りてないですけど。
[00:02:49.000 --> 00:02:55.000]  しましたら、あなたが人生直面した一番の経済的に困難だった出来事っていうのは、どういうことがありましたか?
[00:02:55.000 --> 00:03:08.000]  海外で生活してて、感動されて、親から感動されて、生活を送りますよって手紙でやり取りしてたんだけど、国際電話で来なくなっちゃって、一回来てたんだけど。
[00:03:08.000 --> 00:03:16.000]  で、それから4年ぐらい、無収入で海外で、路上生活みたいな生活を海外で送ってた時はやっぱり一番困った。
[00:03:16.000 --> 00:03:18.000]  それはどちらの国にいらしたんですか?
[00:03:18.000 --> 00:03:19.000]  タイで。
[00:03:19.000 --> 00:03:24.000]  タイなんですね。ありがとうございます。その時はどういう風にして生活をしてらっしゃったんですか?
[00:03:24.000 --> 00:03:37.000]  タイのお寺で、テロワードのお寺にお坊さんと一緒に寝泊まりさせていただいて、お坊さんがいただいたタンブン、ヒンディバートっていうんですかね、お伏せで食べてました。
[00:03:37.000 --> 00:03:44.000]  急に、親が亡くなった時が一番きつかったですね。
[00:03:44.000 --> 00:03:49.000]  その時は何かたくさんお金の出費があったりしましたか?
[00:03:49.000 --> 00:03:53.000]  意外と、知人とか親族の支えがあったから。
[00:03:53.000 --> 00:04:01.000]  その時は持ち越せたから、やっぱり血のつながりってすごいなと思って。
[00:04:01.000 --> 00:04:17.000]  やっぱり受験。大学受験が一番お金がかかって、塾も通わないとやっぱり難しいので、入学にもすごいお金がかかりますし、受験が一番かかったなって思ってます。
[00:04:17.000 --> 00:04:22.000]  昔、家を借りる時にどこも高いなって困ってました。
[00:04:22.000 --> 00:04:24.000]  困ってました。
[00:04:24.000 --> 00:04:27.000]  その時はいくらぐらいが高いと感じましたか?
[00:04:27.000 --> 00:04:32.000]  一部屋で20万円とか。
[00:04:32.000 --> 00:04:36.000]  騙された。詐欺に。
[00:04:36.000 --> 00:04:40.000]  食べるもんもないんだよ。どうすんの?
[00:04:40.000 --> 00:04:44.000]  貧乏だった時の食べるもんとか、何食べてたんですか?
[00:04:44.000 --> 00:04:45.000]  聞きたい?
[00:04:45.000 --> 00:04:46.000]  はい。
[00:04:46.000 --> 00:04:50.000]  マックの捨てたやつを袋開けて食べた。
[00:04:50.000 --> 00:04:51.000]  こっち来るな。
[00:04:51.000 --> 00:04:59.000]  あと炊き出しって日本のシステムがある。月に2回とか公園でそれを食べた。生き延びた。
[00:04:59.000 --> 00:05:03.000]  そういった生活、どれくらいの期間続いたんですか?
[00:05:03.000 --> 00:05:05.000]  4ヶ月ぐらい。
[00:05:05.000 --> 00:05:06.000]  長いですね。
[00:05:06.000 --> 00:05:07.000]  そうそうそう。
[00:05:07.000 --> 00:05:14.000]  では、現在の日本の社会基準を持って自分は貧乏だと感じますか?
[00:05:14.000 --> 00:05:19.000]  いや、中間の辺なんじゃないかなって気はします。年齢的な平均でいくと。
[00:05:19.000 --> 00:05:30.000]  中の女王から付与している。本当に貧乏だったらもう生活できないじゃないですか。
[00:05:30.000 --> 00:05:33.000]  貧乏とは思わないかな。
[00:05:33.000 --> 00:05:35.000]  思わないです。
[00:05:35.000 --> 00:05:44.000]  思わないですね。ありがたいことに仕事もあって働く環境もあるので、貧乏とは思わないです。
[00:05:44.000 --> 00:05:45.000]  全く思わないです。
[00:05:45.000 --> 00:05:47.000]  ありましたね。子供の頃。
[00:05:47.000 --> 00:05:50.000]  その時はどういうことが貧乏だと感じましたか?
[00:05:50.000 --> 00:06:00.000]  貧乏だというか、日本全体が貧しかったんですよ。戦争に負けて。戦後すぐ、僕らは団塊世代って言って。
[00:06:00.000 --> 00:06:07.000]  戦後すぐに3年4年経ったぐらいにたくさんの子供が生まれたその真っ盛りだったんですね。
[00:06:07.000 --> 00:06:11.000]  貧乏ではないけれども、裕福ではないと思います。
[00:06:11.000 --> 00:06:14.000]  なぜそう感じますか?
[00:06:14.000 --> 00:06:16.000]  そうですね。
[00:06:16.000 --> 00:06:33.000]  まあ、困りはしないけど、やっぱりずっと先に貯金がどんどんできるかとかのイメージはちょっと難しそうだから、今は大丈夫だけど、先が心配っていう感じです。
[00:06:33.000 --> 00:06:42.000]  では、貧乏と感じるっていうと、人と比べてのことなのか、それとも日本で全体的に貧乏に日本人がなっているということでしょうか?
[00:06:42.000 --> 00:06:45.000]  うーん、全体的にやっぱり。
[00:06:45.000 --> 00:06:54.000]  やっぱり、毎日の食べ物買うときとかも、高いよねっていろんな人と話しするから、みんなかなって感じです。
[00:06:54.000 --> 00:07:08.000]  いや、やっぱり物価上がってて、給料が上がってないっていうところが主にあるんで、やっぱり経済的にというか、世の中的にどんどん貧乏になってるだろうなっていうのは直感、肌感で感じますね。
[00:07:08.000 --> 00:07:11.000]  どういうものが一番上がったと感じますか?
[00:07:11.000 --> 00:07:14.000]  食費ですね。
[00:07:14.000 --> 00:07:16.000]  全般的に。
[00:07:16.000 --> 00:07:19.000]  全般的に、もう交通費以外は大体上がってるみたいな感じですね。
[00:07:19.000 --> 00:07:25.000]  そういった現象って、いつから続いてると思いますか?
[00:07:25.000 --> 00:07:28.000]  物価が上がり始めたのがコロナじゃないですか。
[00:07:28.000 --> 00:07:31.000]  コロナの影響が大きいと思います。
[00:07:31.000 --> 00:07:36.000]  日本が平均的に貧乏になっていってる原因って何だと思いますか?
[00:07:36.000 --> 00:07:41.000]  今問題になってる、その政府の裏金とかで、福祉に回せる部分のお金が減ってて。
[00:07:41.000 --> 00:07:41.000]  まあ、今問題になってる、その政府の裏金とかで、福祉に回せる部分のお金が減ってて。
[00:07:41.000 --> 00:07:42.000]  まあ、今問題になってる、その政府の裏金とかで、福祉に回せる部分のお金が減ってて。
[00:07:42.000 --> 00:07:45.000]  まあ、今問題になってる、その政府の裏金とかで、福祉に回せる部分のお金が減ってて。
[00:07:45.000 --> 00:07:56.000]  福祉に回せる部分のお金が減ってるから、そこの生活出場品に使うお金が増えてることで、自由に使えるお金が少なくなって、貧乏に感じたり、貧乏になってるんじゃないかなっていうふうに思います。
[00:07:56.000 --> 00:08:03.000]  非正規の方ですね。方たちがすごく増えてる。
[00:08:03.000 --> 00:08:11.000]  上がれないですからね。一変、非正規で10年、20年過ごしてると、そこから正社員になるっていうシステムが日本にはないので、あまり。
[00:08:11.000 --> 00:08:16.000]  なくはないんですけど、なかなかそこからはい上がれないっていうところがやっぱり、それなのかなって思います。
[00:08:16.000 --> 00:08:28.000]  チャレンジする人が増えたんじゃないですかね。安定したアレがもらえるよりも、チャレンジして、少ないお金でも好きなものを突き詰める人が増えて、そう言われてるのかもしれないですね。
[00:08:28.000 --> 00:08:36.000]  YouTuberとか人気なんですよ、今。子供になりたい職業で、多いんで、そうなのかなーみたいな。わかんないですけど。
[00:08:36.000 --> 00:08:40.000]  日本人の東京での平均月収が35万円程度って言われてるんですけど。
[00:08:40.000 --> 00:08:46.000]  本当にそうだと思いますか?それとも、もらってるお給料、それより少ない人が多いんじゃないかなって思いますか?
[00:08:46.000 --> 00:08:47.000]  少ないんじゃない?
[00:08:47.000 --> 00:08:49.000]  少ないと思います。
[00:08:49.000 --> 00:08:54.000]  平均月収で、どれぐらいもらってると思いますか?人は。
[00:08:54.000 --> 00:08:56.000]  25ぐらい?
[00:08:56.000 --> 00:09:02.000]  25とかじゃない?多くて40で、少なくて25とかじゃない?
[00:09:02.000 --> 00:09:09.000]  まあ、これも年齢によるかなとは思ってて、その平均年収が多分40、50代の方とかも入ってるんであれば、それぐらいかなと思います。
[00:09:09.000 --> 00:09:15.000]  で、一番ビジネス層で20代から30代でいくと、35もらってない人の方が多いんじゃないかなと思いますね。
[00:09:15.000 --> 00:09:20.000]  日本で貧乏だと定義される月収っていくらぐらいだと思いますか?
[00:09:20.000 --> 00:09:22.000]  15万以下ぐらい。
[00:09:22.000 --> 00:09:25.000]  手取り20とか?
[00:09:25.000 --> 00:09:29.000]  自分が手取り20万の仕事してたら、私って貧乏だなって思いますか?
[00:09:29.000 --> 00:09:33.000]  節約しないとって感じじゃない?
[00:09:33.000 --> 00:09:36.000]  10万円前後じゃないですかね。
[00:09:36.000 --> 00:09:38.000]  10万円前後だと、東京で暮らしていくのは?
[00:09:38.000 --> 00:09:41.000]  東京で暮らしていくのは、ちょっとカツカツになりそうです。
[00:09:41.000 --> 00:09:42.000]  そうです、そうです。
[00:09:42.000 --> 00:09:49.000]  だから、ネットカフェとかああいうとこで寝泊まりしてる人、若い人、20代とか10代後半ぐらいの人、結構いるって話聞いてるんで、
[00:09:49.000 --> 00:09:57.000]  僕そういう人、10年、15年ぐらい前かな、何人かいたんで、ネットカフェでそういう生活してる方。
[00:09:57.000 --> 00:10:00.000]  だから、全然食べてないから、ガリガリみんな焦っちゃってて。
[00:10:00.000 --> 00:10:07.000]  で、今ちょっとアルバイトやって、パートタイムジョブやって、夜は寝泊まりできないから、ないからネットカフェでみんな寝泊まりしてる。
[00:10:07.000 --> 00:10:12.000]  今でも秋葉原、今のたくさんそういうネットカフェがたくさんありますけど。
[00:10:12.000 --> 00:10:18.000]  では、何の心配もなく、東京で快適に暮らすには、いくらぐらい必要だと思いますか?
[00:10:18.000 --> 00:10:22.000]  何の心配もなく、40万ぐらいはあった方がいいんじゃないですかね。
[00:10:22.000 --> 00:10:24.000]  どれぐらい必要だと思いますか?
[00:10:24.000 --> 00:10:28.000]  何の心配もなく、豊かな気持ち。
[00:10:28.000 --> 00:10:29.000]  100万円?
[00:10:29.000 --> 00:10:32.000]  そうですね、100万円。
[00:10:32.000 --> 00:10:33.000]  欲しいですよね。
[00:10:33.000 --> 00:10:36.000]  月いくらぐらいか。
[00:10:36.000 --> 00:10:40.000]  お子様がいる人として、どれぐらいが十分という感じでしょうか?
[00:10:40.000 --> 00:10:43.000]  60万ぐらい。
[00:10:43.000 --> 00:10:49.000]  マンションに住んでなのか、アパートに住んでなのかって、基準が分からないんですけど。
[00:10:49.000 --> 00:10:58.000]  高級マンションに住んでたら、それこそ100万でも50万でも必要だし、本当に低級のアパートだったら、20万、30万。
[00:10:58.000 --> 00:11:05.000]  もし、ご自身が東京で暮らす上で、全く何の問題もなく暮らすのだとすれば、いくらぐらい必要だと思いますか?
[00:11:05.000 --> 00:11:07.000]  20万円ぐらい。
[00:11:07.000 --> 00:11:13.000]  40万円、50万円ぐらいあれば、何の心配もないから。
[00:11:13.000 --> 00:11:17.000]  もし、今手元に50万円があったら、何を最初にしますか?
[00:11:17.000 --> 00:11:20.000]  家電を買い替えます。
[00:11:20.000 --> 00:11:23.000]  買い替えたい家電、何かありますか?
[00:11:23.000 --> 00:11:25.000]  エアコン、エアコン買い替えたいです。
[00:11:25.000 --> 00:11:30.000]  もし、今お金いっぱい持ってたら、最初に何したいですか?
[00:11:30.000 --> 00:11:33.000]  欲しいおもちゃ買いたい。
[00:11:33.000 --> 00:11:34.000]  どんなおもちゃが欲しいですか?
[00:11:34.000 --> 00:11:38.000]  隅っこのパソコン。
[00:11:38.000 --> 00:11:49.000]  ちょっと貯金をまずするかなって思って、20万ぐらい貯金して、15万は自分の好きなこととかに、趣味とかに使っていきたいなって思います。
[00:11:49.000 --> 00:12:00.000]  海外の観光客が、円安のお金で物がいっぱい安くて買えるっていう風に言って、自分が買えないようなものにたくさんお金を使っていたら、あなたはどう感じますか?
[00:12:00.000 --> 00:12:02.000]  別にどんどん使ってくださいって。
[00:12:02.000 --> 00:12:03.000]  嫌な気持ちはしない?
[00:12:03.000 --> 00:12:08.000]  嫌な気持ちはしないです。もっと味わってください。もっとディープに、ディープに。
[00:12:08.000 --> 00:12:22.000]  ありがとうございますって感じです。日本を、なんか、日本に来て楽しんでもらえればいいなと思うんで、それでなんか、日本人が何か買えなくなってるみたいなこともそんな、ないと思うんで、はい。
[00:12:22.000 --> 00:12:32.000]  だって3年間、僕、バックパッカーやってましたけど、海外でたくさんお金いろんなとこ落としてたんで、落とさないと、その自国のその人たちが潤わないじゃないですか、観光業って、観光業の人たちが。だから、それは僕、
[00:12:32.000 --> 00:12:42.000]  理論分かってるから、プロセス分かってるから、海外の人、お金たくさん落としてもらわないと、日本っていうのは結局ね、タクシーとか入ってこないんで、たくさん。
[00:12:42.000 --> 00:12:57.000]  そのシステム、プロセス、僕、よく理解してるんで、うらやましいってことされるのは自分なんですよ。20年前、30年前の自分のバックパッカーやってた時、タイでも、シンガポーでもたくさん落としましたから、それはその国のそのタイミングになったと思います。
[00:12:57.000 --> 00:13:00.000]  では、あなたは今貯金はできていますか?
[00:13:00.000 --> 00:13:01.000]  ないですね。
[00:13:01.000 --> 00:13:02.000]  ほぼないです。
[00:13:02.000 --> 00:13:04.000]  あんまりできてないです。
[00:13:04.000 --> 00:13:08.000]  じゃあ、貯金をすること自体には意味あると思いますか?
[00:13:08.000 --> 00:13:13.000]  そうですね。何か急に困った時に使えばいいので、ないよりはある方がいいと思います。
[00:13:13.000 --> 00:13:19.000]  お子様がいらっしゃる母として、どれぐらいの貯金があると安心だなと感じますか?
[00:13:19.000 --> 00:13:22.000]  3000万ぐらい。
[00:13:22.000 --> 00:13:24.000]  貯金はできていますか?
[00:13:24.000 --> 00:13:26.000]  まあ、そこそこ、はい。
[00:13:26.000 --> 00:13:30.000]  貯金すること自体に意味はあると思いますか?
[00:13:30.000 --> 00:13:38.000]  もちろん、当然。貯金というか、現金の貯金とは限らないですけど、子供の将来もあるので大事だと思います。
[00:13:38.000 --> 00:13:40.000]  いや、今はできてないですね。
[00:13:40.000 --> 00:13:43.000]  貯金はそもそも意味があると思いますか?
[00:13:43.000 --> 00:13:50.000]  意味はあると思いますが、日本円で貯金していくことに意味はあるのかなとは思っていて、
[00:13:50.000 --> 00:13:59.000]  まあ、いろんなことに今物価も上がっていく中で、円は安くなっていくってことなんで、日本円で貯金をしてても、10年後、今100万貯めてたら、
[00:13:59.000 --> 00:14:10.000]  10年後100万の価値があるかといえば、そうではないはずなので、もっと違うもので、要は下がらないものですよね。価値が下がらないもの。
[00:14:10.000 --> 00:14:17.000]  まあ、簡単に金とかって言っちゃいますけど、そういったもので、なんか貯めておく必要あるんじゃないかなと思いますね。
[00:14:17.000 --> 00:14:21.000]  貯金すること自体に意味はあると思いますか?
[00:14:21.000 --> 00:14:24.000]  問題ならば、しない方がいいと思います。
[00:14:24.000 --> 00:14:28.000]  あると、お金が停滞しちゃうんで。
[00:14:28.000 --> 00:14:34.000]  お金が停滞しちゃうんで、銀行になるべく貯めないように、循環させる方がいいんじゃないかなと思って。
[00:14:34.000 --> 00:14:43.000]  そうしましたら、貯金などがない場合に、他に何か頼れるものとか、生活環境を変えれることとかって日本にありますか?
[00:14:43.000 --> 00:14:52.000]  ありますよ。循環型社会のモデルがちゃんとしっかりできてるんで、日本の場合それも、モデル僕見たんですけど、2、3年前、ちゃんと。
[00:14:52.000 --> 00:14:57.000]  取り入れれば別に、日本って社会保障が充実してますから、ある程度、全然問題ないと思います。
[00:14:57.000 --> 00:15:11.000]  政府に頼るっていう手があると思うんですけど、やっぱり今いろいろ問題になって、政府に対するちょっと不信感があるので、あんまり頼りたくはないなっていうふうな気持ちです。
[00:15:11.000 --> 00:15:26.000]  年金生活に、今年の4月から、あ、今年じゃない、去年の4月から年金生活なんで、どのくらいですかね。あんまりはっきり把握してないけど、たかが知れてますよ、日本の年金はね。
[00:15:26.000 --> 00:15:32.000]  だから、あとそういうのとか、個人年金とかそういうのですからね。どうだろう。
[00:15:32.000 --> 00:15:34.000]  年金っていうのは何歳からもらえるものなんですか?
[00:15:34.000 --> 00:15:45.000]  あのね、日本はね、60、えっと65が基本なんですけど、えっと60からもらえるはずなんですよ。早く。でもそうすると減っちゃうのね。全体的には減る。
[00:15:45.000 --> 00:15:53.000]  で、私はまあ働いてたんで、74まで働いてたんで、ずっと遅らせて、75になったら受け取るっていう感じ。
[00:15:53.000 --> 00:15:54.000]  うん。
[00:15:54.000 --> 00:16:00.000]  日本ではみんなが裕福だっていうイメージを持っている海外の視聴者さんに何か言いたいことはありますか?
[00:16:00.000 --> 00:16:04.000]  日本は裕福ではありません。一部です。
[00:16:04.000 --> 00:16:05.000]  それ以外の人は?
[00:16:05.000 --> 00:16:14.000]  あの、フリをしてる。お金があるフリ。これ日本人の心。ご飯食べてなくても、侍とかはご飯食べてなくても、つま弁じって分かる?
[00:16:14.000 --> 00:16:15.000]  はい。
[00:16:15.000 --> 00:16:23.000]  食べた後にこうやってやるんですよ。ご飯3日ぐらい食べてなくても、つま弁じでこうやってやってる。そしたら見た人は、まあお腹いっぱい食べたんだなと思うけど、
[00:16:23.000 --> 00:16:28.000]  実際は食べてる。これ日本の心。
[00:16:28.000 --> 00:16:30.000]  そういったものは外に見せないようにしているだけ?
[00:16:30.000 --> 00:16:32.000]  そうです。そうです。
[00:16:32.000 --> 00:16:36.000]  なんで日本人はそういうのを外に見せないようにしてると思いますか?
[00:16:36.000 --> 00:16:38.000]  迷惑かかるじゃない。
[00:16:38.000 --> 00:16:47.000]  裕福じゃないけど、心は貧しくはないと思うので、まあバランスだと思います。
[00:16:47.000 --> 00:16:51.000]  すみません。じゃあ、心の貧しくないっていうのはどういうところにあると思いますか?
[00:16:51.000 --> 00:16:52.000]  そうですね。
[00:16:52.000 --> 00:17:03.000]  まあ別にお金かけなくても遊びに行ったりはできるので、お外に出て楽しいねって言ってるのもハッピーかなって思います。
[00:17:03.000 --> 00:17:04.000]  ありがとうございます。
[00:17:04.000 --> 00:17:15.000]  はい。

# verdaccio

vim ~/.config/verdaccio/config.yaml


uplinks:
  npmjs:
    #url: https://registry.npmjs.org/
    #url: https://repo.huaweicloud.com/repository/npm/
    url: https://registry.npm.taobao.org/
    agent_options:
      keepAlive: true
      maxSockets: 40
      maxFreeSockets: 10
  npmjs2:
    url: https://registry.npmjs.org/
    agent_options:
      keepAlive: true
      maxSockets: 40
      maxFreeSockets: 10
packages:
  '@*/*':
    # scoped packages
    access: $all
    publish: $authenticated
    unpublish: $authenticated
    proxy: npmjs npmjs2

  '**':
    # allow all users (including non-authenticated users) to read and
    # publish all packages
    #
    # you can specify usernames/groupnames (depending on your auth plugin)
    # and three keywords: "$all", "$anonymous", "$authenticated"
    access: $all

    # allow all known users to publish/publish packages
    # (anyone can register by default, remember?)
    publish: $authenticated
    unpublish: $authenticated

    # if package is not available locally, proxy requests to 'npmjs' registry
    proxy: npmjs npmjs2


uplinks:
  npmjs:
    url: https://registry.npmjs.org/
    max_fails: 20
    fail_timeout: 10m

npm install --location=global verdaccio@next

verdaccio -l 0.0.0.0:4873

pnpm setup
Appended new lines to /home/tannal/.bashrc

Next configuration changes were made:
export PNPM_HOME="/home/tannal/.local/share/pnpm"
case ":$PATH:" in
  *":$PNPM_HOME:"*) ;;
  *) export PATH="$PNPM_HOME:$PATH" ;;
esac

To start using pnpm, run:
source /home/tannal/.bashrc

pnpm i -g verdaccio@next-7
pnpm i -g verdaccio@latest-6
pnpm i -g verdaccio@next
pnpm uninstall -g verdaccio@next-7

# YouCompleteMe

tannal@raspi:~/.vim/pack/YouCompleteMe/opt/YouCompleteMe$ ls
CODE_OF_CONDUCT.md  codecov.yml  print_todos.sh  tox.ini
CONTRIBUTING.md     doc          python          update-vim-docs
COPYING.txt         install.py   run_tests.py    vimrc_ycm_minimal
README.md           install.sh   test
autoload            plugin       third_party
tannal@raspi:~/.vim/pack/YouCompleteMe/opt/YouCompleteMe$

./install.py --all
popd
~/.vim/pack/YouCompleteMe/opt/YouCompleteMe ~/tannalwork/projects
Generating ycmd build configuration...OK
Compiling ycmd target: ycm_core...OK
Building regex module...OK
Building watchdog module...OK
Installing Omnisharp for C# support...OK
Building gopls for go completion...
OK
Setting up Tern for JavaScript completion...OK
Installing rust-analyzer "nightly-2023-08-18" for Rust support...OK
Installing jdt.ls for Java support...OK
Setting up TSserver for TypeScript completion...OK
Setting up Clangd completer...OK
~/tannalwork/projects


# juicefs

sudo tcpdump -i any -AX -vv 'port 5432'

sudo systemctl restart pg

create database jfs

./psql -U tannal -w -d jfs

curl -sSL https://d.juicefs.com/install | sh -

juicefs mount postgres://tannal:password@192.168.43.246:5432/jfs?sslmode=disable ~/tannalwork/jfs -d

tannal@raspi:~/tannalwork/projects$ juicefs format postgres://tannal:password@192.168.43.246:5432/jfs?sslmode=disable jfs
2024/03/28 15:10:00.716911 juicefs[4446] <INFO>: Meta address: postgres://tannal:****@192.168.43.246:5432/jfs?sslmode=disable [interface.go:497]
2024/03/28 15:10:00.725615 juicefs[4446] <WARNING>: The latency to database is too high: 8.389317ms [sql.go:260]
2024/03/28 15:10:00.897945 juicefs[4446] <INFO>: Data use file:///home/tannal/.juicefs/local/jfs/ [format.go:471]
2024/03/28 15:10:01.182269 juicefs[4446] <INFO>: Volume is formatted as {
  "Name": "jfs",
  "UUID": "cf5834d1-ddcf-42a3-a01c-aa3d159a6e79",
  "Storage": "file",
  "Bucket": "/home/tannal/.juicefs/local/",
  "BlockSize": 4096,
  "Compression": "none",
  "EncryptAlgo": "aes256gcm-rsa",
  "TrashDays": 1,
  "MetaVersion": 1,
  "MinClientVersion": "1.1.0-A",
  "DirStats": true
} [format.go:508]

juicefs format postgres://tannal:password@192.168.43.246:5432/jfs?sslmode=disable jfs

# git new repo

git init
git checkout -b main
git add .
git commit -m "first commit"
git remote add origin http://git.tanmeng.org/tannal/bitcask-kv-go.git
git push -u origin main

# git

git apply --whitespace=

git config --global alias.staash 'stash --all'
git config --global alias.bb !better-branch.sh

git rm -r --cached examples/*.swap
git update-index --assume-unchanged examples/*.swap

git rm -r --cached

git pull --ff-only
git pull --rebase
git checkout --ours db/
git checkout --theirs db/


# git lfs

sudo apt install git-lfs
git lfs install

git lfs pull
git clone https://huggingface.co/PowerInfer/ReluLLaMA-7B-PowerInfer-GGUF
GIT_LFS_SKIP_SMUDGE=1

GIT_LFS_SKIP_SMUDGE=1 git pull origin main
git lfs pull

# git switch a repo default branch to main

```
git branch -m master main
git fetch origin
git branch -u origin/main main
git remote set-head origin -a
git push origin HEAD

```

# go package http

export GOPRIVATE="git.tanmeng.org"
export GOINSECURE='*.tanmeng.org*'


go env -w GOPRIVATE=git.tanmeng.org

$env:GOINSECURE='*.tanmeng.org*'
$env:GOPRIVATE="git.tanmeng.org"

echo $env:GOPROXY

# proxy

$env:http_proxy='http://192.168.43.1:7890'
$env:https_proxy='http://192.168.43.1:7890'

set http_proxy='http://192.168.43.1:7890'
set https_proxy='http://192.168.43.1:7890'

$env:http_proxy=''
$env:https_proxy=''

$env:HTTPS_PROXY="http://192.168.43.1:7890"
$env:HTTP_PROXY="http://192.168.43.1:7890"

export http_proxy=http://10.90.81.138:7890
export https_proxy=http://10.90.81.138:7890

export http_proxy=http://192.168.43.1:7890
export https_proxy=http://192.168.43.1:7890


export http_proxy=http://localhost:7890
export https_proxy=http://localhost:7890

unset http_proxy
unset https_proxy
unset HTTP_PROXY
unset HTTPS_PROXY
unset ALL_PROXY
unset all_proxy

# dbus

sudo apt install libdbus-glib-1-dev

gcc try-dbus.c -o try-dbus `pkg-config --libs --cflags dbus-1 glib-2.0 gobject-2.0 dbus-glib-1`
gcc dbus-example.c -o dbus-example `pkg-config --libs --cflags dbus-1 glib-2.0 gobject-2.0 dbus-glib-1`

pkg-config --cflags gobject-2.0
pkg-config --libs gobject-2.0


# involves

involves:ehsan
involves:joyeecheung
involves:emilio
involves:gterzian
involves:jdm

involves:tlively

clspv/gpuweb/webgpu
involves:alan-baker
involves:kenrussell
involves:beaufortfrancois
involves:Kangz

WebRTC
involves:MirkoBonadei
involves:Orphis


ggml/whisper.cpp/llama.cpp
involves:ggerganov

Angle
involves:null77
involves:vonture
involves:Oletus
involves:Kangz

Webpack
involves:sokra

Babeljs
involves:hzoo
involves:jridgewell
involves:loganfsmyth

github search

Nodejs
involves:Qard

Igalia
involves:mariospr
involves:felipeerias
involves:xanlpz
involves:nicolo-ribaudo

wolvic
involves:calvaris
involves:svillar

Browsers
involves:tiaanl
involves:andreubotella
involves:bfgeek
involves:rniwa
involves:emilio
involves:gterzian
involves:jdm
involves:pylbrecht
involves:fantasai
involves:joyeecheung
involves:cathiechen
involves:xiaochengh
involves:noamr
involves:zcorpan
involves:Ms2ger
involves:mgaudet
involves:sideshowbarker

React
involves:gaearon

involves:gdb
involves:dtolnay
involves:pcwalton

involves:glennw
involves:kvark
involves:CanadaHonk
involves:asajeffrey
involves:atbrakhi


involves:jpbruyere

wpt
involves:gsnedders
involves:dbaron
involves:stephenmcgruer
involves:tabatkins

test-262
involves:leobalter
involves:ptomato
involves:rwaldron
involves:legendecas
involves:FrankYFTang
involves:shvaikalesh


involves:mcollina
involves:anonrig
involves:mertcanaltin

Tokio Rust
involves:carllerche
involves:hawkw
involves:davidpdrsn

involves:basicthinker
involves:scvalex
involves:eholk

involves:steveklabnik
involves:nicoburns

xv6-public
involves:kaashoek
involves:phf
involves:aclements
involves:zeldovich
involves:aliceinwire
involves:tchajed
involves:Icenowy

involves:giuliobenetti
involves:tkso1997

involves:tolmasky owner:tc39

involves:lukewarlow

involves:pcwalton
involves:emilio
involves:gterzian

Mozilla Gfx Team
involves:nical
involves:pcwalton webrender

fuchia graphics team
involves:raphlinus

igalian
involves:ferjm

# .bashrc

if [ -f ~/tannalwork/.bash_aliases ]; then
    source ~/tannalwork/.bash_aliases
fi

# Build SpiderMonkey

mkdir -p $WORK/mozconfigs/debug/
vim $WORK/mozconfigs/debug/MOZCONFIGs

```
# Build only the JS shell
ac_add_options --enable-project=js
# Enable the debugging tools: Assertions, debug only code etc.
ac_add_options --enable-debug
# Enable optimizations as well so that the test suite runs much faster. If
# you are having trouble using a debugger, you should disable optimization.
ac_add_options --enable-optimize
# Use a dedicated objdir for SpiderMonkey debug builds to avoid
# conflicting with Firefox build with default configuration.
mk_add_options MOZ_OBJDIR=@TOPSRCDIR@/obj-debug-@CONFIG_GUESS@
```
export MOZCONFIG=$WORK/mozconfigs/debug

# Scrolling

var allowScrolling = true
window.addEventListener('keydown', function(e) {
  // If user scrolls, disable automatic scrolling temporarily
  if(e.key === 'j') {
      allowScrolling = !allowScrolling;
  }
});

setInterval(() => {
  scrollToRandomPercentage()
}, 1000 * 4)

function scrollToRandomPercentage() {
  if(allowScrolling) {
    // Generate a random percentage between 0 and 1
    var randomPercentage = Math.random();

    // Get the total height of the document
    var totalHeight = document.body.scrollHeight - window.innerHeight;

    // Calculate the position to scroll to
    var scrollTo = randomPercentage * totalHeight;

    // Scroll to the calculated position
    window.scrollTo({
      top: scrollTo,
      behavior: 'instant' // Smooth scrolling
    });
  }
}

# youtube

var allowScrolling = true

setInterval(() => {
  playVideoAtRandomTime()
}, 1000 * 30)

window.addEventListener('keydown', function(e) {
  // If user scrolls, disable automatic scrolling temporarily
  if(e.key === 'h') {
      allowScrolling = !allowScrolling;
  }
});

// Get a reference to the video element
const video = document.querySelector('video');

// Function to generate a random time within the video duration
function getRandomTime(max) {
  return Math.random() * max;
}

// Function to set the video to play at a random time
function playVideoAtRandomTime() {
  if(allowScrolling) {
      // Check if the video is loaded
      if (video.readyState >= 2) {
        // Get the duration of the video
        const duration = video.duration;

        // Generate a random time within the duration
        const randomTime = getRandomTime(duration);

        // Set the current time of the video to the random time
        video.currentTime = randomTime;

        // Play the video
        video.play();
      }
  }
}

# Gitea

custom/cnf/app.ini
···

APP_NAME = Gitea: Git with a cup of tea
RUN_USER = tannal
WORK_PATH = /home/ubuntu/tannalwork/projects/gitea
RUN_MODE = prod

[packages]
ENABLED = true

[migrations]
ALLOW_LOCALNETWORKS = true

[database]
DB_TYPE = sqlite3
HOST = 127.0.0.1:3306
NAME = gitea
USER = gitea
PASSWD =
SCHEMA =
SSL_MODE = disable
PATH = /home/ubuntu/tannalwork/projects/gitea/data/gitea.db
LOG_SQL = false

[repository]
ROOT = /home/ubuntu/tannalwork/projects/gitea/data/gitea-repositories


[server]
SSH_DOMAIN = git.tanmeng.org
DOMAIN = git.tanmeng.org
APP_DATA_PATH = /home/ubuntu/tannalwork/projects/gitea/data

DISABLE_SSH = false
START_SSH_SERVER = true
SSH_PORT         = 2222
SSH_LISTEN_PORT  = 2222
BUILTIN_SSH_SERVER_USER = tannal

LFS_START_SERVER = true
LFS_JWT_SECRET = z0TpyEc1hPmiASwmOtEuRRieeb_L0iKEj1kW79mB8lM
OFFLINE_MODE = true
PROTOCOL  = http
ROOT_URL  = http://git.tanmeng.org/
HTTP_PORT = 3000
CERT_FILE = ~/tannalwork/projects/gitea/cert.pem
KEY_FILE  = ~/tannalwork/projects/gitea/key.pem
LFS_START_SERVER = true


[lfs]
PATH = ~/tannalwork/projects/gitea/data/lfs

[mailer]
ENABLED = false

[service]
REGISTER_EMAIL_CONFIRM = false
ENABLE_NOTIFY_MAIL = false
DISABLE_REGISTRATION = false
ALLOW_ONLY_EXTERNAL_REGISTRATION = false
ENABLE_CAPTCHA = false
REQUIRE_SIGNIN_VIEW = false
DEFAULT_KEEP_EMAIL_PRIVATE = false
DEFAULT_ALLOW_CREATE_ORGANIZATION = true
DEFAULT_ENABLE_TIMETRACKING = true
NO_REPLY_ADDRESS = noreply.localhost

[openid]
ENABLE_OPENID_SIGNIN = true
ENABLE_OPENID_SIGNUP = true

[cron.update_checker]
ENABLED = false

[session]
PROVIDER = file

[log]
MODE = console
LEVEL = info
ROOT_PATH = ~/tannalwork/projects/gitea/log

[repository.pull-request]
DEFAULT_MERGE_STYLE = merge

[repository.signing]
DEFAULT_TRUST_MODEL = committer

[security]
INSTALL_LOCK = true
INTERNAL_TOKEN = eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJuYmYiOjE3MTE5NTIxNDZ9.psNFatTzHbZ8IZ0EBg_M5sJeIZvY4anxddWUfcypm00
PASSWORD_HASH_ALGO = pbkdf2

[oauth2]
JWT_SECRET = 9x2jyh43MEPTfhbNBVPhoKdCfa5Kg4wTkAt9Ewk8wcE


···


```

APP_NAME = Gitea: Git with a cup of tea
RUN_USER = tannal
WORK_PATH = C:\Users\tanna\tannalwork\projects\gitea
RUN_MODE = prod

[packages]
ENABLED = true

[migrations]
ALLOW_LOCALNETWORKS = true

[database]
DB_TYPE = sqlite3
HOST = 127.0.0.1:3306
NAME = gitea
USER = gitea
PASSWD =
SCHEMA =
SSL_MODE = disable
PATH = C:\Users\tanna\tannalwork\projects\gitea\data\gitea.db
LOG_SQL = false

[repository]
ROOT = C:/Users/tanna/tannalwork/projects/gitea/data/gitea-repositories


[server]
SSH_DOMAIN = git.tanmeng.org
DOMAIN = git.tanmeng.org
APP_DATA_PATH = C:\Users\tanna\tannalwork\projects\gitea\data

DISABLE_SSH = false
START_SSH_SERVER = true
SSH_PORT         = 22
SSH_LISTEN_PORT  = 22
BUILTIN_SSH_SERVER_USER = tannal

LFS_START_SERVER = true
LFS_JWT_SECRET = z0TpyEc1hPmiASwmOtEuRRieeb_L0iKEj1kW79mB8lM
OFFLINE_MODE = true
PROTOCOL  = http
ROOT_URL  = http://git.tanmeng.org/
HTTP_PORT = 3000
CERT_FILE = C:\Users\tanna\tannalwork\projects\gitea\cert.pem
KEY_FILE  = C:\Users\tanna\tannalwork\projects\gitea\key.pem
LFS_START_SERVER = true


[lfs]
PATH = C:/Users/tanna/tannalwork/projects/gitea/data/lfs

[mailer]
ENABLED = false

[service]
REGISTER_EMAIL_CONFIRM = false
ENABLE_NOTIFY_MAIL = false
DISABLE_REGISTRATION = false
ALLOW_ONLY_EXTERNAL_REGISTRATION = false
ENABLE_CAPTCHA = false
REQUIRE_SIGNIN_VIEW = false
DEFAULT_KEEP_EMAIL_PRIVATE = false
DEFAULT_ALLOW_CREATE_ORGANIZATION = true
DEFAULT_ENABLE_TIMETRACKING = true
NO_REPLY_ADDRESS = noreply.localhost

[openid]
ENABLE_OPENID_SIGNIN = true
ENABLE_OPENID_SIGNUP = true

[cron.update_checker]
ENABLED = false

[session]
PROVIDER = file

[log]
MODE = console
LEVEL = info
ROOT_PATH = C:/Users/tanna/tannalwork/projects/gitea/log

[repository.pull-request]
DEFAULT_MERGE_STYLE = merge

[repository.signing]
DEFAULT_TRUST_MODEL = committer

[security]
INSTALL_LOCK = true
INTERNAL_TOKEN = eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJuYmYiOjE3MTE5NTIxNDZ9.psNFatTzHbZ8IZ0EBg_M5sJeIZvY4anxddWUfcypm00
PASSWORD_HASH_ALGO = pbkdf2

[oauth2]
JWT_SECRET = 9x2jyh43MEPTfhbNBVPhoKdCfa5Kg4wTkAt9Ewk8wcE

```

```

APP_NAME = Gitea: Git with a cup of tea
RUN_USER = tannal
WORK_PATH = /home/tannal/tannalwork/projects/gitea
RUN_MODE = prod

[packages]
ENABLED = true

[migrations]
ALLOW_LOCALNETWORKS = true

[database]
DB_TYPE = sqlite3
HOST = 127.0.0.1:3306
NAME = gitea
USER = gitea
PASSWD =
SCHEMA =
SSL_MODE = disable
PATH = /home/tannal/tannalwork/projects/gitea/data/gitea.db
LOG_SQL = false

[repository]
ROOT = /home/tannal/tannalwork/projects/gitea/data/gitea-repositories

[server]
SSH_DOMAIN = git.tanmeng.org
DOMAIN = git.tanmeng.org
APP_DATA_PATH = /home/tannal/tannalwork/projects/gitea/data
DISABLE_SSH = false
SSH_PORT = 22
LFS_START_SERVER = true
LFS_JWT_SECRET = z0TpyEc1hPmiASwmOtEuRRieeb_L0iKEj1kW79mB8lM
OFFLINE_MODE = true
PROTOCOL  = http
ROOT_URL  = http://git.tanmeng.org/
HTTP_PORT = 3001
CERT_FILE = /home/tannal/tannalwork/projects/gitea/cert.pem
KEY_FILE  = /home/tannal/tannalwork/projects/gitea/key.pem
LFS_START_SERVER = true


[lfs]
PATH = /home/tannal/tannalwork/projects/gitea/data/lfs

[mailer]
ENABLED = false

[service]
REGISTER_EMAIL_CONFIRM = false
ENABLE_NOTIFY_MAIL = false
DISABLE_REGISTRATION = false
ALLOW_ONLY_EXTERNAL_REGISTRATION = false
ENABLE_CAPTCHA = false
REQUIRE_SIGNIN_VIEW = false
DEFAULT_KEEP_EMAIL_PRIVATE = false
DEFAULT_ALLOW_CREATE_ORGANIZATION = true
DEFAULT_ENABLE_TIMETRACKING = true
NO_REPLY_ADDRESS = noreply.localhost

[openid]
ENABLE_OPENID_SIGNIN = true
ENABLE_OPENID_SIGNUP = true

[cron.update_checker]
ENABLED = false

[session]
PROVIDER = file

[log]
MODE = console
LEVEL = info
ROOT_PATH = /home/tannal/tannalwork/projects/gitea/log

[repository.pull-request]
DEFAULT_MERGE_STYLE = merge

[repository.signing]
DEFAULT_TRUST_MODEL = committer

[security]
INSTALL_LOCK = true
INTERNAL_TOKEN = eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJuYmYiOjE3MTE5NTIxNDZ9.psNFatTzHbZ8IZ0EBg_M5sJeIZvY4anxddWUfcypm00
PASSWORD_HASH_ALGO = pbkdf2

[oauth2]
JWT_SECRET = 9x2jyh43MEPTfhbNBVPhoKdCfa5Kg4wTkAt9Ewk8wcE

```

# Nginx Config


#user  nobody;
worker_processes  4;

#error_log  logs/error.log;
#error_log  logs/error.log  notice;
#error_log  logs/error.log  info;

#pid        logs/nginx.pid;


events {
    worker_connections  1024;
    multi_accept on;
}


http {
    include       mime.types;
    default_type  application/octet-stream;

    #log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
    #                  '$status $body_bytes_sent "$http_referer" '
    #                  '"$http_user_agent" "$http_x_forwarded_for"';

    #access_log  logs/access.log  main;
    # ssl_session_cache   shared:SSL:10m;
    # ssl_session_timeout 10m;

    sendfile        on;
    #tcp_nopush     on;

    #keepalive_timeout  0;
    keepalive_timeout  65;

    #gzip  on;

    server {
        listen 80;
        server_name  git.tanmeng.org;
        location / {
            proxy_pass http://localhost:3000/;
            client_max_body_size 1000M;
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
            proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            proxy_set_header X-Forwarded-Proto $scheme;
        }
    }

    server {
        listen              443 ssl;
        server_name         git.tanmeng.org;
        ssl_certificate     C:\\Users\\tanna\\tannalwork\\projects\\gitea\\cert.pem;
        ssl_certificate_key C:\\Users\\tanna\\tannalwork\\projects\\gitea\\key.pem;
        ssl_protocols       TLSv1 TLSv1.1 TLSv1.2 TLSv1.3;
        ssl_ciphers         HIGH:!aNULL:!MD5;

        location / {
            proxy_pass http://localhost:3000/;
            client_max_body_size 1000M;
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
            proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            proxy_set_header X-Forwarded-Proto $scheme;
        }
    }

    server {
        listen 80;
        server_name  videos.tanmeng.org;
        location / {
            proxy_pass http://192.168.43.246:8080;
        }
    }

    upstream api {
        server 192.168.43.246:10000 weight=1 max_fails=1 fail_timeout=60s;
        server 192.168.43.27:10000 weight=1 max_fails=1 fail_timeout=60s;
        server 192.168.43.95:10000 weight=1 max_fails=1 fail_timeout=60s;
        server 192.168.43.62:10000 weight=1 max_fails=1 fail_timeout=60s;
    }

    upstream home {
        server
    }

    server {
        listen 80;
        server_name  api.tanmeng.org;
        location / {
            proxy_pass http://api;
        }

    }

    server {
        listen 80;
        server_name  docs.tanmeng.org;
        location / {
            proxy_pass http://192.168.43.1:8080/;
        }
    }

    server {
        listen 80;
        server_name  history.tanmeng.org;
        location / {
            proxy_pass http://192.168.43.246:8081/;
        }
    }

    server {
        listen 80;
        server_name  tanmeng.org;
        location / {
            proxy_pass http://192.168.43.62:8080/;
        }
    }

    # server {
    #     listen       80;
    #     server_name  localhost;

    #     #charset koi8-r;

    #     #access_log  logs/host.access.log  main;

    #     location / {
    #         root   html;
    #         index  index.html index.htm;
    #     }

    #     #error_page  404              /404.html;

    #     # redirect server error pages to the static page /50x.html
    #     #
    #     error_page   500 502 503 504  /50x.html;
    #     location = /50x.html {
    #         root   html;
    #     }

    #     # proxy the PHP scripts to Apache listening on 127.0.0.1:80
    #     #
    #     #location ~ \.php$ {
    #     #    proxy_pass   http://127.0.0.1;
    #     #}

    #     # pass the PHP scripts to FastCGI server listening on 127.0.0.1:9000
    #     #
    #     #location ~ \.php$ {
    #     #    root           html;
    #     #    fastcgi_pass   127.0.0.1:9000;
    #     #    fastcgi_index  index.php;
    #     #    fastcgi_param  SCRIPT_FILENAME  /scripts$fastcgi_script_name;
    #     #    include        fastcgi_params;
    #     #}

    #     # deny access to .htaccess files, if Apache's document root
    #     # concurs with nginx's one
    #     #
    #     #location ~ /\.ht {
    #     #    deny  all;
    #     #}
    # }


    # another virtual host using mix of IP-, name-, and port-based configuration
    #
    #server {
    #    listen       8000;
    #    listen       somename:8080;
    #    server_name  somename  alias  another.alias;

    #    location / {
    #        root   html;
    #        index  index.html index.htm;
    #    }
    #}


    # HTTPS server
    #
    # server {
    #    listen       443 ssl;
    #    server_name  git.tanmeng.org;

    #    ssl_certificate      cert.pem;
    #    ssl_certificate_key  cert.key;

    #    ssl_session_cache    shared:SSL:1m;
    #    ssl_session_timeout  5m;

    #    ssl_ciphers  HIGH:!aNULL:!MD5;
    #    ssl_prefer_server_ciphers  on;

    #    location / {
    #         proxy_set_header Host $host;
    #         proxy_set_header X-Real-IP $remote_addr;
    #         proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
    #         proxy_set_header X-Forwarded-Proto $scheme;
    #    }
    # }

}


# bilibili

var allowScrolling = true

setInterval(() => {
  playVideoAtRandomTime()
}, 1000 * 14)

window.addEventListener('keydown', function(e) {
  // If user scrolls, disable automatic scrolling temporarily
  if(e.key === 'h') {
      allowScrolling = !allowScrolling;
  }
});

// Get a reference to the video element
const video = document.querySelector('video');

// Function to generate a random time within the video duration
function getRandomTime(max) {
  return Math.random() * max;
}

// Function to set the video to play at a random time
function playVideoAtRandomTime() {
  if(allowScrolling) {
      // Check if the video is loaded
      if (video.readyState >= 2) {
        // Get the duration of the video
        const duration = video.duration;

        // Generate a random time within the duration
        const randomTime = getRandomTime(duration);

        // Set the current time of the video to the random time
        video.currentTime = randomTime;

        // Play the video
        video.play();
      }
  }
}

# UTF8 decoder js

const utf8_bytes = new Uint8Array([0xE6, 0xB1, 0x89, 0xE5, 0xAD, 0x97]);
const decoder = new TextDecoder('utf-8');
const utf8_string = decoder.decode(utf8_bytes);
console.log(utf8_string); // Output: 汉字


# GeoDNS simple dns service

{
    "serial":1394372421,
    "ttl":    120,
    "targeting": "country continent @ regiongroup region asn",
    "data":{
        "":{
            "ns": [ "ns1.tanmeng.org", "ns2.tanmeng.org" ],
            "a":[
                [
                   "192.168.43.246",
                   "100"
                ]
            ],
            "aaaa": [
                [
                  "fe80::2c4:dfee:ffc0:8d4",
                  "100"
                ],
                [
                  "fe80::2c4:dfee:ffc0:8d4",
                  "10"
                ],
                [
                  "fe80::2c4:dfee:ffc0:8d4",
                  "10"
                ]
              ]
        },
        "git": {
            "ns": [ "ns1.tanmeng.org", "ns2.tanmeng.org" ],
            "a":[
                [
                   "192.168.43.62",
                   "100"
                ]
            ]
        },
        "docs": {
            "ns": [ "ns1.tanmeng.org", "ns2.tanmeng.org" ],
            "a":[
                [
                   "192.168.43.62",
                   "100"
                ]
            ]
        },
        "videos": {
            "ns": [ "ns1.tanmeng.org", "ns2.tanmeng.org" ],
            "a":[
                [
                   "192.168.43.62",
                   "100"
                ]
            ]
        },
        "history": {
            "ns": [ "ns1.tanmeng.org", "ns2.tanmeng.org" ],
            "a":[
                [
                   "192.168.43.62",
                   "100"
                ]
            ]
        },
        "api": {
            "ns": [ "ns1.tanmeng.org", "ns2.tanmeng.org" ],
            "a":[
                [
                   "192.168.43.62",
                   "100"
                ]
            ]
        }
    }
}
# Product

package main

import (
	"fmt"
)

type Student struct {
	ID   int
	Name string
}

type Course struct {
	Code string
	Name string
}

type ProductResult struct {
	StudentID   int
	StudentName string
	CourseCode  string
	CourseName  string
}

func CartesianProduct(students []Student, courses []Course) []ProductResult {
	var result []ProductResult

	for _, student := range students {
		for _, course := range courses {
			result = append(result, ProductResult{
				StudentID:   student.ID,
				StudentName: student.Name,
				CourseCode:  course.Code,
				CourseName:  course.Name,
			})
		}
	}

	return result
}

func main() {
	// Sample data
	students := []Student{
		{ID: 1, Name: "Alice"},
		{ID: 2, Name: "Bob"},
	}

	courses := []Course{
		{Code: "CS101", Name: "Introduction to Computer Science"},
		{Code: "ENG101", Name: "English Composition"},
	}

	// Perform Cartesian product
	result := CartesianProduct(students, courses)

	// Print result
	fmt.Println("Cartesian Product Result:")
	for _, item := range result {
		fmt.Printf("Student ID: %d, Student Name: %s, Course Code: %s, Course Name: %s\n", item.StudentID, item.StudentName, item.CourseCode, item.CourseName)
	}
}


# Select

package main

import (
	"fmt"
)

type Student struct {
	ID    int
	Name  string
	Grade int
}

func SelectField(students []Student, field string, condition func(s Student) bool) []interface{} {
	var result []interface{}

	for _, student := range students {
		if condition(student) {
			switch field {
			case "ID":
				result = append(result, student.ID)
			case "Name":
				result = append(result, student.Name)
			case "Grade":
				result = append(result, student.Grade)
			default:
				// Handle invalid field
				result = append(result, nil)
			}
		}
	}

	return result
}

func main() {
	// Sample data
	students := []Student{
		{ID: 1, Name: "Alice", Grade: 85},
		{ID: 2, Name: "Bob", Grade: 75},
		{ID: 3, Name: "Charlie", Grade: 90},
	}

	// Define condition (e.g., students with grade >= 80)
	condition := func(s Student) bool {
		return s.Grade >= 80
	}

	// Perform select operation for ID field
	result := SelectField(students, "ID", condition)

	// Print result
	fmt.Println("Result of Select (ID):", result)
}


package main

import (
	"fmt"
)

type Student struct {
	ID    int
	Name  string
	Grade int
}

func Select(students []Student, condition func(s Student) bool) []Student {
	var result []Student

	for _, student := range students {
		if condition(student) {
			result = append(result, student)
		}
	}

	return result
}

func main() {
	// Sample data
	students := []Student{
		{ID: 1, Name: "Alice", Grade: 85},
		{ID: 2, Name: "Bob", Grade: 75},
		{ID: 3, Name: "Charlie", Grade: 90},
	}

	// Define condition (e.g., students with grade >= 80)
	condition := func(s Student) bool {
		return s.Grade >= 80
	}

	// Perform select operation
	result := Select(students, condition)

	// Print result
	fmt.Println("Result of Select:")
	for _, student := range result {
		fmt.Printf("ID: %d, Name: %s, Grade: %d\n", student.ID, student.Name, student.Grade)
	}
}


# Division

package main

import (
	"fmt"
)

type Customer struct {
	ID   int
	Name string
}

type Order struct {
	ID         int
	CustomerID int
}

func Division(customers []Customer, orders []Order) []Customer {
	var result []Customer

	for _, customer := range customers {
		isRelated := true

		for _, order := range orders {
			if customer.ID == order.CustomerID {
				isRelated = false
				break
			}
		}

		if isRelated {
			result = append(result, customer)
		}
	}

	return result
}

func main() {
	// Sample data
	customers := []Customer{
		{ID: 1, Name: "Alice"},
		{ID: 2, Name: "Bob"},
		{ID: 3, Name: "Charlie"},
	}

	orders := []Order{
		{ID: 1, CustomerID: 1},
		{ID: 2, CustomerID: 2},
	}

	// Perform division
	result := Division(customers, orders)

	// Print result
	fmt.Println("Result of Division:")
	for _, customer := range result {
		fmt.Printf("ID: %d, Name: %s\n", customer.ID, customer.Name)
	}
}


# Sort

package main

import (
	"fmt"
	"sort"
)

type Person struct {
	ID   int
	Name string
	Age  int
}

type ByAge []Person

func (a ByAge) Len() int           { return len(a) }
func (a ByAge) Less(i, j int) bool { return a[i].Age < a[j].Age }
func (a ByAge) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

func main() {
	// Sample data
	people := []Person{
		{ID: 1, Name: "Alice", Age: 30},
		{ID: 2, Name: "Bob", Age: 25},
		{ID: 3, Name: "Charlie", Age: 35},
	}

	// Sort by age
	sort.Sort(ByAge(people))

	// Print sorted result
	fmt.Println("Sorted by Age:")
	for _, p := range people {
		fmt.Printf("ID: %d, Name: %s, Age: %d\n", p.ID, p.Name, p.Age)
	}
}


# Aggregation

package main

import (
	"fmt"
)

// Define structs representing data
type Transaction struct {
	ID       int
	Amount   float64
	Category string
}

// Sum calculates the sum of amounts in a slice of transactions
func Sum(transactions []Transaction) float64 {
	sum := 0.0
	for _, t := range transactions {
		sum += t.Amount
	}
	return sum
}

// Average calculates the average of amounts in a slice of transactions
func Average(transactions []Transaction) float64 {
	sum := Sum(transactions)
	count := len(transactions)
	if count == 0 {
		return 0.0
	}
	return sum / float64(count)
}

func main() {
	// Sample data
	transactions := []Transaction{
		{ID: 1, Amount: 100.50, Category: "Food"},
		{ID: 2, Amount: 200.75, Category: "Shopping"},
		{ID: 3, Amount: 50.25, Category: "Food"},
		{ID: 4, Amount: 150.0, Category: "Food"},
	}

	// Calculate sum and average of amounts
	sum := Sum(transactions)
	average := Average(transactions)

	// Print aggregation results
	fmt.Printf("Total Sum: %.2f\n", sum)
	fmt.Printf("Average Amount: %.2f\n", average)
}


# filter

package main

import (
	"fmt"
)

// Define structs representing data
type Person struct {
	ID   int
	Name string
	Age  int
}

// Filter function applies a filter condition to a slice of structs
func Filter(people []Person, condition func(p Person) bool) []Person {
	var filtered []Person
	for _, p := range people {
		if condition(p) {
			filtered = append(filtered, p)
		}
	}
	return filtered
}

func main() {
	// Sample data
	people := []Person{
		{ID: 1, Name: "Alice", Age: 30},
		{ID: 2, Name: "Bob", Age: 25},
		{ID: 3, Name: "Charlie", Age: 35},
	}

	// Define filter condition (e.g., age greater than 30)
	condition := func(p Person) bool {
		return p.Age > 30
	}

	// Apply filter
	filteredPeople := Filter(people, condition)

	// Print filtered result
	for _, p := range filteredPeople {
		fmt.Printf("ID: %d, Name: %s, Age: %d\n", p.ID, p.Name, p.Age)
	}
}


# right join

package main

import (
	"fmt"
)

// Define structs representing tables
type Customer struct {
	ID   int
	Name string
}

type Order struct {
	ID         int
	CustomerID int
	Amount     float64
}

// RightJoin performs a right join operation on two slices of structs
func RightJoin(customers []Customer, orders []Order) []struct {
	CustomerName string
	OrderAmount  float64
} {
	var result []struct {
		CustomerName string
		OrderAmount  float64
	}

	// Create a map to store customers by ID
	customerMap := make(map[int]string)
	for _, customer := range customers {
		customerMap[customer.ID] = customer.Name
	}

	// Iterate through each order
	for _, order := range orders {
		// If there's a matching customer, add to result
		if customerName, ok := customerMap[order.CustomerID]; ok {
			result = append(result, struct {
				CustomerName string
				OrderAmount  float64
			}{
				CustomerName: customerName,
				OrderAmount:  order.Amount,
			})
		} else {
			// If no matching customer, add with an empty name
			result = append(result, struct {
				CustomerName string
				OrderAmount  float64
			}{
				CustomerName: "",
				OrderAmount:  order.Amount,
			})
		}
	}
	return result
}

func main() {
	// Sample data
	customers := []Customer{
		{ID: 1, Name: "Alice"},
		{ID: 2, Name: "Bob"},
	}

	orders := []Order{
		{ID: 1, CustomerID: 1, Amount: 100.50},
		{ID: 2, CustomerID: 2, Amount: 200.75},
		{ID: 3, CustomerID: 3, Amount: 300.00},
	}

	// Perform right join
	joined := RightJoin(customers, orders)

	// Print result
	for _, record := range joined {
		fmt.Printf("Customer: %s, Order Amount: $%.2f\n", record.CustomerName, record.OrderAmount)
	}
}


# left join

package main

import (
	"fmt"
)

// Define structs representing tables
type Customer struct {
	ID   int
	Name string
}

type Order struct {
	ID         int
	CustomerID int
	Amount     float64
}

// LeftJoin performs a left join operation on two slices of structs
func LeftJoin(customers []Customer, orders []Order) []struct {
	CustomerName string
	OrderAmount  float64
} {
	var result []struct {
		CustomerName string
		OrderAmount  float64
	}

	// Create a map to store orders by customer ID
	orderMap := make(map[int]float64)
	for _, order := range orders {
		orderMap[order.CustomerID] = order.Amount
	}

	// Iterate through each customer
	for _, customer := range customers {
		// If there's a matching order, add to result
		if orderAmount, ok := orderMap[customer.ID]; ok {
			result = append(result, struct {
				CustomerName string
				OrderAmount  float64
			}{
				CustomerName: customer.Name,
				OrderAmount:  orderAmount,
			})
		} else {
			// If no matching order, add with a zero amount
			result = append(result, struct {
				CustomerName string
				OrderAmount  float64
			}{
				CustomerName: customer.Name,
				OrderAmount:  0,
			})
		}
	}
	return result
}

func main() {
	// Sample data
	customers := []Customer{
		{ID: 1, Name: "Alice"},
		{ID: 2, Name: "Bob"},
		{ID: 3, Name: "Charlie"},
	}

	orders := []Order{
		{ID: 1, CustomerID: 1, Amount: 100.50},
		{ID: 2, CustomerID: 2, Amount: 200.75},
	}

	// Perform left join
	joined := LeftJoin(customers, orders)

	// Print result
	for _, record := range joined {
		fmt.Printf("Customer: %s, Order Amount: $%.2f\n", record.CustomerName, record.OrderAmount)
	}
}


# Golang inner Join

```go

package main

import (
	"fmt"
)

// Define structs representing tables
type Customer struct {
	ID   int
	Name string
}

type Order struct {
	ID         int
	CustomerID int
	Amount     float64
}

// InnerJoin performs an inner join operation on two slices of structs
func InnerJoin(customers []Customer, orders []Order) []struct {
	CustomerName string
	OrderAmount  float64
} {
	var result []struct {
		CustomerName string
		OrderAmount  float64
	}

	// Iterate through each customer and order
	for _, customer := range customers {
		for _, order := range orders {
			// If there's a match on customer ID, add to result
			if customer.ID == order.CustomerID {
				result = append(result, struct {
					CustomerName string
					OrderAmount  float64
				}{
					CustomerName: customer.Name,
					OrderAmount:  order.Amount,
				})
			}
		}
	}
	return result
}

func main() {
	// Sample data
	customers := []Customer{
		{ID: 1, Name: "Alice"},
		{ID: 2, Name: "Bob"},
	}

	orders := []Order{
		{ID: 1, CustomerID: 1, Amount: 100.50},
		{ID: 2, CustomerID: 2, Amount: 200.75},
	}

	// Perform inner join
	joined := InnerJoin(customers, orders)

	// Print result
	for _, record := range joined {
		fmt.Printf("Customer: %s, Order Amount: $%.2f\n", record.CustomerName, record.OrderAmount)
	}
}


```

# Floyd's cycle-finding algorithm

```js
const floyd = (f, x0) => {

    let tortoise = f(x0);
    let hare = f(f(x0));

    while (tortoise !== hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    let mu = 0;
    tortoise = x0;
    while (tortoise !== hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu += 1;
    }

    let lam = 1;
    hare = f(tortoise);
    while (tortoise !== hare) {
        hare = f(hare);
        lam += 1;
    }

    return [mu, lam];

}

// test case 1
let f = (x) => (x + 1) % 7;
let x0 = 0;
console.log(floyd(f, x0)); // [0, 7]

// test case 2
f = (x) => (x + 1) % 5;
x0 = 0;
console.log(floyd(f, x0)); // [0, 5]

// test case 3
f = (x) => (x + 1) % 3;
x0 = 0;
console.log(floyd(f, x0)); // [0, 3]

// complex test case 1
f = (x) => (x + 1) % 7;
x0 = 3;
console.log(floyd(f, x0)); // [3, 4]


// complex test case 2
f = (x) => (x + 1) %10 + 5;
x0 = 0;
console.log(floyd(f, x0)); // [0, 1]

console.log(f(0))
console.log(f(f(0)))
console.log(f(f(f(0))))
console.log(f(f(f(f(0)))))
console.log(f(f(f(f(f(0))))))
console.log(f(f(f(f(f(f(0)))))))
console.log(f(f(f(f(f(f(f(0))))))))
console.log(f(f(f(f(f(f(f(f(0)))))))))

```

# parallel odd even bubble sort in golang

```go

package main

func swap(i, j int, array []int) {
	temp := array[i]
	array[i] = array[j]
	array[j] = temp
}

func thread(array []int, start int, end int, ch chan bool) {
	for i := start; i < end; i += 2 {
		if array[i] > array[i+1] {
			swap(i, i+1, array)
			ch <- false
		}
	}

	ch <- true
}

func oldEventSort(array []int) []int {
	sorted := false
	evenSorted := make(chan bool)
	oddSorted := make(chan bool)

	for !sorted {

		sorted = true

		go thread(array, 0, len(array)-1, evenSorted)

		go thread(array, 1, len(array)-1, oddSorted)

		sorted = <-evenSorted && <-oddSorted
	}

	return array
}

func main() {
	// test case 1
	array := []int{5, 3, 8, 6, 2, 7, 1, 4}
	array = oldEventSort(array)
	// expected output: [1 2 3 4 5 6 7 8]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// test case 2
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9}
	array = oldEventSort(array)
	// expected output: [1 2 3 4 5 6 7 8 9]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// test case 3
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9, 0}
	array = oldEventSort(array)
	// expected output: [0 1 2 3 4 5 6 7 8 9]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// complex test case 4
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9, 0, 10, 15, 13, 12, 11, 14}
	array = oldEventSort(array)
	// expected output: [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}

	println()

	// simple test case 1
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9, 0, 10, 15, 13, 12, 11, 14, 16}
	array = oldEventSort(array)
	// expected output: [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// edge case 1
	array = []int{5}
	array = oldEventSort(array)
	// expected output: [5]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// edge case 2
	array = []int{}
	array = oldEventSort(array)
	// expected output: []
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// big test case 1
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9, 0, 10, 15, 13, 12, 11, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28}
	array = oldEventSort(array)
	// expected output: [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()
}


```

# bubble sort

```js

const bubbleSort = (array) => {
    let n = array.length;

    let swapped = false;

    do{

        swapped = false;

        for(let i = 1; i < n; i++){
            if(array[i - 1] > array[i]){
                let temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                swapped = true;
            }
        }

        console.log(array)

    }while(swapped)

    return array
}


const bubbleSort2 = (array) => {

    for(let n = array.length; n > 1; ){

        // n is the biggest index of the unsorted part of the array
        console.log(array[n])

        let newN = 0
        for(let i = 1; i < n; i++){
            if(array[i - 1] > array[i]){
                let temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                newN = i;
            }
        }
        n = newN;
    }

    return array
}


// test case 1
let array = [5, 3, 8, 2, 1, 4]
console.log(bubbleSort(array)) // [1, 2, 3, 4, 5, 8]


// test case 2
array = [20, 20, 31, 56, 1, 12, 12]
console.log(bubbleSort2(array)) // [1, 12, 12, 20, 20, 31, 56]

```

# html tokenizer

```python

def tokenize(html_input):
    # Regular expressions for identifying different types of tokens
    start_tag_pattern = r'<[^/][^>]*>'
    end_tag_pattern = r'</[^>]*>'
    text_content_pattern = r'[^<]+'

    # Combine the patterns into a single regular expression
    combined_pattern = f'({start_tag_pattern})|({end_tag_pattern})|({text_content_pattern})'

    # Tokenize the HTML input
    tokens = re.findall(combined_pattern, html_input)

    # Flatten the list of tuples and remove empty strings
    tokens = [token for tup in tokens for token in tup if token]

    return tokens

```

# OpenCV install

```bash
VERSION=4.8.0

test -e ${VERSION}.zip || wget https://github.com/opencv/opencv/archive/refs/tags/${VERSION}.zip
test -e opencv-${VERSION} || unzip ${VERSION}.zip

test -e opencv_extra_${VERSION}.zip || wget -O opencv_extra_${VERSION}.zip https://github.com/opencv/opencv_contrib/archive/refs/tags/${VERSION}.zip
test -e opencv_contrib-${VERSION} || unzip opencv_extra_${VERSION}.zip


cd opencv-${VERSION}
mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D WITH_TBB=ON \
-D ENABLE_FAST_MATH=1 \
-D CUDA_FAST_MATH=1 \
-D WITH_CUBLAS=1 \
-D WITH_CUDA=ON \
-D BUILD_opencv_cudacodec=ON \
-D WITH_CUDNN=ON \
-D OPENCV_DNN_CUDA=ON \
-D WITH_QT=OFF \
-D WITH_OPENGL=ON \
-D BUILD_opencv_apps=OFF \
-D BUILD_opencv_python2=OFF \
-D OPENCV_GENERATE_PKGCONFIG=ON \
-D OPENCV_PC_FILE_NAME=opencv.pc \
-D OPENCV_ENABLE_NONFREE=ON \
-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-${VERSION}/modules \
-D INSTALL_PYTHON_EXAMPLES=OFF \
-D INSTALL_C_EXAMPLES=OFF \
-D BUILD_EXAMPLES=OFF \
-D CUDA_ARCH_BIN=8.6 \
-D WITH_FFMPEG=ON \
-D CUDNN_INCLUDE_DIR=/usr/local/cuda/include \
-D CUDNN_LIBRARY=/usr/local/cuda/lib64/libcudnn.so \
..

make -j 8
sudo make -j 8 install

```

# Modern Web Application

```html

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ChatGGG</title>
    <!-- faceicon.svg -->
    <link rel="icon" href="./favicon.svg" type="image/svg+xml">
    <!-- <link rel=stylesheet href="./quill.css" async defer> -->
    <link rel=stylesheet href="//cdn.quilljs.com/1.3.6/quill.snow.css" async defer>
    <link rel=stylesheet href="//cdnjs.cloudflare.com/ajax/libs/KaTeX/0.7.1/katex.min.css" async defer>
    <link rel=stylesheet href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/styles/monokai-sublime.min.css"
        async defer>
    <script src="https://cdn.tailwindcss.com?plugins=forms,typography,aspect-ratio,line-clamp"></script>
    <script type="importmap">
    {
      "imports": {
        "markdown-it": "https://esm.sh/markdown-it@14.0.0",
        "react": "https://esm.sh/stable/react@18.2.0/",
        "react-router": "https://esm.sh/react-router@6.22.3",
        "react-router-dom": "https://esm.sh/react-router-dom@6.22.3",
        "react-dom": "https://esm.sh/react-dom@18.2.0/",
        "tailwindcss": "https://esm.sh/tailwindcss@3.4.1",
        "vue": "https://unpkg.com/vue@3/dist/vue.esm-browser.js",
        "svelte": "https://esm.sh/svelte@4.2.12",
        "solid-js": "https://esm.sh/solid-js@1.8.15",
        "lit-html": "https://esm.sh/lit-html@3.1.2",
        "y-indexeddb": "/y-indexeddb.js",
        "quill": "https://esm.sh/quill@1.3.7",
        "yjs": "https://esm.sh/yjs@13.6.10",
        "y-websocket": "/y-websocket.js",
        "quill-cursors": "https://esm.sh/quill-cursors@4.0.2",
        "y-quill": "/y-quill.js"
      }
    }
    </script>
    <style>
        [v-cloak] {
            display: none;
        }

        #container {
            width: 863px;
            height: 600px;
        }
    </style>
</head>

<body>
    <button type="button" id="y-connect-btn">Disconnect</button>
    <p></p>
    <p>This is a demo of the <a href="https://github.com/yjs/yjs">Yjs</a> ⇔ <a href="https://quilljs.com/">Quill</a>
        binding: <a href="https://github.com/yjs/y-quill">y-quill</a>.</p>
    <p>The content of this editor is shared with every client that visits this domain.</p>

    <script type="module">
        import * as Y from 'yjs'
        import { WebsocketProvider } from 'y-websocket'
        import { QuillBinding } from 'y-quill'
        import Quill from 'quill'
        import QuillCursors from 'quill-cursors'
        import { IndexeddbPersistence } from 'y-indexeddb'

        Quill.register('modules/cursors', QuillCursors)

        window.addEventListener('load', () => {
            const ydoc = new Y.Doc()
            const provider = new WebsocketProvider(
                'ws://192.168.43.246:1234/', // use the public ws server
                // `ws${location.protocol.slice(4)}//${location.host}/ws`, // alternatively: use the local ws server (run `npm start` in root directory)
                'quill-demo-6',
                ydoc
            )
            const indexeddbProvider = new IndexeddbPersistence('y-indexeddb', ydoc)
            const ytext = ydoc.getText('quill')
            const editorContainer = document.createElement('div')
            editorContainer.setAttribute('id', 'editor')
            document.body.insertBefore(editorContainer, null)

            const editor = new Quill(editorContainer, {
                modules: {
                    cursors: true,
                    toolbar: [
                        [{ header: [1, 2, false] }],
                        ['bold', 'italic', 'underline'],
                        ['image', 'code-block']
                    ],
                    history: {
                        userOnly: true
                    }
                },
                placeholder: 'Start collaborating...',
                theme: 'snow' // or 'bubble'
            })

            const binding = new QuillBinding(ytext, editor, provider.awareness)

            /*
            // Define user name and user name
            // Check the quill-cursors package on how to change the way cursors are rendered
            provider.awareness.setLocalStateField('user', {
              name: 'Typing Jimmy',
              color: 'blue'
            })
            */

            const connectBtn = document.getElementById('y-connect-btn')
            connectBtn.addEventListener('click', () => {
                if (provider.shouldConnect) {
                    provider.disconnect()
                    connectBtn.textContent = 'Connect'
                } else {
                    provider.connect()
                    connectBtn.textContent = 'Disconnect'
                }
            })

            // @ts-ignore
            window.example = { provider, ydoc, ytext, binding, Y }
        })
    </script>
</body>

</html>

```

# GTK

```c
#include <gtk/gtk.h>

static void add_task(GtkWidget *widget, gpointer data);
static void remove_task(GtkWidget *widget, gpointer data);



void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *window, *listbox, *add_button, *entry, *scrolled_window;
    GtkWidget *vbox, *hbox; // Vertical and horizontal boxes for layout

    // Create a new window, and set its title
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "To-Do List");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Vertical box for holding the main UI elements
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Scrolled window for the listbox
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 200, 150);
    gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, TRUE, TRUE, 0);

    // Listbox for tasks
    listbox = gtk_list_box_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), listbox);

    // Horizontal box for input and add button
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, TRUE, 0);

    // Task entry field
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);

    // Add task button
    add_button = gtk_button_new_with_label("Add Task");
    gtk_box_pack_start(GTK_BOX(hbox), add_button, FALSE, TRUE, 0);

    // Connect the "clicked" event of the button to the callback function
    g_signal_connect(add_button, "clicked", G_CALLBACK(add_task), entry);

    // Remove task button, placed outside of hbox for simplicity
    GtkWidget *remove_button = gtk_button_new_with_label("Remove Selected Task");
    gtk_box_pack_start(GTK_BOX(vbox), remove_button, FALSE, TRUE, 0);

    // Connect the "clicked" event of the button to the callback function
    g_signal_connect(remove_button, "clicked", G_CALLBACK(remove_task), listbox);

    gtk_widget_show_all(window);
}

static void add_task(GtkWidget *widget, gpointer data) {
    const char *task_text = gtk_entry_get_text(GTK_ENTRY(data));
    if (task_text[0] == '\0') return; // Don't add empty tasks

    GtkWidget *row = gtk_list_box_row_new();
    GtkWidget *label = gtk_label_new(task_text);
    gtk_container_add(GTK_CONTAINER(row), label);
    gtk_container_add(GTK_CONTAINER(gtk_widget_get_parent(widget)), row);

    gtk_widget_show_all(gtk_widget_get_parent(widget));

    gtk_entry_set_text(GTK_ENTRY(data), ""); // Clear entry field
}

static void remove_task(GtkWidget *widget, gpointer data) {
    GtkListBox *listbox = GTK_LIST_BOX(data);
    GtkListBoxRow *row = gtk_list_box_get_selected_row(listbox);

    if (row != NULL) {
        gtk_widget_destroy(GTK_WIDGET(row));
    }
}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.todo", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
```

# Modern Web development

esbuild

```html

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ChatGGG</title>
    <!-- faceicon.svg -->
    <link rel="icon" href="./favicon.svg" type="image/svg+xml">
    <script src="https://cdn.tailwindcss.com?plugins=forms,typography,aspect-ratio,line-clamp"></script>
    <script type="importmap">
    {
      "imports": {
        "markdown-it": "https://esm.sh/markdown-it@14.0.0",
        "react": "https://esm.sh/stable/react@18.2.0/",
        "react-router": "https://esm.sh/react-router@6.22.3",
        "react-router-dom": "https://esm.sh/react-router-dom@6.22.3",
        "react-dom": "https://esm.sh/react-dom@18.2.0/",
        "tailwindcss": "https://esm.sh/tailwindcss@3.4.1",
        "vue": "https://unpkg.com/vue@3/dist/vue.esm-browser.js",
        "svelte": "https://esm.sh/svelte@4.2.12",
        "solid-js": "https://esm.sh/solid-js@1.8.15",
        "lit-html": "https://esm.sh/lit-html@3.1.2"
      }
    }
    </script>
    <style>
        [v-cloak] {
            display: none;
        }

        #container {
            width: 863px;
            height: 600px;
        }
    </style>
</head>

<body>
    <div id="app"></div>
    <div v-cloak id="app-vue" class="text-red-200">
        {{ message }}
    </div>
    <div id="container"></div>
    <script type="module" src="./app.js"></script>
    <script type="module">
        import { App, Counter } from './app.js';
        import ReactDOM from "react-dom";
        import markdownit from "markdown-it";
        ReactDOM.createRoot(document.querySelector('#app')).render(App());

        import * as monaco from 'https://esm.sh/monaco-editor';
        import editorWorker from 'https://esm.sh/monaco-editor/esm/vs/editor/editor.worker?worker';
        import jsonWorker from 'https://esm.sh/monaco-editor/esm/vs/language/json/json.worker?worker';
        import cssWorker from 'https://esm.sh/monaco-editor/esm/vs/language/css/css.worker?worker';
        import htmlWorker from 'https://esm.sh/monaco-editor/esm/vs/language/html/html.worker?worker';
        import tsWorker from 'https://esm.sh/monaco-editor/esm/vs/language/typescript/ts.worker?worker';

        self.MonacoEnvironment = {
            getWorker(_, label) {
                if (label === 'json') {
                    return new jsonWorker();
                }
                if (label === 'css' || label === 'scss' || label === 'less') {
                    return new cssWorker();
                }
                if (label === 'html' || label === 'handlebars' || label === 'razor') {
                    return new htmlWorker();
                }
                if (label === 'typescript' || label === 'javascript') {
                    return new tsWorker();
                }
                return new editorWorker();
            }
        };
        monaco.editor.create(document.getElementById('container'), {
            value: ['function x() {', '\tconsole.log("Hello world!");', '}'].join('\n'),
            language: 'javascript'
        });
    </script>

    <script type="module">
        import { createApp, ref } from 'vue'

        createApp({
            setup() {
                const message = ref('Hello Vue!')
                return {
                    message
                }
            }
        }).mount('#app-vue')
    </script>
</body>

</html>

```

# WebGL threejs

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>Hello World WebGL</title>
    <style>
        body {
            margin: 0;
        }

        canvas {
            display: block;
        }
    </style>
</head>

<body>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/three.js/r128/three.min.js"></script>
    <script>
        // Create an empty scene
        var scene = new THREE.Scene();

        // Create a basic perspective camera
        var camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
        camera.position.z = 4;

        // Create a renderer with Antialiasing
        var renderer = new THREE.WebGLRenderer({ antialias: true });

        // Configure renderer clear color
        renderer.setClearColor("#000000");

        // Configure renderer size
        renderer.setSize(window.innerWidth, window.innerHeight);

        // Append Renderer to DOM
        document.body.appendChild(renderer.domElement);

        // ------------------------------------------------
        // FUN STARTS HERE
        // ------------------------------------------------

        // Create a Cube Mesh with basic material
        var geometry = new THREE.BoxGeometry(1, 1, 1);
        var material = new THREE.MeshBasicMaterial({ color: "#433F81" });
        var cube = new THREE.Mesh(geometry, material);

        // Add cube to Scene
        scene.add(cube);

        // Render Loop
        var render = function () {
            requestAnimationFrame(render);

            cube.rotation.x += 0.01;
            cube.rotation.y += 0.01;

            // Render the scene
            renderer.render(scene, camera);
        };

        render();
    </script>
</body>

</html>
```

# tokenier in c

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Token types
typedef enum {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    PUNCTUATION,
    INCREMENT,
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char value[50]; // Adjust the size as needed
} Token;

// Function to check if a string is a keyword
int isKeyword(const char *word) {
    const char *keywords[] = {"int", "void", "return", "if", "else", "while", "for"};
    const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }

    return 0; // Not a keyword
}

// Function to tokenize a C code
void tokenize(const char *code) {
    char buffer[50]; // Adjust the size as needed
    int bufferIndex = 0;

    for (size_t i = 0; i < strlen(code); i++) {
        char currentChar = code[i];

        if (isalnum(currentChar) || currentChar == '_') {
            // Collect characters for keywords or identifiers
            buffer[bufferIndex++] = currentChar;
        } else {
            // Handle non-alphanumeric characters
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                Token token;

                if (isKeyword(buffer)) {
                    token.type = KEYWORD;
                } else {
                    token.type = IDENTIFIER;
                }

                strcpy(token.value, buffer);
                printf("%s '%s'\n", token.type == KEYWORD ? "keyword" : "identifier", token.value);
                // Reset buffer
                bufferIndex = 0;
            }

            // Handle + - * / ( ) { } ; = characters
            if (currentChar == '+' || currentChar == '-') {
                // increment or decrement
                if (code[i + 1] == currentChar) {
                    Token token;
                    token.type = INCREMENT;
                    token.value[0] = currentChar;
                    token.value[1] = currentChar;
                    token.value[2] = '\0';
                    printf("increment '%s'\n", token.value);
                    i++;
                } else {
                    Token token;
                    token.type = OPERATOR;
                    token.value[0] = currentChar;
                    token.value[1] = '\0';
                    printf("operator '%s'\n", token.value);
                }
            } else if (currentChar == '(' || currentChar == ')' || currentChar == '{' || currentChar == '}' || currentChar == ';') {
                Token token;
                token.type = PUNCTUATION;
                token.value[0] = currentChar;
                token.value[1] = '\0';
                printf("punctuation '%s'\n", token.value);
            } else if (currentChar == '=') {
                Token token;
                token.type = OPERATOR;
                token.value[0] = currentChar;
                token.value[1] = '\0';
                printf("operator '%s'\n", token.value);
            } else if (currentChar == '+') {
                Token token;
                token.type = INCREMENT;
                token.value[0] = currentChar;
                token.value[1] = currentChar;
                token.value[2] = '\0';
                printf("increment '%s'\n", token.value);
            }
        }
    }
}

int main() {
    const char *inputCode = "int a, b;\nint c;\nvoid func(int x) {\n    a++;\n}";

    // Tokenize the input code
    tokenize(inputCode);

    return 0;
}

```

# WebGPU shader

```html

<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <title>webgpu-samples: helloTriangle</title>
  <style>
    :root {
      color-scheme: light dark;
    }

    html,
    body {
      margin: 0;
      /* remove default margin */
      height: 100%;
      /* make body fill the browser window */
      display: flex;
      place-content: center center;
    }

    canvas {
      width: 600px;
      height: 600px;
      max-width: 100%;
      display: block;
    }
  </style>
  <script type="module">
    var triangleVertWGSL = `@vertex
fn main(
  @builtin(vertex_index) VertexIndex : u32
) -> @builtin(position) vec4f {
  var pos = array<vec2f, 3>(
    vec2(0.0, 0.5),
    vec2(-0.5, -0.5),
    vec2(0.5, -0.5)
  );

  return vec4f(pos[VertexIndex], 0.0, 1.0);
}
`;

    var redFragWGSL = `@fragment
fn main() -> @location(0) vec4f {
  return vec4(1.0, 0.0, 0.0, 1.0);
}`;

    const canvas = document.querySelector('canvas');
    const adapter = await navigator.gpu.requestAdapter();
    const device = await adapter.requestDevice();
    const context = canvas.getContext('webgpu');
    const devicePixelRatio = window.devicePixelRatio;
    canvas.width = canvas.clientWidth * devicePixelRatio;
    canvas.height = canvas.clientHeight * devicePixelRatio;
    const presentationFormat = navigator.gpu.getPreferredCanvasFormat();
    context.configure({
      device,
      format: presentationFormat,
      alphaMode: 'premultiplied',
    });
    const pipeline = device.createRenderPipeline({
      layout: 'auto',
      vertex: {
        module: device.createShaderModule({
          code: triangleVertWGSL,
        }),
      },
      fragment: {
        module: device.createShaderModule({
          code: redFragWGSL,
        }),
        targets: [
          {
            format: presentationFormat,
          },
        ],
      },
      primitive: {
        topology: 'triangle-list',
      },
    });
    function frame() {
      const commandEncoder = device.createCommandEncoder();
      const textureView = context.getCurrentTexture().createView();
      const renderPassDescriptor = {
        colorAttachments: [
          {
            view: textureView,
            clearValue: { r: 0.0, g: 0.0, b: 0.0, a: 1.0 },
            loadOp: 'clear',
            storeOp: 'store',
          },
        ],
      };
      const passEncoder = commandEncoder.beginRenderPass(renderPassDescriptor);
      passEncoder.setPipeline(pipeline);
      passEncoder.draw(3);
      passEncoder.end();
      device.queue.submit([commandEncoder.finish()]);
      requestAnimationFrame(frame);
    }
    requestAnimationFrame(frame);
    //# sourceMappingURL=main.js.map

  </script>
</head>

<body>
  <canvas></canvas>
</body>

</html>

```

# linux system programming wav file reading

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WaveHeader{
    int riff_id;
    int riff_sz;
    int riff_fmt;
    int fmt_id;
    int fmt_sz;
    short audio_fmt;
    short num_chn;
    int sample_rate;
    int byte_rate;
    short block_align;
    short bits_per_sample;
    int data_id;
    int data_sz;
} WaveHeader;

int main(void)
{
	FILE *stream;
	WaveHeader wh;

	memset(&wh, 0x00, sizeof(wh));

	printf("sizeof(WaveHeader) = %ld.\n", sizeof(WaveHeader));

	if((stream=fopen("startup.wav","ro"))==NULL)
	{
		fprintf(stderr,"Can not open file.\n");
		return 0;
	}
	printf("open success.\n");

	fseek(stream, 0, SEEK_SET);

	fread(&wh,1,sizeof(wh),stream);

	fclose(stream);

	printf("riff_id %d,\n" \
			"riff_size %d\n" \
			"num_chn %d.\n" \
			"sample_rate %d.\n" \
			"byte_rate %d.\n" \
			"block_align %d.\n" \
			, wh.riff_id, wh.riff_sz, wh.num_chn, wh.sample_rate, wh.byte_rate, wh.block_align);

	return 0;
}

```

# cuda example

#include <iostream>

// Kernel definition
__global__ void matrixAdd(const float* A, const float* B, float* C, int Nx, int Ny) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    if (i < Nx && j < Ny) {
        int index = j * Nx + i;
        C[index] = A[index] + B[index];
    }
}

int main() {
    // Matrix dimensions
    const int Nx = 12;
    const int Ny = 6;

    // Allocate host memory
    float* h_A = new float[Nx * Ny];
    float* h_B = new float[Nx * Ny];
    float* h_C = new float[Nx * Ny];

    // Initialize host arrays
    // ... (code to fill in h_A and h_B with data)

    // Allocate device memory
    float *d_A, *d_B, *d_C;
    cudaMalloc(&d_A, Nx * Ny * sizeof(float));
    cudaMalloc(&d_B, Nx * Ny * sizeof(float));
    cudaMalloc(&d_C, Nx * Ny * sizeof(float));

    // Copy data from host to device
    cudaMemcpy(d_A, h_A, Nx * Ny * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, Nx * Ny * sizeof(float), cudaMemcpyHostToDevice);

    // Kernel launch
    dim3 threadsPerBlock(4, 3);
    dim3 numBlocks((Nx + threadsPerBlock.x - 1) / threadsPerBlock.x,
                   (Ny + threadsPerBlock.y - 1) / threadsPerBlock.y);
    matrixAdd<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, Nx, Ny);

    // Copy result back to host
    cudaMemcpy(h_C, d_C, Nx * Ny * sizeof(float), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    // Free host memory
    delete[] h_A;
    delete[] h_B;
    delete[] h_C;

    return 0;
}

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(matrix_add LANGUAGES CXX CUDA)

# Specify the executable and its source file
add_executable(matrix_add matrix_add.cu)

# Specify the C++ standard
set_target_properties(matrix_add PROPERTIES
                      CUDA_SEPARABLE_COMPILATION ON
                      CXX_STANDARD 14
                      CXX_STANDARD_REQUIRED ON)


# hash join

```go

package main

import (
	"fmt"
)

// Define the struct for table rows
type TableRowR struct {
	id    int
	value int
}

type TableRowS struct {
	id    int
	cdate string
	value int
}

// Define the struct for the join result
type JoinResult struct {
	R_id    int
	S_cdate string
}

// Mock data for tables R and S
var tableR = []TableRowR{
	{id: 1, value: 50},
	{id: 2, value: 120},
	{id: 3, value: 150},
}

var tableS = []TableRowS{
	{id: 2, cdate: "2024-02-16", value: 200},
	{id: 3, cdate: "2024-02-15", value: 90},
	{id: 4, cdate: "2024-02-14", value: 300},
}

// Step 1: Projection
func projectR(rows []TableRowR) []int {
	var projection []int
	for _, row := range rows {
		projection = append(projection, row.id)
	}
	return projection
}

// Step 2: Build hash table for the join
func buildHashTable(rows []TableRowR) map[int]TableRowR {
	hashTable := make(map[int]TableRowR)
	for _, row := range rows {
		hashTable[row.id] = row
	}
	return hashTable
}

// Step 3: Perform the join
func hashJoin(rHashTable map[int]TableRowR, sRows []TableRowS) []JoinResult {
	var results []JoinResult
	for _, sRow := range sRows {
		if rRow, ok := rHashTable[sRow.id]; ok {
			results = append(results, JoinResult{R_id: rRow.id, S_cdate: sRow.cdate})
		}
	}
	return results
}

// Step 4: Filter S by value
func filterS(rows []TableRowS) []TableRowS {
	var filtered []TableRowS
	for _, row := range rows {
		if row.value > 10 {
			filtered = append(filtered, row)
		}
	}
	return filtered
}

func main() {

	// Materialize hash table of R based on projection
	rHashTable := buildHashTable(tableR)

	// Materialize filtered S
	filteredS := filterS(tableS)

	// Perform join and materialize the result
	joinResults := hashJoin(rHashTable, filteredS)

	// Print the join results
	for _, result := range joinResults {
		fmt.Printf("R.id: %d, S.cdate: %s\n", result.R_id, result.S_cdate)
	}
}

```

# Automatic Diffe

```go

package main

import (
	"fmt"
	"math"
)

// Define a struct to hold the value and derivative
type AD struct {
	Value, Derivative float64
}

// Define operations for automatic differentiation
func (ad AD) Multiply(other AD) AD {
	return AD{
		Value:      ad.Value * other.Value,
		Derivative: ad.Value*other.Derivative + ad.Derivative*other.Value,
	}
}

func (ad AD) Add(other AD) AD {
	return AD{
		Value:      ad.Value + other.Value,
		Derivative: ad.Derivative + other.Derivative,
	}
}

func (ad AD) Subtract(other AD) AD {
	return AD{
		Value:      ad.Value - other.Value,
		Derivative: ad.Derivative - other.Derivative,
	}
}

func Log(ad AD) AD {
	return AD{
		Value:      math.Log(ad.Value),
		Derivative: ad.Derivative / ad.Value,
	}
}

func Sin(ad AD) AD {
	return AD{
		Value:      math.Sin(ad.Value),
		Derivative: ad.Derivative * math.Cos(ad.Value),
	}
}

func main() {
	// Initialize x1 and x2 with their values and derivatives
	// Since we are differentiating with respect to x1, its derivative is 1
	x1 := AD{Value: 2, Derivative: 1}
	// x2 is treated as a constant with respect to x1, so its derivative is 0
	x2 := AD{Value: 5, Derivative: 0}

	// Compute the function and its derivative using the chain rule
	v3 := Log(x1)
	v4 := x1.Multiply(x2)
	v5 := Sin(x2)
	v6 := v3.Add(v4)
	v7 := v6.Subtract(v5)

	fmt.Printf("The value of the function is: %.3f\n", v7.Value)
	fmt.Printf("The derivative of the function with respect to x1 is: %.3f\n", v7.Derivative)
}

```

# http proxy

$env:HTTP_PROXY = "http://127.0.0.1:7890"
$env:HTTPS_PROXY = "http://127.0.0.1:7890"

set http_proxy=http://192.168.43.1:7890
set https_proxy=http://192.168.43.1:7890

set http_proxy=hhttp://127.0.0.1:7890
set https_proxy=http://127.0.0.1:7890

$env:HTTP_PROXY = "http://192.168.43.1:7890"
$env:HTTPS_PROXY = "http://192.168.43.1:7890"

$env:HTTP_PROXY = ""
$env:HTTPS_PROXY = ""

# docker and dockerfile

docker container stop
docker container kill
docker container remove

```dockerfile

FROM alpine
CMD ["echo", "Hello World!"]

WORKDIR /usr/src

RUN apt update && apt install -y python3 python3-pip

RUN useradd --create-home appuser
USER appuser

COPY app.py .

ENTRYPOINT ["python3", "-m", "http.server"]
CMD ["8000"]

LABEL maintainer="tannal"
LABEL version = "1.0"
LABEL description = "more garbage code"

ENV API_KEY=hi_mom

EXPOSE 8000

HEALTHCHECK --interval=30s --timeout=10s \
  CMD curl -f http://localhost:6969/health || exit 1

VOLUME /db/data

docker build . -t awesome

docker build . -f Dockerfile -t alpine:helloworld

```


```dockerfile

FROM alpine
CMD ["echo", "Hello World!"]

docker build . -f Dockerfile -t alpine:helloworld
```

# frp systemd service


```bash

wget https://github.com/fatedier/frp/releases/download/v0.53.2/frp_0.53.2_linux_arm64.tar.gz

tar xvf frp_0.53.2_linux_arm64.tar.gz

wget https://github.com/fatedier/frp/releases/download/v0.53.2/frp_0.53.2_linux_amd64.tar.gz

sudo vim /etc/systemd/system/frps.service

config https://github.com/fatedier/frp/blob/1e8806d26b6c1ca5ee683deb38f64f89fe60c1fe/conf/frps_full_example.toml#L121

[Unit]
# 服务名称，可自定义
Description = frp server
After = network.target syslog.target
Wants = network.target

[Service]
Type = simple
# 启动frps的命令，需修改为您的frps的安装路径
ExecStart = /home/ubuntu/tannalwork/projects/frp_0.53.2_linux_amd64/frps -c /home/ubuntu/tannalwork/projects/frp_0.53.2_linux_amd64/frps.toml
Restart=always

[Install]
WantedBy = multi-user.target

# 启动frp
sudo systemctl start frps
# 停止frp
sudo systemctl stop frps
# 重启frp
sudo systemctl restart frps
# 查看frp状态
sudo systemctl status frps


sudo systemctl enable frps


sudo vim /etc/systemd/system/frpc.service
[Unit]
# 服务名称，可自定义
Description = frpc
After = network.target syslog.target
After=network-online.target
Wants=network-online.target systemd-networkd-wait-online.service

[Service]
Type = simple
# 启动frps的命令，需修改为您的frps的安装路径
ExecStart = /home/tannal/tannalwork/projects/frp_0.53.2_linux_arm64/frpc -c /home/tannal/tannalwork/projects/frp_0.53.2_linux_arm64/frpc.toml
Restart=always

[Install]
WantedBy = multi-user.target

sudo systemctl enable frpc

journalctl -u frpc.service


tar xvf frp_0.53.2_linux_amd64.tar.gz

./frps -c frps.toml


@tod
o clash systemctl

```


# symbol link lld

```bash

sudo apt install lld
sudo rm /usr/bin/ld

sudo ln -s /usr/bin/lld /usr/bin/ld
sudo ln -s /usr/bin/ld.lld /usr/bin/ld
sudo ln -sfn /usr/bin/lld /usr/bin/ld
sudo ln -s x86 /usr/bin/ld

sudo ln -sfn x86_64-linux-gnu-ld /usr/bin/ld
sudo ln -sfn aarch64-linux-gnu-ld /usr/bin/ld

sudo ln -sfn x86_64-linux-gnu-ld /usr/bin/ld

strace -e execve lld
strace -e execve ld

```

# ssh authorized keys

```bash

Ed25519 algorithm

rsa algorithm

vim ~/.ssh/authorized_keys

ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIDeryWc8zLoFzIIG1CaTRPD/WEY3ca6mqiLTpYSdPcYq tannal@ubuntu

ssh-keygen -t ed25519

```

# yolo v8

```bash

virtualenv yxl python=python3.8
virtualenv yxl --python=python3.8

Set-ExecutionPolicy Unrestricted -Force

set-executionpolicy remotesigned

Activate yxl/bin/activate

yxl/Scripts/activate

../yxl/Scripts/activate

pip freeze


pip install torch==1.2.0


git clone https://github.com/ultralytics/ultralytics.git


pip install .

nvidia-smi
CUDA Version: 12.2

pip install torch==2.0.1 torchvision==0.15+cu111 torchaudio==2.0.2

PyTorch	TorchAudio	Python
2.0.1	2.0.2	>=3.8 , <=3.11
2.0.0	2.0.1	>=3.8 , <=3.11
1.13.1	0.13.1	>=3.7 , <=3.10
1.13.0	0.13.0	>=3.7 , <=3.10

pip install ultralytics

```

# raylib starter

```bash
# CMakeLists.txt

cmake_minimum_required(VERSION 3.0.0)
project(ray VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

file(GLOB EXAMPLE_SOURCES "*.cc")
find_package(raylib CONFIG REQUIRED)


foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} PRIVATE raylib)
endforeach()

# main.cc
/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

```

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
