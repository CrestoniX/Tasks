cmake_minimum_required(VERSION 3.5)

project(task_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_1
    main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/structures.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/manipulator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/manipulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/utils_funcs.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/utils_funcs.h)
target_include_directories(task_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
