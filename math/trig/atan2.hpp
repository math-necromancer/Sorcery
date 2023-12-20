/*The Math Necromancer*/

#ifndef _NECROMANCER_ATAN2_
#define _NECROMANCER_ATAN2_

#include "../float_class.hpp"
#include "atan.hpp"

namespace necromancer_atan2
{
     using namespace necromancer_float_class;
     /*12/20/2023*/
     float atan2f(const float& _y, const float& _x)
     {
          float_32 _ix, _iy;
          _ix._x = _x;
          _iy._x = _y;
          _int32 _aix, _aiy;
          _aix = _ix._y & 0x7fffffff;
          _aiy = _iy._y & 0x7fffffff;
          /*If _x or _y is NaN*/
          if(_aix > 0x7f800000 || _aiy > 0x7f800000)
               return _x + _y;
          if(_aix == 0 && _aiy == 0)
               return NaNf;
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
          if(_ix._y > 0x80000000 && _iy._y > 0x80000000)
               return necromancer_atan::atanf(_y / _x) - pi;
     }
     /*12/20/2023*/
     double atan2d(const double& _y, const double& _x)
     {
          float_64 _ix, _iy;
          _ix._x = _x;
          _iy._x = _y;
          _int64 _aix, _aiy;
          _aix = _ix._y & 0x7fffffffffffffff;
          _aiy = _iy._y & 0x7fffffffffffffff;
          /*If _x of _y is NaN*/
          if(_aix > 0x7ff0000000000000 || _aiy > 0x7ff0000000000000)
               return _x + _y;
          if(_aix == 0 && _aiy == 0)
               return NaN;
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
          if(_ix._y > 0x8000000000000000 && _iy._y > 0x8000000000000000)
               return necromancer_atan::atand(_y / _x) - pi;
     }
     /*12/20/2023*/
     /*Compute the arctangent of a ratio of 32-bit floats _y and _x*/
     /*(Analyzes Quadrants)*/
     float atan2(const float& _y, const float& _x)
     {
          return atan2f(_y, _x);
     }
     /*12/20/2023*/
     /*Compute the arctangent of a ratio of 64-bit floats _y and _x*/
     /*(Analyzes Quadrants)*/
     double atan2(const double& _y, const double& _x)
     {
          return atan2d(_y, _x);
     }
     /*12/20/2023*/
     /*Compute the arctangent of a ratio of numbers _y and _x*/
     /*(Analyzes Quadrants, Cast to Double)*/
     template<typename _atan2_ty>
     double atan2(const _atan2_ty& _y, const _atan2_ty& _x)
     {
          return atan2d(static_cast<double>(_y), static_cast<double>(_x));
     }
}

#endif /*_NECROMANCER_ATAN2_*/