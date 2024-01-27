/*The Math Necromancer*/

/*This is the implementation as seen in fdlibm. All constants and methods*/
/*come from fdlibm as well.*/
/*https://netlib.org/fdlibm/e_exp.c*/
/*
* ====================================================
* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
*
* Developed at SunSoft, a Sun Microsystems, Inc. business.
* Permission to use, copy, modify, and distribute this
* software is freely granted, provided that this notice 
* is preserved.
* ====================================================
*/

#ifndef _NECROMANCER_EXP_
#define _NECROMANCER_EXP_

#ifndef _MATH_SORCERY_
    #error This file won't work if you don't include "math_sorcery.hpp"!
#else
namespace necromancer_exp
{
    static constexpr double
        /*Minimax coefficients*/
        /*From fdlibm*/
        _exp1 = 1.66666666666666019037e-01,
        _exp2 = -2.77777777770155933842e-03,
        _exp3 = 6.61375632143793436117e-05,
        _exp4 = -1.65339022054652515390e-06,
        _exp5 = 4.13813679705723846039e-08,
        _log2_h[] = {6.93147180369123816490e-01,
                    -6.93147180369123816490e-01},
        _log2_l[] = {1.90821492927058770002e-10, 
                    -1.90821492927058770002e-10},
        _half[] = {0.5, -0.5},
        _invlog2 = 1.44269504088896338700e+00,
        _expd_overflow = 7.09782712893383973096e+02,
        _expd_underflow = -7.45133219101941108420e+02,
        twom120 = 7.523163845262640051e-37,
        twom1000 = 9.3326361850321887899e-302;
    static constexpr float
        _expf_overflow = 8.872283905206973761e+01,
        _expf_underflow = -1.032789299034318511e+02;
    /*1/24/2024 <~ My Birthday! :)*/
    constexpr float expf(const float& _x)
    {
        float_32 _i = {_x};
        _int32 _sx = (_i._y >> 31) & 1;
        _int32 _aix = _i._y & 0x7fffffff;
        if(_aix >= 0x42b17218)
        {
            if(_aix >= 0x7f800000)
            {
                if(_aix > 0x7f800000)
                    return _x;
                return (_sx == 0)? _x : 0.0;
            }
            if(_x > _expf_overflow)
                return sorcery::INFINITYf;
            if(_x < _expf_underflow)
                return 0.0f;
        }
        float _rh = 0;
        float _rl = 0;
        int _k = 0;
        if(_aix > 0x3eb17218)
        {
            if(_aix < 0x3f851592)
            {
                _rh = _x - _log2_h[_sx];
                _rl = _log2_l[_sx];
                _k = 1 - _sx - _sx;
            }
            else
            {
                _k = static_cast<int>(_invlog2 * _x + _half[_sx]);
                _rh = _x - _k * _log2_h[0];
                _rl = _k * _log2_l[0];
            }
            _i._x = _rh - _rl;
        }
        else if(_aix <= 0x37000000)
            return 1.0f + _x;
        else
            _k = 0;
        float _x2 = _i._x * _i._x;
        float _c = _i._x - _x2 * (_exp1 + _x2 * (_exp2 + _x2 * (_exp3 + _x2 * (_exp4 + _x2 * _exp5))));
        if(_k == 0)
            return 1.0f - ((_i._x * _c) / (_c - 2.0f) - _i._x);
        _i._x = 1.0f - ((_rl - (_i._x * _c) / (2.0f - _c)) - _rh);
        if(_k > -120)
        {
            _i._f_32._exp += _k;
            return _i._x;
        }
        _i._f_32._exp += (_k + 120);
        return _i._x * twom120;
    }

    /*1/24/2024 <~ My Birthday! :)*/
    constexpr double expd(const double& _x)
    {
        float_64 _i = {_x};
        _int32 _sx = (_i._lh._hi >> 31) & 1;
        _int32 _aix = _i._lh._hi & 0x7fffffff;
        if(_aix > 0x40862e42)
        {
            if(_aix >= 0x7ff00000)
            {
                if((_aix & 0xfffff | _i._lh._lo) != 0)
                    return _x;
                return (_sx == 0) ? _x : 0.0;
            }
            if(_x > _expd_overflow)
                return sorcery::INFINITY;
            if (_x < _expd_underflow)
                return 0.0;
        }   
        double _rh = 0;
        double _rl = 0;
        int _k = 0;
        if(_aix > 0x3fd62e42)
        {
            if(_aix < 0x3ff0a2b2)
            {
                _rh = _x - _log2_h[_sx];
                _rl = _log2_l[_sx];
                _k = 1 - _sx - _sx;
            }
            else
            {
                _k = static_cast<int>(_invlog2 * _x + _half[_sx]);
                _rh = _x - _k * _log2_h[0];
                _rl = _k * _log2_l[0];
            }
            _i._x = _rh - _rl;
        }
        else if(_aix < 0x3e300000)
            return 1.0 + _x;
        else
            _k = 0;
        double _x2 = _i._x * _i._x;
        double _c = _i._x - _x2 * (_exp1 + _x2 * (_exp2 + _x2 * (_exp3 + _x2 * (_exp4 + _x2 * _exp5))));
        if(_k == 0)
            return 1.0 - ((_i._x * _c) / (_c - 2.0) - _i._x);
        _i._x = 1.0 - ((_rl - (_i._x * _c) / (2.0 - _c)) - _rh);
        if(_k >= -1021)
        {
            _i._f_64._exp += _k;
            return _i._x;
        }
        _i._f_64._exp += (_k + 1000);
        return _i._x * twom1000;
    }
    /*1/24/2024 <~ My Birthday! :)*/
    constexpr float exp2f(const float& _x)
    {
        return expf(_log2_h[0] * _x + _log2_l[0] * _x);
    }
    /*1/24/2024 <~ My Birthday! :)*/
    constexpr double exp2d(const double& _x)
    {
        return expd(_log2_h[0] * _x + _log2_l[0] * _x);
    }
}
#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_EXP_*/