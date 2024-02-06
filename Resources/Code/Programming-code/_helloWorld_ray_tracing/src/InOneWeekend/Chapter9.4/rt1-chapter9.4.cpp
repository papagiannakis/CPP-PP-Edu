/**
 * @file rt1-chapter9.4.cpp
 * @brief This file contains the main entry point for a ray tracing program, based on the first book of the series.
 * ==============================================================================================
 * Extends previous 9.3 ray tracer program by 
 * - adding true lambertian reflection to the sphere that will be ray-traced, to simulate light bounces
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

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"

#include <iostream>

/**
 * It sets up the scene, camera, and renders the image.
 */
int main()
{
    hittable_list world;

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
    
    camera cam;
    
    cam.aspect_ratio        = 16.0 / 9.0;
    cam.image_width         = 400;
    cam.samples_per_pixel   = 100;
    cam.max_depth           = 50;
    
    cam.render(world);
    
    //std::clog << "\rDone. \n";
}