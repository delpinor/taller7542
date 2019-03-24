################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Command/CommandCtrl/Agachar.cpp \
../Command/CommandCtrl/AumentarVelocidadX.cpp \
../Command/CommandCtrl/AumentarVelocidadY.cpp \
../Command/CommandCtrl/DisminuirVelocidadX.cpp \
../Command/CommandCtrl/DisminuirVelocidadY.cpp \
../Command/CommandCtrl/Saltar.cpp 

OBJS += \
./Command/CommandCtrl/Agachar.o \
./Command/CommandCtrl/AumentarVelocidadX.o \
./Command/CommandCtrl/AumentarVelocidadY.o \
./Command/CommandCtrl/DisminuirVelocidadX.o \
./Command/CommandCtrl/DisminuirVelocidadY.o \
./Command/CommandCtrl/Saltar.o 

CPP_DEPS += \
./Command/CommandCtrl/Agachar.d \
./Command/CommandCtrl/AumentarVelocidadX.d \
./Command/CommandCtrl/AumentarVelocidadY.d \
./Command/CommandCtrl/DisminuirVelocidadX.d \
./Command/CommandCtrl/DisminuirVelocidadY.d \
./Command/CommandCtrl/Saltar.d 


# Each subdirectory must supply rules for building sources it contributes
Command/CommandCtrl/%.o: ../Command/CommandCtrl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


