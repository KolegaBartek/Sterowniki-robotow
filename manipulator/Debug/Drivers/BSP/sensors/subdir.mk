################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/sensors/stm32l476g_discovery.c \
../Drivers/BSP/sensors/stm32l476g_discovery_glass_lcd.c \
../Drivers/BSP/sensors/stm32l476g_discovery_gyroscope.c 

OBJS += \
./Drivers/BSP/sensors/stm32l476g_discovery.o \
./Drivers/BSP/sensors/stm32l476g_discovery_glass_lcd.o \
./Drivers/BSP/sensors/stm32l476g_discovery_gyroscope.o 

C_DEPS += \
./Drivers/BSP/sensors/stm32l476g_discovery.d \
./Drivers/BSP/sensors/stm32l476g_discovery_glass_lcd.d \
./Drivers/BSP/sensors/stm32l476g_discovery_gyroscope.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/sensors/%.o Drivers/BSP/sensors/%.su Drivers/BSP/sensors/%.cyclo: ../Drivers/BSP/sensors/%.c Drivers/BSP/sensors/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Drivers/BSP/Components/l3gd20 -I../Drivers/BSP/gyroscope -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-sensors

clean-Drivers-2f-BSP-2f-sensors:
	-$(RM) ./Drivers/BSP/sensors/stm32l476g_discovery.cyclo ./Drivers/BSP/sensors/stm32l476g_discovery.d ./Drivers/BSP/sensors/stm32l476g_discovery.o ./Drivers/BSP/sensors/stm32l476g_discovery.su ./Drivers/BSP/sensors/stm32l476g_discovery_glass_lcd.cyclo ./Drivers/BSP/sensors/stm32l476g_discovery_glass_lcd.d ./Drivers/BSP/sensors/stm32l476g_discovery_glass_lcd.o ./Drivers/BSP/sensors/stm32l476g_discovery_glass_lcd.su ./Drivers/BSP/sensors/stm32l476g_discovery_gyroscope.cyclo ./Drivers/BSP/sensors/stm32l476g_discovery_gyroscope.d ./Drivers/BSP/sensors/stm32l476g_discovery_gyroscope.o ./Drivers/BSP/sensors/stm32l476g_discovery_gyroscope.su

.PHONY: clean-Drivers-2f-BSP-2f-sensors

