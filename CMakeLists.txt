 
cmake_minimum_required(VERSION 3.10)
project(CheckASIO)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(CheckASIO main.cpp)

target_link_libraries(CheckASIO ${Boost_LIBRARIES})
