################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/devices/stm32l476g_discovery.c \
../Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.c \
../Drivers/BSP/devices/stm32l476g_discovery_gyroscope.c 

OBJS += \
./Drivers/BSP/devices/stm32l476g_discovery.o \
./Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.o \
./Drivers/BSP/devices/stm32l476g_discovery_gyroscope.o 

C_DEPS += \
./Drivers/BSP/devices/stm32l476g_discovery.d \
./Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.d \
./Drivers/BSP/devices/stm32l476g_discovery_gyroscope.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/devices/%.o Drivers/BSP/devices/%.su Drivers/BSP/devices/%.cyclo: ../Drivers/BSP/devices/%.c Drivers/BSP/devices/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Drivers/BSP/Components -I../Drivers/BSP/devices -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-devices

clean-Drivers-2f-BSP-2f-devices:
	-$(RM) ./Drivers/BSP/devices/stm32l476g_discovery.cyclo ./Drivers/BSP/devices/stm32l476g_discovery.d ./Drivers/BSP/devices/stm32l476g_discovery.o ./Drivers/BSP/devices/stm32l476g_discovery.su ./Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.cyclo ./Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.d ./Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.o ./Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.su ./Drivers/BSP/devices/stm32l476g_discovery_gyroscope.cyclo ./Drivers/BSP/devices/stm32l476g_discovery_gyroscope.d ./Drivers/BSP/devices/stm32l476g_discovery_gyroscope.o ./Drivers/BSP/devices/stm32l476g_discovery_gyroscope.su

.PHONY: clean-Drivers-2f-BSP-2f-devices

