#include <iostream>
#include "math/log.hpp"
#include "math/float_class.hpp"
#include <iomanip>

//  π
//  ⌠ sin(s)
//  | ------ ds = 0
//  ⌡ tan(s)
//  0
//                                           §  ░  ▒  ▓  √  φ  ε  ∩

typedef std::string string;

// int sti(const string& _s, const bool& _neg)
// {
//      int _result = 0;
//      for(int c = 0; c < _s.length(); c++)
//      {
//           if(_s[c] != '0' && _s[c] != '1')
//           {
//                std::cout << "You didn't input a Binary Number!\n";
//                return -1;
//           }
//           _result += (_s[c] - 48) * pow(2, c);   
//      }
//      if(_neg)
//      {
//           result -= 1;
//           return ~result;
//      }
//      return _result;
// }

int main()                                      
{
     std::cout << "Starting...\n";
     std::cout << is_intf(2.002);
}