cmake_minimum_required(VERSION 3.10)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
set(SRCS src/main.c src/init.c src/work.c src/help_print.c src/exit.c
        src/stack.c src/heap_1.c src/heap_2.c src/list.c src/free.c src/sort.c src/print.c src/out.c src/e.c)
add_executable(ft_ls ${SRCS})