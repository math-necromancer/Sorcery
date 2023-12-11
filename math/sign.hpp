/*The Math Necromancer*/

#ifndef _NECROMANCER_SIGN_
#define _NECROMANCER_SIGN_

#include "float_class.hpp"

namespace necromancer_sign
{
     using namespace necromancer_float_class;
     /*12/10/2023*/
     int sign_bitf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          return _i._f_32._sign;
     }
     /*12/10/2023*/
     int sign_bitd(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          return _i._f_64._sign;
     }
     /*12/10/2023*/
     /*Return a 32-bit float's sign bit*/
     int sign_bit(const float& _x)
     {
          return sign_bitf(_x);
     }
     /*12/10/2023*/
     /*Return a 64-bit float's sign bit*/
     int sign_bit(const double& _x)
     {
          return sign_bitd(_x);
     }

     /*12/10/2023*/
     int signf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          return _i._f_32._sign? -1: 1;
     }
     /*12/10/2023*/
     int signd(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          return _i._f_64._sign? -1: 1;
     }
     /*12/10/2023*/
     /*Return the +- 1, where |_x| * (+- 1) = _x*/
     int sign(const float& _x)
     {
          return signf(_x);
     }
     /*12/10/2023*/
     /*Return the +- 1, where |_x| * (+- 1) = _x*/
     int sign(const double& _x)
     {
          return signd(_x);
     }

     /*12/9/2023*/
     float copysignf(const float& _x, const float& _y)
     {
          float_32 _ix, _iy;
          _ix._x = _x;
          _iy._x = _y;
          /*|_x| OR sign_bit(_y)*/
          _ix._y = (_ix._y & 0x7fffffff) | (_iy._y & 0x80000000);
          return _ix._x;
     }
     /*12/9/2023*/
     double copysignd(const double& _x, const double& _y)
     {
          float_64 _ix, _iy;
          _ix._x = _x;
          _iy._x = _y;
          /*|_x| OR sign_bit(_y)*/
          _ix._y = (_ix._y & 0x7fffffffffffffff) | (_iy._y & 0x8000000000000000);
          return _ix._x;
     }
     /*12/9/2023*/
     /*Return a 32-bit float with a magnitude _x and a sign _y*/
     float copysign(const float& _x, const float& _y)
     {
          return copysignf(_x, _y);
     }
     /*12/9/2023*/
     /*Return a 64-bit float with a magnitude _x and a sign _y*/
     double copysign(const double& _x, const double& _y)
     {
          return copysignd(_x, _y);
     }
}

#endif /*_NECROMANCER_SIGN_*/