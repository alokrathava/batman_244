cmake_minimum_required(VERSION 3.23)
project(WS06_DIY)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WS06_DIY
        Basket.cpp
        Basket.h
        main.cpp)
