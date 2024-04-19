cmake_minimum_required(VERSION 3.10)
project(MiniKind_k-induction)

set(CMAKE_CXX_STANDARD 20)

#add_executable(YourProjectName src/main.cpp
#        src/main.cpp
#        src/Tool/GetInput.h
#        src/Tool/GetInput.cpp
#        src/Tool/ExportOutput.h
#        src/Tool/ExportOutput.cpp
#        src/Translation/ExtractLustreInfo.cpp
#        src/Translation/ExtractLustreInfo.h
#        src/Tool/CheckTool.cpp
#        src/Tool/CheckTool.h
#        src/Tool/StringVectorTool.cpp
#        src/Tool/StringVectorTool.h
#        src/Translation/LustreNode.cpp
#        src/Translation/LustreNode.h
#        src/Translation/VarState.cpp
#        src/Translation/VarState.h
#        src/Translation/VarStateList.cpp
#        src/Translation/VarStateList.h
#        src/Tool/StringTool.cpp
#        src/Tool/StringTool.h)

find_package(Boost 1.83.0 REQUIRED)
if(Boost_FOUND)
    set(Boost_LIBRARY_DIRS DD:/boost/boost_1_84_0/libs)
    message(Boost_INCLUDE_DIRS " ${Boost_INCLUDE_DIRS}")
    message(Boost_LIBRARY_DIRS " ${Boost_LIBRARY_DIRS}")
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

option(VCPKG_CMAKE "设置使用vcpkg安装依赖" OFF)

if(VCPKG_CMAKE)
    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE "/home/blcm/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake"
                CACHE STRING "Vcpkg toolchain file" FORCE)
    else()
        message(STATUS "Using manually specified CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
    endif()
endif()

#设置输出compile_commands.json以供LSP服务器读取
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
#project(Ql2c)


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
include_directories(${ANTLR4_INCLUDE_DIR} ${PROJECT_BINARY_DIR})

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
        antlr4_static)
