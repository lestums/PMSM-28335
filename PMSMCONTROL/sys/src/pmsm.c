/* ==============================================================================
System Name:  PMSM32

File Name:	PMSM3_2.C

Description:	Primary system file for the Real Implementation of Sensorless  
          		Field Orientation Control for a Three Phase Permanent-Magnet
          		Synchronous Motor (PMSM) using sliding-mode rotor position estimator

Originator:		Digital control systems Group - Texas Instruments

Note: In this software, the default inverter is supposed to be DMC1500 board. 
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 04-15-2005	Version 3.20: Support both F280x and F281x targets 
 04-25-2005 Version 3.21: Move EINT and ERTM down to ensure that all initialization
 						  is completed before interrupts are allowed.
=================================================================================  */

// Include header files used in the main function
#include "DSP2833x_Device.h"
#include "IQmathLib.h"
#include "pmsm.h"
#include "parameter.h"
#include "build.h"

// Prototype statements for functions found within this file.
interrupt void PWM_ISR(void);

// Global variables used in this system
float Vd_testing = 0;            // Vd testing (pu) 
float Vq_testing = 0.25;         // Vq testing (pu) 
float Id_ref = 0;                // Id reference (pu) 
float Iq_ref = 0.2;              // Iq reference (pu) 
float speed_ref = 0.2;           // Speed reference (pu)
int speed_ref_rpm;				// Speed reference (rpm) 
float T = 0.001/ISR_FREQUENCY;   // Samping period (sec), see parameter.h 

int IsrTicker = 0;
int BackTicker = 0;

volatile int enable_flag = 0;
int lock_rotor_flag = 0;

int speed_loop_ps = 1;      // Speed loop prescaler
int speed_loop_count = 1;           // Speed loop counter

int temp_buf1, temp_buf2, temp_buf3, temp_buf4;

// Instance a few transform objects
CLARKE clarke1 = CLARKE_DEFAULTS;
PARK park1 = PARK_DEFAULTS;
IPARK ipark1 = IPARK_DEFAULTS;

// Instance PID regulators to regulate the d and q synchronous axis currents,
// and speed
PIDREG3 pid1_id = PIDREG3_DEFAULTS;
PIDREG3 pid1_iq = PIDREG3_DEFAULTS;
PIDREG3 pid1_spd = PIDREG3_DEFAULTS;

// Instance a PWM driver instance
PWMGEN pwm1 = PWMGEN_DEFAULTS;

// Instance a Space Vector PWM modulator. This modulator generates a, b and c
// phases based on the d and q stationery reference frame inputs
SVGENDQ svgen_dq1 = SVGENDQ_DEFAULTS;

// Instance a QEP interface driver 
QEP qep1 = QEP_DEFAULTS;

// Instance a ramp controller to smoothly ramp the frequency
RMPCNTL rc1 = RMPCNTL_DEFAULTS;

//	Instance a ramp generator to simulate an Anglele
RAMPGEN rg1 = RAMPGEN_DEFAULTS;

// Create an instance of the current/dc-bus voltage measurement driver
ILEG2DCBUSMEAS ilg2_vdc1 = ILEG2DCBUSMEAS_DEFAULTS;

SPEED_MEAS_QEP speed1 = SPEED_MEAS_QEP_DEFAULTS;

// Create an instance of DATALOG Module
DLOG_4CH dlog = DLOG_4CH_DEFAULTS;      

extern void InitPieCtrl();
extern void InitSysCtrl();
extern void InitPieVectTable();

void main(void)
{

// Initialize System Control registers, PLL, WatchDog, Clocks to default state:
        // This function is found in the DSP280x_SysCtrl.c file.
	InitSysCtrl();

// Globally synchronize all ePWM modules to the time base clock (TBCLK)
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;

// HISPCP prescale register settings, normally it will be set to default values
    EALLOW;   // This is needed to write to EALLOW protected registers
    SysCtrlRegs.HISPCP.all = 0x0000;     // SYSCLKOUT/1 
    EDIS;   // This is needed to disable write to EALLOW protected registers 

// Disable and clear all CPU interrupts:
	DINT;
	IER = 0x0000;
	IFR = 0x0000;

// Initialize Pie Control Registers To Default State:
        // This function is found in the DSP280x_PieCtrl.c file.
	InitPieCtrl();

// Initialize the PIE Vector Table To a Known State:
        // This function is found in DSP280x_PieVect.c.
	// This function populates the PIE vector table with pointers
        // to the shell ISR functions found in DSP280x_DefaultIsr.c.
	InitPieVectTable();	
	
// User specific functions, Reassign vectors (optional), Enable Interrupts:

   // Waiting for enable flag set
   while (enable_flag==0) 
    { 
      BackTicker++;
    }
    
// Enable CNT_zero interrupt using EPWM1 Time-base
    EPwm1Regs.ETSEL.bit.INTEN = 1;   // Enable EPWM1INT generation 
    EPwm1Regs.ETSEL.bit.INTSEL = 1;  // Enable interrupt CNT_zero event
    EPwm1Regs.ETPS.bit.INTPRD = 1;   // Generate interrupt on the 1st event
	EPwm1Regs.ETCLR.bit.INT = 1;     // Enable more interrupts

// Reassign ISRs. 
        // Reassign the PIE vector for EPWM1_INT to point to a different 
        // ISR then the shell routine found in DSP280x_DefaultIsr.c.
        // This is done if the user does not want to use the shell ISR routine
        // but instead wants to use their own ISR.

	EALLOW;	// This is needed to write to EALLOW protected registers
	PieVectTable.EPWM1_INT = &PWM_ISR;
	EDIS;   // This is needed to disable write to EALLOW protected registers

// Enable PIE group 3 interrupt 1 for EPWM1_INT
    PieCtrlRegs.PIEIER3.all = M_INT1;

// Enable CPU INT3 for EPWM1_INT:
	IER |= M_INT3;

// Initialize PWM module
    pwm1.n_period = SYSTEM_FREQUENCY*1000000*T/2;  // Perscaler X1 (T1), ISR period = T x 1 
	pwm1.init(&pwm1); 


// Initialize DATALOG module
    dlog.iptr1 = &temp_buf1;
    dlog.iptr2 = &temp_buf2;
    dlog.iptr3 = &temp_buf3;
    dlog.iptr4 = &temp_buf4;
    dlog.trig_value = 0x1;
    dlog.size = 0x400;
    dlog.prescalar = 1;
    dlog.init(&dlog);

// Initialize QEP module
    qep1.nb_line_encoder = 2000;
    qep1.mech_scaler = _IQ30(0.25/qep1.nb_line_encoder);
    qep1.pole_pairs = P/2;
    qep1.cal_angle = -2365;
    qep1.init(&qep1);

// Initialize ADC module
    ilg2_vdc1.init(&ilg2_vdc1);

// Initialize the Speed module for QEP based speed calculation
    speed1.K1 = _IQ21(1/(BASE_FREQ*T));
    speed1.K2 = _IQ(1/(1+T*2*PI*30));  // Low-pass cut-off frequency
    speed1.K3 = _IQ(1)-speed1.K2;
    speed1.speed_rpm = 120*(BASE_FREQ/P);

// Initialize the RAMPGEN module
    rg1.step_angle_max = _IQ(BASE_FREQ*T);

// Initialize the PID_REG3 module for Id 
	pid1_id.Kp_reg3 = _IQ(0.06);
	pid1_id.Ki_reg3 = _IQ(0.001);
	pid1_id.Kd_reg3 = _IQ(0/T);
	pid1_id.Kc_reg3 = _IQ(0.016);
    pid1_id.pid_out_max = _IQ(0.30);
    pid1_id.pid_out_min = _IQ(-0.30);
 
// Initialize the PID_REG3 module for Iq 
	pid1_iq.Kp_reg3 = _IQ(0.06);
	pid1_iq.Ki_reg3 = _IQ(0.001);
	pid1_iq.Kd_reg3 = _IQ(0/T);
	pid1_iq.Kc_reg3 = _IQ(0.016);
    pid1_iq.pid_out_max = _IQ(0.7);
    pid1_iq.pid_out_min = _IQ(-0.7);    

// Initialize the PID_REG3 module for speed
    pid1_spd.Kp_reg3 = _IQ(0.5);                  
	pid1_spd.Ki_reg3 = _IQ(0.0005);
	pid1_spd.Kd_reg3 = _IQ(0/(T*speed_loop_ps));
 	pid1_spd.Kc_reg3 = _IQ(0.0004);
    pid1_spd.pid_out_max = _IQ(1);
    pid1_spd.pid_out_min = _IQ(-1); 

// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;	// Enable Global realtime interrupt DBGM

// IDLE loop. Just sit and loop forever:	
	for(;;) BackTicker++;

} 	

interrupt void PWM_ISR(void)
{

// Verifying the ISR
    IsrTicker++;

/* ***************** LEVEL1 ***************** */
#if (BUILDLEVEL==LEVEL1)

	rc1.target_value = _IQ(speed_ref);
	rc1.calc(&rc1);
	
	rg1.rmp_freq = rc1.setpt_value;
	rg1.calc(&rg1);
	
	ipark1.de = _IQ(Vd_testing);
	ipark1.qe = _IQ(Vq_testing);	
	ipark1.ang = rg1.rmp_out;
	ipark1.calc(&ipark1);
	
	svgen_dq1.Ualfa = ipark1.ds;
	svgen_dq1.Ubeta = ipark1.qs;
	svgen_dq1.calc(&svgen_dq1);	
	
	pwm1.Mfunc_c1 = (int)_IQtoIQ15(svgen_dq1.Ta); /* Mfunc_c1 is in Q15 */
	pwm1.Mfunc_c2 = (int)_IQtoIQ15(svgen_dq1.Tb); /* Mfunc_c2 is in Q15 */  
	pwm1.Mfunc_c3 = (int)_IQtoIQ15(svgen_dq1.Tc); /* Mfunc_c3 is in Q15 */
	pwm1.update(&pwm1);
	
	speed_ref_rpm = (int)(speed1.rpm_max*speed_ref);
	
/* select which of the variables are behing displayed trough data LOG */
	temp_buf1 = (int)_IQtoIQ15(rg1.rmp_out);
	temp_buf2 = (int)_IQtoIQ15(svgen_dq1.Ta);
	temp_buf3 = 0;
	temp_buf4 = 0;

#endif /* (BUILDLEVEL==LEVEL1) */

/* ***************** LEVEL2 ***************** */
#if (BUILDLEVEL==LEVEL2)

	rc1.target_value = _IQ(speed_ref);
	rc1.calc(&rc1);
	
	rg1.rmp_freq = rc1.setpt_value;
	rg1.calc(&rg1);
	
	ipark1.de = _IQ(Vd_testing);
	ipark1.qe = _IQ(Vq_testing);	
	ipark1.ang = rg1.rmp_out;
	ipark1.calc(&ipark1);
	
	svgen_dq1.Ualfa = ipark1.ds;
	svgen_dq1.Ubeta = ipark1.qs;
	svgen_dq1.calc(&svgen_dq1);	
	
	pwm1.Mfunc_c1 = (int)_IQtoIQ15(svgen_dq1.Ta); /* Mfunc_c1 is in Q15 */
	pwm1.Mfunc_c2 = (int)_IQtoIQ15(svgen_dq1.Tb); /* Mfunc_c2 is in Q15 */  
	pwm1.Mfunc_c3 = (int)_IQtoIQ15(svgen_dq1.Tc); /* Mfunc_c3 is in Q15 */
	pwm1.update(&pwm1);
	
	ilg2_vdc1.read(&ilg2_vdc1);
	
	clarke1.as = _IQ15toIQ((long)ilg2_vdc1.ImeasA);
	clarke1.bs = _IQ15toIQ((long)ilg2_vdc1.ImeasB);
	clarke1.calc(&clarke1);
		
	park1.ds = clarke1.ds;
	park1.qs = clarke1.qs;
	park1.ang = rg1.rmp_out;
	park1.calc(&park1);
		
	speed_ref_rpm = (int)(speed1.rpm_max*speed_ref);
		
	/* select which of the variables are behing displayed trough data LOG */
	
	temp_buf1 = (int)_IQtoIQ15(rg1.rmp_out);
	temp_buf2 = (int)_IQtoIQ15(svgen_dq1.Ta);
	temp_buf3 = (int)(ilg2_vdc1.ImeasA);
	temp_buf4 = (int)(ilg2_vdc1.ImeasB);


#endif /* (BUILDLEVEL==LEVEL2) */

/* ***************** LEVEL3 ***************** */
#if (BUILDLEVEL==LEVEL3)

	rc1.target_value = _IQ(speed_ref);
	rc1.calc(&rc1);
	
	rg1.rmp_freq = rc1.setpt_value;
	rg1.calc(&rg1);
	
	pid1_iq.pid_ref_reg3 = _IQ(Iq_ref);
	pid1_iq.pid_fdb_reg3 = park1.qe;
	pid1_iq.calc(&pid1_iq);
	
	pid1_id.pid_ref_reg3 = _IQ(Id_ref);
	pid1_id.pid_fdb_reg3 = park1.de;
	pid1_id.calc(&pid1_id);
	
	ipark1.de = pid1_id.pid_out_reg3;
	ipark1.qe = pid1_iq.pid_out_reg3;	
	ipark1.ang = rg1.rmp_out;
	ipark1.calc(&ipark1);
	
	svgen_dq1.Ualfa = ipark1.ds;
	svgen_dq1.Ubeta = ipark1.qs;
	svgen_dq1.calc(&svgen_dq1);	
	
	pwm1.Mfunc_c1 = (int)_IQtoIQ15(svgen_dq1.Ta); /* Mfunc_c1 is in Q15 */
	pwm1.Mfunc_c2 = (int)_IQtoIQ15(svgen_dq1.Tb); /* Mfunc_c2 is in Q15 */  
	pwm1.Mfunc_c3 = (int)_IQtoIQ15(svgen_dq1.Tc); /* Mfunc_c3 is in Q15 */
	pwm1.update(&pwm1);
	
	ilg2_vdc1.read(&ilg2_vdc1);
	
	clarke1.as = _IQ15toIQ((long)ilg2_vdc1.ImeasA);
	clarke1.bs = _IQ15toIQ((long)ilg2_vdc1.ImeasB);
	clarke1.calc(&clarke1);

	park1.ds = clarke1.ds;
	park1.qs = clarke1.qs;
	park1.ang = rg1.rmp_out;
	park1.calc(&park1);
 
	speed_ref_rpm = (int)(speed1.rpm_max*speed_ref);
	
	/* select which of the variables are behing displayed trough data LOG */
	
	temp_buf1 = (int)_IQtoIQ15(rg1.rmp_out);
	temp_buf2 = (int)_IQtoIQ15(svgen_dq1.Ta);
	temp_buf3 = (int)(ilg2_vdc1.ImeasA);
	temp_buf4 = (int)(ilg2_vdc1.ImeasB);

#endif /* (BUILDLEVEL==LEVEL3) */


/* ***************** LEVEL4 ***************** */
#if (BUILDLEVEL==LEVEL4)

	rc1.target_value = _IQ(speed_ref);
	rc1.calc(&rc1);
	
	rg1.rmp_freq = rc1.setpt_value;
	rg1.calc(&rg1);
	
	pid1_iq.pid_ref_reg3 = _IQ(Iq_ref);
	pid1_iq.pid_fdb_reg3 = park1.qe;
	pid1_iq.calc(&pid1_iq);
	
	pid1_id.pid_ref_reg3 = _IQ(Id_ref);
	pid1_id.pid_fdb_reg3 = park1.de;
	pid1_id.calc(&pid1_id);
	
/*-----------------------------------------------------------------------------
Checking lockrtr_flg=FALSE for spinning mode, lockrtr_flg=TRUE for locked rotor mode 
-----------------------------------------------------------------------------*/
	if(lock_rotor_falg==1) {
		ipark1.de = pid1_id.pid_out_reg3;
		ipark1.qe = pid1_iq.pid_out_reg3;	
		ipark1.ang = 0;
		ipark1.calc(&ipark1);
		
		svgen_dq1.Ualfa = ipark1.ds;
		svgen_dq1.Ubeta = ipark1.qs;
		svgen_dq1.calc(&svgen_dq1);	
		
		pwm1.Mfunc_c1 = (int)_IQtoIQ15(svgen_dq1.Ta); /* Mfunc_c1 is in Q15 */
		pwm1.Mfunc_c2 = (int)_IQtoIQ15(svgen_dq1.Tb); /* Mfunc_c2 is in Q15 */  
		pwm1.Mfunc_c3 = (int)_IQtoIQ15(svgen_dq1.Tc); /* Mfunc_c3 is in Q15 */
		pwm1.update(&pwm1);
		
		ilg2_vdc1.read(&ilg2_vdc_vcon1);
		
		clarke1.as = _IQ15toIQ((long)ilg2_vdc_vcon1.Imeas_a);
		clarke1.bs = _IQ15toIQ((long)ilg2_vdc_vcon1.Imeas_b);
		clarke1.calc(&clarke1);
		
		park1.ds = clarke1.ds;
		park1.qs = clarke1.qs;
		park1.ang = 0;
		park1.calc(&park1);

	} else if(lock_rotor_flag==0)	{

		ipark1.de = pid1_id.pid_out_reg3;
		ipark1.qe = pid1_iq.pid_out_reg3;	
		ipark1.ang = rg1.rmp_out;
		ipark1.calc(&ipark1);
		
		svgen_dq1.Ualfa = ipark1.ds;
		svgen_dq1.Ubeta = ipark1.qs;
		svgen_dq1.calc(&svgen_dq1);	
		
		pwm1.Mfunc_c1 = (int)_IQtoIQ15(svgen_dq1.Ta); /* Mfunc_c1 is in Q15 */
		pwm1.Mfunc_c2 = (int)_IQtoIQ15(svgen_dq1.Tb); /* Mfunc_c2 is in Q15 */  
		pwm1.Mfunc_c3 = (int)_IQtoIQ15(svgen_dq1.Tc); /* Mfunc_c3 is in Q15 */
		pwm1.update(&pwm1);
		
		ilg2_vdc1.read(&ilg2_vdc1);
		
		clarke1.as = _IQ15toIQ((long)ilg2_vdc1.ImeasA);
		clarke1.bs = _IQ15toIQ((long)ilg2_vdc1.ImeasB);
		clarke1.calc(&clarke1);
		
		park1.ds = clarke1.ds;
		park1.qs = clarke1.qs;
		park1.ang = rg1.rmp_out;
		park1.calc(&park1);
	
	} 
	
	qep1.calc(&qep1);
	
	speed1.theta_elec = _IQ15toIQ((long)qep1.theta_elec);
	speed1.dir_QEP = (long)(qep1.dir_QEP);
	speed1.calc(&speed1);
	
	speed_ref_rpm = (int)(speed1.rpm_max*speed_ref);
	
/* select which of the variables are behing displayed trough data LOG */
	temp_buf1 = (int)_IQtoIQ15(rg1.rmp_out);
	temp_buf2 = (int)_IQtoIQ15(speed1.theta_elec);
	temp_buf3 = 0;
	temp_buf4 = 0;

#endif /* (BUILDLEVEL==LEVEL4) */


/* ***************** LEVEL5 ***************** */
#if (BUILDLEVEL==LEVEL5)

	if (speed_loop_count==speed_loop_ps) {   
	/* use R66 (Vcontrol) on DMC550 for adjusting speed reference */
		pid1_spd.pid_ref_reg3 = _IQ15toIQ((long)ilg2_vdc1.Vcontrol);
		pid1_spd.pid_fdb_reg3 = speed1.speed_frq;
		pid1_spd.calc(&pid1_spd);
		speed_loop_count=1;
	} else speed_loop_count++; 
	
	pid1_iq.pid_ref_reg3 = pid1_spd.pid_out_reg3;
	pid1_iq.pid_fdb_reg3 = park1.qe;
	pid1_iq.calc(&pid1_iq);
	
	pid1_id.pid_ref_reg3 = _IQ(Id_ref);
	pid1_id.pid_fdb_reg3 = park1.de;
	pid1_id.calc(&pid1_id);
	
	ipark1.de = pid1_id.pid_out_reg3;
	ipark1.qe = pid1_iq.pid_out_reg3;	
	ipark1.ang = speed1.theta_elec;
	ipark1.calc(&ipark1);
	
	svgen_dq1.Ualfa = ipark1.ds;
	svgen_dq1.Ubeta = ipark1.qs;
	svgen_dq1.calc(&svgen_dq1);	
	
	pwm1.Mfunc_c1 = (int)_IQtoIQ15(svgen_dq1.Ta); /* Mfunc_c1 is in Q15 */
	pwm1.Mfunc_c2 = (int)_IQtoIQ15(svgen_dq1.Tb); /* Mfunc_c2 is in Q15 */  
	pwm1.Mfunc_c3 = (int)_IQtoIQ15(svgen_dq1.Tc); /* Mfunc_c3 is in Q15 */
	pwm1.update(&pwm1);
	
	ilg2_vdc1.read(&ilg2_vdc1);
	
	clarke1.as = _IQ15toIQ((long)ilg2_vdc1.ImeasA);
	clarke1.bs = _IQ15toIQ((long)ilg2_vdc1.ImeasB);
	clarke1.calc(&clarke1);
		
	park1.ds = clarke1.ds;
	park1.qs = clarke1.qs;
	park1.ang = speed1.theta_elec;
	park1.calc(&park1);
		
	qep1.calc(&qep1);
		
	speed1.theta_elec = _IQ15toIQ((long)qep1.theta_elec);
	speed1.dir_QEP = (long)(qep1.dir_QEP);
	speed1.calc(&speed1);
		
	speed_ref = _IQ15toF((long)ilg2_vdc1.Vcontrol); 
	speed_ref_rpm = (int)(speed1.rpm_max*speed_ref);
	
	/* select which of the variables are behing displayed trough data LOG */
	temp_buf1 = (int)_IQtoIQ15(svgen_dq1.Ta);    
	temp_buf2 = (int)_IQtoIQ15(speed1.theta_elec);
	temp_buf3 = (int)(ilg2_vdc1.ImeasA);
	temp_buf4 = (int)(ilg2_vdc1.ImeasB);

#endif /* (BUILDLEVEL==LEVEL5) */

// ------------------------------------------------------------------------------
//    Call the DATALOG update function.
// ------------------------------------------------------------------------------
    dlog.update(&dlog);

// Enable more interrupts from this timer
	EPwm1Regs.ETCLR.bit.INT = 1;

// Acknowledge interrupt to recieve more interrupts from PIE group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
