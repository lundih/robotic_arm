################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../amazon-freertos/portable/fsl_tickless_systick.c \
../amazon-freertos/portable/heap_4.c 

OBJS += \
./amazon-freertos/portable/fsl_tickless_systick.o \
./amazon-freertos/portable/heap_4.o 

C_DEPS += \
./amazon-freertos/portable/fsl_tickless_systick.d \
./amazon-freertos/portable/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
amazon-freertos/portable/%.o: ../amazon-freertos/portable/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DSDK_OS_FREE_RTOS -DFSL_RTOS_FREE_RTOS -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"/home/rufusy/robotic_arm/board" -I"/home/rufusy/robotic_arm/source" -I"/home/rufusy/robotic_arm" -I"/home/rufusy/robotic_arm/amazon-freertos/FreeRTOS/portable" -I"/home/rufusy/robotic_arm/amazon-freertos/portable" -I"/home/rufusy/robotic_arm/amazon-freertos/include" -I"/home/rufusy/robotic_arm/drivers" -I"/home/rufusy/robotic_arm/CMSIS" -I"/home/rufusy/robotic_arm/utilities" -I"/home/rufusy/robotic_arm/startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


