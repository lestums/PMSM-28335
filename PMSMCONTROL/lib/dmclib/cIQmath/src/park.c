/*=====================================================================================
 File name:        PARK.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Park Transformation                   

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "park.h"

void park_calc(PARK *v)
{	
  
    _iq cos_ang,sin_ang;

/* Using look-up IQ sine table */  
     sin_ang = _IQsinPU(v->ang);
     cos_ang = _IQcosPU(v->ang);

     v->de = _IQmpy(v->ds,cos_ang) + _IQmpy(v->qs,sin_ang);
     v->qe = _IQmpy(v->qs,cos_ang) - _IQmpy(v->ds,sin_ang);

}


