#include <iostream>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

    // Render (Degradê)
/*
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {

        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i) {

            int red = 0;
            int green = j;
            int blue = 255 - j;

            std::cout << red << ' ' << green << ' ' << blue << '\n';
        }
    }
    std::clog << "\rDone.                 \n";
*/
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

    // Render (Círculo)

    int centerX = image_width / 2;
    int centerY = image_height / 2;
    int radius = 100;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            int dx = i - centerX;
            int dy = j - centerY;
            int distanceSquared = dx * dx + dy * dy;

            if (distanceSquared <= radius * radius) {
                int red = 255;
                int green = 0;
                int blue = 0;

                std::cout << red << " " << green << " " << blue << " ";

            } else {
                int red = 0;
                int green = 0;
                int blue = 0;

                std::cout << red << " " << green << " " << blue << " ";
            }
        }
        std::cout << "\n";
    }

    std::clog << "\rDone.                 \n";

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

}