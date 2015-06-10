cmake_minimum_required(VERSION 3.0)
project(dsb)

add_definitions(--std=c++14 -Wall -Werror -pedantic -g)
set(dsb_SOURCES block.cpp parameter.cpp parameter_descriptor.cpp describable.cpp main.cpp)

add_executable(dsb ${dsb_SOURCES})

