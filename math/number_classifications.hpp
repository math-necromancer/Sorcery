
#ifndef _NUMBER_CLASS_
#define _NUMBER_CLASS_

#include "constants.hpp"

#ifndef _IEEE_754_CLASS_
#define _IEEE_754_CLASS_
     /*0.0 (Subnormal in IEEE-754)*/
     #define _FLT_ZERO 0x0000
     /*Signal NaN*/
     #define _FLT_SNAN 0x0001
     /*Quiet NaN*/
     #define _FLT_QNAN 0x0002
     /*Infinity*/
     #define _FLT_INFINITY 0x0004
     /*Negative Infinity*/
     #define _FLT_NEG_INFY 0x0005
     /*Normal Floating Point*/
     #define _FLT_NORMAL 0x0006
     /*Subnormal Float*/
     #define _FLT_SUBNORMAL 0x0007
     /*NaN*/
     #define _FLT_NAN 0x1000
#endif /*_IEEE_754_CLASS_*/

typedef unsigned long _32int;
typedef unsigned long long _64int;

/*128-Bit Integer!*/
union _128int
{
    _64int _bits[2]; 
};

/*IEEE-754 Floating-Point Forms*/

/*Long double not supported yet...*/
/*For some reason, all the CPUs do Different Things*/
/* :o */

union float_64
{
     double _x;
     _64int _y;
     struct _f_64
     {
          _64int _mantissa : 52;
          _64int _exp : 11;
          _64int _sign : 1;
     };
     _f_64 _f_64;
};

union float_32
{
     float _x;
     _32int _y;
     struct _f_32
     {
          _32int _mantissa : 23;
          _32int _exp : 8;
          _32int _sign : 1;
     };
     _f_32 _f_32;
};

float classify_ieee754_32f(const float& _x)
{
     float_32 _i;
     _i._x = _x;
     _32int _x_int32 = _i._y;
     if(!_x_int32)
          return _FLT_ZERO;
     if(_x_int32 < 0x00800000)
          return _FLT_SUBNORMAL;
     if(_x_int32 >= 0x7f800000)
     {
          _32int _s = _i._f_32._sign;
          return (_x_int32 > 0x7f800000)?
               ((_s)? _FLT_QNAN : _FLT_SNAN) :
                    ((_s)? _FLT_NEG_INFY : _FLT_INFINITY);
     }
     return _FLT_NORMAL;
}
double classify_ieee754_64f(const double& _x)
{
     float_64 _i;
     _i._x = _x;
     _64int _x_int64 = _i._y;
     if(!_x_int64)
          return _FLT_ZERO;
     if(_x_int64 < 0x10000000000000)
          return _FLT_SUBNORMAL;
     if(_i._f_64._exp >= 0x7ff)
     {
          _64int _s = _i._f_64._sign;
          _64int _m = _i._f_64._mantissa;
          return (_m)?
               ((_s)? _FLT_QNAN : _FLT_SNAN) :
                    ((_s)? _FLT_NEG_INFY : _FLT_INFINITY);
     }
     return _FLT_NORMAL;
}

float classify(const float& _x)
{
     return classify_ieee754_32f(_x);
}
double classify(const double& _x)
{
     return classify_ieee754_64f(_x);
}
template<typename _flt>
double classify(const _flt& _x)
{
     return classify_ieee754_64f((double) _x);
}

bool is_inff(const float& _x)
{
     float_32 _i;
     _i._x = _x;
     return classify(_i._x)
          == _FLT_INFINITY || classify(_i._x)
               == _FLT_NEG_INFY;
}
bool is_infd(const double& _x)
{
     float_64 _i;
     _i._x = _x;
     return classify(_i._x)
          == _FLT_INFINITY || classify(_i._x)
               == _FLT_NEG_INFY;
}
bool is_inf(const float& _x)
{
     return is_inff(_x);
}
bool is_inf(const double& _x)
{
     return is_infd(_x);
}
template<typename _flt>
bool is_inf(const _flt& _x)
{
     return is_infd((double) _x);
}

bool is_finitef(const float& _x)
{
     return (classify(_x)
          != _FLT_ZERO && classify(_x)
               == _FLT_NORMAL || classify(_x)
                    == _FLT_SUBNORMAL);
}
bool is_finited(const double& _x)
{
     return (classify(_x)
          == _FLT_ZERO || classify(_x)
               == _FLT_NORMAL || classify(_x)
                    == _FLT_SUBNORMAL);
}
bool is_finite(const float& _x)
{
     return is_finitef(_x);
}
bool is_finite(const double& _x)
{
     return is_finited(_x);
}
template<typename _flt>
bool is_finite(const _flt& _x)
{
     return is_finited((double) _x);
}

bool is_nanf(const float& _x)
{
     return (classify(_x) == _FLT_QNAN ||
          classify(_x) == _FLT_SNAN);
}
bool is_nand(const double& _x)
{
     return (classify(_x) == _FLT_QNAN ||
          classify(_x) == _FLT_SNAN);
}
bool is_nan(const float& _x)
{
     return is_nanf(_x);    
}
bool is_nan(const double& _x)
{
     return is_nand(_x);
}
template<typename _flt>
bool is_nan(const _flt& _x)
{
     return is_nand((double) _x);
}

bool is_qnanf(const float& _x)
{
     return (classify(_x) == _FLT_QNAN);
}
bool is_qnand(const double& _x)
{
     return (classify(_x) == _FLT_QNAN);
}
bool is_qnan(const float& _x)
{
     return is_qnanf(_x);
}
bool is_qnan(const double& _x)
{
     return is_qnand(_x);
}
template<typename _flt>
bool is_qnan(const _flt& _x)
{
     return is_qnand((double) _x);
}

bool is_snanf(const float& _x)
{
     return (classify(_x) == _FLT_SNAN);
}
bool is_snand(const double& _x)
{
     return (classify(_x) == _FLT_SNAN);
}
bool is_snan(const float& _x)
{
     return is_snanf(_x);
}
bool is_snan(const double& _x)
{
     return is_snand(_x);
}
template<typename _flt>
bool is_snan(const _flt& _x)
{
     return is_snand((double) _x);
}

template<typename _typ>
bool is_positive(const _typ& _x)
{
     if(is_nan(_x))
     {
          return false;
     }
     return _x > 0;
}
template<typename _typ>
bool is_negative(const _typ& _x)
{
     if(is_nan(_x))
     {
          return false;
     }
     return _x < 0;
}

template<typename _typ>
bool is_int(const _typ& _x)
{
     if(is_nan(_x))
     {
          return false;
     }
     return _x == (int) _x;
}

bool is_even(const int& _x)
{
     return !(_x & 1);
}
bool is_odd(const int& _x)
{
     return (_x & 1);
}

template<typename _typ>
bool is_decimal(const _typ& _x)
{
     if(is_nan(_x))
     {
          return false;
     }
     return _x != (int) _x;
}

#endif /*_NUMBER_CLASS_*/