/*The Math Necromancer*/

#ifndef __FACTORIAL__
#define __FACTORIAL__

#include "constants.hpp"

namespace factorial
{
    /*Get the Factorial of any number*/
    /*Decimals will truncate*/
    template <typename T>
    long long factorial(T x)
    {
        /*Negative Factorials require the Gamma Function*/
        if(x < 0)
        {
            /*Even with the Gamma Function, negative integers*/
            /*are Asymptotic*/
            return undefined;
        }
        long long factorial = 1;
        for(int i = 2; i <= x /*If x isn't an integer, it doesn't matter*/; i++)
        {
            factorial *= i;
        }
        return factorial;
    }
}

#endif /*__FACTORIAL__*/