cmake_minimum_required(VERSION 3.22.1)

set(This Example)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Atividade\ 02\ -\ 09.10/color.h
    Atividade\ 02\ -\ 09.10/mat2.h
    Atividade\ 02\ -\ 09.10/mat3.h
    Atividade\ 02\ -\ 09.10/mat4.h
    Atividade\ 02\ -\ 09.10/vec2.h
    Atividade\ 02\ -\ 09.10/vec3.h
    Atividade\ 02\ -\ 09.10/vec4.h
)
set(Sources
    Atividade\ 02\ -\ 09.10/main.cc
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)
