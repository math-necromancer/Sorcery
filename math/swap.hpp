/*The Math Necromancer*/

#ifndef _NECROMANCER_SWAP_
#define _NECROMANCER_SWAP_

namespace necromancer_swap
{
     /*12/20/2023*/
     /*Swap the values of 2 numbers _x and _y*/
     template<typename _swap_ty>
     void swap(_swap_ty& _x, _swap_ty& _y)
     {
          _swap_ty _tmp;
          _tmp = _x;
          _x = _y;
          _y = _tmp;
     }
}

#endif /* _NECROMANCER_SWAP_ */