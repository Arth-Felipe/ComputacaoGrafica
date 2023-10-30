# Arquivo de descrição dos testes que serão rodados num nó filho do sistema construído

cmake_minimum_required(VERSION 3.22.1)

set(This Atv2-Tests)

# Arquivo com os devidos testes, propriamente definidos
set(Sources
    Atv2-Tests.cc
)

# Similar a 'add_library', mas ao invés de fazer um componente ligado a um programa, faz o programa em si
add_executable(${This} ${Sources})

# Dependências (programa principal provido pelo Google + aquilo que será testado)
target_link_libraries(${This} PUBLIC
    gtest_main
    Atv2
)

# Indicação ao CMake de que este programa é um teste unitário
add_test(
    NAME ${This}
    COMMAND ${This}
)
