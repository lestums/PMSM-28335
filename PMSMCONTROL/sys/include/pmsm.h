/* ==============================================================================
System Name:  PMSM

File Name:	PMSM.H

Description:	Primary system header file for the Real Implementation of Sensorless  
          	Field Orientation Control for a Three Phase Permanent-Magnet
          	Synchronous Motor (PMSM)

Originator:	Digital control systems Group - Texas Instruments

Modifiers:	ESIEE I3S Project team
		
		LE STUM Sébastien - LIN Tingting
		MARECHAL Valentin - TRAN Duc		
*/

#ifndef PMSM_H
#define PMSM_H

/*-------------------------------------------------------------------------------
Next, Include project specific include files.
-------------------------------------------------------------------------------*/

#include "park.h"       	// Include header for the PARK object 
#include "ipark.h"       	// Include header for the IPARK object 
#include "pid_reg3.h"       	// Include header for the PIDREG3 object 
#include "clarke.h"         	// Include header for the CLARKE object 
#include "svgen_dq.h"       	// Include header for the SVGENDQ object 
#include "speed_fr.h"		// Include header for the SPEED_MEAS_QEP object 
#include "rampgen.h"        	// Include header for the RAMPGEN object 
#include "rmp_cntl.h"       	// Include header for the RMPCNTL object 

#include "F28335_qep.h"        	// Include header for the QEP object 
#include "F28335_vdc.h"		// Include header for the ILEG2DCBUSMEAS object
#include "F28335_pwm.h"        	// Include header for the PWMGEN object 

#include "dlog4ch.h"		// Include header for the DLOG_4CH object

#endif

//===========================================================================
// No more.
//===========================================================================
