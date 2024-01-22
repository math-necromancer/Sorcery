/*The Math Necromancer*/

#ifndef _NECROMANCER_SIGN_
#define _NECROMANCER_SIGN_

#include "float_class.hpp"

#ifndef _MATH_SORCERY_
    #error This file won't work if you don't include "math_sorcery.hpp"!
#else
     namespace necromancer_sign
     {
          /*12/24/2023*/
          constexpr int sign_bitf(const float& _x)
          {
               float_32 _i = {_x};
               return _i._f_32._sign;
          }
          /*12/24/2023*/
          constexpr int sign_bitd(const double& _x)
          {
               float_64 _i = {_x};
               return _i._f_64._sign;
          }
          /*12/24/2023*/
          constexpr int signf(const float& _x)
          {
               float_32 _i = {_x};
               return _i._f_32._sign? -1: 1;
          }
          /*12/10/2023*/
          constexpr int signd(const double& _x)
          {
               float_64 _i = {_x};
               return _i._f_64._sign? -1: 1;
          }
          /*12/24/2023*/
          constexpr float copysignf(const float& _x, const float& _y)
          {
               float_32 _ix = {_x};
               float_32 _iy = {_y};
               /*|_x| OR sign_bit(_y)*/
               _ix._y = (_ix._y & 0x7fffffff) | (_iy._y & 0x80000000);
               return _ix._x;
          }
          /*1/17/2024*/
          constexpr double copysignd(const double& _x, const double& _y)
          {
               float_64 _ix = {_x};
               float_64 _iy = {_y};
               /*|_x| OR sign_bit(_y)*/
               _ix._lh._hi = (_ix._lh._hi & 0x7fffffff) | (_iy._lh._hi & 0x80000000);
               return _ix._x;
          }
     }
#endif /*_MATH_SORCERY_*/

#endif /*_NECROMANCER_SIGN_*/