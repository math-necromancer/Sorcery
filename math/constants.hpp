/*The Math Necromancer*/

#ifndef __CONSTANTS__
#define __CONSTANTS__

typedef unsigned long long uint64_t;

//Infinity and undefined

/*Infinities*/
#define INFINITY (1.0 / 0.0)
/*-inf - Never used as it just returns NaN*/
#define NEGATIVE_INFINITY (-1.0 / 0.0)
#define RECIPROCAL_INFINITY 0.0

/*NaN and Undefined Values*/

union double_bits
{
    uint64_t bits;
    double value;
};

double_bits static nan_bits = {0x7FF8000000000001ull};

#define NaN (nan_bits.value)
#define undefined NaN

//Finite Constants for Math

/*Stuff with pi*/
#define pi 3.1415926535897932384626
/*2 pi*/
#define tau 6.2831853071795864769252
/*pi / 2*/
#define pi_2 1.5707963267948966192313
/*pi / 3*/
#define pi_3 1.0471975511965977461542
/*pi / 4*/
#define pi_4 0.7853981633974483096156
/*pi / 6*/
#define pi_6 0.5235987755982988730771

/*Angle Conversion constants*/
#define rad_to_deg 57.29577951308232
#define deg_to_rad 0.017453292519943

/*Euler stuff*/
#define e 2.7182818284590452353602
#define gamma 0.577215664901532

/*Physics things*/

/*Speed of light in a vacuum*/
/*measured in m/s*/
#define C 299792458
/*Planck Constant*/
#define planck_h 6.62607015e-34
/*planck_h / pi_2*/
#define reduced_plank_h 1.054571817e-34
/*Elementary Charge*/
#define e_charge 1.602176634e-19
/*Mass of an Electron*/
#define m_e 9.1093837015e-31
/*Mass of a Proton*/
#define m_p 1.67262192369e-27
/*Mass of a Neutron*/
#define m_n 1.67492749804e-27
/*Avagadro's Number*/
#define avogadro 6.02214076e+23
/*Standard for gravity*/
/*~9.8m/s/s*/
#define std_grav 9.80665

#endif /*__CONSTANTS__*/