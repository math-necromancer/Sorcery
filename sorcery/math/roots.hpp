/*The Math Necromancer*/

/*  ------------------------------------    */
/*  | Use hardware sqrt if you have it |    */
/*  ------------------------------------    */

#ifndef _NECROMANCER_ROOTS_
#define _NECROMANCER_ROOTS_

#ifndef _MATH_SORCERY_
    #error This file won't work if you don't include "math_sorcery.hpp"!
#else
    #include "float_class.hpp"

    namespace necromancer_root
    {
        constexpr static double
            _root2_h = 1.41421356237309492343,
            _root2_l = 1.25371688724209987963e-16;
        constexpr static float
            _root2f_h = 1.41421353816986083984,
            _root2f_l = 2.42040947284749563551e-8;
        /*1/7/2024*/
        constexpr float sqrtf(const float& _x)
        {
            float_32 _i = {_x};
            /*If _x is infinite or 0*/
            if(_i._y == 0x07f80000 || _i._y & 0x7fffffff == 0 || _x == 1)
                return _x;
            /*If _x is NaN, also catches the sign bit*/
            if(_i._y > 0x7f800000)
                return sorcery::NaNf;
            int _k = _i._f_32._exp - 0x07f;
            int _e = (_k >> 1) + 0x07f;
            _i._f_32._exp = 0x07f;
            /*To avoid divisions, we calculate x / sqrt(x). 1 / sqrt(x) doesn't*/
            /*need division to calculate, and sqrt(x) = x / sqrt(x).*/
            /*It's a nice trick*/
            float _f = 0.1501f * _i._x * _i._x - 0.7374f * _i._x + 1.585f;
            _f = 1.5f * _f - 0.5f * _i._x * _f * _f * _f;
            _f = 1.5f * _f - 0.5f * _i._x * _f * _f * _f;
            _i = {_f * _i._x};
            _i._f_32._exp = _e;
            float _r = 0;
            if(_k & 1)
                _r += _i._x * _root2f_h + _i._x * _root2f_l;
            else
                _r += _i._x;
            /*Clean up any imprecision*/
            return (_r + _x / _r) * 0.5f;
        }
        /*1/7/2024*/
        constexpr double sqrtd(const double& _x)
        {
            float_64 _i = {_x};
            /*If _x is infinite or 0*/
            if(_i._lh._hi == 0x7ff00000 || (_i._lh._hi & 0x7fffffff | _i._lh._lo) == 0 || _x == 1)
                return _x;
            /*If _x is NaN, also catches the sign bit*/
            if(_i._lh._hi > 0x7f800000)
                return sorcery::NaN;
            int _k = _i._f_64._exp - 0x3ff;
            int _e = (_k >> 1) + 0x3ff;
            _i._f_64._exp = 0x3ff;
            /*To avoid divisions, we calculate x / sqrt(x). 1 / sqrt(x) doesn't*/
            /*need division to calculate, and sqrt(x) = x / sqrt(x).*/
            /*It's a nice trick*/
            double _f = 0.1501 * _i._x * _i._x - 0.7374 * _i._x + 1.585;
            _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
            _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
            _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
            _i = {_f * _i._x};
            _i._f_64._exp = _e;
            double _r = 0;
            if(_k & 1)
                _r += _i._x * _root2_h + _i._x * _root2_l;
            else
                _r += _i._x;
            /*Clean up any imprecision*/
            return (_r + _x / _r) * 0.5;
        }
    }
#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_ROOTS_*/