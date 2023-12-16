/*The Math Necromancer*/

#ifndef _NECROMANCER_ABS_
#define _NECROMANCER_ABS_

#include "float_class.hpp"

namespace absolute
{
    using namespace necromancer_float_class;
    float absf(const float& _x)
    {
        if(is_nan(_x))
            return _x;
        float_32 _i;
        _i._x = _x;
        _i._y &= 0x7fffffff;
        return _i._x;
    }
    double absd(const double& _x)
    {
        if(is_nan(_x))
            return _x;
        float_64 _i;
        _i._x = _x;
        _i._y &= 0x7fffffffffffffff;
        return _i._x;
    }
    int absi(const int& _x)
    {
        if(is_nan(_x))
            return _x;
        return (_x >= 0)? _x : -_x;
    }

    float abs(const float& _x)
    {
        return absf(_x);
    }
    double abs(const double& _x)
    {
        return absd(_x);
    }
    int abs(const int& _x)
    {
        return absi(_x);
    }
    template<typename _abs_typ>
    double abs(const _abs_typ& _x)
    {
        return absd((double) _x);
    }
}

#endif /*_NECROMANCER_ABS_*/