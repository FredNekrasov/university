cmake_minimum_required(VERSION 3.29)
project(CPL C)

set(CMAKE_C_STANDARD 23)

add_executable(CPL src/main.c
        src/pws/firstPW/firstPW1V.c
        src/pws/firstPW/firstPW2V.c)