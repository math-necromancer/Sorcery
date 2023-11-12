/*The Math Necromancer*/

#ifndef __FRACTIONS__
#define __FRACTIONS__

#include "gcf.hpp"
#include "lcm.hpp"

namespace necromancer_fractions
{
     class fraction;
     class mixed;

     fraction frac(const mixed& _m);
     mixed mix(const fraction& _f);
     fraction purify(const fraction& _f);
     fraction form_of_1(const int& _n);
     fraction simplify(const fraction& _f);

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

               fraction frac() const
               {
                    return _frac;
               }
               void fraction(const fraction& _f)
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

     fraction fraction::operator = (const fraction& _f)
     {
          _numerator = _f.numerator();
          _denominator = _f.denominator();
          simplify(*this);
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

     fraction frac(const mixed& _m)
     {
          int _n = _m.frac().numerator();
          if(_n == 0)
          {
               return fraction(_m.frac().numerator(), 1);
          }
          int _d = _m.frac().denominator();
          fraction _int_part = fraction(_m.integer() * _d, _d);
          fraction _r = _int_part + _m.frac();
          return _r;
     }
     mixed mix(const fraction& _f)
     {
          fraction _f1 = _f;
          if(_f1.numerator() < _f1.denominator())
          {
               return mixed(0, fraction(_f1.numerator(), _f1.denominator()));
          }
          else if(_f1.numerator() == _f1.denominator())
          {
               return mixed(1, fraction(0, 1));
          }
          int _int_part = _f1.numerator() / _f1.denominator();
          fraction _fractional_part = _f1 - fraction(_int_part * _f1.denominator(), _f1.denominator());
          return mixed(_int_part, _fractional_part);
     }

     /*A Hardcore version of simlification - makes the fraction*/
     /*as nice to look at as possible*/
     fraction purify(const fraction& _f)
     {
          fraction _f1 = _f;
          if(_f1.denominator() < 0)
          {
               _f1.numerator(-_f1.numerator());
               _f1.denominator(-_f1.denominator());
          }
          else if(_f1.denominator() == 0)
          {
               return fraction(0, 0, true);
          }
          else if(_f1.numerator() == 0)
          {
               return fraction(0, 1);
          }
          fraction _r = simplify(_f1);
          return _r;
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
          if(_f1.numerator() == 0)
          {
               return fraction(0, 1);
          }
          else if(_f1.numerator() == 1)
          {
               return _f1;
          }
          else if(_f1.numerator() == 2 && _f1.denominator() % 2 == 0)
          {
               _f1.numerator(1);
               _f1.denominator(_f1.denominator() / 2);
          }
          int _gcf = necromancer_gcf::gcf(_f1.numerator(), _f1.denominator());
          _f1.numerator(_f1.numerator() / _gcf);
          _f1.denominator(_f1.denominator() / _gcf);
          return _f1;
     }
}

#endif /*__FRACTIONS__*/