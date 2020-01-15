
#pragma once

#include <fstream>
#include <string>
#include <iostream>

#include "./../math/vector.h"

//
// Inspired by:
// https://www.scratchapixel.com/code.php?id=8&origin=/lessons/3d-basic-rendering/ray-tracing-overview
//

namespace foundation {

inline double clamp(const double &lo, const double &hi, const double &v)
{ 
    return std::max(lo, std::min(hi, v)); 
} 

void save_image_ppm(
    Vector3d *frame_buffer,
    const int frame_width,
    const int frame_height)
{

    // Open output file.
    std::ofstream file;
    file.open("./../../../../sandbox/output/out.ppm"); 

    // Header.
    // PPM version, frame width, frame height, max value.
    file << "P6\n" << frame_width << " " << frame_height << "\n255\n";

    for (size_t i = 0; i < frame_width * frame_height; ++i) 
    {
        char r = (char)(255 * clamp(0, 1, frame_buffer[i].x));
        char g = (char)(255 * clamp(0, 1, frame_buffer[i].y));
        char b = (char)(255 * clamp(0, 1, frame_buffer[i].z));
        file << r << g << b;
    } 

    file.close();
}

} // namespace foundation