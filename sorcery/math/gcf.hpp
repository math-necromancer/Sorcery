/*The Math Necromaner*/

#ifndef _NECROMANCER_GCF_
#define _NECROMANCER_GCF_

#ifndef _MATH_SORCERY_
    #error This file won't work if you don't include "math_sorcery.hpp"!
#else
#include "swap.hpp"
namespace necromancer_gcf
{
     /*12/24/2023*/
     constexpr int gcf(const int& _x, const int& _y)
     {
          if(_x == 0)
               return _y;
          if(_y == 0)
               return _x;
          int _f = sorcery::abs(_x), _g = sorcery::abs(_y);
          int _k = sorcery::countr_zero(_f | _g);
          const int _i = sorcery::countr_zero(_f);
               _f >>= _i;
          const int _j = sorcery::countr_zero(_g);
               _g >>= _j;
          while(_f != _g)
          {
               if(_f < _g)
                    necromancer_swap::swap(_f, _g);
               _f -= _g;
               _f >>= sorcery::countr_zero(_f);
          }
          return _f << _k;
     }
     /*1/7/2024*/
     constexpr _s_int64 gcf(const _s_int64& _x, const _s_int64& _y)
     {
          if(_x == 0)
               return _y;
          if(_y == 0)
               return _x;
          _s_int64 _f = sorcery::abs(_x), _g = sorcery::abs(_y);
          _s_int64 _k = sorcery::countr_zero(_f | _g);
          const int _i = sorcery::countr_zero(_f);
               _f >>= _i;
          const int _j = sorcery::countr_zero(_g);
               _g >>= _j;
          while(_f != _g)
          {
               if(_f < _g)
                    necromancer_swap::swap(_f, _g);
               _f -= _g;
               _f >>= sorcery::countr_zero(_f);
          }
          return _f << _k;
     }
     /*12/24/2023*/
     constexpr int lcm(const int& _x, const int& _y)
     {
          /*We would do (_x * _y) / gcf(_x, _y), but that has overflow*/
          return _x * (_y / gcf(_x, _y));
     }
     /*1/7/2024*/
     constexpr _s_int64 lcm(const _s_int64 _x, const _s_int64 _y)
     {
          /*We would do (_x * _y) / gcf(_x, _y), but that has overflow*/
          return _x * (_y / gcf(_x, _y));
     }
}
#endif /*_MATH_SORCERY_*/
#endif /* _NECROMANCER_GCF_ */