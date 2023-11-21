/*The Math Necromancer*/

/*============ C++ Approximations for Trigonometric Functions ============*/
/*This file is made to polish up the functions from cordic.hpp. It generally*/
/*Has precision of over 6 decimal places.*/

/*How it works:*/
/*The angle is reduced due to trig functions being periodic.*/
/*This file has precomputed values. If certain input are detected, they are returned.*/
/*The functions then use various algorithms such as the CORDIC algorithm (sloppy implementation),*/
/*and for small values, the Taylor Series.*/

/*If the value is really small, it returns a rough Taylor Series, which is really accurate.*/
/*e.g. euclid_trig::cos(0.01) = 0.9999500004166667*/
/*It actually is: = cos(0.01) = 0.99995000041666527778*/

/*However, at values _x exceptionally close to π/2,*/
/*euclid_trig::tan(_x) becomes very inaccurate!*/
/*e.g. euclid_trig::tan(1.5707129934617561871) = 12115.20281955513*/
/*It actually is: = tan(1.5707129934617561871) = 12000*/

/*π/2 ≈ 1.5707963267948966192*/

#ifndef __EUCLID_TRIG__
#define __EUCLID_TRIG__

#define SIN_PI_6 0.500000000000000
#define SIN_PI_4 0.707106781186547
#define SIN_PI_3 0.866025403784438
#define COS_PI_6 0.866025403784438
#define COS_PI_4 0.707106781186547
#define COS_PI_3 0.500000000000000  

#include "cordic.hpp"
#include "abs.hpp"
#include "rem.hpp"
#include "number_classifications.hpp"

namespace euclid_trig
{
     float atanf(const float& _x)
     {
          float _r = _x;
          float mult = 1.0f;
          if(_r < 0.0f)
          {
               _r *= -1.0f;
               mult = -1.0f;
          }
          if(is_infinite(_r))
          {
               return pi_2 * mult;
          }
          else if(is_nan(_r))
          {
               return _r;
          }
          else if(_r <= 0.07f)
          {
               /*If _r is small enough, you can just return*/
               /*The first 3 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to _r - (_r^3 / 3) + (_r ^ 5 / 5)*/
               float _r3 = _r * _r * _r;
               float _r5 = _r3 * _r * _r;
               return _r - (_r3 / 3) + (_r5 / 5);
          }
          else if(_r = 1.0f)
          {
               return pi_4 * mult;
          }
          return (float) cordic::atan2f(_x, 1);
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
          if(is_infinite(_r))
          {
               return pi_2 * mult;
          }
          else if(is_nan(_r))
          {
               return _r;
          }
          else if(_r <= 0.07)
          {
               /*If _r is small enough, you can just return*/
               /*The first 3 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to _r - (_r^3 / 3) + (_r ^ 5 / 5)*/
               double _r3 = _r * _r * _r;
               double _r5 = _r3 * _r * _r;
               return _r - (_r3 / 3) + (_r5 / 5);
          }
          else if(_r = 1.0)
          {
               return pi_4 * mult;
          }
          return (double) cordic::atan2d(_x, 1);
     }
     long double atanl(const long double& _x)
     {
          long double _r = _x;
          long double mult = 1.0l;
          if(_r < 0.0l)
          {
               _r *= -1.0l;
               mult = -1.0l;
          }
          if(is_infinite(_r))
          {
               return pi_2 * mult;
          }
          else if(is_nan(_r))
          {
               return _r;
          }
          else if(_r <= 0.07l)
          {
               /*If _r is small enough, you can just return*/
               /*The first 3 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to _r - (_r^3 / 3) + (_r ^ 5 / 5)*/
               long double _r3 = _r * _r * _r;
               long double _r5 = _r3 * _r * _r;
               return _r - (_r3 / 3) + (_r5 / 5);
          }
          else if(_r = 1.0l)
          {
               return pi_4 * mult;
          }
          return cordic::atan2l(_x, 1);
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
     float cosf(const float& _x)
     {
          float _r = necromancer_rem::rem(_x, pi);
          if(is_nan(_r) || is_infinite(_r))
          {
               return undefined;
          }
          else if(_r < 0.0f)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0f;
          }
          if(_r - pi_2 <= 0.0667f)
          {
              /*If _r is small enough, you can just return*/
               /*The first 3 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^2 / 2!) + (_r^4 / 4!)*/
               long double _r2 = _r * _r;
               long double _r4 = _r2 * _r2;
               return 1 - (_r2 / 2) + (_r4 / 24);
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
          double _r = necromancer_rem::rem(_x, pi);
          if(is_nan(_r) || is_infinite(_r))
          {
               return undefined;
          }
          else if(_r < 0.0)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0;
          }
          if(_r - pi_2 <= 0.0667)
          {
               /*If _r is small enough, you can just return*/
               /*The first 3 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^2 / 2!) + (_r^4 / 4!)*/
               long double _r2 = _r * _r;
               long double _r4 = _r2 * _r2;
               return 1 - (_r2 / 2) + (_r4 / 24);
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
          long double _r = necromancer_rem::rem(_x, pi);
          if(is_nan(_r) || is_infinite(_r))
          {
               return undefined;
          }
          else if(_r < 0.0l)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0l;
          }
          if(_r - pi_2 <= 0.07l)
          {
               /*If _r is small enough, you can just return*/
               /*The first 3 terms of the Taylor Series*/
               /*as it's already a very good approximation*/
               /*equivalent to 1 - (_r^2 / 2!) + (_r^4 / 4!)*/
               long double _r2 = _r * _r;
               long double _r4 = _r2 * _r2;
               return 1 - (_r2 / 2) + (_r4 / 24);
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
     /*Sine doesn't want to work right now D:*/
}

#endif /*__EUCLID_TRIG__*/