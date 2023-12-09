/*The Math Necromancer*/

#ifndef __FRACTIONS__
#define __FRACTIONS__

#include "gcf.hpp"
#include "lcm.hpp"
#include "abs.hpp"

namespace necromancer_fractions
{
     class fraction;
     class mixed;

     /*Return the value of a fraction as a float*/
     float evalf(const fraction& _f);
     /*Return the value of a fraction as a double*/
     double evald(const fraction& _f);
     /*Return the value of a fraction as a long double*/
     long double evall(const fraction& _f);
     /*eval() returns double*/
     double eval(const fraction& _f);
     /*Return the value of a mixed number as a float*/
     float m_evalf(const mixed& _m);
     /*Return the value of a mixed number as a double*/
     double m_evald(const mixed& _m);
     /*Return the value of a mixed number as a long double*/
     long double m_evall(const mixed& _m);
     /*m_eval() returns double*/
     double m_eval(const mixed& _m);
     /*Return the Absolute Value of a fraction*/
     fraction abs(const fraction& _f);
     /*Convert a mixed number to a fraction*/
     fraction frac(const mixed& _m);
     /*Convet a fraction to a mixed number*/
     mixed mix(const fraction& _f);
     /*Return a fraction that evaluates to 1 with numerator*/
     /*and denominator values of an integer _n*/
     fraction form_of_1(const int& _n);
     /*Simplify a Fraction*/
     fraction simplify(const fraction& _f);
     /*Hardcore version of simplification. Makes the fraction*/
     /*as nice to look at as possible*/
     fraction purify(const fraction& _f);

     class fraction
     {
          private:
               int _numerator, _denominator;
               bool _err_state = false;
          public:
               int numerator() const
               {
                    return _numerator;
               }
               void numerator(int _num_val)
               {
                    _numerator = _num_val;
               }
               int denominator() const
               {
                    return _denominator;
               }
               void denominator(int _den_val)
               {
                    _denominator = _den_val;
               }

               bool err() const
               {
                    return _err_state;
               }
               void err(bool _err_val)
               {
                    _err_state = _err_val;
               }

               fraction()
                    : _numerator(1), _denominator(1), _err_state(false)
               {}
               fraction(int _n, int _d)
                    : _numerator(_n), _denominator(_d), _err_state(false)
               {}
               fraction(int _n, int _d, bool _err)
                    : _numerator(_n), _denominator(_d), _err_state(_err)
               {}

               fraction operator = (const int& _n);
               fraction operator += (const int& _n);
               fraction operator -= (const int& _n);
               fraction operator *= (const int& _n);
               fraction operator /= (const int& _n);

               fraction operator = (const fraction& _f);
               fraction operator += (const fraction& _f);
               fraction operator -= (const fraction& _f);
               fraction operator *= (const fraction& _f);
               fraction operator /= (const fraction& _f);
     };

     class mixed
     {
          private:
               int _integer;
               fraction _frac;
               bool _err_state = false;
          public:
               int integer() const
               {
                    return _integer;
               }
               void integer(const int& _i)
               {
                    _integer = _i;
               }

               fraction fractional() const
               {
                    return _frac;
               }
               void fractional(const fraction& _f)
               {
                    _frac = _f;
               }

               bool err() const
               {
                    return _err_state;
               }
               void err(const bool& _err)
               { 
                    _err_state = _err;
               }

               mixed()
                    : _integer(0), _frac(1, 1)
               {}
               mixed(int _i)
                    : _integer(_i)
               {}
               mixed(int _i, necromancer_fractions::fraction _f)
                    : _integer(_i), _frac(_f)
               {}
               mixed(int _i, necromancer_fractions::fraction _f, bool _err)
                    : _integer(_i), _frac(_f), _err_state(_err)
               {}

               mixed operator = (const int& _n);
               mixed operator += (const int& _n);
               mixed operator -= (const int& _n);
               mixed operator *= (const int& _n);
               mixed operator /= (const int& _n);

               mixed operator = (const mixed& _f);
               mixed operator += (const mixed& _f);
               mixed operator -= (const mixed& _f);
               mixed operator *= (const mixed& _f);
               mixed operator /= (const mixed& _f);
     };

     /*Sorry, but the results of operations won't be nice.*/
     /*For some reason, purifying the fractions in the operation code*/
     /*crashes all the things :(*/

     fraction fraction::operator = (const fraction& _f)
     {
          _numerator = _f.numerator();
          _denominator = _f.denominator();
          return *this;
     }
     fraction fraction::operator = (const int& _n)
     {
          _numerator = _n;
          _denominator = 1;
          return *this;
     }

     fraction fraction::operator += (const fraction& _f)
     {
          fraction _f1 = _f;
          if(_denominator == _f1.denominator())
          {
               *this = fraction(_numerator + _f1.numerator(), _denominator);
               return *this;
          }
          else if(_f1.numerator() == 0)
          {
               return *this;
          }
          else if(_numerator == 0)
          {
               *this = _f1;
               return *this;
          }
          int _common_denominator = necromancer_lcm::lcm(_denominator, _f1.denominator());
          *this *= form_of_1(_common_denominator / _denominator);
          _f1 *= form_of_1(_common_denominator / _f1.denominator());
          _numerator += _f1.numerator();
          return *this;
     }
     fraction fraction::operator += (const int& _n)
     {
          _numerator += (_n * _denominator);
          return *this;
     }

     fraction fraction::operator -= (const fraction& _f)
     {
          fraction _f1 = _f;
          if(_denominator == _f1.denominator())
          {
               *this = fraction(_numerator - _f1.numerator(), _denominator);
               return *this;
          }
          else if(_f1.numerator() == 0)
          {
               return *this;
          }
          else if(_numerator == 0)
          {
               *this = fraction(-_f1.numerator(), _f1.denominator());
               return *this;
          }
          int _common_denominator = necromancer_lcm::lcm(_denominator, _f1.denominator());
          *this *= form_of_1(_common_denominator / _denominator);
          _f1 *= form_of_1(_common_denominator / _f1.denominator());
          _numerator -= _f1.numerator();
          return *this;
     }
     fraction fraction::operator -= (const int& _n)
     {
          _numerator -= (_n * _denominator);
          return *this;
     }

     fraction fraction::operator *= (const fraction& _f)
     {
          _numerator *= _f.numerator();
          _denominator *= _f.denominator();
          return *this;
     }
     fraction fraction::operator *= (const int& _n)
     {
          _numerator *= _n;
          return *this;
     }

     fraction fraction::operator /= (const fraction& _f)
     {
          _numerator *= _f.denominator();
          _denominator *= _f.numerator();
          return *this;
     }
     fraction fraction::operator /= (const int& _n)
     {
          _denominator *= _n;
          return *this;
     }

     fraction operator + (const fraction& _f)
     {
          return _f;
     }
     fraction operator - (const fraction& _f)
     {
          return fraction(-_f.numerator(), _f.denominator());
     }

     fraction operator + (const fraction& _x, const fraction& _y)
     {
          fraction _r = _x;
          _r += _y;
          return _r;
     }
     fraction operator + (const fraction& _x, const int& _y)
     {
          fraction _r = _x;
          _r += _y;
          return _r;
     }
     fraction operator + (const int& _x, const fraction& _y)
     {
          fraction _r = _y;
          _r += _x;
          return _r;
     }

     fraction operator - (const fraction& _x, const fraction& _y)
     {
         fraction _r = _x;
         _r -= _y;
         return _r; 
     }
     fraction operator - (const fraction& _x, const int& _y)
     {
          fraction _r = _x;
          _r -= _y;
          return _r;
     }
     fraction operator - (const int& _x, const fraction& _y)
     {
          fraction _r = -_y;
          _r += _x;
          return _r;
     }

     fraction operator * (const fraction& _x, const fraction& _y)
     {
          fraction _r = _x;
          _r *= _y;
          return _r;
     }
     fraction operator * (const fraction& _x, const int& _y)
     {
          fraction _r = _x;
          _r *= _y;
          return _r;
     }
     fraction operator * (const int& _x, const fraction& _y)
     {
          fraction _r = _y;
          _r *= _x;
          return _r;
     }

     fraction operator / (const fraction& _x, const fraction& _y)
     {
          fraction _r = _x;
          _r /= _y;
          return _r;
     }
     fraction operator / (const fraction& _x, const int& _y)
     {
          fraction _r = _x;
          _r /= _y;
          return _r;
     }
     fraction operator / (const int& _x, const fraction& _y)
     {
          fraction _r = _y;
          _r /= _x;
          return _r;
     }

     mixed mixed::operator = (const mixed& _m)
     {
          _integer = _m.integer();
          _frac = _m.fractional();
          return *this;
     }
     mixed mixed::operator = (const int& _n)
     {
          _integer = _n;
          _frac = 0;
          return *this;
     }

     mixed mixed::operator += (const mixed& _m)
     {
          fraction _x = frac(*this);
          fraction _y = frac(_m);
          _x += _y;
          *this = mix(_x);
          return *this;
     }
     mixed mixed::operator += (const int& _n)
     {
          _integer += _n;
          return *this;
     }

     mixed mixed::operator -= (const mixed& _m)
     {
          fraction _x = frac(*this);
          fraction _y = frac(_m);
          _x -= _y;
          *this = mix(_x);
          return *this;
     }
     mixed mixed::operator -= (const int& _n)
     {
          _integer -= _n;
          return *this;
     }

     mixed mixed::operator *= (const mixed& _m)
     {
          fraction _x = frac(*this);
          fraction _y = frac(_m);
          _x *= _y;
          *this = mix(_x);
          return *this;
     }
     mixed mixed::operator *= (const int& _n)
     {
          fraction _f = frac(*this);
          _f *= _n;
          *this = mix(_f);
          return *this;
     }

     mixed mixed::operator /= (const mixed& _m)
     {
          fraction _x = frac(*this);
          fraction _y = frac(_m);
          _x /= _y;
          *this = mix(_x);
          return *this;
     }
     mixed mixed::operator /= (const int& _n)
     {
          fraction _f = frac(*this);
          _f /= _n;
          *this = mix(_f);
          return *this;
     }

     mixed operator + (const mixed& _m)
     {
          return _m;
     }
     mixed operator - (const mixed& _m)
     {
          return mixed(-_m.integer(), -_m.fractional());
     }

     mixed operator + (const mixed& _x, const mixed& _y)
     {
          mixed _r = _x;
          _r += _y;
          return _r;
     }
     mixed operator + (const mixed& _x, const int& _y)
     {
          mixed _r = _x;
          _r += _y;
          return _r;
     }
     mixed operator + (const int& _x, const mixed& _y)
     {
          mixed _r = _y;
          _r += _x;
          return _r;
     }

     mixed operator - (const mixed& _x, const mixed& _y)
     {
          mixed _r = _x;
          _r -= _y;
          return _r;
     }
     mixed operator - (const mixed& _x, const int& _y)
     {
          mixed _r = _x;
          _r -= _y;
          return _r;
     }
     mixed operator - (const int& _x, const mixed& _y)
     {
          mixed _r = -_y;
          _r += _x;
          return _r;
     }

     mixed operator * (const mixed& _x, const mixed& _y)
     {
          mixed _r = _x;
          _r *= _y;
          return _r;
     }
     mixed operator * (const mixed& _x, const int& _y)
     {
          mixed _r = _x;
          _r *= _y;
          return _r;
     }
     mixed operator * (const int& _x, const mixed& _y)
     {
          mixed _r = _y;
          _r *= _x;
          return _r;
     }
     
     mixed operator / (const mixed& _x, const mixed& _y)
     {
          mixed _r = _x;
          _r /= _y;
          return _r;
     }
     mixed operator / (const mixed& _x, const int& _y)
     {
          mixed _r = _x;
          _r /= _y;
          return _r;
     }
     mixed operator / (const int& _x, const mixed& _y)
     {
          mixed _r = _x;
          _r /= _y;
          return _r;
     }

     bool operator == (const fraction& _x, const fraction& _y)
     {
          fraction _s_x = purify(_x);
          fraction _s_y = purify(_y);
          return (_s_x.numerator() == _s_y.numerator() && _s_x.denominator() == _s_y.denominator());
     }
     template<typename _F>
     bool operator == (const fraction& _x, const _F& _y)
     {
          fraction _s_x = purify(_x);
          return (_s_x.numerator() == _y && _s_x.denominator() == 1);
     }
     template<typename _F>
     bool operator == (const _F& _x, const fraction& _y)
     {
          fraction _s_y = purify(_y);
          return (_s_y.numerator() == _x && _s_y.denominator() == 1);
     }

     bool operator != (const fraction& _x, const fraction& _y)
     {
          fraction _s_x = purify(_x);
          fraction _s_y = purify(_y);
          return (_s_x.numerator() != _s_y.numerator() || _s_x.denominator() != _s_y.denominator());
     }
     template<typename _F>
     bool operator != (const fraction& _x, const _F& _y)
     {
          fraction _s_x = purify(_x);
          return (_s_x.numerator != _y || _s_x.denominator() != 1);
     }
     template<typename _F>
     bool operator != (const _F& _x, const fraction& _y)
     {
          fraction _s_y = purify(_y);
          return (_s_y.numerator() != _x || _s_y.denominator() != 1);
     }

     bool operator > (const fraction& _x, const fraction& _y)
     {
          if(_x.denominator() == _y.denominator())
          {
               return (_x.numerator() > _x.denominator());
          }
          /*Cross multiplying method*/
          return (_x.numerator() * _y.denominator() > _x.denominator() * _y.numerator());
     }
     template<typename _F>
     bool operator > (const fraction& _x, const _F& _y)
     {
          if(_x.numerator() > (_y * _x.denominator()))
          {
               return true;
          }
          return (_x > fraction(_y, 1));
     }
     template<typename _F>
     bool operator < (const _F& _x, const fraction& _y);

     template<typename _F>
     bool operator > (const _F& _x, const fraction& _y)
     {
          if(_y.numerator() > (_x * _y.denominator()))
          {
               return true;
          }
          return (_y < fraction(_x, 1));
     }

     bool operator < (const fraction& _x, const fraction& _y)
     {
          if(_x.denominator() == _y.denominator())
          {
               return (_x.numerator() < _y.denominator());
          }
          /*Cross multiplying method*/
          return (_x.numerator() * _y.denominator() < _x.denominator() * _y.numerator()); 
     }
     template<typename _F>
     bool operator < (const fraction& _x, const _F& _y)
     {
          if(_x.numerator() < (_y * _x.denominator()))
          {
               return true;
          }
          return (_x < fraction(_y, 1));
     }
     template<typename _F>
     bool operator < (const _F& _x, const fraction& _y)
     {
          if(_y.numerator() < (_x * _y.denominator()))
          {
               return true;
          }
          return (_y > fraction(_x, 1));
     }

     float evalf(const fraction& _f)
     {
          return (float) _f.numerator() / _f.denominator();
     }
     double evald(const fraction& _f)
     {
          return (double) _f.numerator() / _f.denominator();
     }
     long double evall(const fraction& _f)
     {
          return (long double) _f.numerator() / _f.denominator();
     }
     /*eval() returns double*/
     double eval(const fraction& _f)
     {
          return evald(_f);
     }
     /*For other types, use evalf() for float,*/
     /* or evall() for long double*/

     float m_evalf(const mixed& _m)
     {
          return _m.integer() + evalf(_m.fractional());
     }
     double m_evald(const mixed& _m)
     {
          return _m.integer() + evald(_m.fractional());
     }
     long double m_evall(const mixed& _m)
     {
          return _m.integer() + evall(_m.fractional());
     }
     /*m_eval() returns double*/
     double m_eval(const mixed& _m)
     {
          return m_evald(_m);
     }
     /*For other types, use m_evalf() for float,*/
     /*or m_evall() for long double*/

     fraction frac(const mixed& _m)
     {
          int _n = _m.fractional().numerator();
          if(_n == 0)
          {
               return fraction(_m.fractional().numerator(), 1);
          }
          int _d = _m.fractional().denominator();
          fraction _int_part = fraction(_m.integer() * _d, _d);
          fraction _r = purify(_int_part + _m.fractional());
          return _r;
     }
     mixed mix(const fraction& _f)
     {
          fraction _f1 = _f;
          if(absolute::abs(_f1.numerator()) < absolute::abs(_f1.denominator()))
          {
               return mixed(0, fraction(_f1.numerator(), _f1.denominator()));
          }
          else if(_f1.numerator() == _f1.denominator())
          {
               return mixed(1, fraction(0, 1));
          }
          int _int_part = _f1.numerator() / _f1.denominator();
          fraction _fractional_part = purify(_f1 - fraction(_int_part * _f1.denominator(), _f1.denominator()));
          return mixed(_int_part, _fractional_part);
     }
     
     fraction abs(const fraction& _f)
     {
          return fraction(absolute::abs(_f.numerator()), absolute::abs(_f.denominator()));
     }

     fraction form_of_1(const int& _n)
     {
          if(_n == 0)
          {
               return fraction(1, 1);
          }
          return fraction(_n, _n);
     }
     fraction simplify(const fraction& _f)
     {
          fraction _f1 = _f;
          int _gcf = necromancer_gcf::gcf(absolute::abs(_f1.numerator()), absolute::abs(_f1.denominator()));
          _f1.numerator(_f1.numerator() / _gcf);
          _f1.denominator(_f1.denominator() / _gcf);
          return _f1;
     }
     /*A Hardcore version of simlification - makes the fraction*/
     /*as nice to look at as possible*/
     fraction purify(const fraction& _f)
     {
          fraction _f1 = _f;
          if(_f1.denominator() == 0)
          {
               return fraction(0, 0, true);
          }
          else if(_f1.numerator() == 0)
          {
               return fraction(0, 1);
          }
          int mult = 1;
          if(_f1.numerator() < 0 ^ _f1.denominator() < 0)
          {
               mult = -1;
          }
          _f1 = abs(_f1) * mult;
          fraction _r = simplify(_f1);
          return _r;
     }
}

#endif /*__FRACTIONS__*/