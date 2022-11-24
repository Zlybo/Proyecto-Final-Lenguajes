cmake_minimum_required(VERSION 3.23)
project(Proyecto_Final_Lenguajes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto_Final_Lenguajes
        main.cpp
        pronombres.h
        verbos.h
        articulos.h
        nombres.h
        clasificacion.cpp
        clasificacion.h
        verbos-espanol-conjugaciones.txt)
