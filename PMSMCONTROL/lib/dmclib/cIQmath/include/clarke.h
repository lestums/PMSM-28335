/* =================================================================================
File name:       CLARKE.H  (IQ version)                  
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the CLARKE.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/

typedef struct {  _iq  as;  		/* Input: phase-a stator variable  */
				  _iq  bs;			/* Input: phase-b stator variable  */
				  _iq  ds;			/* Output: stationary d-axis stator variable  */
				  _iq  qs;			/* Output: stationary q-axis stator variable  */
		 	 	  void  (*calc)();	/* Pointer to calculation function */ 
				 } CLARKE;	            

typedef CLARKE *CLARKE_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the CLARKE object.
-----------------------------------------------------------------------------*/                     
#define CLARKE_DEFAULTS { 0, \
                          0, \
                          0, \
                          0, \
              			  (void (*)(long))clarke_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in CLARKE.C
------------------------------------------------------------------------------*/
void clarke_calc(CLARKE_handle);
