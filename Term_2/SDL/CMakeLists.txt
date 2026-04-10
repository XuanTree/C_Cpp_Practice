cmake_minimum_required(VERSION 3.10)
project(MySDL3Project LANGUAGES C CXX)

# 设置 SDL3 的查找路径，请根据你的实际情况修改
set(SDL3_DIR "D:/SDL3-mingw/x86_64-w64-mingw32/lib/cmake/SDL3")
find_package(SDL3 REQUIRED)

# 添加可执行文件
add_executable(${PROJECT_NAME} main.cpp)

# 链接 SDL3 库
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

# 自动将 SDL3.dll 拷贝到输出目录
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL3::SDL3>
    $<TARGET_FILE_DIR:${PROJECT_NAME}>)
