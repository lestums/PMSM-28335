################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LIB_SRCS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/lib/IQmath.lib 

OBJ_SRCS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/clarke.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/ipark.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/park.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/pid_reg3.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/rampgen.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/rmp_cntl.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/speed_fr.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/speed_pr.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/svgen_dq.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/svgen_mf.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/vhzprof.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/volt_calc.obj 

C_SRCS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/clarke.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/ipark.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/park.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/pid_reg3.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/rampgen.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/rmp_cntl.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/speed_fr.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/speed_pr.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/svgen_dq.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/svgen_mf.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/vhzprof.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/volt_calc.c 

OBJS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/clarke.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/ipark.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/park.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/pid_reg3.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/rampgen.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/rmp_cntl.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/speed_fr.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/speed_pr.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/svgen_dq.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/svgen_mf.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/vhzprof.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/volt_calc.obj 

C_DEPS += \
./clarke.pp \
./ipark.pp \
./park.pp \
./pid_reg3.pp \
./rampgen.pp \
./rmp_cntl.pp \
./speed_fr.pp \
./speed_pr.pp \
./svgen_dq.pp \
./svgen_mf.pp \
./vhzprof.pp \
./volt_calc.pp 


# Each subdirectory must supply rules for building sources it contributes
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/clarke.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/clarke.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="clarke.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/ipark.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/ipark.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="ipark.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/park.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/park.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="park.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/pid_reg3.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/pid_reg3.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="pid_reg3.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/rampgen.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/rampgen.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="rampgen.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/rmp_cntl.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/rmp_cntl.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="rmp_cntl.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/speed_fr.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/speed_fr.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="speed_fr.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/speed_pr.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/speed_pr.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="speed_pr.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/svgen_dq.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/svgen_dq.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="svgen_dq.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/svgen_mf.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/svgen_mf.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="svgen_mf.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/vhzprof.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/vhzprof.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="vhzprof.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/obj/volt_calc.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cIQmath/src/volt_calc.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cIQmath/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="volt_calc.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


