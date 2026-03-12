cmake_minimum_required(VERSION 3.10.0)
project(PlatForm VERSION 0.1.0 LANGUAGES C CXX)

# 添加SFML的CMake模块路径
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};D:/SFML64/lib/cmake/SFML")

# 查找SFML库
find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

# 添加可执行文件及其源文件
add_executable(PlatForm
    main.cpp
    include/MenuState.cpp
    include/GameState.cpp
)

# 链接SFML库，包括音频模块（ResourceManager使用了 sf::SoundBuffer）
target_link_libraries(PlatForm PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)


