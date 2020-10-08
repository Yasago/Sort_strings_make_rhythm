cmake_minimum_required(VERSION 3.15)
project(Sort_strings C)

set(CMAKE_C_STANDARD 99)

add_executable(Sort_strings main.c sortingLibrary.c sortingLibrary.h testLibrary.c testLibrary.h fileLibrary.c fileLibrary.h)