/*The Math Necromancer*/

/*============ C++ Infinite and Undefined Value Support ============*/

/*NaN: Not a Number - undefined. Quiet NaNs do not raise errors, while*/
/*Signal NaNs do. <= (Errors not supported yet - Signal NaNs are useless...)*/

/*Infinity: ∞*/

/*If you can't read Hexidecimal you will die*/

/*You'll also probably decompose if you can't or don't understnad*/
/*IEEE 754 floating point formatting...*/

/*=====================================*/

#ifndef _NECROMANCER_NAN_INF_
#define _NECROMANCER_NAN_INF_

typedef unsigned long long int ulongl_t;
typedef unsigned long int ulong_t;

/*NaN and Undefined Values*/
/*========================*/

/*Unions to store the bits and cast them to floats later...*/

union nan_float_bits
{
    ulong_t bits;
    float nan_value;
};
union nan_double_bits
{
    ulongl_t bits;
    double nan_value;
};

/*Funny IEEE bit hacks :)*/

/*Quiet NaN - Signed Bit set to 1*/
/*e.g ~ 1-11111111-10000000000000000000000*/

/*Signal NaN - Signed Bit set to 0*/
/*e.g ~ 0-11111111-10000000000000000000000*/

nan_float_bits static qnanf_bits = {0xffc00000};
nan_float_bits static snanf_bits = {0x7fc00000};

nan_double_bits static qnand_bits = {0xfff8000000000000};
nan_double_bits static snand_bits = {0x7ff8000000000000};

/*Define the NaN's...*/

/*Single Precision Quiet NaN*/
#define _qNaNf qnanf_bits.nan_value
/*Double Precision Quiet NaN*/
#define _qNaNd qnand_bits.nan_value

/*Single Precision Signal NaN*/
#define _sNaNf snanf_bits.nan_value
/*Double Precision Signal NaN*/
#define _sNaNd snand_bits.nan_value

/*Return a Single Precision Quiet NaN*/
template<typename _return = float>
_return qnanf()
{
     return _qNaNf;
}
/*Return a Single Precision Signal NaN*/
template<typename _return = float>
_return snanf()
{
     return _sNaNf;
}
/*Return a Double Precision Quiet NaN*/
template<typename _return = double>
_return qnan()
{
     return _qNaNd;
}
/*Return a Double Precision Signal NaN*/
template<typename _return = double>
_return snan()
{
     return _sNaNd;
}

/*Return a NaN*/
template<typename _nan_ty_ = double>
_nan_ty_ nan(const bool& is_quiet, const bool& is_double)
{
     switch (is_double)
     {
          case 1:
               return is_quiet? qnan<_nan_ty_>(): snan<_nan_ty_>();
               break;
          default:
               return is_quiet? qnanf<_nan_ty_>(): snanf<_nan_ty_>();
               break;
     }    
}

/*Double Precision Quiet NaN*/
/*If you want other NaNs, use nan() or different #defines*/
#define NaN nan<double>(1, 1)
/*Single Precision Quiet NaN*/
/*If you want other NaNs, use nan() or different #defines*/
#define NaNf nan<float>(1, 0)
/*Double Precision Signal NaN*/
/*If you want other NaNs, use nan() or different #defines*/
#define sNaN nan<double>(0, 1)
/*Single Precision Signal NaN*/
/*If you want other NaNs, use nan() or different #defines*/
#define sNaNf nan<float>(0, 0)

/*Double Precision Quiet undefined/NaN*/
/*If you want other undefineds/NaNs, use nan() or different #defines*/
#define undefined nan<double>(1, 1)
/*Single Precision Quiet undefined/NaN*/
/*If you want other undefineds/NaNs, use nan() or different #defines*/
#define undefinedf nan<float>(1, 0)

/*Infinities ( +- ∞ )*/
/*==================*/

/*Unions to store the bits and cast them to floats later...*/

union inf_float_bits
{
     ulong_t bits;
     float inf;
};
union inf_double_bits
{
     ulongl_t bits;
     double inf;
};

/*More evil IEEE 754 bit hacking :)*/

/*Infinity:*/
/*0-11111111-00000000000000000000000*/
/*-Infinity:*/
/*1-11111111-00000000000000000000000*/

inf_float_bits static inff_bits = {0x7f800000};
inf_float_bits static ninff_bits = {0xff800000};

inf_double_bits static infd_bits = {0x7ff0000000000000};
inf_double_bits static ninfd_bits = {0xfff0000000000000};

/*Define the Infinities...*/

/*Single Precision Infinity*/
#define Inff inff_bits.inf
/*Double Precision Infinity*/
#define Infd infd_bits.inf

/*Single Precision Negative Infinity*/
#define Ninff ninff_bits.inf
/*Double Precision Negative Infinity*/
#define Ninfd ninfd_bits.inf

template<typename _return = float>
/*Return a Single Precision Infinity*/
_return inff()
{
     return Inff;
}
template<typename _return = float>
/*Return a Single Precision Negative Infinity*/
_return ninff()
{
     return Ninff;
}

template<typename _return = double>
/*Return a Double Precision Infinity*/
_return inf()
{
     return Infd;
}
template<typename _return = double>
/*Return a Double Precision Negative Infinity*/
_return ninf()
{
     return Ninfd;
}

template<typename _inf_ty_ = double>
_inf_ty_ inf(const bool& is_negative, const bool& is_double)
{
     switch(is_double)
     {
          case 1:
               return is_negative? ninf<_inf_ty_>(): inf<_inf_ty_>();
               break;
          default:
               return is_negative? ninff<_inf_ty_>(): inff<_inf_ty_>();
               break;
     }
}

/*Double Precision Infinity*/
/*If you want other Infinities, use inf() or different #defines*/
#define INFINITY inf<double>(0, 1)
/*Single Precision Infinity*/
/*If you want other Infinities, use inf() or different #defines*/
#define INFINITYf inf<float>(0, 0)
/*Double Precision Infinity*/
/*If you want other Infinities, use inf() or different #defines*/
#define NEGATIVE_INFINITY inf<double>(1, 1)
/*Double Precision Negative Infinity*/
/*If you want other Infinities, use inf() or different #defines*/
#define NEGATIVE_INFINITYf inf<float>(1, 0)

#endif /*_NECROMANCER_NAN_INF_*/