/*The Math Necromancer*/

#ifndef _NECROMANCER_MATH_
#define _NECROMANCER_MATH_

/*Sometimes, it's necessary to catch other math libraries, but these detect <cmath> and <math.h>*/

/*Throw a warning if not using <cmath> or <math.h>*/
#if !defined(_GLIBCXX_CMATH) && !defined(_GLIBCXX_MATH_H) && !defined(_MATH_H_)
     #ifndef _NECROMANCER_SKIP_CMATH_WARN_
          #warning "Remember, this isn't sophisticated. Use <cmath> or <math.h> for serious work!"
          /*To disable this warning, `#define _NECROMANCER_SKIP_CMATH_WARN_` before #include'ing this file*/
     #endif /*_NECROMANCER_SKIP_CMATH_WARN*/
#endif /*!defined(_GLIBCXX_CMATH) && !defined(_GLIBCXX_MATH_H)*/
/*Throw an error if the standard math libraries are included, it will cause conflict*/
#if (defined(_GLIBCXX_CMATH) || defined(_GLIBCXX_MATH_H) || defined(_MATH_H_)) && defined(_NECROMANCER_MATH_)
     #error "Never use this library with <cmath> or <math.h>!"
#endif /*(defined(_GLIBCXX_CMATH) || defined(_GLIBCXX_MATH_H) || defined(_MATH_H_)) && defined(_NECROMANCER_MATH_)*/



#endif /*_NECROMANCER_MATH_*/