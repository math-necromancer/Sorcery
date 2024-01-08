/*The Math Necromancer*/

#ifndef _NECROMANCER_RATIO_
#define _NECROMANCER_RATIO_

#include "math_sorcery.hpp"

namespace sorcery
{
     /**
      * @brief Standard ratio / fraction class
      * 
      * @param _ratio_ty the type of the numerator and denominator
     */
     template<typename _ratio_ty = _s_int32>
     class ratio
     {
          private:
               _ratio_ty _numer, _denom;
          public:
               _ratio_ty numerator() const
               {
                    return _numer;
               };
               _ratio_ty denominator() const
               {
                    return _denom;
               }
               bool true_ratio = 
                    sorcery::numeric_limits<_ratio_ty>::is_integer;

               constexpr ratio<_ratio_ty> operator = (const _ratio_ty& _s);
               constexpr ratio<_ratio_ty> operator += (const _ratio_ty& _s);
               constexpr ratio<_ratio_ty> operator -= (const _ratio_ty& _s);
               constexpr ratio<_ratio_ty> operator *= (const _ratio_ty& _s);
               constexpr ratio<_ratio_ty> operator /= (const _ratio_ty& _s);

               constexpr ratio<_ratio_ty> operator = (const ratio<_ratio_ty>& _r);
               constexpr ratio<_ratio_ty> operator += (const ratio<_ratio_ty>& _r);
               constexpr ratio<_ratio_ty> operator -= (const ratio<_ratio_ty>& _r);
               constexpr ratio<_ratio_ty> operator *= (const ratio<_ratio_ty>& _r);
               constexpr ratio<_ratio_ty> operator /= (const ratio<_ratio_ty>& _r);

               ratio()
                    : _numer(0), _denom(1)
               {}
               ratio(const _ratio_ty& _s)
                    : _numer(_s), _denom(1)
               {}
               ratio(const _ratio_ty& _n, const _ratio_ty& _d)
                    : _numer(_n * sorcery::sign(_d) / sorcery::gcf(_n, _d)),
                    _denom(sorcery::abs(_d) / sorcery::gcf(_n, _d))
               {}
     };
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator = (const _ratio_ty& _s)
     {
          _numer = _s;
          _denom = 1;
          return *this;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator += (const _ratio_ty& _s)
     {
          _numer += _s * _denom;
          /*This line is not useless. It simplifies the fraction*/
          *this = ratio<_ratio_ty>(_numer, _denom);
          return *this;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator -= (const _ratio_ty& _s)
     {
          _numer -= _s * _denom;
          /*This line is not useless. It simplifies the fraction*/
          *this = ratio<_ratio_ty>(_numer, _denom);
          return *this;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator *= (const _ratio_ty& _s)
     {
          _numer *= _s;
          /*This line is not useless. It simplifies the fraction*/
          *this = ratio<_ratio_ty>(_numer, _denom);
          return *this;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator /= (const _ratio_ty& _s)
     {
          _numer /= _s;
          /*This line is not useless. It simplifies the fraction*/
          *this = ratio<_ratio_ty>(_numer, _denom);
          return *this;
     }

     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator = (const ratio<_ratio_ty>& _r)
     {
          _numer = _r.numerator();
          _denom = _r.denominator();
          return *this;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator += (const ratio<_ratio_ty>& _r)
     {
          _numer = _numer * _r.denominator() +
               _denom * _r.numerator();
          _denom *= _r.denominator();
          /*This line is not useless. It simplifies the fraction*/
          *this = ratio<_ratio_ty>(_numer, _denom);
          return *this;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator -= (const ratio<_ratio_ty>& _r)
     {
          _numer = _numer * _r.denominator() -
               _denom * _r.numerator();
          _denom *= _r.denominator();
          /*This line is not useless. It simplifies the fraction*/
          *this = ratio<_ratio_ty>(_numer, _denom);
          return *this;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator *= (const ratio<_ratio_ty>& _r)
     {
          _numer *= _r.numerator();
          _denom *= _r.denominator();
          /*This line is not useless. It simplifies the fraction*/
          *this = ratio<_ratio_ty>(_numer, _denom);
          return *this;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     ratio<_ratio_ty>::operator /= (const ratio<_ratio_ty>& _r)
     {
          _numer *= _r.denominator();
          _denom *= _r.numerator();
          /*This line is not useless. It simplifies the fraction*/
          *this = ratio<_ratio_ty>(_numer, _denom);
          return *this;
     }

     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator + (const ratio<_ratio_ty>& _r)
     {
          /*This line is not useless. It simplifies the fraction*/
          ratio<_ratio_ty> _f = ratio<_ratio_ty>(_r.numerator(), _r.denominator());
          return _f;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator - (const ratio<_ratio_ty>& _r)
     {
          /*This line is not useless. It simplifies the fraction*/
          ratio<_ratio_ty> _f = ratio<_ratio_ty>(_r.numerator(), _r.denominator());
          _f *= -1;
          return _f;
     }

     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator + (const ratio<_ratio_ty>& _x, const ratio<_ratio_ty> _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r += _y;
          return _r;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator + (const ratio<_ratio_ty>& _x, const _ratio_ty& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r += _y;
          return _r;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator + (const _ratio_ty& _x, const ratio<_ratio_ty>& _y)
     {
          ratio<_ratio_ty> _r = _y;
          _r += _x;
          return _r;
     }

     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator - (const ratio<_ratio_ty>& _x, const ratio<_ratio_ty>& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r -= _y;
          return _r;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator - (const ratio<_ratio_ty>& _x, const _ratio_ty& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r -= _y;
          return _r;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator - (const _ratio_ty& _x, const ratio<_ratio_ty>& _y)
     {
          ratio<_ratio_ty> _r = -_y;
          _r += _x;
          return _r;
     }

     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator * (const ratio<_ratio_ty>& _x, const ratio<_ratio_ty>& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r *= _y;
          return _r;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator * (const ratio<_ratio_ty>& _x, const _ratio_ty& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r *= _y;
          return _r;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator * (const _ratio_ty& _x, const ratio<_ratio_ty>& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r *= _y;
          return _r;
     }

     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator / (const ratio<_ratio_ty>& _x, const ratio<_ratio_ty>& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r /= _y;
          return _r;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator / (const ratio<_ratio_ty>& _x, const _ratio_ty& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r /= _y;
          return _r;
     }
     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty>
     operator / (const _ratio_ty& _x, const ratio<_ratio_ty>& _y)
     {
          ratio<_ratio_ty> _r = _x;
          _r /= _y;
          return _r;
     }

     template<typename _ratio_ty, typename _eval_ty = double>
     constexpr _eval_ty eval(const ratio<_ratio_ty>& _r)
     {
          return static_cast<_eval_ty>(_r.numerator()) / _r.denominator();
     }

     /*** acos ***/

     constexpr float acos(const ratio<float>& _r)
     {
          return sorcery::acos(eval<float, float>(_r));
     }
     constexpr double acos(const ratio<double>& _r)
     {
          return sorcery::acos(eval<double, double>(_r));
     }
     template<typename _ratio_ty>
     constexpr double acos(const ratio<_ratio_ty>& _r)
     {
          return sorcery::acos(eval(_r));
     }

     /*** asin ***/

     constexpr float asin(const ratio<float>& _r)
     {
          return sorcery::asin(eval<float, float>(_r));
     }
     constexpr double asin(const ratio<double>& _r)
     {
          return sorcery::asin(eval<double, double>(_r));
     }
     template<typename _ratio_ty>
     constexpr double asin(const ratio<_ratio_ty>& _r)
     {
          return sorcery::asin(eval(_r));
     }

     template<typename _ratio_ty>
     constexpr ratio<_ratio_ty> abs(const ratio<_ratio_ty>& _r)
     {
          constexpr _ratio_ty _x = _r.numerator();
          constexpr _ratio_ty _y = _r.denominator();
          return ratio<_ratio_ty>(sorcery::abs(_x), sorcery::abs(_y));
     }
}

#endif /*_NECROMANCER_RATIO_*/