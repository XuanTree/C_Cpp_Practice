# CMakeList.txt: Visual_Studio 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑 #
cmake_minimum_required (VERSION 3.10)

include_directories(./include)
aux_source_directory(./src srcs)

project (Visual_Studio)

add_executable(Visual_Studio main.cpp ${srcs} "src/Test.cpp")