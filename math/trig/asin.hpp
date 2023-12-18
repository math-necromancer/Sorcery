/*The Math Necromancer*/

#ifndef _NECROMANCER_ASIN_
#define _NECROMANCER_ASIN_

#include "../float_class.hpp"
#include "../roots.hpp"
#include "atan.hpp"

namespace necromancer_asin
{
     using namespace necromancer_float_class;
     /*Compute the Arcsine of a 32-bit float _x*/
     float asinf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          _i._y &= 0x7fffffff;
          float _r;
          /*_x is 0 or NaN*/
          if(_i._y > 0x7f800000 || _i._y == 0)
               return _x;
          /*_x > 1.0*/
          if(_i._y > 0x3f800000)
               return NaNf;
          _r = necromancer_atan::atanf(necromancer_root::sqrtf(_x / (1 - _x * _x)));
          return copysign(_r, _x);
     }
}

#endif /*_NECROMANCER_ASIN_*/