/*=====================================================================================
 File name:        PID_REG3.C                   
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  PID controller with anti-windup          

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "pid_reg3.h"

void pid_reg3_calc(PIDREG3 *v)
{	

    v->e_reg3 = v->pid_ref_reg3 - v->pid_fdb_reg3;
    
    v->up_reg3 = v->Kp_reg3*v->e_reg3;
    
    v->uprsat_reg3 = v->up_reg3 + v->ui_reg3 + v->ud_reg3;
    
    if (v->uprsat_reg3 > v->pid_out_max)
      v->pid_out_reg3 =  v->pid_out_max;
    else if (v->uprsat_reg3 < v->pid_out_min)
      v->pid_out_reg3 =  v->pid_out_min;  
    else
      v->pid_out_reg3 = v->uprsat_reg3;
    
    v->saterr_reg3 = v->pid_out_reg3 - v->uprsat_reg3;
    
    v->ui_reg3 = v->ui_reg3 + v->Ki_reg3*v->up_reg3 + v->Kc_reg3*v->saterr_reg3;
    
    v->ud_reg3 = v->Kd_reg3*(v->up_reg3 - v->up1_reg3);
     
    v->up1_reg3 = v->up_reg3; 
    
}


