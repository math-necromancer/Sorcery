/*The Math Necromancer*/

#ifndef _NECROMANCER_MIN_MAX_
#define _NECROMANCER_MIN_MAX_

namespace necromancer_min_max
{
     /*** max ***/

     /*12/28/2023*/
     /*Return the maximum value between _x and _y*/
     template<typename _max_ty>
     constexpr _max_ty max(const _max_ty& _x, const _max_ty& _y)
     {
          return _x > _y? _x: _y;
     }
     /*** min ***/

     /*12/28/2023*/
     /*Return the minimum value between _x and _y*/
     template<typename _min_ty>
     constexpr _min_ty min(const _min_ty& _x, const _min_ty& _y)
     {
          return _x > _y? _y: _x;
     }
     /*** Array functions ***/

     /*12/28/2023*/
     /*Return the maximum value of an array*/
     template<typename _arr_ty, int _arr_size>
     constexpr _arr_ty arr_max(const _arr_ty (&_arr)[_arr_size])
     {
          _arr_ty _r = static_cast<_arr_ty>(0);
          for(int _i = 0; _i < _arr_size; _i ++)
          {
               _r = max<_arr_ty>(_r, _arr[_i]);
          }
          return _r;
     }
     /*12/28/2023*/
     /*Return the minimum value of a array*/
     template<typename _arr_ty, int _arr_size>
     constexpr _arr_ty arr_min(const _arr_ty (&_arr)[_arr_size])
     {
          _arr_ty _r = static_cast<_arr_ty>(0);
          for(int _i = 0; _i < _arr_size; _i ++)
          {
               _r = min<_arr_ty>(_r, _arr[_i]);
          }
          return _r;
     }
}

#endif /*_NECRIMANCER_MIN_MAX_*/