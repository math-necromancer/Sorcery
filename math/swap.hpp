/*The Math Necromancer*/

#ifndef _NECROMANCER_SWAP_
#define _NECROMANCER_SWAP_

namespace necromancer_swap
{
     template<typename T>
     void swap(T x, T y)
     {
          T tmp;
          tmp = x;
          x = y;
          y = tmp;
     }
}

#endif /* _NECROMANCER_SWAP__ */