################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/atan2_tab.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/atan_tab.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/clarke.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/fix_float.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/ipark.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/park.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/pid_reg3.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/rampgen.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/rmp_cntl.c \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/sin_tab.c 

OBJS += \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/atan2_tab.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/atan_tab.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/clarke.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/fix_float.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/ipark.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/park.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/pid_reg3.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/rampgen.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/rmp_cntl.obj \
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/sin_tab.obj 

C_DEPS += \
./atan2_tab.pp \
./atan_tab.pp \
./clarke.pp \
./fix_float.pp \
./ipark.pp \
./park.pp \
./pid_reg3.pp \
./rampgen.pp \
./rmp_cntl.pp \
./sin_tab.pp 


# Each subdirectory must supply rules for building sources it contributes
C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/atan2_tab.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/atan2_tab.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="atan2_tab.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/atan_tab.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/atan_tab.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="atan_tab.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/clarke.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/clarke.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="clarke.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/fix_float.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/fix_float.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="fix_float.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/ipark.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/ipark.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="ipark.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/park.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/park.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="park.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/pid_reg3.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/pid_reg3.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="pid_reg3.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/rampgen.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/rampgen.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="rampgen.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/rmp_cntl.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/rmp_cntl.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="rmp_cntl.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/obj/sin_tab.obj: C:/Documents\ and\ Settings/projet/Bureau/TestCode\ 1/PMSMCONTROL/lib/dmclib/cfloat/src/sin_tab.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g -O3 --define="_DEBUG" --define="LARGE_MODEL" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Program Files/Texas Instruments/xdais_6_23/packages/ti/xdais" --include_path="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/include" --quiet --diag_warning=225 --sat_reassoc=off --large_memory_model --fp_reassoc=off --obj_directory="C:/Documents and Settings/projet/Bureau/TestCode 1/PMSMCONTROL/lib/dmclib/cfloat/obj" $(GEN_OPTS_QUOTED) --preproc_with_compile --preproc_dependency="sin_tab.pp" $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


