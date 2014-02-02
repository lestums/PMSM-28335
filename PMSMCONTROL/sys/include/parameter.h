/* ==============================================================================
System Name:  PMSM31

File Name:	PARAMETER.H

Description:	Parameters file for the Real Implementation of Sensored  
          		Field Orientation Control for a Three Phase Permanent-Magnet
          		Synchronous Motor (PMSM)
          		
Originator:		Digital control systems Group - Texas Instruments

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
=================================================================================  */

#ifndef PARAMETER_H
#define PARAMETER_H

/*-------------------------------------------------------------------------------
Next, definitions used in main file.
-------------------------------------------------------------------------------*/
#define PI 3.14159265358979

/* Define the system frequency (MHz) */
#define SYSTEM_FREQUENCY 150

/* Define the ISR frequency (kHz) */
#define ISR_FREQUENCY 20

// Parameters not used for sensored control are commented out.

/* This machine parameters are based on 24-v Applied Motion PMSM motor (A0050-103-3-000) */
/* Define the PMSM motor parameters */
//#define RS  	1.11               		/* Stator resistance (ohm) */
//#define RR   	0               		/* Rotor resistance (ohm) */
//#define LS   	0.00127    				/* Stator inductance (H) */
//#define LR   	0						/* Rotor inductance (H) */	
//#define PM   	0.01289					/* Permanent-magnat flux (volt.sec/rad) */
#define P    	8						/* Number of poles */	

/* Define the base quantites */
//#define BASE_VOLTAGE    13.86         /* Base peak phase voltage (volt) */
//#define BASE_CURRENT    3             /* Base peak phase current (amp) */
//#define BASE_TORQUE     7.35105194    /* Base torque (N.m) */
//#define BASE_FLUX       0.79616       /* Base flux linkage (volt.sec/rad) */
#define BASE_FREQ      	60          	/* Base electrical frequency (Hz) */

#endif  // end of PARAMETER.H definition

//===========================================================================
// No more.
//===========================================================================
