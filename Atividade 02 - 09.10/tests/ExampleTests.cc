/**
 * @file ExampleTests.cc
 * @author Arthur Felipe Bravo Pita
 * @brief Arquivo com os devidos testes, propriamente definidos
 * @version 1.0
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>

// #include "color.h"
// #include "vec2.h"
// #include "vec3.h"
// #include "vec4.h"
// #include "mat2.h"
#include "../Atividade 02 - 09.10/mat3.h"
#include "../Atividade 02 - 09.10/mat4.h"

// TEST(TesteVec2, TesteX) {}
// TEST(TesteVec3, TesteX) {}
// TEST(TesteVec4, TesteX) {}
// TEST(TesteMat2, TesteX) {}


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //


/**
 * @brief Teste da criação de uma matriz 3x3 com o construtor personalizado, que permite especificar os elementos da matriz.
 * 
 */
TEST(TestesMat3, TesteCriacaoMatriz3x3) {
    mat3 mat3_A(1.0, 2.0, 3.0,
                4.0, 5.0, 6.0,
                7.0, 8.0, 9.0);

    EXPECT_EQ(mat3_A(0, 0), 1.0);
    EXPECT_EQ(mat3_A(1, 1), 5.0);
    EXPECT_EQ(mat3_A(2, 2), 9.0);
}


/**
 * @brief Teste de multiplicação de matriz por matriz.
 * 
 */
TEST(TestesMat3, TesteMultiplicacaoEntreMatrizes3x3) {
    mat3 mat3_A(1.0, 2.0, 3.0,
                 4.0, 5.0, 6.0,
                 7.0, 8.0, 9.0);
    mat3 mat3_B(9.0, 8.0, 7.0,
                 6.0, 5.0, 4.0,
                 3.0, 2.0, 1.0);
    mat3 resultado = mat3_A * mat3_B;

    mat3 esperado(30.0, 24.0, 18.0,
                  84.0, 69.0, 54.0,
                  138.0, 114.0, 90.0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(resultado(i, j), esperado(i, j));
}   }   }


/**
 * @brief Teste de multiplicação de matriz por vetor.
 * 
 */
TEST(TestesMat3, TesteMultiplicacaoMatriz3x3PorVetor) {
    mat3 mat3_A(1.0, 2.0, 3.0,
                4.0, 5.0, 6.0,
                7.0, 8.0, 9.0);
    vec3 vetor(1.0, 2.0, 3.0);
    vec3 resultado = mat3_A * vetor;

    vec3 esperado(14.0, 32.0, 50.0);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(resultado[i], esperado[i]);
}   }


/**
 * @brief Teste do cálculo do determinante da matriz.
 * 
 */
TEST(TestesMat3, TesteDeterminante3x3) {
    mat3 mat3_A(1.0, 2.0, 3.0,
                4.0, 5.0, 6.0,
                7.0, 8.0, 9.0);
    double determinante = mat3_A.determinant();

    double esperado = 0.0;

    EXPECT_EQ(determinante, esperado);
}


/**
 * @brief Teste de criação de uma matriz de identidade.
 * 
 */
TEST(TestesMat3, TesteMatrizIdentidade3x3) {
    mat3 identidade = identity3();
    mat3 mat3_A(1.0, 0.0, 0.0,
                0.0, 1.0, 0.0,
                0.0, 0.0, 1.0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(identidade(i, j), mat3_A(i, j));
}   }   }


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //


/**
 * @brief Teste de criação de uma matriz 4x4 com construtor personalizado, que permite especificar os elementos da matriz.
 * 
 */
TEST(TestesMat4, TesteCriacaoMatriz4x4) {
    mat4 mat4_A(1.0, 2.0, 3.0, 4.0,
                5.0, 6.0, 7.0, 8.0,
                9.0, 10.0, 11.0, 12.0,
                13.0, 14.0, 15.0, 16.0);

    EXPECT_EQ(mat4_A(0, 0), 1.0);
    EXPECT_EQ(mat4_A(1, 1), 6.0);
    EXPECT_EQ(mat4_A(2, 2), 11.0);
    EXPECT_EQ(mat4_A(3, 3), 16.0);
}


/**
 * @brief Teste de negação da matriz, que inverte todos os seus elementos.
 * 
 */
TEST(TestesMat4, TesteNegacaoMatriz4x4) {
    mat4 mat4_A(1.0, 2.0, 3.0, 4.0,
                5.0, 6.0, 7.0, 8.0,
                9.0, 10.0, 11.0, 12.0,
                13.0, 14.0, 15.0, 16.0);

    mat4 resultado = -mat4_A;

    mat4 esperado(-1.0, -2.0, -3.0, -4.0,
                 -5.0, -6.0, -7.0, -8.0,
                 -9.0, -10.0, -11.0, -12.0,
                 -13.0, -14.0, -15.0, -16.0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(resultado(i, j), esperado(i, j));
}   }   }


/**
 * @brief Teste de multiplicação de matriz por escalar.
 * 
 */
TEST(TestesMat4, TesteMultiplicacaoMatriz4x4PorEscalar) {
    mat4 mat4_A(1.0, 2.0, 3.0, 4.0,
                5.0, 6.0, 7.0, 8.0,
                9.0, 10.0, 11.0, 12.0,
                13.0, 14.0, 15.0, 16.0);

    mat4_A *= 2.0;

    mat4 esperado(2.0, 4.0, 6.0, 8.0,
                  10.0, 12.0, 14.0, 16.0,
                  18.0, 20.0, 22.0, 24.0,
                  26.0, 28.0, 30.0, 32.0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(mat4_A(i, j), esperado(i, j));
}   }   }


/**
 * @brief Teste da soma dos elementos da diagonal principal.
 * 
 */
TEST(TestesMat4, TesteSomaDiagonal4x4) {
    mat4 mat4_A(1.0, 2.0, 3.0, 4.0,
                5.0, 6.0, 7.0, 8.0,
                9.0, 10.0, 11.0, 12.0,
                13.0, 14.0, 15.0, 16.0);

    double resultado = mat4_A.trace();

    double esperado = 34.0;  // Soma dos elementos da diagonal principal

    EXPECT_EQ(resultado, esperado);
}


/**
 * @brief Teste de transposição da matriz.
 * 
 */
TEST(TestesMat4, TesteTransposicaoMatriz4x4) {
    mat4 mat4_A(1.0, 2.0, 3.0, 4.0,
                5.0, 6.0, 7.0, 8.0,
                9.0, 10.0, 11.0, 12.0,
                13.0, 14.0, 15.0, 16.0);

    mat4 resultado = transpose(mat4_A);

    mat4 esperado(1.0, 5.0, 9.0, 13.0,
                 2.0, 6.0, 10.0, 14.0,
                 3.0, 7.0, 11.0, 15.0,
                 4.0, 8.0, 12.0, 16.0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(resultado(i, j), esperado(i, j));
}   }   }
