# potential mentors

# Camera

CameraDevice -> CaptureSession -> ImageReader -> MediaCodec -> MediaMuxer
[采集]         [处理]           [格式转换]    [编码]       [封装]

# ART

Anwar Ghuloum

Brian Carlstrom

Ian Rogers

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

https://groups.google.com/g/android-ndk

# tokie

(base) a17@17:~/tannalwork/projects/aosp$ tokei .
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Language              Files        Lines         Code     Comments       Blanks
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 ABNF                      1           93           69            1           23
 AWK                      90         8032         5570         1561          901
 ActionScript             56         7125         3715         2618          792
 Ada                      22         6411         4089         1120         1202
 Alex                     48        10009         8850            0         1159
 Arduino C++               3          640          521           40           79
 Arturo                    1        15392        15372            1           19
 AsciiDoc                 80        21544        16227          581         4736
 ASN.1                     1           14           10            0            4
 Assembly               1718      2558500      2427784        17606       113110
 GNU Style Assembly     6228      2947769      2447792       242525       257452
 Autoconf               3506       533377       397816        74721        60840
 Automake                449        44370        34020         4443         5907
 BASH                   1191       123765        87709        22728        13328
 Batch                   883        61028        45106         2058        13864
 Bazel                  8550      1258481      1069110        94726        94645
 Bitbake                2309      8399229      8153824       129502       115903
 C                     49068     19768417     14826235      2600419      2341763
 C Header             229279     58942721     40452589     12997205      5492927
 CMake                  5453       623445       473517        81040        68888
 C#                     1023       395697       319888        46919        28890
 C Shell                   6          275          177           40           58
 CIL (SELinux)           219       530052       439768        45491        44793
 COBOL                     3          725          725            0            0
 C++                  113627     42589132     33370313      4367861      4850958
 C++ Header            14869      6539736      5150491       517117       872128
 CSS                     476       106134        87227         6478        12429
 CUDA                     92        10741         7168         1938         1635
 CUE                      51          459          459            0            0
 Cython                   71        10258         7197         1368         1693
 D                       521        25375        22852         1635          888
 Dart                     26        12344        10318          597         1429
 Device Tree             528        45672        35588         6097         3987
 Dockerfile              642        32125        17674         9199         5252
 .NET Resource             3          370          174          195            1
 Dream Maker              17         8271         6928         1342            1
 Ebuild                    1           28            9           15            4
 Emacs Lisp               31         5981         4055         1212          714
 F#                       12          624          502            0          122
 Fish                      9          946          599          204          143
 FlatBuffers Schema      152        17570        10264         4536         2770
 Forge Config           1852        69680        53240        11982         4458
 Forth                     4         6775         6709           54           12
 FORTRAN Legacy           84        69467        45894        23459          114
 FORTRAN Modern            9          423          143          266           14
 FreeMarker               55         4389         3155          610          624
 F*                        4         1419         1419            0            0
 GDB Script                2          128           44           64           20
 Gherkin (Cucumber)       54          902          690           67          145
 Glimmer TS                1           46           38            0            8
 GLSL                   2670       160543       138622         6066        15855
 Go                    13563      3855212      3005026       512397       337789
 GraphQL                   3           51           51            0            0
 Groovy                  874        88566        47974        27275        13317
 Handlebars               22          683          613           12           58
 Happy                    29        32488        27616            0         4872
 HEX                      41         3209         3074            0          135
 HICAD                     2           75           57            0           18
 HLSL                    317        28641        26344           92         2205
 INI                     399        17100        11420         3326         2354
 Java                 194232     59860587     36785105     17411651      5663831
 JavaScript              936       268162       205164        36903        26095
 Jinja2                   51         7956         6929          207          820
 jq                       20          438          298           38          102
 JSON                   9183     20372801     20316286            0        56515
 Jsonnet                   7          213           93          108           12
 Julia                     2         1546          930          473          143
 Kotlin                17800      2378206      1702442       413965       261799
 Korn shell                2          616          446           94           76
 LLVM                  12854      1371337       704893       503770       162674
 Lex                      27         7598         5700          914          984
 LD Script               137         6062         4018         1495          549
 Common Lisp               1          692          502           81          109
 Lua                     137        34669        28635         2980         3054
 M4                      364       195426       132517        46142        16767
 Makefile               5440      4973524      4630644        85673       257207
 Meson                   504        45468        37712         3152         4604
 Metal Shading Lan|      347        19744        18201          276         1267
 Modelica                 39        16933        16700          103          130
 Module-Definition       986       264818       237305         2000        25513
 Monkey C                  7        54640        36541        18027           72
 MSBuild                  97         5182         4368          514          300
 Nextflow                  1            1            1            0            0
 Nix                       6          275          244            3           28
 NuGet Config              6           40           36            2            2
 OCaml                   123        23336        17791         3303         2242
 Objective-C            1888       350557       209365        98002        43190
 Objective-C++           950       161320       104335        34914        22071
 OpenCL                  286        65382        44287        12493         8602
 OpenType Feature |      138         2986         2333          290          363
 Pacman's makepkg          2           49           39            4            6
 Pan                      70         8718         7346          606          766
 Pascal                   16        19027        13358         3341         2328
 Perl                    491       263372       206252        30212        26908
 Pest                     24         1084          617          244          223
 Phix                      1            1            1            0            0
 PHP                     568        97186        52983        33125        11078
 PlantUML                 32         2547         2046           97          404
 PO File                 395      1162136       579957       338396       243783
 Poke                      2            2            2            0            0
 PowerShell               29         3424         2000          995          429
 Processing                9          845          724           89           32
 Prolog                  213         5044         4369          162          513
 Protocol Buffers       9681      1997329       844601       842169       310559
 Puppet                    1            1            1            0            0
 Python                34157      9859321      7824353       790256      1244712
 R                        32         5905         3410         1542          953
 Rusty Object Nota|        4           48           48            0            0
 RPM Specfile             98       105722        87885          495        17342
 Rakefile                  8          939          732           83          124
 ReScript               3996       220543       218429         1652          462
 ReStructuredText       5605      1261643       935559            0       326084
 Ruby                    317        63839        46240         9091         8508
 Ruby HTML                 1          127          102            0           25
 SRecode Template          1            4            4            0            0
 Sass                    196        14590        11868         1193         1529
 Scala                     3           90           29           46           15
 Scons                    85         4026         2651          562          813
 Shell                  7462       918208       617815       180160       120233
 Snakemake                45        17167        15536          236         1395
 SQL                     458        49909        34448        12984         2477
 Stata                     1           14           14            0            0
 Stratego/XT              39          241          227            0           14
 SVG                     540        87510        86397          987          126
 Swift                   106        22585        17728         2751         2106
 SWIG                     45        13026        10844          462         1720
 TCL                       2           27           15            6            6
 Templ                   727        38973        36262          798         1913
 TeX                      60        53157        33152        15430         4575
 Plain Text            33907     38178581            0     37241299       937282
 TOML                   2050       115660        88858        13040        13762
 TSX                       7          609          457           99           53
 TypeScript             1402       605039       463571       119358        22110
 Typst                     1           20           20            0            0
 VB6                      23         4146         3091          651          404
 VBScript                  4           32           24            2            6
 Apache Velocity         178         7654         5144         1105         1405
 Vim Script               17         5146         4951          109           86
 Visual Studio Pro|      969       264118       263444          563          111
 Visual Studio Sol|      110        18114        18058            0           56
 WebGPU Shader Lan|      403        19769        19693           20           56
 XSL                    2505       123668        49214        57496        16958
 Xcode Config              9          332           95          208           29
 XML                   87111     13982190     12550042      1160333       271815
 YAML                   1772       156826       142596         7587         6643
 Zig                       1           83           73            0           10
 Zsh                       2           32            4           26            2
─────────────────────────────────────────────────────────────────────────────────
 HTML                  31313     12696100     11878850       609947       207303
 |- CSS                 4259       287395       232576          504        54315
 |- HTML                  83         3117         2949           13          155
 |- JavaScript         22837      1063962       980289        75382         8291
 (Total)                         14050574     13094664       685846       270064
─────────────────────────────────────────────────────────────────────────────────
 Jupyter Notebooks        38         2136         1138          644          354
 |- Markdown               9          625            0          473          152
 |- Python                13         1511         1138          171          202
 (Total)                             4272         2276         1288          708
─────────────────────────────────────────────────────────────────────────────────
 Markdown               9818      1219354            0       889242       330112
 |- ABNF                   2          247          190           26           31
 |- BASH                 316         8113         7352          421          340
 |- Batch                  2            5            5            0            0
 |- Bazel                  5          213          176           25           12
 |- C                     63         2579         2053          282          244
 |- CMake                 38          773          558          108          107
 |- C#                     2           32           24            8            0
 |- C++                  107         7716         5859          970          887
 |- CSS                    3           51           46            2            3
 |- GLSL                   1            2            2            0            0
 |- Go                     9          255          179           38           38
 |- Groovy               255         1458         1257           54          147
 |- Haskell                1           28           22            0            6
 |- HTML                  48         1014          929           18           67
 |- INI                    3           94           74            5           15
 |- Java                 170         8229         6166         1095          968
 |- JavaScript             9          234          179           37           18
 |- JSON                  46         1387         1383            0            4
 |- JSX                    1           18           12            2            4
 |- Kotlin               103         8593         7257          563          773
 |- Lua                    2           38           33            5            0
 |- Makefile               5           67           37           24            6
 |- Markdown              59         1288            0          872          416
 |- Meson                  1           11           10            0            1
 |- Objective-C            2           32           24            8            0
 |- Perl                   1           30           16            5            9
 |- PHP                    3           21           19            2            0
 |- Python               419        10119         8147          696         1276
 |- Ruby                  12          173          124           31           18
 |- Rust                 582        25288        19503         2383         3402
 |- Scala                158          159          159            0            0
 |- Shell                203         2791         2413          199          179
 |- SQL                   18          520          403           87           30
 |- Swift                 12          178           88           55           35
 |- TOML                 374         1275         1093          127           55
 |- TypeScript             1           89           71            7           11
 |- XML                  299         8778         8141          202          435
 |- YAML                  26          344          303           38            3
 |- Zsh                    2            2            2            0            0
 (Total)                          1311598        74309       897637       339652
─────────────────────────────────────────────────────────────────────────────────
 Rust                  32618     10408853      8909629       459093      1040131
 |- Markdown           18956      1809769        70174      1345663       393932
 (Total)                         12218622      8979803      1804756      1434063
─────────────────────────────────────────────────────────────────────────────────
 Vue                      38          254          192            0           62
 |- CSS                   24          322          292            0           30
 |- HTML                  38          909          907            2            0
 |- JavaScript            34         1362         1305           33           24
 (Total)                             2847         2696           35          116
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Total                977689    337861500    226049378     84808014     27004108
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
