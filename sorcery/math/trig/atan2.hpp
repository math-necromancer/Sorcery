/*The Math Necromancer*/

#ifndef _NECROMANCER_ATAN2_
#define _NECROMANCER_ATAN2_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "../float_class.hpp"
#include "atan.hpp"

/*#define for pi, used when this file has no incoming definition*/
#ifndef pi
     #define pi 3.1415926535897932384
#endif /*pi*/

namespace necromancer_atan2
{
     using namespace necromancer_float_class;
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
          _int64 _aix = _ix._y & 0x7fffffffffffffff;
          /*|_y|*/
          _int64 _aiy = _iy._y & 0x7fffffffffffffff;
          /*If _x of _y is NaN*/
          if(_aix > 0x7ff0000000000000 || _aiy > 0x7ff0000000000000)
               return _x + _y;
          /*atan2(0, 0) is undefined*/
          if(_aix == 0 && _aiy == 0)
               return sorcery::NaN;
          /*_x is positive*/
          /*(1'st and 4'th quad)*/
          if(_ix._y == _aix)
               return necromancer_atan::atand(_y / _x);
          /*_x is negative and _y is positive*/
          /*(2'nd quad)*/
          if(_ix._y > 0x8000000000000000 && _iy._y == _aiy)
               return necromancer_atan::atand(_y / _x) + pi;
          /*_x and _y are both negative*/
          /*(3'rd quad)*/
          return necromancer_atan::atand(_y / _x) - pi;
     }
}

#endif /*_NECROMANCER_ATAN2_*/