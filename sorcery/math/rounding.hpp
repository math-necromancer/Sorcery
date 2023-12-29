/*The Math Necromancer*/

#ifndef _NECROMANCER_ROUND_
#define _NECROMANCER_ROUND_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "float_class.hpp"
#include "sign.hpp"

namespace necromancer_round
{
     using namespace necromancer_float_class;

     /*Basically, an integer will never have bits past the*/
     /*n'th leading mantissa bit, where n is the exponent.*/
     /*This lets us create a mask by getting all 1's int the*/
     /*mantissa, then shifting it by 22 - n, because the the*/
     /*mantissa is 22 bits long.*/
     /*Demonstration:*/
     /*511.70f :                                       */
     /*   0 - 10000111 - 11111111101100110011010       */
     /*   ^      ^                  ^                  */
     /*  sign   exp             mantissa               */
     /*AND the mantissa with 11111111100000000000000   */
     /*   0 - 10000111 - 11111111101100110011010       */
     /*  &               11111111100000000000000       */
     /*We return 511.0f, which is this in binary:      */
     /*   0 - 10000111 - 11111111100000000000000       */
     /*The double implementation is similar to this, but the mantissa*/
     /*is 52 bits wide, and there is a different exponent bias.*/

     /*12/26/2023*/
     constexpr float truncf(const float& _x)
     {
          float_32 _i = {_x};
          /*|_x|*/
          _i._y &= 0x7fffffff;
          /*If |_x| is greater than this, it's an integer, infinity, or NaN*/
          if(_i._y >= 0x4b7fffff)
               return _x;
          _int32 _e = _i._f_32._exp - 0x07f;
          _i._f_32._mantissa &= ((1 << _e + 1) - 1) << 0x017 - _e;
          return necromancer_sign::
               copysignf(_i._x, _x);
     }
     /*12/26/2023*/
     constexpr _int64 truncd(const double& _x)
     {
          float_64 _i = {_x};
          /*|_x|*/
          _i._y &= 0x7fffffffffffffff;
          /*If |_x| is greater than this, it's an integer, infinity, or NaN*/
          if(_i._y >= 0x433fffffffffffff)
               return _x;
          _int64 _e = _i._f_64._exp - 0x3ff;
          return _i._f_64._mantissa & ((1 << _e + 1) - 1) << 0x034 - _e;
          return necromancer_sign::
               copysignd(_i._x, _x);
     }
}

#endif /*_NECROMANCER_ROUND_*/