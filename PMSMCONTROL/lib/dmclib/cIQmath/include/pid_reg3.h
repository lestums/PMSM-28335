/* =================================================================================
File name:       PID_REG3.H  (IQ version)                    
                    
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

typedef struct {  _iq  pid_ref_reg3;   	/* Input: Reference input  */
				  _iq  pid_fdb_reg3;   	/* Input: Feedback input  */
				  _iq  e_reg3;			/* Variable: Error    */
				  _iq  Kp_reg3;			/* Parameter: Proportional gain  */
				  _iq  up_reg3;			/* Variable: Proportional output  */
				  _iq  ui_reg3;			/* Variable: Integral output    */
				  _iq  ud_reg3;			/* Variable: Derivative output    */	
				  _iq  uprsat_reg3; 	/* Variable: Pre-saturated output  */
				  _iq  pid_out_max;		/* Parameter: Maximum output    */
				  _iq  pid_out_min;		/* Parameter: Minimum output    */
				  _iq  pid_out_reg3;   	/* Output: PID output    */
				  _iq  saterr_reg3;		/* Variable: Saturated difference */
				  _iq  Ki_reg3;			/* Parameter: Integral gain   */
				  _iq  Kc_reg3;			/* Parameter: Integral correction gain  */
				  _iq  Kd_reg3; 		/* Parameter: Derivative gain   */
				  _iq  up1_reg3;		/* History: Previous proportional output  */
		 	 	  void  (*calc)();	  	/* Pointer to calculation function */ 
				 } PIDREG3;	            

typedef PIDREG3 *PIDREG3_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the PIDREG3 object.
-----------------------------------------------------------------------------*/                     
#define PIDREG3_DEFAULTS { 0, \
                           0, \
                           0, \
                           _IQ(1.3), \
                           0, \
                           0, \
                           0, \
                           0, \
                           _IQ(1), \
                           _IQ(-1), \
                           0, \
                           0, \
                           _IQ(0.02), \
                           _IQ(0.5), \
                           _IQ(1.05), \
                           0, \
              			  (void (*)(long))pid_reg3_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in PIDREG3.C
------------------------------------------------------------------------------*/
void pid_reg3_calc(PIDREG3_handle);
