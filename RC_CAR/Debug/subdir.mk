################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_MOTOR_program.c \
../DIO_program.c \
../PWM_program.c \
../UART_program.c \
../main.c 

OBJS += \
./DC_MOTOR_program.o \
./DIO_program.o \
./PWM_program.o \
./UART_program.o \
./main.o 

C_DEPS += \
./DC_MOTOR_program.d \
./DIO_program.d \
./PWM_program.d \
./UART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


