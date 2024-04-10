# MiniKind_k-induction使用手册

## 1.完成编译

该项目需要首先下载boost库，教程链接如下https://zhuanlan.zhihu.com/p/85806857

#### 4.10错误日志 

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





