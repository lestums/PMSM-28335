/*=====================================================================================
 File name:        RAMPGEN.C                 
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  The Ramp Generation                   

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "rampgen.h"

void rampgen_calc(RAMPGEN *v)
{	

        v->angle_rg += v->step_angle_max*v->rmp_freq;       
        
        if (v->angle_rg>1)
          v->angle_rg -= 1;
        else if (v->angle_rg<-1)
          v->angle_rg += 1;

       v->rmp_out = v->angle_rg*v->rmp_gain + v->rmp_offset;

       if (v->rmp_out>1)
          v->rmp_out -= 1;
        else if (v->rmp_out<-1)
          v->rmp_out += 1;

}




