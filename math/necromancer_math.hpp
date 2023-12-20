/*The Math Necromancer*/

#ifndef _NECROMANCER_MATH_
#define _NECROMANCER_MATH_

/*Sometimes, it's necessary to catch other math libraries, but these detect <cmath> and <math.h>*/
/*At least, they do on my compiler :)*/

/*Throw a warning if not using <cmath> or <math.h>*/
#if !defined(_GLIBCXX_CMATH) && !defined(_GLIBCXX_MATH_H) && !defined(_MATH_H_)
     #ifndef _NECROMANCER_SKIP_MATH_WARN_
          #warning "Remember, this isn't sophisticated. Use <cmath> or <math.h> for serious work!"
          /*To disable this warning, `#define _NECROMANCER_SKIP_CMATH_WARN_` before including this file*/
     #endif /*_NECROMANCER_SKIP_MATH_WARN*/
#endif /*!defined(_GLIBCXX_CMATH) && !defined(_GLIBCXX_MATH_H)*/
/*Throw an error if the standard math libraries are included, it will cause conflict*/
/*To detect another library, #define _FORBIDDEN_MATH_ as the #define of said library*/
#if (defined(_GLIBCXX_CMATH) || defined(_GLIBCXX_MATH_H) || defined(_MATH_H_) || defined(_FORBIDDEN_MATH_)) && defined(_NECROMANCER_MATH_)
     #error "Never use this library with <cmath> or other math libraries!"
#endif /*(defined(_GLIBCXX_CMATH) || defined(_GLIBCXX_MATH_H) || defined(_MATH_H_)) && defined(_NECROMANCER_MATH_)*/



#endif /*_NECROMANCER_MATH_*/