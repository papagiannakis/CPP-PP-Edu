#ifndef HITTABLE_H
#define HITTABLE_H
/**
 * @file hittable.h
 * @brief This file contains a class to represent Hittable objects (intersected by rays).
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

/**
 * @brief The hit_record class represents a record of a ray hit.
 *  It contains the hit point, the normal vector at the hit point, the ray parameter value at the hit point, 
 *  and a flag indicating if the ray hit the front face of the object.
 * 
*/
class hit_record
{
public:
  point3 p;
  vec3 normal;

  double t;
  bool front_face;

  // Sets the hit record normal vector based on the given ray and outward normal.
  // The outward_normal parameter is assumed to have unit length.
  // Parameters:
  // - r: The ray used for computing the normal vector.
  // - outward_normal: The outward normal vector.
  void set_face_normal(const ray &r, const vec3 &outward_normal)
  {
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

/**
 * @brief The hittable class represents an abstract base class for objects that can be hit by a ray.
 */
class hittable {
  public:
    /**
     * @brief Destructor for the hittable class.
     */
    virtual ~hittable() = default;

    /**
     * @brief Determines if a ray hits the object and records the hit information in the hit_record parameter.
     * 
     * @param r The ray to be tested for intersection.
     * @param ray_t The interval of valid ray parameter values.
     * @param rec The hit_record object to store the hit information.
     * @return true if the ray hits the object, false otherwise.
     */
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};


#endif
