/**
 * @file rt1-chapter4.2.cpp
 * @brief This file contains the main entry point for a ray tracing program, based on the first book of the series.
 * ==============================================================================================
Extends previous 3.1 ray tracer program by generating an image by casting a ray through each pixel of the image,
calculating the color of the pixel based on the ray, and writing the color to the output stream.

This is a basic implementation of a ray tracing algorithm.

In this example we introduce the concept of a Viewport, which is a rectangle in 3D space that defines what part of the world
we want to render. The viewport is defined by its width and height, and it is positioned in front of the camera at a distance
of 1 unit along the z-axis.

The viewport_width and image_width represent different concepts in the context of a 3D rendering system like a ray tracer.
- image_width is the width of the final image in pixels. It's an integer value that determines how many horizontal pixels
the final image will have.
- On the other hand, viewport_width is the width of the viewport in the 3D world space.
It's a floating-point value that represents a distance in the 3D world.

The viewport is like a window through which the 3D scene is viewed.
It's not necessarily related to the pixel dimensions of the final image.

The relationship between the viewport width and the image width is used to calculate the size of a pixel in the world space.
This is important for determining the direction of the rays that are cast through each pixel.
In the provided code, the viewport_width is calculated based on the image_width, the image_height,
and the aspect ratio of the viewport.
This ensures that the aspect ratio of the final image matches the aspect ratio of the viewport.
 * ==============================================================================================
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
#include "ray.h"
#include <iostream>

/*


*/

/**
 * Calculates the color of a ray.
 *
 * @param r The ray for which to calculate the color.
 * @return The calculated color.
 */
color ray_color(const ray &r)
{
    /*
    calculates the unit direction of a vector and then computes a value based on the y-component
    of that unit direction.
    */
    vec3 unit_direction = unit_vector(r.direction());

    // The unit_direction.y() part is calling a method on the unit_direction object to get its y-component.
    // This value is then added to 1.0, and the result is halved by multiplying it by 0.5.
    // The result is stored in the variable a.
    auto a = 0.5 * (unit_direction.y() + 1.0);

    // this line of code is performing a linear interpolation between white and light blue based on the value of a.
    // When a is 0, the result is white; when a is 1, the result is light blue;
    // and when a is between 0 and 1, the result is a blend of white and light blue.
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main()
{
    // Image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 600;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
    auto camera_center = point3(0, 0, 0);

    std::clog << "Image width: " << image_width << "\nImage height: " << image_height << "\n";
    std::clog << "Viewport width: " << viewport_width << "\nViewport height: " << viewport_height << "\n";

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the position of the upper left corner of a viewport
    // and the location of the center of the pixel at the (0,0) position in a 3D space.
    // It starts from the camera_center, moves backwards along the z-axis by
    // focal_length units (since vec3(0, 0, focal_length) represents a vector pointing along the z-axis),
    // and then moves half the viewport's width and height in the negative u and v directions.
    // The result is stored in the viewport_upper_left variable.
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;

    // This line calculates the location of the center of the pixel at the (0,0) position.
    //  It starts from the viewport_upper_left position, and then moves half the width and
    //  height of a pixel in the positive u and v directions. The result is stored in the pixel00_loc variable.
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render the ra-traced image
    std::cout << "P3\n"
              << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) // y coordinates
    {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush; // number of scanlines remaining
        for (int i = 0; i < image_width; ++i) // x coordinates
        {
            // calculates the location of the center of the current pixel in the viewport. 
            // It starts from the location of the center of the pixel at the (0,0) position (pixel00_loc), 
            // and then moves i times the width of a pixel in the u direction and j times the height of a pixel in the v direction.
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);

            // This line calculates the direction of the ray that will be cast through the current pixel. 
            // It subtracts the position of the camera from the position of the pixel center, 
            // resulting in a vector that points from the camera to the pixel center.
            auto ray_direction = pixel_center - camera_center;
            
            // creates a ray object with the camera center as the origin and the calculated direction.
            ray r(camera_center, ray_direction);
            
            // calculates the color of the pixel based on the direction of the ray
            color pixel_color = ray_color(r);
            
            // writes the color to the output stream in a format suitable for an image file.
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone. \n";

    return 0;
}
