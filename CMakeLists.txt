cmake_minimum_required(VERSION 3.31)
project(ordenacao C)

set(CMAKE_C_STANDARD 99)

add_executable(ordenacao main.c
        ordenacao-normal.c
        ordenacao-ponteiros.c
        alg.h)
