/*=====================================================================================
 File name:        RMP_CNTL.H                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description: Header file containing constants, data type definitions, and 
 function prototypes for the RMPCNTL module.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0
-------------------------------------------------------------------------------------*/

#ifndef __RMP_CNTL_H__
#define __RMP_CNTL_H__

typedef struct { float  target_value; 	/* Input: Target input (pu) */
				 float  rmp_dly_max;	/* Parameter: Maximum delay rate (Q0) */			
		 	 	 float  rmp_lo_limit;	/* Parameter: Minimum limit (pu) */					  
				 float  rmp_hi_limit;	/* Parameter: Maximum limit (pu) */
				 float  rmp_delay_cntl; /* Variable: Incremental delay (Q0) */	
				 float  setpt_value;	/* Output: Target output (pu) */				 
				 float  s_eq_t_flg;		/* Output: Flag output (Q0) */
		  	  	 void  (*calc)();	  	/* Pofloater to calculation function */ 
				 } RMPCNTL;	            

typedef RMPCNTL *RMPCNTL_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the RMPCNTL object.
-----------------------------------------------------------------------------*/                     
#define RMPCNTL_DEFAULTS { 0, \
                           5, \
                          	-1, \
                          	1, \
                          	0, \
                          	0, \
                          	0, \
                   			(void (*)(long))rmp_cntl_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in RMP_CNTL.C
------------------------------------------------------------------------------*/
void rmp_cntl_calc(RMPCNTL_handle);

#endif /* __RMP_CNTL_H__ */
