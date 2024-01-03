/*The Math Necromancer*/

#ifndef _NECROMANCER_ASIN_
#define _NECROMANCER_ASIN_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "../float_class.hpp"
#include "../roots.hpp"
#include "atan.hpp"

namespace necromancer_asin
{
     using namespace necromancer_float_class;
     /*12/18/2023*/
     constexpr float asinf(const float& _x)
     {
          float_32 _i = {_x};
          /*|_x|*/
          _i._y &= 0x7fffffff;
          /*asin(_x) is undefined for |_x| > 1*/
          if(_i._y > 0x3f800000)
               return sorcery::NaNf;
          /*|_x| < 1/256, we return _x as it's asin(x) in single precision*/
          if(_i._y <= 0x3b800000)
               return _x;
          float _r = necromancer_atan::
               atanf(_x / necromancer_root::sqrtf(1 - _x * _x));
          return necromancer_sign::
               copysignf(_r, _x);
     }
     /*12/18/2023*/
     constexpr double asind(const double& _x)
     {
          float_64 _i = {_x};
          _i._x = _x;
          /*|_x|*/
          _i._lh._hi &= 0x7fffffff;
          /*asin(_x) is undefined for |_x| > 1*/
          if(_i._y > 0x3ff0000000000000)
               return sorcery::NaNf;
          double _r = necromancer_atan::
               atand(_x / necromancer_root::sqrtd(1 - _x * _x));
          return necromancer_sign::
               copysignd(_r, _x);
     }
}

#endif /*_NECROMANCER_ASIN_*/