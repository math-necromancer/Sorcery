/*The Math Necromancer*/

/*  ------------------------------------    */
/*  | Use hardware sqrt if you have it |    */
/*  ------------------------------------    */

#ifndef _NECROMANCER_ROOTS_
#define _NECROMANCER_ROOTS_

#include "constants.hpp"
#include "float_class.hpp"

namespace necromancer_root
{
    using namespace necromancer_float_class;

    /*12/18/2023*/
    float sqrtf(const float& _x)
    {
        float_32 _i;
        _i._x = _x;
        /*If _x is NaN, also catches the sign bit*/
        if(_i._y > 0x7f800000)
            return NaNf;
        /*If _x is infinite, 0, or 1*/
        if(_i._y == 0x07f80000 || _i._y == 0 || _i._y == 0x3f800000)
            return _x;
        _int32 _e = (_i._f_32._exp - 0x07f) >> 1;
        _i._f_32._exp = 0x07f;
        float_32 _f;
        /*Really good linear approximation of sqrt(x) for x in (1, 2)*/
        _f._x = _i._x * 0.405f + 0.605f;
        _i._f_32._mantissa = _f._f_32._mantissa;
        _i._f_32._exp = _e + 0x07f;
        float _r = _i._x;
        _r = f32o2(_r + (_x / _r));
        _r = f32o2(_r + (_x / _r));
        _r = f32o2(_r + (_x / _r));
        _r = f32o2(_r + (_x / _r));
        return _r;
    }
    /*12/18/2023*/
    double sqrtd(const double& _x)
    {
        float_64 _i;
        _i._x = _x;
        /*If _x is NaN, also catches the sign bit*/
        if(_i._y > 0x7ff0000000000000)
            return NaN;
        /*If _x is infinite, 0, or 1*/
        if(_i._x == 0x7ff0000000000000 || _i._y == 0 || _i._y == 0x3ff0000000000000)
            return _x;
        _int32 _e = (_i._f_64._exp - 0x3ff) >> 1;
        _i._f_64._exp = 0x3ff;
        float_64 _f;
        /*Really good linear approximation of sqrt(x) for x in (1, 2)*/
        _f._x = _i._x * 0.405 + 0.605;
        _i._f_64._mantissa = _f._f_64._mantissa;
        _i._f_64._exp = _e + 0x3ff;
        double _r = _i._x;
        _r = f64o2(_r + (_x / _r));
        _r = f64o2(_r + (_x / _r));
        _r = f64o2(_r + (_x / _r));
        _r = f64o2(_r + (_x / _r));
        _r = f64o2(_r + (_x / _r));
        return _r;
    }
    /*12/20/2023*/
    /*Compute the square root of a 32-bit float _x*/
    float sqrt(const float& _x)
    {
        return sqrtf(_x);
    }
    /*12/20/2023*/
    /*Compute the square root of a 64-bit float _x*/
    double sqrt(const double& _x)
    {
        return sqrtd(_x);
    }
    /*12/20/2023*/
    /*Compute the square root of any number _x*/
    /*(Cast to Double)*/
    template<typename _sqrt_ty>
    double sqrt(const _sqrt_ty& _x)
    {
        return sqrtd(static_cast<double>(_x));
    }
}

#endif /*_NECROMANCER_ROOTS_*/