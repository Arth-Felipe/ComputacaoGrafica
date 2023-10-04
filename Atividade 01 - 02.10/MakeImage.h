// Arquivo de cabeçalho que contém a declaração da classe e de seus membros

#ifndef MAKEIMAGE_H
#define MAKEIMAGE_H

#include <string>

class MakeImage {
public:
    void drawGradient();
    void drawRing();
    void drawTriangle();
    bool saveImage(const std::string& nomeDoArquivo);

private:
    int image_width = 256;
    int image_height = 256;
};

#endif // MAKEIMAGE_H
