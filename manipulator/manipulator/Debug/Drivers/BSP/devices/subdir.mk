################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/devices/stm32l476g_discovery.c \
../Drivers/BSP/devices/stm32l476g_discovery_compass.c \
../Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.c 

OBJS += \
./Drivers/BSP/devices/stm32l476g_discovery.o \
./Drivers/BSP/devices/stm32l476g_discovery_compass.o \
./Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.o 

C_DEPS += \
./Drivers/BSP/devices/stm32l476g_discovery.d \
./Drivers/BSP/devices/stm32l476g_discovery_compass.d \
./Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/devices/stm32l476g_discovery.o: ../Drivers/BSP/devices/stm32l476g_discovery.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components -I../Drivers/BSP/devices -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/devices/stm32l476g_discovery.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/devices/stm32l476g_discovery_compass.o: ../Drivers/BSP/devices/stm32l476g_discovery_compass.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components -I../Drivers/BSP/devices -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/devices/stm32l476g_discovery_compass.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.o: ../Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components -I../Drivers/BSP/devices -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/devices/stm32l476g_discovery_glass_lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

