/* =================================================================================
File name:       SVGEN_DQ.H  (IQ version)                    
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the SVGEN_DQ.
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-15-2002		Release	Rev 1.0                                                   
------------------------------------------------------------------------------*/

typedef struct 	{ _iq  Ualfa; 			/* Input: reference alfa-axis phase voltage   */
				  _iq  Ubeta;			/* Input: reference beta-axis phase voltage   */
				  _iq  Ta;				/* Output: reference phase-a switching function  */			
				  _iq  Tb;				/* Output: reference phase-b switching function   */
				  _iq  Tc;				/* Output: reference phase-c switching function   */
				  void   (*calc)();	    /* Pointer to calculation function */ 
				} SVGENDQ;
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																				
typedef SVGENDQ *SVGENDQ_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the SVGENDQ object.
-----------------------------------------------------------------------------*/                     
#define SVGENDQ_DEFAULTS { 0,0,0,0,0, \
                       (void (*)(long))svgendq_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in SVGEN_DQ.C
------------------------------------------------------------------------------*/
void svgendq_calc(SVGENDQ_handle);
