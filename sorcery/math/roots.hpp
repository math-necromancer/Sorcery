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
        /*1/7/2024*/
        constexpr float sqrtf(const float& _x)
        {
            float_32 _i = {_x};
            /*If _x is NaN, also catches the sign bit*/
            if(_i._y > 0x7f800000)
                return sorcery::NaNf;
            /*If _x is infinite or 0*/
            if(_i._y == 0x07f80000 || _x == 0 || _x == 1)
                return _x;
            float _exp_mult = 1.0f;
            if(_i._f_32._exp - 0x07f & 1)
                _exp_mult = 1.4142135f;
            int _e = (_i._f_32._exp - 0x07f >> 1) + 0x07f;
            _i._f_32._exp = 0x07f;
            /*To avoid divisions, we calculate x / sqrt(x). 1 / sqrt(x) doesn't*/
            /*need division to calculate, and sqrt(x) = x / sqrt(x).*/
            /*It's a nice trick*/
            float _f = 0.18f * _i._x * _i._x - 0.839f * _i._x + 1.6662f;
            _f = 1.5f * _f - 0.5f * _i._x * _f * _f * _f;
            _f = 1.5f * _f - 0.5f * _i._x * _f * _f * _f;
            _i = {_f * _i._x};
            _i._f_32._exp = _e;
            return _i._x * _exp_mult;
        }
        /*1/7/2024*/
        constexpr double sqrtd(const double& _x)
        {
            float_64 _i = {_x};
            /*If _x is NaN, also catches the sign bit*/
            if(_i._y > 0x7ff0000000000000)
                return sorcery::NaN;
            /*If _x is infinite or 0*/
            if(_i._lh._hi == 0x7ff00000 || _x == 0 || _x == 1)
                return _x;
            double _exp_mult = 1.0;
            if(_i._f_64._exp - 0x3ff & 1)
                _exp_mult = 1.414213562373095;
            int _e = (_i._f_64._exp - 0x3ff >> 1) + 0x3ff;
            _i._f_64._exp = 0x3ff;
            /*To avoid divisions, we calculate x / sqrt(x). 1 / sqrt(x) doesn't*/
            /*need division to calculate, and sqrt(x) = x / sqrt(x).*/
            /*It's a nice trick*/
            double _f = 0.18 * _i._x * _i._x - 0.839 * _i._x + 1.6662;
            _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
            _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
            _f = 1.5 * _f - 0.5 * _i._x * _f * _f * _f;
            _i = {_f * _i._x};
            _i._f_64._exp = _e;
            return _i._x * _exp_mult;
        }
    }
#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_ROOTS_*/