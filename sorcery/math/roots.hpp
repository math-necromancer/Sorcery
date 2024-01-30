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
        _root2_l = 1.85149241818168869221e-09;
    /*1/7/2024*/
    constexpr float sqrtf(const float& _x)
    {
        float_32 _i = {_x};
        if(_i._y >= 0x7f800000)
        {
            if(_i._y == 0x7f800000) 
                return _x;
            return sorcery::NaNf;
        }
        if(_i._y == 0x3f800000 || _i._y == 0)
            return _x;
        int _e = 0;
        _i._x = necromancer_float_class::frexpf(_i._x, &_e);
        if(_e & 1)
        {
            _i._x *= 0.5f;
            _e ++;
        }
        /*To avoid divisions, we calculate x / sqrt(x). 1 / sqrt(x) doesn't*/
        /*need division to calculate, and sqrt(x) = x / sqrt(x).*/
        /*It's a nice trick*/
        float _f = 0.778f * _i._x * _i._x - 1.99f * _i._x + 2.211f;
        _f = 1.5f * _f - 0.5f * _i._x * _f * _f * _f;
        _f = 1.5f * _f - 0.5f * _i._x * _f * _f * _f;
        _f = 1.5f * _f - 0.5f * _i._x * _f * _f * _f;
        _i._x *= _f;
        _i._f_32._exp += _e >> 1;
        return (_i._x + _x / _i._x) * 0.5;
    }
    /*1/7/2024*/
    constexpr double sqrtd(const double& _x)
    {
        float_64 _i = {_x};
        if(_i._lh._hi >= 0x7ff00000 && _i._lh._lo == 0)
        {
            if(_i._lh._hi == 0x7ff00000) 
                return _x;
            return sorcery::NaN;
        }
        if((_i._lh._hi & 0xc00fffff | _i._lh._lo) == 0)
            return _x;
        int _e = 0;
        _i._x = necromancer_float_class::frexpd(_i._x, &_e);
        if(_e & 1)
        {
            _i._x *= 0.5;
            _e ++;
        }
        /*To avoid divisions, we calculate x / sqrt(x). 1 / sqrt(x) doesn't*/
        /*need division to calculate, and sqrt(x) = x / sqrt(x).*/
        /*It's a nice trick*/
        double _f = 0.778 * _i._x * _i._x - 1.99 * _i._x + 2.211;
        _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
        _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
        _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
        _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
        _i._x *= _f;
        _i._f_64._exp += _e >> 1;
        _i._x = (_i._x + _x / _i._x) * 0.5;
        if (_i._x * _i._x > _x)
            _i._y --;
        else if(_i._x * _i._x < _x)
            _i._y ++;
        return _i._x;
    }   
}
#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_ROOTS_*/