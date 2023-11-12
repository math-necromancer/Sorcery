#include "math/fractions.hpp"
#include "math/constants.hpp"
#include <iostream>
#include <iomanip>

using namespace necromancer_fractions;

int main()
{
    mixed _x(7, fraction(6, 9));
    _x /= mixed(3, fraction(17, 2));

    std::cout << "Result: " << _x.integer() << " + " << _x.fractional().numerator() << " / " << _x.fractional().denominator() << '\n';
    
    return 0;  // Add a return statement to keep the console window open
}
