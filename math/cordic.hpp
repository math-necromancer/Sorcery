/*The Math Necromancer*/

/*CORDIC Algorithm for approximations of*/
/*Trigonometric Functions*/
/*This Library refines the approximantions done by*/
/*coirdc_operations.hpp and cordic_functions.hpp*/

#ifndef __CORDIC__
#define __CORDIC__

#include "cordic_operations.hpp"
#include "cordic_functions.hpp"
#include "rem.hpp"

using namespace necromancer_cordic_operations;
using namespace necromancer_cordic_functions;

namespace cordic
{
     float atanf(const float& _x)
     {
          float _r = _x;
          if(_r == 0.0f || _r == NaN || _r == undefined)
          {
               return _r;
          }
          else if(_r == INFINITY)
          {
               return pi_2;
          }
          return (float) cordic_arctan(_r);
     }
     double atand(const double& _x)
     {
          double _r = _x;
          if(_r == 0.0 || _r == NaN || _r == undefined)
          {
               return _r;
          }
          else if(_r == INFINITY)
          {
               return pi_2;
          }
          return (double) cordic_arctan(_r);
     }
     long double atanl(const long double& _x)
     {
          long double _r = _x;
          if(_r == 0.0l || _r == NaN || _r == undefined)
          {
               return _r;
          }
          else if(_r == INFINITY)
          {
               return pi_2;
          }
          return cordic_arctan(_r);
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

     float atan2f(const float& _x, const float& _y)
     {
          float _o = _x;
          float _a = _y;
          if(_a == 0.0f || _o == INFINITY)
          {
               return pi_2;
          }
          else if(_o == 0.0f || _o == NaN || _o == undefined)
          {
               return _o;
          }
          return (float) cordic_arctan2(_o, _a);
     }
     double atan2d(const double& _x, const double& _y)
     {
          float _o = _x;
          float _a = _y;
          if(_a == 0.0 || _o == INFINITY)
          {
               return pi_2;
          }
          else if(_o == 0.0 || _o == NaN || _o == undefined)
          {
               return _o;
          }
          return (double) cordic_arctan2(_o, _a);
     }
     long double atan2l(const double& _x, const double& _y)
     {
          float _o = _x;
          float _a = _y;
          if(_a == 0.0l || _o == INFINITY)
          {
               return pi_2;
          }
          else if(_o == 0.0l || _o == NaN || _o == undefined)
          {
               return _o;
          }
          return cordic_arctan2(_o, _a);
     }
     float atan2(const float& _x, const float& _y)
     {
          return atan2f(_x, _y);
     }
     double atan2(const double& _x, const double& _y)
     {
          return atan2d(_x, _y);
     }
     long double atan2(const long double& _x, const long double& _y)
     {
          return atan2l(_x, _y);
     }

     float hypotf(const float& _x, const float& _y)
     {
          if(_x == 0.0f)
          {
               return _y;
          }
          else if(_y == 0.0f)
          {
               return _x;
          }
          return (float) cordic_hypot(_x, _y);
     }
     double hypotd(const double& _x, const double& _y)
     {
          if(_x == 0.0)
          {
               return _y;
          }
          else if(_y == 0.0)
          {
               return _x;
          }
          return (double) cordic_hypot(_x, _y);
     }
     double hypotl(const long double& _x, const long double& _y)
     {
          if(_x == 0.0l)
          {
               return _y;
          }
          else if(_y == 0.0l)
          {
               return _x;
          }
          return cordic_hypot(_x, _y);
     }
     float hypot(const float& _x, const float& _y)
     {
          return hypotf(_x, _y);
     }
     double hypot(const double& _x, const double& _y)
     {
          return hypotd(_x, _y);
     }
     float hypot(const long double& _x, const long double& _y)
     {
          return hypotl(_x, _y);
     }

     float cosf(const float& _x)
     {
          float _r = necromancer_rem::rem(_x, tau);
          if(_r == 0.0f || _r == pi)
          {
               return 1.0f;
          }
          else if(_r == pi_2 || _r == tau - pi_2)
          {
               return 0.0f;
          }
          return (float) cordic_cos(_r);
     }
     double cosd(const double& _x)
     {
          double _r = necromancer_rem::rem(_x, tau);
          if(_r == 0.0 || _r == pi)
          {
               return 0.0;
          }
          else if(_r == pi_2 || _r == tau - pi_2)
          {
               return 1.0;
          }
          return (double) cordic_cos(_r);
     }
     long double cosl(const long double& _x)
     {
          long double _r = necromancer_rem::rem(_x, tau);
          if(_r == 0.0l || _r == pi)
          {
               return 0.0l;
          }
          else if(_r == pi_2 || _r == tau - pi_2)
          {
               return 1.0l;
          }
          return (long double) cordic_cos(_r);
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

     float sinf(const float& _x)
     {
          float _r = necromancer_rem::rem(_x, tau);
          if(_r == 0.0f || _r == pi)
          {
               return 0.0f;
          }
          else if(_r == pi_2)
          {
               return 1.0f;
          }
          else if(_r == tau - pi_2)
          {
               return -1.0f;
          }
          return (float) cordic_sin(_r);
     }
     double sind(const double& _x)
     {
          double _r = necromancer_rem::rem(_x, tau);
          if(_r == 0.0 || _r == pi)
          {
               return 0.0;
          }
          else if(_r == pi_2)
          {
               return 1.0;
          }
          else if(_r == tau - pi_2)
          {
               return -1.0;
          }
          return (double) cordic_sin(_r);
     }
     long double sinl(const long double& _x)
     {
          long double _r = necromancer_rem::rem(_x, tau);
          if(_r == 0.0l || _r == pi)
          {
               return 0.0l;
          }
          else if(_r == pi_2)
          {
               return 1.0l;
          }
          else if(_r == tau - pi_2)
          {
               return -1.0l;
          }
          return (long double) cordic_sin(_r);
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

     float tanf(const float& _x)
     {
          float _r = necromancer_rem::rem(_x, pi);
          if(_r == 0.0f)
          {
               return _r;
          }
          else if(_r == pi_2)
          {
               return 1.0f / 0.0f;
          }
          else if(_r == -pi_2)
          {
               return -1.0f / 0.0f;
          }
          return (float) cordic_tan(_r);
     }
     double tand(const double& _x)
     {
          float _r = necromancer_rem::rem(_x, pi);
          if(_r == 0.0)
          {
               return _r;
          }
          else if(_r == pi_2)
          {
               return 1.0 / 0.0;
          }
          else if(_r == -pi_2)
          {
               return -1.0 / 0.0;
          }
          return (double) cordic_tan(_r);
     }
     long double tanl(const long double& _x)
     {
          float _r = necromancer_rem::rem(_x, pi);
          if(_r == 0.0l)
          {
               return _r;
          }
          else if(_r == pi_2)
          {
               return 1.0l / 0.0l;
          }
          else if(_r == -pi_2)
          {
               return -1.0l / 0.0l;
          }
          return cordic_tan(_r);
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
}

#endif /*__CORDIC__*/