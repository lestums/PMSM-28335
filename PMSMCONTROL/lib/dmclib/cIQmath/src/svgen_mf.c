/*=====================================================================================
 File name:        SVGEN_MF.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:   Space-vector PWM generation based on magnitude and frequency components

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#include "IQmathLib.h"         /* Include header for IQmath library */
/* Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file */
#include "svgen_mf.h"

void svgenmf_calc(SVGENMF *v)
{	
	_iq step_angle_sv,entry_old,dx,dy;
	_iq T = _IQ(1.0);

	/* Normalise the freq input to appropriate step angle */
    /* Here, 1 pu. = 60 degree */
    step_angle_sv = _IQmpy(v->sv_freq,v->sv_freq_max);

    /* Calculate new angle alpha */
    entry_old = v->entry_new;
    v->alpha_sv = v->alpha_sv+step_angle_sv;
	if (v->alpha_sv >= _IQ(1.0))
	  v->alpha_sv = v->alpha_sv-_IQ(1.0); 
       
    v->entry_new = v->alpha_sv;
    
    dy = _IQsin(_IQmpy(v->entry_new,PI_THIRD));              /* dy = sin(entry_new) */
    dx = _IQsin(PI_THIRD-_IQmpy(v->entry_new,PI_THIRD));     /* dx = sin(60-entry_new) */
  
    /* Determine which sector */
    if (v->entry_new-entry_old<0)
    {
      if (v->sector_ptr==5)
         v->sector_ptr = 0;
      else
         v->sector_ptr = v->sector_ptr + 1;   
    }
 
    if (v->sector_ptr==0)  /* Sector 1 calculations - a,b,c --> a,b,c */
    {
		v->Ta = _IQmpy(_IQ(0.5),(T-dx-dy));
		v->Tb = v->Ta + dx;
		v->Tc = T - v->Ta; 
    }
    else if (v->sector_ptr==1)  /* Sector 2 calculations - a,b,c --> b,a,c  &  dx <--> dy */
    {
		v->Tb = _IQmpy(_IQ(0.5),(T-dx-dy));
		v->Ta = v->Tb + dy;
		v->Tc = T - v->Tb; 
    }
    else if (v->sector_ptr==2)  /* Sector 3 calculations - a,b,c --> b,c,a */
    {
		v->Tb = _IQmpy(_IQ(0.5),(T-dx-dy));
		v->Tc = v->Tb + dx;
	    v->Ta = T - v->Tb; 
    }
    else if (v->sector_ptr==3)  /* Sector 4 calculations - a,b,c --> c,b,a  &  dx <--> dy */
    {
		v->Tc = _IQmpy(_IQ(0.5),(T-dx-dy));
		v->Tb = v->Tc + dy;
		v->Ta = T - v->Tc; 
    }
    else if (v->sector_ptr==4)  /* Sector 5 calculations - a,b,c --> c,a,b */
    {
		v->Tc = _IQmpy(_IQ(0.5),(T-dx-dy));
		v->Ta = v->Tc + dx;
		v->Tb = T - v->Tc; 
    }
    else if (v->sector_ptr==5)  /* Sector 6 calculations - a,b,c --> a,c,b  &  dx <--> dy */
    {
		v->Ta = _IQmpy(_IQ(0.5),(T-dx-dy));
		v->Tc = v->Ta + dy;
		v->Tb = T - v->Ta; 
    }

    v->Ta = _IQmpy(_IQ(2.0),(v->Ta-_IQ(0.5)));
    v->Ta = _IQmpy(v->sv_gain,v->Ta) + v->sv_offset;

    v->Tb = _IQmpy(_IQ(2.0),(v->Tb-_IQ(0.5)));
    v->Tb = _IQmpy(v->sv_gain,v->Tb) + v->sv_offset;

    v->Tc = _IQmpy(_IQ(2.0),(v->Tc-_IQ(0.5)));
    v->Tc = _IQmpy(v->sv_gain,v->Tc) + v->sv_offset;

}



