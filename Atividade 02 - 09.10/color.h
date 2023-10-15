/**
 * @file color.h
 * @author Peter Shirley, Trevor David Black, Steve Hollasch
 * @brief Using our new vec3 class, we'll create a new color.h header file and define a utility function that writes a single pixel's color out to the standard output stream
 * @version 1.0
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif
