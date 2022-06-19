################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_HOST/Target/subdir.mk
-include USB_HOST/App/subdir.mk
-include Middlewares/Third_Party/LibJPEG/source/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/subdir.mk
-include LIBJPEG/Target/subdir.mk
-include LIBJPEG/App/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/gui/subdir.mk
-include Core/Src/fonts/subdir.mk
-include Core/Src/bsp/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := F746disco-audio-processing-RTOS-TP-SIA
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F746disco-audio-processing-RTOS-TP-SIA.elf \

MAP_FILES += \
F746disco-audio-processing-RTOS-TP-SIA.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F746disco-audio-processing-RTOS-TP-SIA.list \


# All Target
all: main-build

# Main-build Target
main-build: F746disco-audio-processing-RTOS-TP-SIA.elf secondary-outputs

# Tool invocations
F746disco-audio-processing-RTOS-TP-SIA.elf F746disco-audio-processing-RTOS-TP-SIA.map: $(OBJS) $(USER_OBJS) C:\projet\Projet_stm32\Projet\ Audio\ 11\ mai\ 2022\Projet\ Audio\ 11\ mai\ 2022\F746disco-audio-processing-RTOS-TP-SIA\STM32F746NGHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "F746disco-audio-processing-RTOS-TP-SIA.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\projet\Projet_stm32\Projet Audio 11 mai 2022\Projet Audio 11 mai 2022\F746disco-audio-processing-RTOS-TP-SIA\STM32F746NGHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="F746disco-audio-processing-RTOS-TP-SIA.map" -Wl,--gc-sections -static -L"C:\projet\Projet_stm32\Projet Audio 11 mai 2022\Projet Audio 11 mai 2022\F746disco-audio-processing-RTOS-TP-SIA\Drivers\CMSIS\Lib\GCC" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F746disco-audio-processing-RTOS-TP-SIA.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F746disco-audio-processing-RTOS-TP-SIA.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) F746disco-audio-processing-RTOS-TP-SIA.elf F746disco-audio-processing-RTOS-TP-SIA.list F746disco-audio-processing-RTOS-TP-SIA.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
