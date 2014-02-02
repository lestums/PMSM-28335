/* ==================================================================================
File name:       F280XILEG_VDC.H
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Modifiers : ESIEE I3S Project team 
				LE STUM Sébastien - LIN Tingting
				MARECHAL Valentin - Duc Tran

Description: 	This header file contains source for the F28335 Two leg current measurement 
		and DC-bus measurement driver.
*/

#ifndef __F28335ILEG_VDC_H__
#define __F28335ILEG_VDC_H__

#include "F28335_mask.h"

/*-----------------------------------------------------------------------------
Define the structure of the ILEG2DCBUSMEAS Object
-----------------------------------------------------------------------------*/
typedef struct { int16 ImeasAGain;    // Parameter: gain for Ia (Q13) 
                 int16 ImeasAOffset;   // Parameter: offset for Ia (Q15) 
                 int16 ImeasA;         // Output: measured Ia (Q15) 
                 int16 ImeasBGain;     // Parameter: gain for Ib (Q13) 
                 int16 ImeasBOffset;   // Parameter: offset for Ib (Q15) 
                 int16 ImeasB;         // Output: measured Ib (Q15) 
                 int16 VdcMeasGain;    // Parameter: gain for Vdc (Q13) 
                 int16 VdcMeasOffset;  // Parameter: offset for Vdc (Q15) 
                 int16 VdcMeas;        // Output: measured Vdc (Q15) 
				 int16 Vcontrol; 	   // Output: V control for speed reference (Q15)
				 int16 ImeasC;	  	   // Output: computed Ic (Q15) 	
                 Uint16 ChSelect;      // Parameter: ADC channel selection
                 void (*init)();       // Pointer to the init function 
                 void (*read)();       // Pointer to the read function 
               } ILEG2DCBUSMEAS;

typedef ILEG2DCBUSMEAS *ILEG2DCBUSMEAS_handle;
/*-----------------------------------------------------------------------------
 Note 1 : It is necessary to call the init function to change the ADC 
            register settings, for the change in the channel setting for 
            ChSelect setting changes to take effect.
            The read function will not detect or act upon this change.
-----------------------------------------------------------------------------*/
// Default Initializer for the ILEG2DCBUSMEAS Object
// DMC1500 + eZdsp2808: ChSelect = 0x0710
// DMC550 + eZdsp2808: ChSelect = 0x0610
// Note: Assuming the base DC-bus voltage is 24 volt 
//        - ADC input for Vdc_bus range is 24*1/(24.9+1) = 0.927 volt on DMC550
//        - Then, Vdc_bus gain = 3.0/0.927 = 3.2375 (or 0x675C in Q13) 

#define F28335_ILEG2_DCBUS_MEAS_DEFAULTS { 0x1FFF,0x0000,0x0000,             \
                                          0x1FFF,0x0000,0x0000,             \
                                          0x1FFF,0x0000,0x0000,             \
                                          0x0000,0x0000,0x0710,                    \
                                          (void (*)(Uint32))F28335_ileg2_dcbus_drv_init, \
                                          (void (*)(Uint32))F28335_ileg2_dcbus_drv_read  \
                                         }

#define ILEG2DCBUSMEAS_DEFAULTS F28335_ILEG2_DCBUS_MEAS_DEFAULTS 

#define ADCTRL1_INIT_STATE  ADC_SUS_MODE0 + ADC_ACQ_PS_16 + \
                            ADC_CPS_2 + ADC_SEQ_CASC

#define ADCTRL2_INIT_STATE  ADC_EPWM_SOCA_SEQ1

/*------------------------------------------------------------------------------
 Prototypes for the functions in F280XILEG_VDC.C
------------------------------------------------------------------------------*/
void F28335_ileg2_dcbus_drv_init(ILEG2DCBUSMEAS *);
void F28335_ileg2_dcbus_drv_read(ILEG2DCBUSMEAS *);

#endif 
