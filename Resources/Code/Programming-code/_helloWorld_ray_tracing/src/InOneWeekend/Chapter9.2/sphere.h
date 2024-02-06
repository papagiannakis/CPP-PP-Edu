#ifndef SPHERE_H
#define SPHERE_H
/**
 * @file sphere.h
 * @brief This file contains a class to represent a Sphere as a Hittable.
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

#include "hittable.h"


/**
 * @brief Represents a sphere object in a ray tracing scene.
 */
class sphere : public hittable {
  public:
    /**
     * @brief Constructs a sphere with the given center, radius, and material.
     * @param _center The center point of the sphere.
     * @param _radius The radius of the sphere.
     */
    sphere(point3 _center, double _radius)
      : center(_center), radius(_radius) {}

    /**
     * @brief Determines if a ray intersects with the sphere and calculates the hit record.
     * @param r The ray to test for intersection.
     * @param ray_t The interval of valid ray parameter values.
     * @param rec The hit record to store the intersection information.
     * @return True if the ray intersects with the sphere, false otherwise.
     */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0)
            return false;

        // Find the nearest root that lies in the acceptable range.
        auto sqrtd = sqrt(discriminant);
        auto root = (-half_b - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (-half_b + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }

  private:
    point3 center;
    double radius;
};


#endif
