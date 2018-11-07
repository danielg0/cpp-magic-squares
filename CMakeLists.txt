cmake_minimum_required (VERSION 3.12)
project (cpp-magic-squares)

find_package (gflags REQUIRED)

file (GLOB magic-squares_SRC "src/*.cpp")
include_directories (include)

add_executable (magic-squares ${magic-squares_SRC})
target_link_libraries (magic-squares gflags)
