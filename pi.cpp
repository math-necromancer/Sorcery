#include "math/complex.hpp"
#include <iostream>

using namespace necromancer_complex;

int main()
{
    complex<double> _cz = 1.0;
    std::cout << '(' << _cz.real() << " + " << _cz.img() << "i)\n";
    complex<double> _sqrt_cz = sqrt(_cz);
    std::cout << '(' << _sqrt_cz.real() << " + " << _sqrt_cz.img() << "i)\n";
}
/* :D */