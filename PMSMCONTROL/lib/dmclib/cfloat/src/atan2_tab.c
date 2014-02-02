/*=====================================================================================
 File name:        ATAN2_TAB.C                   
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Computation of atan2 based on look-up atan table                
               
               Note that angle = atan2(y/x) in pu (1 pu = 360 degree)
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "atan2_tab.h"

extern float atan_tab[];

void atan2_tab_calc(ATAN2TAB *v)
{	
     float y_x;
     
     y_x = v->y/v->x;
     if ((y_x < 0)&(y_x >= -1))
      {
         y_x = -y_x;
         v->ang = atan_tab[(int)(y_x*256)];
      }
     else if ((y_x < 0)&(y_x < -1))
      {
         y_x = -1/y_x;
         v->ang = 0.25 - atan_tab[(int)(y_x*256)];
      }
     else if ((y_x > 0)&(y_x > 1))
      {
         y_x = 1/y_x;
         v->ang = 0.25 - atan_tab[(int)(y_x*256)];
      }
     else if ((y_x > 0)&(y_x <= 1))        
      {
         v->ang = atan_tab[(int)(y_x*256)];
      }
     
     if ((v->x<0)&(v->y>=0))              /* Second-quadrant */
       v->ang = 0.5 - v->ang;
     else if ((v->x<0)&(v->y<0))          /* Third-quadrant */
       v->ang = 0.5 + v->ang;
     else if ((v->x>=0)&(v->y<0))         /* Fourth-quadrant */
       v->ang = 1 - v->ang;
}


