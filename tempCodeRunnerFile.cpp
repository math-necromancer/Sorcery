#include "math/cordic.hpp"
#include "math/complex.hpp"
#include <iostream>
#include <iomanip>

using namespace necromancer_complex;

int main()
{
    complex x(5, 12);
    complex y(7, 7);
    complex z = x + y;
    std::cout << z.real() << " + " << z.img() << "i\n";
}