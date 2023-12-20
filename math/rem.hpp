/*The Math Necromancer*/

#ifndef _NECROMANCER_REM_
#define _NECROMANCER_REM_

#include "constants.hpp"
#include "float_class.hpp"

namespace necromancer_rem
{
    /*12/20/2023*/
    float remf(const float& _x, const float& _y)
    {
        if(_y == 1)
        {
            return _x - static_cast<int>(_x);
        }
        if(_y == 0)
        {
            return NaNf;
        }
        int _q = static_cast<int>(_x / _y);
        return _x - (static_cast<float>(_q) * _y);
    }
    /*12/20/2023*/
    double remd(const double& _x, const double& _y)
    {
        if(_y == 1)
        {
            return _x - static_cast<int>(_x);
        }
        if(_y == 0)
        {
            return NaN;
        }
        int _q = static_cast<int>(_x / _y);
        return _x - (static_cast<double>(_q) * _y);
    }
    /*12/20/2023*/
    /*Return the remainder of a 32-bit float division _x / _y*/
    float rem(const float& _x, const float& _y)
    {
        return remf(_x, _y);
    }
    /*12/20/2023*/
    /*Return the remainder of a 64-bit float division _x / _y*/
    double rem(const double& _x, const double& _y)
    {
        return remd(_x, _y);
    }
    /*12/20/2023*/
    /*Return the remainder of a division _x / _y*/
    /*(Cast to Double)*/
    template<typename _rem_ty>
    _rem_ty rem(const _rem_ty& _x, const _rem_ty& _y)
    {
        return static_cast<_rem_ty>(remd(
            static_cast<double>(_x), static_cast<double>(_y)
        ));
    }
}

#endif /*_NECROMANCER_REM_*/