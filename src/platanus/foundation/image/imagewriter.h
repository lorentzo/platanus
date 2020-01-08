
#include <fstream>
#include <string>
#include <iostream>

#include "./../math/vector.h"

//
// Inspired by:
// https://raytracing.github.io/books/RayTracingInOneWeekend.html
//

struct Sample
{
    char r,g,b;
};

void save_image_ppm(
    Vector3d **frame_buffer,
    const int frame_width,
    const int frame_height)
{

    // Open output file.
    std::ofstream file("out.ppm", std::ios::binary);

    // Header.
    std::string frame_width_str = std::to_string(frame_width);
    std::string frame_height_str = std::to_string(frame_height);
    file.write("P6 ", 3); // version + whitespace (3B)
    file.write(frame_width_str.c_str(), 4);
    file.write(" ", 1);
    file.write(frame_height_str.c_str(), 4);
    file.write(" ", 1);
    file.write("255 ", 5); // max value, (4B)

    // Values.
    for (size_t j = 0; j < frame_height; ++j)
    {
        for(size_t i = 0; i < frame_width; ++i)
        {
            Sample s;
            s.r = frame_buffer[i][j].x;
            s.g = frame_buffer[i][j].y;
            s.b = frame_buffer[i][j].z;
            file.write(reinterpret_cast<char*>(&s), sizeof(Sample));
        }
    }
    file.close();
}