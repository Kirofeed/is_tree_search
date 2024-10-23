cmake_minimum_required(VERSION 3.27)
project(create_tree VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -Wextra -Werror)

add_executable(create_tree main.cpp)
