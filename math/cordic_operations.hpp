/*The Math Necromancer*/

/*============ C++ CORDIC Algorithm Implementation ============*/
/*Calculate Trigonometric and other Transcendental functions with*/
/*ease using this small file*/

#ifndef __CORDIC_OPERATIONS__
#define __CORDIC_OPERATIONS__

#include "constants.hpp"
#include "rem.hpp"
#include "abs.hpp"

namespace necromancer_cordic_operations
{
     template<typename _CRDC>
     class cordic_result;

     typedef long double lngdbl_tp;

     #define ATAN_LENGTH 61
     /*Arctangent values of reciprocals of powers of 2*/
     /*Measured in Radians*/
     const lngdbl_tp atan_table[ATAN_LENGTH] =
     {
          /*atan(1)*/
          7.8539816339744830962e-01,
          4.6364760900080611621e-01,
          2.4497866312686415417e-01,
          1.2435499454676143503e-01,
          6.2418809995957348474e-02,
          3.1239833430268276254e-02,
          1.5623728620476830803e-02,
          7.8123410601011112965e-03,
          3.9062301319669718276e-03,
          1.9531225164788186851e-03,
          9.7656218955931943042e-04,
          4.8828121119489827547e-04,
          2.4414062014936176402e-04,
          1.2207031189367020424e-04,
          6.1035156174208775022e-05,
          3.0517578115526096862e-05,
          1.5258789061315762107e-05,
          7.6293945311019702634e-06,
          3.8146972656064962829e-06,
          1.9073486328101870354e-06,
          9.5367431640596087942e-07,
          4.7683715820308885993e-07,
          2.3841857910155798249e-07,
          1.1920928955078068531e-07,
          5.9604644775390554414e-08,
          2.9802322387695303677e-08,
          1.4901161193847655147e-08,
          7.4505805969238279871e-09,
          3.7252902984619140453e-09,
          1.8626451492309570291e-09,
          9.3132257461547851536e-10,
          4.6566128730773925778e-10,
          2.3283064365386962890e-10, 
          1.1641532182693481445e-10, 
          5.8207660913467407226e-11, 
          2.9103830456733703613e-11, 
          1.4551915228366851807e-11, 
          7.2759576141834259033e-12, 
          3.6379788070917129517e-12, 
          1.8189894035458564758e-12, 
          9.0949470177292823792e-13, 
          4.5474735088646411896e-13, 
          2.2737367544323205948e-13, 
          1.1368683772161602974e-13, 
          5.6843418860808014870e-14, 
          2.8421709430404007435e-14, 
          1.4210854715202003717e-14, 
          7.1054273576010018587e-15, 
          3.5527136788005009294e-15, 
          1.7763568394002504647e-15, 
          8.8817841970012523234e-16, 
          4.4408920985006261617e-16, 
          2.2204460492503130808e-16, 
          1.1102230246251565404e-16, 
          5.5511151231257827021e-17, 
          2.7755575615628913511e-17, 
          1.3877787807814456755e-17, 
          6.9388939039072283776e-18, 
          3.4694469519536141888e-18, 
          1.7347234759768070944e-18,
          8.6736173798840354720e-19
     };
     #define ATANH_LENGTH 61
     /*Inverse Hyperbolic Tangent values of*/
     /*reciprocals of powers of 2*/
     /*Measured in Radians*/
     const lngdbl_tp atanh_table[ATANH_LENGTH] =
     {
          /*atanh(x) table starts at an x of 1/2,*/
          /*because atanh(1) = INFINITY...*/
          5.4930614433405484569e-01,
          2.5541281188299534160e-01,
          1.2565721414045303884e-01,
          6.2581571477003007126e-02,
          3.1260178490666994764e-02,
          1.5626271752052211379e-02,
          7.8126589515404209103e-03,
          3.9062698683968260531e-03,
          1.9531274835325499986e-03,
          9.7656281044103584096e-04,
          4.8828128880511282676e-04,
          2.4414062985063858292e-04,
          1.2207031310632980660e-04,
          6.1035156325791225317e-05,
          3.0517578134473903148e-05,
          1.5258789063684237893e-05,
          7.6293945313980297366e-06,
          3.8146972656435037170e-06,
          1.9073486328148129646e-06,
          9.5367431640653912057e-07,
          4.7683715820316114007e-07,
          2.3841857910156701750e-07,
          1.1920928955078181468e-07,
          5.9604644775390695586e-08,
          2.9802322387695321323e-08,
          1.4901161193847657352e-08,
          7.4505805969238282628e-09,
          3.7252902984619140797e-09,
          1.8626451492309570334e-09,
          9.3132257461547851589e-10,
          4.6566128730773925784e-10,
          2.3283064365386962891e-10,
          1.1641532182693481445e-10,
          5.8207660913467407226e-11,
          2.9103830456733703613e-11,
          1.4551915228366851806e-11,
          7.2759576141834259033e-12,
          3.6379788070917129516e-12,
          1.8189894035458564758e-12,
          9.0949470177292823791e-13,
          4.5474735088646411895e-13,
          2.2737367544323205947e-13,
          1.1368683772161602973e-13,
          5.6843418860808014869e-14,
          2.8421709430404007434e-14,
          1.4210854715202003717e-14,
          7.1054273576010018587e-15,
          3.5527136788005009293e-15,
          1.7763568394002504646e-15,
          8.8817841970012523233e-16,
          4.4408920985006261616e-16,
          2.2204460492503130808e-16,
          1.1102230246251565404e-16,
          5.5511151231257827021e-17,
          2.7755575615628913510e-17,
          1.3877787807814456755e-17,
          6.9388939039072283776e-18,
          3.4694469519536141888e-18,
          1.7347234759768070944e-18,
          8.6736173798840354720e-19,
          4.3368086899420177360e-19
     };

     const lngdbl_tp cordic_K = 6.0725293500888125616e-01;
     //const lngdbl_tp cordic_K_h = 

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
     /*CORDIC Vectoring mode*/
     cordic_result<_CRDC> cordic_vec_euclid(const _CRDC& _x, const _CRDC& _y, const _CRDC& _theta)
     {
          _CRDC __x = absolute::abs(_x);
          _CRDC __y = absolute::abs(_y);
          int mult = 1;
          if(_x < 0 ^ _y < 0)
          {
               mult = -1;
          }
          
          _CRDC x_1 = __x;
          _CRDC x_2 = __x;
          _CRDC y_1 = __y;
          _CRDC y_2 = __y;
          _CRDC _ang = 0;
          _CRDC exp_2 = 1;
          int _delta = 1;
          _CRDC y_exp_2, x_exp_2;
          for(int i = 0; i < ATAN_LENGTH; i++)
          {
               y_exp_2 = (y_2 / exp_2);
               x_exp_2 = (x_2 / exp_2);
               _delta = (y_2 >= 0)? 1: -1;
               x_1 += _delta * (y_exp_2);
               y_1 -= _delta * (x_exp_2);
               _ang += _delta * atan_table[i];

               x_2 = x_1;
               y_2 = y_1;
               exp_2 *= 2;
          }
          return cordic_result<_CRDC>(x_2, y_2, _ang * mult);
     }
     template<typename _CRDC = lngdbl_tp>
     cordic_result<_CRDC> cordic_vec_hyperbolic(const _CRDC& _x, const _CRDC& _y, const _CRDC& _theta)
     {
          //later...
     }

     template<typename _CRDC = lngdbl_tp>
     /*CORDIC Rotation mode*/
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
          for(int i = 0; i < ATAN_LENGTH; i++)
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