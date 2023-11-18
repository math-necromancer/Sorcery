/*The Math Necromacner*/

#ifndef __CORDIC_OPERATIONS__
#define __CORDIC_OPERATIONS__

#include "constants.hpp"
#include "rem.hpp"

namespace necromancer_cordic_operations
{
     /*Arctangent values in radians of reciprocals of powers of 2*/
     const long double arctan_table[] =
     {
         0.78539816339744830962, 0.46364760900080611621,
         0.24497866312686415417, 0.12435499454676143503, 0.062418809995957348474,
         0.031239833430268276254, 0.015623728620476830803, 0.0078123410601011112965,
         0.0039062301319669718276, 0.0019531225164788186851, 0.0009765621895593194304,
         0.00048828121119489827547, 0.00024414062014936176402, 0.00012207031189367020424,
         0.000061035156174208775022, 0.000030517578115526096862, 0.000015258789061315762107,
         0.0000076293945311019702634, 0.0000038146972656064962829, 0.0000019073486328101870354
     };

     /*Get the amount of values in the arctangent table*/
     int arctan_table_length = sizeof(arctan_table) / sizeof(arctan_table[0]);

     /*CORDIC gain*/
     /*Scale Factor for the Infinite Product of the Cosine of the CORDIC Rotation Matrix*/
     const long double cordic_K = 0.6072529350088812561694;

     /*CORDIC gain for Hyperbolic Trig*/
     const long double cordic_Kh = 1.20513635844646;

     /*Class for return values, resembles a vector*/
     /*Contains x, y, and the angle*/
     class cordic_result
     {
          public:
               long double x, y, angle;

               /*If values are not specified, default to 0*/
               cordic_result()
                   : x(0.0), y(0.0), angle(0.0)
               {}
               /*Constructor for specific initialization of vales*/
               cordic_result(long double _x, long double _y, long double _angle)
                    : x(_x), y(_y), angle(_angle)
               {}
     };

     class cordic_result_polar
     {
          public:
               long double r, theta;
               /*If values are not specified, default to 0*/
               cordic_result_polar()
                    : r(0.0), theta(0.0)
               {}
               cordic_result_polar(double _r, double _theta)
                    : r(_r), theta(_theta)
               {}
     };
     
     double reduce_angle(double theta)
     {
          theta = necromancer_rem::rem(theta, tau);
          if(theta < -pi)
          {
              theta += tau;
          }
          else if(theta > pi)
          {
              theta -= tau;
          }
          return theta;
     }

     /*Method Used to Compare Vectors and Determine Angles*/
     cordic_result cordic_vector(double x, double y, double theta)
     {
          double x_new = x;
          double y_new = y;
          double exp_2 = 1.0;
          double angle = 0.0;
          for(int i = 1; i < arctan_table_length; i++)
          {
               double delta = (y >= 0.0)? 1.0: -1.0;
               x_new += delta * (y / exp_2);
               y_new -= delta * (x / exp_2);
               angle += delta * arctan_table[i - 1];

               x = x_new;
               y = y_new;
               exp_2 *= 2;
          }
          /*Defines the return values. The angle variable is the arctangent*/
          cordic_result return_val(x, y, angle);
          return return_val;
     }

     /*Method Used to Compare Angles and Determine Vectors*/
     cordic_result cordic_angle(double x, double y, double theta)
     {
          theta = reduce_angle(theta);
          double multiplier = 1.0;
          if(theta > pi_2)
          {
              theta -= pi;
              multiplier = -1.0;
          }
          else if(theta < -pi_2)
          {
              theta += pi;
              multiplier = -1.0;
          }
          double x_new = x;
          double y_new = y;
          double exp_2 = 1.0;
          double angle = 0.0;
          for(int i = 0; i < arctan_table_length; i++)
          {
              double delta = (angle <= theta)? 1.0: -1.0;
              x_new -= delta * (y / exp_2);
              y_new += delta * (x / exp_2);
              angle += delta * arctan_table[i];
              x = x_new;
              y = y_new;
              exp_2 *= 2;
          }
          cordic_result return_val(x * multiplier, y * multiplier, angle);
          return return_val;
     }
}

#endif /*__CORDIC_OPERATIONS__*/