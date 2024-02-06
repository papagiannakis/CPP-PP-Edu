/**
 * @file ray.h
 * @brief This file contains a class to represent a ray in 3D space.
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

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
  public:
    /**
     * @brief Represents a ray in 3D space.
     */
    ray() {}

    /**
     * @brief Constructs a ray with the given origin and direction.
     * @param origin The origin point of the ray.
     * @param direction The direction vector of the ray.
     */
    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    /**
     * @brief Returns the origin point of the ray.
     * @return The origin point of the ray.
     */
    point3 origin() const  { return orig; }

    /**
     * @brief Returns the direction vector of the ray.
     * @return The direction vector of the ray.
     */
    vec3 direction() const { return dir; }

    /**
     * @brief Returns the point on the ray at the given parameter value.
     * @param t The parameter value.
     * @return The point on the ray at the given parameter value.
     */
    point3 at(double t) const {
        return orig + t*dir;
    }

  private:
    point3 orig; // The origin point of the ray.
    vec3 dir; // The direction vector of the ray.
};

#endif