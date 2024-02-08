/*The Math Necromancer*/

/*Compute the trigonometric arc tangent of _x*/
/*Range Reduction:*/
/*   If |_x| > 1, use the reciprocal of _x (1 / _x). This works because*/
/*   of the identity atan(x) = sign(x) * pi / 2 + atan(1 / x)*/
/*Then, just use a polynomial to approximate atan(_x) for 0 < |_x| <= 1*/
/*The polynomial is such*/
/*         3                5                  39          */
/* _x + (_x * _atan1) + (_x * _atan2) + ... (_x  * _atan19)*/
/*   ez :)   */


#ifndef _NECROMANCER_ATAN_
#define _NECROMANCER_ATAN_

#ifndef _MATH_SORCERY_
     #error This file won't work if you don't include "math_sorcery.hpp"!
#else
     #include "../float_class.hpp"
     #include "../sign.hpp"
     namespace necromancer_atan
     {
          static const double
               /*atan(inf) = pi/2*/
               _atan_inf[] = {1.57079632679489661, -1.57079632679489661};
          /*Minimax coefficients for a polynomial approximation*/
          /*From referenced stackoverflow post*/
          /*https://stackoverflow.com/questions/23047978/how-is-arctan-implemented*/
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
               /*signbit(_x) << 31*/
               _int32 _sx = (_i._y >> 31) & 1;
               /*|_x|*/
               _i._y &= 0x7fffffff;
               _int32 _y = _i._y;
               /*_x is 0 or NaN*/
               if(_i._y > 0x7f800000 || _i._y == 0)
                    return _x;
               /*|_x| > 1.0*/
               if(_i._y > 0x3f800000)
                    _i._x = (1.0f / _i._x);
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
               _i._x = (_t1 + _t2);
               _i._y |= _sx;
               /*Special case if |_x| is greater than 1*/
               if(_y > 0x3f800000)
                    /*atan(x) = atan(inf) - atan(1/x)*/
                    _i._x = _atan_inf[_sx] - _i._x;
               return _i._x;
          }
          /*12/24/2023*/
          constexpr double atand(const double& _x)
          {
               float_64 _i = {_x};
               /*signbit(_x) << 31*/
               _int32 _sx = (_i._lh._hi >> 31) & 1;
               /*|_x|*/
               _i._lh._hi &= 0x7fffffff;
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
               _i._x = (_t1 + _t2);
               _i._lh._hi |= _sx;
               /*Special case if |_x| is greater than 1*/
               if(_y > 0x3ff0000000000000)
                    /*atan(x) = atan(inf) - atan(1/x)*/
                    _i._x = _atan_inf[_sx] - _i._x;
               return _i._x;
          }
     }
#endif /*_MATH_SORCERY_*/
#endif /*_NECROMANCER_ATAN_*/