# MiniKind_k-induction使用手册

## 编译环境

该项目需要首先下载boost库，教程链接如下https://zhuanlan.zhihu.com/p/85806857

Cmake选项`-DCMAKE_TOOLCHAIN_FILE=D:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake`

## 编码日志

### 4.10日志 

下载的boost版本为1.84.0

CMakeLists.txt 中添加(不知为何clion检测版本为1.83.0)

```cpp
find_package(Boost 1.83.0 REQUIRED)
if(Boost_FOUND)
    set(Boost_LIBRARY_DIRS DD:/boost/boost_1_84_0/libs)
    message(Boost_INCLUDE_DIRS " ${Boost_INCLUDE_DIRS}")
    message(Boost_LIBRARY_DIRS " ${Boost_LIBRARY_DIRS}")
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
```

将`D:\boost\boost_1_84_0\libs`粘贴到`D:\vcpkg\vcpkg\installed\x64-windows\include\boost`完成对boost的编译



**已完成部分：**

1. 完成boost库的安装
2. 使用`../src/Tool/GetInput.cpp`将`input.lustre`中lustre代码读入
3. 使用`../src/Tool/ExportOutput.cpp`将结果信息输出到`output.txt`
4. 完成`../src/Tool`中`CheckTool.cpp` 与 `StringVectorTool.cpp`中部分函数编写

### 4.11日志

需要被反复引用 include 的类需要在 .h 文件中加上

```cpp
#ifndef CLASSNAME_H
#define CLASSNAME_H

class ClassName{
    //.....
};

#endif
```

**LustreNode类内容：**

1. node名称
2. 输入参数列表
3. 输出参数列表
4. 局域变量列表
5. node语句列表
6. 状态转移列表（根据语句的“=”分割为“from”与“to”）

**已完成部分：**

1. 完成`../src/Translation/ExtractLustreInfo.cpp` 的编写，将lustre代码转化为`../src/Translation/LustreNode.cpp`类
2. 完成`../src/Translation/LustreNode.cpp`类构造，信息获取等内容
3. 完成`../src/Tool`中`CheckTool.cpp` 与 `StringVectorTool.cpp`中部分函数编写

### 4.12日志

k-induction算法需要将代码处理为如下格式（下文将称之为k输入格式）

```cpp
// X is program variables
Pre(X); // pre code from entry.
while(G(X)) { // loop guard.
  T(X, X'); // loop body, update X to X'.
}
assert(Post(X)); // post code and assertion.
```

因此新建`../src/Translation/VarState.cpp`与`../src/Translation/VarStateList.cpp`类

**VarState类内容：**

1. 用来存储单个变量的k输入格式
2. 变量名与变量类型
3. 4个`vector<string>, pre, guard, translate, post`

**VarStateList类内容：**

1. 用来存储一个node中所有的变量的k输入格式
2. 一个`map<string, VarStateList>`存储对应变量名到对应State的映射

**已完成部分：**

1. 完成`../src/Translation/VarState.cpp`与`../src/Translation/VarStateList.cpp`的编写，将`LustreNode`类转化为`../src/Translation/VarStateList.cpp`类
2. 完成`../src/Tool`中`StringTool.cpp` 与 `StringVectorTool.cpp`中部分函数编写

**待完成部分：**

1. `../src/Translation/VarStateList.cpp 中 BuildVarStateList方法`中通过代码语句获取Grand循环与Post断言信息
2. `../src/Translation/VarStateList.cpp 中 BuildVarStateList方法`中通过代码语句区分Pre与Translation信息

### 4.14日志

**已完成部分：**

1. 完成处理简单由"->"与"if"组成的循环的代码编写
2. 更新`../src/Tool`中`StringTool.cpp` 与`../src/Translation/VarStateList.cpp`中部分函数的编写

### 4.19日志

连接L2C解析模块内容与利用vcpkg安装z3库

**已完成部分：**

1. 成功连接L2C解析模块相关内容。相关内容在`../src/Lustre`和`../src/SymbolTable`两个文件夹中

2. 成功利用vcpkg安装z3库

### 4.20日志

4.19日z3库无法运行

放弃从vcpkg中使用z3，专用将z3库放到项目的lib文件夹中

于`https://github.com/Z3Prover/z3/releases`下载`z3-4.13.0-x64-win.zip`解压后放到项目的`lib`文件夹中，修改`cmakelists.txt`



于`https://github.com/boostorg/boost/releases`重新安装boost文件`boost-1.84.0.zip`

解压后于`boost-1.84.0`文件夹打开powershell执行文件运行`.\bootstrap.bat mingw`生成`b2.exe`

执行`.\b2.exe install --prefix="D:\boost-build"`将boost安装到`D:\boost-build`中



**由于lib中文件夹过大无法推送至github，因此创建.gitignore文件忽略lib/z3-4.13.0-x64-win文件夹**



`cmakelists.txt`中添加

```cpp
# 以下三个编译选项为可选 set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost)

set(INCLUDE_DIR include)
    
if(Boost_FOUND)
    list(APPEND INCLUDE_DIR ${Boost_INCLUDE_DIRS})
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(STATUS "Find Boost_Lib error")
endif()
aux_source_directory(. SRC_DIR)
include_directories(${INCLUDE_DIR})
    
    
    
add_executable(MiniKind_k-induction ${SRC_DIR})

target_link_libraries(MiniKind_k-induction ${Boost_LIBRARIES})
```

今日修改后完整`CMakeLists.txt`为

```cpp
cmake_minimum_required(VERSION 3.10)
project(MiniKind_k-induction)

set(CMAKE_CXX_STANDARD 20)

# Boost库
# 以下三个编译选项为可选 set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost)

set(INCLUDE_DIR include)

if(Boost_FOUND)
    list(APPEND INCLUDE_DIR ${Boost_INCLUDE_DIRS})
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(STATUS "Find Boost_Lib error")
endif()
aux_source_directory(. SRC_DIR)
include_directories(${INCLUDE_DIR})

# Z3库
find_package(Z3 REQUIRED)

# Vcpkg设置
option(VCPKG_CMAKE "设置使用vcpkg安装依赖" OFF)
if(VCPKG_CMAKE)
    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE "/home/blcm/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file" FORCE)
    else()
        message(STATUS "Using manually specified CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
    endif()
endif()

# 设置输出compile_commands.json以供LSP服务器读取
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

if(VCPKG_CMAKE)
    find_package(antlr4-runtime CONFIG REQUIRED)
    find_package(antlr4-generator CONFIG REQUIRED)
endif()

if(NOT VCPKG_CMAKE)
    add_subdirectory(runtime)
    set(ANTLR4_INCLUDE_DIR
            ${PROJECT_SOURCE_DIR}/runtime/src
            ${PROJECT_SOURCE_DIR}/runtime/src/atn
            ${PROJECT_SOURCE_DIR}/runtime/src/dfa
            ${PROJECT_SOURCE_DIR}/runtime/src/internal
            ${PROJECT_SOURCE_DIR}/runtime/src/misc
            ${PROJECT_SOURCE_DIR}/runtime/src/support
            ${PROJECT_SOURCE_DIR}/runtime/src/tree
            ${PROJECT_SOURCE_DIR}/runtime/src/tree/pattern
            ${PROJECT_SOURCE_DIR}/runtime/src/tree/xpath
    )
endif()

include_directories(
        ${Boost_INCLUDE_DIR}
        ${ANTLR4_INCLUDE_DIR}
        ${PROJECT_BINARY_DIR}
)

file(GLOB_RECURSE Ql2c_SRC
        "src/Tool/*.cpp"
        "src/Tool/*.h"
        "src/Translation/*.h"
        "src/Translation/*.cpp"
        "src/Lustre/*.cpp"
        "src/Lustre/*.h"
        "src/Lustre/generated/*.cpp"
        "src/Lustre/generated/*.h"
        "src/Lustre/visitor/*.cpp"
        "src/Lustre/visitor/*.h"
        "src/Lustre/typeBlock/*.cpp"
        "src/Lustre/typeBlock/*.h"
        "src/Lustre/constBlock/*.cpp"
        "src/Lustre/constBlock/*.h"
        "src/Lustre/userOpDecl/*.cpp"
        "src/Lustre/userOpDecl/*.h"
        "src/Lustre/equation/*.cpp"
        "src/Lustre/equation/*.h"
        "src/Lustre/tool/*.cpp"
        "src/Lustre/tool/*.h"
        "src/SymbolTable/*.cpp"
        "src/SymbolTable/*.h"
        "src/*.h"
        "src/*.cpp"
)

add_executable(
        MiniKind_k-induction src/main.cpp ${Ql2c_SRC}
)

add_dependencies(
        MiniKind_k-induction
        antlr4_static
)

target_link_libraries(
        MiniKind_k-induction
        antlr4_static
        ${Z3_LIBRARIES}  # 链接z3库
        ${Boost_LIBRARY_DIR}
)
```

**已完成部分：**

1. 转用lib使用z3库
2. 重新安装与使用boost库
