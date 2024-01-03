/*The Math Necromancer*/

#ifndef _NECROMANCER_REM_
#define _NECROMANCER_REM_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "float_class.hpp"

namespace necromancer_rem
{
    /*12/24/2023*/
    constexpr float remf(const float& _x, const float& _y)
    {
        if(_y == 1)
            return _x - static_cast<int>(_x);
        if(_y == 0)
            return sorcery::NaNf;
        int _q = static_cast<int>(_x / _y);
        return _x - (static_cast<float>(_q) * _y);
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

#endif /*_NECROMANCER_REM_*/