cmake_minimum_required(VERSION 3.22)
project(Trepa_Colinas C)

set(CMAKE_C_STANDARD 99)

add_executable(Trepa_Colinas main.c funcao.c funcao.h utils.c utils.h algoritmo.c algoritmo.h)
