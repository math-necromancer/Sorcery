/*The Math Necromancer*/

/*I promise I'll change it later; Taylor Series is slow :(*/
/*It doesn't even include range reduction, so it kinda diverges at large values*/

#ifndef _NECROMANCER_EXP_
#define _NECROMANCER_EXP_

#include "float_class.hpp"

#ifndef _MATH_SORCERY_
    #error This file won't work if you don't include "math_sorcery.hpp"!
#else
    namespace necromancer_exp
    {
        static constexpr double
            _exp1 = 1.666666666666666666e-01,
            _exp2 = 4.166666666666666666e-02,
            _exp3 = 8.333333333333333333e-03,
            _exp4 = 1.388888888888888888e-03,
            _exp5 = 1.984126984126984127e-04,
            _exp6 = 2.480158730158730158e-05,
            _exp7 = 2.755731922398589065e-06;
        static constexpr double
            /*Doubles to make log(2) better than a single number*/
            _log2_h = 6.931471805599453e-01,
            _log2_l = 9.417232121458000e-18;

        constexpr float expf(const float& _x)
        {
            float_32 _i = {_x};
            _i._y &= 0x7fffffff;
            _int32 _e = _i._f_32._exp - 0x07f;
            _i._f_32._exp = 0x07f;
            float _f = _i._x - (_e * _log2_h + _e * _log2_l);
            _f *= 0.125f;
            _e += 3;
            float _r = 1.0f + _f * (0.5f * _f * (_exp1 * _f * (_exp2 * _f *
                (_exp3 * _f * (_exp4 * _f * (_exp5 * _f * (_exp6 * _f * _exp7)))))));
            return (1 << _e) * _r;
        }
    }
#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_EXP_*/