################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Command/Command.cpp \
../Command/CommandCtrl.cpp 

OBJS += \
./Command/Command.o \
./Command/CommandCtrl.o 

CPP_DEPS += \
./Command/Command.d \
./Command/CommandCtrl.d 


# Each subdirectory must supply rules for building sources it contributes
Command/%.o: ../Command/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


