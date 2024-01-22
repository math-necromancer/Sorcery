/*The Math Necromancer*/

#ifndef _NECROMANCER_REM_
#define _NECROMANCER_REM_

#ifndef _MATH_SORCERY_
    #error This file won't work if you don't include "math_sorcery.hpp"!
#else
    #include "float_class.hpp"

    namespace necromancer_rem
    {
        /*12/24/2023*/ // <=  NOT ANYMORE
        constexpr float remf(const float& _x, const float& _y)
        {
            float_32 _ix = {_x}, _iy = {_y};
            _ix._y &= 0x7fffffff;
            _iy._y &= 0x7fffffff;
            if(_iy._y == 0 || _ix._y >= 0x7f800000)
            {
                if(_ix._y == 0x7f800000)
                    return _x;
                return sorcery::NaNf;
            }
            if(_ix._y < _iy._y)
                return _x;
            
        }
        /*12/24/2023*/
        constexpr double remd(const double& _x, const double& _y)
        {
            if(_y == 1)
                return _x - static_cast<int>(_x);
            if(_y == 0)
                return sorcery::NaN;
            int _q = static_cast<int>(_x / _y);
            return _x - (static_cast<double>(_q) * _y);
        }
    }

#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_REM_*/