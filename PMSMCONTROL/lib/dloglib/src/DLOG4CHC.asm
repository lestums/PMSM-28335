;==============================================================================
; File name     : DLOG4CHC.ASM                     
;                    
; Originator    : Advanced Embeeded Control (AEC)
;                 Texas Instruments Inc.
;
; Description   : 4-Channel Data logging module
;
; Date          : 02/01/2002 (DD/MM/YYYY)
;==============================================================================
; Routine Name: data_log_update                                
;  
; C prototype : void DLOG_4CH_update(DLOG_4CH_handle);
;               void DLOG_4CH_init(DLOG_4CH_handle);
;
; The struct object is defined in the header file "dlog_4ch.h" as follows:
;
; typedef struct { 
;       long task;           /* Variable: Task address pointer          */
;       int  *iptr1;         /* Input: First input pointer (Q15)        */    
;       int  *iptr2;         /* Input: Second input pointer (Q15)       */        
;       int  *iptr3;         /* Input: Third input pointer (Q15)        */
;       int  *iptr4;         /* Input: Fourth input pointer (Q15)       */ 
;       int  trig_value;     /* Input: Trigger point (Q15)              */           
;       int  prescalar;      /* Parameter: Data log prescale            */
;       int  skip_cntr;      /* Variable: Data log skip counter         */                 
;       int  cntr;           /* Variable: Data log counter              */
;       long write_ptr;      /* Variable: Graph address pointer         */
;       int  size;           /* Parameter: Maximum data DLOG_4CH_buffer */
;       int  (*init)();      /* Pointer to init function                */
;       int  (*update)();    /* Pointer to update function              */ 
;       } DLOG_4CH;                            

;==============================================================================

; External Reference
                .def  _DLOG_4CH_update 
                .def  _DLOG_4CH_init

; Data log buffer definition
BUFF_SIZE       .set  800h
                
DLOG_4CH_buff1      .usect "DLOG", BUFF_SIZE
DLOG_4CH_buff2      .usect "DLOG", BUFF_SIZE
DLOG_4CH_buff3      .usect "DLOG", BUFF_SIZE
DLOG_4CH_buff4      .usect "DLOG", BUFF_SIZE
                

;==============================================================================
; Initialization Function
;==============================================================================

_DLOG_4CH_init:                                     
        MOVL    XAR5,#POS_TRIG_S1
        MOVL    *XAR4,XAR5          ; task=#POS_TRIG_S1 
        ADDB    XAR4,#10            ; XAR4->trig_value
        
        MOV     *+XAR4[2],#0

        MOVL    XAR5,#DLOG_4CH_buff1
        MOVL    *+XAR4[4],XAR5      ; write_ptr=DLOG_4CH_buff1
               
        
        MOV     AL,*+XAR4[6]        ; ACC=size
        MOV     *+XAR4[3],AL        ; cntr=size
        LRETR
            
;==============================================================================
; Datalog Update Function
;==============================================================================

_DLOG_4CH_update:   
        SETC    SXM
        MOVL    XAR5,XAR4           ; XAR4->task
        MOVL    XAR7,*XAR4++        ; XAR4->iptr1, XAR7=task            
        ADDB    XAR5,#10            ; XAR5->trig_value
        LB      *XAR7               ; Branch to TASK    
        
POS_TRIG_S1:
        MOV     ACC,*XAR5           ; ACC=trig_value
        MOVL    XAR6,*XAR4          ; XAR6=iptr1
        SUB     ACC,*XAR6           ; ACC=(trig_value - *iptr1)
        BF      DL_EXIT,LEQ         ; Exit if ACC <= 0 
                                         
        MOVL    XAR6,#POS_TRIG_S2   
        MOVL    *--XAR4,XAR6        ; task=POS_TRIG_S2
        LRETR
                
POS_TRIG_S2:                    
        MOV     ACC,*XAR5           ; ACC=trig_value
        MOVL    XAR6,*XAR4          ; XAR6=iptr1
        SUB     ACC,*XAR6           ; ACC=(trig_value - *iptr1)
        BF      DL_EXIT,GEQ         ; Exit if ACC >= 0 
                                                    
        MOVL    XAR6,#DL_TRIGGERED   
        MOVL    *--XAR4,XAR6        ; task=POS_TRIG_S2
        LRETR
                
DL_TRIGGERED:                                   
        INC     *+XAR5[2]           ; skip_cntr=skip_cntr+1
        MOV     ACC,*+XAR5[2]       ; ACC=skip_cntr
        SUB     ACC,*+XAR5[1]       ; ACC=skip_cntr-prescalar
        SBF     DL_EXIT,NEQ         ; if (skip_cntr+1) < prescalar, then exit
        
        MOV     *+XAR5[2],#0        ; skip_cntr=0   
        MOV     ACC,*+XAR5[3]       ; ACC=cntr
        SBF     DLOG_END,EQ 
                        
        DEC     *+XAR5[3]           ; cntr=cntr-1
        ADDB    XAR5,#4             ; XAR5->write_ptr

        MOVL    XAR6,*XAR5          ; XAR6=write_ptr
        ADDB    XAR6,#1             ; XAR6=write_ptr+1
        MOVL    *XAR5,XAR6          ; write_ptr=write_ptr + 1
        SUBB    XAR6,#1             ; XAR6=write_ptr

        MOV     AR0,#BUFF_SIZE      ; AR0=BUFF_SIZE 
        
                                
; Log sample pointed by IPTR1       
        MOVL    XAR7,*XAR4++        ; XAR7=iptr1
        MOV     AL,*XAR7            ; AL=*iptr1
        NOP     *,ARP6
        MOV     *0++,AL             ; *write_ptr=*iptr1, XAR6=write_ptr+size

; Log sample pointed by IPTR2           
        MOVL    XAR7,*XAR4++        ; XAR7=iptr2
        MOV     AL,*XAR7            ; AL=*iptr2
        NOP     *,ARP6
        MOV     *0++,AL             ; *write_ptr=*iptr2, XAR6=write_ptr+size

; Log sample pointed by IPTR3                           
        MOVL    XAR7,*XAR4++        ; XAR7=iptr3
        MOV     AL,*XAR7            ; AL=*iptr3
        NOP     *,ARP6
        MOV     *0++,AL             ; *write_ptr=*iptr3, XAR6=write_ptr+size

; Log sample pointed by IPTR4                   
        MOVL    XAR7,*XAR4++        ; XAR7=iptr4
        MOV     AL,*XAR7            ; AL=*iptr4
        NOP     *,ARP6
        MOV     *0++,AL             ; *write_ptr=*iptr4, XAR6=write_ptr+size
        LRETR

; Reinitialise the module to log the data when the logging is triggered next
        
DLOG_END: 

        MOVL    XAR6,#DLOG_4CH_buff1
        MOVL    *+XAR5[4],XAR6      ; write_ptr=DLOG_4CH_buff1
               
        MOVL    XAR6,#POS_TRIG_S1   
        MOVL    *--XAR4,XAR6        ; task=POS_TRIG_S2

        MOV     AL,*+XAR5[6]        ; ACC=size
        MOV     *+XAR5[3],AL        ; cntr=size
      
DL_EXIT:        
        LRETR   

