cmake_minimum_required (VERSION 3.12)
project (cpp-magic-squares)

file (GLOB magic-squares_SRC "src/*.cpp")
add_executable(magic-squares ${magic-squares_SRC})
