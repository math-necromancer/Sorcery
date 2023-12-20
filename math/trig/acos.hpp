/*The Math Necromancer*/

#ifndef _NECROMANCER_ACOS_
#define _NECROMANCER_ACOS_

#include "../float_class.hpp"
#include "../roots.hpp"
#include "atan.hpp"

namespace necromancer_acos
{
     using namespace necromancer_float_class;

     /*12/20/2023*/
     float acosf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          float _r;
          /*_x is NaN*/
          if(_i._y & 0x7fffffff > 0x7f800000)
               return _x;
          _r =  necromancer_atan::
               atanf(necromancer_root::sqrtf(1 - _x * _x) / _x);
          /*_x > 0*/
          if(_i._y < 0x80000000)
               return _r;
          return _r + pi;
     }
     /*12/20/2023*/
     double acosd(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          double _r;
          /*_x is NaN*/
          if(_i._y & 0x7fffffffffffffff > 0x7ff0000000000000)
               return _x;
          _r = necromancer_atan::
               atand(necromancer_root::sqrtd(1 - _x * _x) / _x);
          /*_x > 0*/
          if(_i._y < 0x8000000000000000)
               return _r;
          return _r + pi;
     }
     /*12/20/2023*/
     /*Compute the Arccosine of a 32-bit float _x*/
     float acos(const float& _x)
     {
          return acosf(_x);
     }
     /*12/20/2023*/
     /*Compute the Arccosine of a 64-bit float _x*/
     double acos(const double& _x)
     {
          return acosd(_x);
     }
     /*12/20/2023*/
     /*Compute the Arccosine of any number _x*/
     /*(Cast to Double)*/
     template<typename _acos_ty>
     double acos(const _acos_ty& _x)
     {
          return acosd(static_cast<double>(_x));
     }
}

#endif /*_NECROMANCER_ACOS_*/