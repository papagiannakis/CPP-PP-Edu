/**
 * @file vec3.h
 * @brief This file contains a class to represent a 3D vector.
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

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

/**
 * @brief A class representing a 3D vector.
 */
class vec3 {
  public:
    double e[3];

    /**
     * @brief Default constructor. Initializes all elements to 0.
     */
    vec3() : e{0,0,0} {}

    /**
     * @brief Constructor that initializes the vector with the given values.
     * @param e0 The value for the first element.
     * @param e1 The value for the second element.
     * @param e2 The value for the third element.
     */
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    /**
     * @brief Get the x-coordinate of the vector.
     * @return The x-coordinate.
     */
    double x() const { return e[0]; }

    /**
     * @brief Get the y-coordinate of the vector.
     * @return The y-coordinate.
     */
    double y() const { return e[1]; }

    /**
     * @brief Get the z-coordinate of the vector.
     * @return The z-coordinate.
     */
    double z() const { return e[2]; }

    /**
     * @brief Negate the vector.
     * @return The negated vector.
     */
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    /**
     * @brief Get the element at the specified index.
     * @param i The index of the element.
     * @return The element at the specified index.
     */
    double operator[](int i) const { return e[i]; }

    /**
     * @brief Get a reference to the element at the specified index.
     * @param i The index of the element.
     * @return A reference to the element at the specified index.
     */
    double& operator[](int i) { return e[i]; }

    /**
     * @brief Add a vector to this vector.
     * @param v The vector to add.
     * @return A reference to this vector after the addition.
     */
    vec3& operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    /**
     * @brief Multiply this vector by a scalar.
     * @param t The scalar to multiply by.
     * @return A reference to this vector after the multiplication.
     */
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    /**
     * @brief Divide this vector by a scalar.
     * @param t The scalar to divide by.
     * @return A reference to this vector after the division.
     */
    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    /**
     * @brief Get the length of the vector.
     * @return The length of the vector.
     */
    double length() const {
        return sqrt(length_squared());
    }

    /**
     * @brief Get the squared length of the vector.  It's used instead of the length function 
     * to avoid the square root operation, which is computationally expensive. 
     * The square of the length of a vector is the sum of the squares of its components. 
     * For example, if the vector is (x, y, z), the square of its length is x^2 + y^2 + z^2.
     * @return The squared length of the vector.
     */
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    static vec3 random() {
        return vec3(random_double(), random_double(), random_double());
    }

    static vec3 random(double min, double max) {
        return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
    }
}; //end of class vec3

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;


// Vector Utility Functions

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

//generates a random 3-dimensional vector, or point, that lies within a unit sphere centered at the origin.
inline vec3 random_in_unit_sphere() {
    // This is an infinite loop that continues until it finds a point within the unit sphere. 
    // This is a common pattern for generating random points within a certain region, as it's simple and guarantees 
    // that the point will be within the region, but it can be inefficient if the region is small compared to the 
    // range of possible points.
    while (true) {
        // generates a random 3-dimensional vector with each component in the range [-1, 1]. 
        // The vec3::random function is assumed to generate a random number for each component of the vector.
        auto p = vec3::random(-1,1);
        // checks if the generated point is within the unit sphere. It does this by calculating the square 
        // of the length of the vector from the origin to the point, which is equivalent to the square of the 
        // radius of the sphere at that point. If the square of the length is less than 1, the point is within 
        // the unit sphere, and the function returns the point. If the square of the length is not less than 1, 
        // the function continues to the next iteration of the loop and generates a new point.
        if (p.length_squared() < 1)
            return p;
    }
}

inline vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

// We can take the dot product of the surface normal and our random vector to determine if it's in the correct hemisphere. 
// If the dot product is positive, then the vector is in the correct hemisphere. If the dot product is negative, 
// then we need to invert the vector.
inline vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

#endif