/*The Math Necromancer*/

#ifndef __FACTORIAL__
#define __FACTORIAL__

#include "constants.hpp"

namespace factorial
{
    /*Get the Factorial of any number*/
    /*Decimals will truncate*/
    long long factorial(int x)
    {
        /*Negative Factorials require the Gamma Function*/
        if(x < 0)
        {
            /*Even with the Gamma Function, negative integers*/
            /*are Asymptotic*/
            return undefined;
        }
        long long factorial = 1;
        /*Start i at 2 because all previous factorials are 1*/
        for(int i = 2; i <= x; i++)
        {
            factorial *= i;
        }
        return factorial;
    }
}

#endif /*__FACTORIAL__*/