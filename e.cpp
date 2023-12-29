#include <iostream>
#include <iomanip>
#include "sorcery/array/array.hpp"
#include <chrono>
#include "algorithm"

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
    std::cout << "Starting...\n";
    std::cout << std::setprecision(16) << 2.07 << '\n';
}