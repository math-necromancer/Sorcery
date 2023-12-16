/*The Math Necromancer*/

#ifndef _NECROMANCER_ROOTS_
#define _NECROMANCER_ROOTS_

#include "abs.hpp"
#include "constants.hpp"
#include "exponent_int.hpp"
#include "exp.hpp"
#include "float_class.hpp"

namespace root
{
    float _sqrtf(const float& _x)
    {
        using namespace necromancer_float_class;
        float_32 _i;
        _i._x = _x;
        int _k = ((_i._f_32._exp - 0x07f) >> 1) + 0x07f;
        float _f, _r;
        _i._f_32._exp = 0x07f;
        _f = _i._x;
        _r = 0.625f + (0.39f * _f);
        _r = 0.5f * (_r + (_f / _r));
        _r = 0.5f * (_r + (_f / _r));
        _r = 0.5f * (_r + (_f / _r));
        _r = 0.5f * (_r + (_f / _r));
        _r = 0.5f * (_r + (_f / _r));
        _r = 0.5f * (_r + (_f / _r));
        return _r;
    }

    float sqrtf(const float& _x)
    {
        /*Roots of Negatives are Complex*/
        if(_x < 0)
        {
            return undefined;
        }
        else if(_x == e)
        {
            return necromancer_exp::exp(0.5f);
        }
        /*These are all their own Square Roots*/
        else if(_x == 0 || _x == 1 || _x == INFINITY || _x == NaN || _x == undefined)
        {
            return _x;
        }
        float _root = _x > 1? _x / 2: _x;
        float _prev_root = 0.0f;
        /*EPSILON represents the tolarance of the root approximation*/
        const float EPSILON = 1e-8f;
        /*Iterative Babylonian method*/
        for(int i = 0; i < 200 /*Arbitrarily high number of iterations*/; i++)
        {
            _prev_root = _root;
            _root = (_root + (_x / _root)) / 2;
            /*If the root is precise enough, break out of the loop*/
            if(absolute::abs(_root - _prev_root) < EPSILON)
            {
                break;
            }
        }
        return _root;
    }
    double sqrtd(const double& _x)
    {
        if(_x < 0)
        {
            return undefined;
        }
        else if(_x == e)
        {
            return necromancer_exp::exp(0.5);
        }
        else if(_x == 0 || _x == 1 || _x == INFINITY || _x == NaN || _x == undefined)
        {
            return _x;
        }
        double _root = _x > 1? _x / 2: _x;
        double _prev_root = 0.0;
        /*EPSILON represents the tolarance of the root approximation*/
        const double EPSILON = 1e-8;
        /*Iterative Babylonian method*/
        for(int i = 0; i < 200 /*Arbitrarily high number of iterations*/; i++)
        {
            _prev_root = _root;
            _root = (_root + (_x / _root)) / 2;
            /*If the root is precise enough, break out of the loop*/
            if(absolute::abs(_root - _prev_root) < EPSILON)
            {
                break;
            }
        }
        return _root;
    }
    long double sqrtl(const long double& _x)
    {
        if(_x < 0)
        {
            return undefined;
        }
        else if(_x == e)
        {
            return necromancer_exp::exp(0.5l);
        }
        else if(_x == 0 || _x == 1 || _x == INFINITY || _x == NaN || _x == undefined)
        {
            return _x;
        }
        long double _root = _x > 1? _x / 2: _x;
        long double _prev_root = 0.0f;
        /*EPSILON represents the tolarance of the root approximation*/
        const long double EPSILON = 1e-18;
        /*Iterative Babylonian method*/
        for(int i = 0; i < 200 /*Arbitrarily high number of iterations*/; i++)
        {
            _prev_root = _root;
            _root = (_root + (_x / _root)) / 2;
            /*If the root is precise enough, break out of the loop*/
            if(absolute::abs(_root - _prev_root) < EPSILON)
            {
                break;
            }
        }
        return _root;
    }
    float sqrt(const float& _x)
    {
        return sqrtf(_x);
    }
    double sqrt(const double& _x)
    {
        return sqrtd(_x);
    }
    long double sqrt(const long double& _x)
    {
        return sqrtl(_x);
    }
    template<typename _S>
    double sqrt(const _S& _x)
    {
        return sqrtd((double) _x);
    }

    double cbrt(double x)
    {
        int negative_mult = 1;
        /*Unlike square roots, cube roots of negatives are defiend*/
        /*It's just the negative of their positive counterpart*/
        negative_mult = x < 0? -1: 1;
        x = absolute::abs(x);
        /*These are all their Cube Roots*/
        if(x == 0 || x == 1 || x == INFINITY || x == NaN || x == undefined)
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
        return root * negative_mult;
    }

    double intRoot(double x, int y)
    {
        switch (y)
        {
        case 1: return x;
            break;
        case 2: return sqrtf(x);
            break;
        case 3: return cbrt(x);
            break;
        default:
            break;
        }
        if(x < 0 || !(y & 1) == 0)
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

#endif /*_NECROMANCER_ROOTS_*/