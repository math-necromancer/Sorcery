/*The Math Necromancer*/

#ifndef _NECROMANCER_FLOAT_CLASS_
#define _NECROMANCER_FLOAT_CLASS_

#ifndef _MATH_SORCERY_
     #warning Are you sure you want to use this raw file instead of "math_sorcery.hpp"?
#endif /*_MATH_SORCERY_*/

/*Nice #defines for cases where you have not included "math_necromancy"*/

#ifndef _int32
     /*You might be using this file alone. Maybe #include math_sorcery.hpp?*/
     #define _int32 unsigned long
#endif /*_int32*/
#ifndef _int64
     /*You might be using this file alone. Maybe #include math_sorcery.hpp?*/
     #define _int64 unsigned long long
#endif /*_int64*/

/*Needed for frexp*/
static const double
     two24 = 0x1000000,
     two54 = 0x40000000000000;

namespace necromancer_float_class
{
     /*** IEEE-754 Floating-Point Forms ***/
     /*nice floating point shapes (o_o)*/
     /*These unions are basically the magic behind all the fancy functions*/
     /*I will not be supporting long doubles (80 bit float)*/

     /*12/13/2023*/
     /*32-bit float form*/
     union float_32
     {
          float _x;      
          _int32 _y;
          struct _f_32
          {
               _int32 _mantissa : 23;
               _int32 _exp : 8;
               _int32 _sign : 1;
          } _f_32;
          struct _lh
          {
               unsigned short _lo, _hi;
          } _lh;
     };
     /*12/13/2023*/
     /*64-bit float form*/
     union float_64
     {
          double _x;
          _int64 _y;
          struct _f_64
          {
               _int64 _mantissa : 52;
               _int64 _exp : 11;
               _int64 _sign : 1;
          } _f_64;
          struct _lh
          {
               _int32 _lo, _hi;
          } _lh;
     };
     /*** IEEE-754 Float Classifications ***/

     /*0.0 (Subnormal in IEEE-754)*/
     #define _FLT_ZERO 0x001
     /*"Not a Number"*/
     #define _FLT_NAN 0x0002
     /*Infinity*/
     #define _FLT_INFINITY 0x0003
     /*Negative Infinity*/
     #define _FLT_NEG_INFY 0x0004
     /*Normal Floating Point*/
     #define _FLT_NORMAL 0x0005
     /*Subnormal Float*/
     #define _FLT_SUBNORMAL 0x0006

     /*12/24/2023*/
     constexpr float _flt_bits(const _int32 _i)
     {
          float_32 _f = {0.0f};
          _f._y = _i;
          return _f._x;
     }
     /*12/24/2023*/
     constexpr double _dbl_bits(const _int64 _i)
     {
          float_64 _f = {0.0};
          _f._y = _i;
          return _f._x;
     }
     /*12/24/2023*/
     constexpr float _flt_inff(const bool& _is_negative)
     {
          return _is_negative ? _flt_bits(0xff800000):
               _flt_bits(0x7f800000);
     }
     /*12/24/2023*/
     constexpr double _flt_infd(const bool& _is_negative)
     {
          return _is_negative ? _dbl_bits(0xfff0000000000000):
               _dbl_bits(0x7ff0000000000000);
     }
     /*12/24/2023*/
     constexpr float _flt_nanf()
     {
          return _flt_bits(0x7fffffff);
     }
     /*12/24/2023*/
     constexpr double _flt_nand()
     {
          return _dbl_bits(0x7fffffffffffffff);
     }
     /*Single precision Infinity*/
     #define INFINITYf necromancer_float_class::_flt_inff(false)
     /*Double precision Infinity*/
     #define INFINITY necromancer_float_class::_flt_infd(false)
     /*Single precision negative Infinity*/
     #define NEGATIVE_INFINITYf necromancer_float_class::_flt_inff(true)
     /*Double precision negative Infinity*/
     #define NEGATIVE_INFINITY necromancer_float_class::_flt_infd(true)
     /*Single precision "Not a Number"*/
     #define NaNf necromancer_float_class::_flt_nanf()
     /*Double precision "Not a Number"*/
     #define NaN necromancer_float_class::_flt_nand()     
     /*12/24/2023*/
     constexpr int classify_ieee754_32f(const float& _x)
     {
          float_32 _i = {_x};
          if(!(_i._y & 0x7fffffff))
               return _FLT_ZERO;
          if(_i._f_32._exp == 0x000)
               return _FLT_SUBNORMAL;
          if(_i._f_32._exp == 0x0ff)
          {
               if (_i._f_32._mantissa)
                    return _FLT_NAN;
               return (_i._f_32._sign)? _FLT_NEG_INFY: _FLT_INFINITY;
          }
          return _FLT_NORMAL;
     }
     /*12/24/2023*/
     constexpr int classify_ieee754_64f(const double& _x)
     {
          float_64 _i = {_x};
          if(!((_i._lh._hi & 0x7fffffff) | _i._lh._lo))
               return _FLT_ZERO;
          if(_i._f_64._exp == 0x000)
               return _FLT_SUBNORMAL;
          if(_i._f_64._exp == 0x7ff)
          {
               if (_i._f_64._mantissa)
                    return _FLT_NAN;
               return (_i._f_64._sign)? _FLT_NEG_INFY: _FLT_INFINITY;
          }
          return _FLT_NORMAL;
     }
     /*12/24/2023*/
     constexpr bool is_inff(const float& _x)
     {
          float_32 _i = {_x};
          _i._y &= 0x7fffffff;
          return _i._y == 0x7f800000;
     }
     /*1/17/2024*/
     constexpr bool is_infd(const double& _x)
     {
          float_64 _i = {_x};
          _i._lh._hi &= 0x7fffffff;
          return _i._lh._hi == 0x7f800000 && _i._lh._lo == 0;
     }
     /*12/24/2023*/
     constexpr bool is_finitef(const float& _x)
     {
          float_32 _i = {_x};
          return _i._f_32._exp < 0x0ff;
     }
     /*12/24/2023*/
     constexpr bool is_finited(const double& _x)
     {
          float_64 _i = {_x};
          return _i._f_64._exp < 0x7ff;
     }
     /*12/24/2023*/
     constexpr bool is_nanf(const float& _x)
     {
          float_32 _i = {_x};
          _i._y &= 0x7fffffff;
          return _i._y > 0x7f800000;
     }
     /*12/24/2023*/
     constexpr bool is_nand(const double& _x)
     {
          float_64 _i = {_x};
          _i._lh._hi &= 0x7fffffff;
          return _i._y > 0x7ff0000000000000;
     }
     /*12/24/2023*/
     constexpr bool is_positivef(const float& _x)
     {
          if(is_nanf(_x))
               return false;
          float_32 _i = {_x};
          return _i._x < 0x80000000;
     }
     /*12/24/2023*/
     constexpr bool is_positived(const double& _x)
     {
          if(is_nand(_x))
               return false;
          float_64 _i = {_x};
          return _i._lh._hi < 0x80000000;
     }
     /*12/24/2023*/
     constexpr bool is_negativef(const float& _x)
     {
          if(is_nanf(_x))     
               return false;
          float_32 _i = {_x};
          return _i._x >= 0x80000000;
     }
     /*12/24/2023*/
     constexpr bool is_negatived(const double& _x)
     {
          if(is_nand(_x))
               return false;
          float_64 _i = {_x};
          return _i._lh._hi >= 0x80000000;
     }
     /*12/24/2023*/
     constexpr bool is_intf(const float& _x)
     {
          float_32 _i = {_x};
          _i._y &= 0x7fffffff;
          /*If _x is Infinity or NaN*/
          if(_i._y >= 0x7f800000)
               return false;
          /*If _x is larger than this, than IEEE-754 can only represent integers*/
          if(_i._y >= 0x4b7fffff)
               return true;
          return _i._f_32._mantissa << _i._f_32._exp - 0x07e == 0;
     }
     /*12/24/2023*/
     constexpr bool is_intd(const double& _x)
     {
          float_64 _i = {_x};
          _i._lh._hi &= 0x7fffffff;
          /*If _x is Infinity or NaN*/
          if(_i._lh._hi >= 0x7f800000)
               return false;
          /*If _x is larger than this, than IEEE-754 can only represent integers*/
          if(_i._lh._hi >= 0x43400000)
               return true;
          return _i._f_64._mantissa << _i._f_64._exp - 0x03fe == 0;
     }
     /*12/24/2023*/
     constexpr bool is_decimalf(const float& _x)
     {
          float_32 _i = {_x};
          _i._y &= 0x7fffffff;
          /*If _x is larger than this, than IEEE-754 can only represent integers*/
          /*This also catches Infinity and NaN*/
          if(_i._y >= 0x4b7fffff)
               return false;  
          return _i._y << _i._f_32._exp - 0x076;
     }
     /*12/24/2023*/
     constexpr bool is_decimald(const double& _x)
     {
          float_64 _i = {_x};
          _i._lh._hi &= 0x7fffffff;
          /*If _x is larger than this, than IEEE-754 can only represent integers*/
          /*This also catches Infinity and NaN*/
          if(_i._lh._hi >= 0x43400000)
               return false;
          return _i._y << _i._f_64._exp - 0x03f2; 
     }
     /*1/29/2024*/
     constexpr float frexpf(const float& _x, int *_eptr)
     {
          float_32 _i = {_x};
          *_eptr = 0;
          /*_x is infinity, NaN, or 0*/
          if(_i._y & 0x7fffffff >= 0x7f800000 || _x == 0)
               return _x;
          /*Subnormal float ~ scale up _x*/
          if(_i._y & 0x7fffffff < 0x00800000)
          {
               _i._x *= two24;
               *_eptr -= 24;
          }
          /*Subtract 126 to avoid a multiplication that would be*/
          /*needed if we subtracted 127*/
          *_eptr += _i._f_32._exp - 126;
          /*Same business...*/
          _i._f_32._exp = 126;
          return _i._x;
     }
     /*1/29/2024*/
     constexpr double frexpd(const double& _x, int *_eptr)
     {
          float_64 _i = {_x};
          *_eptr = 0;
          /*If _x is infinity, NaN, or 0*/
          if(_i._lh._hi & 0x7fffffff >= 0x7ff00000 || _x == 0)
               return _x;
          /*Subnormal float ~ scale up _x*/
          if(_i._lh._hi & 0x7fffffff < 0x01000000)
          {
               _i._x *= two54;
               *_eptr = -54;
          }
          /*Subtract 1022 to avoid a multiplication that would be*/
          /*needed if we subtracted 1023*/
          *_eptr += _i._f_64._exp - 1022;
          /*Same business...*/
          _i._f_64._exp = 1022;
          return _i._x;
     }
     /*1/29/2024*/
     constexpr float ldexpf(const float& _x, const int& _e)
     {
          float_32 _i = {_x};
          if(_i._y & 0x7fffffff >= 0x7f800000 || _i._y == 0)
               return _x;
          _i._f_32._exp += _e;
          return _i._x;
     }
     /*1/29/2024*/
     constexpr double ldexpd(const double& _x, const int& _e)
     {
          float_64 _i = {_x};
          /*If _x is infinity, NaN, or 0*/
          if(_i._lh._hi & 0x7fffffff >= 0x7f800000 || _i._y == 0)
               return _x;
          _i._f_64._exp += _e;
          return _i._x;
     }
     /*12/24/2023*/
     constexpr float nextafterf(const float& _x, const float& _y)
     {
          float_32 _ix = {_x};
          float_32 _iy = {_y};
          /*|_x|*/
          _int32 _aix = _ix._y & 0x7fffffff;
          /*|_y|*/
          _int32 _aiy = _iy._y & 0x7fffffff;
          /*_x or _y is NaN*/
          if(_aix > 0x7f800000 || _aiy > 0x7f800000)
               return _x + _y;
          /*_x = _y, return _y*/
          if(_ix._y == _iy._y)
               return _y;
          if(_aix == 0)
          {
               /*Return +-_FLT_SUB_EPSILON_*/
               _ix._y = (_iy._y & 0x80000000) | 1;
               return _ix._x;
          }
          /*If _x is positive - we check the sign bit*/
          if(_ix._y < 0x80000000)
          {
               if(_iy._y < 0x80000000 && _ix._y < _iy._y)
                    _ix._y ++;
               else
                    _ix._y --;
          }
          else
          {
               if(_iy._y < 0x80000000 || _ix._y > _iy._y)
                    _ix._y --;
               else
                    _ix._y ++;
          }
          return _ix._x;
     }
     /*12/24/2023*/
     constexpr double nextafterd(const double& _x, const double& _y)
     {
          float_64 _ix = {_x};
          float_64 _iy = {_y};
          /*|_x|*/
          _int64 _aix = _ix._y & 0x7fffffffffffffff;
          /*|_y|*/
          _int64 _aiy = _iy._y & 0x7fffffffffffffff;
          /*_x or _y is NaN*/
          if(_aix > 0x7ff0000000000000 || _aiy > 0x7ff0000000000000)
               return _x + _y;
          if(_ix._y == _iy._y)
               return _y;
          if(_aix == 0)
          {
               /*Return +-_DBL_SUB_EPSILON_*/
               _aix = (_iy._y & 0x8000000000000000) | 1;
               _ix._y = _aix;
               return _ix._x;
          }
          /*If _x isn't negative - we check the sign bit*/
          if(_ix._y < 0x8000000000000000)
          {
               if(_iy._y < 0x8000000000000000 && _ix._y < _iy._y)
                    _ix._y ++;
               else
                    _ix._y --;
          }
          else
          {
               if(_iy._y < 0x8000000000000000 || _ix._y < _iy._y)
                    _ix._y ++;
               else
                    _ix._y --;
          }
          return _ix._x;
     }
     /*12/24/2023*/
     constexpr float f32o2(const float& _x)
     {
          float_32 _i = {_x};
          _i._f_32._exp --;
          return _i._x;
     }
     /*12/24/2023*/
     constexpr double f64o2(const double& _x)
     {
          float_64 _i = {_x};
          _i._f_64._exp --;
          return _i._x;
     }
}

#endif /*_NECROMANCER_FLOAT_CLASS_*/