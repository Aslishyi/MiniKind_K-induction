cmake_minimum_required(VERSION 3.10)
project(MiniKind_k-induction)

set(CMAKE_CXX_STANDARD 11)

add_executable(YourProjectName src/main.cpp
        src/main.cpp
        src/Tool/GetInput.h
        src/Tool/GetInput.cpp
        src/Tool/ExportOutput.h
        src/Tool/ExportOutput.cpp
        src/Translation/ExtractLustreInfo.cpp
        src/Translation/ExtractLustreInfo.h
        src/Tool/CheckTool.cpp
        src/Tool/CheckTool.h
        src/Tool/StringVectorTool.cpp
        src/Tool/StringVectorTool.h
        src/Translation/LustreNode.cpp
        src/Translation/LustreNode.h
        src/Translation/VarState.cpp
        src/Translation/VarState.h
        src/Translation/VarStateList.cpp
        src/Translation/VarStateList.h
        src/Tool/StringTool.cpp
        src/Tool/StringTool.h)

find_package(Boost 1.83.0 REQUIRED)
if(Boost_FOUND)
    set(Boost_LIBRARY_DIRS DD:/boost/boost_1_84_0/libs)
    message(Boost_INCLUDE_DIRS " ${Boost_INCLUDE_DIRS}")
    message(Boost_LIBRARY_DIRS " ${Boost_LIBRARY_DIRS}")
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

