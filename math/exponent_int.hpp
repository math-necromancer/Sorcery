/*The Math Necromancer*/

#ifndef _NECROMANCER_EXPONENT_
#define _NECROMANCER_EXPONENT_

#include "float_class.hpp"

double exponentInteger(double x, int exp)
{
    if(exp == 0)
    {
        if(x == 0.0)
        {
            return NaNf;
        }
        return 1;
    }
    if(exp < 0.0)
    {
       return 1 / exponentInteger(x, -exp);
    }
    double result = 1.0;
    while(exp > 0)
    {
        if(exp % 2 == 1)
        {
            result *= x;
        }
        x *= x;
        exp >>= 1;
    }
    return result;
}

#endif /*_NECROMANCER_EXPONENT_*/