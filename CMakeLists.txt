cmake_minimum_required(VERSION 3.0.0)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(Algorithms VERSION 1.0.0)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS "EPI/*.cpp")

add_executable(algorithms ${SRCS} "main.cpp")

target_include_directories(algorithms PRIVATE "EPI")
