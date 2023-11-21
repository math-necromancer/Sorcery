#include <iostream>
#include <iomanip>
#include "math/constants.hpp"
#include "math/complex.hpp"
#include "math/cordic.hpp"
#include "math/euclid_trig.hpp"

using namespace necromancer_complex;
using namespace cordic;

int main()
{
     std::cout << std::setprecision(16) << euclid_trig::cos(0.02);
}