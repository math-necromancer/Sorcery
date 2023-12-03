/*The Math Necromancer*/

#ifndef __SIGN__
#define __SIGN__

#include "float_class.hpp"

template<typename T>
int sign(const T& _x)
{
     return _x > 0? 1: -1;
}

template<typename _S>
_S sign_bitf(const float &_x)
{
     float_32 _i;
     _i._x = _x;
     return _i._f_32._sign;
}
template<typename _S>
_S sign_bitd(const double& _x)
{
     float_64 _i;
     _i._x = _x;
     return _i._f_64._sign;
}

float fsign_bitf(const float& _x)
{
     return sign_bitf<float>(_x);
}
float fsign_bitd(const double& _x)
{
     return sign_bitd<double>(_x);
}
double dsign_bitf(const float& _x)
{
     return sign_bitf<double>(_x);
}
double dsign_bitd(const double& _x)
{
     return sign_bitd<double>(_x);
}

float sign_bit(const float& _x)
{
     return fsign_bitf(_x);
}
double sign_bit(const double _x)
{
     return dsign_bitd(_x);
}

#endif /*__SIGN__*/