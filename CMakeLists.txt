cmake_minimum_required(VERSION 3.0)
project(stompblocks)

add_definitions(--std=c++14 -Wall -Werror -pedantic -g)
set(stompblocks_SOURCES definitions.cpp block.cpp block_descriptor.cpp parameter.cpp parameter_descriptor.cpp describable.cpp main.cpp)

add_executable(stompblocks ${stompblocks_SOURCES})
target_link_libraries(stompblocks -ljsoncpp)

