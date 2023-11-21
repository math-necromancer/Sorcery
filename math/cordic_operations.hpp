/*The Math Necromancer*/

#ifndef __CORDIC_OPERATIONS__
#define __CORDIC_OPERATIONS__

#include "constants.hpp"
#include "rem.hpp"

namespace necromancer_cordic_operations
{
     template<typename _CRDC>
     class cordic_result;

     typedef long double lngdbl_tp;

     const lngdbl_tp atan_table[] =
     {
          0.78539816339744830962, 0.46364760900080611621,
          0.24497866312686415417, 0.12435499454676143503, 0.062418809995957348474,
          0.031239833430268276254, 0.015623728620476830803, 0.0078123410601011112965,
          0.0039062301319669718276, 0.0019531225164788186851, 0.0009765621895593194304,
          0.00048828121119489827547, 0.00024414062014936176402, 0.00012207031189367020424,
          0.000061035156174208775022, 0.000030517578115526096862, 0.000015258789061315762107,
          0.0000076293945311019702634, 0.0000038146972656064962829, 0.0000019073486328101870354,
          0.00000095367431640596087942
     };
     int atan_table_len = sizeof(atan_table) / sizeof(atan_table[0]);

     const lngdbl_tp cordic_K = 0.6072529350088812561694;

     template<typename _CRDC = lngdbl_tp>
     class cordic_result
     {
          private:
               _CRDC _x, _y, _angle;
          public:
               _CRDC x()
               {
                    return _x;
               }
               void x(_CRDC _x_val)
               {
                    _x = _x_val;
               }

               _CRDC y()
               {
                    return _y;
               }
               void y(_CRDC _y_val)
               {
                    _y = _y_val;
               }

               _CRDC angle()
               {
                    return _angle;
               }
               void angle(_CRDC _ang_val)
               {
                    _angle = _ang_val;
               }

               cordic_result()
                    : _x(0), _y(0), _angle(0)
               {}
               cordic_result(_CRDC _x_val, _CRDC _y_val, _CRDC _a_val)
                    : _x(_x_val), _y(_y_val), _angle(_a_val)
               {}
     };
     template<typename _CRDC = lngdbl_tp>
     _CRDC reduce_angle(const _CRDC& _theta)
     {
          _CRDC _theta1 = _theta;
          _theta1 = necromancer_rem::rem(_theta1, tau);
          if(_theta1 < -pi)
          {
               _theta1 += tau;
          }
          else if(_theta1 > pi)
          {
               _theta1 -= tau;
          }
          return _theta1;
     }
     template<typename _CRDC = lngdbl_tp>
     cordic_result<_CRDC> cordic_vec_euclid(const _CRDC& _x, const _CRDC& _y, const _CRDC& _theta)
     {
          _CRDC x_new = _x;
          _CRDC y_new = _y;
          _CRDC __x = _x;
          _CRDC __y = _y;
          _CRDC _ang = 0;
          _CRDC exp_2 = 1;
          int _delta = 1;
          _CRDC y_exp_2, x_exp_2;
          for(int i = 0; i < atan_table_len; i++)
          {
               y_exp_2 = (__y / exp_2);
               x_exp_2 = (__x / exp_2);
               _delta = (__y >= 0)? 1: -1;
               x_new += _delta * (y_exp_2);
               y_new -= _delta * (x_exp_2);
               _ang += _delta * atan_table[i];

               __x = x_new;
               __y = y_new;
               exp_2 *= 2;
          }
          return cordic_result<_CRDC>(__x, __y, _ang);
     }
     template<typename _CRDC = lngdbl_tp>
     cordic_result<_CRDC> cordic_angle_euclid(const _CRDC& _x, const _CRDC& _y, const _CRDC& _theta)
     {
          _CRDC _theta1 = reduce_angle(_theta);
          int mult = 1;
          if(_theta1 > pi_2)
          {
               _theta1 -= pi;
               mult = -1;
          }
          else if(_theta1 < -pi_2)
          {
               _theta1 += pi;
               mult = -1;
          }
          _CRDC x_new = _x;
          _CRDC y_new = _y;
          _CRDC __x = x_new;
          _CRDC __y = y_new;
          _CRDC _ang = 0;
          _CRDC exp_2 = 1;
          int _delta = 1;
          _CRDC y_exp_2, x_exp_2;
          for(int i = 0; i < atan_table_len; i++)
          {
               y_exp_2 = (__y / exp_2);
               x_exp_2 = (__x / exp_2);
               _delta = (_ang <= _theta1)? 1: -1;
               x_new -= _delta * (y_exp_2);
               y_new += _delta * (x_exp_2);
               _ang += _delta * atan_table[i];

               __x = x_new;
               __y = y_new;
               exp_2 *= 2;
          }
          __x *= mult;
          __y *= mult;
          return cordic_result<_CRDC>(__x, __y, _ang);
     }
}
#endif /*__CORDIC_OPERATIONS__*/