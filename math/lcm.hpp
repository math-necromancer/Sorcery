/*The Math Necromancer*/

#ifndef _NECROMANCER_LCM_
#define _NECROMANCER_LCM_

#include "gcf.hpp"

namespace necromancer_lcm
{
     /*12/20/2023*/
     /*Return the least common multiple of integers _x and _y*/
     int lcm(const int& _x, const int& _y)
     {
          return (_x * _y) / necromancer_gcf::gcf(_x, _y);
     }
}

#endif /*_NECROMANCER_LCM_*/