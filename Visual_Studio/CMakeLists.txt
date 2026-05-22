cmake_minimum_required(VERSION 3.10.0)
project(Visual_Studio VERSION 0.1.0 LANGUAGES C CXX)

include_directories(./include)
aux_source_directory(./src srcs)

add_executable(Visual_Studio main.cpp ${srcs} "src/Test.cpp" "include/Test.h")

