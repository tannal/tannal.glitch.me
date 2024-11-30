# eva-llvm

```CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(eval-llvm)

set(CMAKE_CXX_STANDARD 14)

# Find LLVM package
find_package(LLVM REQUIRED CONFIG)

# Set include directories
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Add your source files
add_executable(eval-llvm eva-llvm.cpp)

# Link against LLVM libraries
target_link_libraries(eval-llvm LLVM)
```

```eva-llvm.cpp


#include "EvaLLVM.h"

int main(int argc, char **argv) {

  std::string program = R"(
        42
    )";

  EvaLLVM vm;

  vm.exec(program);

  return 0;
}

```

```EvaLLVM.h

#ifndef EvaLLVM_h

#define EvaLLVM_h

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <memory>
#include <system_error>

class EvaLLVM {
public:
    EvaLLVM() { moduleInit(); }

    void exec(const std::string &program) { 
        saveModuleToFile("./out.ll");
    }


private:
    void saveModuleToFile(const std::string &filename){
        std::error_code errCode;
        llvm::raw_fd_ostream outLL(filename, errCode);

        module->print(outLL, nullptr);
    } // Declare the saveModuleToFile function
    void moduleInit() {
        ctx = std::make_unique<llvm::LLVMContext>();
        module = std::make_unique<llvm::Module>("EvaLLVM", *ctx);
        builder = std::make_unique<llvm::IRBuilder<>>(*ctx);
    }

  std::unique_ptr<llvm::LLVMContext> ctx;

  std::unique_ptr<llvm::Module> module;

  std::unique_ptr<llvm::IRBuilder<>> builder;
};

#endif


```


