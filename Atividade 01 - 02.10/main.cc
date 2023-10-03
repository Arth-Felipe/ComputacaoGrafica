#include <iostream>

int main() {

    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

    // Imagem Degradê

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            int red = 0;
            int green = j;
            int blue = 255 - j;

            std::cout << red << ' ' << green << ' ' << blue << '\n';
        }
    }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

    // Imagem Rosquinha

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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

    // Imagem Triângulo

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