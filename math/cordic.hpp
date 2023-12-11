/*The Math Necromancer*/

/*CORDIC Algorithm for approximations of*/
/*Trigonometric Functions*/
/*This Library refines the approximantions done by*/
/*coirdc_operations.hpp and cordic_functions.hpp*/

#ifndef _NECROMANCER_CORDIC_
#define _NECROMANCER_CORDIC_

#include "cordic_operations.hpp"
#include "cordic_functions.hpp"
#include "constants.hpp"
#include "float_class.hpp"
#include "rem.hpp"
#include "abs.hpp"

namespace necromancer_cordic
{
     using namespace necromancer_cordic_operations;
     using namespace necromancer_cordic_functions;
     using namespace necromancer_float_class;

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

     float asinf(const float& _x)
     {
          if(is_nan(_x) || absolute::abs<float>(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs<float>(_x) == 1)
          {
               return pi_2 * _x;
          }
          return cordic_arcsin<float>(_x);
     }
     double asind(const double& _x)
     {
          if(is_nan(_x) || absolute::abs<double>(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs<double>(_x) == 1)
          {
               return pi_2 * _x;
          }
          return cordic_arcsin<double>(_x);
     }
     long double asinl(const long double& _x)
     {
          if(is_nan(_x) || absolute::abs<long double>(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs<long double>(_x) == 1)
          {
               return pi_2 * _x;
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
          if(is_nan(_x) || absolute::abs<float>(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs<float>(_x) == 1)
          {
               return -_x * pi_2 + pi_2;
          }
          return cordic_arccos<float>(_x);
     }
     double acosd(const double& _x)
     {
          if(is_nan(_x) || absolute::abs<double>(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs<double>(_x) == 1)
          {
               return -_x * pi_2 + pi_2;
          }
          return cordic_arccos<double>(_x);
     }
     long double acosl(const long double& _x)
     {
          if(is_nan(_x) || absolute::abs<long double>(_x) > 1)
          {
               return undefined;
          }
          else if(_x == 0 || absolute::abs<long double>(_x) == 1)
          {
               return -_x * pi_2 + pi_2;
          }
          return cordic_arccos<long double>(_x);
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
          if(is_inff(_x))
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
          if(is_infd(_x))
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
          if(is_inf(_x))
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

     float atan2f(const float& _y, const float& _x)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_inff(_x))
          {
               return is_inff(_y)? undefined: (float) pi_2;
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
          return cordic_arctan2<float>(_y, _x);
     }
     double atan2d(const double& _y, const double& _x)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_infd(_x))
          {
               return is_infd(_y)? undefined: (double) pi_2;
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
          return cordic_arctan2<double>(_y, _x);
     }
     long double atan2l(const long double& _y, const long double& _x)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_inf(_x))
          {
               return is_inf(_y)? undefined: (long double) pi_2;
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
          return cordic_arctan2<long double>(_y, _x);
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

     float hypotf(const float& _x, const float& _y)
     {
          if(is_nan(_x) || is_nan(_y))
          {
               return undefined;
          }
          else if(is_inff(_x) || is_inff(_y))
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
          else if(is_infd(_x) || is_infd(_y))
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
          else if(is_inf(_x) || is_inf(_y))
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
          else if(is_inff(_x))
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
          else if(is_inff(_x))
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
          else if(is_inff(_x))
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
          if(is_nan(_x) || is_inff(_x))
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
          if(is_nan(_x) || is_infd(_x))
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
          if(is_nan(_x) || is_inf(_x))
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
          if(is_nan(_x) || is_inff(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, pi) == pi_2 || necromancer_rem::rem(_x, pi) == -pi_2)
          {
               return INFINITY;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          else if(necromancer_rem::rem(_x, pi) == pi_4)
          {
               return 1;
          }
          return cordic_tan<float>(_x);
     }
     double tand(const double& _x)
     {
          if(is_nan(_x) || is_infd(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, pi) == pi_2 || necromancer_rem::rem(_x, pi) == -pi_2)
          {
               return INFINITY;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          else if(necromancer_rem::rem(_x, pi) == pi_4)
          {
               return 1;
          }
          return cordic_tan<double>(_x);
     }
     long double tanl(const long double& _x)
     {
          if(is_nan(_x) || is_inf(_x))
          {
               return undefined;
          }
          else if(necromancer_rem::rem(_x, pi) == pi_2 || necromancer_rem::rem(_x, pi) == -pi_2)
          {
               return INFINITY;
          }
          else if(necromancer_rem::rem(_x, pi) == 0)
          {
               return 0;
          }
          else if(necromancer_rem::rem(_x, pi) == pi_4)
          {
               return 1;
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

#endif /*_NECROMANCER_CORDIC_*/