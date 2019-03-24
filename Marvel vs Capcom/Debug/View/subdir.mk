################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../View/View.cpp \
../View/ViewModel.cpp \
../View/View_Jugador.cpp \
../View/View_Pantalla.cpp 

OBJS += \
./View/View.o \
./View/ViewModel.o \
./View/View_Jugador.o \
./View/View_Pantalla.o 

CPP_DEPS += \
./View/View.d \
./View/ViewModel.d \
./View/View_Jugador.d \
./View/View_Pantalla.d 


# Each subdirectory must supply rules for building sources it contributes
View/%.o: ../View/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


