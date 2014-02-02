/*=====================================================================================
 File name:        VOLT_CALC.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  The Voltage Reconstruction based on switching functions and DC-Bus voltage                    

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "volt_calc.h"

void phase_voltage_calc(PHASEVOLTAGE *v)
{	
     if (v->out_of_phase > 0)
     {
        v->Mfunc_V1 = -v->Mfunc_V1;
        v->Mfunc_V2 = -v->Mfunc_V2;
        v->Mfunc_V3 = -v->Mfunc_V3;     
     }

/* scale the incomming Modulation functions with the DC_bus value */
     v->Mfunc_V1 = _IQmpy(v->DC_bus,v->Mfunc_V1);
     v->Mfunc_V2 = _IQmpy(v->DC_bus,v->Mfunc_V2);    
     v->Mfunc_V3 = _IQmpy(v->DC_bus,v->Mfunc_V3);
 
/* calculate the 3 Phase voltages */         
     /* Phase A */
     v->Vphase_A = _IQmpy(TWO_THIRD,v->Mfunc_V1);
     v->Vphase_A -= _IQmpy(ONE_THIRD,v->Mfunc_V2);
     v->Vphase_A -= _IQmpy(ONE_THIRD,v->Mfunc_V3);

     /* Phase B */
     v->Vphase_B = _IQmpy(TWO_THIRD,v->Mfunc_V2);
     v->Vphase_B -= _IQmpy(ONE_THIRD,v->Mfunc_V1); 
     v->Vphase_B -= _IQmpy(ONE_THIRD,v->Mfunc_V3); 
               
     /* Phase C */
     v->Vphase_C = _IQmpy(TWO_THIRD,v->Mfunc_V3);
     v->Vphase_C -= _IQmpy(ONE_THIRD,v->Mfunc_V1); 
     v->Vphase_C -= _IQmpy(ONE_THIRD,v->Mfunc_V2);  

/* Voltage transformation (a,b,c)  ->  (Direct,Quadrature)  */
     /* Direct-axis */
     v->Vdirect = v->Vphase_A;
     
     /* Quadrature-axis */
     v->Vquadra = _IQmpy((v->Vphase_A + _IQmpy(_IQ(2),v->Vphase_B)),INV_SQRT3);

}



