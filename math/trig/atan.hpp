/*The Math Necromancer*/

/*Reference:*/
/*https://stackoverflow.com/questions/23047978/how-is-arctan-implemented*/

#ifndef _NECROMANCER_ATAN_
#define _NECROMANCER_ATAN_

#include "../float_class.hpp"
#include "../sign.hpp"

using namespace necromancer_float_class;
using namespace necromancer_sign;

namespace necromancer_atan
{
     static const double
          _atan_inf = 1.57079632679489661;
     static const double
          _atan1 = -3.3333333333331838e-1,
          _atan2 = 1.9999999999755005e-1,
          _atan3 = -1.4285714271334810e-1,
          _atan4 = 1.1111110678749421e-1,
          _atan5 = -9.0909012354005267e-2,
          _atan6 = 7.6922129305867892e-2,
          _atan7 = -6.6658603633512892e-2,
          _atan8 = 5.8773077721790683e-2,
          _atan9 = -5.2392330054601366e-2,
          _atan10 = 4.6739496199158334e-2,
          _atan11 = -4.0926382420509999e-2,
          _atan12 = 3.4067811082715810e-2,
          _atan13 = -2.5826796814492296e-2,
          _atan14 = 1.6978035834594660e-2,
          _atan15 = -9.1845592187222193e-3,
          _atan16 = 3.8559749383656407e-3,
          _atan17 = -1.1640717779912220e-3,
          _atan18 = 2.2302240345710764e-4,
          _atan19 = -2.0258553044340116e-5;
     /*12/18/2023*/
     float atanf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          _i._y &= 0x7fffffff;
          _int32 _y = _i._y;
          float _t1, _t2, _z, _z2, _r;
          /*_x is 0 or NaN*/
          if(_i._y > 0x7f800000 || _i._y == 0)
               return _x;
          /*|_x| > 1.0*/
          if(_i._y > 0x3f800000)
               _i._x = (1.0f/ _i._x);
          /*|_x|^2*/
          _z = _i._x * _i._x;
          /*|_x|^4*/
          _z2 = _z * _z;
          _t1 = _i._x + _i._x * _z * (_atan1 + _z2 * (_atan3 + _z2 * (_atan5 + _z2 *
               (_atan7 + _z2 * (_atan9 + _z2 * (_atan11 + _z2 * (_atan13 + _z2 *
                    (_atan15 + _z2 * (_atan17 + _z2 * _atan19)))))))));
          _t2 = _i._x* _z2 * (_atan2 + _z2 * (_atan4 + _z2 * (_atan6 + _z2 *
               (_atan8 + _z2 * (_atan10 + _z2 * (_atan12 + _z2 * (_atan14 + _z2 *
                    (_atan16 + _z2 * _atan18))))))));
          _r = (_t1 + _t2);
          /*_x > 1.0*/
          if(_y > 0x3f800000)
               _r = _atan_inf - _r;
          return copysign(_r, _x);
     }
     /*12/18/2023*/
     double atand(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          _i._y &= 0x7fffffffffffffff;
          _int64 _y = _i._y;
          double _t1, _t2, _z, _z2, _r;
          if(_i._y > 0x7ff0000000000000 || _i._y == 0)
               return _x;
          /*|_x| > 1.0*/
          if(_i._y > 0x3ff0000000000000)
               _i._x = (1.0 / _i._x);
          /*|_x|^2*/
          _z = _i._x * _i._x;
          /*|_x|^4*/
          _z2 = _z * _z;
          _t1 = _i._x + _i._x * _z * (_atan1 + _z2 * (_atan3 + _z2 * (_atan5 + _z2 *
               (_atan7 + _z2 * (_atan9 + _z2 * (_atan11 + _z2 * (_atan13 + _z2 *
                    (_atan15 + _z2 * (_atan17 + _z2 * _atan19)))))))));
          _t2 = _i._x* _z2 * (_atan2 + _z2 * (_atan4 + _z2 * (_atan6 + _z2 *
               (_atan8 + _z2 * (_atan10 + _z2 * (_atan12 + _z2 * (_atan14 + _z2 *
                    (_atan16 + _z2 * _atan18))))))));
          _r = (_t1 + _t2);
          if(_y > 0x3ff0000000000000)
               _r = _atan_inf - _r;
          return copysign(_r, _x);
     }
     /*12/20/2023*/
     /*Compute the Arctangnet of a 32-bit float _x*/
     float atan(const float& _x)
     {
          return atanf(_x);
     }
     /*12/20/2023*/
     /*Compute the Arctangent of a 64-bit float _x*/
     double atan(const double& _x)
     {
          return atand(_x);
     }
     /*12/20/2023*/
     /*Compute the Arctangent of any number _x*/
     /*(Cast to Double)*/
     template<typename _atan_ty>
     double atan(const _atan_ty& _x)
     {
          return atand(static_cast<double>(_x));
     }
}

#endif /*_NECROMANCER_ATAN_*/