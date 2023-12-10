/*The Math Necromancer*/

#ifndef _NECROMANCER_REM_
#define _NECROMANCER_REM_

#include "constants.hpp"
#include "float_class.hpp"

namespace necromancer_rem
{
    double rem(const double& _x, const double& _y)
    {
        if(_y == 1)
        {
            return _x - (int) _x;
        }
        int _q = (int) (_x / _y);
        return _x - ((float) _q * _y);
    }
}

#endif /*_NECROMANCER_REM_*/