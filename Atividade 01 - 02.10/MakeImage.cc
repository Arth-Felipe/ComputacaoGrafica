// Arquivo de implementação que contém a definição dos métodos da classe

#include "MakeImage.h"
#include <iostream>

MakeImage::MakeImage(int image_width, int image_height) : image_width(image_width), image_height(image_height) {
    // Inicialize o ImageMagick aqui
    Magick::InitializeMagick(nullptr);

    // Inicialize a imagem com as dimensões especificadas e um fundo branco
    image = Magick::Image(Magick::Geometry(image_width, image_height), Magick::Color("white"));
}

MakeImage::~MakeImage() {
    // O destrutor pode ser usado para liberar recursos, se necessário
}

// Imagem Gradiente
void MakeImage::drawGradient() {

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            int red = 0;
            int green = j;
            int blue = 255 - j;

            std::cout << red << ' ' << green << ' ' << blue << '\n';
        }
    }
}

// Imagem Anel
void MakeImage::drawRing() {

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    const int centerX = image_width / 2;
    const int centerY = image_height / 2;
    const int outerRadius = 90;
    const int innerRadius = 60;

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            int dx = i - centerX;
            int dy = j - centerY;
            int distSquared = dx * dx + dy * dy;

            int red = 0;
            int green = 0;
            int blue = 0;

            if (distSquared <= outerRadius * outerRadius && distSquared >= innerRadius * innerRadius) {
                green = 255;
            }

            std::cout << red << ' ' << green << ' ' << blue << '\n';
        }
    }
}

// Imagem Triângulo
void MakeImage::drawTriangle() {

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Coordenadas dos vértices do triângulo
    int x1 = image_width / 2;
    int y1 = image_height / 4;

    int x2 = image_width / 4;
    int y2 = (3 * image_height) / 4;

    int x3 = (3 * image_width) / 4;
    int y3 = (3 * image_height) / 4;

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            int red = 0;
            int green = 0;
            int blue = 0;

            if (((i - x1) * (y2 - y1) - (j - y1) * (x2 - x1) >= 0) &&
                ((i - x2) * (y3 - y2) - (j - y2) * (x3 - x2) >= 0) &&
                ((i - x3) * (y1 - y3) - (j - y3) * (x1 - x3) >= 0)) {
                blue = 255;
            }

            std::cout << red << ' ' << green << ' ' << blue << '\n';
        }
    }
}

bool MakeImage::saveImage(const std::string& nomeDoArquivo) {
    try {
        image.write(nomeDoArquivo);
        std::cout << "Imagem salva como '" << nomeDoArquivo << "'." << std::endl;
        return true;
    } catch (Magick::Exception& e) {
        std::cerr << "Erro ao salvar a imagem: " << e.what() << std::endl;
        return false;
    }
}
