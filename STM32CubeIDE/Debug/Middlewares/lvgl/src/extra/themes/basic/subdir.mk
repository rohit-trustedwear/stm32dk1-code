################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.c 

C_DEPS += \
./Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.d 

OBJS += \
./Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.c Middlewares/lvgl/src/extra/themes/basic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-lvgl-2f-src-2f-extra-2f-themes-2f-basic

clean-Middlewares-2f-lvgl-2f-src-2f-extra-2f-themes-2f-basic:
	-$(RM) ./Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.cyclo ./Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.d ./Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.o ./Middlewares/lvgl/src/extra/themes/basic/lv_theme_basic.su

.PHONY: clean-Middlewares-2f-lvgl-2f-src-2f-extra-2f-themes-2f-basic

