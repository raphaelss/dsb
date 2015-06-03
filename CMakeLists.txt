cmake_minimum_required(VERSION 3.0)
project(dsb)

add_definitions(--std=c++11 -Wall -Werror -pedantic -g)
set(dsb_SOURCES main.cpp)

add_executable(dsb ${dsb_SOURCES})

