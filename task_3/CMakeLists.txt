cmake_minimum_required(VERSION 3.5)

project(task_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_3 main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/gcodeparser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/gcodeparser.cpp)
target_include_directories(task_3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
