/*The Math Necromancer*/

#ifndef _NECROMANCER_VARIADIC_
#define _NECROMANCER_VARIADIC_

#include "minmax.hpp"

/*** Variable argument functions ***/

/*12/28/2023*/
#define _num_args(_type, ...)           \
     (sizeof((_type[]){0, ##__VA_ARGS__}) / sizeof(_type) - 1)
/*12/28/2023*/
/*Specialized array for max(_type, ...)*/
#define _max_arg_array(_type, ...)      \
     ((_type[]){sorcery::numeric_limits<_type>::min(), ##__VA_ARGS__})
/*12/28/2023*/
/*Specialized array for min(_type, ...)*/
#define _min_arg_array(_type, ...)      \
     ((_type[]){sorcery::numeric_limits<_type>::max(), ##__VA_ARGS__})
namespace necromancer_variadic
{
     using namespace necromancer_min_max;
     /*12/28/2023*/
     /*Return the number of arguments passed into this function*/
     /*Might be useful???*/
     template<typename _arg_ty = double, typename... _args>
     constexpr unsigned long num_args(_args... _arg)
     {
          return _num_args(_arg_ty, _arg...);
     }
     /*12/28/2023*/
     /*Return the maximum value given a variable number of inputs*/
     template<typename _arg_ty = double, typename... _args>
     constexpr _arg_ty max(_args... _arg)
     {
          return arr_max<_arg_ty>(_max_arg_array(_arg_ty, _arg...));
     }
     /*12/28/2023*/
     /*Return the minimum value given a variable number of inputs*/
     template<typename _arg_ty = double, typename... _args>
     constexpr _arg_ty min(_args... _arg)
     {
          return arr_min<_arg_ty>(_min_arg_array(_arg_ty, _arg...));
     }
}

#endif /*_NECROMANCER_VARIADIC_*/