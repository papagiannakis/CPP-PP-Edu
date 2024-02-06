/**
 * @file color.h
 * @brief This file contains the main entry point for a ray tracing program, based on the first book of the series.
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

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;

void write_color(std::ostream &out, color pixel_color) 
{
   // Write the translated [0,255] value of each color component. 
   out  << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' ' 
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
  
}


#endif