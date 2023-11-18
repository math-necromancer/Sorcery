/*The Math Necromancer*/

#ifndef __EXP__
#define __EXP__

#include "constants.hpp"

namespace necromancer_exp
{
     float expf(const float& _x)
     {
          if(_x < 0)
          {
               return 1.0f / expf(-_x);
          }
          if(_x == 0)
          {
               return 1;
          }
          else if(_x == 1)
          {
               return e;
          }
          /*For any precision, these need to be able to store*/
          /*A lot of decimal places via long double*/
          long double x = _x;
          long double _exp_r = x;
          /*20! is so huge you really don't need anything*/
          /*more precise*/
          for(int i = 2; i <= 20; i++)
          {
               /*Just a Taylor Series*/
               x *= _x / i;
               _exp_r += x;
          }
          _exp_r++;
          /*Convert to float at the end*/
          return (float) _exp_r;
     }
     double expd(const double& _x)
     {
          if(_x < 0)
          {
               return 1.0 / expd(-_x);
          }
          if(_x == 0)
          {
               return 1;
          }
          else if(_x == 1)
          {
               return e;
          }
          /*For any precision, these need to be able to store*/
          /*A lot of decimal places via long double*/
          long double x = _x;
          long double _exp_r = x;
          /*20! is so huge you really don't need anything*/
          /*more precise*/
          for(int i = 2; i <= 20; i++)
          {
               /*Just a Taylor Series*/
               x *= _x / i;
               _exp_r += x;
          }
          _exp_r++;
          /*Convert to double at the end*/
          return (double) _exp_r;
     }
     long double expl(const long double& _x)
     {
          if(_x < 0)
          {
               return 1.0l / expl(-_x);
          }
          if(_x == 0)
          {
               return 1;
          }
          else if(_x == 1)
          {
               return e;
          }
          /*For any precision, these need to be able to store*/
          /*A lot of decimal places via long double*/
          long double x = _x;
          long double _exp_r = x;
          /*20! is so huge you really don't need anything*/
          /*more precise*/
          for(int i = 2; i <= 20; i++)
          {
               /*Just a Taylor Series*/
               x *= _x / i;
               _exp_r += x;
          }
          _exp_r++;
          return _exp_r;
     }
     float exp(const float& _x)
     {
          return expf(_x);
     }
     double exp(const double& _x)
     {
          return expd(_x);
     }
     long double exp(const long double& _x)
     {
          return expl(_x);
     }
}

#endif /*__EXP__*/