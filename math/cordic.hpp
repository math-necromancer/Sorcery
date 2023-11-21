/*The Math Necromancer*/

/*CORDIC Algorithm for approximations of*/
/*Trigonometric Functions*/
/*This Library refines the approximantions done by*/
/*coirdc_operations.hpp and cordic_functions.hpp*/

#ifndef __CORDIC__
#define __CORDIC__

#include "cordic_operations.hpp"
#include "cordic_functions.hpp"
#include "constants.hpp"
#include "number_classifications.hpp"
#include "rem.hpp"

using namespace necromancer_cordic_operations;
using namespace necromancer_cordic_functions;

namespace cordic
{
     float atanf(const float& _x);
     double atand(const double& _x);
     long double atanl(const long double& _x);
     float atan(const float& _x);
     double atan(const double& _x);
     long double atan(const long double& _x);
     template<typename _atan_typ>
     double atan(const _atan_typ& _x);

     float atan2f(const float& _x, const float& _y);
     double atan2d(const double& _x, const double& _y);
     long double atan2l(const long double& _x, const long double& _y);
     float atan2(const float& _x, const float& _y);
     double atan2(const double& _x, const double& _y);
     long double atan2(const long double& _x, const long double& _y);
     template<typename _atan2_typ>
     double atan2(const _atan2_typ& _x, const _atan2_typ& _y);

     float hypotf(const float& _x, const float& _y);
     double hypotd(const double& _x, const double& _y);
     long double hypotl(const long double& _x, const long double& _y);
     float hypot(const float& _x, const float& _y);
     double hypot(const double& _x, const double& _y);
     long double hypot(const long double& _x, const long double& _y);
     template<typename _hypot_typ>
     double hypot(const _hypot_typ& _x, const _hypot_typ& _y);

     float sinf(const float& _x);
     double sind(const double& _x);
     long double sinl(const long double& _x);
     float sin(const float& _x);
     double sin(const double& _x);
     long double sin(const long double& _x);
     template<typename _sin_typ>
     double sin(const _sin_typ& _x);

     float cosf(const float& _x);
     double cosd(const double& _x);
     long double cosl(const long double& _x);
     float cos(const float& _x);
     double cos(const double& _x);
     long double cos(const long double& _x);
     template<typename _cos_typ>
     double cos(const _cos_typ& _x);

     float tanf(const float& _x);
     double tand(const double& _x);
     long double tanl(const long double& _x);
     float tan(const float& _x);
     double tan(const double& _x);
     long double tan(const long double& _x);
     template<typename _tan_typ>
     double tan(const _tan_typ& _x);

     float atanf(const float& _x)
     {
          if(is_infinite(_x))
          {
               return (float) pi_2;
          }
          else if(_x == 0 || _x == 1 || _x == -1 || is_nan(_x))
          {
               return (float) (_x * pi_4);
          }
          return cordic_arctan<float>(_x);
     }
     double atand(const double& _x)
     {
          if(is_infinite(_x))
          {
               return (double) pi_2;
          }
          else if(_x == 0 || _x == 1 || _x == -1 || is_nan(_x))
          {
               return (double) (_x * pi_4);
          }
          return cordic_arctan<double>(_x);
     }
     long double atanl(const long double& _x)
     {
          if(is_infinite(_x))
          {
               return (long double) pi_2;
          }
          else if(_x == 0 || _x == 1 || _x == -1 || is_nan(_x))
          {
               return (long double) (_x * pi_4);
          }
          return cordic_arctan<long double>(_x);
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

     float atan2f(const float& _x, const float& _y)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_infinite(_x))
          {
               return is_infinite(_y)? undefined: (float) pi_2;
          }
          int neg = 1;
          if(_x < 0 ^ _y < 0)
          {
               neg = -1;
          }
          if(_x == 0 || _x == _y || -_x == _y)
          {
               return (float) (neg * pi_4);
          }
          return cordic_arctan2<float>(_x, _y);
     }
     double atan2d(const double& _x, const double& _y)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_infinite(_x))
          {
               return is_infinite(_y)? undefined: (double) pi_2;
          }
          int neg = 1;
          if(_x < 0 ^ _y < 0)
          {
               neg = -1;
          }
          if(_x == 0 || _x == _y || -_x == _y)
          {
               return (double) (neg * pi_4);
          }
          return cordic_arctan2<double>(_x, _y);
     }
     long double atan2l(const long double& _x, const long double& _y)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_infinite(_x))
          {
               return is_infinite(_y)? undefined: (long double) pi_2;
          }
          int neg = 1;
          if(_x < 0 ^ _y < 0)
          {
               neg = -1;
          }
          if(_x == 0 || _x == _y || -_x == _y)
          {
               return (long double) (neg * pi_4);
          }
          return cordic_arctan2<long double>(_x, _y);
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
     template<typename _atan2_typ>
     double atan2(const _atan2_typ& _x, const _atan2_typ& _y)
     {
          return atan2d((double) _x, (double) _y);
     }

     float hypotf(const float& _x, const float& _y)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_infinite(_x) || is_infinite(_y))
          {
               return INFINITY;
          }
          else if(_x == 0)
          {
               return _y;
          }
          else if(_y == 0)
          {
               return _x;
          }
          return cordic_hypot<float>(_x, _y);
     }
     double hypotd(const double& _x, const double& _y)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_infinite(_x) || is_infinite(_y))
          {
               return INFINITY;
          }
          else if(_x == 0)
          {
               return _y;
          }
          else if(_y == 0)
          {
               return _x;
          }
          return cordic_hypot<double>(_x, _y);
     }
     long double hypotl(const long double& _x, const long double& _y)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_infinite(_x) || is_infinite(_y))
          {
               return INFINITY;
          }
          else if(_x == 0)
          {
               return _y;
          }
          else if(_y == 0)
          {
               return _x;
          }
          return cordic_hypot<long double>(_x, _y);
     }

     float hypot(const float& _x, const float& _y)
     {
          return hypotf(_x, _y);
     }
     double hypot(const double& _x, const double& _y)
     {
          return hypotd(_x, _y);
     }
     long double hypot(const long double& _x, const long double& _y)
     {
          return hypotl(_x, _y);
     }
     template<typename _hypot_typ>
     double hypot(const _hypot_typ& _x, const _hypot_typ& _y)
     {
          return hypotd((double) _x, (double) _y);
     }

     float sinf(const float& _x)
     {
          if(is_nan(_x))
          {
               return _x;
          }
          else if(is_infinite(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          else if(necromancer_rem::rem(_x, tau) == pi_2)
          {
               return 1;
          }
          else if(necromancer_rem::rem(_x, tau) == -pi_2)
          {
               return -1;
          }
          return cordic_sin<float>(_x);
     }
     double sind(const double& _x)
     {
          if(is_nan(_x))
          {
               return _x;
          }
          else if(is_infinite(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          else if(necromancer_rem::rem(_x, tau) == pi_2)
          {
               return 1;
          }
          else if(necromancer_rem::rem(_x, tau) == -pi_2)
          {
               return -1;
          }
          return cordic_sin<double>(_x);
     }
     long double sinl(const long double& _x)
     {
          if(is_nan(_x))
          {
               return _x;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          else if(is_infinite(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, tau) == pi_2)
          {
               return 1;
          }
          else if(necromancer_rem::rem(_x, tau) == -pi_2)
          {
               return -1;
          }
          return cordic_sin<long double>(_x);
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

     float cosf(const float& _x)
     {
          if(is_nan(_x) || is_infinite(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, tau) == 0)
          {
               return 1;
          }
          else if(necromancer_rem::rem(_x, tau) == pi)
          {
               return -1;
          }
          else if(necromancer_rem::rem(_x, tau) == pi_2)
          {
               return 0;
          }
          else if(necromancer_rem::rem(_x, tau) == -pi_2)
          {
               return -0;
          }
          return cordic_cos<float>(_x);
     }
     double cosd(const double& _x)
     {
          if(is_nan(_x) || is_infinite(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, tau) == 0)
          {
               return 1;
          }
          else if(necromancer_rem::rem(_x, tau) == pi)
          {
               return -1;
          }
          else if(necromancer_rem::rem(_x, tau) == pi_2)
          {
               return 0;
          }
          else if(necromancer_rem::rem(_x, tau) == -pi_2)
          {
               return -0;
          }
          return cordic_cos<double>(_x);
     }
     long double cosl(const long double& _x)
     {
          if(is_nan(_x) || is_infinite(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, tau) == 0)
          {
               return 1;
          }
          else if(necromancer_rem::rem(_x, tau) == pi)
          {
               return -1;
          }
          else if(necromancer_rem::rem(_x, tau) == pi_2)
          {
               return 0;
          }
          else if(necromancer_rem::rem(_x, tau) == -pi_2)
          {
               return -0;
          }
          return cordic_cos<long double>(_x);
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

     float tanf(const float& _x)
     {
          if(is_nan(_x) || is_infinite(_x) || necromancer_rem::rem(_x, pi) == pi_2 || necromancer_rem::rem(_x, pi) == -pi_2)
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          return cordic_tan<float>(_x);
     }
     double tand(const double& _x)
     {
          if(is_nan(_x) || is_infinite(_x) || necromancer_rem::rem(_x, pi) == pi_2 || necromancer_rem::rem(_x, pi) == -pi_2)
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          return cordic_tan<double>(_x);
     }
     long double tanl(const long double& _x)
     {
          if(is_nan(_x) || is_infinite(_x) || necromancer_rem::rem(_x, pi) == pi_2 || necromancer_rem::rem(_x, pi) == -pi_2)
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          return cordic_tan<long double>(_x);
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

#endif /*__CORDIC__*/