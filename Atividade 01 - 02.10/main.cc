// Arquivo principal que usará a classe para salvar uma imagem

#include <iostream>
#include "MakeImage.h"

int main() {

    const int image_width = 256;
    const int image_height = 256;

    MakeImage myImage(image_width, image_height);

    myImage.drawGradient();
    myImage.saveImage("gradiente.png");

    myImage.drawRing();
    myImage.saveImage("anel.png");

    myImage.drawTriangle();
    myImage.saveImage("triangulo.png");
}