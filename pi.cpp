#include "math/fractions.hpp"
#include <iostream>

using namespace necromancer_fractions;

int main()
{
    fraction _x(2, 3);
    fraction _y(3, 2);
    _x += _y;
    std::cout << _x.numerator() << " / " << _x.denominator() << "\n";
}
/* :D */