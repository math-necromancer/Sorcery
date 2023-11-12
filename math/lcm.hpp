/*The Math Necromancer*/

#ifndef __LCM__
#define __LCM__

namespace necromancer_lcm
{
     int lcm(const int& _x, const int& _y)
     {
          int _prod = _x * _y;
          return _prod / necromancer_gcf::gcf(_x, _y);
     }
}

#endif /*__LCM___*/