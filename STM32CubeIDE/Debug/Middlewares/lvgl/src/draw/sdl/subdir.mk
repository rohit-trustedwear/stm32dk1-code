################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

C_DEPS += \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 

OBJS += \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.o: C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.c Middlewares/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U5G9xx -c -I../../Core/Inc -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/lvgl" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares/ui" -I"C:/TouchGFXProjects/MyApplication_3/Middlewares" -I../../TouchGFX/App -I../../TouchGFX/Target/generated -I../../TouchGFX/Target -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I../../Drivers/BSP/STM32U5x9J-DK -I../../Drivers/BSP/Components/mx25um51245g -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../Middlewares/ST/touchgfx_components/gpu2d/NemaGFX/include -I../../Middlewares/ST/touchgfx_components/gpu2d/TouchGFXNema/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-Middlewares-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_layer.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.cyclo ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./Middlewares/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-Middlewares-2f-lvgl-2f-src-2f-draw-2f-sdl
