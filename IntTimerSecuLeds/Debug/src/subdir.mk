################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/IntTimerSecuLeds.c \
../src/TeclasDriver.c \
../src/TimerDriver.c \
../src/cr_startup_lpc43xx.c \
../src/crp.c \
../src/ledDriver.c \
../src/setupDriver.c \
../src/sysinit.c \
../src/vector.c 

OBJS += \
./src/IntTimerSecuLeds.o \
./src/TeclasDriver.o \
./src/TimerDriver.o \
./src/cr_startup_lpc43xx.o \
./src/crp.o \
./src/ledDriver.o \
./src/setupDriver.o \
./src/sysinit.o \
./src/vector.o 

C_DEPS += \
./src/IntTimerSecuLeds.d \
./src/TeclasDriver.d \
./src/TimerDriver.d \
./src/cr_startup_lpc43xx.d \
./src/crp.d \
./src/ledDriver.d \
./src/setupDriver.d \
./src/sysinit.d \
./src/vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__MULTICORE_NONE -DDEBUG -D__CODE_RED -DCORE_M4 -D__USE_LPCOPEN -DNO_BOARD_LIB -D__LPC43XX__ -D__REDLIB__ -I"C:\Users\Leo\Documents\LPCXpresso_8.0.0_526\workspace\IntTimerSecuLeds\inc" -I"C:\Users\Leo\Documents\LPCXpresso_8.0.0_526\workspace\lpc_chip_43xx\inc" -I"C:\Users\Leo\Documents\LPCXpresso_8.0.0_526\workspace\lpc_chip_43xx\inc\usbd" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


