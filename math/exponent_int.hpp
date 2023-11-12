/*The Math Necromancer*/

#ifndef __EXPONENT__
#define __EXPONENT__

#include "constants.hpp"

double exponentInteger(double x, int exp)
{
    if(exp == 0)
    {
        if(x == 0.0)
        {
            return undefined;
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
        exp /= 2;
    }
    return result;
}

#endif /*__EXPONENT__*/