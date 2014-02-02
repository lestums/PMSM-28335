/*=====================================================================================
 File name:        RMP_CNTL.C                   
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  Ramp control          

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "rmp_cntl.h"

void rmp_cntl_calc(RMPCNTL *v)
{	

      if (v->target_value != v->setpt_value)
      {
         v->rmp_delay_cntl += 1;
         if (v->rmp_delay_cntl >= v->rmp_dly_max)
         {
           if (v->target_value >= v->setpt_value)
           {
            v->setpt_value += 0.0000305;  /* 0.0000305 is resolution of Q15 */
            if (v->setpt_value > v->rmp_hi_limit)
              v->setpt_value = v->rmp_hi_limit;           
            v->rmp_delay_cntl = 0;
           }
           else
           {
            v->setpt_value -= 0.0000305;  /* 0.0000305 is resolution of Q15 */
            if (v->setpt_value < v->rmp_lo_limit)
              v->setpt_value = v->rmp_lo_limit;           
            v->rmp_delay_cntl = 0;
           }
         }
         
      }
      else  v->s_eq_t_flg = 1; 
}


