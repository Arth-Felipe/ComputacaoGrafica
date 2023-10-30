/**
 * @file main.cc
 * @author Peter Shirley, Trevor David Black, Steve Hollasch
 * @brief Now we can change our main to use both of these. Final code for the first PPM image
 * @version 1.0
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../headers/color.h"
#include "../headers/vec2.h"
#include "../headers/vec3.h"
#include "../headers/vec4.h"
#include "../headers/mat2.h"
#include "../headers/mat3.h"
#include "../headers/mat4.h"

#include <iostream>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}
