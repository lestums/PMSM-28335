/*=====================================================================================
 File name:        SPEED_FR.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Speed measurement computation based QEP encoder (rotor angle)                   

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 03-15-2003	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "speed_fr.h"

void speed_frq_calc(SPEED_MEAS_QEP *v)
{

   _iq tmp1;

/* Differentiator  */
/*
   if (v->dir_QEP==0)      // T2 is counting down
   {
    if (v->theta_elec>v->theta_old)
      tmp1 = _IQ(1) - v->theta_elec + v->theta_old;
    else
      tmp1 = v->theta_elec - v->theta_old;
   }
   else if (v->dir_QEP==1)      // T2 is counting up
   {
    if (v->theta_elec<v->theta_old)
      tmp1 = _IQ(1) + v->theta_elec - v->theta_old;
    else 
      tmp1 = v->theta_elec - v->theta_old;
   }
   tmp1 = _IQmpy(v->K1,tmp1);     // Q21 = Q21*GLOBAL_Q
*/


// Differentiator  
  // Synchronous speed computation   
   if ((v->theta_elec < _IQ(0.9))&(v->theta_elec > _IQ(0.1)))
		// Q21 = Q21*(GLOBAL_Q-GLOBAL_Q)
   		tmp1 = _IQmpy(v->K1,(v->theta_elec - v->theta_old));
   else tmp1 = _IQtoIQ21(v->speed_frq);


// Low-pass filter 
   // Q21 = GLOBAL_Q*Q21 + GLOBAL_Q*Q21
   tmp1 = _IQmpy(v->K2,_IQtoIQ21(v->speed_frq))+_IQmpy(v->K3,tmp1);  

   if (tmp1>_IQ21(1))
     v->speed_frq = _IQ(1);
   else if (tmp1<_IQ21(-1))
     v->speed_frq = _IQ(-1);      
   else
     v->speed_frq = _IQ21toIQ(tmp1);

/* Update the electrical angle */
    v->theta_old = v->theta_elec;

/* Change motor speed from pu value to rpm value (GLOBAL_Q -> Q0) */
/* Q0 = Q0*GLOBAL_Q => _IQXmpy(), X = GLOBAL_Q */
   v->speed_rpm = _IQmpy(v->rpm_max,v->speed_frq); 

}

