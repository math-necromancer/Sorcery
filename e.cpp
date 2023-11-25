#include <iostream>
#include <iomanip>
#include "math/cordic.hpp"

using namespace necromancer_cordic_functions;

int main()
{
     double r = cordic_arccos(-0.7);
     std::cout << std::setprecision(16) << r;
}