/*The Math Necromancer*/

#ifndef _MATH_SORCERY_
#define _MATH_SORCERY_

/*Sometimes, it's necessary to catch other math libraries, but these detect <cmath> and <math.h>*/
/*At least, they do on my compiler*/

/*Throw a warning if not using <cmath> or <math.h>*/
#if !defined(_GLIBCXX_CMATH) && !defined(_GLIBCXX_MATH_H) && !defined(_MATH_H_)
     #ifndef _MATH_SORCERY_SKIP_MATH_WARN_
          #warning "Remember, this isn't sophisticated. Use <cmath> or <math.h> for serious work!"
          /*To disable this warning, `#define _NECROMANCER_SKIP_CMATH_WARN_` before including this file*/
     #endif /*_MATH_SORCERY_SKIP_MATH_WARN_*/
#endif /*!defined(_GLIBCXX_CMATH) && !defined(_GLIBCXX_MATH_H)*/
/*Throw an error if the standard math libraries are included; it will cause conflict*/
/*To detect another library, #define _FORBIDDEN_MATH_ as the #define of said library*/
#if (defined(_GLIBCXX_CMATH) || defined(_GLIBCXX_MATH_H) || defined(_MATH_H_) || defined(_FORBIDDEN_MATH_)) && defined(_MATH_SORCERY_)
     #error "Never use this library with <cmath> or other math libraries!"
#endif /*(defined(_GLIBCXX_CMATH) || defined(_GLIBCXX_MATH_H) || defined(_MATH_H_)) && defined(_MATH_SORCERY_)*/

#include "float_class.hpp"

#ifndef _NECROMANCER_FLOAT_CLASS_
     #error "Could not get float_class.hpp! This is serious!"
#endif /*_NECROMANCER_FLOAT_CLASS_*/

/*Get rid of those macros defined in "float_class.hpp"*/
#undef INFINITYf
#undef INFINITY
#undef NEGATIVE_INFINITYf
#undef NEGATIVE_INFINITY
#undef NaNf
#undef NaN
#undef _FLT_ZERO
#undef _FLT_NAN
#undef _FLT_INFINITY
#undef _FLT_NEGATIVE_INFY
#undef _FLT_NORMAL
#undef _FLT_SUBNORMAL
#undef _int32
#undef _int64

/*Redefine _int32 and _int64 if needed...*/

#ifndef _int32
     /*32 bit unsiged integer (unsigned long)*/
     #define _int32 unsigned long
#endif /*_int32*/
#ifndef _int64
     /*64 bit unsigned integer (unsigned long long)*/
     #define _int64 unsigned long long
#endif /*_int64*/

/*Mystical namespace for everything*/
namespace sorcery
{
     /*1/14/2024*/
     /*Return the argument*/
     /*Might be useful???*/
     template<typename _ret_val>
     _ret_val ret(const _ret_val& _x)
     {
          return _x;
     }
};

namespace sorcery
{
     /*12/24/2023 <~ 69?*/
     /*Convert an integral bit representation into it's respective 32-bit float*/
     constexpr float flt_bits(const _int32& _i)
     {
          return necromancer_float_class::
               _flt_bits(_i);
     }
     /*12/24/2023*/
     /*Convert an integral bit representation into it's respective 64-bit float*/
     constexpr double dbl_bits(const _int64 _i)
     {
          return necromancer_float_class::
               _dbl_bits(_i);
     }
}

/*Maximum value of a 32-bit float (float)*/
#define _NUMERIC_FLT_MAXIMUM_ flt_bits(0x7f7fffff)
/*Minimum normal value of a 32-bit float (float)*/
#define _NUMERIC_FLT_EPSILON_ flt_bits(0x00800000)
/*Minimum subnormal value of a 32-bit float (float)*/
#define _NUMERIC_FLT_SUB_EPSILON_ flt_bits(0x00000001)
/*One unit in the last place after 1.0f (float)*/
#define _NUMERIC_FLT_SMALL_ flt_bits(0x34000000)
/*Maximum value of a 64-bit float (double)*/
#define _NUMERIC_DBL_MAXIMUM_ dbl_bits(0x7fefffffffffffff)
/*Minimum normal value of a 64-bit float (double)*/
#define _NUMERIC_DBL_EPSILON_ dbl_bits(0x0010000000000000)
/*Minimum subnormal value of a 64-bit float (double)*/
#define _NUMERIC_DBL_SUB_EPSILON_ dbl_bits(0x0000000000000001)
/*One unit in the last place after 1.0 (double)*/
#define _NUMERIC_DBL_SMALL_ dbl_bits(0x3cb0000000000000)
/*Maximum signed 8-bit integer (char)*/
#define _NUMERIC_CHAR_MAXIMUM_ 0x07f
/*Maximum signed 16-bit integer (short)*/
#define _NUMERIC_SHORT_MAXIMUM_ 0x7fff
/*Maximum signed 32-bit integer (int)*/
#define _NUMERIC_INT32_MAXIMUM_ 0x7fffffff
/*Maximum signed 64-bit integer (long long)*/
#define _NUMERIC_INT64_MAXIMUM_ 0x7fffffffffffffff

#define _bitsize(_type)                 \
     sizeof(_type) * 8
/*Shamelessly stolen from system header <limits>*/

#define _is_signed(_type, _bitsize)     \
     (static_cast<_type>(-1) < 0)
#define _digits2(_type, _bitsize)       \
     (_bitsize - _is_signed(_type, _bitsize))
#define _max_val(_type, _bsize)         \
     (_is_signed(_type, _bsize) ?       \
     ((((static_cast<_type>(1) <<       \
     (_digits2(_type, _bsize) - 1))     \
     - 1) << 1) + 1) : ~static_cast<_type>(0))
#define _min_val(_type, _bitsize)       \
     (_is_signed(_type, _bitsize) ?     \
     -_max(_type, _bitsize) - 1 :       \
     static_cast<_type>(0))

namespace sorcery
{
     /*Sorry, it looks like this type isn't supported yet...*/
     template<typename _ty>
     class numeric_limits
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = false;
     };

     /*Specification for numeric_limits<bool>*/
     template<>
     class numeric_limits<bool>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr bool min()
               {
                    return false;
               }
               /*Maximum value of this type*/
               static constexpr bool max()
               {
                    return true;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(bool);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(bool);
               /*Is this type signed?*/
               static constexpr bool is_signed = false;
               /*Is this type integral?*/
               static constexpr bool is_integer = true; 
               /*Is this type exact?*/    
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"?*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr bool infinity(const bool& _neg)
               {
                    return static_cast<bool>(0);
               }
               /*Get a NaN if this type has one*/
               static constexpr bool nan()
               {
                    return static_cast<bool>(0);
               }
     };
     /*Specification for numeric_limits<signed char>*/
     template<>
     class numeric_limits<signed char>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr signed char min()
               {
                    return -_NUMERIC_CHAR_MAXIMUM_ - 1;
               }
               /*Maximum value of this type*/
               static constexpr signed char max()
               {
                    return _NUMERIC_CHAR_MAXIMUM_;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(signed char);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(signed char);
               /*Is this type signed?*/
               static constexpr bool is_signed = true;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"?*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr signed char infinity(const bool& _neg)
               {
                    return static_cast<signed char>(0);
               }
               /*Get a NaN if this type has one*/
               static constexpr signed char nan()
               {
                    return static_cast<signed char>(0);
               }
     };
     /*Specification for numeric_limits<unsigned char>*/
     template<>
     class numeric_limits<unsigned char>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr unsigned char min()
               {
                    return 0;
               }
               /*Maximum value of this type*/
               static constexpr unsigned char max()
               {
                    return _NUMERIC_CHAR_MAXIMUM_ * 2 + 1;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(unsigned char);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(unsigned char);
               /*Is this type signed?*/
               static constexpr bool is_signed = false;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have a "Not a Number"?*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr unsigned char infinity(const bool& _neg)
               {
                    return static_cast<unsigned char>(0);
               }
               /*Get a NaN if this tpye has one*/
               static constexpr unsigned char nan()
               {
                    return static_cast<unsigned char>(0);
               }
     };
     /*Specification for numeric_limits<signed short>*/
     template<>
     class numeric_limits<signed short>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr signed short min()
               {
                    return -_NUMERIC_SHORT_MAXIMUM_ - 1;
               }
               /*Maximum value of this type*/
               static constexpr signed short max()
               {
                    return _NUMERIC_SHORT_MAXIMUM_;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(signed short);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(signed short);
               /*Is this type signed?*/
               static constexpr bool is_signed = true;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"?*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr signed short infinity(const bool& _neg)
               {
                    return static_cast<signed short>(0);
               }
               /*Get a NaN if this tpe has one*/
               static constexpr signed short nan()
               {
                    return static_cast<signed short>(0);
               }
     };
     /*Specification for numeric_limits<unsigned short>*/
     template<>
     class numeric_limits<unsigned short>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr unsigned short min()
               {
                    return 0;
               }
               /*Maximum value of this type*/
               static constexpr unsigned short max()
               {
                    return _NUMERIC_SHORT_MAXIMUM_ * 2 + 1;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(unsigned short);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(unsigned short);
               /*Is this type signed?*/
               static constexpr bool is_signed = false;
               /*Is this type integral*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr unsigned short infinity(const bool& _neg)
               {
                    return static_cast<unsigned short>(0);
               }
               /*Get a NaN if this type has one*/
               static constexpr unsigned short nan()
               {
                    return static_cast<unsigned short>(0);
               }
     };
     /*Specification for numeric_limits<signed int>*/
     template<>
     class numeric_limits<signed int>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr signed int min()
               {
                    return -_NUMERIC_INT32_MAXIMUM_ - 1;
               }
               /*Maximum value of this type*/
               static constexpr signed int max()
               {
                    return _NUMERIC_INT32_MAXIMUM_;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(signed int);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(signed int);
               /*Is this type signed?*/
               static constexpr bool is_signed = true;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"?*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr signed int infinity(const bool& _neg)
               {
                    return static_cast<signed int>(0);
               }
               /*Get a NaN if this type has one*/
               static constexpr signed int nan()
               {
                    return static_cast<signed int>(0);
               }
     };
     /*Specification for numeric_limits<unsigned int>*/
     template<>
     class numeric_limits<unsigned int>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr unsigned int min()
               {
                    return 0;
               }
               /*Maximum value of this type*/
               static constexpr unsigned int max()
               {
                    return _NUMERIC_INT32_MAXIMUM_ * 2u + 1;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(unsigned int);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(unsigned int);
               /*Is this type siged?*/
               static constexpr bool is_signed = false;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"?*/
               static constexpr bool has_nan = false;
               /*Return an infinity if this type has one*/
               static constexpr unsigned int infinity(const bool& _neg)
               {
                    return static_cast<unsigned int>(0);
               }
               /*Return a NaN if this type has one*/
               static constexpr unsigned int nan()
               {
                    return static_cast<unsigned int>(0);
               }
     };
     /*Specification for numeric_limits<signed long>*/
     template<>
     class numeric_limits<signed long>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr signed long min()
               {
                    return -_NUMERIC_INT32_MAXIMUM_ - 1;
               }
               /*Maximum value of this type*/
               static constexpr signed long max()
               {
                    return _NUMERIC_INT32_MAXIMUM_;
               }
               /*Size on bytes of this type*/
               static constexpr int size = sizeof(signed long);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(signed long);
               /*Is this type signed?*/
               static constexpr bool is_signed = true;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity*/
               static constexpr bool has_infinity = false;
               /*Does this type have a NaN?*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr signed long infinity(const bool& _neg)
               {
                    return static_cast<signed long>(0);
               }
               /*Get a NaN if this type has one*/
               static constexpr signed long nan()
               {
                    return static_cast<signed long>(0);
               }
     };
     /*Specification for numeric_limits<unsigned long>*/
     template<>
     class numeric_limits<unsigned long>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr unsigned long min()
               {
                    return 0;
               }
               /*Maximum value of this type*/
               static constexpr unsigned long max()
               {
                    return _NUMERIC_INT32_MAXIMUM_ * 2ul + 1;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(unsigned long);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(unsigned long);
               /*Is this type signed?*/
               static constexpr bool is_signed = false;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr unsigned long infinity(const bool& _neg)
               {
                    return static_cast<unsigned long>(0);
               }
               /*Get a NaN if this type has one*/
               static constexpr unsigned long nan()
               {
                    return static_cast<unsigned long>(0);
               }
     };
     /*Specification for numeric_limits<signed long long>*/
     template<>
     class numeric_limits<signed long long>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value of this type*/
               static constexpr signed long long min()
               {
                    return -_NUMERIC_INT64_MAXIMUM_ - 1;
               }
               /*Maximum value of this type*/
               static constexpr signed long long max()
               {
                    return _NUMERIC_INT64_MAXIMUM_;
               }
               /*Size in bytes of this type*/
               static constexpr bool size = sizeof(signed long long);
               /*Size of bits of this type*/
               static constexpr int bitsize = _bitsize(signed long long);
               /*Is this type signed?*/
               static constexpr bool is_signed = true;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr signed long long infinity(const bool& _neg)
               {
                    return static_cast<signed long long>(0);
               }
               /*Get a NaN if this type has one*/
               static constexpr signed long long nan()
               {
                    return static_cast<signed long long>(0);
               }
     };
     /*Specification for numeric_limits<unsigned long long>*/
     template<>
     class numeric_limits<unsigned long long>
     {
          public:
               /*Is this a specified class?*/
               static constexpr bool is_specialized = true;
               /*Minimum value*/
               static constexpr unsigned long long min()
               {
                    return 0;
               }
               /*Maximum value*/
               static constexpr unsigned long long max()
               {
                    return _NUMERIC_INT64_MAXIMUM_ * 2ull + 1;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(unsigned long long);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(unsigned long long);
               /*Is this type singed?*/
               static constexpr bool is_signed = false;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = true;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = false;
               /*Does this type have "Not a Number"*/
               static constexpr bool has_nan = false;
               /*Get an infinity if this type has one*/
               static constexpr unsigned long long infinity(const bool& _neg)
               {
                    return static_cast<unsigned long long>(0);
               }
               /*Get a NaN inf this type has one*/
               static constexpr unsigned long long nan()
               {
                    return static_cast<unsigned long long>(0);
               }
     };
     /*Specification for numeric_limits<float>*/
     template<>
     class numeric_limits<float>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Smallest positive normal number*/
               static constexpr float epsilon()
               {
                    return _NUMERIC_FLT_EPSILON_;
               }
               /*Smallest positive subnormal number*/
               static constexpr float sub_epsilon()
               {
                    return _NUMERIC_FLT_SUB_EPSILON_;
               }
               /*Minimum value of this type*/
               static constexpr float min()
               {
                    return -_NUMERIC_FLT_MAXIMUM_;
               }
               /*Maximum value of this type*/
               static constexpr float max()
               {
                    return _NUMERIC_FLT_MAXIMUM_;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(float);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(float);
               /*Is this type signed?*/
               static constexpr bool is_signed = true;
               /*Is this type integral?*/
               static constexpr bool is_integer = false;
               /*Is this type exact?*/
               static constexpr bool is_exact = false;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = true;
               /*DOes this type have "Not a Number"?*/
               static constexpr bool has_nan = true;
               /*Get an infinity if this type has one*/
               static constexpr float infinity(const bool& _neg)
               {
                    return necromancer_float_class::
                         _flt_inff(_neg);
               }
               /*Get a NaN if this type has one*/
               static constexpr float nan()
               {
                    return necromancer_float_class::
                         _flt_nanf();
               }
     };
     /*Specification for numeric_limits<double>*/
     template<>
     class numeric_limits<double>
     {
          public:
               /*Is this a specialized class?*/
               static constexpr bool is_specialized = true;
               /*Smallest positive normal number*/
               static constexpr double epsilon()
               {
                    return _NUMERIC_DBL_EPSILON_;
               }
               /*Smallest positive subnormal number*/
               static constexpr double sub_epsilon()
               {
                    return _NUMERIC_DBL_SUB_EPSILON_;
               }
               /*Minimum value of this type*/
               static constexpr double min()
               {
                    return -_NUMERIC_DBL_MAXIMUM_;
               }
               /*Maximum value of this type*/
               static constexpr double max()
               {
                    return _NUMERIC_DBL_MAXIMUM_;
               }
               /*Size in bytes of this type*/
               static constexpr int size = sizeof(double);
               /*Size in bits of this type*/
               static constexpr int bitsize = _bitsize(double);
               /*Is this type signed?*/
               static constexpr bool is_signed = true;
               /*Is this type integral?*/
               static constexpr bool is_integer = true;
               /*Is this type exact?*/
               static constexpr bool is_exact = false;
               /*Does this type have an infinity?*/
               static constexpr bool has_infinity = true;
               /*Does this type have "Not a Number"?*/
               static constexpr bool has_nan = true;
               /*Get an infinity if this type has one*/
               static constexpr double infinity(const bool& _neg)
               {
                    return necromancer_float_class::
                         _flt_infd(_neg);
               }
               /*Get a NaN if this type has one*/
               static constexpr double nan()
               {
                    return necromancer_float_class::
                         _flt_nand();
               }
     };
}

/*Return the high word of a [_float32] or [_float64] _i*/
#define hi(_i) _i._lh._hi
/*Return the low word of a [_float32] or [_float64] _i*/
#define lo(_i) _i._lh._lo

/*1 bit of information*/
#define bit bool
/*8 bit signed integer (signed char)*/
#define _s_int08 char
/*8 bit unsigned integer (unsigned char)*/
#define int08 unsigned char
/*16 bit signed integer (signed short)*/
#define _s_int16 short
/*16 bit unsigned integer (unsigned short)*/
#define int16 unsigned short
/*32 bit signed integer (signed long)*/
#define _s_int32 long
/*64 bit signed integer (signed long long)*/
#define _s_int64 long long
/*32-bit IEEE-754 float (float)*/
#define f32 float
/*32-bit IEEE-754 float (double)*/
#define f64 double
/*Union to acces the bits of a 32-bit float*/
typedef necromancer_float_class::float_32 float_32;
/*Union to access the bits of a 64-bit float*/
typedef necromancer_float_class::float_64 float_64;

namespace sorcery
{
     /*Generate a single precision infinity*/
     /*Set _n to true for a negative infinity, otherwise leave blank*/
     float inff(bool _n = false)
     {
          return numeric_limits<float>::infinity(_n);
     }
     /*Generate a double precision infinity*/
     /*Set _n to true for a negative infinity, otherwise leave blank*/
     double inf(bool _n = false)
     {
          return numeric_limits<double>::infinity(_n);
     }
     /*Generate a single precision "Not a Number"*/
     float nanf()
     {
          return numeric_limits<float>::nan();
     }
     /*Generate a double precision "Not a Number"*/
     double nan()
     {
          return numeric_limits<double>::nan();
     }
}

/*Single precision Infinity*/
#define INFINITYf numeric_limits<float>::infinity(false)
/*Double precision Infinity*/
#define INFINITY numeric_limits<double>::infinity(false)
/*Single precision Negative Infinity*/
#define NEGATIVE_INFINITYf numeric_limits<float>::infinity(true)
/*Double precision Negative Infinity*/
#define NEGATIVE_INFINITY numeric_limits<double>::infinity(true)
/*Single precision "Not a Number"*/
#define NaNf numeric_limits<float>::nan()
/*Double precision "Not a Number"*/
#define NaN numeric_limits<double>::nan()
/*π*/
#define pi 3.1415926535897932384
/*π/2*/
#define pi_2 1.5707963267948966192
/*π/4*/
#define pi_4 0.7853981633974483096
/*τ = 2π*/
#define tau 6.2831853071795864769
/*e ~ The base of natural logarithms*/
/*You should know what this is*/
#define e 2.7182818284590452354
/*log(2)*/
#define ln2 0.6931471805599453094
/*log_2(e)*/
#define log2e 1.4426950408889634074
/*√2*/
#define sqrt2 1.4142135623730950488
/*** IEEE-754 Float Classifications ***/

/*0.0 (Subnormal in IEEE-754)*/
/*This is a flag, not the actual value*/
#define _FLT_ZERO 0x001
/*"Not a Number"*/
/*This is a flag, not the actual value*/
#define _FLT_NAN 0x0002
/*Infinity*/
/*This is a flag, not the actual value*/
#define _FLT_INFINITY 0x0003
/*Negative Infinity*/
/*This is a flag, not the actual value*/
#define _FLT_NEG_INFY 0x0004
/*Normal Floating Point*/
/*This is a flag, not the actual value*/
#define _FLT_NORMAL 0x0005
/*Subnormal Float*/
/*This is a flag, not the actual value*/
#define _FLT_SUBNORMAL 0x0006


/*Main folder*/
#include "abs.hpp"
#include "exp.hpp"
#include "float_class.hpp"
/*gcf.hpp included later*/
#include "log.hpp"
#include "minmax.hpp"
#include "rem.hpp"
#include "roots.hpp"
#include "rounding.hpp"
#include "sign.hpp"
#include "swap.hpp"
#include "variadic.hpp"
/*Trig folder*/
#include "trig/acos.hpp"
#include "trig/asin.hpp"
#include "trig/atan.hpp"
#include "trig/atan2.hpp"

namespace sorcery
{
     /*** Trig functions ***/

     /*** acos ***/
     #ifdef _NECROMANCER_ACOS_
          /*12/24/2023*/
          /*Compute the arccosine of a 32-bit float _x*/
          constexpr float acos(const float& _x)
          {
               return necromancer_acos::acosf(_x);
          }
          /*12/24/2023*/
          /*Compute the arccosine of a 64-bit float _x*/
          constexpr double acos(const double& _x)
          {
               return necromancer_acos:: 
                    acosd(_x);
          }
          /*12/24/2023*/
          /*Compute the arccosine of a number _x*/
          /*(Cast to double)*/
          template<typename _acos_ty>
          constexpr double acos(const _acos_ty& _x)
          {
               return necromancer_acos::
                    acosd(static_cast<double>(_x));
          }
     #else
          #warning "Could not get acos()"
     #endif /*_NECROMANCER_ACOS_*/

     /*** asin ***/
     #ifdef _NECROMANCER_ASIN_
          /*12/24/2023*/
          /*Compute the arcsine of a 32-bit float _x*/
          constexpr float asin(const float& _x)
          {
               return necromancer_asin::
                    asinf(_x);
          }
          /*12/24/2023*/
          /*Compute the arcsine of a 64-bit float _x*/
          constexpr double asin(const double& _x)
          {
               return necromancer_asin::
                    asind(_x);
          }
          /*12/24/2023*/
          /*Compute the arcsine of a number _x*/
          /*(Cast to double)*/
          template<typename _asin_ty>
          constexpr double asin(const _asin_ty& _x)
          {
               return necromancer_asin::
                    asind(static_cast<double>(_x));
          }
     #else
          #warning "Could not get asin()"
     #endif /*_NECROMANCER_ASIN_*/

     /*** atan ***/
     #ifdef _NECROMANCER_ATAN_
          /*12/24/2023*/
          /*Compute the arctangent of a 32-bit float _x*/
          constexpr float atan(const float& _x)
          {
               return necromancer_atan::
                    atanf(_x);
          }
          /*12/24/2023*/
          /*Compute the arctangent of a 64-bit float _x*/
          constexpr double atan(const double& _x)
          {
               return necromancer_atan::
                    atand(_x);
          }
          /*12/24/2023*/
          /*Compute the arctangent of a number _x*/
          /*(Cast to Double)*/
          template<typename _atan_ty>
          constexpr double atan(const _atan_ty& _x)
          {
               return necromancer_atan::
                    atand(static_cast<double>(_x));
          }
     #else
          #warning "Could not get atan()"
     #endif /*_NECROMANCER_ATAN_*/

     /*** atan2 ***/
     #ifdef _NECROMANCER_ATAN2_
          /*12/24/2023*/
          /*Figure out what it does; it's not my job to tell you*/
          constexpr float atan2(const float& _y, const float& _x)
          {
               return necromancer_atan2::
                    atan2f(_y, _x);
          }
          /*12/24/2023*/
          /*Figure out what it does; it's not my job to tell you*/
          constexpr double atan2(const double& _y, const double& _x)
          {
               return necromancer_atan2::
                    atan2d(_y, _x);
          }
          /*12/24/2023*/
          /*Figure out what it does; it's not my job to tell you*/
          template<typename _atan2_ty>
          constexpr double atan2(const _atan2_ty& _x, const _atan2_ty& _y)
          {
               return necromancer_atan2::
                    atan2d(static_cast<double>(_x),
                         static_cast<double>(_y));
          }
     #else
          #warning "Could not get atan2()"
     #endif /*_NECROMANCER_ATAN2_*/

     /*** abs ***/
     #ifdef _NECROMANCER_ABS_
          /*12/24/2023*/
          /*Get the absolute value of a 32-bit float _x*/
          constexpr float abs(const float& _x)
          {
               return necromancer_abs::
                    absf(_x);
          }
          /*12/24/2023*/
          /*Get the absolute value of a 64-bit float _x*/
          constexpr double abs(const double& _x)
          {
               return necromancer_abs::
                    absd(_x);
          }
          /*1/7/2024*/
          /*Get the absolute value of a number _x*/
          template<typename _abs_ty>
          constexpr _abs_ty abs(const _abs_ty& _x)
          {
               return _x > 0? _x : -_x;
          }
     #else
          #warning "Could not get abs()"
     #endif /*_NECROMANCER_ABS_*/

     /*1/7/2023*/
     /*Get the number of trailing zeros of a 32 bit int _x*/
     /*It's not the fastest, but it does the job...*/
     constexpr int countr_zero(const int& _x)
     {
          /*|_x|*/
          if(_x == 0)
               return 32;
          /*I am confused by this part. I just stole it from*/
          /*the Java stl*/
          int _i = ~_x & (_x - 1);
          int _c = 1;
          if(_i > 0x8000)
          {
               _c += 16;
               _i >>= 16;
          }
          if(_i > 0x0080){
               _c += 8;
               _i >>= 8;
          }
          if(_i > 0x0008)
          {
               _c += 4;
               _i >>= 4;
          }
          if(_i > 0x0002)
          {
               _c += 2;
               _i >>= 2;
          }
          return _c + (_i >> 1);
     }
     /*1/7/2023*/
     /*Get the number of trailing zeros of a 64 bit int _x*/
     /*It's not the fastest, but it does the job...*/
     constexpr long long countr_zero(const long long _x)
     {
          if(_x == 0)
               return 64;
          /*I am confused by this part. I just stole it from*/
          /*the Java stl*/
          long long _i = ~_x & (_x - 1);
          long long _c = 1;
          if(_i > 0x80000000)
          {
               _c += 32;
               _i >>= 32;
          }
          if(_i > 0x8000)
          {
               _c += 16;
               _i >>= 16;
          }
          if(_i > 0x0080){
               _c += 8;
               _i >>= 8;
          }
          if(_i > 0x0008)
          {
               _c += 4;
               _i >>= 4;
          }
          if(_i > 0x0002)
          {
               _c += 2;
               _i >>= 2;
          }
          return _c + (_i >> 1);
     }

     /*** exp and exp2 ***/
     #ifdef _NECROMANCER_EXP_
          /*** exp ***/

          /*Returm the base e exponential of a 32-bit float _x, where*/
          /*e is the base of natural logarithms*/
          constexpr float exp(const float& _x)
          {
               return necromancer_exp::expf(_x);
          }
          /*Returm the base e exponential of a 64-bit float _x, where*/
          /*e is the base of natural logarithms*/
          constexpr double exp(const double& _x)
          {
               return necromancer_exp::expd(_x);
          }
          /*Returm the base e exponential of _x, where*/
          /*e is the base of natural logarithms*/
          template<typename _exp_ty>
          double exp(const _exp_ty& _x)
          {
               return necromancer_exp::expd(static_cast<double>(_x));
          }
          /*** exp2 ***/

          /*Returm the base 2 exponential of a 32-bit float _x*/
          constexpr float exp2(const float& _x)
          {
               return necromancer_exp::exp2f(_x);
          }
          /*Returm the base 2 exponential of a 64-bit float _x*/
          constexpr double exp2(const double& _x)
          {
               return necromancer_exp::exp2d(_x);
          }
          /*Returm the base 2 exponential of _x*/
          template<typename _exp_ty>
          double exp2(const _exp_ty& _x)
          {
               return necromancer_exp::exp2d(static_cast<double>(_x));
          }
     #else
          #warning Could not get exp() or exp2()
     #endif

     /*** float_class stuff ***/
     #ifdef _NECROMANCER_FLOAT_CLASS_
          /*12/27/2023*/
          /*Classify a 32-bit float*/
          /*1: Zero*/
          /*2: "Not a Number"*/
          /*3: Infinity*/
          /*4: -Infinity*/
          /*5: Normal float*/
          /*6: Subnormal float*/
          constexpr int classify(const float& _x)
          {
               return necromancer_float_class::
                    classify_ieee754_32f(_x);
          }
          /*12/27/2023*/
          /*Classify a 64-bit float*/
          /*1: Zero*/
          /*2: "Not a Number"*/
          /*3: Infinity*/
          /*4: -Infinity*/
          /*5: Normal float*/
          /*6: Subnormal float*/
          constexpr int classify(const double& _x)
          {
               return necromancer_float_class::
                    classify_ieee754_64f(_x);
          }
          /*12/28/2023*/
          /*Classify a number _x as if it was a 64-bit float*/
          /*1: Zero*/
          /*2: "Not a Number"*/
          /*3: Infinity*/
          /*4: -Infinity*/
          /*5: Normal float*/
          /*6: Subnormal float*/
          template<typename _classify_ty>
          int classify(const _classify_ty& _x)
          {
               return necromancer_float_class::
                    classify_ieee754_64f(static_cast<double>(_x));
          }
          /*12/27/2023*/
          /*Return true if a 32-bit float is infinite*/
          constexpr bool is_inf(const float& _x)
          {
               return necromancer_float_class::
                    is_inff(_x);
          }
          /*12/27/2023*/
          /*Return true if a 64-bit float is infinite*/
          constexpr bool is_inf(const double& _x)
          {
               return necromancer_float_class::
                    is_infd(_x);
          }
          /*12/28/2023*/
          /*Return true if a number _x is infinite*/
          /*(Cast to Double)*/
          template<typename _inf_ty>
          constexpr bool is_inf(const _inf_ty& _x)
          {
               return necromancer_float_class::
                    is_infd(static_cast<double>(_x));
          }
          /*12/27/2023*/
          /*Return true if a 32-bit float is finite*/
          constexpr bool is_finite(const float& _x)
          {
               return necromancer_float_class::
                    is_finitef(_x);
          }
          /*12/27/2023*/
          /*Return true if a 64-bit float is finite*/
          constexpr bool is_finite(const double& _x)
          {
               return necromancer_float_class::
                    is_finited(_x);
          }
          /*12/28/2023*/
          /*Return true if a number _x float is finite*/
          /*(Cast to Double)*/
          template<typename _finite_ty>
          constexpr bool is_finite(const _finite_ty& _x)
          {
               return necromancer_float_class::
                    is_finited(static_cast<double>(_x));
          }
          /*12/27/2023*/
          /*Return true if a 32-bit float is "Not a Number"*/
          constexpr bool is_nan(const float& _x)
          {
               return necromancer_float_class::
                    is_nanf(_x);
          }
          /*12/27/2023*/
          /*Return true if a 64-bit float is "Not a Number"*/
          constexpr bool is_nan(const double& _x)
          {
               return necromancer_float_class::
                    is_nand(_x);
          }
          /*12/28/2023*/
          /*Return true if a number _x is "Not a Number"*/
          /*(Cast to Double)*/
          template<typename _nan_ty>
          constexpr bool is_nan(const _nan_ty& _x)
          {
               return necromancer_float_class::
                    is_nand(static_cast<double>(_x));
          }
          /*12/27/2023*/
          /*Return true if a 32-bit float is positive*/
          constexpr bool is_positive(const float& _x)
          {
               return necromancer_float_class::
                    is_positivef(_x);
          }
          /*12/27/2023*/
          /*Return true if a 64-bit float is positive*/
          constexpr bool is_positive(const double& _x)
          {
               return necromancer_float_class::
                    is_positived(_x);
          }
          /*12/28/2023*/
          /*Return true if a number _x is positive*/
          /*(Cast to Double)*/
          template<typename _pos_ty>
          constexpr bool is_positive(const _pos_ty& _x)
          {
               return necromancer_float_class::
                    is_positived(static_cast<double>(_x));
          }
          /*12/27/2023*/
          /*Return true if a 32-bit float is negative*/
          constexpr bool is_negative(const float& _x)
          {
               return necromancer_float_class::
                    is_negativef(_x);
          }
          /*12/27/2023*/
          /*Return true if a 64-bit float is negative*/
          constexpr bool is_negative(const double& _x)
          {
               return necromancer_float_class::
                    is_negatived(_x);
          }
          /*12/28/2023*/
          /*Return true if a number _x is negative*/
          /*(Cast to Double)*/
          template<typename _neg_ty>
          constexpr bool is_negative(const _neg_ty& _x)
          {
               return necromancer_float_class::
                    is_negatived(static_cast<double>(_x));
          }
          /*12/27/2023*/
          /*Return true if a 32-bit float can be expressed as an integer*/
          constexpr bool is_int(const float& _x)
          {
               return necromancer_float_class::
                    is_intf(_x);
          }
          /*12/27/2023*/
          /*Return true if a 64-bit float can be expressed as an integer*/
          constexpr bool is_int(const double& _x)
          {
               return necromancer_float_class::
                    is_intd(_x);
          }
          /*12/28/2023*/
          /*Return true if a number _x can be expressed as an integer*/
          /*(Cast to Double)*/
          template<typename _int_ty>
          constexpr bool is_int(const _int_ty& _x)
          {
               return necromancer_float_class::
                    is_intd(static_cast<double>(_x));
          }
          /*12/27/2023*/
          /*Return true if a 32-bit float cannot be expressed as an integer*/
          constexpr bool is_decimal(const float& _x)
          {
               return necromancer_float_class::
                    is_decimalf(_x);
          }
          /*12/27/2023*/
          /*Return true if a 64-bit float cannot be expressed as an integer*/
          constexpr bool is_decimal(const double& _x)
          {
               return necromancer_float_class::
                    is_decimald(_x);
          }
          /*12/28/2023*/
          /*Return true if a number _x cannot be expressed as an integer*/
          /*(Cast to Double)*/
          template<typename _dec_ty>
          constexpr bool is_decimal(const _dec_ty& _x)
          {
               return necromancer_float_class::
                    is_decimald(_x);
          }
          /*12/27/2023*/
          /*Return the next representable 32-bit float after _x towards _y*/
          constexpr float nextafter(const float& _x, const float& _y)
          {
               return necromancer_float_class::
                    nextafterf(_x, _y);
          }
          /*12/27/2023*/
          /*Return the next representable 64-bit float after _x towards _y*/
          constexpr double nextafter(const double& _x, const double& _y)
          {
               return necromancer_float_class::
                    nextafterd(_x, _y);
          }
          /*12/28/2023*/
          /*Return the next representable 64-bit float after _x towards _y*/
          /*(Cast to Double)*/
          template<typename _next_ty>
          constexpr double nextafter(const _next_ty& _x, const _next_ty& _y)
          {
               return necromancer_float_class::
                    nextafterd(static_cast<double>(_x),
                              static_cast<double>(_y));
          }
          /*12/27/2023*/
          /*Divide a 32-bit float by 2*/
          constexpr float flto2(const float& _x)
          {
               return necromancer_float_class::
                    f32o2(_x);
          }
          /*12/27/2023*/
          /*Divide a 64-bit float by 2*/
          constexpr double flto2(const double& _x)
          {
               return necromancer_float_class::
                    f64o2(_x);
          }
          /*1/9/2024*/
          /*Return a 32 bit float _f where 0.5 <= |_f| < 1, and set *_e to be*/
          /*an exponent where _x = _f * 2^_e*/
          constexpr float frexp(const float& _x, int* _e)
          {
               return necromancer_float_class::
                    frexpf(_x, _e);
          }
          /*1/9/2024*/
          /*Return a 64 bit float _f where 0.5 <= |_f| < 1, and set *_e to be*/
          /*an exponent where _x = _f * 2^_e*/
          constexpr double frexp(const double& _x, int* _e)
          {
               return necromancer_float_class::
                    frexpd(_x, _e);
          }
          /*1/9/2024*/
          /*Return a 32 bit float _f where _f = _x * 2^_e*/
          constexpr float ldexp(const float& _x, const int& _e)
          {
               return necromancer_float_class::
                    ldexpf(_x, _e);
          }
          /*1/9/2024*/
          /*Return a 64 bit float _f where _f = _x * 2^_e*/
          constexpr double ldexp(const double& _x, const int& _e)
          {
               return necromancer_float_class::
                    ldexpd(_x, _e);
          }
     #else
          /*This error has already been accounted for*/
     #endif
}
     #include "gcf.hpp"

namespace sorcery
{
     /*** gcf and lcm ***/
     #ifdef _NECROMANCER_GCF_
          /*** gcf ***/

          /*12/24/2023*/
          /*Get the greatest common factor of two 32-bit ints _x and _y*/
          constexpr int gcf(const int& _x, const int& _y)
          {
               return necromancer_gcf::
                    gcf(_x, _y);
          }
          /*1/7/2024*/
          /*Get the greatest common factor of two 64-bit ints _x and _y*/
          constexpr _s_int64 gcf(const _s_int64& _x, const _s_int64& _y)
          {
               return necromancer_gcf::
                    gcf(_x, _y);
          }
          /*** lcm ***/

          /*1/3/2023*/
          /*Get the least common multiple of two 32-bit ints _x and _y*/
          constexpr int lcm(const int& _x, const int& _y)
          {
               return necromancer_gcf::
                    lcm(_x, _y);
          }
          /*1/7/2024*/
          /*Get the least common multiple of two 64-bit ints _x and _y*/
          constexpr _s_int64 lcm(const _s_int64 _x, const _s_int64 _y)
          {
               return necromancer_gcf::
                    lcm(_x, _y);
          }
     #else
          #warning Could not get gcf() or lcm()
     #endif /*_NECROMANCER_GCF_*/

     /*** logarithms ***/
     #ifdef _NECROMANCER_LOG_
          /*** log ~ ln ***/

          /*12/24/2023*/
          /*Compute the natural logarithm of a 32-bit float _x*/
          constexpr float log(const float& _x)
          {
               return necromancer_log::
                    logf(_x);
          }
          /*12/24/2023*/
          /*Compute the natural logarithm of a 64-bit float _x*/
          constexpr double log(const double& _x)
          {
               return necromancer_log::
                    logd(_x);
          }
          /*12/24/2023*/
          /*Compute the natural logarithm of a number _x*/
          /*(Cast to Double)*/
          template<typename _log_ty>
          constexpr double log(const _log_ty& _x)
          {
               return necromancer_log::
                    logd(static_cast<double>(_x));
          }
          /*** log2 ***/

          /*12/24/2023*/
          /*Compute the base-2 logarithm of a 32-bit float _x*/
          constexpr float log2(const float& _x)
          {
               return necromancer_log::
                    log2f(_x);
          }
          /*12/24/2023*/
          /*Compute the base-2 logarithm of a 64-bit float _x*/
          constexpr double log2(const double& _x)
          {
               return necromancer_log::
                    log2d(_x);
          }
          /*12/24/2023*/
          /*Compute the base-2 logarithm of a number _x*/
          /*(Cast to Double)*/
          template<typename _log2_ty>
          constexpr double log2(const _log2_ty& _x)
          {
               return necromancer_log::
                    log2d(static_cast<double>(_x));
          }
          /*** ilog2 ***/

          /*12/24/2023*/
          /*Return the integral part of the base-2 logarithm of a 32-bit float _x*/
          constexpr int ilog2(const float& _x)
          {
               return necromancer_log::
                    ilog2f(_x);
          }
          /*12/24/2023*/
          /*Return the integral part of the base-2 logarithm of a 64-bit float _x*/
          constexpr int ilog2(const double& _x)
          {
               return necromancer_log::
                    ilog2d(_x);
          }
          /*12/24/2023*/
          /*Return the integral part of the base-2 logarithm of a number _x*/
          /*(Cast to Double)*/
          template<typename _ilog2_ty>
          constexpr int ilog2(const _ilog2_ty& _x)
          {
               return necromancer_log::
                    ilog2d(static_cast<double>(_x));
          }
          /*** log10 ***/

          /*12/24/2023*/
          /*Compute the base-10 logarithm of a 32-bit float _x*/
          constexpr float log10(const float& _x)
          {
               return necromancer_log::
                    log10f(_x);
          }
          /*12/24/2023*/
          /*Compute the base-10 logarithm of a 64-bit float _x*/
          constexpr double log10(const double& _x)
          {
               return necromancer_log::
                    log10d(_x);
          }
          /*12/24/2023*/
          /*Compute the base-10 logarithm of a number _x*/
          /*(Cast to Double)*/
          template<typename _log10_ty>
          constexpr double log10(const _log10_ty& _x)
          {
               return necromancer_log::
                    log10d(static_cast<double>(_x));
          }
          /*** custom base logarithm ***/

          /*12/24/2023*/
          /*Return a logarithm with any base of 32-bit floats _x and _y*/
          /*_y is the base of the logarithm*/
          constexpr float log(const float& _x, const float& _y)
          {
               return necromancer_log::
                    logf(_x, _y);
          }
          /*12/24/2023*/
          /*Return a logarithm with any base of 64-bit floats _x and _y*/
          /*_y is the base of the logarithm*/
          constexpr double log(const double& _x, const double& _y)
          {
               return necromancer_log::
                    logd(_x, _y);
          }
          /*12/24/2023*/
          /*Return a logarithm with any base of numbers _x and _y*/
          /*_y is the base of the logarithm*/
          /*(Cast to Double)*/
          template<typename _log_ty>
          constexpr double log(const _log_ty& _x, const _log_ty& _y)
          {
               return necromancer_log::
                    logd(static_cast<double>(_x),
                         static_cast<double>(_y));
          }

     #else
          #warning "Could not get log(), log2(), ilog2(), or log10()"
     #endif /*_NECROMANCER_LOG_*/

     /*** min, max ***/
     #ifdef _NECROMANCER_MIN_MAX_
          /*12/28/2023*/
          /*This gets max(_x, _y)*/
          template<typename _max_ty>
          constexpr _max_ty max(const _max_ty& _x, const _max_ty& _y)
          {
               return necromancer_min_max::
                    max(_x, _y);
          }
          /*12/28/2023*/
          /*Return the maximum value in an array*/
          template<typename _arr_ty, int _arr_size>
          constexpr _arr_ty max(const _arr_ty (&_arr)[_arr_size])
          {
               return necromancer_min_max::
                    arr_max(_arr);
          }
          /*12/28/2023*/
          /*This gets min(_x, _y)*/
          template<typename _min_ty>
          constexpr _min_ty min(const _min_ty& _x, const _min_ty& _y)
          {
               return necromancer_min_max::
                    min(_x, _y);
          }
          /*12/28/2023*/
          /*Return the minimum value in an array*/
          template<typename _arr_ty, int _arr_size>
          constexpr _arr_ty min(const _arr_ty (&_arr)[_arr_size])
          {
               return necromancer_min_max::
                    arr_min(_arr);
          }
     #else
          #warning "Could not get min() or max()"
     #endif /*_NECROMANCER_LOG_*/

     /*** rem ***/
     #ifdef _NECROMANCER_REM_
          /*12/24/2023*/
          /*Get the remainder after dividing _x by _y*/
          constexpr float rem(const float& _x, const float& _y)
          {
               return necromancer_rem::
                    remf(_x, _y);
          }
          /*12/24/2023*/
          /*Get the remainder after dividing _x by _y*/
          constexpr double rem(const double& _x, const double& _y)
          {
               return necromancer_rem::
                    remd(_x, _y);
          }
          /*12/24/2023*/
          /*Get the remainder after dividing _x by _y*/
          constexpr int rem(const int& _x, const int& _y)
          {
               return _x % _y;
          }
     #else
          #warning "Could not get rem()"
     #endif /*_NECROMANCER_REM_*/

     /*** sqrt ***/
     #ifdef _NECROMANCER_ROOTS_
          /*12/24/2023*/
          /*Compute the square root of a 32-bit float _x*/
          constexpr float sqrt(const float& _x)
          {
               return necromancer_root::
                    sqrtf(_x);
          }
          /*12/24/2023*/
          /*Compute the square root of a 64-bit float _x*/
          constexpr double sqrt(const double& _x)
          {
               return necromancer_root::
                    sqrtd(_x);
          }
          /*12/24/2023*/
          /*Compute the square root of a number _x*/
          /*(Cast to Double)*/
          template<typename _sqrt_ty>
          constexpr double sqrt(const _sqrt_ty& _x)
          {
               return necromancer_root::
                    sqrtd(static_cast<double>(_x));
          }
     #else
          #warning "Could not get sqrt()"
     #endif /*_NECROMANCER_ROOTS_*/

     /*** rounding functions ***/
     #ifdef _NECROMANCER_ROUND_
          /*** trunc ***/

          /*1/5/2024*/
          /*Round a 32-bit float towards 0*/
          constexpr float trunc(const float& _x)
          {
               return necromancer_round::
                    truncf(_x);
          }
          /*1/5/2024*/
          /*Round a 64-bit float towards 0*/
          constexpr double trunc(const double& _x)
          {
               return necromancer_round::
                    truncd(_x);
          }
          /*1/5/2024*/
          /*Round a number _x towards 0*/
          template<typename _trunc_ty>
          constexpr double trunc(const _trunc_ty& _x)
          {
               return necromancer_round::
                    truncd(static_cast<double>(_x));
          }
          /*1/6/2024*/
          /*Round a 32-bit float towards -inf*/
          constexpr float floor(const float& _x)
          {
               return necromancer_round::
                    floorf(_x);
          }
          /*1/6/2024*/
          /*Round a 64-bit float towards -inf*/
          constexpr double floor(const double& _x)
          {
               return necromancer_round::
                    floord(_x);
          }
          /*1/6/2024*/
          /*Round a number _x towards -inf*/
          template<typename _floor_ty>
          constexpr double floor(const _floor_ty& _x)
          {
               return necromancer_round::
                    floorf(static_cast<double>(_x));
          }
          /*1/6/2024*/
          /*Round a 32-bit float towards inf*/
          constexpr float ceil(const float& _x)
          {
               return necromancer_round::
                    ceilf(_x);
          }
          /*1/6/2024*/
          /*Round a 64-bit float towards inf*/
          constexpr double ceil(const double& _x)
          {
               return necromancer_round::
                    ceild(_x);
          }
          /*1/6/2024*/
          /*Round a number _x towards inf*/
          template<typename _ceil_ty>
          constexpr double ceil(const _ceil_ty& _x)
          {
               return necromancer_round::
                    ceild(static_cast<double>(_x));
          }
     #else
     #endif /*_NECROMANCER_ROUND_*/

     /*** sign functions ***/
     #ifdef _NECROMANCER_SIGN_
          /*** sign ***/

          /*12/24/2023*/
          /*Get the sign of a 32-bit float _x*/
          constexpr int sign(const float& _x)
          {
               return necromancer_sign::
                    signf(_x);
          }
          /*12/24/2023*/
          /*Get the sign of a 64-bit float _x*/
          constexpr int sign(const double& _x)
          {
               return necromancer_sign::
                    signd(_x);
          }
          /*12/24/2023*/
          /*Get the sign of a number _x*/
          template<typename _sign_ty>
          constexpr _sign_ty sign(const _sign_ty& _x)
          {
               return _x > 0? 1 : -1;
          }
          /*** signbit ***/

          /*12/24/2023*/
          /*Get the sign bit of a 32-bit float _x*/
          constexpr int signbit(const float& _x)
          {
               return necromancer_sign::
                    sign_bitf(_x);
          }
          /*12/24/2023*/
          /*Get the sign bit of a 64-bit float _x*/
          constexpr int signbit(const double& _x)
          {
               return necromancer_sign::
                    sign_bitd(_x);
          }
          /*12/24/2023*/
          /*Get the sign bit of a number _x*/
          /*(Cast to Double)*/
          template<typename _signbit_ty>
          constexpr int signbit(const _signbit_ty& _x)
          {
               return necromancer_sign::
                    sign_bitd(static_cast<double>(_x));
          }
          /*** copysign ***/

          /*12/24/2023*/
          /*Return a new 32-bit float with a magnitude of _x and a sign of _y*/
          constexpr float copysign(const float& _x, const float& _y)
          {
               return necromancer_sign::
                    copysignf(_x, _y);
          }
          /*12/24/2023*/
          /*Return a new 64-bit float with the magnitude of _x and the sign of _y*/
          constexpr double copysign(const double& _x, const double& _y)
          {
               return necromancer_sign::
                    copysignd(_x, _y);
          }
          /*12/24/2023*/
          /*Return a new integer with the magnitude of _x and the sign of _y*/
          /*(Cast to Double)*/
          constexpr int copysign(const int& _x, const int& _y)
          {
               return necromancer_sign:: 
                    copysignd(static_cast<double>(_x),
                         static_cast<double>(_y));
          }
          /*12/24/2023*/
          /*Return a new number with the magnidute of _x and the sign of _y*/
          /*(Cast to Double)*/
          template<typename _copysign_ty>
          constexpr _copysign_ty copysign(const _copysign_ty& _x, const _copysign_ty& _y)
          {
               return static_cast<_copysign_ty>(necromancer_sign::
                    copysignd(static_cast<double>(_x),
                         static_cast<double>(_y)));
          }
     #else
          #warning "Could not get signbit(), sign(), or copysign()"
     #endif /*_NECROMANCER_SIGN_*/

     /*** swap ***/
     #ifdef _NECROMANCER_SWAP_
          /*12/22/2023*/
          /*This does what you think it does*/
          template<typename _swap_ty>
          void swap(_swap_ty& _x, _swap_ty& _y)
          {
               return necromancer_swap::
                    swap(_x, _y);
          }
     #else     
          #warning "Could not get swap()"
     #endif /*_NECROMANCER_SWAP*/

     /*** Variadic functions ***/
     #ifdef _NECROMANCER_VARIADIC_
          /*12/28/2023*/
          /*Return the number of arguments passed into this function*/
          /*Might be useful???*/
          template<typename _arg_ty = double, typename... _args>
          constexpr unsigned long num_args(_args... _arg)
          {
               return necromancer_variadic::
                    num_args<_arg_ty>(_arg...);
          }
          /*12/28/2023*/
          /*Return the maximum value given a variable number of inputs*/
          template<typename _arg_ty = double, typename... _args>
          constexpr _arg_ty max(_args... _arg)
          {
               return necromancer_variadic::
                    max(_arg...);
          }
          /*12/28/2023*/
          /*Return the minimum value given a variable number of inputs*/
          template<typename _arg_ty = double, typename... _args>
          constexpr _arg_ty min(_args... _arg)
          {
               return necromancer_variadic::
                    min(_arg...);
          }
     #else
          #warning "Could not get variadic functions"
     #endif /*_NECROMANCER_VARIADIC_*/
}

#endif /*_MATH_SORCERY_*/
