/* =================================================================================
File name:        SPEED_PR.H  (IQ version)                 
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
    Header file containing the data types, constants for the period based
    speed measurement function. Also contains the prototypes for the 
    functions implemented in SPEED_PR.C
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/

typedef struct {
       long time_stamp_new;  /* Variable : New 'Timestamp' corresponding to a capture event (Q0) - independently with global Q */
       long time_stamp_old;  /* Variable : Old 'Timestamp' corresponding to a capture event (Q0) - independently with global Q */
       long time_stamp; 	 /* Input : Current 'Timestamp' corresponding to a capture event (Q0) - independently with global Q */
       long speed_scaler;    /* Parameter :  Scaler converting 1/N cycles to a Q15 speed (Q0) - independently with global Q */
       _iq speed_prd;        /* Output :  speed in per-unit                            */
       long rpm_max;         /* Parameter : Scaler converting Q15 speed to rpm (Q0) speed - independently with global Q */
       long speed_rpm;       /* Output : speed in r.p.m. (Q0) - independently with global Q  */
       void (*calc)();     	 /* Pointer to the calulation function                   */
       } SPEED_MEAS_CAP;     /* Data type created      */

/* 
Note that 
         speed_scaler = 60*f/rmp_max 
where f = CLK_freq/(128*N), N = number of teeth in sprocket
and 128 is pre-determined prescaler of timer 2 (used by capture)
*/

typedef SPEED_MEAS_CAP *SPEED_MEAS_CAP_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the SPEED_MEAS_CAP object.
-----------------------------------------------------------------------------*/                     
/* speed_scaler = 260 based on f(clk) 25 MHz, f(samping)=16.67, 25 kHz*/
/* rmp_max = 1800 rpm */

#define SPEED_MEAS_CAP_DEFAULTS   { 0, \
                                    0, \
                                    0, \
                                   260, \
                                    0, \
                                   1800, \
                                    0, \
                                  (void (*)(long))speed_prd_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in SPEED_PR.C
------------------------------------------------------------------------------*/
void speed_prd_calc(SPEED_MEAS_CAP_handle); 




