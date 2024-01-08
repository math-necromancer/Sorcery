/*The Math Necromancer*/

#ifndef _NECROMANCER_ABS_
#define _NECROMANCER_ABS_

#ifndef _MATH_SORCERY_
     #error This file won't work if you don't include "math_sorcery.hpp"!
#else
    #include "float_class.hpp"
    namespace necromancer_abs
    {
        /*1/5/2024*/
        constexpr float absf(const float& _x)
        {
            float_32 _i = {_x};
            _i._y &= 0x7fffffff;
            return _i._x;
        }
        /*1/5/2024*/
        constexpr double absd(const double& _x)
        {
            float_64 _i = {_x};
            _i._lh._hi &= 0x7fffffff;
            return _i._x;
        }
    }
#endif /*_MATH_SORCERY_*/
#endif /*_NECROMANCER_ABS_*/