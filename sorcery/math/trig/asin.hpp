/*The Math Necromancer*/

#ifndef _NECROMANCER_ASIN_
#define _NECROMANCER_ASIN_

#ifndef _MATH_SORCERY_
     #error This file won't work if you don't include "math_sorcery.hpp"!
#else
     #include "../float_class.hpp"
     #include "../roots.hpp"
     #include "atan.hpp"
     namespace necromancer_asin
     {
          /*12/18/2023*/
          constexpr float asinf(const float& _x)
          {
               float_32 _i = {_x};
               _int32 _sx = _i._y & 0x80000000;
               _i._y ^= _sx;
               /*|_x|*/
               _i._y &= 0x7fffffff;
               /*asin(_x) is undefined for |_x| > 1*/
               if(_i._y > 0x3f800000)
                    return sorcery::NaNf;
               /*|_x| < 1/256, we return _x as it's asin(x) in single precision*/
               if(_i._y <= 0x3b800000)
                    return _x;
               _i._x = necromancer_atan::
                    atanf(_x / necromancer_root::sqrtf(1 - _x * _x));
               _i._y |= _sx;
               return _i._x;
          }
          /*12/18/2023*/
          constexpr double asind(const double& _x)
          {
               float_64 _i = {_x};
               /*|_x|*/
               _int32 _sx = _i._lh._hi & 0x80000000;
               _i._lh._hi ^= _sx;
               /*asin(_x) is undefined for |_x| > 1*/
               if(_i._lh._hi > 0x3ff00000)
                    return sorcery::NaNf;
               _i._x = necromancer_atan::
                    atand(_x / necromancer_root::sqrtd(1 - _x * _x));
               _i._lh._hi |= _sx;
               return _i._x;
          }
     }
#endif /*_MATH_SORCERY_*/
#endif /*_NECROMANCER_ASIN_*/