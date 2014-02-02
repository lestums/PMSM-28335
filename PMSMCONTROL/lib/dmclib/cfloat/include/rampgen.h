/* =================================================================================
File name:        RAMPGEN.H                   
                    
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

typedef struct { float  rmp_freq; 		/* Input: Ramp frequency (pu) */	
		 	     float  step_angle_max;	/* Parameter: Maximum step angle (pu) */		
	 	 	     float  angle_rg;		/* Variable: Step angle (pu) */					  
			     float  rmp_gain;		/* Input: Ramp gain (pu) */
			     float  rmp_out;  	 	/* Output: Ramp signal (pu) */	
			     float  rmp_offset;		/* Input: Ramp offset (pu) */				 
	  	  	     void  (*calc)();	  	/* Pointer to calculation function */ 
			   } RAMPGEN;	            

typedef RAMPGEN *RAMPGEN_handle;  
/*------------------------------------------------------------------------------
      Object Initializers
------------------------------------------------------------------------------*/                       
#define RAMPGEN_DEFAULTS {0,0,0,1,0,1, \
                         (void (*)(long))rampgen_calc }

/*------------------------------------------------------------------------------
      Funtion prototypes
------------------------------------------------------------------------------*/                                               
void rampgen_calc(RAMPGEN_handle);

