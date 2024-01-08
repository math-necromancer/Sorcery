/*The Math Necromancer*/

#ifndef _NECROMANCER_ACOS_
#define _NECROMANCER_ACOS_

#ifndef _MATH_SORCERY_
     #error This file won't work if you don't include "math_sorcery.hpp"!
#else
     #include "../float_class.hpp"
     #include "../roots.hpp"
     #include "atan.hpp"
     namespace necromancer_acos
     {
          /*12/20/2023*/
          constexpr float acosf(const float& _x)
          {
               float_32 _i = {_x};
               /*acos(_x) is undefined for |_x| > 1*/
               if(_i._y & 0x7fffffff > 0x3f800000)
                    return sorcery::NaNf;
               float _r =  necromancer_atan::
                    atanf(necromancer_root::sqrtf(1 - _x * _x) / _x);
               /*_x > 0*/
               if(_i._y < 0x80000000)
                    return _r;
               return _r + pi;
          }
          /*12/20/2023*/
          constexpr double acosd(const double& _x)
          {
               float_64 _i = {_x};
               /*acos(_x) is undefined for |_x| > 1*/
               if(_i._lh._hi & 0x7fffffff > 0x3ff00000)
                    return sorcery::NaN;
               double _r = necromancer_atan::
                    atand(necromancer_root::sqrtd(1 - _x * _x) / _x);
               /*_x > 0*/
               if(_i._lh._hi < 0x80000000)
                    return _r;
               return _r + pi;
          }
     }
#endif /*_MATH_SORCERY_*/
#endif /*_NECROMANCER_ACOS_*/