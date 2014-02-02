/*=====================================================================================
 File name:        IPARK.C                   
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Inverse Park Transformation               

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "ipark.h"

extern float sin_tab[];

void ipark_calc(IPARK *v)
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
 
     v->ds = v->de*cos_ang - v->qe*sin_ang;
     v->qs = v->qe*cos_ang + v->de*sin_ang;  
}
