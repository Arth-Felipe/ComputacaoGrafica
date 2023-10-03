// Arquivo de cabeçalho que contém a declaração da classe e de seus membros

#ifndef MAKEIMAGE_H
#define MAKEIMAGE_H

#include <string>
#include <Magick++.h>

class MakeImage {
public:
    MakeImage(int image_width, int image_height);
    ~MakeImage();

    void drawGradient();
    void drawRing();
    void drawTriangle();
    bool saveImage(const std::string& nomeDoArquivo);

private:
    int image_width;
    int image_height;
    Magick::Image image;
};

#endif // MAKEIMAGE_H
