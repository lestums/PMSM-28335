/* ==================================================================================
File name:        F28XPWM.H                     
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Modifiers : ESIEE I3S Project team 
				LE STUM Sébastien - LIN Tingting
				MARECHAL Valentin - Duc Tran

Description:  
		Header file containing data type and object definitions and 
		initializers. Also contains prototypes for the functions in F28XPWM.C.


=====================================================================================
*/


#ifndef __F28335_PWM_H__
#define __F28335_PWM_H__

#include "F28335_mask.h"

/*----------------------------------------------------------------------------
Initialization constant for the F28X Timer TxCON for PWM Generation. 
Sets up the timer to run free upon emulation suspend, continuous up-down mode
prescaler 1, timer enabled.
----------------------------------------------------------------------------*/
#define PWM_INIT_STATE  (FREE_RUN_FLAG +\
						PRDLD_IMMEDIATE+ \
                        TIMER_CNT_UPDN +        \
						HSPCLKDIV_PRESCALE_X_1+ \
                        CLKDIV_PRESCALE_X_1 + \
                        PHSDIR_CNT_UP   + \
                        CNTLD_DISABLE)

/*----------------------------------------------------------------------------
Initialization constant for the F2833X Compare Control Register
----------------------------------------------------------------------------*/
#define CMPCTL_INIT_STATE ( LOADAMODE_ZRO + \
                          LOADBMODE_ZRO + \
                          SHDWAMODE_SHADOW + \
                          SHDWBMODE_SHADOW )


/*---------------------------------------------------------------------------
Initialization constant for the F2833X Action Qualifier Output A Register
----------------------------------------------------------------------------*/
#define AQCTLA_INIT_STATE (CAU_SET +CAD_CLEAR)


/*-------------------------------------------------------------------------------------
Initialization constant for the F2833X Dead-Band Generator registers for PWM Generation
Stes up the dead band for PWM and sets up dead band values
----------------------------------------------------------------------------*/
#define DBCTL_INIT_STATE (BP_ENABLE + POLSEL_ACTIVE_HI_CMP)

#define DBCNT_INIT_STATE 100 //100 couunts = 1 usec (delay)* 100 count/usec ( for TBCLK =SYSCLK/1)



/*------------------------------------------------------------------------------------
Initialization constant for the F2833X PWM Chopper Control register for PWM Generation
----------------------------------------------------------------------------*/
#define PCCTL_INIT_STATE CHPEN_DISABLE


/*---------------------------------------------------------------------------
Initialization constant for the F2833X Trip ZOne Select Register
----------------------------------------------------------------------------*/
#define TZSEL_INIT_STATE DISABLE_TZSEL


/*----------------------------------------------------------------------------
Initialization constant for the F2833X Trip Zone Control Register
----------------------------------------------------------------------------*/
#define TZCTL_INIT_STATE   (TZA_HI_Z + TZB_HI_Z + \
                            DCAEVT1_HI_Z + DCAEVT2_HI_Z   +  \
                            DCBEVT1_HI_Z + DCBEVT2_HI_Z)

/*-----------------------------------------------------------------------------
Define the structure of the PWM Driver Object 
-----------------------------------------------------------------------------*/
typedef struct {   
        int n_period;          /* Input: PWM Half-Period in CPU clock cycles (Q0)  */
        int Mfunc_p;           /* Input: Period scaler (Q15)                */
        int Mfunc_c1;          /* Input: PWM 1&2 Duty cycle ratio (Q15)       */
        int Mfunc_c2;          /* Input: PWM 3&4 Duty cycle ratio (Q15)       */
        int Mfunc_c3;          /* Input: PWM 5&6 Duty cycle ratio (Q15)       */
        void (*init)();        /* Pointer to the init function               */
        void (*update)();      /* Pointer to the update function             */
        } PWMGEN ;    

/*-----------------------------------------------------------------------------
Define a PWMGEN_handle
-----------------------------------------------------------------------------*/
typedef PWMGEN *PWMGEN_handle;

/*------------------------------------------------------------------------------
Default Initializers for the F28X PWMGEN Object 
------------------------------------------------------------------------------*/
#define F28335_FC_PWM_GEN {1000,   \
                              0x7FFF, \
                              0x4000, \
                              0x4000, \
                              0x4000, \
                             (void (*)(long))F28335_PWM_Init,  \
                             (void (*)(long))F28335_PWM_Update \
                             }



#define PWMGEN_DEFAULTS 	F28335_FC_PWM_GEN
/*------------------------------------------------------------------------------
 Prototypes for the functions in F28XPWM.C
------------------------------------------------------------------------------*/
void F28335_PWM_Init(PWMGEN_handle);
void F28335_PWM_Update(PWMGEN_handle);

#endif  

