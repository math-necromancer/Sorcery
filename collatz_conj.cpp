#include <iostream>
#include <iomanip>
#include "math/number_classifications.hpp"
#include "math/constants.hpp"

int main()
{
     std::cout << "Starting...\n";
     double _x = inf();
     int is_inf_;
     for(int i = 0; i <= 70000000
                         /*70,000,000*/; i++)
     {
          is_inf_ = is_inf(_x);
     }
}