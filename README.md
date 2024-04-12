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

