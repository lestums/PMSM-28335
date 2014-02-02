/*=====================================================================================
 File name:        RAMPGEN.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  The Ramp Generation                   

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "rampgen.h"

void rampgen_calc(RAMPGEN *v)
{	

        v->angle_rg += _IQmpy(v->step_angle_max,v->rmp_freq);       
        
        if (v->angle_rg>_IQ(1))
          v->angle_rg -= _IQ(1);
        else if (v->angle_rg<_IQ(-1))
          v->angle_rg += _IQ(1);

       v->rmp_out = _IQmpy(v->angle_rg,v->rmp_gain) + v->rmp_offset;

       if (v->rmp_out>_IQ(1))
          v->rmp_out -= _IQ(1);
        else if (v->rmp_out<_IQ(-1))
          v->rmp_out += _IQ(1);

}



