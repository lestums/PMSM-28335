/* =================================================================================
File name:       ATAN2_TAB.H                     
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the ATAN2TAB.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/

typedef struct {  float  x;      		/* Input: x argument */
	              float  y;		  		/* Input: y argument  */
	              float  ang;         	/* Output: angle (pu)  */
		 	 	  void  (*calc)();	  	  /* Pointer to calculation function */ 
				 } ATAN2TAB;	            

typedef ATAN2TAB *ATAN2TAB_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the ATAN2TAB object.
-----------------------------------------------------------------------------*/                     
#define ATAN2TAB_DEFAULTS {  0,0,0, \
             			 (void (*)(long))atan2_tab_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in ATAN2_TAB.C
------------------------------------------------------------------------------*/
void atan2_tab_calc(ATAN2TAB_handle);

