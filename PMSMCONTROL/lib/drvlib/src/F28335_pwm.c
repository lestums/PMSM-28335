/* ==================================================================================
File name:      F28335_PWM.C
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Modifiers : ESIEE I3S Project team 
				LE STUM Sébastien - LIN Tingting
				MARECHAL Valentin - Duc Tran

Description:   	This file contains source for the Full Compare PWM  drivers for the 
		F28335
              
=====================================================================================
*/

#include "DSP2833x_Device.h"
#include "F28335_pwm.h"

#include "F28335_mask.h"

   
void F28335_PWM_Init(PWMGEN *p)    
{          
   
         // Setup Sync    
         EPwm1Regs.TBCTL.bit.SYNCOSEL = 0;          // Pass through    
         EPwm2Regs.TBCTL.bit.SYNCOSEL = 0;          // Pass through    
         EPwm3Regs.TBCTL.bit.SYNCOSEL = 0;          // Pass through    
        
   
         // Allow each timer to be sync'ed    
         EPwm1Regs.TBCTL.bit.PHSEN = 1;   
         EPwm2Regs.TBCTL.bit.PHSEN = 1;   
         EPwm3Regs.TBCTL.bit.PHSEN = 1;   
       
   
         // Init Timer-Base Period Register for EPWM1-EPWM3    
         EPwm1Regs.TBPRD = p->n_period;   
         EPwm2Regs.TBPRD = p->n_period; 
         EPwm3Regs.TBPRD = p->n_period;   
   
         // Init Timer-Base Phase Register for EPWM1-EPWM3    
         EPwm1Regs.TBPHS.half.TBPHS = 0;   
         EPwm2Regs.TBPHS.half.TBPHS = 0;   
         EPwm3Regs.TBPHS.half.TBPHS = 0;   
   
         // Init Timer-Base Control Register for EPWM1-EPWM3    
         EPwm1Regs.TBCTL.all = PWM_INIT_STATE;   
         EPwm2Regs.TBCTL.all = PWM_INIT_STATE;   
         EPwm3Regs.TBCTL.all = PWM_INIT_STATE;   
   
         // Init Compare Control Register for EPWM1-EPWM3    
         EPwm1Regs.CMPCTL.all = CMPCTL_INIT_STATE;   
         EPwm2Regs.CMPCTL.all = CMPCTL_INIT_STATE;   
         EPwm3Regs.CMPCTL.all = CMPCTL_INIT_STATE;   
   
         // Init Action Qualifier Output A Register for EPWM1-EPWM3    
         EPwm1Regs.AQCTLA.all = AQCTLA_INIT_STATE;   
         EPwm2Regs.AQCTLA.all = AQCTLA_INIT_STATE;   
         EPwm3Regs.AQCTLA.all = AQCTLA_INIT_STATE;   
   
         // Init Dead-Band Generator Control Register for EPWM1-EPWM3    
         EPwm1Regs.DBCTL.all = DBCTL_INIT_STATE;   
         EPwm2Regs.DBCTL.all = DBCTL_INIT_STATE;   
         EPwm3Regs.DBCTL.all = DBCTL_INIT_STATE;   
   
		 // Init Dead-Band Generator Control Register for EPWM1-EPWM3    
         EPwm1Regs.DBFED = DBCNT_INIT_STATE;
		 EPwm1Regs.DBRED = DBCNT_INIT_STATE;
         EPwm2Regs.DBFED = DBCNT_INIT_STATE;
		 EPwm2Regs.DBRED = DBCNT_INIT_STATE;
		 EPwm3Regs.DBFED = DBCNT_INIT_STATE;
		 EPwm3Regs.DBRED = DBCNT_INIT_STATE;

         ///// Init PWM Chopper Control Register for EPWM1-EPWM3    
         EPwm1Regs.PCCTL.all = PCCTL_INIT_STATE;   
         EPwm2Regs.PCCTL.all = PCCTL_INIT_STATE;   
         EPwm3Regs.PCCTL.all = PCCTL_INIT_STATE;   
    
         EALLOW;                       // Enable EALLOW     
   
         // Init Trip Zone Select Register    
         EPwm1Regs.TZSEL.all = TZSEL_INIT_STATE;   
         EPwm2Regs.TZSEL.all = TZSEL_INIT_STATE;   
         EPwm3Regs.TZSEL.all = TZSEL_INIT_STATE;   
   
         // Init Trip Zone Control Register    
         EPwm1Regs.TZCTL.all = TZCTL_INIT_STATE;   
         EPwm2Regs.TZCTL.all = TZCTL_INIT_STATE;   
         EPwm2Regs.TZCTL.all = TZCTL_INIT_STATE;   
   
         // Setting six EPWM as primary output pins    
         GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // EPWM1A pin    
         GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // EPWM1B pin    
         GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // EPWM2A pin    
         GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // EPWM2B pin    
         GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // EPWM3A pin    
         GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // EPWM3B pin    
   
         EDIS;                         // Disable EALLOW    
}   
   
   
void F28335_PWM_Update(PWMGEN *p)    
{          
   
    int32 Tmp;   
    int16 MPeriod;   
   
// Convert "Period" (Q15) modulation function to Q0    
    Tmp = (int32)p->n_period*(int32)p->Mfunc_p;								// Q15 = Q0*Q15    
    MPeriod = (int16)(Tmp>>16) + (int16) (p->n_period>>1);                         // Q0 = (Q15->Q0)/2 + (Q0/2)

      EPwm1Regs.TBPRD = MPeriod;
	  EPwm2Regs.TBPRD = MPeriod;
	  EPwm3Regs.TBPRD = MPeriod;
      

	  // Compute the compare A (Q0) from the EPWM1A0 & EPWM1B0 duty cycle ratio (Q15)
    Tmp = (int32)p->n_period*(int32)p->Mfunc_c1;								// Q15 = Q0*Q15    
    EPwm1Regs.CMPA.half.CMPA = (int16) (Tmp>>16) + (int16) (MPeriod>>1);			// Q0 = (Q15->Q0)/2 + (Q0/2)
	

	  // Compute the compare B (Q0) from the EPWM1A0 & EPWM1B0 duty cycle ratio (Q15)
    Tmp = (int32)p->n_period*(int32)p->Mfunc_c2;								// Q15 = Q0*Q15    
    EPwm2Regs.CMPA.half.CMPA = (int16) (Tmp>>16) + (int16) (MPeriod>>1);			// Q0 = (Q15->Q0)/2 + (Q0/2)

  // Compute the compare C (Q0) from the EPWM1A0 & EPWM1B0 duty cycle ratio (Q15)
    Tmp = (int32)p->n_period*(int32)p->Mfunc_c3;								// Q15 = Q0*Q15    
    EPwm3Regs.CMPA.half.CMPA = (int16) (Tmp>>16) + (int16) (MPeriod>>1);			// Q0 = (Q15->Q0)/2 + (Q0/2)

}   
