/*=====================================================================================
 File name:        VHZPROF.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:   V/f Profile for Scalar Control of Induction Motor

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "vhzprof.h"
#include <stdlib.h>

void vhz_prof_calc(VHZPROF *v)
{	
	_iq vf_slope, freq_abs;

    freq_abs = labs(v->freq);

	if (freq_abs <= v->FL)   
        v->vout = v->Vmin;                              /* Profile #1  */
	else if ((freq_abs > v->FL)&(freq_abs <= v->FH))      
       {
        vf_slope = _IQdiv((v->Vmax - v->Vmin),(v->FH - v->FL));    /* Computing v/f slope */
        v->vout = v->Vmin + _IQmpy(vf_slope,(freq_abs-v->FL));  /* Profile #2  */
       }
    else if ((freq_abs > v->FH)&(freq_abs < v->Fmax))      
        v->vout = v->Vmax;                             /* Profile #3  */
}


