/*The Math Necromancer*/

#ifndef _NECROMANCER_ATAN2_
#define _NECROMANCER_ATAN2_

#ifndef _MATH_SORCERY_
     #error This file won't work if you don't include "math_sorcery.hpp"!
#else
     #include "../float_class.hpp"
     #include "atan.hpp"
     namespace necromancer_atan2
     {
          /*12/24/2023*/
          constexpr float atan2f(const float& _y, const float& _x)
          {
               float_32 _ix = {_x};
               float_32 _iy = {_y};
               /*|_x|*/
               _int32 _aix = _ix._y & 0x7fffffff;
               /*|_y|*/
               _int32 _aiy = _iy._y & 0x7fffffff;
               /*If _x or _y is NaN*/
               if(_aix > 0x7f800000 || _aiy > 0x7f800000)
                    return _x + _y;
               /*atan2(0, 0) is undefined*/
               if(_aix == 0 && _aiy == 0)
                    return sorcery::NaNf;
               /*_x is positive*/
               /*(1'st and 4'th quad)*/
               if(_ix._y == _aix)
                    return necromancer_atan::atanf(_y / _x);
               /*_x is negative and _y is positive*/
               /*(2'nd quad)*/
               if(_ix._y > 0x80000000 && _iy._y == _aiy)
                    return necromancer_atan::atanf(_y / _x) + pi;
               /*_x and _y are both negative*/
               /*(3'rd quad)*/
               return necromancer_atan::atanf(_y / _x) - pi;
          }
          /*12/24/2023*/
          constexpr double atan2d(const double& _y, const double& _x)
          {
               float_64 _ix = {_x};
               float_64 _iy = {_y};
               /*|_x|*/
               _int32 _aix = _ix._lh._hi & 0x7fffffff;
               /*|_y|*/
               _int32 _aiy = _iy._lh._hi & 0x7fffffff;
               /*If _x of _y is NaN*/
               if(_aix > 0x7ff00000 || _aiy > 0x7ff00000)
                    return _x + _y;
               /*atan2(0, 0) is undefined*/
               if((_aix | _ix._lh._lo) == 0 && (_aiy | _iy._lh._lo == 0))
                    return sorcery::NaN;
               /*_x is positive*/
               /*(1'st and 4'th quad)*/
               if(_ix._lh._hi == _aix)
                    return necromancer_atan::atand(_y / _x);
               /*_x is negative and _y is positive*/
               /*(2'nd quad)*/
               if(_ix._lh._hi > 0x80000000 && _iy._lh._hi == _aiy)
                    return necromancer_atan::atand(_y / _x) + pi;
               /*_x and _y are both negative*/
               /*(3'rd quad)*/
               return necromancer_atan::atand(_y / _x) - pi;
          }
     }
#endif /*_MATH_SORCERY_*/
#endif /*_NECROMANCER_ATAN2_*/