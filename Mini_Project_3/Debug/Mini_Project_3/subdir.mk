################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mini_Project_3/Mini_Project_3.c \
../Mini_Project_3/adc.c \
../Mini_Project_3/gpio.c \
../Mini_Project_3/lcd.c \
../Mini_Project_3/lm35_sensor.c \
../Mini_Project_3/motor.c 

OBJS += \
./Mini_Project_3/Mini_Project_3.o \
./Mini_Project_3/adc.o \
./Mini_Project_3/gpio.o \
./Mini_Project_3/lcd.o \
./Mini_Project_3/lm35_sensor.o \
./Mini_Project_3/motor.o 

C_DEPS += \
./Mini_Project_3/Mini_Project_3.d \
./Mini_Project_3/adc.d \
./Mini_Project_3/gpio.d \
./Mini_Project_3/lcd.d \
./Mini_Project_3/lm35_sensor.d \
./Mini_Project_3/motor.d 


# Each subdirectory must supply rules for building sources it contributes
Mini_Project_3/%.o: ../Mini_Project_3/%.c Mini_Project_3/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


