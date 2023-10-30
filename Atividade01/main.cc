/**
 * @file main.cc
 * @author Arthur Felipe Bravo Pita
 * @brief Programa principal que usará a instanciação de um objeto da classe "MakeImage" e seus métodos para salvar uma imagem
 * @version 1.0
 * @date 2023-10-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "MakeImage.h"

int main() {

    // Instanciação de um objeto da classe "MakeImage"
    MakeImage myImage = MakeImage();

    // Geração dos arquivos .ppm através dos métodos específicos de cada imagem (um degradê, um anel e um triângulo)
    myImage.drawGradient();
    myImage.drawRing();
    myImage.drawTriangle();

    // Conversão dos arquivos .ppm gerados em imagens .png
    myImage.saveImage("result-gradiente.png");
    myImage.saveImage("result-anel.png");
    myImage.saveImage("result-triangulo.png");

    return 0;
}