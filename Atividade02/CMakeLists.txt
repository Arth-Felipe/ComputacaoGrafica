# Versão do CMake que estamos usando (pode ser conferido através de "cmake --version" no terminal)
cmake_minimum_required(VERSION 3.22.1)

# Variável "This" usada em diversos lugares (maior facilidade para caso se decida renomear o projeto)
set(This Atividade03)

# Estabelecimento do nome do projeto e linguagens em uso
project(${This} C CXX)

# Variáveis para informe de versões ao sistema de construção do programa
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Indicação ao CMake de que serão feitos testes unitários
enable_testing()

# Definição das dependências (pasta clonada do Google Test)
add_subdirectory(googletest)

## ↓↓ ↓↓ Descrição do que será construído no código ↓↓ ↓↓ ##

# Variável com arquivos "Headers"
set(Headers
    headers/color.h
    headers/mat2.h
    headers/mat3.h
    headers/mat4.h
    headers/vec2.h
    headers/vec3.h
    headers/vec4.h
)

# Variável com arquivos "Sources"
set(Sources
    src/main.cc
)

# Comando para realmente se fazer o código de testes (link com outras coisas para se formar o programa)
add_library(${This} STATIC ${Sources} ${Headers})

# Separação dos testes dos arquivos códigos (criação da sub-pasta)
add_subdirectory(test)
