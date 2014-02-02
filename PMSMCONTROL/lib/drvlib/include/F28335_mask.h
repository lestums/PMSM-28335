/* ==================================================================================
File name:        PROJETMASK.H                     
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Modifiers : ESIEE I3S Project team 
				LE STUM Sébastien - LIN Tingting
				MARECHAL Valentin - Duc Tran			
*/

#ifndef  __F28335_MASK_H__
#define  __F28335_MASK_H__

/*------------------------------------------------------------------------------
  F28335 Time-Base Control Register (TBCTL)
------------------------------------------------------------------------------*/
#define TIMER_CNT_UP                0x0000
#define TIMER_CNT_DN                0x0001
#define TIMER_CNT_UPDN              0x0002
#define TIMER_STOP                  0x0003

#define CNTLD_ENABLE                0x0004
#define CNTLD_DISABLE               0x0000

#define PRDLD_IMMEDIATE             0x0008
#define PRDLD_SHADOW                0x0000

#define SYNCOSEL_EPWMSYNCI          0x0000
#define SYNCOSEL_CNT_EQ             0x0010
#define SYNCOSEL_CMPB_EQ            0x0020
#define SYNCOSEL_DISABLE            0x0030

#define HSPCLKDIV_PRESCALE_X_1      0x0000
#define HSPCLKDIV_PRESCALE_X_2      0x0080
#define HSPCLKDIV_PRESCALE_X_4      0x0100
#define HSPCLKDIV_PRESCALE_X_6  	0x0180
#define HSPCLKDIV_PRESCALE_X_8  	0x0200
#define HSPCLKDIV_PRESCALE_X_10  	0x0280
#define HSPCLKDIV_PRESCALE_X_12  	0x0300
#define HSPCLKDIV_PRESCALE_X_14 	0x0380

#define CLKDIV_PRESCALE_X_1         0x0000
#define CLKDIV_PRESCALE_X_2         0x0400
#define CLKDIV_PRESCALE_X_4         0x0800
#define CLKDIV_PRESCALE_X_8  	    0x0C00
#define CLKDIV_PRESCALE_X_16  	    0x1000
#define CLKDIV_PRESCALE_X_32  	    0x1400
#define CLKDIV_PRESCALE_X_64  	    0x1800
#define CLKDIV_PRESCALE_X_128 	    0x1C00

#define PHSDIR_CNT_UP               0x2000
#define PHSDIR_CNT_DN               0x0000

#define FREE_RUN_FLAG               0x8000
#define SOFT_STOP_FLAG              0x4000

/*------------------------------------------------------------------------------
 F28335 Compare Control Registers (CMPCTL)
------------------------------------------------------------------------------*/
#define LOADAMODE_ZRO               0x0000
#define LOADAMODE_PRD               0x0001
#define LOADAMODE_ZRO_PRD           0x0002
#define LOADAMODE_FRZ               0x0003

#define LOADBMODE_ZRO               0x0000
#define LOADBMODE_PRD               0x0004
#define LOADBMODE_ZRO_PRD           0x0008
#define LOADBMODE_FRZ               0x000C

#define SHDWAMODE_IMMEDIATE         0x0010
#define SHDWAMODE_SHADOW            0x0000

#define SHDWBMODE_IMMEDIATE         0x0040
#define SHDWBMODE_SHADOW            0x0000

/*------------------------------------------------------------------------------
 F28335 Action Qualifier Output A/B Control Registers (AQCTLA/AQCTLB)
------------------------------------------------------------------------------*/
#define ZRO_NOTHING                 0x0000
#define ZRO_CLEAR                   0x0001
#define ZRO_SET                     0x0002
#define ZRO_TOGGLE                  0x0003

#define PRD_NOTHING                 0x0000
#define PRD_CLEAR                   0x0004
#define PRD_SET                     0x0008
#define PRD_TOGGLE                  0x000C

#define CAU_NOTHING                 0x0000
#define CAU_CLEAR                   0x0010
#define CAU_SET                     0x0020
#define CAU_TOGGLE                  0x0030

#define CAD_NOTHING                 0x0000
#define CAD_CLEAR                   0x0040
#define CAD_SET                     0x0080
#define CAD_TOGGLE                  0x00C0

#define CBU_NOTHING                 0x0000
#define CBU_CLEAR                   0x0100
#define CBU_SET                     0x0200
#define CBU_TOGGLE                  0x0300

#define CBD_NOTHING                 0x0000
#define CBD_CLEAR                   0x0400
#define CBD_SET                     0x0800
#define CBD_TOGGLE                  0x0C00

/*------------------------------------------------------------------------------
 F28335 Action Qualifier S/W Force Register (AQSFRC)
------------------------------------------------------------------------------*/
#define ACTSFA_NOTHING              0x0000
#define ACTSFA_CLEAR                0x0001
#define ACTSFA_SET                  0x0002
#define ACTSFA_TOGGLE               0x0003

#define ACTSFB_NOTHING              0x0000
#define ACTSFB_CLEAR                0x0008
#define ACTSFB_SET                  0x0010
#define ACTSFB_TOGGLE               0x0018
 
#define RLDCSF_ZRO                  0x0000
#define RLDCSF_PRD                  0x0040
#define RLDCSF_ZRO_PRD              0x0080
#define RLDCSF_IMMEDIATE            0x00C0

/*------------------------------------------------------------------------------
 F28335 Action Qualifier Continuous S/W Force Register (AQCSFRC)
------------------------------------------------------------------------------*/
#define CSFA_DISABLE                0x0000
#define CSFA_LOW                    0x0001
#define CSFA_HIGH                   0x0002

#define CSFB_DISABLE                0x0000
#define CSFB_LOW                    0x0004
#define CSFB_HIGH                   0x0008

/*------------------------------------------------------------------------------
 F28335 Dead-Band Generator Control Register (DBCTL)
------------------------------------------------------------------------------*/
#define BP_DISABLE                  0x0000
#define BP_BYPASSA_FLA              0x0001
#define BP_BYPASSB_RSA              0x0002
#define BP_ENABLE                   0x0003

#define POLSEL_ACTIVE_HI            0x0000
#define POLSEL_ACTIVE_LO_CMP        0x0004
#define POLSEL_ACTIVE_HI_CMP        0x0008
#define POLSEL_ACTIVE_LO            0x000C

/*------------------------------------------------------------------------------
 F28335 PWM Chopper Control Register (PCCTL)
------------------------------------------------------------------------------*/
#define CHPEN_ENABLE                0x0001
#define CHPEN_DISABLE               0x0000

#define OSHTWTH_X_1                 0x0000
#define OSHTWTH_X_2                 0x0002
#define OSHTWTH_X_3                 0x0004
#define OSHTWTH_X_4                 0x0006
#define OSHTWTH_X_5                 0x0008
#define OSHTWTH_X_6                 0x000A
#define OSHTWTH_X_7                 0x000C
#define OSHTWTH_X_8                 0x000E
#define OSHTWTH_X_9                 0x0010
#define OSHTWTH_X_10                0x0012
#define OSHTWTH_X_11                0x0014
#define OSHTWTH_X_12                0x0016
#define OSHTWTH_X_13                0x0018
#define OSHTWTH_X_14                0x001A
#define OSHTWTH_X_15                0x001C
#define OSHTWTH_X_16                0x001E

#define CHPFREQ_X_1                 0x0000
#define CHPFREQ_X_2                 0x0020
#define CHPFREQ_X_3                 0x0040
#define CHPFREQ_X_4                 0x0060
#define CHPFREQ_X_5                 0x0080
#define CHPFREQ_X_6                 0x00A0
#define CHPFREQ_X_7                 0x00C0
#define CHPFREQ_X_8                 0x00E0

#define CHPDUTY_X_1                 0x0000
#define CHPDUTY_X_2                 0x0100
#define CHPDUTY_X_3                 0x0200
#define CHPDUTY_X_4                 0x0300
#define CHPDUTY_X_5                 0x0400
#define CHPDUTY_X_6                 0x0500
#define CHPDUTY_X_7                 0x0600

/*------------------------------------------------------------------------------
 F28335 Trip Zone Select Register (TZSEL)
------------------------------------------------------------------------------*/
#define DISABLE_TZSEL               0x0000

#define DISABLE_TZ1_CBC             0x0000
#define ENABLE_TZ1_CBC              0x0001

#define DISABLE_TZ2_CBC             0x0000
#define ENABLE_TZ2_CBC              0x0002

#define DISABLE_TZ3_CBC             0x0000
#define ENABLE_TZ3_CBC              0x0004

#define DISABLE_TZ4_CBC             0x0000
#define ENABLE_TZ4_CBC              0x0008

#define DISABLE_TZ5_CBC             0x0000
#define ENABLE_TZ5_CBC              0x0010

#define DISABLE_TZ6_CBC             0x0000
#define ENABLE_TZ6_CBC              0x0020

#define DISABLE_DCAEVT2_CBC         0x0000
#define ENABLE_DCAEVT2_CBC          0x0040

#define DISABLE_DCBEVT2_CBC         0x0000
#define ENABLE_DCBEVT2_CBC          0x0080

#define DISABLE_TZ1_OST             0x0000
#define ENABLE_TZ1_OST              0x0100

#define DISABLE_TZ2_OST             0x0000
#define ENABLE_TZ2_OST              0x0200

#define DISABLE_TZ3_OST             0x0000
#define ENABLE_TZ3_OST              0x0400

#define DISABLE_TZ4_OST             0x0000
#define ENABLE_TZ4_OST              0x0800

#define DISABLE_TZ5_OST             0x0000
#define ENABLE_TZ5_OST              0x1000

#define DISABLE_TZ6_OST             0x0000
#define ENABLE_TZ6_OST              0x2000

#define DISABLE_DCAEVT1_OST         0x0000
#define ENABLE_DCAEVT1_OST          0x4000

#define DISABLE_DCBEVT1_OST         0x0000
#define ENABLE_DCBEVT1_OST          0x8000

/*------------------------------------------------------------------------------
 F28335 Trip Zone Control Register (TZCTL)
------------------------------------------------------------------------------*/
#define TZA_HI_Z                    0x0000
#define TZA_FORCE_HI                0x0001
#define TZA_FORCE_LO                0x0002
#define TZA_NOTHING                 0x0003

#define TZB_HI_Z                    0x0000
#define TZB_FORCE_HI                0x0004
#define TZB_FORCE_LO                0x0008
#define TZB_NOTHING                 0x000C

#define DCAEVT1_HI_Z                0x0000
#define DCAEVT1_FORCE_HI            0x0010
#define DCAEVT1_FORCE_LO            0x0020
#define DCAEVT1_NOTHING             0x0030

#define DCAEVT2_HI_Z                0x0000
#define DCAEVT2_FORCE_HI            0x0040
#define DCAEVT2_FORCE_LO            0x0080
#define DCAEVT2_NOTHING             0x00C0

#define DCBEVT1_HI_Z                0x0000
#define DCBEVT1_FORCE_HI            0x0100
#define DCBEVT1_FORCE_LO            0x0200
#define DCBEVT1_NOTHING             0x0300

#define DCBEVT2_HI_Z                0x0000
#define DCBEVT2_FORCE_HI            0x0400
#define DCBEVT2_FORCE_LO            0x0800
#define DCBEVT2_NOTHING             0x0C00

/*------------------------------------------------------------------------------
 F28335 Trip Enable Interrupt Register (TZEINT)
------------------------------------------------------------------------------*/
#define DISABLE_CBC_INT            0x0000
#define ENABLE_CBC_INT             0x0002

#define DISABLE_OST_INT            0x0000
#define ENABLE_OST_INT             0x0004

#define DISABLE_DCAEVT1_INT        0x0000
#define ENABLE_DCAEVT1_INT         0x0008

#define DISABLE_DCAEVT2_INT        0x0000
#define ENABLE_DCAEVT2_INT         0x0010

#define DISABLE_DCBEVT1_INT        0x0000
#define ENABLE_DCBEVT1_INT         0x0020

#define DISABLE_DCBEVT2_INT        0x0000
#define ENABLE_DCBEVT2_INT         0x0040

/*------------------------------------------------------------------------------
 F28335 Event Trigger Selection Register (ETSEL)
------------------------------------------------------------------------------*/
#define INTSEL_CNT_ZERO            0x0001
#define INTSEL_PRD_EQ              0x0002
#define INTSEL_CMPA_EQ_UC          0x0004
#define INTSEL_CMPA_EQ_DC          0x0005
#define INTSEL_CMPB_EQ_UC          0x0006
#define INTSEL_CMPB_EQ_DC          0x0007

#define INTSEL_DISABLE             0x0000
#define INTSEL_ENABLE              0x0008

#define SOCASEL_CNT_ZERO           0x0100
#define SOCASEL_PRD_EQ             0x0200
#define SOCASEL_CMPA_EQ_UC         0x0400
#define SOCASEL_CMPA_EQ_DC         0x0500
#define SOCASEL_CMPB_EQ_UC         0x0600
#define SOCASEL_CMPB_EQ_DC         0x0700

#define SOCASEL_DISABLE            0x0000
#define SOCASEL_ENABLE             0x0800

#define SOCBSEL_CNT_ZERO           0x1000
#define SOCBSEL_PRD_EQ             0x2000
#define SOCBSEL_CMPA_EQ_UC         0x4000
#define SOCBSEL_CMPA_EQ_DC         0x5000
#define SOCBSEL_CMPB_EQ_UC         0x6000
#define SOCBSEL_CMPB_EQ_DC         0x7000

#define SOCBSEL_DISABLE            0x0000
#define SOCBSEL_ENABLE             0x8000

/*------------------------------------------------------------------------------
 F280X Event Trigger Pre-Scale Register (ETPS)
------------------------------------------------------------------------------*/
#define INTPRD_DISABLE             0x0000
#define INTPRD_ONE_EVENT           0x0001
#define INTPRD_TWO_EVENT           0x0002
#define INTPRD_THREE_EVENT         0x0003

#define SOCAPRD_DISABLE            0x0000
#define SOCAPRD_ONE_EVENT          0x0100
#define SOCAPRD_TWO_EVENT          0x0200
#define SOCAPRD_THREE_EVENT        0x0300

#define SOCBPRD_DISABLE            0x0000
#define SOCBPRD_ONE_EVENT          0x1000
#define SOCBPRD_TWO_EVENT          0x2000
#define SOCBPRD_THREE_EVENT        0x3000

/*------------------------------------------------------------------------------
 F28335 ECAP Control Register 1 (ECCTL1)
------------------------------------------------------------------------------*/
#define CAP1POL_RISING_EDGE        0x0000
#define CAP1POL_FALLING_EDGE       0x0001

#define CTRRST1_ABSOLUTE_TS        0x0000
#define CTRRST1_DIFFERENCE_TS      0x0002

#define CAP2POL_RISING_EDGE        0x0000
#define CAP2POL_FALLING_EDGE       0x0004

#define CTRRST2_ABSOLUTE_TS        0x0000
#define CTRRST2_DIFFERENCE_TS      0x0008

#define CAP3POL_RISING_EDGE        0x0000
#define CAP3POL_FALLING_EDGE       0x0010

#define CTRRST3_ABSOLUTE_TS        0x0000
#define CTRRST3_DIFFERENCE_TS      0x0020

#define CAP4POL_RISING_EDGE        0x0000
#define CAP4POL_FALLING_EDGE       0x0040

#define CTRRST4_ABSOLUTE_TS        0x0000
#define CTRRST4_DIFFERENCE_TS      0x0080

#define CAPLDEN_DISABLE            0x0000
#define CAPLDEN_ENABLE             0x0100

#define EVTFLTPS_X_1               0x0000
#define EVTFLTPS_X_2               0x0200
#define EVTFLTPS_X_4               0x0400
#define EVTFLTPS_X_6               0x0600
#define EVTFLTPS_X_8               0x0800
#define EVTFLTPS_X_10              0x0A00
#define EVTFLTPS_X_12              0x0C00
#define EVTFLTPS_X_14              0x0E00
#define EVTFLTPS_X_16              0x1000
#define EVTFLTPS_X_18              0x1200
#define EVTFLTPS_X_20              0x1400
#define EVTFLTPS_X_22              0x1600
#define EVTFLTPS_X_24              0x1800
#define EVTFLTPS_X_26              0x1A00
#define EVTFLTPS_X_28              0x1C00
#define EVTFLTPS_X_30              0x1E00
#define EVTFLTPS_X_32              0x2000
#define EVTFLTPS_X_34              0x2200
#define EVTFLTPS_X_36              0x2400
#define EVTFLTPS_X_38              0x2600
#define EVTFLTPS_X_40              0x2800
#define EVTFLTPS_X_42              0x2A00
#define EVTFLTPS_X_44              0x2C00
#define EVTFLTPS_X_46              0x2E00
#define EVTFLTPS_X_48              0x3000
#define EVTFLTPS_X_50              0x3200
#define EVTFLTPS_X_52              0x3400
#define EVTFLTPS_X_54              0x3600
#define EVTFLTPS_X_56              0x3800
#define EVTFLTPS_X_58              0x3A00
#define EVTFLTPS_X_60              0x3C00
#define EVTFLTPS_X_62              0x3E00

#define EMULATION_SOFT             0x0000
#define EMULATION_FREE             0x8000

/*------------------------------------------------------------------------------
 F28335 ECAP Control Register 2 (ECCTL2)
------------------------------------------------------------------------------*/
#define CONTINUOUS_MODE           0x0000
#define ONE_SHOT_MODE             0x0001

#define ONESHT_CAP_EV1            0x0000
#define ONESHT_CAP_EV2            0x0002
#define ONESHT_CAP_EV3            0x0004
#define ONESHT_CAP_EV4            0x0006

#define TSCNTSTP_STOP             0x0000
#define TSCNTSTP_FREE             0x0010

#define SYNCI_DISABLE             0x0000
#define SYNCI_ENABLE              0x0020

#define SYNCO_SYNC_IN             0x0000
#define SYNCO_PRD_EQ              0x0040
#define SYNCO_DISABLE             0x0080

#define CAPTURE_MODE              0x0000
#define APWM_MODE                 0x0200

#define APWMPOL_HIGH              0x0000
#define APWMPOL_LOW               0x0400

/*------------------------------------------------------------------------------
 F28335 EQEP Decode Control Register  (QDECCTL)
------------------------------------------------------------------------------*/
#define QSP_NO_EFFECT             0x0000
#define QSP_NEGATE                0x0020

#define QIP_NO_EFFECT             0x0000
#define QIP_NEGATE                0x0040

#define QBP_NO_EFFECT             0x0000
#define QBP_NEGATE                0x0080

#define QAP_NO_EFFECT             0x0000
#define QAP_NEGATE                0x0100

#define IGATE_DISABLE             0x0000
#define IGATE_WITH_STROBE         0x0200

#define SWAP_DISABLE              0x0000
#define SWAP_ENABLE               0x0400

#define XCR_X2                    0x0000
#define XCR_X1                    0x0800

#define SPSEL_INDEX               0x0000
#define SPSEL_STROBE              0x1000

#define SOEN_DISABLE              0x0000
#define SOEN_ENABLE               0x2000

#define QSRC_QUAD_MODE            0x0000
#define QSRC_DIR_MODE             0x4000
#define QSRC_UPCNT_MODE           0x8000
#define QSRC_DWNCNT_MODE          0xC000

/*------------------------------------------------------------------------------
 F28335 EQEP Control Register  (QEPCTL)
------------------------------------------------------------------------------*/
#define WDE_DISABLE               0x0000
#define WDE_ENABLE                0x0001

#define UTE_DISABLE               0x0000
#define UTE_ENABLE                0x0002

#define QCLM_POSCNT               0x0000
#define QCLM_TIME_OUT             0x0004

#define QPEN_RESET                0x0000
#define QPEN_ENABLE               0x0008

#define IEL_RISING                0x0010
#define IEL_FALLING               0x0020
#define IEL_SOFTWARE              0x0030

#define SEL_RISING                0x0000
#define SEL_RISING_FALLING        0x0040

#define SWI_DISABLE               0x0000
#define SWI_POSCNT_INIT           0x0080

#define IEI_RISING                0x0200
#define IEI_FALLING               0x0300

#define SEI_RISING                0x0800
#define SEI_RISING_FALLING        0x0C00

#define PCRM_INDEX                0x0000
#define PCRM_POSMAX               0x1000
#define PCRM_FIRST_INDEX          0x2000
#define PCRM_TIME_EVENT           0x3000

#define QEP_EMULATION_SOFT        0x4000
#define QEP_EMULATION_FREE        0x8000

/*------------------------------------------------------------------------------
 F28335 EQEP Position-Compare Control Register  (QPOSCTL)
------------------------------------------------------------------------------*/
#define PCE_DISABLE               0x0000
#define PCE_ENABLE                0x1000

#define PCPOL_HIGH                0x0000
#define PCPOL_LOW                 0x2000

#define PCLOAD_ZERO               0x0000
#define PCLOAD_QPOSCMP            0x4000

#define PCSHDW_DISABLE            0x0000
#define PCSHDW_ENABLE             0x8000

/*------------------------------------------------------------------------------
 F28335 EQEP Capture Control Register  (QCAPCTL)
------------------------------------------------------------------------------*/
#define UPPS_X1                   0x0000
#define UPPS_X2                   0x0001
#define UPPS_X3                   0x0002
#define UPPS_X8                   0x0003
#define UPPS_X16                  0x0004
#define UPPS_X32                  0x0005
#define UPPS_X64                  0x0006
#define UPPS_X128                 0x0007
#define UPPS_X256                 0x0008
#define UPPS_X512                 0x0009
#define UPPS_X1024                0x000A
#define UPPS_X2048                0x000B

#define CCPS_X1                   0x0000
#define CCPS_X2                   0x0010
#define CCPS_X4                   0x0020
#define CCPS_X8                   0x0030
#define CCPS_X16                  0x0040
#define CCPS_X32                  0x0050
#define CCPS_X64                  0x0060
#define CCPS_X128                 0x0070

#define CEN_DISABLE               0x0000
#define CEN_ENABLE                0x8000

/*------------------------------------------------------------------------------
 F28335 Register ADCTRL1
------------------------------------------------------------------------------*/
#define ADC_SUS_MODE0           0x0000
#define ADC_SUS_MODE1           0X1000
#define ADC_SUS_MODE2           0x2000
#define ADC_SUS_MODE3           0X3000
#define ADC_RESET_FLAG          0x4000

#define ADC_ACQ_PS_1            0x0000
#define ADC_ACQ_PS_2            0x0100
#define ADC_ACQ_PS_3            0x0200
#define ADC_ACQ_PS_4            0x0300
#define ADC_ACQ_PS_5            0x0400
#define ADC_ACQ_PS_6            0x0500
#define ADC_ACQ_PS_7            0x0600
#define ADC_ACQ_PS_8            0x0700
#define ADC_ACQ_PS_9            0x0800
#define ADC_ACQ_PS_10           0x0900
#define ADC_ACQ_PS_11           0x0A00
#define ADC_ACQ_PS_12           0x0B00
#define ADC_ACQ_PS_13           0x0C00
#define ADC_ACQ_PS_14           0x0D00
#define ADC_ACQ_PS_15           0x0E00
#define ADC_ACQ_PS_16           0x0F00

#define ADC_CPS_1               0x0000
#define ADC_CPS_2               0x0080
#define ADC_CONT_RUN            0x0040
#define ADC_SEQ_CASC            0x0010
#define ADC_SEQ_DUAL            0x0000

/*------------------------------------------------------------------------------
 F28335 Register ADCTRL2
------------------------------------------------------------------------------*/
#define ADC_EPWM_SOCB           0x8000
#define ADC_RST_SEQ1            0x4000
#define ADC_SOC_SEQ1            0x2000

#define ADC_INT_ENA_SEQ1        0x0800
#define ADC_INT_MODE_SEQ1       0X0400
#define ADC_EPWM_SOCA_SEQ1      0x0100

#define ADC_EXT_SOC_SEQ1        0x0080
#define ADC_RST_SEQ2            0x0040
#define ADC_SOC_SEQ2            0x0020

#define ADC_INT_ENA_SEQ2        0x0008
#define ADC_INT_MODE_SEQ2       0x0004
#define ADC_EPWM_SOCB_SEQ2      0x0001

/*------------------------------------------------------------------------------
 F28335 Register ADCTRL3
------------------------------------------------------------------------------*/
#define ADC_RFDN                0x0080
#define ADC_BGDN                0x0040
#define ADC_PWDN                0x0020

#define ADC_CLKPS_X_1           0x0000
#define ADC_CLKPS_X_2           0x0002
#define ADC_CLKPS_X_4           0x0004
#define ADC_CLKPS_X_6           0x0006
#define ADC_CLKPS_X_8           0x0008
#define ADC_CLKPS_X_10          0x000A
#define ADC_CLKPS_X_12          0x000C
#define ADC_CLKPS_X_14          0x000E
#define ADC_CLKPS_X_16          0x0010
#define ADC_CLKPS_X_18          0x0012
#define ADC_CLKPS_X_20          0x0014
#define ADC_CLKPS_X_22          0x0016
#define ADC_CLKPS_X_24          0x0018
#define ADC_CLKPS_X_26          0x001A
#define ADC_CLKPS_X_28          0x001C
#define ADC_CLKPS_X_30          0x001E

#define ADC_SMODE_SIMULTANEOUS  0x0001
#define ADC_SMODE_SEQUENTIAL    0x0000

#endif  // __F28335_BMSK_H__
// EOF


