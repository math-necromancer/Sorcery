/*The Math Necromancer*/

#ifndef _NECROMANCER_LCM_
#define _NECROMANCER_LCM_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "gcf.hpp"

namespace necromancer_lcm
{
     /*12/24/2023*/
     /*Return the least common multiple of integers _x and _y*/
     constexpr int lcm(const int& _x, const int& _y)
     {
          return (_x * _y) / necromancer_gcf::gcf(_x, _y);
     }
}

#endif /*_NECROMANCER_LCM_*/