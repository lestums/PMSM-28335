/* =================================================================================
File name:       PARK.H (IQ version)                    
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the PARK.

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/

typedef struct {  _iq  ds;  		/* Input: stationary d-axis stator variable */
				  _iq  qs;		    /* Input: stationary q-axis stator variable */
				  _iq  ang;			/* Input: rotating angle (pu) */
				  _iq  de;			/* Output: rotating d-axis stator variable */
				  _iq  qe;			/* Output: rotating q-axis stator variable */
		 	 	  void  (*calc)();	/* Pointer to calculation function */ 
				 } PARK;	            

typedef PARK *PARK_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the PARK object.
-----------------------------------------------------------------------------*/                     
#define PARK_DEFAULTS {  0, \
                          0, \
                          0, \
                          0, \
                          0, \
              			  (void (*)(long))park_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in PARK.C
------------------------------------------------------------------------------*/
void park_calc(PARK_handle);
