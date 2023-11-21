#include <iostream>
#include <iomanip>
#include "math/constants.hpp"
#include "math/complex.hpp"

using namespace necromancer_complex;

int main()
{
     complex e_r = exp(complex(0.0, 0.0));
     std::cout << e_r.real() << " + " << e_r.img() << "i\n";
}