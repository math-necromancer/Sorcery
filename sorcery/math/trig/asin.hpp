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
               /*asin(_x) is undefined for |_x| > 1*/
               if(_i._y & 0x7fffffff > 0x3f800000)
                    return sorcery::NaNf;
               return necromancer_atan::
                    atanf(_x / necromancer_root::sqrtf(1 - _x * _x));
          }
          /*12/18/2023*/
          constexpr double asind(const double& _x)
          {
               float_64 _i = {_x};
               /*asin(_x) is undefined for |_x| > 1*/
               if(_i._lh._hi & 0x7fffffff > 0x3ff00000)
                    return sorcery::NaNf;
               return necromancer_atan::
                    atand(_x / necromancer_root::sqrtd(1 - _x * _x));
          }
     }
#endif /*_MATH_SORCERY_*/
#endif /*_NECROMANCER_ASIN_*/