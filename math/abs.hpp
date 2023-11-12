/*The Math Necromancer*/

#ifndef __ABS__
#define __ABS__

namespace absolute
{
    template <typename T>
    T abs(T _x)
    {
        return x < 0? -_x: _x;
    }
}

#endif /*__ABS__*/