################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/ui/screens/subdir.mk
-include Middlewares/ui/components/subdir.mk
-include Middlewares/ui/subdir.mk
-include Middlewares/lvgl/src/widgets/subdir.mk
-include Middlewares/lvgl/src/misc/subdir.mk
-include Middlewares/lvgl/src/hal/subdir.mk
-include Middlewares/lvgl/src/font/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/win/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/tileview/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/tabview/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/spinner/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/spinbox/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/span/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/msgbox/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/meter/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/menu/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/list/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/led/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/keyboard/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/imgbtn/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/colorwheel/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/chart/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/calendar/subdir.mk
-include Middlewares/lvgl/src/extra/widgets/animimg/subdir.mk
-include Middlewares/lvgl/src/extra/themes/mono/subdir.mk
-include Middlewares/lvgl/src/extra/themes/default/subdir.mk
-include Middlewares/lvgl/src/extra/themes/basic/subdir.mk
-include Middlewares/lvgl/src/extra/others/snapshot/subdir.mk
-include Middlewares/lvgl/src/extra/others/msg/subdir.mk
-include Middlewares/lvgl/src/extra/others/monkey/subdir.mk
-include Middlewares/lvgl/src/extra/others/imgfont/subdir.mk
-include Middlewares/lvgl/src/extra/others/ime/subdir.mk
-include Middlewares/lvgl/src/extra/others/gridnav/subdir.mk
-include Middlewares/lvgl/src/extra/others/fragment/subdir.mk
-include Middlewares/lvgl/src/extra/libs/sjpg/subdir.mk
-include Middlewares/lvgl/src/extra/libs/rlottie/subdir.mk
-include Middlewares/lvgl/src/extra/libs/qrcode/subdir.mk
-include Middlewares/lvgl/src/extra/libs/png/subdir.mk
-include Middlewares/lvgl/src/extra/libs/gif/subdir.mk
-include Middlewares/lvgl/src/extra/libs/fsdrv/subdir.mk
-include Middlewares/lvgl/src/extra/libs/freetype/subdir.mk
-include Middlewares/lvgl/src/extra/libs/ffmpeg/subdir.mk
-include Middlewares/lvgl/src/extra/libs/bmp/subdir.mk
-include Middlewares/lvgl/src/extra/layouts/grid/subdir.mk
-include Middlewares/lvgl/src/extra/layouts/flex/subdir.mk
-include Middlewares/lvgl/src/extra/subdir.mk
-include Middlewares/lvgl/src/draw/swm341_dma2d/subdir.mk
-include Middlewares/lvgl/src/draw/sw/subdir.mk
-include Middlewares/lvgl/src/draw/stm32_dma2d/subdir.mk
-include Middlewares/lvgl/src/draw/sdl/subdir.mk
-include Middlewares/lvgl/src/draw/nxp/vglite/subdir.mk
-include Middlewares/lvgl/src/draw/nxp/pxp/subdir.mk
-include Middlewares/lvgl/src/draw/arm2d/subdir.mk
-include Middlewares/lvgl/src/draw/subdir.mk
-include Middlewares/lvgl/src/core/subdir.mk
-include Middlewares/lvgl/env_support/rt-thread/squareline/subdir.mk
-include Middlewares/lvgl/env_support/rt-thread/subdir.mk
-include Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/subdir.mk
-include Middlewares/RTOS2/CMSIS/RTOS2/Core/TZ_Non_Supported/subdir.mk
-include Drivers/STM32U5xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/STM32U5x9J-DK/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include Application/User/gui/subdir.mk
-include Application/User/generated/subdir.mk
-include Application/User/TouchGFX/Target/generated/subdir.mk
-include Application/User/TouchGFX/Target/subdir.mk
-include Application/User/TouchGFX/App/subdir.mk
-include Application/User/Startup/subdir.mk
-include Application/User/Core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := STM32U5G9J-DK1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32U5G9J-DK1.elf \

MAP_FILES += \
STM32U5G9J-DK1.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32U5G9J-DK1.list \


# All Target
all: main-build

# Main-build Target
main-build: STM32U5G9J-DK1.elf secondary-outputs

# Tool invocations
STM32U5G9J-DK1.elf STM32U5G9J-DK1.map: $(OBJS) $(USER_OBJS) C:\TouchGFXProjects\MyApplication_3\STM32CubeIDE\STM32U5G9NJHXQ_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "STM32U5G9J-DK1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m33 -T"C:\TouchGFXProjects\MyApplication_3\STM32CubeIDE\STM32U5G9NJHXQ_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32U5G9J-DK1.map" -Wl,--gc-sections -static -L../../Middlewares/ST/touchgfx/lib/core/cortex_m33/gcc -L../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/lib/core/cortex_m33/gcc -L../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/lib/cortex_m33/gcc --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32U5G9J-DK1.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32U5G9J-DK1.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) STM32U5G9J-DK1.elf STM32U5G9J-DK1.list STM32U5G9J-DK1.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
