#ifndef CAMERA_H
#define CAMERA_H
/**
 * @file camera.h
 * @brief This file contains a class to represent a camera for our ray-tracer.
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

#include "rtweekend.h"

#include "color.h"
#include "hittable.h"

#include <iostream>

/*
* @brief A class representing a camera.
* The camera class in the provided C++ code is used to simulate a camera in a 3D scene. 
* It has several member variables and functions that are used to calculate the color of each pixel 
* in the rendered image based on the objects in the scene and the position and orientation of the camera.
*/
class camera {
  public:
    double  aspect_ratio      = 1.0;  // Ratio of image width over height
    int     image_width       = 100;  // Rendered image width in pixel count
    int     samples_per_pixel = 10; // Count of random samples for each pixel


    // The render function is used to render the image. 
    // It first calls the initialize function to calculate the necessary variables. 
    // Then, it loops over each pixel in the image, calculates the color of the pixel based on the objects in the scene 
    // and the ray from the camera to the pixel, and writes the color to the standard output.
    void render(const hittable& world) 
    {
        initialize();

        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; ++j) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i)
            {
                color pixel_color(0, 0, 0);
                for (int sample = 0; sample < samples_per_pixel; ++sample)
                {
                    ray r = get_ray(i, j);
                    pixel_color += ray_color(r, world);
                }
                write_color(std::cout, pixel_color, samples_per_pixel);
            }
        }
        //std::clog << "\rDone.                 \n";
    }

  private:
    int    image_height;    // Rendered image height
    point3 center;          // Camera center
    point3 pixel00_loc;     // Location of pixel 0, 0
    vec3   pixel_delta_u;   // Offset to pixel to the right
    vec3   pixel_delta_v;   // Offset to pixel below
    
    void initialize() 
    {
        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;
        center = point3(0, 0, 0);
        // Determine viewport dimensions.
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        auto viewport_u = vec3(viewport_width, 0, 0);
        auto viewport_v = vec3(0, -viewport_height, 0);
        // Calculate the horizontal and vertical delta vectors from pixel to pixel.
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;
        // Calculate the location of the upper left pixel.
        auto viewport_upper_left =
            center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }

    // The ray_color function is used to calculate the color of a pixel based on a ray and the objects in the scene. 
    // It first checks if the ray hits any object in the scene. If it does, 
    // it returns a color based on the normal at the hit point. If it doesn't, it returns a color based on the direction of the ray.
    color ray_color(const ray& r, const hittable& world) const 
    {
        hit_record rec;

        if (world.hit(r, interval(0, infinity), rec))
        {
            return 0.5 * (rec.normal + color(1, 1, 1));
        }

        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
    }

    // generate a ray that originates from the camera and passes through a specific pixel in the image
    ray get_ray(int i, int j) const
    {
        // Get a randomly sampled camera ray for the pixel at location i,j.
        auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
        auto pixel_sample = pixel_center + pixel_sample_square();
        auto ray_origin = center;
        auto ray_direction = pixel_sample - ray_origin;
        return ray(ray_origin, ray_direction);
    }

    vec3 pixel_sample_square() const
    {
        // Returns a random point in the square surrounding a pixel at the origin. 
        auto px = -0.5 + random_double();
        auto py = -0.5 + random_double();
        return (px * pixel_delta_u) + (py * pixel_delta_v);
    }

};//end class camera


#endif
