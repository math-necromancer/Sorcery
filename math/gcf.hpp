/*The Math Necromaner*/

#ifndef _NECROMANCER_GCF_
#define _NECROMANCER_GCF_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "swap.hpp"

namespace necromancer_gcf
{
     /*12/24/2023*/
     /*Return the greatest common factor of integers _x and _y*/
     constexpr int gcf(const int& _x, const int& _y)
     {
          if(_x == _y)
               return _x;
          if(_x == 0)
               return _y;
          if(_y == 0)
               return _x;
          int _x1 = _x;
          int _y1 = _y;
          int _k = 0;
          while(((_x1 | _y1) & 1) == 0)
          {
               _x1 >>= 1;
               _y1 >>= 1;
               _k ++;
          }
          while((_x1 & 1) == 0)
               _x1 >>= 1;
          while(_y1 != 0)
          {
               while((_y1 & 1) == 0)
                    _y1 >>= 1;
               if(_x1 > _y1)
                    necromancer_swap::swap(_x1, _y1);
               _y1 -= _x1;
          }
          return _x1 << _k;
     }
}

#endif /* _NECROMANCER_GCF_ */