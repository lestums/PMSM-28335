/* ==================================================================================
File name:       ProjetQEP.H                     
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Modifiers : ESIEE I3S Project team 
				LE STUM Sébastien - LIN Tingting
				MARECHAL Valentin - Duc Tran

Description:	Header file containing data type and object definitions and 
				initializers. Also contains prototypes for the functions in ProjetQEP.C.

=====================================================================================
History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0                                      
----------------------------------------------------------------------------------*/

#ifndef __F28335_QEP_H__
#define __F28335_QEP_H__

#include "F28335_mask.h"

/*--------------------------------------------------------------------
	Initialization state for EQEP Decode Control Register
  -------------------------------------------------------------------- */
#define QEP_DECCTL_REG_INIT_STATE 	( XCR_X2 + QSRC_QUAD_MODE )

/*--------------------------------------------------------------------
	Initialization state for EQEP Control Register
  -------------------------------------------------------------------- */
#define QEP_CTL_REG_INIT_STATE 		( QEP_EMULATION_FREE + PCRM_INDEX + IEI_RISING + IEL_RISING + QPEN_ENABLE + QCLM_TIME_OUT + UTE_ENABLE )

/*--------------------------------------------------------------------
	Initialization state for EQEP Position-Compare Control Register
  -------------------------------------------------------------------- */
#define QEP_POSCTL_REG_INIT_STATE 	PCE_DISABLE

/*--------------------------------------------------------------------
	Initialization state for EQEP Capture Control Register
  -------------------------------------------------------------------- */
#define QEP_CAPCTL_REG_INIT_STATE 	( UPPS_X32 + CCPS_X1 + CEN_ENABLE )

/*-----------------------------------------------------------------------------
Define the structure of the QEP (Quadrature Encoder) Driver Object 
-----------------------------------------------------------------------------*/
typedef struct {int32 theta_elec;     /* Output: Motor Electrical angle (Q15)  */
                int32 theta_mech;     /* Output: Motor Mechanical Angle (Q15)  */
                Uint16 QEP_period;
				Uint16 dir_QEP;        /* Output: Motor rotation direction (Q0) */
                Uint32 QEP_cnt_idx; 	/* Variable: Encoder counter index (Q0)  */
                int32 theta_raw;      /* Variable: Raw angle from Timer 2 (Q0)             */
                Uint32 mech_scaler;   /* Parameter: 0.9999/total count (Q30) */
                Uint16 nb_line_encoder; /*Parameter: Number of line encoder (Q0) */
				Uint16 pole_pairs;     /* Parameter: Number of pole pairs (Q0)  */
                int32 cal_angle;      /* Parameter: Raw angular offset between encoder and phase a (Q0) */
                Uint16 index_sync_flag; /* Output: Index sync status (Q0)       */
                void (*init)();     /* Pointer to the init funcion           */
                void (*calc)();     /* Pointer to the calc funtion           */
                void (*isr)();      /* Pointer to the isr funtion           */
                }  QEP;

/*-----------------------------------------------------------------------------
Define a QEP_handle
-----------------------------------------------------------------------------*/
typedef QEP *QEP_handle;

/*-----------------------------------------------------------------------------
Default initializer for the QEP Object.
-----------------------------------------------------------------------------*/
/* Applied-motion PMSM motor: 24-v, 8-pole, 2000 line encoder */
/* mech_scaler = 1/8000 = 0x00020C4A (Q30) */

#define QEP_DEFAULTS { 0x0,0x0,0x0,0x0,0x0,0x0,0x00020C4A,0x0,4,0,0x0,  \
                (void (*)(int32))F28335_QEP_Init,            \
                (void (*)(int32))F28335_QEP_Calc, 	  		  \
                (void (*)(int32))F28335_QEP_Isr }

/*-----------------------------------------------------------------------------
Prototypes for the functions in F28XQEP.C                                 
-----------------------------------------------------------------------------*/
void F28335_QEP_Init(QEP_handle);                                              
void F28335_QEP_Calc(QEP_handle);
void F28335_QEP_Isr(QEP_handle);
                
#endif /*  __F28335_QEP_H__ */




