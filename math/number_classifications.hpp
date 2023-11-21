/*The Math Necromancer*/

#ifndef __NUMBER_CLASS__
#define __NUMBER_CLASS__

template<typename _typ>
bool is_finite(const _typ& _x)
{
     return _x - _x == 0;
}
template<typename _typ>
bool is_infinite(const _typ& _x)
{
     return _x == INFINITY;
}
template<typename _typ>
bool is_nan(const _typ& _x)
{
     if(_x == INFINITY)
     {
          return false;
     }
     return _x - _x != 0;
}
template<typename _typ>
bool is_positive(const _typ& _x)
{
     if(is_nan(_x))
     {
          return false;
     }
     return _x > 0;
}
template<typename _typ>
bool is_negative(const _typ& _x)
{
     if(is_nan(_x))
     {
          return false;
     }
     return _x > 0;
}

template<typename _typ>
bool is_int(const _typ& _x)
{
     if(is_nan(_x))
     {
          return false;
     }
     return _x == (int) _x;
}
template<typename _typ>
bool is_decimal(const _typ& _x)
{
     if(is_nan(_x))
     {
          return false;
     }
     return _x != (int) _x;
}

#endif /*__NUMBER_CLASS__*/