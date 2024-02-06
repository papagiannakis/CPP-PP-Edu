/**
 * @file rt1-chapter3.1.cpp
 * @brief This file contains the main entry point for a ray tracing program, based on the first book of the series.
* ==============================================================================================
 * 
 * Extends previous Chapter2.3 and generates a simple image using ray tracing techniques.
 * It uses the color.h and vec3.h header files to define the color and vector classes.
 * It initializes the image width and height, and then renders the image
 * by iterating over each pixel and calculating its color. The resulting
 * image is written to the standard output.
 * 
 * So, in simple terms, this code is generating an image by calculating 
 * and outputting the color of each pixel. 
 * The color is determined by the pixel's position, 
 * with the top left pixel being black (0,0,0) 
 * and the bottom right pixel being yellow (1,1,0).
 * 
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

#include "vec3.h"
#include "color.h"
#include <iostream>


int main() 
{
    // Image
    int image_width = 256; 
    int image_height = 256;
    
    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n"; 

    for (int j = 0; j < image_height; ++j) 
    {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush; 
        for (int i = 0; i < image_width; ++i) 
        {
            // This line calculates the color of the current pixel. It creates a color object 
            // (presumably a three-component vector representing red, green, and blue) 
            // with each component normalized to the range [0,1]. 
            // The x and y components are determined by the pixel's position in the image, while the z component is set to 0.
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0); 
            write_color(std::cout, pixel_color);
        } 
    }
    std::clog << "\rDone. \n";

    return 0;
}
