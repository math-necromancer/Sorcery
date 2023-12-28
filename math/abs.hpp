/*The Math Necromancer*/

#ifndef _NECROMANCER_ABS_
#define _NECROMANCER_ABS_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "float_class.hpp"

namespace necromancer_abs
{
    using namespace necromancer_float_class;
    /*12/20/2023*/
    constexpr float absf(const float& _x)
    {
        if(is_nanf(_x))
            return _x;
        float_32 _i = {_x};
        _i._y &= 0x7fffffff;
        return _i._x;
    }
    /*12/20/2023*/
    constexpr double absd(const double& _x)
    {
        if(is_nand(_x))
            return _x;
        float_64 _i = {_x};
        _i._y &= 0x7fffffffffffffff;
        return _i._x;
    }
    /*12/20/2023*/
    constexpr int absi(const int& _x)
    {
        return (_x >= 0)? _x : -_x;
    }
}

#endif /*_NECROMANCER_ABS_*/