cmake_minimum_required(VERSION 4.2)
project(BattleAirNeo)

include_directories(./include)
aux_source_directory(./src srcs)

set(CMAKE_CXX_STANDARD 17)

add_executable(BattleAirNeo main.cpp ${srcs})

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};D:/SFML64/lib/cmake/SFML")

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)
target_link_libraries(BattleAirNeo PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)
