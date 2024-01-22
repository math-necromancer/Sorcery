#include <iostream>
#include <iomanip>
#define _MATH_SORCERY_SKIP_MATH_WARN_
#include "sorcery/math/math_sorcery.hpp"
#include "sorcery/math/exp.hpp"

/* Yooo... C++ can control time now?... */

#include <chrono>

//  π
//  ⌠ sin(s)
//  | ------ ds = 0
//  ⌡ tan(s)
//  0                                      §  ░  ▒  ▓  √  φ  ε  ∩

/** EPIC ABSOLUTE VALUE C++ BATTLES OF HISTORY
 * 
 * cmath
 *   GLIBCXX_CONSTEXPR double
 *        abs(double __x)
 *   { return __builtin_abs(__x); }
 * 
 * Joseph
 *   double abs(double _x){
 *        return _x > 0? _x: -_x;
 *   }
 * 
 * David
 *   double abs(const double& _x)
 *   {
 *        if(is_nan(_x))
 *             return NaNf;
 *        float_32 _i;
 *        _i._x = _x;
 *        _i._y &= 0x7fffffff;
 *        return _i._x;
 *   }
*/
/** EPIC COPYSIGN BATTLES OF HISTORY
 * 
 * cmath
 *   GLIBCXX_CONSTEXPR double
 *        copysign(double __x, double __y)
 *   { return __builtin_copysign(__x, __y); }
 * 
 * Joseph
 *   double copysign(double _x, double _y){
 *        return _y > 0? abs(_x): -abs(_x);
 *   }
 * 
 * David
 *   double copysignd(const double& _x, const double& _y)
 *   {
 *        float_64 _ix, _iy;
 *        _ix._x = _x;
 *        _iy._x = _y;
 *        _ix._y = (_ix._y & 0x7fffffffffffffff) | (_iy._y & 0x8000000000000000);
 *        return _ix._x;
 *   }
*/

int main()
{
    std::cout << "Starting..." << '\n';
    std::chrono::time_point<std::chrono::high_resolution_clock> _start, _end;
    _start = std::chrono::high_resolution_clock::now();

    double _s;
    int _e = 0;

    //death

    //double squares[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};

    //for(int _c = 0; _c <= 70000000; _c++ /* C++ :) */)
        _s = sorcery::ldexp(1., -3);
    
    _end = std::chrono::high_resolution_clock::now();
    std::cout << std::setprecision(16) << _s << '\n';
    std::chrono::duration<double> elapsed_seconds = _end - _start;
    std::cout << std::setprecision(16) << "That computation took " << elapsed_seconds.count() << " seconds!\n";
    // std::cout <<
}