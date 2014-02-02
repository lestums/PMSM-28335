/* =================================================================================
File name:        RAMPGEN.H  (IQ version)                   
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
This file contains type definitions, constants and initializers for
the ramp generation functions contained in RAMPGEN.C
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/

typedef struct { _iq  rmp_freq; 		/* Input: Ramp frequency (pu) */	
		 	     _iq  step_angle_max;	/* Parameter: Maximum step angle (pu) */		
	 	 	     _iq  angle_rg;			/* Variable: Step angle (pu) */					  
			     _iq  rmp_gain;			/* Input: Ramp gain (pu) */
			     _iq  rmp_out;  	 	/* Output: Ramp signal (pu) */	
			     _iq  rmp_offset;		/* Input: Ramp offset (pu) */				 
	  	  	     void  (*calc)();	  	/* Pointer to calculation function */ 
			   } RAMPGEN;	            

typedef RAMPGEN *RAMPGEN_handle;  
/*------------------------------------------------------------------------------
      Object Initializers
------------------------------------------------------------------------------*/                       
#define RAMPGEN_DEFAULTS {0,0,0,_IQ(1),0,_IQ(1), \
                         (void (*)(long))rampgen_calc }

/*------------------------------------------------------------------------------
      Funtion prototypes
------------------------------------------------------------------------------*/                                               
void rampgen_calc(RAMPGEN_handle);


