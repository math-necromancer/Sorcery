/*The Math Necromancer*/

#ifndef _NECROMANCER_LCM_
#define _NECROMANCER_LCM_

#include "gcf.hpp"

namespace necromancer_lcm
{
     int lcm(const int& _x, const int& _y)
     {
          int _prod = _x * _y;
          return _prod / necromancer_gcf::gcf(_x, _y);
     }
}

#endif /*_NECROMANCER_LCM_*/