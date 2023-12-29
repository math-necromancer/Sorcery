/*The Math Necromancer*/

/*Reference:*/
/*https://stackoverflow.com/questions/23047978/how-is-arctan-implemented*/

#ifndef _NECROMANCER_ATAN_
#define _NECROMANCER_ATAN_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "../float_class.hpp"
#include "../sign.hpp"

namespace necromancer_atan
{
     using namespace necromancer_float_class;
     
     static const double
          /*atan(inf) = pi/2*/
          _atan_inf = 1.57079632679489661;
     /*Minimax coefficients for a polynomial approximation*/
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
     /*12/24/2023*/
     constexpr float atanf(const float& _x)
     {
          float_32 _i = {_x};
          /*|_x|*/
          _i._y &= 0x7fffffff;
          _int32 _y = _i._y;
          /*_x is 0 or NaN*/
          if(_i._y > 0x7f800000 || _i._y == 0)
               return _x;
          /*|_x| > 1.0*/
          if(_i._y > 0x3f800000)
               _i._x = (1.0f/ _i._x);
          /*|_x|^2*/
          float _z = _i._x * _i._x;
          /*|_x|^4*/
          float _z2 = _z * _z;
          float _t1 = _i._x + _i._x * _z * (_atan1 + _z2 * (_atan3 + _z2 * (_atan5 + _z2 *
               (_atan7 + _z2 * (_atan9 + _z2 * (_atan11 + _z2 * (_atan13 + _z2 *
                    (_atan15 + _z2 * (_atan17 + _z2 * _atan19)))))))));
          float _t2 = _i._x* _z2 * (_atan2 + _z2 * (_atan4 + _z2 * (_atan6 + _z2 *
               (_atan8 + _z2 * (_atan10 + _z2 * (_atan12 + _z2 * (_atan14 + _z2 *
                    (_atan16 + _z2 * _atan18))))))));
          float _r = (_t1 + _t2);
          /*Special case if |_x| is greater than 1*/
          if(_y > 0x3f800000)
               /*atan(x) = atan(inf) - atan(1/x)*/
               _r = _atan_inf - _r;
          return necromancer_sign::
               copysignf(_r, _x);
     }
     /*12/24/2023*/
     constexpr double atand(const double& _x)
     {
          float_64 _i = {_x};
          /*|_x|*/
          _i._y &= 0x7fffffffffffffff;
          _int64 _y = _i._y;
          /*_x is 0 or NaN*/
          if(_i._y > 0x7ff0000000000000 || _i._y == 0)
               return _x;
          /*|_x| > 1.0*/
          if(_i._y > 0x3ff0000000000000)
               _i._x = (1.0 / _i._x);
          /*|_x|^2*/
          double _z = _i._x * _i._x;
          /*|_x|^4*/
          double _z2 = _z * _z;
          double _t1 = _i._x + _i._x * _z * (_atan1 + _z2 * (_atan3 + _z2 * (_atan5 + _z2 *
               (_atan7 + _z2 * (_atan9 + _z2 * (_atan11 + _z2 * (_atan13 + _z2 *
                    (_atan15 + _z2 * (_atan17 + _z2 * _atan19)))))))));
          double _t2 = _i._x* _z2 * (_atan2 + _z2 * (_atan4 + _z2 * (_atan6 + _z2 *
               (_atan8 + _z2 * (_atan10 + _z2 * (_atan12 + _z2 * (_atan14 + _z2 *
                    (_atan16 + _z2 * _atan18))))))));
          double _r = (_t1 + _t2);
          /*Special case if |_x| is greater than 1*/
          if(_y > 0x3ff0000000000000)
               /*atan(x) = atan(inf) - atan(1/x)*/
               _r = _atan_inf - _r;
          return necromancer_sign::
               copysignd(_r, _x);
     }
}

#endif /*_NECROMANCER_ATAN_*/