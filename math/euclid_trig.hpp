/*The Math Necromancer*/

/*============ C++ Approximations for Trigonometric Functions ============*/
/*This file is made to approximate various trigonometric functions and*/
/* to polish up the functions from cordic.hpp. It generally*/
/*Has precision of over 9 decimal places.*/

/*How it works:*/
/*The angle is reduced due to trig functions being periodic.*/
/*This file has precomputed values. If certain input are detected, they are returned.*/
/*The functions then use various algorithms such as the CORDIC algorithm (sloppy implementation),*/
/*and for small values, the Taylor Series.*/

/*In some cases, the functions have a precision of up to*/
/*8.6736173798840354720e-19, or*/
/*0.0000000000000000008673617379884035472*/

/*If the value is really small, it returns a rough Taylor Series, which is really accurate.*/
/*e.g. euclid_trig::cos(0.01) = 0.9999500004166653*/
/*It actually is: = cos(0.01) = 0.99995000041666527778*/

/*However, at values _x exceptionally close to π/2,*/
/*euclid_trig::tan(_x) becomes very inaccurate!*/
/*e.g. euclid_trig::tan(1.5707129934617561871) = 12115.20281955513*/
/*It actually is: = tan(1.5707129934617561871) = 12000*/

/*π/2 ≈ 1.5707963267948966192*/

#ifndef __EUCLID_TRIG__
#define __EUCLID_TRIG__ 

#include "cordic.hpp"
#include "abs.hpp"
#include "rem.hpp"
#include "float_class.hpp"
#include "sign.hpp"

#define SIN_PI_6 5.000000000000003-01
#define SIN_PI_4 7.07106781186547e-01
#define SIN_PI_3 8.66025403784438e-01

#define COS_PI_6 8.66025403784438e-01
#define COS_PI_4 7.07106781186547e-01
#define COS_PI_3 5.00000000000000e-01

namespace euclid_trig
{
     float asinf(const float& _x);
     double asind(const double& _x);
     long double asinl(const long double& _x);
     float asin(const float& _x);
     double asin(const double& _x);
     long double asin(const long double& _x);
     template<typename _asin_typ>
     double asin(const _asin_typ& _x);

     float acosf(const float& _x);
     double acosd(const double& _x);
     long double acosl(const long double& _x);
     float acos(const float& _x);
     double acos(const double& _x);
     long double acos(const long double& _x);
     template<typename _acos_typ>
     double acos(const _acos_typ& _x);

     float atanf(const float& _x);
     double atand(const double& _x);
     long double atanl(const long double& _x);
     float atan(const float& _x);
     double atan(const double& _x);
     long double atan(const long double& _x);
     template<typename _atan_typ>
     double atan(const _atan_typ& _x);

     float atan2f(const float& _y, const float& _x);
     double atan2d(const double& _y, const double& _x);
     long double atan2l(const long double& _y, const long double& _x);
     float atan2(const float& _y, const float& _x);
     double atan2(const double& _y, const double& _x);
     long double atan2(const long double& _y, const long double& _x);
     template<typename _atan2_typ>
     double atan2(const _atan2_typ& _y, const _atan2_typ& _x);

     float cosf(const float& _x);
     double cosd(const double& _x);
     long double cosl(const long double& _x);
     float cos(const float& _x);
     double cos(const double& _x);
     long double cos(const long double& _x);
     template<typename _cos_typ>
     double cos(const _cos_typ& _x);

     float sinf(const float& _x);
     double sind(const double& _x);
     long double sinl(const long double& _x);
     float sin(const float& _x);
     double sin(const double& _x);
     long double sin(const long double& _x);
     template<typename _sin_typ>
     double sin(const _sin_typ& _x);

     float tanf(const float& _x);
     double tand(const double& _x);
     long double tanl(const long double& _x);
     float tan(const float& _x);
     double tan(const double& _x);
     long double tan(const long double& _x);
     template<typename _tan_typ>
     double tan(const _tan_typ& _x);

     float asinf(const float& _x)
     {
          if(is_nanf(_x) || absolute::absf(_x) > 1)
          {
               return undefined;
          }
          else if(!_x || absolute::absf(_x) == 1)
          {
               return _x * pi_2;
          }
          else if(absolute::absf(_x) == 0.5)
          {
               /*asin(.5) = pi/6*/
               return _x * pi_3;
          }
          else if(absolute::abs(_x) == SIN_PI_4)
          {
               return sign(_x) * pi_4;
          }
          return cordic_arcsin<float>(_x);
     }
     double asind(const double& _x)
     {
          if(is_nan(_x) || absolute::abs(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs(_x) == 1)
          {
               return _x * pi_2;
          }
          else if(absolute::abs(_x) == 0.5)
          {
               /*asin(.5) = pi/6*/
               return _x * pi_3;
          }
          else if(absolute::abs(_x) == SIN_PI_4)
          {
               return sign(_x) * pi_4;
          }
          return cordic_arcsin<double>(_x);
     }
     long double asinl(const long double& _x)
     {
          if(is_nan(_x) || absolute::abs(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs(_x) == 1)
          {
               return _x * pi_2;
          }
          else if(absolute::abs(_x) == 0.5)
          {
               /*asin(.5) = pi/6*/
               return _x * pi_3;
          }
          else if(absolute::abs(_x) == SIN_PI_4)
          {
               return sign(_x) * pi_4;
          }
          return cordic_arcsin<long double>(_x);
     }
     float asin(const float& _x)
     {
          return asinf(_x);
     }
     double asin(const double& _x)
     {
          return asind(_x);
     }
     long double asin(const long double& _x)
     {
          return asinl(_x);
     }
     template<typename _asin_typ>
     double asin(const _asin_typ& _x)
     {
          return asind((double) _x);
     }

     float acosf(const float& _x)
     {
          if(is_nan(_x) || absolute::abs(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs(_x) == 1)
          {
               return -_x * pi_2 + pi_2;
          }
          else if(absolute::abs(_x) == 0.5)
          {
               /*acos(.5) = pi/3*/
               return sign(_x) * pi_3;
          }
          else if(absolute::abs(_x) == COS_PI_4)
          {
               return sign(_x) * pi_4;
          }
          return cordic_arcsin<float>(_x);
     }
     double acosd(const double& _x)
     {
          if(is_nan(_x) || absolute::abs(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs(_x) == 1)
          {
               return -_x * pi_2 + pi_2;
          }
          else if(absolute::abs(_x) == 0.5)
          {
               /*acos(.5) = pi/3*/
               return sign(_x) * pi_3;
          }
          else if(absolute::abs(_x) == COS_PI_4)
          {
               return sign(_x) * pi_4;
          }
          return cordic_arcsin<double>(_x);
     }
     long double acosl(const long double& _x)
     {
          if(is_nan(_x) || absolute::abs(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs(_x) == 1)
          {
               return -_x * pi_2 + pi_2;
          }
          else if(absolute::abs(_x) == 0.5)
          {
               /*acos(.5) = pi/3*/
               return sign(_x) * pi_3;
          }
          else if(absolute::abs(_x) == COS_PI_4)
          {
               return sign(_x) * pi_4;
          }
          return cordic_arcsin<long double>(_x);
     }
     float acos(const float& _x)
     {
          return acosf(_x);
     }
     double acos(const double& _x)
     {
          return acosd(_x);
     }
     long double acos(const long double& _x)
     {
          return acosl(_x);
     }
     template<typename _acos_typ>
     double acos(const _acos_typ& _x)
     {
          return acosd((double) _x);
     }

     float atanf(const float& _x)
     {
          float _r = _x;
          float mult = 1.0f;
          if(_r < 0.0f)
          {
               _r *= -1.0f;
               mult = -1.0f;
          }
          if(is_inf(_r))
          {
               return pi_2 * mult;
          }
          else if(is_nan(_r))
          {
               return _r;
          }
          else if(_r == 1.0f || _r == 0.0f)
          {
               return pi_4 * _r * mult;
          }
          else if(_r <= 0.07f)
          {
               /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to _r - (_r^3 / 3) + (_r ^ 5 / 5)...*/
               float _r3 = _r * _r * _r;
               float _r5 = _r3 * _r * _r;
               float _r7 = _r5 * _r * _r;
               return _r - (_r3 / 3) + (_r5 / 5) - (_r7 / 7);
          }
          return (float) cordic::atanf(_x);
     }
     double atand(const double& _x)
     {
          double _r = _x;
          double mult = 1.0;
          if(_r < 0.0)
          {
               _r *= -1.0;
               mult = -1.0;
          }
          if(is_inf(_r))
          {
               return pi_2 * mult;
          }
          else if(is_nan(_r))
          {
               return _r;
          }
          else if(_r == 1.0 || _r == 0.0)
          {
               return pi_4 * _r * mult;
          }
          else if(_r <= 0.07)
          {
               /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to _r - (_r^3 / 3) + (_r ^ 5 / 5)...*/
               double _r3 = _r * _r * _r;
               double _r5 = _r3 * _r * _r;
               double _r7 = _r5 * _r * _r;
               return _r - (_r3 / 3) + (_r5 / 5) - (_r7 / 7);
          }
          return (double) cordic::atand(_x);
     }
     long double atanl(const long double& _x)
     {
          long double _r = _x;
          int mult = 1.0l;
          if(_r < 0.0l)
          {
               _r *= -1.0l;
               mult = -1;
          }
          if(is_inf(_r))
          {
               return pi_2 * mult;
          }
          else if(is_nan(_r))
          {
               return _r;
          }
          else if(_r == 1.0l || _r == 0.0l)
          {
               return pi_4 * _r * mult;
          }
          else if(_r <= 0.07l)
          {
               /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to _r - (_r^3 / 3) + (_r ^ 5 / 5)...*/
               long double _r3 = _r * _r * _r;
               long double _r5 = _r3 * _r * _r;
               long double _r7 = _r5 * _r * _r;
               return _r - (_r3 / 3) + (_r5 / 5) - (_r7 / 7);
          }
          return cordic::atanl(_x);
     }
     float atan(const float& _x)
     {
          return atanf(_x);
     }
     double atan(const double& _x)
     {
          return atand(_x);
     }
     long double atan(const long double& _x)
     {
          return atanl(_x);
     }
     template<typename _atan_typ>
     double atan(const _atan_typ& _x)
     {
          return atand((double) _x);
     }

     float atan2f(const float& _y, const float& _x)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          int mult = 1;
          float _x1 = _x;
          float _y1 = _y;
          if(_x < 0 ^ _y < 0)
          {
               _x1 *= -1;
               _y1 *= -1;
               mult = -1;
          }
          else if(is_inf(_x1))
          {     
               return is_inf(_y1)? undefined: pi_2 * mult;
          }
          else if(_x1 == _y1)
          {
               return pi_4;
          }
          return cordic::atan2f(_y1, _x1);
     }
     double atan2d(const double& _y, const double& _x)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          int mult = 1;
          double _x1 = _x;
          double _y1 = _y;
          if(_x < 0 ^ _y < 0)
          {
               _x1 *= -1;
               _y1 *= -1;
               mult = -1;
          }
          else if(is_inf(_x1))
          {     
               return is_inf(_y1)? undefined: pi_2 * mult;
          }
          else if(_x1 == _y1)
          {
               return pi_4;
          }
          return cordic::atan2d(_y1, _x1);
     }
     long double atan2l(const long double& _y, const long double& _x)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          int mult = 1;
          long double _x1 = _x;
          long double _y1 = _y;
          if(_x < 0 ^ _y < 0)
          {
               _x1 *= -1;
               _y1 *= -1;
               mult = -1;
          }
          else if(is_inf(_x1))
          {     
               return is_inf(_y1)? undefined: pi_2 * mult;
          }
          else if(_x1 == _y1)
          {
               return pi_4;
          }
          return cordic::atan2l(_y1, _x1);
     }
     float atan2(const float& _y, const float& _x)
     {
          return atan2f(_y, _x);
     }
     double atan2(const double& _y, const double& _x)
     {
          return atan2d(_y, _x);
     }
     long double atan2(const long double& _y, const long double& _x)
     {
          return atan2l(_y, _x);
     }
     template<typename _atan2_typ>
     double atan2(const _atan2_typ& _y, const _atan2_typ& _x)
     {
          return atan2d((double) _y, (double) _x);
     }

     float cosf(const float& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          float _r = necromancer_rem::rem(_x, pi);
          if(_r < 0.0f)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0f;
          }
          if(_r == 0.0f)
          {
               return 1;
          }
          else if(_r <= 0.07f)
          {
              /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^2 / 2!) + (_r^4 / 4!)...*/
               float _r2 = _r * _r;
               float _r4 = _r2 * _r2;
               float _r6 = _r4 * _r2;
               return 1.0f - (_r2 / 2) + (_r4 / 24) - (_r6 / 720);
          }
          /*Precomputed Vaues*/
          if(_r == pi_6)
          {
               return COS_PI_6;
          }
          else if(_r == pi_4)
          {
               return COS_PI_4;
          }
          else if(_r == pi_3)
          {
               return COS_PI_3;
          }
          return cordic::cosf(_r);
     }
     double cosd(const double& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          double _r = necromancer_rem::rem(_x, pi);
          if(_r < 0.0)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0;
          }
          if(_r == 0.0)
          {
               return 1;
          }
          if(_r <= 0.07)
          {
               /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^2 / 2!) + (_r^4 / 4!)...*/
               double _r2 = _r * _r;
               double _r4 = _r2 * _r2;
               double _r6 = _r4 * _r2;
               return 1.0 - (_r2 / 2) + (_r4 / 24) - (_r6 / 720);
          }
          /*Precomputed Vaues*/
          if(_r == pi_6)
          {
               return COS_PI_6;
          }
          else if(_r == pi_4)
          {
               return COS_PI_4;
          }
          else if(_r == pi_3)
          {
               return COS_PI_3;
          }
          return cordic::cosd(_r);

     }
     long double cosl(const long double& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          long double _r = necromancer_rem::rem(_x, pi);
          if(_r < 0.0l)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0l;
          }
          if(_r == 0.0l)
          {
               return 1;
          }
          if(_r <= 0.07l)
          {
               /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^2 / 2!) + (_r^4 / 4!)...*/
               long double _r2 = _r * _r;
               long double _r4 = _r2 * _r2;
               long double _r6 = _r4 * _r2;
               return 1.0l - (_r2 / 2) + (_r4 / 24) - (_r6 / 720);
          }
          /*Precomputed Vaues*/
          if(_r == pi_6)
          {
               return COS_PI_6;
          }
          else if(_r == pi_4)
          {
               return COS_PI_4;
          }
          else if(_r == pi_3)
          {
               return COS_PI_3;
          }
          return cordic::cosl(_r);

     }
     float cos(const float& _x)
     {
          return cosf(_x);
     }
     double cos(const double& _x)
     {
          return cosd(_x);
     }
     long double cos(const long double& _x)
     {
          return cosl(_x);
     }
     template<typename _cos_typ>
     double cos(const _cos_typ& _x)
     {
          return cosd((double) _x);
     }
     /*Sine doesn't want to work right now D:*/
     float sinf(const float& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          float _r = necromancer_rem::rem(_x, tau);
          if(_r > pi)
          {
               _r -= tau;
          }
          else if(_r < -pi)
          {
               _r += tau;
          }
          if(_r <= 0.07f || _r >= -0.07f)
          {
               /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^3 / 3!) + (_r^5 / 5!)...*/
               float _r3 = _r * _r * _r;
               float _r5 = _r3 * _r * _r ;
               float _r7 = _r5 * _r * _r;
               return _r - (_r3 / 6) + (_r5 / 120) - (_r7 / 5040);
          }
          /*Precomputed Vaues*/
          if(_r == pi_6)
          {
               return SIN_PI_6;
          }
          else if(_r == pi_4)
          {
               return SIN_PI_4;
          }
          else if(_r == pi_3)
          {
               return SIN_PI_3;
          }
          return cordic::sinf(_r);
     }
     double sind(const double& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          double _r = necromancer_rem::rem(_x, tau);
          if(_r > pi)
          {
               _r -= tau;
          }
          else if(_r < -pi)
          {
               _r += tau;
          }
          if(_r <= 0.07 || _r >= -0.07)
          {
               /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^3 / 3!) + (_r^5 / 5!)...*/
               double _r3 = _r * _r * _r;
               double _r5 = _r3 * _r * _r ;
               double _r7 = _r5 * _r * _r;
               return _r - (_r3 / 6) + (_r5 / 120) - (_r7 / 5040);
          }
          /*Precomputed Vaues*/
          if(_r == pi_6)
          {
               return SIN_PI_6;
          }
          else if(_r == pi_4)
          {
               return SIN_PI_4;
          }
          else if(_r == pi_3)
          {
               return SIN_PI_3;
          }
          return cordic::sind(_r);
     }
     long double sinl(const long double& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          double _r = necromancer_rem::rem(_x, tau);
          if(_r > pi)
          {
               _r -= tau;
          }
          else if(_r < -pi)
          {
               _r += tau;
          }
          if(_r <= 0.07l || _r >= -0.07l)
          {
               /*If _r is small enough, you can just return*/
               /*The first 4 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^3 / 3!) + (_r^5 / 5!)...*/
               long double _r3 = _r * _r * _r;
               long double _r5 = _r3 * _r * _r ;
               long double _r7 = _r5 * _r * _r;
               return _r - (_r3 / 6) + (_r5 / 120) - (_r7 / 5040);
          }
          /*Precomputed Vaues*/
          if(_r == pi_6)
          {
               return SIN_PI_6;
          }
          else if(_r == pi_4)
          {
               return SIN_PI_4;
          }
          else if(_r == pi_3)
          {
               return SIN_PI_3;
          }
          return cordic::sinl(_r);
     }
     float sin(const float& _x)
     {
          return sinf(_x);
     }
     double sin(const double& _x)
     {
          return sind(_x);
     }
     long double sin(const long double& _x)
     {
          return sinl(_x);
     }
     template<typename _sin_typ>
     double sin(const _sin_typ& _x)
     {
          return sind((double) _x);
     }

     float tanf(const float& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          float _r = necromancer_rem::rem(_x, pi);
          if(_r > pi_2)
          {
               _r -= pi;
               _r *= -1;
          }
          if(_r <= 0.07f || _r >= -0.07f)
          {
               /*2 terms of sin(x) Taylor Series / 2 terms*/
               /*of cos(x) Taylor Series*/
               /*Very good approximation*/
               return (_r - (_r * _r * _r / 6)) / (1 - (_r * _r / 2));
          }
          return cordic::tanf(_r);
     }
     double tand(const double& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          double _r = necromancer_rem::rem(_x, pi);
          if(_r > pi_2)
          {
               _r -= pi;
               _r *= -1;
          }
          if(_r <= 0.07f || _r >= -0.07f)
          {
               /*2 terms of sin(x) Taylor Series / 2 terms*/
               /*of cos(x) Taylor Series*/
               /*Very good approximation*/
               return (_r - (_r * _r * _r / 6)) / (1 - (_r * _r / 2));
          }
          return cordic::tand(_r);
     }
     long double tanl(const long double& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          long double _r = necromancer_rem::rem(_x, pi);
          if(_r > pi_2)
          {
               _r -= pi;
               _r *= -1;
          }
          if(_r <= 0.07f || _r >= -0.07f)
          {
               /*2 terms of sin(x) Taylor Series / 2 terms*/
               /*of cos(x) Taylor Series*/
               /*Very good approximation*/
               return (_r - (_r * _r * _r / 6)) / (1 - (_r * _r / 2));
          }
          return cordic::tand(_r);
     }
     float tan(const float& _x)
     {
          return tanf(_x);
     }
     double tan(const double& _x)
     {
          return tand(_x);
     }
     long double tan(const long double& _x)
     {
          return tanl(_x);
     }
     template<typename _tan_typ>
     double tan(const _tan_typ& _x)
     {
          return tand((double) _x);
     }
}

#endif /*__EUCLID_TRIG__*/