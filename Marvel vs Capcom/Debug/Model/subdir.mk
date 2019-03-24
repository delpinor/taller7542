################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Model/Activo.cpp \
../Model/Estado.cpp \
../Model/Inactivo.cpp \
../Model/LTexture.cpp \
../Model/Model.cpp \
../Model/Model_Jugador.cpp 

OBJS += \
./Model/Activo.o \
./Model/Estado.o \
./Model/Inactivo.o \
./Model/LTexture.o \
./Model/Model.o \
./Model/Model_Jugador.o 

CPP_DEPS += \
./Model/Activo.d \
./Model/Estado.d \
./Model/Inactivo.d \
./Model/LTexture.d \
./Model/Model.d \
./Model/Model_Jugador.d 


# Each subdirectory must supply rules for building sources it contributes
Model/%.o: ../Model/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


