/* ==================================================================================
File name:       F28335_VDC.C
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Modifiers : ESIEE I3S Project team 
				LE STUM Sébastien - LIN Tingting
				MARECHAL Valentin - Duc Tran

Description:	This file contains source for the F28335 Two leg current measurement 
				and DC-bus measurement driver.
              
=====================================================================================
*/

#include "DSP2833x_Device.h"
#include "F28335_vdc.h"

#define CPU_CLOCK_SPEED      6.667L   // for a 150MHz CPU clock speed
#define ADC_usDELAY 10000L
#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_CLOCK_SPEED) - 9.0L) / 5.0L)

extern void DSP2833x_usDelay(unsigned long Count);

void F28335_ileg2_dcbus_drv_init(ILEG2DCBUSMEAS *p)
{
    DELAY_US(ADC_usDELAY);	
  
    AdcRegs.ADCTRL1.all = ADC_RESET_FLAG; 		// Reset the ADC Module 
	asm(" NOP ");
	asm(" NOP ");    

    AdcRegs.ADCTRL3.bit.ADCBGRFDN = 0x3;		// Power up bandgap/reference circuitry
	DELAY_US(ADC_usDELAY);			    		// Delay before powering up rest of ADC 
    
    AdcRegs.ADCTRL3.bit.ADCPWDN = 1;	   		// Power up rest of ADC
	DELAY_US(ADC_usDELAY);	

    AdcRegs.ADCTRL3.bit.ADCCLKPS = 16;     		// Set up ADCTRL3 register 
    AdcRegs.ADCTRL1.all = ADCTRL1_INIT_STATE;	// Set up ADCTRL1 register 
    AdcRegs.ADCTRL2.all = ADCTRL2_INIT_STATE; 	// Set up ADCTRL2 register 
	AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 2;       // Specify three conversions
    AdcRegs.ADCCHSELSEQ1.all = p->ChSelect;     // Configure channel selection

    AdcRegs.ADCREFSEL.all = 39;                 // Set up the ADC reference select register
    AdcRegs.ADCOFFTRIM.all = 65534;             // Set up the ADC offset trim register

    // Set up Event Trigger with CNT_zero enable for Time-base of EPWM1
    EPwm1Regs.ETSEL.bit.SOCAEN = 1;     // Enable SOCA
    EPwm1Regs.ETSEL.bit.SOCASEL = 1;    // Enable CNT_zero event for SOCA
    EPwm1Regs.ETPS.bit.SOCAPRD = 1;     // Generate SOCA on the 1st event
	EPwm1Regs.ETCLR.bit.SOCA = 1;       // Clear SOCA flag

}  

void F28335_ileg2_dcbus_drv_read(ILEG2DCBUSMEAS *p)
{
       int16 DatQ15;
       int32 Tmp;

        // Wait until ADC conversion is completed
        while (AdcRegs.ADCST.bit.SEQ1_BSY == 1)
        {};

        DatQ15 = AdcRegs.ADCRESULT0^0x8000;       // Convert raw result to Q15 (bipolar signal)
        Tmp = (int32)p->ImeasAGain*(int32)DatQ15; // Tmp = gain*dat => Q28 = Q13*Q15
        p->ImeasA = (int16)(Tmp>>13);             // Convert Q28 to Q15
        p->ImeasA += p->ImeasAOffset;             // Add offset
        p->ImeasA *= -1;                   	  	  // Positive direction, current flows to motor

        DatQ15 = AdcRegs.ADCRESULT1^0x8000;   	  // Convert raw result to Q15 (bipolar signal)
        Tmp = (int32)p->ImeasBGain*(int32)DatQ15; // Tmp = gain*dat => Q28 = Q13*Q15
        p->ImeasB = (int16)(Tmp>>13);             // Convert Q28 to Q15
        p->ImeasB += p->ImeasBOffset;             // Add offset
        p->ImeasB *= -1;                   		  // Positive direction, current flows to motor
 
        DatQ15 = (AdcRegs.ADCRESULT2>>1)&0x7FFF;   // Convert raw result to Q15 (unipolar signal)
        Tmp = (int32)p->VdcMeasGain*(int32)DatQ15; // Tmp = gain*dat => Q28 = Q13*Q15
        if (Tmp > 0x0FFFFFFF)                      // Limit Tmp to 1.0 in Q28
           Tmp = 0x0FFFFFFF;
        p->VdcMeas = (int16)(Tmp>>13);             // Convert Q28 to Q15
        p->VdcMeas += p->VdcMeasOffset;            // Add offset

        p->ImeasC = -(p->ImeasA + p->ImeasB);      // Compute phase-c current
	p->Vcontrol = AdcRegs.ADCRESULT3^0x8000;    
        AdcRegs.ADCTRL2.all |= 0x4040;             // Reset the sequence

}            
          
