/*The Math Necromancer*/

#ifndef _NECROMANCER_ROUND_
#define _NECROMANCER_ROUND_

#ifndef _MATH_SORCERY_
     #error This file won't work if you don't include "math_sorcery.hpp"!
#else
     #include "float_class.hpp"
     #include "sign.hpp"
     namespace necromancer_round
     {
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

          /*1/17/2024*/
          constexpr float truncf(const float& _x)
          {
               float_32 _i = {_x};
               _int32 _sx = _i._y & 0x80000000;
               /*|_x|*/
               _i._y &= 0x7fffffff;
               /*If |_x| is greater than this, it's an integer, infinity, or NaN*/
               if(_i._y >= 0x4b7fffff)
                    return _x;
               int _e = _i._f_32._exp - 0x07f;
               _i._f_32._mantissa &= ((1 << _e + 1) - 1) << 0x017 - _e;
               _i._y |= _sx;
               return _i._x;
          }
          /*1/17/2024*/
          constexpr double truncd(const double& _x)
          {
               float_64 _i = {_x};
               _int32 _sx = _i._lh._hi & 0x80000000;
               /*|_x|*/
               _i._lh._hi &= 0x7fffffff;
               /*If |_x| is greater than this, it's an integer, infinity, or NaN*/
               if(_i._lh._hi >= 0x43400000)
                    return _x;
               int _e = _i._f_64._exp - 0x3ff;
               _i._f_64._mantissa &= ((1ull << _e + 1) - 1) << 0x034 - _e;
               _i._lh._hi |= _sx;
               return _i._x;
          }
          /*1/5/2024*/
          constexpr float floorf(const float& _x)
          {
               float_32 _i = {_x};
               _int32 _sx = _i._y & 0x80000000;
               if(_sx >> 31 == 1)
                    _i._x --;
               /*|_x|*/
               _i._y &= 0x7fffffff;
               /*If |_x| is greater than this, it's an integer, infinity, or NaN*/
               if(_i._y >= 0x4b7fffff)
                    return _x;
               int _e = _i._f_32._exp - 0x07f;
               _i._f_32._mantissa &= ((1 << _e + 1) - 1) << 0x017 - _e;
               _i._y |= _sx;
               return _i._x;
          }
          /*1/5/2024*/
          constexpr double floord(const double& _x)
          {
               float_64 _i = {_x};
               _int32 _sx = _i._lh._hi & 0x80000000;
               if(_i._f_64._sign)
                    _i._x --;
               /*|_x|*/
               _i._lh._hi &= 0x7fffffff;
               /*If |_x| is greater than this, it's an integer, infinity, or NaN*/
               if(_i._lh._hi >= 0x43400000)
                    return _x;
               int _e = _i._f_64._exp - 0x3ff;
               _i._f_64._mantissa &= ((1ull << _e + 1) - 1) << 0x034 - _e;
               _i._y |= _sx;
               return _i._x;
          }
          /*1/6/2024*/
          constexpr float ceilf(const float& _x)
          {
               float_32 _i = {_x};
               _int32 _sx = _i._y & 0x80000000;
               if(_sx >> 31 == 1)
                    _i._x ++;
               /*|_x|*/
               _i._y &= 0x7fffffff;
               /*If |_x| is greater than this, it's an integer, infinity, or NaN*/
               if(_i._y >= 0x4b7fffff)
                    return _x;
               int _e = _i._f_32._exp - 0x07f;
               _i._f_32._mantissa &= ((1 << _e + 1) - 1) << 0x017 - _e;
               _i._y |= _sx;
               return _i._x;
          }
          /*1/6/2024*/
          constexpr double ceild(const double& _x)
          {
               float_64 _i = {_x};
               _int32 _sx = _i._lh._hi & 0x80000000;
               if(_i._f_64._sign)
                    _i._x ++;
               /*|_x|*/
               _i._lh._hi &= 0x7fffffff;
               /*If |_x| is greater than this, it's an integer, infinity, or NaN*/
               if(_i._lh._hi >= 0x43400000)
                    return _x;
               int _e = _i._f_64._exp - 0x3ff;
               _i._f_64._mantissa &= ((1ull << _e + 1) - 1) << 0x034 - _e;
               _i._y |= _sx;
               return _i._x;
          }
     }
#endif /*_MATH_SORCERY_*/
#endif /*_NECROMANCER_ROUND_*/