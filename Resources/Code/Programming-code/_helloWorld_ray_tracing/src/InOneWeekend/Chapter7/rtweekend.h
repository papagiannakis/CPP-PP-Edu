#ifndef RTWEEKEND_H
#define RTWEEKEND_H
/**
 * @file rtweekend.h
 * @brief This file contains utility functions and constants.
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

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers
#include "interval.h"
#include "ray.h"
#include "vec3.h"


#endif
