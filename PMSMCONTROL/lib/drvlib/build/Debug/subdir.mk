################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/src/F28335_pwm.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/src/F28335_qep.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/src/F28335_vdc.c 

ASM_SRCS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/DSP2833x/source/DSP2833x_usDelay.asm 

ASM_DEPS += \
./DSP2833x_usDelay.pp 

OBJS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/obj/DSP2833x_usDelay.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/obj/F28335_pwm.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/obj/F28335_qep.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/obj/F28335_vdc.obj 

C_DEPS += \
./F28335_pwm.pp \
./F28335_qep.pp \
./F28335_vdc.pp 


# Each subdirectory must supply rules for building sources it contributes
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/obj/DSP2833x_usDelay.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/DSP2833x/source/DSP2833x_usDelay.asm $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/drvlib/include" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/DSP2833x/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/drvlib/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="DSP2833x_usDelay.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/obj/F28335_pwm.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/src/F28335_pwm.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/drvlib/include" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/DSP2833x/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/drvlib/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="F28335_pwm.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/obj/F28335_qep.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/src/F28335_qep.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/drvlib/include" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/DSP2833x/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/drvlib/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="F28335_qep.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/obj/F28335_vdc.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/drvlib/src/F28335_vdc.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/drvlib/include" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/DSP2833x/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/drvlib/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="F28335_vdc.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


