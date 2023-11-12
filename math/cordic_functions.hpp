/*The Math Necromancer*/

/*============ C++ CORDIC Algorithm Implementation ============*/
/*Includes functions for Sine, Cosine, and Tangent*/
/*as well as Arctangent, Arctangent derived from a ratio,*/
/*and the Hypotinuse given 2 sides of a right triangle*

/*Only includes this file if it*/
/*has not been included before*/
#ifndef __CORDIC_FUNCTIONS__
#define __CORDIC_FUNCTIONS__

#include "constants.hpp"
#include "rem.hpp"
#include "cordic_operations.hpp"

using namespace necromancer_cordic_operations;

namespace necromancer_cordic_functions
{
    /*Get the Arc Tangnet in Radians From a Ratio y / x*/
    long double cordic_arctan2(long double y, long double x)
    {
        cordic_result result = cordic_vector(x, y, 0);
        return result.angle;
    }

    /*Get the Arc Tangent of a Tangent Value x*/
    long double cordic_arctan(long double x)
    {
        long double y = 1;
        cordic_result result = cordic_vector(y, x, 0);
        return result.angle;
    }

    /*Get the Hypotinuse of a Right Triangle With Lengths x and y*/
    long double cordic_hypot(long double x, long double y)
    {
        /*When calling cordic_vector, the x variable is*/
        /*The hypotinuse of an imaginary triangle with side lengths of*/
        /*the original x variable and y variable*/
        cordic_result result = cordic_vector(x, y, 0);
        /*The hypotinuse is scaled by a constant cordic_K*/
        return result.x * cordic_K;
    }

    /*Get the Sine of Theta Radians*/
    long double cordic_sin(long double theta)
    {
        theta = reduce_angle(theta);
        long double x = 1.0;
        long double y = 0.0;
        cordic_result result = cordic_angle(x, y, theta);
        return result.y * cordic_K;
    }

    /*Get the Cosine of Theta Radians*/
    long double cordic_cos(long double theta)
    {
        theta = reduce_angle(theta);
        long double x = 1.0;
        long double y = 0.0;
        cordic_result result = cordic_angle(x, y, theta);
        return result.x * cordic_K;
    }

    /*Get the Tangent of Theta Radians*/
    long double cordic_tan(long double theta)
    {
        theta = reduce_angle(theta);
        long double x = 1.0;
        long double y = 0.0;
        cordic_result result = cordic_angle(x, y, theta);
        return result.y / result.x;
    }
}
#endif /*__CORDIC_FUNCTIONS__*/