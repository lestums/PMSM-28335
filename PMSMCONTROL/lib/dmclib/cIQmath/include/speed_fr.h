/* =================================================================================
File name:        SPEED_FR.H  (IQ version)                    
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
    Header file containing the data types, constants for the rotor angle based
    speed measurement function. Also contains the prototypes for the 
    functions implemented in SPEED_FR.C
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 03-15-2003		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/
typedef struct {
       _iq theta_elec;  	/* Input: Electrical angle (pu)  */
       long dir_QEP;  		/* Input: Direction of rotation (Q0) - independently with global Q */
       _iq theta_old;   	/* History: Electrical angle at previous step (pu)  */
       _iq speed_frq;       /* Output: Speed in per-unit  (pu) */
       long rpm_max;        /* Parameter: Base speed in rpm (Q0) - independently with global Q */
       _iq21 K1;         	/* Parameter: Constant for differentiator (Q21) - independently with global Q */
       _iq K2;         		/* Parameter: Constant for low-pass filter (pu) */
       _iq K3;         		/* Parameter: Constant for low-pass filter (pu) */
       long speed_rpm;      /* Output : Speed in rpm  (Q0) - independently with global Q */
       void (*calc)();  	/* Pointer to the calulation function */
       } SPEED_MEAS_QEP;   	/* Data type created  */

typedef SPEED_MEAS_QEP *SPEED_MEAS_QEP_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the SPEED_MEAS_QEP object.
-----------------------------------------------------------------------------*/                     
#define SPEED_MEAS_QEP_DEFAULTS   { 0, \
                                    1, \
                                    0, \
                                    0, \
                                    0, \
                                    0, \
                                    0, \
                                    0, \
                                    0, \
                               (void (*)(long))speed_frq_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in SPEED_FR.C
------------------------------------------------------------------------------*/
void speed_frq_calc(SPEED_MEAS_QEP_handle); 
