cmake_minimum_required(VERSION 3.14)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_ls main.c header.h ft_ls.c fill.c list_func.c lst_func_more.c print_large.c)