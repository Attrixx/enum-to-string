cmake_minimum_required(VERSION 3.16)
project(EnumToStringExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(EnumToStringExample example.cpp)

target_include_directories(EnumToStringExample PRIVATE ./)

enable_testing()
add_subdirectory(tests)
