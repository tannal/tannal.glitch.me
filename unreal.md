# dev

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