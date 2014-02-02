/* =================================================================================
File name:        RMP_CNTL.H  (IQ version)                  
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the RMPCNTL module.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/
#ifndef __RMP_CNTL_H__
#define __RMP_CNTL_H__

typedef struct { _iq  target_value; 	/* Input: Target input (pu) */
				 long  rmp_dly_max;		/* Parameter: Maximum delay rate (Q0) - independently with global Q */			
		 	 	 _iq  rmp_lo_limit;		/* Parameter: Minimum limit (pu) */					  
				 _iq  rmp_hi_limit;		/* Parameter: Maximum limit (pu) */
				 long  rmp_delay_cntl;  /* Variable: Incremental delay (Q0) - independently with global Q */	
				 _iq  setpt_value;		/* Output: Target output (pu) */				 
				 long  s_eq_t_flg;		/* Output: Flag output (Q0) - independently with global Q */
		  	  	 void  (*calc)();	  	/* Po_iqer to calculation function */ 
				 } RMPCNTL;	            

typedef RMPCNTL *RMPCNTL_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the RMPCNTL object.
-----------------------------------------------------------------------------*/                     
#define RMPCNTL_DEFAULTS { 0, \
                           400, \
                          	_IQ(-1), \
                          	_IQ(1), \
                          	0, \
                          	0, \
                          	0, \
                   			(void (*)(long))rmp_cntl_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in RMP_CNTL.C
------------------------------------------------------------------------------*/
void rmp_cntl_calc(RMPCNTL_handle);

#endif /* __RMP_CNTL_H__ */
