cmake_minimum_required(VERSION 3.16)

set(project ascii)

set(include
    include/command.h
)

set(source
    source/main.cc
    source/command.cc
)

project(${project} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${project}
    ${include}
    ${source}
)

target_include_directories(${project}
    PUBLIC include
)
