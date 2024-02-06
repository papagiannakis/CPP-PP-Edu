#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
/**
 * @file hittable_list.h
 * @brief This file contains a class to represent a list of Hittable objects (intersected by rays).
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

#include <memory>
#include <vector>


/**
 * @brief A class representing a list of hittable objects.
 * 
 * This class inherits from the hittable class and provides functionality to store and manage a collection of hittable objects.
 */
class hittable_list : public hittable {
  public:
    std::vector<shared_ptr<hittable>> objects; /**< The list of hittable objects. */

    /**
     * @brief Default constructor for hittable_list.
     */
    hittable_list() {}

    /**
     * @brief Constructor for hittable_list that adds an object to the list.
     * 
     * @param object The hittable object to add to the list.
     */
    hittable_list(shared_ptr<hittable> object) { add(object); }

    /**
     * @brief Clears the list of hittable objects.
     */
    void clear() { objects.clear(); }

    /**
     * @brief Adds a hittable object to the list.
     * 
     * @param object The hittable object to add.
     */
    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    /**
     * @brief Determines if a ray intersects with any of the hittable objects in the list.
     * 
     * @param r The ray to test for intersection.
     * @param ray_t The interval of valid ray parameter values.
     * @param rec The hit record to store the intersection information.
     * @return True if the ray intersects with any of the hittable objects, false otherwise.
     */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        hit_record temp_rec;
        auto hit_anything = false;
        auto closest_so_far = ray_t.max;

        for (const auto& object : objects) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};


#endif
