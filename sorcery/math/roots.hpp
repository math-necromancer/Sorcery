/*The Math Necromancer*/

/*  ------------------------------------    */
/*  | Use hardware sqrt if you have it |    */
/*  ------------------------------------    */

#ifndef _NECROMANCER_ROOTS_
#define _NECROMANCER_ROOTS_

#ifndef _MATH_SORCERY_
    #error This file won't work if you don't include "math_sorcery.hpp"!
#else

namespace necromancer_root
{
    constexpr static double
        _root2_h = 1.41421356052160263062e-00,
        _root2_l = 1.85149241818168869221e-09,
        _sqrt0 = 2.970007306476529,
        _sqrt1 = -5.905066631911932,
        _sqrt2 = 8.4484863690695,
        _sqrt3 = -7.372624329236391,
        _sqrt4 = 3.793513538167545,
        _sqrt5 = -1.056911270417094,
        _sqrt6 = 1.2280370363669926e-01;
    /*1/7/2024*/
    constexpr float sqrtf(const float& _x)
    {
        float_32 _i = {_x};
        if(_i._y >= 0x7f800000)
        {
            if(_i._y < 0x80000000) 
                return _x;
            return sorcery::NaN;
        }
        int _e = _i._f_32._exp - 127;
        _i._f_32._exp = 127;
        if(_e & 1)
            _i._f_32._exp --;
            _e ++;
        /*To avoid divisions, we calculate x / sqrt(x). 1 / sqrt(x) doesn't*/
        /*need division to calculate, and sqrt(x) = x / sqrt(x).*/
        /*It's a nice trick*/
        float _f = _sqrt0 + _i._x * (_sqrt1 + _i._x * (_sqrt2 + _i._x * (_sqrt3 + _i._x * (_sqrt4 + _i._x * (_sqrt5 + _i._x * _sqrt6)))));
        _f *= 1.5f - 0.5f * _i._x * _f * _f;
        /*Double Newton iteration that saves 1 multiply and quadruples correct digits*/
        float _z = _f * _i._x + 1.0f / _f;
        _i._x = 0.25f * _z + _i._x / _z;
        _i._f_32._exp += _e >> 1;
        return _i._x;
    }
    /*2/1/2024*/
    constexpr double sqrtd(const double& _x)
    {
        float_64 _i = {_x};
        if(_i._lh._hi >= 0x7ff00000)
        {
            if(_i._lh._hi < 0x80000000) 
                return _x;
            return sorcery::NaN;
        }
        int _e = _i._f_64._exp - 1023;
        _i._f_64._exp = 1023;
        if(_e & 1)
            _i._f_64._exp --;
            _e ++;
        /*To avoid divisions, we calculate x / sqrt(x). 1 / sqrt(x) doesn't*/
        /*need division to calculate, and sqrt(x) = x / sqrt(x).*/
        /*It's a nice trick*/
        double _f = _sqrt0 + _i._x * (_sqrt1 + _i._x * (_sqrt2 + _i._x * (_sqrt3 + _i._x * (_sqrt4 + _i._x * (_sqrt5 + _i._x * _sqrt6)))));
        _f *= 1.5 - 0.5 * _i._x * _f * _f;
        _f *= 1.5 - 0.5 * _i._x * _f * _f;
        /*Double Newton iteration that saves 1 multiply and quadruples correct digits*/
        double _z = _f * _i._x + 1.0 / _f;
        _i._x = 0.25 * _z + _i._x / _z;
        _i._f_64._exp += _e >> 1;
        return _i._x;
    }   
}
#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_ROOTS_*/