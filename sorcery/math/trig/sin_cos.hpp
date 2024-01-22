/*The Math Necromancer*/

#ifndef _NECROMANCER_SIN_COS_
#define _NECROMANCER_SIN_COS_

#ifndef _MATH_SORCERY_
     #error This file won't work if you don't include "math_sorcery.hpp"!
#else
     #include "../float_class.hpp"
     #include "../sign.hpp"
     #include "../rem.hpp"
     /*Courtesy of fdlibm for these constants*/
     /* ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunSoft, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice 
     * is preserved.
     * ====================================================
     */

     const static double
          _sin1 = -1.6666666666666632e-01,
          _sin2 = 8.3333333333224894e-03,
          _sin3 = -1.9841269829857949e-04,
          _sin4 = 2.7557313707070067e-06,
          _sin5 = -2.5050760253406863e-08,
          _sin6 = 1.5896909952115501e-10;
     const static double
          _cos1 = 4.1666666666666601e-02,
          _cos2 = -1.3888888888874109e-03,
          _cos3 = 2.4801587289476729e-05,
          _cos4 = -2.7557314351390663e-07,
          _cos5 = 2.0875723212981748e-09,
          _cos6 = -1.1359647557788194e-11;
     namespace necromancer_sin_cos
     {
          /*1/17/2024*/
          /*We assume that |_x| is within pi/4*/
          float sinf_in_pio4(const float& _x)
          {
               float_32 _i = {_x};
               _int32 _sx = _i._y & 0x80000000;
               float _z, _r;
               /*|_x|*/
               _i._y &= 0x7fffffff;
               /*|_x| < 2^-8, we return _x as it's sin(x) in single precision*/
               if(_i._y <= 0x3b800000)
                    return _x;
               _z = _i._x * _i._x;
               _r = _i._x + _i._x * _z * (_sin1 + _z * (_sin2 + _z * (_sin3 + _z *
                    (_sin4 + _z * (_sin5 + _z * _sin6)))));
               /*sin(-x) = -sin(x)*/
               _i._y |= _sx;
               return _i._x;
          }
          /*12/21/2023*/
          /*We assume that |_x| is within pi/4*/
          double sind_in_pio4(const double& _x)
          {
               float_64 _i = {_x};
               _int32 _sx = _i._y & 0x80000000;
               double _z, _r;
               /*|_x|*/
               _i._y &= 0x7fffffffffffffff;
               /*|_x| < 2^-16, we return _x as it's sin(x) in double precision*/
               if(_i._y < 0x3ef0000000000000)
                    return _x;
               _z = _i._x * _i._x;
               _r = _i._x + _i._x * _z * (_sin1 + _z * (_sin2 + _z * (_sin3 + _z *
                    (_sin4 + _z * (_sin5 + _z * _sin6)))));
               /*sin(-x) = -sin(x)*/
               _i._y |= _sx;
               return _i._y;
          }
          /*12/21/2023*/
          /*We assume that |_x| is within pi/4*/
          float cosf_in_pio4(const float& _x)
          {
               float_32 _i = {_x};
               float _z, _r;
               /*|_x|*/
               _i._y &= 0x7fffffff;
               _z = _i._x * _i._x;
               _r = 1.0f + _z * (0.5 + _z * (_cos1 + _z * (_cos2 + _z *
                    (_cos3 + _z * (_cos4 + _z * (_cos5 + _z * _cos6))))));
               /*No need for copysign because cos(-x) = cos(x)*/
               return _r;
          }
          /*12/21/2023*/
          /*We assume that |_x| is within pi/4*/
          double cosd_in_pio4(const double& _x)
          {
               float_64 _i = {_x};
               double _z, _r;
               /*|_x|*/
               _i._y &= 0x7fffffffffffffff;
               _z = _i._x * _i._x;
               _r = 1.0f + _z * (0.5 + _z * (_cos1 + _z * (_cos2 + _z *
                    (_cos3 + _z * (_cos4 + _z * (_cos5 + _z * _cos6))))));
               /*No need for copysign because cos(-x) = cos(x)*/
               return _r;
          }
     }
#endif /*_MATH_SORCERY_*/
#endif /*_NECROMANCER_SIN_COS_*/
