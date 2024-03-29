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
    myImage.drawGradient("result-gradiente.ppm");
    myImage.drawRing("result-anel.ppm");
    myImage.drawTriangle("result-triangulo.ppm");

    // Conversão dos arquivos .ppm gerados em imagens .png
    myImage.saveImage("result-gradiente.ppm");
    myImage.saveImage("result-anel.ppm");
    myImage.saveImage("result-triangulo.ppm");

    return 0;
}