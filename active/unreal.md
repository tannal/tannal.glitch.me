# dev

git lfs install
git clone https://github.com/cqcallaw/shootergame.git

cd ~/tannalwork/projects/UnrealEngine
./GenerateProjectFiles.sh -project=/home/a17/tannalwork/projects/shootergame/ShooterGame.uproject -game -engine

./Engine/Binaries/Linux/UnrealEditor ~/tannalwork/projects/shootergame/ShooterGame.uproject

git clone https://github.com/EpicGames/UnrealEngine
./Setup.sh 
./GenerateProjectFiles.sh
make -j 20

根据你提供的编译输出信息，可以看出虚幻引擎开源版本的编译产生了许多共享库(.so文件)和一些可执行文件。主要的编译产物包括:

1. 各种模块的共享库文件(libUnrealFrontend-*.so)
2. UnrealFrontend可执行文件
3. 元数据文件(UnrealFrontend.version和UnrealFrontend.target)

要运行测试和使用编译好的引擎，你可以按照以下步骤操作:

1. 运行编辑器:
   在引擎根目录下运行:
   ```
   ./Engine/Binaries/Linux/UnrealEditor
   ```

2. 运行自动化测试:
   使用UnrealEditor命令行工具运行自动化测试:
   ```
   ./Engine/Binaries/Linux/UnrealEditor -ExecCmds="Automation RunTests Now" -log
   ```

3. 运行单元测试:
   ```
   ./Engine/Binaries/Linux/UnrealEditor-Cmd -run=AutomationCommandlet -TestFilter=UnitTests
   ```

4. 性能测试:
   ```
   ./Engine/Binaries/Linux/UnrealEditor-Cmd -run=AutomationCommandlet -TestFilter=Perf
   ```

5. 启动项目:
   如果你有一个UE项目，可以这样启动:
   ```
   ./Engine/Binaries/Linux/UnrealEditor /path/to/your/project/YourProject.uproject
   ```

6. 使用UnrealFrontend:
   UnrealFrontend是一个用于项目管理和部署的工具:
   ```
   ./Engine/Binaries/Linux/UnrealFrontend
   ```

7. 检查版本信息:
   查看UnrealFrontend.version文件内容:
   ```
   cat Engine/Binaries/Linux/UnrealFrontend.version
   ```

8. 运行特定模块的测试:
   你可以针对特定模块运行测试，例如:
   ```
   ./Engine/Binaries/Linux/UnrealEditor-Cmd -run=AutomationCommandlet -TestFilter=Core
   ```

记住，在运行这些命令之前，确保你已经正确设置了环境变量，并且所有必要的依赖都已安装。如果遇到权限问题，可能需要使用sudo或修改文件权限。

此外，虚幻引擎的开源版本可能与完整的商业版本有所不同，某些功能可能受限或需要额外的设置。建议查阅虚幻引擎的官方文档和GitHub仓库的README文件，以获取最新的使用说明和测试方法。


# tokei


(base) a17@17:~/tannalwork/projects/UnrealEngine$ tokei .
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Language              Files        Lines         Code     Comments       Blanks
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 ASP.NET                   6         1331         1072            0          259
 Autoconf                177        65564        53777         3772         8015
 Automake                 85         9367         6766         1239         1362
 Batch                   279        13693         9943          824         2926
 Bitbake                 101       145243       139672         4136         1435
 C                      4252      2820553      2177413       319723       323417
 C Header              68242     13895696      8308895      3579523      2007278
 CMake                  1935       176958       118895        32074        25989
 C#                     5335      1194050       836852       214724       142474
 C++                   36669     15834204     12226112      1325516      2282576
 C++ Header            33025      7752481      5535343      1232898       984240
 CSS                      33         8171         6495          598         1078
 Dockerfile              114         8244         4131         2257         1856
 .NET Resource           111        39488        33463         6018            7
 GLSL                    459        18756        13976         2044         2736
 HICAD                     1           46           36            0           10
 HLSL                    265        25323        16790         5145         3388
 INI                     498        28276        21998         3003         3275
 Java                    150        38308        28951         4733         4624
 JavaScript               84        14286        11178         1852         1256
 JSON                    554       203879       203246            0          633
 Lex                       1           53           50            0            3
 Makefile                600        41948        18337        15332         8279
 Meson                     3           61           41           12            8
 Module-Definition       165        28310        26199          188         1923
 MSBuild                 158        13325        12552          441          332
 NuGet Config              9           57           57            0            0
 Objective-C             136        36850        23696         7366         5788
 Objective-C++            81        28745        19671         4272         4802
 Perl                     74        12686         9101         1981         1604
 PowerShell               43         1974         1047          684          243
 Python                 8406      3620584      2926482       236364       457738
 Shell                   472       152820       111670        24471        16679
 Plain Text             5324      4523756            0      4356539       167217
 TSX                     143        56049        43361         1243        11445
 TypeScript               57        17391        11125         1962         4304
 Unreal Plugin           637        24547        24424            0          123
 Unreal Project           35         1626         1626            0            0
 Unreal Shader            21         3299         2483          300          516
 Unreal Shader Hea|        1            7            5            1            1
 Visual Studio Pro|      732       310554       310195          193          166
 Visual Studio Sol|      262        18888        18723            0          165
 XAML                     17         2585         2311          113          161
 Xcode Config              5          263          101           96           66
 XML                     763       335228       327254         3450         4524
 YAML                      3           21           18            0            3
─────────────────────────────────────────────────────────────────────────────────
 HTML                    434       762239       744020          201        18018
 |- CSS                  143        15324        14381          267          676
 |- JavaScript            85        57787        51100          598         6089
 (Total)                           835350       809501         1066        24783
─────────────────────────────────────────────────────────────────────────────────
 Markdown                503       103272            0        77036        26236
 |- BASH                  31          237          202           29            6
 |- C                      6          217          168           17           32
 |- CMake                  7          233          175           21           37
 |- C++                   25         1736         1285          223          228
 |- HTML                   1            7            7            0            0
 |- INI                    3           42           27            9            6
 |- JavaScript             1           39           36            1            2
 |- JSON                   9          218          216            0            2
 |- Markdown               2           22            0           12           10
 |- Python                 1            4            4            0            0
 |- Rust                   1           35           24            7            4
 |- Shell                 10          131           99           13           19
 |- TOML                   2           14            9            3            2
 |- XML                    4          139          126            4            9
 (Total)                           106346         2378        77375        26593
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 Total                171460     52467240     34457412     11473528      6536300
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━