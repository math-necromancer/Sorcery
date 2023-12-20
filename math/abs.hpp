/*The Math Necromancer*/

#ifndef _NECROMANCER_ABS_
#define _NECROMANCER_ABS_

#include "float_class.hpp"

namespace necromancer_abs
{
    using namespace necromancer_float_class;
    /*12/20/2023*/
    float absf(const float& _x)
    {
        if(is_nanf(_x))
            return _x;
        float_32 _i;
        _i._x = _x;
        _i._y &= 0x7fffffff;
        return _i._x;
    }
    /*12/20/2023*/
    double absd(const double& _x)
    {
        if(is_nand(_x))
            return _x;
        float_64 _i;
        _i._x = _x;
        _i._y &= 0x7fffffffffffffff;
        return _i._x;
    }
    /*12/20/2023*/
    int absi(const int& _x)
    {
        return (_x >= 0)? _x : -_x;
    }
    /*12/20/2023*/
    /*Get the absolute value of a 32-bit float _x*/
    float abs(const float& _x)
    {
        return absf(_x);
    }
    /*12/20/2023*/
    /*Get the absolute value of a 64-bit float _x*/
    double abs(const double& _x)
    {
        return absd(_x);
    }
    /*12/20/2023*/
    /*Get the absolute value of an integer _x*/
    int abs(const int& _x)
    {
        return absi(_x);
    }
    /*12/20/2023*/
    /*Get the absolute value of any number _x*/
    /*(Cast to Double)*/
    template<typename _abs_ty>
    _abs_ty abs(const _abs_ty& _x)
    {
        return absd(static_cast<double>(_x));
    }
}

#endif /*_NECROMANCER_ABS_*/