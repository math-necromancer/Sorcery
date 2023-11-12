/*The Math Necromaner*/

#ifndef __GCM__
#define __GCM__

#include "swap.hpp"
#include "rem.hpp"

namespace necromancer_gcf
{
     int euclid_gcf(const int& _x, const int& _y)
     {
          int x = _x;
          int y = _y;
          if(x < y)
          {
               necromancer_swap::swap(x, y);
          }
          double _r;
          while(y != 0)
          {
               _r = necromancer_rem::rem(x, y);
               x = y;
               y = _r;
          }
          return x;
     }
     int gcf(const int& _x, const int& _y)
     {
          return euclid_gcf(_x, _y);
     }
}

#endif /* __GCM__ */