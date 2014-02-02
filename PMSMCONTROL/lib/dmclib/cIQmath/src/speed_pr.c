/*=====================================================================================
 File name:        SPEED_PR.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Speed measurement computation based capture                   

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "speed_pr.h"

void speed_prd_calc(SPEED_MEAS_CAP *v)
{

   _iq event_period;
   
   v->time_stamp_old = v->time_stamp_new;
   v->time_stamp_new = v->time_stamp;
   
   event_period = v->time_stamp-v->time_stamp_old;
   
   if (event_period < 0)
     event_period += 32767;   /* 7FFFh = 32767 */
     
   v->speed_prd = _IQdiv(v->speed_scaler,event_period); 

/* Q0 = Q0*GLOBAL_Q => _IQXmpy(), X = GLOBAL_Q */
   v->speed_rpm = _IQmpy(v->rpm_max,v->speed_prd); 
   
}
