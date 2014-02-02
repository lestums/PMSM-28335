/* ==================================================================================
File name:      F28335_QEP.C
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Modifiers : ESIEE I3S Project team 
				LE STUM Sébastien - LIN Tingting
				MARECHAL Valentin - Duc Tran

Description:   This file contains the updated version of QEP Driver module for 
			   eZDSP F2833x
              
=====================================================================================
History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
----------------------------------------------------------------------------------*/

#include "DSP2833x_Device.h"
#include "F28335_qep.h"

void  F28335_QEP_Init(QEP* p)
{
	EQep1Regs.QUPRD=1500000;							// Timer initialisation for 100Hz at 150 MHz SYSCLKOUT
	EQep1Regs.QDECCTL.all = QEP_DECCTL_REG_INIT_STATE; 	// Initialization of QEP Decode Control Register
	EQep1Regs.QEPCTL.all = QEP_CTL_REG_INIT_STATE;		// Initialization of QEP Control register
	EQep1Regs.QPOSCTL.all = QEP_POSCTL_REG_INIT_STATE;	// Initialization of QEP Position-Compare Control Register
	EQep1Regs.QCAPCTL.all = QEP_CAPCTL_REG_INIT_STATE;		// Initialization of QEP Capture control register
	EQep1Regs.QPOSMAX = 4*p->nb_line_encoder;
	
	EALLOW;
	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;
	GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1;
	GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 1;
	EDIS; 
}    

void F28335_QEP_Calc(QEP* p)
{

     long tmp;

     p->dir_QEP = EQep1Regs.QEPSTS.bit.QDF;
     
     p->theta_raw = ((unsigned int)EQep1Regs.QPOSCNT) + p->cal_angle;
     
     tmp = __qmpy32by16(p->mech_scaler,p->theta_raw,31);   /* Q15 = Q30*Q0 */ 
     p->theta_mech = (int)(tmp);         /* Q15 -> Q15 */
     p->theta_mech &= 0x7FFF;
	     
     p->theta_elec = p->pole_pairs*p->theta_mech-2048;  /* Q0*Q15 = Q15 */
     p->theta_elec &= 0x7FFF;     
}

void F28335_QEP_Isr(QEP *p)
{

     p->QEP_cnt_idx = ((unsigned int)EQep1Regs.QPOSCNT);
     EQep1Regs.QPOSCNT = 0;
     p->index_sync_flag = 0x00F0;

}
