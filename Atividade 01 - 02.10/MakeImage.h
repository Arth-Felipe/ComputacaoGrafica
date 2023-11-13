/**
 * @brief Arquivo de cabeçalho contendo a declaração da classe "MakeImage" e de seus membros
 * 
 */

#ifndef MAKEIMAGE_H
#define MAKEIMAGE_H

#include <string>

class MakeImage {
public:

    MakeImage();
    MakeImage(const int, const int);

    void drawGradient(std::string nomeDoArquivo);
    void drawRing(std::string nomeDoArquivo);
    void drawTriangle(std::string nomeDoArquivo);
    bool saveImage(const std::string& nomeDoArquivo);

private:

    // Definição do tamanho da imagem a ser gerada
    int image_width = 256;
    int image_height = 256;
};

#endif // MAKEIMAGE_H
