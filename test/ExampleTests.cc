#include <gtest/gtest.h>

// #include "color.h"
// #include "vec2.h"
// #include "vec3.h"
// #include "vec4.h"
// #include "mat2.h"
#include "mat3.h"
#include "mat4.h"


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //

TEST(ExampleTests, TesteVec2) {}

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //

TEST(ExampleTests, TesteVec3) {}

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //

TEST(ExampleTests, TesteVec4) {}

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //

TEST(ExampleTests, TesteMat2) {}

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //

TEST(ExampleTests, TesteMat3) {}

// Teste a criação de uma matriz mat3 com números diferentes
TEST(Mat3Tests, TesteCriacaoMatriz) {
    mat3 matriz(1.0, 2.0, 3.0,
                4.0, 5.0, 6.0,
                7.0, 8.0, 9.0);

    EXPECT_EQ(matriz(0, 0), 1.0);
    EXPECT_EQ(matriz(1, 1), 5.0);
    EXPECT_EQ(matriz(2, 2), 9.0);
}

// Teste a multiplicação de matriz por matriz com números diferentes
TEST(Mat3Tests, TesteMultiplicacaoMatrizPorMatriz) {
    mat3 matrizA(1.0, 2.0, 3.0,
                 4.0, 5.0, 6.0,
                 7.0, 8.0, 9.0);
    mat3 matrizB(9.0, 8.0, 7.0,
                 6.0, 5.0, 4.0,
                 3.0, 2.0, 1.0);
    mat3 resultado = matrizA * matrizB;

    mat3 esperado(30.0, 24.0, 18.0, 84.0, 69.0, 54.0, 138.0, 114.0, 90.0);

    EXPECT_EQ(resultado, esperado);
}

// Teste a multiplicação de matriz por vetor com números diferentes
TEST(Mat3Tests, TesteMultiplicacaoMatrizPorVetor) {
    mat3 matriz(1.0, 2.0, 3.0,
                4.0, 5.0, 6.0,
                7.0, 8.0, 9.0);
    vec3 vetor(1.0, 2.0, 3.0);
    vec3 resultado = matriz * vetor;

    vec3 esperado(14.0, 32.0, 50.0);

    EXPECT_EQ(resultado, esperado);
}

// Teste o cálculo do determinante com números diferentes
TEST(Mat3Tests, TesteDeterminante) {
    mat3 matriz(1.0, 2.0, 3.0,
                4.0, 5.0, 6.0,
                7.0, 8.0, 9.0);
    double determinante = matriz.determinant();

    double esperado = 0.0;

    EXPECT_EQ(determinante, esperado);
}

// Teste a matriz de identidade com números diferentes
TEST(Mat3Tests, TesteMatrizIdentidade) {
    mat3 identidade = identity3();
    mat3 matriz(1.0, 2.0, 3.0,
                4.0, 5.0, 6.0,
                7.0, 8.0, 9.0);

    EXPECT_EQ(identidade, matriz);
}

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //

TEST(ExampleTests, TesteMat4) {

    // Criando duas instâncias da classe mat4
    mat4 mat4_A(1.0, 2.0, 3.0, 4.0,
                5.0, 6.0, 7.0, 8.0,
                9.0, 10.0, 11.0, 12.0,
                13.0, 14.0, 15.0, 16.0);

    mat4 mat4_B(2.0, 0.0, 0.0, 0.0,
                0.0, 2.0, 0.0, 0.0,
                0.0, 0.0, 2.0, 0.0,
                0.0, 0.0, 0.0, 2.0);

    // Usando um método membro da classe, por exemplo, a função determinant()
    double det = mat4_A.determinant();

    // Usando um método definido fora da classe com inline, por exemplo, a função operator* (multiplicação de matrizes)
    mat4 resultado = mat4_A * mat4_B;


    mat4_A *= 2.0;
    mat4_B = 2.0 * mat4_A;

    EXPECT_EQ(false, true);

}

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //
