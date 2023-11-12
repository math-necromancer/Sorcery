/*The Math Necromancer*/

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
          if(_r = INFINITY)
          {
               return pi_2 * mult;
          }
          else if(_r <= 0.0667f || _r == NaN || _r == undefined)
          {
               /*If _r is small enough, you can just return it right now*/
               /*as it's already a very good approximation*/
               return _r;
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
          if(_r = INFINITY)
          {
               return pi_2 * mult;
          }
          else if(_r <= 0.0667 || _r == NaN || _r == undefined)
          {
               /*If _r is small enough, you can just return it right now*/
               /*as it's already a very good approximation*/
               return _r;
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
          if(_r = INFINITY)
          {
               return pi_2 * mult;
          }
          else if(_r <= 0.0667l || _r == NaN || _r == undefined)
          {
               /*If _r is small enough, you can just return it right now*/
               /*as it's already a very good approximation*/
               return _r;
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
     float cosf(const float& _x)
     {
          float _r = necromancer_rem::rem(_x, pi);
          if(_r < 0.0f)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0f;
          }
          if(_r - pi_2 <= 0.0667f)
          {
               return _r - pi_2;
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
          if(_r < 0.0)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0;
          }
          if(_r - pi_2 <= 0.0667)
          {
               return _r - pi_2;
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
          if(_r < 0.0l)
          {
               /*cos(-x) = cos(x)*/
               _r *= -1.0l;
          }
          if(_r - pi_2 <= 0.0667l)
          {
               return _r - pi_2;
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