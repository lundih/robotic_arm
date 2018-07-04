################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/motor_driver.c \
../source/robotic_arm.c \
../source/semihost_hardfault.c 

OBJS += \
./source/motor_driver.o \
./source/robotic_arm.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/motor_driver.d \
./source/robotic_arm.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DSDK_OS_FREE_RTOS -DFSL_RTOS_FREE_RTOS -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"/home/rufusy/robotic_arm/board" -I"/home/rufusy/robotic_arm/source" -I"/home/rufusy/robotic_arm" -I"/home/rufusy/robotic_arm/amazon-freertos/FreeRTOS/portable" -I"/home/rufusy/robotic_arm/amazon-freertos/portable" -I"/home/rufusy/robotic_arm/amazon-freertos/include" -I"/home/rufusy/robotic_arm/drivers" -I"/home/rufusy/robotic_arm/CMSIS" -I"/home/rufusy/robotic_arm/utilities" -I"/home/rufusy/robotic_arm/startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


