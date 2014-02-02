/* =================================================================================
File name:       IPARK.H                     
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the IPARK.

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/

typedef struct {  float  ds;  		/* Output: stationary d-axis stator variable */
				  float  qs;		/* Output: stationary q-axis stator variable */
				  float  ang;		/* Input: rotating angle (rad) */
				  float  de;		/* Input: rotating d-axis stator variable */
				  float  qe;		/* Input: rotating q-axis stator variable */
		 	 	  void  (*calc)();	/* Pointer to calculation function */ 
				 } IPARK;	            

typedef IPARK *IPARK_handle;

/*-----------------------------------------------------------------------------
Default initalizer for the IPARK object.
-----------------------------------------------------------------------------*/                     
#define IPARK_DEFAULTS {  0, \
                          0, \
                          0, \
                          0, \
                          0, \
              			  (void (*)(long))ipark_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in IPARK.C
------------------------------------------------------------------------------*/
void ipark_calc(IPARK_handle);

