################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fonts/font12.c \
../Core/Src/fonts/font16.c \
../Core/Src/fonts/font20.c \
../Core/Src/fonts/font24.c \
../Core/Src/fonts/font8.c 

OBJS += \
./Core/Src/fonts/font12.o \
./Core/Src/fonts/font16.o \
./Core/Src/fonts/font20.o \
./Core/Src/fonts/font24.o \
./Core/Src/fonts/font8.o 

C_DEPS += \
./Core/Src/fonts/font12.d \
./Core/Src/fonts/font16.d \
./Core/Src/fonts/font20.d \
./Core/Src/fonts/font24.d \
./Core/Src/fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fonts/%.o Core/Src/fonts/%.su: ../Core/Src/fonts/%.c Core/Src/fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DARM_MATH_CM7 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../LIBJPEG/App -I../LIBJPEG/Target -I../Drivers/CMSIS/DSP/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/Third_Party/LibJPEG/include -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fonts

clean-Core-2f-Src-2f-fonts:
	-$(RM) ./Core/Src/fonts/font12.d ./Core/Src/fonts/font12.o ./Core/Src/fonts/font12.su ./Core/Src/fonts/font16.d ./Core/Src/fonts/font16.o ./Core/Src/fonts/font16.su ./Core/Src/fonts/font20.d ./Core/Src/fonts/font20.o ./Core/Src/fonts/font20.su ./Core/Src/fonts/font24.d ./Core/Src/fonts/font24.o ./Core/Src/fonts/font24.su ./Core/Src/fonts/font8.d ./Core/Src/fonts/font8.o ./Core/Src/fonts/font8.su

.PHONY: clean-Core-2f-Src-2f-fonts

