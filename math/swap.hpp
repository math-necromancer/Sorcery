/*The Math Necromancer*/

#ifndef __SWAP__
#define __SWAP__

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

#endif /* __SWAP__ */