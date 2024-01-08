/*The Math Necromancer*/

#ifndef _NECROMANCER_SWAP_
#define _NECROMANCER_SWAP_

#ifndef _MATH_SORCERY_
    #warning Are you sure you want to use this raw file instead of "math_sorcery.hpp"?
#endif /*_MATH_SORCERY_*/

namespace necromancer_swap
{
    /*12/27/2023*/
    template<typename _swap_ty>
    void swap(_swap_ty& _x, _swap_ty& _y)
    {
        /*New swap method that doesn't have a temporary value*/
        _x += _y;
        _y = _x - _y;
        _x -= _y;
    }
}

#endif /* _NECROMANCER_SWAP_ */