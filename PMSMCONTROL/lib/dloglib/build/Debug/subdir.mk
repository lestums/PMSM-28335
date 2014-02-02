################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dloglib/src/DLOG4CHC.asm 

ASM_DEPS += \
./DLOG4CHC.pp 

OBJS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dloglib/obj/DLOG4CHC.obj 


# Each subdirectory must supply rules for building sources it contributes
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dloglib/obj/DLOG4CHC.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dloglib/src/DLOG4CHC.asm $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dloglib/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="DLOG4CHC.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


