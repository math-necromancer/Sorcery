/*The Math Necromancer*/

#ifndef _NECROMANCER_COMPLEX_
#define _NECROMANCER_COMPLEX_

#ifndef _MATH_SORCERY_
    #ifdef _RAW_FILE_WARN_
        #warning "Are you sure you want to use this raw file instead of math_sorcery.hpp?"
    #endif /*_RAW_FILE_WARN_*/
#endif /*_MATH_SORCERY_*/

#include "math_sorcery.hpp"

namespace sorcery
{
     using namespace sorcery;
     /*12/13/2023*/
     /*Complex Number Class ~ (x + yi)*/
     template<typename _Cx = int>
     class complex
     {
          private:
               _Cx _real, _img;
          public:
               /*Get the real component of a complex number*/
               _Cx real() const
               {
                    return _real;
               }
               /*Set the real component of a complex number*/
               void real(const _Cx& _r)
               {
                    _real = _r;
               }
               /*Get the imaginary component of a complex number*/
               _Cx img() const
               {
                    return _img;
               }
               /*Set the imaginary component of a complex number*/
               void img(const _Cx& _i)
               {
                    _img = _i;
               }
               /*Operations with scalars*/

               constexpr complex<_Cx> operator = (const _Cx& _s);
               constexpr complex<_Cx> operator += (const _Cx& _s);
               constexpr complex<_Cx> operator -= (const _Cx& _s);
               constexpr complex<_Cx> operator *= (const _Cx& _s);
               constexpr complex<_Cx> operator /= (const _Cx& _s);
               /*Operations with other complex numbers*/

               constexpr complex<_Cx> operator = (const complex<_Cx>& _z);
               constexpr complex<_Cx> operator += (const complex<_Cx>& _z);
               constexpr complex<_Cx> operator -= (const complex<_Cx>& _z);
               constexpr complex<_Cx> operator *= (const complex<_Cx>& _z);
               constexpr complex<_Cx> operator /= (const complex<_Cx>& _z);

               /*Default constructor, defaults to 0*/
               complex()
                    : _real(static_cast<_Cx>(0)), _img(static_cast<_Cx>(0))
               {}
               /*Constructor with a scalar*/
               complex(const _Cx& _s)
                    : _real(_s), _img(static_cast<_Cx>(0))
               {}
               /*Constructor with real and imaginary components*/
               complex(const _Cx& _r, const _Cx& _i)
                    : _real(_r), _img(_i)
               {}
               /*Contructor with another complex number*/
               complex(const complex<_Cx>& _z)
                    : _real(_z.real()), _img(_z.img())
               {}
               /*12/25/2023 ~ Christmas!*/
               /*Return i*/
               static constexpr complex<_Cx> i()
               {
                    return complex<_Cx>(static_cast<_Cx>(0),
                                        static_cast<_Cx>(1));
               }
     };
     /*** Modify complex values with operations ***/

     /*12/13/2023*/
     /*Assign a complex number to a scalar*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator = (const _Cx& _s)
     {
          _real = _s;
          _img = 0;
          return *this;
     }
     /*12/13/2023*/
     /*Add a scalar to a complex number*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator += (const _Cx& _s)
     {
          _real += _s;
          return *this;
     }
     /*12/13/2023*/
     /*Subtract a scalar from a complex number*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator -= (const _Cx& _s)
     {
          _real -= _s;
          return *this;
     }
     /*12/13/2023*/
     /*Multiply a complex number by a scalar*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator *= (const _Cx& _s)
     {
          _real *= _s;
          _img *= _s;
          return *this;
     }
     /*12/13/2023*/
     /*Divide a complex number by a scalar*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator /= (const _Cx& _s)
     {
          _real /= _s;
          _img /= _s;
          return *this;
     }
     
     /*12/13/2023*/
     /*Assign one complex number to another*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator = (const complex<_Cx>& _z)
     {
          _real = _z.real();
          _img = _z.img();
          return *this;
     }
     /*12/13/2023*/
     /*Add one complex number to another*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator += (const complex<_Cx>& _z)
     {
          _real += _z.real();
          _img += _z.img();
          return *this;
     }
     /*12/13/2023*/
     /*Subtract one complex number from another*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator -= (const complex<_Cx>& _z)
     {
          _real -= _z.real();
          _img -= _z.img();
          return *this;
     }
     /*12/13/2023*/
     /*Multiply one complex number by another*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator *= (const complex<_Cx>& _z)
     {
          _real = _real * _z.real() - _img * _z.img();
          _img = _real * _z.img() + _img() * _z.real();
          return *this;
     }
     /*12/13/2023*/
     /*Divide one complex number by another*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     complex<_Cx>::operator /= (const complex<_Cx>& _z)
     {
          _Cx _r = _real * _z.real() + _img * _z.img();
          const _Cx _abs2_z = _z.real() * _z.real() + _z.img() * _z.img();
          _img = (_img * _z.real() - _real * _z.img()) / _abs2_z;
          _real = _r / _abs2_z;
          return *this;
     }

     /*** Operators ***/

     /*12/14/2023*/
     /*Return _z*/
     template<typename _Cx>
     inline constexpr bool
     operator + (const complex<_Cx>& _z)
     {
          return _z;
     }
     /*12/14/2023*/
     /*Return the complex negation of _z*/
     template<typename _Cx>
     inline constexpr bool
     operator - (const complex<_Cx>& _z)
     {
          return complex<_Cx>(-_z.real(), -_z.img());
     }

     /*12/13/2023*/
     /*Return a new complex number (_x + _y)*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator + (const complex<_Cx>& _x, const complex<_Cx>& _y)
     {
          complex<_Cx> _r = _x;
          _r += _y;
          return _r;
     }
     /*12/13/2023*/
     /*Return a new complex number _x plus a scalar _y*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator + (const complex<_Cx>& _x, const _Cx& _y)
     {
          complex<_Cx> _r = _x;
          _r += _y;
          return _r;
     }
     /*12/13/2023*/
     /*Return a scalar _x plus a complex number _y*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator + (const _Cx& _x, const complex<_Cx>& _y)
     {
          complex<_Cx> _r = _y;
          _r += _x;
          return _r;
     }

     /*12/13/2023*/
     /*Return a new complex number (_x - _y)*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator - (const complex<_Cx>& _x, const complex<_Cx>& _y)
     {
          complex<_Cx> _r = _x;
          _r -= _y;
          return _r;
     }
     /*12/13/2023*/
     /*Return a new complex number _x minus a scalar _y*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator - (const complex<_Cx>& _x, const _Cx& _y)
     {
          complex<_Cx> _r = _x;
          _r += _y;
          return _r;
     }
     /*12/13/2023*/
     /*Return a scalar _x minus a complex number _y*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator - (const _Cx& _x, const complex<_Cx>& _y)
     {
          complex<_Cx> _r = -_y;
          _r += _x;
          return _r;
     }

     /*12/13/2023*/
     /*Return a new complex number (_x * _y)*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator * (const complex<_Cx>& _x, const complex<_Cx>& _y)
     {
          complex<_Cx> _r = _x;
          _r *= _y;
          return _r;
     }
     /*12/13/2023*/
     /*Return a complex number _x time a scalar _y*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator * (const complex<_Cx>& _x, const _Cx& _y)
     {
          complex<_Cx> _r = _x;
          _x *= _y;
          return _r;
     }
     /*12/13/2023*/
     /*Return a scalar _x times a complex number _y*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator * (const _Cx& _x, const complex<_Cx>& _y)
     {
          complex<_Cx> _r = _x;
          _r *= _y;
          return _r;
     }

     /*12/13/2023*/
     /*Return a new complex number (_x / _y)*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator / (const complex<_Cx>& _x, const complex<_Cx>& _y)
     {
          complex<_Cx> _r = _x;
          _r /= _y;
          return _r;
     }
     /*12/13/2023*/
     /*Return a comlex number _x divided by a scalar _y*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator / (const complex<_Cx>& _x, const _Cx& _y)
     {
          complex<_Cx> _r = _x;
          _r /= _y;
          return _r;
     }
     /*12/13/2023*/
     /*Return a scalar _x divided by a complex number _y*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     operator / (const _Cx& _x, const complex<_Cx>& _y)
     {
          complex<_Cx> _r = _x;
          _r /= _y;
          return _r;
     }

     /*12/13/2023*/
     /*Return true if complex numbers _x and _y are equal*/
     template<typename _Cx>
     inline constexpr bool
     operator == (const complex<_Cx>& _x, const complex<_Cx>& _y)
     {
          return (_x.real() == _y.real() && _x.img() == _y.img());
     }
     /*12/13/2023*/
     /*Return true if a complex number _x and a scalar _y are equal*/
     template<typename _Cx>
     inline constexpr bool
     operator == (const complex<_Cx>& _x, const _Cx& _y)
     {
          return (_x.real() == _y && _x.img() == 0);
     }
     /*12/13/2023*/
     /*Return true if a scalar _x and a complex number _y are equal*/
     template<typename _Cx>
     inline constexpr bool 
     operator == (const _Cx& _x, const complex<_Cx>& _y)
     {
          return (_y.real() == _x && _y.img() == 0);
     }
     
     /*12/13/2023*/
     /*Return false if complex number _x and _y are equal*/
     template<typename _Cx>
     inline constexpr bool
     operator != (const complex<_Cx>& _x, const complex<_Cx>& _y)
     {
          return (_x.real() != _y.real() || _x.img() != _y.img());
     }
     /*12/13/2023*/
     /*Return false if a complex number _x and a scalar _y are equal*/
     template<typename _Cx>
     inline constexpr bool
     operator != (const complex<_Cx>& _x, const _Cx& _y)
     {
          return (_x.real() != _y || _x.img() != 0);
     }
     /*12/13/2023*/
     /*Return false if a scalar _x and a complex number _y are equal*/
     template<typename _Cx>
     inline constexpr bool
     operator != (const _Cx& _x, const complex<_Cx>& _y)
     {
          return (_y.real() != _x || _y.img() != 0);
     }
     /*** Values ***/

     /*12/14/2023*/
     /*Return _z*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     z_val(const complex<_Cx>& _z)
     {
          return _z;
     }

     /*12/13/2023*/
     /*Get the real component of a complex number _z*/
     template<typename _Cx>
     inline constexpr _Cx
     real(const complex<_Cx>& _z)
     {
          return _z.real();
     }
     /*12/13/2023*/
     /*Get the imaginary component of a complex number _z*/
     template<typename _Cx>
     inline constexpr _Cx
     img(const complex<_Cx>& _z)
     {
          return _z.img();
     }

     /*12/25/2023 ~ Christmas!*/
     /*Return i*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     i()
     {
          return complex<_Cx>(0, 1);
     }

     /*========================================================*/

     /*12/13/2023*/
     template<typename _Cx>
     inline constexpr _Cx
     _complex_abs(const complex<_Cx>& _z)
     {
          _Cx _x = _z.real();
          _Cx _y = _z.img();
          return sqrt(_x * _x + _y * _y);
     }
     /*12/13/2023*/
     /*Return the magnitude of a complex number _z*/
     template<typename _Cx>
     inline constexpr _Cx
     abs(const complex<_Cx>& _z)
     {
          return _complex_abs(_z);
     }

     /*12/25/2023 ~ Christmas!*/
     template<typename _Cx>
     inline constexpr _Cx
     _complex_abs2(const complex<_Cx>& _z)
     {
          _Cx _x = _z.real();
          _Cx _y = _z.img();
          return _x * _x + _y * _y;
     }
     /*12/25/2023 ~ Christmas!*/
     /*Return the squared magnitude of a complex number _z*/
     template<typename _Cx>
     inline constexpr _Cx
     abs2(const complex<_Cx>& _z)
     {
          return _complex_abs2(_z);
     }

     /*12/24/2023*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     _complex_conj(const complex<_Cx>& _z)
     {
          return complex<_Cx>(_z.real(), -_z.img());
     }
     /*1/3/2024*/
     /*Return the conjugate of a complex number _z*/
     template<typename _Cx>
     inline constexpr complex<_Cx>
     conj(const complex<_Cx>& _z)
     {
          return _complex_conj(_z);
     }

     /*12/21/2023*/
     template<typename _Cx>
     inline complex<_Cx>
     _complex_sqrt(const complex<_Cx>& _z)
     {
          if(_z.img() == 0)
               return _z.real() > 0? complex<_Cx>(sqrt(_z.real()), 0):
                    complex<_Cx>(0, sqrt(-_z.real()));
          /*Extremely scary, but derivable formula*/
          _Cx _r = sqrt((abs(_z) + _z.real()) / 2);
          _Cx _i = (_z.img() / abs(_z.img())) * 
               sqrt((abs(_z) - _z.real()) / 2);
          return complex<_Cx>(_r, _i);
     }

     /*12/25/2023 ~ Christmas!*/
     /*Compute the square root of a complex number _z*/
     template<typename _Cx>
     inline complex<_Cx>
     sqrt(const complex<_Cx>& _z)
     {
          return _complex_sqrt(_z);
     }

     /*12/25/2023 ~ Christmas!*/
     template<typename _Cx>
     inline constexpr _Cx
     _complex_arg(const complex<_Cx>& _z)
     {
          return atan2(_z.img(), _z.real());
     }
     /*12/25/2023 ~ Christmas!*/
     /*Return the phase angle of a complex number _z*/
     template<typename _Cx>
     inline constexpr _Cx
     /*Why not use phase()???*/
     arg(const complex<_Cx>& _z)
     {
          return _complex_arg(_z);
     }
     /*12/25/2023 ~ Christmas!*/
     /*Return the phase angle of a complex number _z*/
     template<typename _Cx>
     inline constexpr _Cx
     /*Why not use arg()???*/
     phase(const complex<_Cx>& _z)
     {
          return _complex_arg(_z);
     }

     // /*12/15/2023*/
     // template<typename _Cx>
     // inline complex<_Cx>
     // _c_exp(const complex<_Cx>& _z)
     // {
     //      return complex<_Cx>(necromancer_exp::exp(_z.real())
     //           * complex<Cx>(euclid_trig::cos(_z.img()), euclid_trig::sin(_z.img())));
     // }

     /*12/25/2023 ~ Christmas!*/
     template<typename _Cx>
     inline complex<_Cx>
     _complex_log(const complex<_Cx>& _z)
     {
          return complex<_Cx>(log(_complex_abs(_z)), _complex_arg(_z));
     }
     /*12/25/2023 ~ Christmas!*/
     /*Compute the complex natural logarithm of a complex number _z*/
     template<typename _Cx>
     inline complex<_Cx>
     log(const complex<_Cx>& _z)
     {
          return _complex_log(_z);
     }
}

#endif /*_NECROMANCER_COMPLEX*/

// /*The Math Necromancer*/

// /*============ C++ Complex Number Support and Operations ============*/
// /*Full complex number support for C++. If for some reason one doesn't want*/
// /*to use <complex.h> or <complex>, then this will also work, all though*/
// /*It is less sophisticated.*/

// /*This file was made to help Wizards in need of the more Complex spells,*/
// /*And venture down into the mines of custom libraries without any standard*/
// /*Libraries. It is a beacon for those who dare to walk away from the well-*/
// /*worn path of standard libraries*/

// /*Add, Subtract, Multiply, Divide, Convert to Polar Coordinates*/
// /*Get the Magnitude, Square Root, and more*/

// /*Enchanted Runes, These protect the sacred knowledge from within*/
// /*From being summoned more than once. These are crucial for the*/
// /*Magic to work in harmony, lest Chaos be Unleashed into this Realm*/
// #ifndef _NECROMANCER_COMPLEX_
// #define _NECROMANCER_COMPLEX_

// #include "constants.hpp"
// #include "roots.hpp"
// #include "cordic.hpp"
// #include "abs.hpp"
// #include "exp.hpp"
// #include "log.hpp"

// namespace necromancer_complex
// {
//      /*Forward class declarations*/
//      /*These will be defined later*/
//      template<typename _C>
//      class complex;
//      template<typename _C>
//      class complex_polar;

//      /*Forward function declarations*/
//      /*These will be defined later.*/
//      /*=============================*/

//      /*Return i*/
//      template<typename _C>
//      complex<_C> i();
//      /*Convert a Scalar to a Complex Number*/
//      template<typename _C>
//      complex<_C> complx(const _C& _s);
//      /*Convert a Complex Number to a Scalar*/
//      template<typename _C>
//      _C scalar(const complex<_C>& _s);
//      /*Get the Conjugate of a Complex Number*/
//      template<typename _C>
//      complex<_C> conj(const complex<_C>& _z);
//      /*Get the magnitude squared of a Complex Number*/
//      template<typename _C>
//      _C abs2(const complex<_C>& _z);
//      /*Get the magnitude of a Complex Number*/
//      template<typename _C>
//      _C abs(const complex<_C>& _z);
//      /*Get the Phase Angle of a Complex Number*/
//      template<typename _C>
//      _C complex_angle(const complex<_C>& _z);
//      /*Get the Argument of a Complex Number*/
//      template<typename _C>
//      _C arg(const complex<_C>& _z);
//      /*Get the Square Root of a Complex Number*/
//      /*(Only the Positive one)*/
//      template<typename _C>
//      complex<_C> sqrt(const complex<_C>& _z);
//      /*Convert Cartesian Complex Numbers to*/
//      /*Polar Complex Numbers*/
//      template<typename _C>
//      complex_polar<_C> polar(const complex<_C>& _z);
//      /*Convert Polar Complex Numbers to*/
//      /*Cartesian Complex Numbers*/
//      template<typename _C>
//      complex<_C> cart(const complex_polar<_C>& _z);
//      /*Raise e to a Complex Number*/
//      template<typename _C>
//      complex<_C> exp(const complex<_C>& _z);
//      /*Return the Complex Natural Logarithm of _z*/
//      template<typename _C>
//      complex<_C> log(const complex<_C>& _z);

//      /*Flexible template. Defaults to double*/
//      /*If no type is specified*/
//      template<typename _C = double>
//      /*Class definition*/
//      class complex
//      {
//           private:
//                _C _real, _img;
//                bool _err_state;
//           public:
//                /*Get the real component*/
//                /*of a Complex Number*/
//                _C real() const
//                {
//                     return _real;
//                }
//                /*Assign a real part*/
//                /*To a Complex Number*/
//                void real(_C _r_val)
//                {
//                     _real = _r_val;
//                }
//                /*Get the imaginary component*/
//                /*of a Complex Numer*/
//                _C img() const
//                {
//                     return _img;
//                }

//                /*Assign an imaginary part*/
//                /*To a Complex Number*/
//                void img(_C _i_val)
//                {
//                     _img = _i_val;
//                }

//                /*Get the Error state*/
//                bool err() const
//                {
//                     return _err_state;
//                }
//                /*Assign the error state*/
//                void err(bool _err)
//                {
//                     _err_state = _err;
//                }

//                /*Check if a Complex Number*/
//                /*Can be Expressed as a Real*/
//                bool is_real()
//                {
//                     return _img == 0;
//                }
//                /*Check if a Complex Number*/
//                /*Can't be Expressed as a Real*/
//                bool is_complex()
//                {
//                     return _img != 0;
//                }

//                /*Default constructor. If no values*/
//                /*are specified, default to 0*/
//                complex()
//                     : _real(0), _img(0), _err_state(false)
//                {}
//                complex(const _C& _r)
//                     : _real(_r), _img(0), _err_state(false)
//                {}
//                /*Assign complex values*/
//                complex(const _C& _r, const _C& _i)
//                     : _real(_r), _img(_i), _err_state(false)
//                {}
//                /*Assign complex values as well as an error state*/
//                complex(const _C& _r, const _C& _i, bool _err)
//                     : _real(_r), _img(_i), _err_state(_err)
//                {}

//                /*Operations with Scalars*/
//                /*These are just declarations*/
//                /*They will be defined later*/
//                /*=========================*/
//                /*Assign a Scalar to a Complex Number*/
//                template<typename _C1>
//                complex<_C> operator = (const _C1& _s);
//                /*Add a Scalar to a Complex Number*/
//                template<typename _C1>
//                complex<_C> operator += (const _C1& _s);
//                /*Subtract a Scalar from a Complex Number*/
//                template<typename _C1>
//                complex<_C> operator -= (const _C1& _s);
//                /*Multiply a Complex Number by a Scalar*/
//                template<typename _C1>
//                complex<_C> operator *= (const _C1& _s);
//                /*Divide a Complex Number by a Scalar*/
//                template<typename _C1>
//                complex<_C> operator /= (const _C1& _s);

//                /*Operations with other Complex Numbers*/
//                /*These are just declarations*/
//                /*They will be defined later*/
//                /*=========================*/
//                /*Assign one Complex Number to Another*/
//                template<typename _C1>
//                complex<_C> operator = (const complex<_C1>& _z);
//                /*Add one Complex Number to Another*/
//                template<typename _C1>
//                complex<_C> operator += (const complex<_C1>& _z);
//                /*Subtract one Complex Number from Another*/
//                template<typename _C1>
//                complex<_C> operator -= (const complex<_C1>& _z);
//                /*Multiply one Complex Number by Another*/
//                template<typename _C1>
//                complex<_C> operator *= (const complex<_C1>& _z);
//                /*Divide one Complex Number by Another*/
//                template<typename _C1>
//                complex<_C> operator /= (const complex<_C1>& _z);
//      };

//      /*Polar complex numbers - The idea is very similar*/
//      /*to normal Complex Numbers*/
//      template<typename _C = double>
//      class complex_polar
//      {
//           private:
//                _C _ray, _theta;
//                bool _err_state;
//           public:
//                /*Get the Ray of a Polar Complex Number*/
//                _C ray() const
//                {
//                     return _ray;
//                }
//                /*Assign a Value for the Ray of*/
//                /*a Polar Complex Number*/
//                void ray(_C _ray_val)
//                {
//                     _ray = _ray_val;
//                }
//                /*Get the Angle of a Polar Complex Number*/
//                _C theta() const
//                {
//                     return _theta;
//                }
//                /*Assign a Value for the Angle of a*/
//                /*Polar Complex Number*/
//                void theta(_C _theta_val)
//                {
//                     _theta = _theta_val;
//                }
//                /*Get the Error State*/
//                bool err() const
//                {
//                     return _err_state;
//                }
//                /*Assign the Error State*/
//                void err(bool _err_val)
//                {
//                     _err_state = _err_val;
//                }

//                /*Default Constructor. If no Values*/
//                /*are Specified, default to 0*/
//                complex_polar()
//                     : _ray(0), _theta(0)
//                {}
//                /*Assign the Ray and the Angle*/
//                complex_polar(_C _r, _C _t)
//                     : _ray(_r), _theta(_t)
//                {}
//                /*Assign the Ray, the Angle, and the Error State*/
//                complex_polar(_C _r, _C _t, bool _err)
//                     : _ray(_r), _theta(_t), _err_state(_err)
//                {}

//                /*Operations with Scalars*/
//                /*These are just Declarations*/
//                /*They will be Defined Later*/
//                /*=========================*/
//                /*Assign a Scalar to a Polar Complex Number*/
//                template<typename _C1>
//                complex_polar<_C> operator = (const _C1& _s);
//                /*Add a Scalar to a Polar Complex Number*/
//                template<typename _C1>
//                complex_polar<_C> operator += (const _C1& _s);
//                /*Subtract a Scalar from a Polar Complex Number*/
//                template<typename _C1>
//                complex_polar<_C> operator -= (const _C1& _s);
//                /*Multiply a Polar Complex Number by a Scalar*/
//                template<typename _C1>
//                complex_polar<_C> operator *= (const _C1& _s);
//                /*Divide a Polar Complex Number by a Scalar*/
//                template<typename _C1>
//                complex_polar<_C> operator /= (const _C1& _s);

//                /*Operations with other Polar Complex Numbers*/
//                /*These are just declarations*/
//                /*They will be defined later*/
//                /*=========================*/
//                /*Assign one Complex Number to Another*/
//                template<typename _C1>
//                complex_polar<_C> operator = (const complex_polar<_C1>& _z);
//                /*Add one Complex Number to Another*/
//                template<typename _C1>
//                complex_polar<_C> operator += (const complex_polar<_C1>& _z);
//                /*Subtract one Complex Number from Another*/
//                template<typename _C1>
//                complex_polar<_C> operator -= (const complex_polar<_C1>& _z);
//                /*Multiply one Complex Number by Another*/
//                template<typename _C1>
//                complex_polar<_C> operator *= (const complex_polar<_C1>& _z);
//                /*Divide one Complex Number by Another*/
//                template<typename _C1>
//                complex_polar<_C> operator /= (const complex_polar<_C1>& _z);
//      };

//      template<typename _C>
//      template<typename _C1>
//      /*Assign one Complex Number to Another*/
//      complex<_C> complex<_C>::operator = (const complex<_C1>& _z)
//      {
//           _real = _z.real();
//           _img = _z.img();
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Assign a Complex Number to a Scalar*/
//      complex<_C> complex<_C>::operator = (const _C1& _s)
//      {
//           _real = _s;
//           _img = 0;
//           return *this;
//      }

//      template<typename _C>
//      template<typename _C1>
//      /*Add one Complex Number to Another*/
//      complex<_C> complex<_C>::operator += (const complex<_C1>& _z)
//      {
//           _real += _z.real();
//           _img += _z.img();
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Add a Scalar to a Complex Number*/
//      complex<_C> complex<_C>::operator += (const _C1& _s)
//      {
//           _real += _s;
//           return *this;
//      }

//      template<typename _C>
//      template<typename _C1>
//      /*Subtract one Complex Number from Another*/
//      complex<_C> complex<_C>::operator -= (const complex<_C1>& _z)
//      {
//           _real -= _z.real();
//           _img -= _z.img();
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Subtract a Scalar from a Complex Number*/
//      complex<_C> complex<_C>::operator -= (const _C1& _s)
//      {
//           _real -= _s;
//           return *this;
//      }

//      template<typename _C>
//      template<typename _C1>
//      /*Multiply one Complex Number by Another*/
//      complex<_C> complex<_C>::operator *= (const complex<_C1>& _z)
//      {
//           const _C1 _r = _real * _z.real() - _img * _z.img();
//           _img = _real * _z.img() + _img * _z.real();
//           _real = _r;
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Multiply a Complex Number by a Scalar*/
//      complex<_C> complex<_C>::operator *= (const _C1& _s)
//      {
//           _real *= _s;
//           _img *= _s;
//           return *this;
//      }

//      template<typename _C>
//      template<typename _C1>
//      /*Divide one Complex Number by Another*/
//      complex<_C> complex<_C>::operator /= (const complex<_C1>& _z)
//      {
//           const _C _r = _real * _z.real() + _img * _z.img();
//           const _C _abs2_z = abs2(_z);
//           _img = (_img * _z.real() - _real * _z.img()) / _abs2_z;
//           _real = _r / _abs2_z;
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Divide a Complex Number by a Scalar*/
//      complex<_C> complex<_C>::operator /= (const _C1& _s)
//      {
//           _real /= _s;
//           _img /= _s;
//           return *this;
//      }

//      template<typename _C>
//      /*Return the Complex Positive of a Complex Number _z*/
//      /*(Basically, just return _z)*/
//      complex<_C> operator + (const complex<_C>& _z)
//      {
//           return _z;
//      }
//      template<typename _C>
//      /*Return the Complex Negation of a Complex Number _z*/
//      complex<_C> operator - (const complex<_C> _z)
//      {
//           return complex<_C>(-_z.real(), -_z.img());
//      }

//      template<typename _C>
//      /*Return the Complex Increment of a Complex Number _z*/
//      complex<_C> operator ++ (const complex<_C>& _z)
//      {
//           complex<_C> _r = _z;
//           _r += 1;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Complex Decrement of a Complex Number _z*/
//      complex<_C> operator -- (const complex<_C>& _z)
//      {
//           complex<_C> _r = _z;
//           _r -= 1;
//           return _r;
//      }

//      template<typename _C>
//      /*Return the Result of Adding Two Complex Numbers _x and _y*/
//      complex<_C> operator + (const complex<_C>& _x, const complex<_C>& _y)
//      {
//           complex<_C> _r = _x;
//           _r += _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Adding a Complex Number _x and a Scalar _y*/
//      complex<_C> operator + (const complex<_C>& _x, const _C& _y)
//      {
//           complex<_C> _r = _x;
//           _r += _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Adding a Scalar _x and a Complex Number _y*/
//      complex<_C> operator + (const _C& _x, const complex<_C>& _y)
//      {
//           complex<_C> _r = _y;
//           _y += _x;
//           return _r;
//      }

//      template<typename _C>
//      /*Return the Result of Subtracting Two Complex Numbers _x and _y*/
//      complex<_C> operator - (const complex<_C>& _x, const complex<_C>& _y)
//      {
//           complex<_C> _r = _x;
//           _r -= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Subtracting a Scalar _y from a Complex Number _x*/
//      complex<_C> operator - (const complex<_C>& _x, const _C& _y)
//      {
//           complex<_C> _r = _x;
//           _r -= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Subtracting a Complex Number _y from a Scalar _x*/
//      complex<_C> operator - (const _C& _x, const complex<_C>& _y)
//      {
//           complex<_C> _r = -_y;
//           _y += _x;
//           return _r;
//      }

//      template<typename _C>
//      /*Return the Result of Multiplying Two Complex Number _x and _y*/
//      complex<_C> operator * (const complex<_C>& _x, const complex<_C>& _y)
//      {
//           complex<_C> _r = _x;
//           _r *= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Multiplying a Complex Number _x by a Scalar _y*/
//      complex<_C> operator * (const complex<_C>& _x, const _C& _y)
//      {
//           complex<_C> _r = _x;
//           _r *= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Multiplying a Scalar _x by a Complex Number _y*/
//      complex<_C> operator * (const _C& _x, const complex<_C>& _y)
//      {
//           complex<_C> _r = _y;
//           _r *= _x;
//           return _r;
//      }

//      template<typename _C>
//      /*Return the Result of Dividing Two Complex Number _x and _y*/
//      complex<_C> operator / (const complex<_C>& _x, const complex<_C>& _y)
//      {
//           complex<_C> _r = _x;
//           _r /= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Dividing a Complex Number _x by a Scalar _y*/
//      complex<_C> operator / (const complex<_C>& _x, const _C& _y)
//      {
//           complex<_C> _r = _x;
//           _r /= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Dividing a Scalar _x by a Complex Number _y*/
//      complex<_C> operator / (const _C& _x, const complex<_C>& _y)
//      {
//           complex<_C> _r = _x;
//           _r /= _y;
//           return _r;
//      }

//      /*It's disputed on how to do operations on Complex Numbers*/
//      /*This is one way...*/

//      template<typename _C>
//      template<typename _C1>
//      /*Assign one Polar Complex Number to Another*/
//      complex_polar<_C> complex_polar<_C>::operator = (const complex_polar<_C1>& _z)
//      {
//           _ray = _z.ray();
//           _theta = _z.theta();
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Assign a Polar Complex Number to a Scalar*/
//      complex_polar<_C> complex_polar<_C>::operator = (const _C1& _s)
//      {
//           _ray = _s;
//           _theta = 0;
//           return *this;
//      }

//      template<typename _C>
//      template<typename _C1>
//      /*Add one Polar Complex Number to Another*/
//      complex_polar<_C> complex_polar<_C>::operator += (const complex_polar<_C1>& _z)
//      {
//           complex<_C> _cr = cart(*this);
//           complex<_C> _cz = cart(_z);
//           *this = polar(_cr + _cz);
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Add a Scalar to a Polar Complex Number*/
//      complex_polar<_C> complex_polar<_C>::operator += (const _C1& _s)
//      {
//           complex<_C> _cr = cart(*this);
//           _cr += _s;
//           *this = polar(_cr);
//           return *this;
//      }

//      template<typename _C>
//      template<typename _C1>
//      /*Subtract one Polar Complex Number from Another*/
//      complex_polar<_C> complex_polar<_C>::operator -= (const complex_polar<_C1>& _z)
//      {
//           complex<_C> _cr = cart(*this);
//           complex<_C> _cz = cart(_z);
//           *this = polar(_cr + _cz);
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Subtract a Scalar from a Polar Complex Number*/
//      complex_polar<_C> complex_polar<_C>::operator -= (const _C1& _s)
//      {
//           complex<_C> _cr = cart(*this);
//           _cr -= _s;
//           *this = polar(_cr);
//           return *this;
//      }

//      template<typename _C>
//      template<typename _C1>
//      /*Multiply one Polar Complex Number by Another*/
//      complex_polar<_C> complex_polar<_C>::operator *= (const complex_polar<_C1>& _z)
//      {
//           _ray *= _z.ray();
//           _theta += _z.theta();
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Multiply a Polar Complex Number by a Scalar*/
//      complex_polar<_C> complex_polar<_C>::operator *= (const _C1& _s)
//      {
//           _ray *= _s;
//           return *this;
//      }

//      template<typename _C>
//      template<typename _C1>
//      /*Divide one Polar Complex Number by Another*/
//      complex_polar<_C> complex_polar<_C>::operator /= (const complex_polar<_C1>& _z)
//      {
//           _ray /= _z.ray();
//           _theta -= _z.theta();
//           return *this;
//      }
//      template<typename _C>
//      template<typename _C1>
//      /*Divide a Polar Complex Number by a Scalar*/
//      complex_polar<_C> complex_polar<_C>::operator /= (const _C1& _s)
//      {
//           _ray /= _s;
//           return *this;
//      }

//      template<typename _C>
//      /*Return the Complex Positive of a Polar Complex Number _z*/
//      /*(Basically, just return _z)*/
//      complex_polar<_C> operator + (const complex_polar<_C>& _z)
//      {
//           return _z;
//      }
//      template<typename _C>
//      /*Return the Complex Negation of a Polar Complex Number _z*/
//      complex_polar<_C> operator - (const complex_polar<_C>& _z)
//      {
//           return complex_polar<_C>(_z.ray(), -_z.theta());
//      }

//      template<typename _C>
//      /*Return the Result of Adding Two Polar Complex Numbers _x and _y*/
//      complex_polar<_C> operator + (const complex_polar<_C>& _x, const complex_polar<_C>& _y)
//      {
//           complex_polar<_C> _r = _x;
//           _r += _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Adding a Polar Complex Number _x and a Scalar _y*/
//      complex_polar<_C> operator + (const complex_polar<_C>& _x, const _C& _y)
//      {
//           complex_polar<_C> _r = _x;
//           _r += _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Adding a Scalar _x and a Polar Complex Number _y*/
//      complex_polar<_C> operator + (const _C& _x, const complex_polar<_C>& _y)
//      {
//           complex_polar<_C> _r = _y;
//           _r += _x;
//           return _r;
//      }

//      template<typename _C>
//      /*Return the Result of Subtracting Two Polar Complex Numbers _x and _y*/
//      complex_polar<_C> operator - (const complex_polar<_C>& _x, const complex_polar<_C>& _y)
//      {
//           complex_polar<_C> _r = _x;
//           _r -= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Subtracting a Polar Complex Number _x and a Scalar _y*/
//      complex_polar<_C> operator - (const complex_polar<_C>& _x, const _C& _y)
//      {
//           complex_polar<_C> _r = _x;
//           _r -= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Subtracting a Scalar _x and a Polar Complex Number _y*/
//      complex_polar<_C> operator - (const _C& _x, const complex_polar<_C>& _y)
//      {
//           complex_polar<_C> _r = -_y;
//           _r += _x;
//           return _r;
//      }

//      template<typename _C>
//      /*Return the Result of Multiplying Two Polar Complex Numbers _x and _y*/
//      complex_polar<_C> operator * (const complex_polar<_C>& _x, const complex_polar<_C>& _y)
//      {
//           complex_polar<_C> _r = _x;
//           _r *= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Multiplying a Complex Polar Number _x and a Scalar _y*/
//      complex_polar<_C> operator * (const complex_polar<_C>& _x, const _C& _y)
//      {
//           complex_polar<_C> _r = _x;
//           _r *= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Multiplying a Scalar _x and a Complex Polar Number _y*/
//      complex_polar<_C> operator * (const _C& _x, const complex_polar<_C>& _y)
//      {
//           complex_polar<_C> _r = _y;
//           _r *= _x;
//           return _r;
//      }

//      template<typename _C>
//      /*Return the Result of Dividing Two Polar Complex Numbers _x and _y*/
//      complex_polar<_C> operator / (const complex_polar<_C>& _x, const complex_polar<_C>& _y)
//      {
//           complex_polar<_C> _r = _x;
//           _r /= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Dividing a Polar Complex Number _x and a Scalar _y*/
//      complex_polar<_C> operator / (const complex_polar<_C>& _x, const _C& _y)
//      {
//           complex_polar<_C> _r = _x;
//           _r /= _y;
//           return _r;
//      }
//      template<typename _C>
//      /*Return the Result of Dividing a Scalar _x with a Polar Complex Number _y*/
//      complex_polar<_C> operator / (const _C& _x, const complex_polar<_C>& _y)
//      {
//           complex<_C> _r = _x;
//           _r /= _y;
//           return _r;
//      }

//      template<typename _C>
//      /*Return True if Two Complex Numbers are Equal*/
//      bool operator == (const complex<_C>& _x, const complex<_C> _y)
//      {
//           return (_x.real() == _y.real() && _x.img() == _y.img());
//      }
//      template<typename _C>
//      /*Return True if a Complex Number and a Scalar are Equal*/
//      bool operator == (const complex<_C>& _x, const _C& _y)
//      {
//           return (_x.real() == _y && _x.img() == 0);
//      }
//      template<typename _C>
//      /*Return True if a Scalar and a Complex Number are Equal*/
//      bool operator == (const _C& _x, const complex<_C>& _y)
//      {
//           return (_x == _y.real() && _y.img() == 0);
//      }

//      template<typename _C>
//      /*Return False if Two Complex Numbers are Equal*/
//      bool operator != (const complex<_C>& _x, const complex<_C> _y)
//      {
//           return (_x.real() != _y.real() || _x.img() != _y.img());
//      }
//      template<typename _C>
//      /*Return False if a Complex Number and a Scalar are Equal*/
//      bool operator != (const complex<_C>& _x, const _C& _y)
//      {
//           return (_x.real() != _y || _x.img() != 0);
//      }
//      template<typename _C>
//      /*Return False if a Scalar and a Complex Number are Equal*/
//      bool operator != (const _C& _x, const complex<_C>& _y)
//      {
//           return (_y.real() != _x || _y.img() != 0);
//      }

//      template<typename _C>
//      /*Return True if Two Polar Complex Numbers are Equal*/
//      bool operator == (const complex_polar<_C>& _x, const complex_polar<_C>& _y)
//      {
//           return (_x.ray() == _y.ray() && _x.theta() == _y.theta());
//      }
//      template<typename _C>
//      /*Return True if a Polar Complex Number and a Scalar are Equal*/
//      bool operator == (const complex_polar<_C>& _x, const _C& _y)
//      {
//           return (_x.ray() == _y && _x.theta() == 0);
//      }
//      template<typename _C>
//      /*Return True if a Scalar and a Polar Complex Number are Equal*/
//      bool operator == (const _C& _x, const complex_polar<_C>& _y)
//      {
//           return (_y.ray() == _x && _y.theta() == 0);
//      }

//      template<typename _C>
//      /*Return False if Two Polar Complex Numbers are Equal*/
//      bool operator != (const complex_polar<_C>& _x, const complex_polar<_C>& _y)
//      {
//           return (_x.ray() != _y.ray() || _x.theta() != _y.theta());
//      }
//      template<typename _C>
//      /*Return False if a Polar Complex Number and a Scalar are Equal*/
//      bool operator != (const complex_polar<_C>& _x, const _C& _y)
//      {
//           return (_x.ray() != _y || _x.theta() != 0);
//      }
//      template<typename _C>
//      /*Return False if a Scalar and a Polar Complex Number are Equal*/
//      bool operator != (const _C& _x, const complex_polar<_C>& _y)
//      {
//           return (_y.ray() != _x || _y.theta() != 0);
//      }

//      template<typename _C>
//      /*Similar to _z.is_real(). However, It is not*/
//      /*a member function*/
//      bool is_real(const complex<_C>& _z)
//      {
//           return _z.is_real();
//      }
//      template<typename _C>
//      /*Similar to _z.is_complex(). However, It is not*/
//      /*a member function*/
//      bool is_complex(const complex<_C>& _z)
//      {
//           return _z.is_complex();
//      }

//      template<typename _C>
//      /*Return i*/
//      complex<_C> i()
//      {
//           return complex<_C>(0, 1);
//      }

//      template<typename _C>
//      /*Convert a Scalar to a Complex Number*/
//      complex<_C> complx(const _C& _s)
//      {
//           return complex(_s, 0);
//      }
//      template<typename _C>
//      /*Convert a Complex Number to a Scalar*/
//      _C scalar(const complex<_C>& _z)
//      {
//           return _z.real();
//      }

//      template<typename _C>
//      /*Get the Conjugate of a Complex Number*/
//      complex<_C> conj(const complex<_C>& _z)
//      {
//           return complex<_C>(_z.real(), -_z.img());
//      }

//      template<typename _C>
//      /*Get the Magnitude Squared of a Complex Number*/
//      _C abs2(const complex<_C>& _z)
//      {
//           return (_z.real() * _z.real() + _z.img() * _z.img());
//      }
//      template<typename _C>
//      /*Get the Magnitude of a Complex Number*/
//      _C abs(const complex<_C>& _z)
//      {
//           if(_z.real() == 0)
//                return _z.img();
//           else if(_z.img() == 0)
//                return _z.img();
//           _C _r =  absolute::abs(necromancer_cordic::hypot(_z.real(), _z.img()));
//           return _r;
//      }
//      template<typename _C>
//      /*Get the Phase Angle of a Complex Number*/
//      _C complex_angle(const complex<_C>& _z)
//      {
//           return necromancer_cordic::atan2(_z.img(), _z.real());
//      }
//      template<typename _C>
//      /*Get the Argument of a Complex Number*/
//      _C arg(const complex<_C>& _z)
//      {
//           /*Arg is just the angle under a different name*/
//           return complex_angle(_z);
//      }
//      template<typename _C>
//      /*Get the Square Root of a Complex Number*/
//      complex<_C> sqrt(const complex<_C>& _z)
//      {
//           if(_z == -1)
//           {
//                return i<_C>();
//           }
//           else if(_z.img() == 0)
//           {
//                return _z.real() > 0? complex<_C>(root::sqrt(_z.real()), 0): complex<_C>(0, root::sqrt(-_z.real()));
//           }
//           /*Extremely scary, but derivable formula*/
//           _C _r = root::sqrt((abs(_z) + _z.real()) / 2);
//           _C _i = (_z.img() / absolute::abs(_z.img())) * root::sqrt((abs(_z) - _z.real()) / 2);
//           return complex<_C>(_r, _i);
//      }
//      template<typename _C>
//      /*Get the Square Root of a Polar Complex Number*/
//      complex_polar<_C> polar_sqrt(const complex_polar<_C>& _z)
//      {
//           /*Just convert to cartesian and take the roots*/
//           _C _r = root::sqrt(_z.ray()) * necromancer_cordic::cos(_z.theta() / 2);
//           _C _i = root::sqrt(_z.ray()) * necromancer_cordic::sin(_z.theta() / 2);
//           complex<_C> cart_r(_r, _i);
//           /*Then convert back to polar*/
//           return polar(cart_r);
//      }
//      template<typename _C>
//      /*Convert a Cartesian Complex Number to Polar Coordinates*/
//      complex_polar<_C> polar(const complex<_C>& _z)
//      {
//           _C _ray = necromancer_cordic::hypot(_z.real(), _z.img());
//           _C _theta = necromancer_cordic::atan2(_z.img(), _z.real());
//           return complex_polar<_C>(_ray, _theta);
//      }
//      template<typename _C>
//      /*Convert a Polar Complex Number to Cartesian Coordinates*/
//      complex<_C> cart(const complex_polar<_C>& _z)
//      {
//           _C _r = _z.ray();
//           _C _t = _z.theta();
//           /*Result will be scaled down by the ray length,*/
//           /*so we just multiply the result by _r*/
//           complex<_C> result = _r * complex<_C>(necromancer_cordic::cos(_t), necromancer_cordic::sin(_t));
//           return result;
//      }
//      template<typename _C>
//      /*Raise e to a Complex Number*/
//      complex<_C> exp(const complex<_C>& _z)
//      {
//           if(_z.real() == 0)
//           {
//                return complex<_C>(necromancer_cordic::cos(_z.img()), necromancer_cordic::sin(_z.img()));
//           }
//           return necromancer_exp::exp<_C>(_z.real()) * complex(necromancer_cordic::cos(_z.img()), necromancer_cordic::sin(_z.img()));
//      }
//      /*Return the Complex Natural Logarithm of _z*/
//      template<typename _C>
//      complex<_C> log(const complex<_C>& _z)
//      {
//           complex_polar _polar_z = polar(_z);
//           return complex<_C>(necromancer_log::log(abs(_z)), necromancer_cordic::atan2(_z.real(), _z.img()));
//      }
// }

// #endif /*_NECROMANCER_COMPLEX_*/