/**
 * @file Atv3-Tests.cc
 * @author Arthur Felipe Bravo Pita
 * @brief Arquivo com a definição dos devidos testes da Atividade 3
 * @version 1.0
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include "../headers/processObject.h"


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //


/**
 * @brief Teste de carregamento de arquivo OBJ e preenchimento das estruturas de dados.
 * 
 */
TEST(ProcessObjectTests, TestLoadFileOBJ) {

    processObject instancia;
    bool success = instancia.loadFileOBJ("/mnt/c/Users/Archie/Desktop/ComputacaoGrafica/Atividade 03 - 16.10/tests/example-sword.obj");

    ASSERT_TRUE(success);

    EXPECT_FALSE(instancia.vertexClass.empty());
    EXPECT_FALSE(instancia.textureCoordClass.empty());
    EXPECT_FALSE(instancia.normalClass.empty());
    EXPECT_FALSE(instancia.faceClass.empty());
}


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //


/**
 * @brief Teste de leitura de vértices.
 * 
 */
TEST(ProcessObjectTests, TestVertices) {

    processObject instancia;
    instancia.loadFileOBJ("/mnt/c/Users/Archie/Desktop/ComputacaoGrafica/Atividade 03 - 16.10/tests/example-sword.obj");

    ASSERT_GT(instancia.vertexClass.size(), 0);

    // Verificação de uma coordenada x de vértice
    ASSERT_FLOAT_EQ(instancia.vertexClass[0].x, 0.53338897f);
}


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //


/**
 * @brief Teste de leitura de coordenadas de textura.
 * 
 */
TEST(ProcessObjectTests, TestTextureCoordinates) {

    processObject instancia;
    instancia.loadFileOBJ("/mnt/c/Users/Archie/Desktop/ComputacaoGrafica/Atividade 03 - 16.10/tests/example-sword.obj");

    ASSERT_GT(instancia.textureCoordClass.size(), 0);

    // Verificação de uma coordenada u de conjunto de coordenadas de textura
    ASSERT_FLOAT_EQ(instancia.textureCoordClass[0].u, 0.27559999f);
}


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //


/**
 * @brief Teste de leitura de normais.
 * 
 */
TEST(ProcessObjectTests, TestNormals) {

    processObject instancia;
    instancia.loadFileOBJ("/mnt/c/Users/Archie/Desktop/ComputacaoGrafica/Atividade 03 - 16.10/tests/example-sword.obj");

    ASSERT_GT(instancia.normalClass.size(), 0);

    // Verificação de uma coordenada x de normal
    ASSERT_FLOAT_EQ(instancia.normalClass[0].x, -0.44369999f);
}


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //


/**
 * @brief Teste de leitura de faces.
 * 
 */
TEST(ProcessObjectTests, TestFaces) {

    processObject instancia;
    instancia.loadFileOBJ("/mnt/c/Users/Archie/Desktop/ComputacaoGrafica/Atividade 03 - 16.10/tests/example-sword.obj");

    ASSERT_GT(instancia.faceClass.size(), 0);

    // Verificação de um índice de vértice em face
    ASSERT_GT(instancia.faceClass[0].vertexIndex, 0);
}


// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- //
