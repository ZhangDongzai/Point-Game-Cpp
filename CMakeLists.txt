cmake_minimum_required(VERSION 3.27)
project(Point_Game_Cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Point_Game_Cpp
        src/main.cpp
        include/setting.h
        include/game.h
        include/color.h)

target_link_libraries(Point_Game_Cpp
        SDL2main
        SDL2)
