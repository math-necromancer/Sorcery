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
    /*Get the Square Root of a 32-bit float _x*/
    float sqrtf(const float& _x)
    {
        float_32 _i;
        _i._x = _x;
        /*If _x is infinite, nan, 0, or 1*/
        /*`_i._x >= 0x7f80...` includes the sign bit, so this also handles negatives*/
        if(_i._x >= 0x7f800000 || _i._x == 0 || _i._x == 0x3f800000)
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
    /*Compute the Square Root of a 64-bit float _x*/
    double sqrtd(const double& _x)
    {
        float_64 _i;
        _i._x = _x;
        /*If x is infinite, nan, 0, or 1*/
        /*`_i._x >= 0x7ff0...` includes the sign bit, so this also handles negatives*/
        if(_i._x >= 0x7ff0000000000000 || _i._x == 0 || _i._x == 0x3ff0000000000000)
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
}

#endif /*_NECROMANCER_ROOTS_*/