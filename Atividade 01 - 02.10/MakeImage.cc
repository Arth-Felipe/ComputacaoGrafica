/**
 * @file MakeImage.cc
 * @author Arthur Felipe Bravo Pita
 * @brief Arquivo de implementação contendo a definição e desenvolvimento dos métodos da classe
 * @version 1.0
 * @date 2023-10-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "MakeImage.h"
#include <iostream>
#include <fstream>
#include <Magick++.h>

//-------------------------------------------------------------------------------------------------------------//

/**
 * @brief Esta função gera um arquivo .ppm de uma imagem gradiente do azul para o verde
 * 
 */
void MakeImage::drawGradient() {

    std::ofstream file("result-gradiente.ppm");
    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            int red = 0;
            int green = j;
            int blue = 255 - j;

            file << red << ' ' << green << ' ' << blue << '\n';
        }
    }
    file.close();
    std::cout << "Geração do arquivo 'result-gradiente.ppm' bem-sucedida!" << std::endl;
}

//-------------------------------------------------------------------------------------------------------------//

/**
 * @brief Esta função gera um arquivo .ppm de uma imagem de um anel (ou rosquinha) verde num fundo preto
 * 
 */
void MakeImage::drawRing() {

    std::ofstream file("result-anel.ppm");
    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Constantes para a criação dos dois círculos que irão compor o anel (um externo e um interno)
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

            file << red << ' ' << green << ' ' << blue << '\n';
        }
    }
    file.close();
    std::cout << "Geração do arquivo 'result-anel.ppm' bem-sucedida!" << std::endl;
}

//-------------------------------------------------------------------------------------------------------------//

/**
 * @brief Esta função gera um arquivo .ppm de uma imagem de um triângulo equilátero azul num fundo preto
 * 
 */
void MakeImage::drawTriangle() {

    std::ofstream file("result-triangulo.ppm");
    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

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

            file << red << ' ' << green << ' ' << blue << '\n';
        }
    }
    file.close();
    std::cout << "Geração do arquivo 'result-triangulo.ppm' bem-sucedida!" << std::endl;
}

//-------------------------------------------------------------------------------------------------------------//

/**
 * @brief Esta função inicializa o uso da biblioteca ImageMagick e, através de uma de suas funções próprias, converte os arquivos .ppm gerados pelas funções anteriores em imagens .png
 * 
 * @param nomeDoArquivo Representa o nome do arquivo de imagem .png que será gerada a partir dos .ppm
 * @return true Significa que a criação e escrita da imagem foram bem-sucedidas
 * @return false Significa que houve uma falha no processo de salvar a imagem a partir do .ppm
 */
bool MakeImage::saveImage(const std::string& nomeDoArquivo) {

    // Inicialização do ImageMagick
    Magick::InitializeMagick(nullptr);

    std::string oldFormat = "x";

    if (nomeDoArquivo[7] == 'g')
        oldFormat = "result-gradiente.ppm";

    else if (nomeDoArquivo[7] == 'a')
        oldFormat = "result-anel.ppm";

    else // (nomeDoArquivo[7] == 't')
        oldFormat = "result-triangulo.ppm";

    Magick::Image image(oldFormat);

    try {
        image.write(nomeDoArquivo);
        std::cout << "Imagem salva como '" << nomeDoArquivo << "'." << std::endl;
        return true;

    } catch (Magick::Exception& e) {
        std::cerr << "Erro ao salvar a imagem: " << e.what() << std::endl;
        return false;
    }
}
