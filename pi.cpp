#include "math/fractions.hpp"
#include "math/constants.hpp"
#include <iostream>
#include <iomanip>

using namespace necromancer_fractions;

int main()
{
    fraction x(69, 9);
    mixed _x = mix(x);
    std::cout << _x.integer() << " + " << _x.frac().numerator() << " / " << _x.frac().denominator() << '\n';
}