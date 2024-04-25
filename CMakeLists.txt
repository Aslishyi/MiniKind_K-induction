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



include_directories(${ANTLR4_INCLUDE_DIR} ${PROJECT_BINARY_DIR})

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
    find_package(spdlog CONFIG REQUIRED)
endif()

if(NOT VCPKG_CMAKE)
    add_subdirectory(lib/runtime)
    set(ANTLR4_INCLUDE_DIR
            lib/runtime/src
            lib/runtime/src/atn
            lib/runtime/src/dfa
            lib/runtime/src/internal
            lib/runtime/src/misc
            lib/runtime/src/support
            lib/runtime/src/tree
            lib/runtime/src/tree/pattern
            lib/runtime/src/tree/xpath
    )
    # spdlog的部分配置
    add_subdirectory(lib/spdlog-1.13.0)
endif()
include_directories(${ANTLR4_INCLUDE_DIR} ${PROJECT_BINARY_DIR})

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
        src/Lustre/expr/ApplyExprVisitor.h
        src/Z3Solver/CreateSolver.cpp
        src/Z3Solver/CreateSolver.h
        src/Tool/Z3Tool.cpp
        src/Tool/Z3Tool.h
        src/Z3Solver/KInduction.cpp
        src/Z3Solver/KInduction.h
)

add_dependencies(
        MiniKind_k-induction
        antlr4_static
)

target_link_libraries(
        MiniKind_k-induction
        antlr4_static
        spdlog::spdlog
        ${Z3_LIBRARIES}  # 链接z3库
        ${Boost_LIBRARY_DIR}
)
