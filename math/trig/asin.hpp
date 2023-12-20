/*The Math Necromancer*/

#ifndef _NECROMANCER_ASIN_
#define _NECROMANCER_ASIN_

#include "../float_class.hpp"
#include "../roots.hpp"
#include "atan.hpp"

namespace necromancer_asin
{
     using namespace necromancer_float_class;
     /*12/18/2023*/
     float asinf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          _i._y &= 0x7fffffff;
          float _r;
          /*_x is 0 or NaN*/
          if(_i._y > 0x7f800000 || _i._y == 0)
               return _x;
          /*|_x| > 1.0*/
          if(_i._y > 0x3f800000)
               return NaNf;
          _r = necromancer_atan::
               atanf(_x / necromancer_root::sqrtf(1 - _x * _x));
          return copysign(_r, _x);
     }
     /*12/18/2023*/
     double asind(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          _i._y &= 0x7fffffffffffffff;
          float _r;
          /*_x is 0 or NaN*/
          if(_i._y > 0x7ff0000000000000 || _i._y == 0)
               return _x;
          /*|_x| > 1.0*/
          if(_i._y > 0x3ff0000000000000)
               return NaNf;
          _r = necromancer_atan::
               atand(_x / necromancer_root::sqrtd(1 - _x * _x));
          return copysign(_r, _x);
     }
     /*12/20/2023*/
     /*Compute the Arcsine of a 32-bit float _x*/
     float asin(const float& _x)
     {
          return asinf(_x);
     }
     /*12/20/2023*/
     /*Compute the Arcsine of a 64-bit float _x*/
     double asin(const double& _x)
     {
          return asind(_x);
     }
     /*12/20/2023*/
     /*Compute the Arcsine of any number _x*/
     /*(Cast to Double)*/
     template<typename _asin_ty>
     double asin(const _asin_ty& _x)
     {
          return asind(static_cast<double>(_x));
     }
}

#endif /*_NECROMANCER_ASIN_*/