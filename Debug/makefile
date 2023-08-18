################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/7_segment/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
EXTI_ITI.lss \

FLASH_IMAGE += \
EXTI_ITI.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: EXTI_ITI.elf secondary-outputs

# Tool invocations
EXTI_ITI.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,EXTI_ITI.map -mmcu=atmega32 -o "EXTI_ITI.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

EXTI_ITI.lss: EXTI_ITI.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EXTI_ITI.elf  >"EXTI_ITI.lss"
	@echo 'Finished building: $@'
	@echo ' '

EXTI_ITI.hex: EXTI_ITI.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex EXTI_ITI.elf  "EXTI_ITI.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EXTI_ITI.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 EXTI_ITI.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) EXTI_ITI.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
