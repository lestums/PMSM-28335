/*=====================================================================================
 File name:        IPARK.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Inverse Park Transformation                   

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "ipark.h"

void ipark_calc(IPARK *v)
{	
   
   _iq cos_ang,sin_ang;
   
/* Using look-up IQ sine table */  
     sin_ang = _IQsinPU(v->ang);
     cos_ang = _IQcosPU(v->ang);
 
     v->ds = _IQmpy(v->de,cos_ang) - _IQmpy(v->qe,sin_ang);
     v->qs = _IQmpy(v->qe,cos_ang) + _IQmpy(v->de,sin_ang);  
}


