// Arquivo principal que usará a classe para salvar uma imagem

#include <iostream>
#include "MakeImage.h"

int main() {

    MakeImage myImage = MakeImage();

    myImage.drawGradient();
    myImage.saveImage("result-gradiente.png");

    myImage.drawRing();
    myImage.saveImage("result-anel.png");

    myImage.drawTriangle();
    myImage.saveImage("result-triangulo.png");

    return 0;
}