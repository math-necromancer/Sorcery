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
#include "roots.hpp"

using namespace necromancer_cordic_operations;

namespace necromancer_cordic_functions
{
    typedef long double lngdbl_tp;

    /*Get the Arc Tangnet in Radians From a Ratio x / y*/
    template<typename _CRDC = lngdbl_tp>
    _CRDC cordic_arctan2(const _CRDC& _y, const _CRDC& _x)
    {
        cordic_result<_CRDC> result = cordic_vec_euclid(_x, _y, (_CRDC) 0);
        _CRDC _r = result.angle();
        return _r;
    }

    template<typename _CRDC = lngdbl_tp>
    _CRDC cordic_arcsin(const _CRDC& _x)
    {
        /*root::sqrt() is slow, will use CORDIC sqrt() later*/
        _CRDC _y = root::sqrt((_CRDC) 1 - (_x * _x));
        cordic_result<_CRDC> result = cordic_vec_euclid(_y, _x, (_CRDC) 0);
        _CRDC _r = result.angle();
        return _r;
    }

    template<typename _CRDC = lngdbl_tp>
    _CRDC cordic_arccos(const _CRDC& _x)
    {
        _CRDC _y = root::sqrt((_CRDC) 1 - (_x * _x));
        cordic_result result = cordic_vec_euclid(_x, _y, (_CRDC) 0);\
        _CRDC _r = result.angle() > 0? result.angle(): result.angle() + pi;
        return _r;
    }

    /*Get the Arc Tangent of a Tangent Value x*/
    template<typename _CRDC = lngdbl_tp>
    _CRDC cordic_arctan(const _CRDC& _x)
    {
        _CRDC _y = 1;
        cordic_result<_CRDC> result = cordic_vec_euclid(_y, _x, (_CRDC) 0);
        _CRDC _r = result.angle();
        return _r;
    }

    /*Get the Hypotinuse of a Right Triangle With Lengths x and y*/
    template<typename _CRDC = lngdbl_tp>
    _CRDC cordic_hypot(const _CRDC _x, const _CRDC& _y)
    {
        /*When calling cordic_vector, the x variable is*/
        /*The hypotinuse of an imaginary triangle with side lengths of*/
        /*the original x variable and y variable*/
        cordic_result<_CRDC> result = cordic_vec_euclid(_x, _y, (_CRDC) 0);
        /*The hypotinuse is scaled by a constant cordic_K*/
        return result.x() * cordic_K;
    }

    /*Get the Sine of Theta Radians*/
    template<typename _CRDC = lngdbl_tp>
    _CRDC cordic_sin(const _CRDC& _theta)
    {
        _CRDC theta = reduce_angle(_theta);
        _CRDC _x = 1;
        _CRDC _y = 0;
        cordic_result<_CRDC> result = cordic_angle_euclid(_x, _y, theta);
        return result.y() * cordic_K;
    }

    /*Get the Cosine of Theta Radians*/
    template<typename _CRDC = lngdbl_tp>
    _CRDC cordic_cos(const _CRDC& _theta)
    {
        _CRDC theta = reduce_angle(_theta);
        _CRDC _x = 1;
        _CRDC _y = 0;
        cordic_result<_CRDC> result = cordic_angle_euclid(_x, _y, theta);
        return result.x() * cordic_K;
    }

    /*Get the Tangent of Theta Radians*/
    template<typename _CRDC = lngdbl_tp>
    _CRDC cordic_tan(_CRDC _theta)
    {
        _CRDC theta = reduce_angle(_theta);
        _CRDC _x = 1;
        _CRDC _y = 0;
        cordic_result result = cordic_angle_euclid(_x, _y, theta);
        return result.y() / result.x();
    }
}
#endif /*__CORDIC_FUNCTIONS__*/