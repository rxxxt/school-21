cmake_minimum_required(VERSION 3.17)
project(test_cub C)

set(CMAKE_C_FLAGS "-Lmlx -lmlx -framework OpenGL -framework AppKit")

link_directories(/usr/local/lib)
include_directories(/usr/local/include)
add_executable(test_cub main.c)