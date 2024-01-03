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
            return sorcery::NaNf;
        /*If _x is infinite, 0, or 1*/
        if(_i._y == 0x07f80000 || _i._y == 0 || _i._y == 0x3f800000)
            return _x;
        _int32 _e = ((_i._f_32._exp - 0x07f) >> 1) + 0x07f;
        _i._f_32._exp = 0x07f;
        /*Really good linear approximation of sqrt(x) for x in (1, 2)*/
        float _f = _i._x * 0.414f + 0.596f;
        _i = {_f};
        _i._f_32._exp = _e;
        float _r = _i._x;
        _r = (_r + _x / _r) * 0.5f;
        _r = (_r + _x / _r) * 0.5f;
        _r = (_r + _x / _r) * 0.5f;
        _r = (_r + _x / _r) * 0.5f;
        return _r;
    }
    /*12/24/2023*/
    constexpr double sqrtd(const double& _x)
    {
        float_64 _i = {_x};
        /*If _x is NaN, also catches the sign bit*/
        if(_i._y > 0x7ff0000000000000)
            return sorcery::NaN;
        /*If _x is infinite, 0, or 1*/
        if(_i._x == 0x7ff0000000000000 || _i._y == 0 || _i._y == 0x3ff0000000000000)
            return _x;
        _int32 _e = ((_i._f_64._exp - 0x3ff) >> 1) + 0x3ff;
        _i._f_64._exp = 0x3ff;
        /*Really good linear approximation of sqrt(x) for x in (1, 2)*/
        double _f = _i._x * 0.414 + 0.596;
        _i = {_f};
        _i._f_64._exp = _e;
        double _r = _i._x;
        _r = (_r + _x / _r) * 0.5;
        _r = (_r + _x / _r) * 0.5;
        _r = (_r + _x / _r) * 0.5;
        _r = (_r + _x / _r) * 0.5;
        _r = (_r + _x / _r) * 0.5;
        return _r;
    }
}

#endif /*_NECROMANCER_ROOTS_*/