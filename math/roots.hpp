/*The Math Necromancer*/

#ifndef __ROOTS__
#define __ROOTS__

#include "abs.hpp"
#include "constants.hpp"
#include "exponent_int.hpp"
#include "rem.hpp"

namespace root
{
    double sqrt(double x)
    {
        /*Roots of Negatives are Complex*/
        if(x < 0)
        {
            return undefined;
        }
        /*These are all their own Square Roots*/
        else if(x == 0 || x == 1 || x == INFINITY || x == NaN || x == undefined)
        {
            return x;
        }
        double root = x > 1? x / 2: x;
        double prev_root = 0.0;
        /*EPSILON represents the tolarance of the root approximation*/
        double EPSILON = 1e-16;
        /*Iterative Babylonian method*/
        for(int i = 0; i < 200 /*Arbitrarily high number of iterations*/; i++)
        {
            prev_root = root;
            root = (root + (x / root)) / 2;
            /*If the root is precise enough, break out of the loop*/
            if(absolute::abs(root - prev_root) < EPSILON)
            {
                break;
            }
        }
        return root;
    }

    double cbrt(double x)
    {
        bool is_negative = false;
        /*Unlike square roots, cube roots of negatives are defiend*/
        /*It's just the negative of their positive counterpart*/
        if(x < 0)
        {
            x *= -1;
            is_negative = true;
        }
        /*These are all their Cube Roots*/
        else if(x == 0 || x == 1 || x == INFINITY || x == NaN || x == undefined)
        {
            return x;
        }
        double root = x > 1? x / 3: x;
        double prev_root = 0.0;
        /*EPSILON represents the tolarance of the root approximation*/
        double EPSILON = 1e-16;
        /*Iterative Babylonian method*/
        for(int i = 0; i < 200 /*Arbitrarily high number of iterations*/; i++)
        {
            prev_root = root;
            root = (2 * root + x / (root * root)) / 3;
            /*If the root is precise enough, break out of the loop*/
            if(absolute::abs(root - prev_root) < EPSILON)
            {
                break;
            }
        }
        /*If the input was negative, negate the result before returning*/
        return is_negative? -root: root; 
    }

    double intRoot(double x, int y)
    {
        switch (y)
        {
        case 1: return x;
            break;
        case 2: return sqrt(x);
            break;
        case 3: return cbrt(x);
            break;
        default:
            break;
        }
        if(x < 0 && necromancer_rem::rem(y, 2) == 0)
        {
            return undefined;
        }
        else if(x == 0 || x == 1 || x == INFINITY || x == NaN || x == undefined)
        {
            return x;
        }
        double root = x > 1? x / y: x;
        double prev_root = 0.0;

        double EPSILON = 1e-16;

        for(int i = 0; i <= 200; i++)
        {
            prev_root = root;
            root = ((y - 1) * root + (x / exponentInteger(root, y - 1))) / y;
            if(absolute::abs(root - prev_root) < EPSILON)
            {
                break;
            }
        }
        return root;
    }
}

#endif /*__ROOTS__*/