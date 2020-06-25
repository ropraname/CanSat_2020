################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/subdir.mk
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
CanSat_2020.lss \

FLASH_IMAGE += \
CanSat_2020.hex \

EEPROM_IMAGE += \
CanSat_2020.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: CanSat_2020.elf secondary-outputs

# Tool invocations
CanSat_2020.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CanSat_2020.map -Wl,-u,vfprintf -mmcu=atmega128 -o "CanSat_2020.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CanSat_2020.lss: CanSat_2020.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CanSat_2020.elf  >"CanSat_2020.lss"
	@echo 'Finished building: $@'
	@echo ' '

CanSat_2020.hex: CanSat_2020.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex CanSat_2020.elf  "CanSat_2020.hex"
	@echo 'Finished building: $@'
	@echo ' '

CanSat_2020.eep: CanSat_2020.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex CanSat_2020.elf  "CanSat_2020.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CanSat_2020.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 CanSat_2020.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CanSat_2020.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
