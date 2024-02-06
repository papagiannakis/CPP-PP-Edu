/**
 * @file rt1-chapter2.3.cpp
 * @brief This file contains the main entry point for a ray tracing program, based on the first book of the series.
* ==============================================================================================
Same as previous 2.2 but also adds a progress indicator output to the console.

Initially a 3x3 PPM image is created, but it is not visible unless you zoom 128000%.

black (0,0,0)           -   burgundy red (127,0,0)      -   red (255,0,0)
light green (0,127,0)   - olive green (127, 127,0)      - orange (255,127,0)
green (0,255,0)         - green (127,255,0)             - yellow (255, 255, 0)

* Originally written in 2016 by Peter Shirley 
* You can find it at the regular spot: https://raytracing.github.io
* To the extent possible under law, the author(s) have dedicated all copyright and related and
* neighboring rights to this software to the public domain worldwide. This software is
* distributed without any warranty.
*
* You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication
* along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
* ==============================================================================================
 *
 * @author Dr. George Papagiannakis
 * @date 2024
 */

#include <iostream>

int main() 
{
    // Image
    int image_width = 3; 
    int image_height = 3;
    
    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; ++j) 
    { 
        // number of scanline remaining to be processed
        // It uses the carriage return character (\r) to overwrite the previous output, 
        // so that the progress is displayed on a single line
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush<<std::endl;
        for (int i = 0; i < image_width; ++i)
        {
            auto r = double(i) / (image_width-1); 
            auto g = double(j) / (image_height-1); 
            auto b = 0;
            int ir = static_cast<int>(255.999 * r); 
            int ig = static_cast<int>(255.999 * g); 
            int ib = static_cast<int>(255.999 * b);
            
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return 0;
}
