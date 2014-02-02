/* =================================================================================
File name:        VOLT_CAL.H (IQ version)                      
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
         Header file containing constants, data type definitions, and 
         function prototypes for the VOLT_CAL module.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/
#ifndef __VOLT_CAL_H__
#define __VOLT_CAL_H__

typedef struct 	{ _iq  DC_bus;		/* Input: DC-bus voltage (pu) */ 
			  	  _iq  Mfunc_V1;  	/* Input: Modulation voltage phase A (pu) */ 
		  	  	  _iq  Mfunc_V2;	/* Input: Modulation voltage phase B (pu) */ 	
		   	  	  _iq  Mfunc_V3;	/* Input: Modulation voltage phase C (pu) */ 
                  long  out_of_phase; /* Parameter: Out of Phase adjustment (0 or 1) (Q0) - independently with global Q */
	  	  	  	  _iq  Vphase_A;	/* Output: Phase voltage phase A (pu) */ 
		   	  	  _iq  Vphase_B;	/* Output: Phase voltage phase B (pu) */ 
		  	  	  _iq  Vphase_C;	/* Output: Phase voltage phase C (pu) */ 
		  	  	  _iq  Vdirect;		/* Output: Stationary d-axis phase voltage (pu) */ 
		  	  	  _iq  Vquadra;  	/* Output: Stationary q-axis phase voltage (pu) */
		  	  	  void  (*calc)();	/* Po_iqer to calculation function */ 
				} PHASEVOLTAGE;	                   

typedef PHASEVOLTAGE *PHASEVOLTAGE_handle; 

/*
out_of_phase = 1 for the out of phase correction if
* Mfunc_V1 is out of phase with PWM1,
* Mfunc_V2 is out of phase with PWM3,
* Mfunc_V3 is out of phase with PWM5,
otherwise, set 0 if their phases are correct.
*/

/*-----------------------------------------------------------------------------
Default initalizer for the PHASEVOLTAGE object.
-----------------------------------------------------------------------------*/                     
#define PHASEVOLTAGE_DEFAULTS { 0, \
                          		0, \
                          		0, \
                          		0, \
                          		1, \
                          		0, \
                          		0, \
                          		0, \
		         				0, \
 		          				0, \
                  				(void (*)(long))phase_voltage_calc }

#define ONE_THIRD  _IQ(0.33333333333333)
#define TWO_THIRD  _IQ(0.66666666666667)
#define INV_SQRT3  _IQ(0.57735026918963)
/*------------------------------------------------------------------------------
Prototypes for the functions in VOLT_CAL.C
------------------------------------------------------------------------------*/
void phase_voltage_calc(PHASEVOLTAGE_handle);

#endif /* __VOLT_CAL_H__ */
