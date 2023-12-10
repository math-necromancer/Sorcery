/*The Math Necromancer*/

/*============ The Natural Logarithm ============*/
/*Computes log(x) on an IEEE-754 Machine*/

#ifndef _NECROMANCER_LOG_
#define _NECROMANCER_LOG_

#include "float_class.hpp"

const static long double
     log2_h = 6.93147180369123816490e-01,
     log2_l = 1.90821492927232121458e-10,

     /*Minimax coeficcients for 2 * arctanh(x)*/

     log1 = 6.66666666666667653654896829047862109605e-01,
     log2 = 3.99999999996639180070480580779767357622e-01,
     log3 = 2.85714286985476106491309914245597720749e-01,
     log4 = 2.22222024077476110197597399876978069272e-01,
     log5 = 1.81833876328594532366358057253631240618e-01,
     log6 = 1.53181571233880298729095145342556944283e-01,
     log7 = 1.47580071554569676223389696418304199218e-01;

     /*Less precise (2 / (2i + 1)) as i increments from 1 - 7*/
     // log1 = 6.66666666666666666666666666666666666666e-01,
     // log2 = 4.00000000000000000000000000000000000000e-01,
     // log3 = 2.85714285714285714285714285714285714285e-01,
     // log4 = 2.22222222222222222222222222222222222222e-01,
     // log5 = 1.81818181818181818181818181818181818181e-01,
     // log6 = 0.15384615384615384615384615384615384615e-01,
     // log7 = 1.33333333333333333333333333333333333333e-01;

     /*Sometimes, log8 and log9 need to be defined for precision*/
     /* 2/17 */
     // log8 = 5.88235294117647058823529411764705882352e-02,
     /* 2/19 */
     // log9 = 5.26315789473684210526315789473684210526e-02; 

/*Compute the Natural Logarithm of _x*/
/*Reduce the Range of _x*/
/*   Given an IEEE-754 Machine, find an f and e where _x = (f + 1) * 2^e:*/
/*        sqrt(2)/2 < (f - 1) < sqrt(2)*/
/*   log(x) = log((f - 1) * 2^e) = (log(f - 1) + elog(2)) via properties of log(x)*/
/*   Solution: Set y to the exponent part of a Floating point value. Now calculate*/
/*   log(f - 1) and let log(2) be a constant - now elog(2) is constant. For _f, it*/
/*   is simply a modification of the Mantissa of _x after setting the exponent correctly*/
/*   Return log(f + 1) + elog(2)*/
/*   Remember, e is not Euler's number in this situation*/
/*Computation of log(f - 1)*/
/*   The informed reader may recall that log(_x) = 2 * arctanh((_x - 1) / (_x + 1))*/
/*   We have a series for arctanh(_x), which we can truncate to ~7 terms.*/
/*                 1        3        5        7   */
/*   arctanh(x) = x + (1/3)x + (1/5)x + (1/7)x ...*/
/*   This is the formula shown in the functions below. We put in _f / (_f + 2), as*/
/*   _f has been decremented already. Then we just return our result scaled back up*/

/*12/3/2023*/
/*Compute the Natural Logarithm of _x*/
float logf(const float& _x)
{
     float_32 _i;
     _i._x = _x;
     /*Special Cases...*/
     if(_i._y == 0x3f800000)
          /*log(1) = 0.0*/
          return 0x000;
     if(_i._y == 0x7f800000)
          /*log(inf) = inf*/
          return INFINITYf;
     if(!_i._y)
          /*log(0^+) -> -inf*/
          return NEGATIVE_INFINITYf;
     if(_i._y > 0x7f800000 || _i._f_32._sign)
          /*log(_x) for _x < 0 or is_nan(_x) is undefined; this includes -0*/
          return NaNf;
     float _e, _f, _s, _z, _z2, _t1, _t2, _r, _hfsq;
     _e = _i._f_32._exp - 0x07e;
     _i._f_32._exp = 0x07e;
     _f = _i._x;
     /*Reduce the range of _f further*/
     if(_i._f_32._mantissa < 0x3504f3)
     {
          _f *= 2;
          /*When doubling _f, you need to subtract from the exponent as well*/
          _e --;
     }
     _f --;
     _s = _f / (_f + 0x002);
     _z = _s * _s;
     _z2 = _z * _z;
     _t1 = _z * (log1 + _z2 * (log3 + _z2 * (log5 + _z2 * log7)));
     _t2 = _z2 * (log2 + _z2 * (log4 + _z2 * log6));
     _r = _t1 + _t2;
     _hfsq = 0.5f * _f * _f;
     /*We can't just return _e * log(2). It isn't precise enough*/
     return _e * log2_h - ((_hfsq - (_s * (_hfsq + _r) + _e * log2_l)) - _f);
}
/*12/3/2023*/
/*Compute the Natural Logarithm of _x*/
double logd(const double& _x)
{
     float_64 _i;
     _i._x = _x;
     /*Special Cases*/
     if(_i._y == 0x3f800000)
          /*log(1) = 0.0*/
          return 0x00000000;
     if(_i._y == 0x7ff0000000000000)
          /*log(inf) = inf*/
          return INFINITY;
     if(!_i._y)
          /*log(0^+) -> -inf*/
          return NEGATIVE_INFINITY;
     if(_i._y > 0x7ff0000000000000 || _i._f_64._sign)
          /*log(_x) for _x < 0 or is_nan(_x) is undefined; this includes -0*/
          return NaN;
     double _e, _f, _s, _z, _z2, _t1, _t2, _r, _hfsq;
     _e = _i._f_64._exp - 0x03fe;
     _i._f_64._exp = 0x03fe;
     _f = _i._x;
     /*Reduce the range of _f further*/
     if(_i._f_64._mantissa < 0x3ff6a09e667f3bcd)
     {
          _f *= 2;
          /*When doubling _f, you need to subtract from the exponent as well*/
          _e --;
     }
     _f --;
     _s = _f / (_f + 0x002) ;
     _z = _s * _s;
     _z2 = _z * _z;
     _t1 = _z * (log1 + _z2 * (log3 + _z2 * (log5 + _z2 * log7)));
     _t2 = _z2 * (log2 + _z2 * (log4 + _z2 * log6));
     _r = _t1 + _t2;                           
     _hfsq = 0.5 * _f * _f;
     /*We can't just return _e * log(2). It isn't precise enough*/
     return _e * log2_h - ((_hfsq - (_s * (_hfsq + _r) + _e * log2_l)) - _f);
}

#endif /*_NECROMANCER_LOG_*/