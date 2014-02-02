/* =================================================================================
File name:       SVGEN_MF.H  (IQ version)                   
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the SVGEN_MF.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002	Release	Rev 1.0                                                  
------------------------------------------------------------------------------*/

typedef struct 	{ _iq  sv_gain; 		/* Input: reference gain voltage (pu) */
				  _iq  sv_offset;		/* Input: reference offset voltage (pu) */
				  _iq  sv_freq;			/* Input: reference frequency (pu) */
                  _iq  sv_freq_max;  	/* Parameter: Maximum step angle = 6*base_freq*T (pu) */ 
                  _iq  alpha_sv;     	/* History: Sector angle (pu) */
                  _iq  entry_new;    	/* History: Sine (angular) look-up pointer (pu) */
                  long  sector_ptr;    	/* History: Sector number (Q0) - independently with global Q */
				  _iq  Ta;				/* Output: reference phase-a switching function (pu)  */			
				  _iq  Tb;				/* Output: reference phase-b switching function (pu)  */
				  _iq  Tc;				/* Output: reference phase-c switching function (pu)  */
				  void   (*calc)();	    /* Pointer to calculation function */ 
				} SVGENMF;
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																				
typedef SVGENMF *SVGENMF_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the SVGENMF object.
-----------------------------------------------------------------------------*/                     
#define SVGENMF_DEFAULTS { 0,0,0,0,0,0,0,0,0,0, \
                       (void (*)(long))svgenmf_calc }

#define	PI_THIRD	_IQ(1.04719755119660)    /* This is 60 degree */
/*------------------------------------------------------------------------------
Prototypes for the functions in SVGEN_MF.C
------------------------------------------------------------------------------*/
void svgenmf_calc(SVGENMF_handle);
