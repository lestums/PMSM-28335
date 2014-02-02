/*=====================================================================================
 File name:        CLARKE.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Clarke Transformation                   

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "clarke.h"

/* 1/sqrt(3) = 0.57735026918963 */
   
void clarke_calc(CLARKE *v)
{	
   v->ds = v->as;

   v->qs = _IQmpy((v->as + _IQmpy(_IQ(2),v->bs)),_IQ(0.57735026918963));
 
}


