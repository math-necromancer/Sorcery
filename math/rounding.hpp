/*The Math Necromancer*/

#ifndef _NECROMANCER_ROUND_
#define _NECROMANCER_ROUND_

#include "float_class.hpp"

namespace necromancer_round
{
     using namespace necromancer_float_class;

     /*12/11/2023*/
     float ffloorf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          if(_i._f_32._exp <= 0x07f)
               return 0.0;
          /*Mantissa is now either 1.0 or 1.5*/
          _i._y &= 0xffc00000;
          return _i._x;
     }
     /*12/11/2023*/
     int ifloorf(const float& _x)
     {
          return (int) _x;
     }
     /*12/11/2023*/
     double dfloord(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          if(_i._f_64._exp <= 0x3ff)
               return 0.0;
          /*Mantissa is now either 1.0 or 1.5*/
          _i._y &= 0xfff8000000000000;
          return _i._x;
     }
     /*12/11/2023*/
     int ifloord(const double& _x)
     {
          return (int) _x;
     }
     /*12/11/2023*/
     /*Return a 32-bit floating integer of a rounded down _x*/
     float floor(const float& _x)
     {
          return ffloorf(_x);
     }
     /*12/11/2023*/
     /*Return a 64-bit floating integer of a rounded down _x*/
     double floor(const double& _x)
     {
          return dfloord(_x);
     }
     /*12/11/2023*/
     /*Return an integer of a 32-bit float _x rounded down*/
     int ifloor(const float& _x)
     {
          return ifloorf(_x);
     }
     /*12/11/2023*/
     /*Return an integer of a 64-bit float _x rounded down*/
     int ifloor(const double& _x)
     {
          return ifloord(_x);
     }
}

#endif /*_NECROMANCER_ROUND_*/