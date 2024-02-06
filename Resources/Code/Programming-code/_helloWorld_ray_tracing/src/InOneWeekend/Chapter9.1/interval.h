#ifndef INTERVAL_H
#define INTERVAL_H
/**
 * @file interval.h
 * @brief This file contains a class to manage real-valued intervals with a minimum and a maximum.
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

class interval {
  public:
    double min, max;

    /**
     * @brief Represents an interval between two values.
     * 
     * An interval is defined by a minimum value and a maximum value.
     * It provides various operations such as calculating the size, expanding the interval,
     * checking if it contains a value, checking if it surrounds a value, and clamping a value.
     */
    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double _min, double _max) : min(_min), max(_max) {}

    /**
     * @brief Calculates the size of the interval.
     * 
     * @return The size of the interval (max - min).
     */
    double size() const {
        return max - min;
    }

    /**
     * @brief Expands the interval by a given delta.
     * 
     * @param delta The amount by which to expand the interval.
     * @return The expanded interval.
     */
    interval expand(double delta) const {
        auto padding = delta/2;
        return interval(min - padding, max + padding);
    }

    /**
     * @brief Checks if the interval contains a given value.
     * 
     * @param x The value to check.
     * @return True if the interval contains the value, false otherwise.
     */
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    /**
     * @brief Checks if the interval surrounds a given value.
     * 
     * @param x The value to check.
     * @return True if the interval surrounds the value, false otherwise.
     */
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    /**
     * @brief Clamps a given value within the interval.
     * 
     * If the value is less than the minimum value, it is clamped to the minimum value.
     * If the value is greater than the maximum value, it is clamped to the maximum value.
     * Otherwise, the value remains unchanged.
     * 
     * @param x The value to clamp.
     * @return The clamped value.
     */
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe;
};

const interval interval::empty    = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);


#endif
