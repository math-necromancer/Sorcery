/*The Math Necromancer*/

/*I promise I'll change it later; Taylor Series are slow :(*/
/*It doesn't even include range reduction, so it kinda diverges at large values*/

#ifndef __EXP__
#define __EXP__

#include "constants.hpp"

namespace necromancer_exp
{
     /*If the input is a float, this function will be used*/
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
               return (float) e;
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
     /*If the input is a double, this function will be used*/
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
               return (double) e;
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
     /*If the input is a long double, this function will be used*/
     long double expl(const long double& _x)
     {
          if(_x < 0)
          {
               return 1.0l / expl(-_x);
          }
          else if(_x == 0)
          {
               return 1;
          }
          else if(_x == 1)
          {
               return (long double) e;
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
          /*Return e^x as a float*/
          return expf(_x);
     }
     double exp(const double& _x)
     {
          /*Return e^x as a double*/
          return expd(_x);
     }
     long double exp(const long double& _x)
     {
          /*Return e^x as a long double*/
          return expl(_x);
     }
     template<typename _e_x>
     double exp(const _e_x& _x)
     {
          return expd((double) _x);
     }
}

#endif /*__EXP__*/