#include <iostream>

int main() {

    // Image

    const int image_width = 256;
    const int image_height = 256;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

    // Render (Degradê)

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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

    // Render (Rosquinha)

    const int centerX = image_width / 2;
    const int centerY = image_height / 2;
    const int outerRadius = 90;
    const int innerRadius = 60;

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {

        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i) {
            int dx = i - centerX;
            int dy = j - centerY;
            int distSquared = dx * dx + dy * dy;

            int red = 0;
            int green = 0;
            int blue = 0;

            if (distSquared <= outerRadius * outerRadius && distSquared >= innerRadius * innerRadius) {
                red = 255;
                green = 0;
                blue = 0;
            }

            std::cout << red << ' ' << green << ' ' << blue << '\n';
        }
    }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

    std::clog << "\rDone.                 \n";

}