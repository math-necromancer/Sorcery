/*The Math Necromancer*/

/*I promise I'll change it later; Taylor Series is slow :(*/
/*It doesn't even include range reduction, so it kinda diverges at large values*/

#ifndef _NECROMANCER_EXP_
#define _NECROMANCER_EXP_

#include "float_class.hpp"
#include "math_sorcery.hpp"

#ifndef _MATH_SORCERY_
    #error This file won't work if you don't include "math_sorcery.hpp"!
#else
    namespace necromancer_exp
    {
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
        static constexpr double
            /*Minimax coefficients*/
            /*From fdlibm*/
            _exp1 = 1.66666666666666019037e-01,
            _exp2 = -2.77777777770155933842e-03,
            _exp3 = 6.61375632143793436117e-05,
            _exp4 = -1.65339022054652515390e-06,
            _exp5 = 4.13813679705723846039e-08;
        static constexpr double
            /*Doubles to make log(2) better than a single number*/
            /*From fdlibm*/
            _log2_h = 6.9314718036912381e-01,
            _log2_l = 1.9082149292705877e-10;
        static constexpr float
            _expf_overflow = 8.872283905206973761e+01,
            _expf_underflow = -1.032789299034318511e+02;
        static constexpr double
            _expd_overflow = 7.09782712893383973096e+02,
            _expd_underflow = -7.45133219101941108420e+02;
        float expf(const float& _x)
        {
            float_32 _i = {_x};
            /*If */
            if(_i._y & 0x7fffffff > 0x7f800000)
                return _x;
            if(_i._y == 0x7f800000 || _x > _expf_overflow)
                return sorcery::INFINITYf;
            if(_i._y == 0xff800000 || _x < _expf_underflow)
                return 0.0f;
            
        }
    }
#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_EXP_*/