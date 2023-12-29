/*The Math Necromancer*/

#ifndef _NECROMANCER_ARRAY_
#define _NECROMANCER_ARRAY_

#include "../math/variadic.hpp"

/*Since there is a 0 in front of it, we must alter array[i] to be array[i ++]*/
#define _arg_array(_type, ...)          \
     ((_type[]){static_cast<_type>(0), ##__VA_ARGS__})

namespace necromancer_array
{
     using namespace necromancer_variadic;

     typedef unsigned int _array_index;
     typedef unsigned int _array_size;

     template<typename _arr_ty>
          #define _array_pointer(_type) _type*
     class array
     {
          private:
               _array_pointer(_arr_ty) _array_elements;
               _array_size _arr_size;
          public:
               _arr_ty operator [] (const _array_index& _index);
               array<_arr_ty> operator = (const array<_arr_ty> _array);
               template<typename _arr_size>
               array<_arr_ty> operator = (const _array_ty (&_array)[_arr_size]);
               array()
                    : _array_elements(static_cast<_arr_ty>(0)), _arr_size(1)
               {}
               template<typename... _elements>
               array(_elements... _e)
                    : _array_elements(_arg_array(_arr_ty, _e...)), _arr_size(num_args(_e...))
               {}
     };
     template<typename _arr_ty>
     _arr_ty array<_arr_ty>::operator [] (const _array_index& _index)
     {
          /*We must increment _index, due to the 0 inserted in the second constructor*/
          return _array_elements[_index ++];
     }
     template<typename _arr_ty>
     array<_arr_ty> array<_arr_ty>::operator = (const array<_arr_ty> _array)
     {
          _array_elements = _array._array_elements;
          _array_size = _array._arr_size;
          return *this;
     }
}

#endif /*_NECROMANCER_ARRAY_*/