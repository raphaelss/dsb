cmake_minimum_required(VERSION 2.8)
project(dsb)

add_definitions(--std=c++11 -Wall -Werror -pedantic -g)
set(dsb_SOURCES block_descriptor.cpp main.cpp)

add_executable(dsb ${dsb_SOURCES})

