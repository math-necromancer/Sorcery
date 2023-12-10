/*The Math Necromancer*/

#ifndef _NECROMANCER_SIGN_
#define _NECROMANCER_SIGN_

#include "float_class.hpp"

namespace necromancer_sign
{
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
}

#endif /*_NECROMANCER_SIGN_*/