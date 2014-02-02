/*=====================================================================================
 File name:        PARK.C                   
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Park Transformation               

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "park.h"

extern float sin_tab[];

void park_calc(PARK *v)
{	
  
    float cos_ang,sin_ang;

/* Using look-up sine table */  
/* (PI/2)/(2*PI) = 0.25 */
/* ((PI/2)/(2*PI))*256 = 0.25*256 = 64 */
/* ((PI/2)-2*PI)/(2*PI) = -0.75 */
/* (((PI/2)-2*PI)/(2*PI))*256 = -0.75*256 = -192 */

    if (v->ang+0.25 > 1) 
     {
     sin_ang = sin_tab[(int)(v->ang*256)];
     cos_ang = sin_tab[(int)(v->ang*256) - 192];  
     }
    else
    { 
     sin_ang = sin_tab[(int)(v->ang*256)];
     cos_ang = sin_tab[(int)(v->ang*256) + 64];
    }

     v->de = v->ds*cos_ang + v->qs*sin_ang;
     v->qe = v->qs*cos_ang - v->ds*sin_ang;

}


