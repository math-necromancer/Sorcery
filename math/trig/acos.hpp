/*The Math Necromancer*/

#ifndef _NECROMANCER_ACOS_
#define _NECROMANCER_ACOS_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "../float_class.hpp"
#include "../roots.hpp"
#include "atan.hpp"

/*#define for pi, used when this file has no incoming definition*/
#ifndef pi
     #define pi 3.1415926535897932384
#endif /*pi*/

namespace necromancer_acos
{
     using namespace necromancer_float_class;

     /*12/20/2023*/
     constexpr float acosf(const float& _x)
     {
          float_32 _i = {_x};
          /*_x is NaN*/
          if(_i._y & 0x7fffffff > 0x7f800000)
               return _x;
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
          /*_x is NaN*/
          if(_i._y & 0x7fffffffffffffff > 0x7ff0000000000000)
               return _x;
          double _r = necromancer_atan::
               atand(necromancer_root::sqrtd(1 - _x * _x) / _x);
          /*_x > 0*/
          if(_i._y < 0x8000000000000000)
               return _r;
          return _r + pi;
     }
}

#endif /*_NECROMANCER_ACOS_*/