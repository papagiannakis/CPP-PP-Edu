/**
 * @file rt1-chapter5.2.cpp
 * @brief This file contains the main entry point for a ray tracing program, based on the first book of the series.
 * ==============================================================================================
 * Extends previous 4.1 ray tracer program by placing a small sphere at −1 on the z-axis 
 * and then coloring red any pixel that intersects it.
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


/**
 * Checks if a ray intersects with a sphere.
 *
 * @param center The center point of the sphere.
 * @param radius The radius of the sphere.
 * @param r The ray to check for intersection.
 * @return True if the ray intersects with the sphere, false otherwise.
 */
bool hit_sphere(const point3 &center, double radius, const ray &r)
{
    // calculates the vector from the sphere's center to the origin of the ray. 
    // This is done by subtracting the center of the sphere from the origin of the ray.
    vec3 oc = r.origin() - center;
    
    // This line calculates the dot product of the ray's direction with itself. 
    // This is equivalent to the square of the length of the direction vector, 
    // which is always 1 for a normalized direction vector.
    auto a = dot(r.direction(), r.direction());
    
    // This line calculates twice the dot product of the vector oc and the ray's direction. 
    // This is part of the quadratic equation used to find the intersection points of the ray and the sphere.
    auto b = 2.0 * dot(oc, r.direction());
    
    // This line calculates the dot product of the vector oc with itself, which is the square of the length of oc, 
    // and subtracts the square of the sphere's radius. This is also part of the quadratic equation.
    auto c = dot(oc, oc) - radius * radius;
    
    // This line calculates the discriminant of the quadratic equation. 
    // The discriminant is used to determine the number of solutions to the equation.
    auto discriminant = b * b - 4 * a * c;
    
    // This line returns a boolean value indicating whether the discriminant is greater than or equal to zero. 
    // If the discriminant is negative, the quadratic equation has no real solutions, 
    // which means the ray does not intersect the sphere. 
    // If the discriminant is zero or positive, the equation has one or two real solutions, 
    // which means the ray intersects the sphere at one or two points.
    return (discriminant >= 0);
}

/**
 * Calculates the color of a ray.
 *
 * @param r The ray for which to calculate the color.
 * @return The calculated color.
 */
color ray_color(const ray &r)
{
    // This line calls the hit_sphere function with a sphere centered at (0, 0, -1), a radius of 0.5, and a ray r. 
    // The hit_sphere function checks if the ray intersects the sphere and returns true if it does and false otherwise.
    // If the hit_sphere function returns true, it returns a color object representing the color red. 
    // The color class is a custom type that represents a color in RGB format. 
    // The constructor color() initializes a color with the given red, green, and blue components. 
    // In this case, the color is fully red, as indicated by the arguments (1, 0, 0).
    if (hit_sphere(point3(0, 0, -1), 0.5, r))
        return color(1, 0, 0); // red

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
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
