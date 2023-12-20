/*The Math Necromancer*/

#ifndef _NECROMANCER_FLOAT_CLASS_
#define _NECROMANCER_FLOAT_CLASS_

namespace necromancer_float_class
{
     typedef unsigned long _int32;
     typedef unsigned long long _int64;

     /*** IEEE-754 Floating-Point Forms ***/
     /*I will not be supporting long doubles*/

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
          };
          _f_64 _f_64;
     };
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
          };
          _f_32 _f_32;
     };
     /*** Predefined NaNs and Infinities ***/

     const static float_32 _nanf = {0x7fc00000};
     const static float_64 _nand = {0x7ff8000000000000};
     const static float_32 _inff = {0x7f800000};
     const static float_32 _ninff = {0xff800000};
     const static float_64 _infd = {0x7ff0000000000000};
     const static float_64 _ninfd = {0xfff0000000000000};

     /*Single precision "Not a Number"*/
     #define NaNf necromancer_float_class::_nanf._x
     /*Double precision "Not a Number"*/
     #define NaN necromancer_float_class::_nand._x
     /*Single precision Infinity*/
     #define INFINITYf necromancer_float_class::_inff._x
     /*Single precision negative Infinity*/
     #define NEGATIVE_INFINITYf necromancer_float_class::_ninff._x
     /*Double precision Infinity*/
     #define INFINITY necromancer_float_class::_infd._x
     /*Double precision Negative Infinity*/
     #define NEGATIVE_INFINITY necromancer_float_class::_ninfd._x

     /*** IEEE-754 Float Classifications ***/
     /*Even though qNaN and sNaN are practically the same*/
     /*in this library (no errors), it's still nice to detect*/

     /*0.0 (Subnormal in IEEE-754)*/
     #define _FLT_ZERO 0x0000
     /*Signal "Not a Number"*/
     #define _FLT_SNAN 0x0001
     /*Quiet "Not a Number"*/
     #define _FLT_QNAN 0x0002
     /*Infinity*/
     #define _FLT_INFINITY 0x0004
     /*Negative Infinity*/
     #define _FLT_NEG_INFY 0x0005
     /*Normal Floating Point*/
     #define _FLT_NORMAL 0x0006
     /*Subnormal Float*/
     #define _FLT_SUBNORMAL 0x0007

     /*Smallest normal 32-bit float*/
     #define _FLT_EPSILON_ 1.17549435082e-38
     /*Smallest subnormal 32-bit float*/
     #define _FLT_SUB_EPSILON_ 1.40129846432e-45
     /*Largest 32-bit float*/
     #define _FLT_MAX_ 3.40282346639e+38

     /*Smallest normal 64-bit float*/
     #define _DBL_EPSILON_ 2.2250738585072013830902327173324e-308
     /*Smallest subnormal 64-bit float*/
     #define _DBL_SUB_EPSILON_ 4.9405539954293899510135527255649e-324
     /*Largest 64-bit float*/
     #define _DBL_MAX_ 8.9884656743115775427577229730589e+307

     /*12/13/2023*/
     float classify_ieee754_32f(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          if(!(_i._y & 0x7fffffff))
               return _FLT_ZERO;
          if(_i._f_32._exp == 0x000)
               return _FLT_SUBNORMAL;
          if(_i._f_32._exp == 0x0ff)
          {
               if (_i._f_32._mantissa)
                    return (_i._f_32._sign)? _FLT_QNAN : _FLT_SNAN;
               return (_i._f_32._sign)? _FLT_NEG_INFY : _FLT_INFINITY;
          }
          return _FLT_NORMAL;
     }
     /*12/13/2023*/
     double classify_ieee754_64f(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          if(!(_i._y & 0x7fffffffffffffff))
               return _FLT_ZERO;
          if(_i._f_64._exp == 0x000)
               return _FLT_SUBNORMAL;
          if(_i._f_64._exp == 0x7ff)
          {
               if (_i._f_64._mantissa)
                    return (_i._f_64._sign)? _FLT_QNAN : _FLT_SNAN;
               return (_i._f_64._sign)? _FLT_NEG_INFY : _FLT_INFINITY;
          }
          return _FLT_NORMAL;
     }

     /*12/13/2023*/
     /*Classify a 32-bit float*/
     float classify(const float& _x)
     {
          return classify_ieee754_32f(_x);
     }
     /*12/13/2023*/
     /*Classify a 64-bit float*/
     double classify(const double& _x)
     {
          return classify_ieee754_64f(_x);
     }
     /*12/13/2023*/
     /*Classify any number as if it were a 64-bit float (regular conversion)*/
     template<typename _flt>
     double classify(const _flt& _x)
     {
          return classify_ieee754_64f((double) _x);
     }

     /*12/13/2023*/
     bool is_inff(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          /*|_x|*/
          _i._y &= 0x7fffffff;
          return classify(_i._x) == _FLT_INFINITY;
     }
     /*12/13/2023*/
     bool is_infd(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          /*|_x|*/
          _i._y &= 0x7fffffffffffffff;
          return classify(_i._x) == _FLT_INFINITY;
     }

     bool is_finitef(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          return _i._f_32._exp < 0x0ff;
     }
     bool is_finited(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          return _i._f_64._exp < 0x7ff;
     }

     /*12/13/2023*/
     bool is_nanf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          /*|_x|*/
          _i._y &= 0x7fffffff;
          return _i._y > 0x7f800000;
     }
     /*12/13/2023*/
     bool is_nand(const double& _x)
     {
          float_32 _i;
          _i._x = _x;
          /*|_x|*/
          _i._y &= 0x7fffffffffffffff;
          return _i._y > 0x7ff0000000000000;
     }

     bool is_qnanf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          return _i._y > 0x7f800000 && _i._y < 0x80000000;
     }
     bool is_qnand(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          return _i._y > 0x7ff0000000000000 && _i._y < 0x8000000000000000;
     }

     bool is_snanf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          return _i._y > 0xff800000;
     }
     bool is_snand(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          return _i._y > 0xfff0000000000000;
     }

     /*12/8/2023*/
     bool is_positivef(const float& _x)
     {
          if(is_nanf(_x))
               return false;
          float_32 _i;
          _i._x = _x;
          return _i._x < 0x80000000;
     }
     /*12/8/2023*/
     bool is_positived(const double& _x)
     {
          if(is_nand(_x))
               return false;
          float_64 _i;
          _i._x = _x;
          return _i._x < 0x8000000000000000;
     }

     /*12/8/2023*/
     bool is_negativef(const float& _x)
     {
          if(is_nanf(_x))     
               return false;
          float_32 _i;
          _i._x = _x;
          return _i._x > 0x80000000;
     }
     /*12/8/2023*/
     bool is_negatived(const double& _x)
     {
          if(is_nand(_x))
               return false;
          float_64 _i;
          _i._x = _x;
          return _i._x > 0x8000000000000000;
     }

     /*12/8/2023*/
     bool is_intf(const float& _x)
     {
          if(is_nanf(_x) || is_inff(_x))
               return false;
          float_32 _i;
          _i._x = _x;
          return _i._y << (_i._f_32._exp - 0x076) == 0;
     }
     /*12/8/2023*/
     bool is_intd(const double& _x)
     {
          if(is_nand(_x) || is_infd(_x))
               return false;
          float_64 _i;
          _i._x = _x;
          return _i._f_64._mantissa << (_i._f_64._exp - 0x03ff) == 0; 
     }
     /*12/8/2023*/
     /*Return true if a 32-bit float can be expressed as an integer*/
     bool is_int(const float& _x)
     {
          return is_intf(_x);
     }
     /*12/8/2023*/
     /*Return true if a 64-bit float can be expressed as an integer*/
     bool is_int(const double& _x)
     {
          return is_intd(_x);
     }

     /*12/8/2023*/
     bool is_decimalf(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          if(is_nanf(_x) || is_inff(_x))
               return false;
          return (_i._f_32._mantissa | 0x400000) != 0x400000;
     }
     /*12/8/2023*/
     bool is_decimald(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          if(is_nand(_x) || is_infd(_x))
               return false;
          return (_i._f_64._mantissa | 0x8000000000000) != 0x8000000000000;
     }
     /*12/8/2023*/
     /*Return true if a 32-bit float cannot be expressed as an integer*/
     bool is_decimal(const float& _x)
     {
          return is_decimalf(_x);
     }
     /*12/8/2023*/
     /*Return true if a 64-bit float cannot be expressed as an integer*/
     bool is_decimal(const double& _x)
     {
          return is_decimald(_x);
     }

     /*12/8/2023*/
     float nextafterf(const float& _x, const float& _y)
     {
          float_32 _fx, _fy;
          _int32 _ix, _iy;
          _fx._x = _x;
          _fy._x = _y;
          /*|_x|*/
          _ix = _fx._y & 0x7fffffff;
          /*|_y|*/
          _iy = _fy._y & 0x7fffffff;
          /*_x or _y is NaN*/
          if(_ix > 0x7f800000 || _iy > 0x7f800000)
               return _x + _y;
          if(_ix == _iy)
               return _y;
          if(_ix == 0x000)
          {
               /*Return +-_FLT_SUB_EPSILON_*/
               _ix = (_ix & 0x80000000) | 1;
               _fx._y = _ix;
               return _fx._x;
          }
          /*If _fx._y is less than the sign bit. Used to check if _x is positive*/
          if(_fx._y < 0x80000000 && _fx._y >= 0)
          {
               if(_ix > _iy)
                    _fx._y --;
               else
                    _fx._y ++;
          }
          else
          {
               if(_ix > _iy || _y >= 0)
                    _ix ++;
               else
                    _ix --;
          }
          _fx._y = _ix;
          return _fx._x;
     }
     /*12/8/2023*/
     double nextafterd(const double& _x, const double& _y)
     {
          float_64 _fx, _fy;
          _int64 _ix, _iy, _aix, _aiy;
          _fx._x = _x;
          _fy._y = _y;
          _ix = _fx._y;
          _iy = _fy._y;
          /*|_x|*/
          _aix = _ix & 0x7fffffffffffffff;
          /*|_y|*/
          _aiy = _iy & 0x7fffffffffffffff;
          /*_x or _y is NaN*/
          if(_aix > 0x7ff0000000000000 || _aiy > 0x7ff0000000000000)
               return _x + _y;
          if(_ix == _iy)
               return _y;
          if(_aix == 0x000)
          {
               /*Return +-_FLT_SUB_EPSILON_*/
               _ix = (_ix & 8000000000000000) | 0x001;
               _fx._y = _ix;
               return _fx._x;
          }
          if(_aix > 0x000)
          {
               if(_ix > _iy)
                    _ix --;
               else
                    _ix ++;
          }
          else
          {
               if(_ix > _iy)
                    _ix --;
               else
                    _ix ++;
          }
          _fx._y = _ix;
          return _fx._x;
     }
     /*12/8/2023*/
     /*Return the next representable 32-bit float after _x towards _y*/
     float nextafter(const float& _x, const float& _y)
     {
          return nextafterf(_x, _y);
     }
     /*12/8/2023*/
     /*Return the next representable 64-bit float after _x towards _y*/
     double nextafter(const double& _x, const double& _y)
     {
          return nextafterd(_x, _y);
     }
     /*12/18/2023*/
     /*Divide a 32-bit float by 2 (fast!)*/
     float f32o2(const float& _x)
     {
          float_32 _i;
          _i._x = _x;
          _i._f_32._exp --;
          return _i._x;
     }
     /*12/18/2023*/
     /*Divide a 64-bit float by 2 (fast!)*/
     double f64o2(const double& _x)
     {
          float_64 _i;
          _i._x = _x;
          _i._f_64._exp --;
          return _i._x;
     }
}

#endif /*_NECROMANCER_FLOAT_CLASS_*/