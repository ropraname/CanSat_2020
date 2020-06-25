################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/adxl345_i2c.c \
../Sources/bmp280_i2c.c \
../Sources/ds18b20.c \
../Sources/i2c_avr.c \
../Sources/main.c \
../Sources/onewire.c \
../Sources/romsearch.c \
../Sources/uart.c 

OBJS += \
./Sources/adxl345_i2c.o \
./Sources/bmp280_i2c.o \
./Sources/ds18b20.o \
./Sources/i2c_avr.o \
./Sources/main.o \
./Sources/onewire.o \
./Sources/romsearch.o \
./Sources/uart.o 

C_DEPS += \
./Sources/adxl345_i2c.d \
./Sources/bmp280_i2c.d \
./Sources/ds18b20.d \
./Sources/i2c_avr.d \
./Sources/main.d \
./Sources/onewire.d \
./Sources/romsearch.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


