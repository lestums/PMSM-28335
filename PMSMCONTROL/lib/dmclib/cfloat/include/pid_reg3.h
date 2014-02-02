/* =================================================================================
File name:       PID_REG3.H                     
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the PIDREG3.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/

typedef struct {  float  pid_ref_reg3;   	/* Input: Reference input  */
				  float  pid_fdb_reg3;   	/* Input: Feedback input  */
				  float  e_reg3;			/* Variable: Error    */
				  float  Kp_reg3;			/* Parameter: Proportional gain  */
				  float  up_reg3;			/* Variable: Proportional output  */
				  float  ui_reg3;			/* Variable: Integral output    */
				  float  ud_reg3;			/* Variable: Derivative output    */	
				  float  uprsat_reg3; 		/* Variable: Pre-saturated output  */
				  float  pid_out_max;		/* Parameter: Maximum output    */
				  float  pid_out_min;		/* Parameter: Minimum output    */
				  float  pid_out_reg3;   	/* Output: PID output    */
				  float  saterr_reg3;		/* Variable: Saturated difference */
				  float  Ki_reg3;			/* Parameter: Integral gain   */
				  float  Kc_reg3;			/* Parameter: Integral correction gain  */
				  float  Kd_reg3; 			/* Parameter: Derivative gain   */
				  float  up1_reg3;			/* History: Previous proportional output  */
		 	 	  void  (*calc)();	  		/* Pointer to calculation function */ 
				 } PIDREG3;	            

typedef PIDREG3 *PIDREG3_handle;

/*-----------------------------------------------------------------------------
Default initalizer for the PIDREG3 object.
-----------------------------------------------------------------------------*/                     
#define PIDREG3_DEFAULTS { 0, \
                           0, \
                           0, \
                           56, \
                           0, \
                           0, \
                           0, \
                           0, \
                           1, \
                           -1, \
                           0, \
                           0, \
                           0.02, \
                           0.5, \
                           1.05, \
                           0, \
              			  (void (*)(long))pid_reg3_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in PIDREG3.C
------------------------------------------------------------------------------*/
void pid_reg3_calc(PIDREG3_handle);
