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



**已完成部分：**

1. 转用lib使用z3库
2. 重新安装与使用boost库

### 4.21日志

**已完成部分：**

1. L2C解析子模块完成对lustre语言的SSA转化

2. 完成L2C解析模块项目的合并
3. 完成spdlog库的配置

### 4.22 日志

编写`CreateSolver.cpp`完成输入`VarStateList`类后创建`CreateSolver`类构造Z3求解器

完成对以下lustre函数的解析构建

```cpp
node Counter(init1: int;init2: int) returns (count1: int;count2: int);
var
    x: int;
    y: int;
let
    count1 = init1 + x;
    count2 = init2 + y;
tel;
```



**已完成部分：**

1. 完成Z3Solver求解器的构造部分`CreateSolver`类部分代码
2. 完成`Tool/Z3Tool`部分内容编写
3. 修改匹配lustre的正则表达式，使其可以匹配`node`或`function`开头的代码

### 4.23日志

编写`CreateSolver.cpp`完成对`"->"`符号简单公式的处理

完成对以下lustre函数的解析与构建

```cpp
node Counter(init1: int;init2: int) returns (count1: int;count2: int);
var
    x: int;
    y: int;
    t: int;
let
  init1 = x + 1;
  init2 = y + 1;
  count1 = init1 -> count1 + 1;
  count1 = count1 + x;
  count2 = t + 2;
tel;
```

**已完成部分：**

1. 编写`CreateSolver.cpp`完成对`"->"`符号简单公式的处理

### 4.25日志

编写`KInduction.cpp`完成对`"->"`符号语句的`Split Case K-induction`验证

`Split Case K-induction`参考代码

样例代码：

```cpp
int k = 1;
z3::expr larrow_expr, rarrow_expr, lhs_expr;
while(true){
    ...
    assert(k == 1 ? lhs_expr == larrow_expr : lhs_expr == rarrow_expr);
    k ++;
}
```

**Split Case K-induction**样例代码：

```cpp
#include <z3++.h>
#include <iostream>

using namespace z3;

bool check_k_induction(context& c, solver& s, expr& lhs_expr, expr& larrow_expr, expr& rarrow_expr, int max_k) {
    expr k = c.int_const("k");
    
    // Base Case: k == 1, assert lhs_expr == larrow_expr
    s.add(k == 1);
    s.add(lhs_expr == larrow_expr);
    check_result base_result = s.check();
    if (base_result == unsat) {
        std::cout << "Base case failed to hold." << std::endl;
        return false;
    } else if (base_result == sat) {
        model m = s.get_model();
        std::cout << "Base case counterexample found: k = " << m.eval(k) << ", lhs_expr = " << m.eval(lhs_expr) << ", larrow_expr = " << m.eval(larrow_expr) << std::endl;
        return false;
    }
    
    // Clear solver for inductive step
    s.reset();
    
    // Inductive Step: Assume valid for k, prove for k + 1
    expr k_prime = c.int_const("k_prime");
    s.add(k_prime == k + 1);
    s.add(implies(k == 1, lhs_expr == larrow_expr));
    s.add(implies(k > 1, lhs_expr == rarrow_expr));
    
    // Prove for k + 1
    s.add(implies(k_prime == 1, lhs_expr == larrow_expr));
    s.add(implies(k_prime > 1, lhs_expr == rarrow_expr));
    
    check_result step_result = s.check();
    if (step_result == unsat) {
        std::cout << "Inductive step holds." << std::endl;
        return true;
    } else if (step_result == sat) {
        model m = s.get_model();
        std::cout << "Inductive step counterexample found: k = " << m.eval(k) << ", k_prime = " << m.eval(k_prime)
                  << ", lhs_expr = " << m.eval(lhs_expr) << ", larrow_expr = " << m.eval(larrow_expr)
                  << ", rarrow_expr = " << m.eval(rarrow_expr) << std::endl;
        return false;
    }
    return false; // Default return for unexpected cases
}

int main() {
    context c;
    solver s(c);
    
    expr lhs_expr = c.int_const("lhs_expr");
    expr larrow_expr = c.int_const("larrow_expr");
    expr rarrow_expr = c.int_const("rarrow_expr");
    
    int max_k = 10;  // Maximum number of steps to verify k-induction (for practical termination in example)
    
    if (check_k_induction(c, s, lhs_expr, larrow_expr, rarrow_expr, max_k)) {
        std::cout << "Loop invariant verified successfully." << std::endl;
    } else {
        std::cout << "Loop invariant could not be verified." << std::endl;
    }

    return 0;
}
```







