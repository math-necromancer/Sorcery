/*The Math Necromaner*/

#ifndef __GCF__
#define __GCF__

#include "swap.hpp"

namespace necromancer_gcf
{
     int euclid_gcf(const int& _x, const int& _y)
     {
          int x = _x;
          int y = _y;
          if(x == y)
          {
               return x;
          }
          else if(x < y)
          {
               necromancer_swap::swap(x, y);
          }
          double _r;
          while(y != 0)
          {
               _r = x % y;
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

#endif /* __GCF__ */