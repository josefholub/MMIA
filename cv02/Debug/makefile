################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

BUILD_ARTIFACT_NAME := cv02
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
cv02.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
cv02.list \

OBJCOPY_BIN += \
cv02.bin \


# All Target
all: main-build

# Main-build Target
main-build: cv02.elf secondary-outputs

# Tool invocations
cv02.elf: $(OBJS) $(USER_OBJS) D:\Documents\VUT\ FEKT\ BRNO\01\ FEKT\4\ YEAR\7\ SEMESTER\MKS\xholub39\MMIA\cv02\STM32F030R8TX_FLASH.ld
	arm-none-eabi-gcc -o "cv02.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"D:\Documents\VUT FEKT BRNO\01 FEKT\4 YEAR\7 SEMESTER\MKS\xholub39\MMIA\cv02\STM32F030R8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="cv02.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

cv02.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "cv02.list"
	@echo 'Finished building: $@'
	@echo ' '

cv02.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "cv02.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
