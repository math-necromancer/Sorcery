/*The Math Necromancer*/

/*  ------------------------------------    */
/*  | Use hardware sqrt if you have it |    */
/*  ------------------------------------    */

#ifndef _NECROMANCER_ROOTS_
#define _NECROMANCER_ROOTS_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "float_class.hpp"

namespace necromancer_root
{
    using namespace necromancer_float_class;

    /*12/24/2023*/
    constexpr float sqrtf(const float& _x)
    {
        float_32 _i = {_x};
        /*If _x is NaN, also catches the sign bit*/
        if(_i._y > 0x7f800000)
            return NaNf;
        /*If _x is infinite, 0, or 1*/
        if(_i._y == 0x07f80000 || _i._y == 0 || _i._y == 0x3f800000)
            return _x;
        _int32 _e = ((_i._f_32._exp - 0x07f) >> 1) + 0x07f;
        _i._f_32._exp = 0x07f;
        /*Really good linear approximation of sqrt(x) for x in (1, 2)*/
        float_32 _f = {_i._x * 0.405f + 0.605f};
        _i._f_32._mantissa = _f._f_32._mantissa;
        _i._f_32._exp = _e;
        float _r = _i._x;
        _r = f32o2(_r + (_x / _r));
        _r = f32o2(_r + (_x / _r));
        _r = f32o2(_r + (_x / _r));
        _r = f32o2(_r + (_x / _r));
        return _r;
    }
    /*12/24/2023*/
    constexpr double sqrtd(const double& _x)
    {
        float_64 _i = {_x};
        /*If _x is NaN, also catches the sign bit*/
        if(_i._y > 0x7ff0000000000000)
            return NaN;
        /*If _x is infinite, 0, or 1*/
        if(_i._x == 0x7ff0000000000000 || _i._y == 0 || _i._y == 0x3ff0000000000000)
            return _x;
        _int32 _e = ((_i._f_64._exp - 0x3ff) >> 1) + 0x3ff;
        _i._f_64._exp = 0x3ff;
        /*Really good linear approximation of sqrt(x) for x in (1, 2)*/
        float_64 _f = {_i._x * 0.405 + 0.605};
        _i._f_64._mantissa = _f._f_64._mantissa;
        _i._f_64._exp = _e;
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