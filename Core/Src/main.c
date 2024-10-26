/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "jpeg_utils_conf.h"
#include "cmsis_os2.h"
//#include "app_touchgfx.h"
#include "lvgl.h"
#include "ui.h"
#include "lv_conf.h"
#include "stm32u5x9j_discovery_ts.h"
//#include "Middlewares/lvgl_port_touch.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32u5x9j_discovery_hspi.h"
#include "stm32u5x9j_discovery_ospi.h"
#include "stm32u5x9j_discovery_ts.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

CRC_HandleTypeDef hcrc;

DCACHE_HandleTypeDef hdcache1;
DCACHE_HandleTypeDef hdcache2;

DMA2D_HandleTypeDef hdma2d;

DSI_HandleTypeDef hdsi;

GPU2D_HandleTypeDef hgpu2d;

XSPI_HandleTypeDef hxspi1;

JPEG_HandleTypeDef hjpeg;
DMA_HandleTypeDef handle_GPDMA1_Channel1;
DMA_HandleTypeDef handle_GPDMA1_Channel0;

LTDC_HandleTypeDef hltdc;

OSPI_HandleTypeDef hospi1;

TIM_HandleTypeDef htim8;

/* USER CODE BEGIN PV */

XSPI_HandleTypeDef xospi1;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
static void SystemPower_Config(void);
void MX_FREERTOS_Init(void);
static void MX_GPIO_Init(void);
static void MX_GPDMA1_Init(void);
static void MX_CRC_Init(void);
static void MX_TIM8_Init(void);
static void MX_DMA2D_Init(void);
static void MX_GPU2D_Init(void);
static void MX_DSIHOST_DSI_Init(void);
static void MX_LTDC_Init(void);
static void MX_OCTOSPI1_Init(void);
static void MX_HSPI1_Init(void);
static void MX_DCACHE1_Init(void);
static void MX_DCACHE2_Init(void);
static void MX_ICACHE_Init(void);
static void MX_JPEG_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/**********************
 *  STATIC VARIABLES
 **********************/

static bool _initialized = false;
static TS_State_t state = {0};  // Touch state structure from BSP

static lv_coord_t last_x = 0;
static lv_coord_t last_y = 0;
static lv_indev_state_t last_state = LV_INDEV_STATE_RELEASED;

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void
lvgl_touchscreen_read (lv_indev_drv_t *indev, lv_indev_data_t *data);

/* USER CODE END 0 */

/**********************
 *  STATIC PROTOTYPES
 **********************/



#define MY_DISP_HOR_RES    480
#define MY_DISP_VER_RES    480

static void disp_flush (lv_disp_drv_t*, const lv_area_t*, lv_color_t*);
//static void disp_flush_complete (DMA2D_HandleTypeDef*);

/**********************
 *  STATIC VARIABLES
 **********************/

static lv_disp_drv_t disp_drv;
static lv_disp_draw_buf_t disp_buf;

static __attribute__((aligned(32))) lv_color_t buf_1[MY_DISP_HOR_RES * 100];
//static __attribute__((aligned(32))) lv_color_t buf_2[MY_DISP_HOR_RES * 40];

//static __attribute__((section(".lvgl_buf"), aligned(32))) lv_color_t framebuffer[MY_DISP_HOR_RES * MY_DISP_VER_RES];

static __attribute__((aligned(32))) lv_color_t framebuffer[MY_DISP_HOR_RES * MY_DISP_VER_RES];
/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lvgl_display_init(void)
{
    /* Initialize display buffer */
	lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, MY_DISP_HOR_RES * MY_DISP_VER_RES);

    /* Initialize display driver */
    lv_disp_drv_init(&disp_drv);

    /* Set resolution of the display */
    disp_drv.hor_res = MY_DISP_HOR_RES;
    disp_drv.ver_res = MY_DISP_VER_RES;

    /* Register flush callback */
    disp_drv.flush_cb = disp_flush;

    /* Set display buffer */
    disp_drv.draw_buf = &disp_buf;

    /* Disable DSI wrapper before setting the frame buffer address */
    __HAL_DSI_WRAPPER_DISABLE(&hdsi);

    /* Set the LTDC frame buffer start address */
    HAL_LTDC_SetAddress(&hltdc, (uint32_t)framebuffer, 0);

    /* Re-enable DSI wrapper after setting the frame buffer */
    __HAL_DSI_WRAPPER_ENABLE(&hdsi);

    /* Register display driver */
    lv_disp_drv_register(&disp_drv);

    /* Enable the LCD, Send Display on DCS command to display */
    HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, DSI_SET_DISPLAY_ON, 0x00);

    /* Start PWM Timer channel for backlight */
    (void)HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_2);


    /* Enable Backlight by setting Brightness to 100% */
    __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, 2U * 100);
}


void
lvgl_touchscreen_init (void)
{
	if (!_initialized) {

	        TS_Init_t TsInit;

	        TsInit.Width = 480;
	        TsInit.Height = 480;
	        TsInit.Orientation = TS_ORIENTATION_PORTRAIT;
	        TsInit.Accuracy = 0;

	        if (BSP_TS_Init(0, &TsInit) == BSP_ERROR_NONE) {
	            _initialized = true;
	        }
	    }

	    /* Register the LVGL input device driver */
	    static lv_indev_drv_t indev_drv;
	    lv_indev_drv_init(&indev_drv);  // Initialize the driver

	    indev_drv.type = LV_INDEV_TYPE_POINTER;  // Set type to pointer
	    indev_drv.read_cb = lvgl_touchscreen_read;  // Set read callback

	    lv_indev_drv_register(&indev_drv);  // Register the driver with LVGL
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void
lvgl_touchscreen_read (lv_indev_drv_t  *indev,
                       lv_indev_data_t *data)
{
	 // Provide the last saved coordinates and state to LVGL
	    data->point.x = last_x;
	    data->point.y = last_y;
	    data->state = last_state;
}

/* Callback function for GPIO EXTI interrupt */
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == TS_INT_PIN) {  // Check for the correct interrupt pin
        if (_initialized) {
            if (BSP_TS_GetState(0, &state) == BSP_ERROR_NONE) {
                // Save the touch coordinates and state
                last_x = state.TouchX;
                last_y = state.TouchY;
                last_state = state.TouchDetected ? LV_INDEV_STATE_PRESSED : LV_INDEV_STATE_RELEASED;
            }
        }
    }
}

static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p)
{
    // Calculate the width and height of the area to copy
    lv_coord_t width = lv_area_get_width(area);
    lv_coord_t height = lv_area_get_height(area);

    // Calculate the destination address in the frame buffer
    uint32_t dstAddress = hltdc.LayerCfg[0].FBStartAdress +
                          2 * (area->y1 * MY_DISP_HOR_RES + area->x1);

    // Pointer to the destination in the frame buffer
    lv_color_t *dst_ptr = (lv_color_t *)dstAddress;

    // Pointer to the source buffer (provided by LVGL)
    lv_color_t *src_ptr = color_p;

    // Iterate over each row in the area
    for (lv_coord_t y = 0; y < height; y++)
    {
        // Copy one row of pixels from the source to the destination
        memcpy(dst_ptr, src_ptr, width * sizeof(lv_color_t));

        // Move the source pointer to the next row
        src_ptr += width;

        // Move the destination pointer to the next row in the frame buffer
        dst_ptr += MY_DISP_HOR_RES;
    }

    // Notify LVGL that the flush is ready
    lv_disp_flush_ready(drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

//static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p)
//{
//
//	    lv_coord_t width = lv_area_get_width(area);
//	    lv_coord_t height = lv_area_get_height(area);
//
//	    // Configure DMA2D for memory-to-memory transfer with RGB565
//	    DMA2D->CR = 0x0U << DMA2D_CR_MODE_Pos;  // Memory-to-Memory mode
//	    DMA2D->FGPFCCR = DMA2D_INPUT_RGB565;    // Input color format: RGB565
//	    DMA2D->FGMAR = (uint32_t)color_p;       // Source buffer address
//	    DMA2D->FGOR = 0;                        // No offset in input buffer
//	    DMA2D->OPFCCR = DMA2D_OUTPUT_RGB565;    // Output color format: RGB565
//	    DMA2D->OMAR = hltdc.LayerCfg[0].FBStartAdress +
//	                  2 * (area->y1 * MY_DISP_HOR_RES + area->x1);  // Frame buffer address
//	    DMA2D->OOR = MY_DISP_HOR_RES - width;  // Output offset for stride
//	    DMA2D->NLR = (width << DMA2D_NLR_PL_Pos) | (height << DMA2D_NLR_NL_Pos);  // Width and height
//	    DMA2D->IFCR = 0x3FU;                   // Clear all interrupt flags
//	    DMA2D->CR |= DMA2D_CR_TCIE;            // Enable transfer complete interrupt
//	    DMA2D->CR |= DMA2D_CR_START;           // Start DMA2D transfer
//
//}


//void configureInterrupts(void)
//{
//    NVIC_SetPriority(DSI_IRQn, 9);
//    NVIC_EnableIRQ(DSI_IRQn);
//
//    // New configurations for DMA2D interrupt
//    NVIC_SetPriority(DMA2D_IRQn, 9); // You can adjust the priority as needed
//    NVIC_EnableIRQ(DMA2D_IRQn);
//}


/**
  * @brief This function handles GPU2D Error interrupt.
  */
//void DMA2D_IRQHandler(void)
//{
//	//HAL_DMA2D_IRQHandler(&hdma2d);  // Handle the DMA2D interrupt
//    if (DMA2D->ISR & DMA2D_ISR_TCIF)
//    {
//        DMA2D->IFCR = DMA2D_IFCR_CTCIF; /* Clear the interrupt flag */
//        lv_disp_flush_ready(&disp_drv);  /* Notify LVGL that flush is complete */
//    }
//}

void LVGL_Task(void *argument)
{
    for(;;)
    {
        lv_task_handler();  // Handle LVGL tasks
        osDelay(5);         // Delay for 5ms
    }
}

#include "stm32u5xx_hal.h"  // Adjust the header file according to your STM32 series

#include "stm32u5xx_hal.h"

#include "stm32u5xx_hal.h"

void MPU_Config(void)
{
    MPU_Region_InitTypeDef MPU_InitStruct = {0};

    /* Disable the MPU before configuration */
    HAL_MPU_Disable();

    /* Configure MPU region for PSRAM1 (0xA0000000 - 0xA3FFFFFF) */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER0;                // Use MPU region 0
    MPU_InitStruct.BaseAddress = 0xA0000000;                   // Start address of PSRAM1
    MPU_InitStruct.LimitAddress = 0xA3FFFFFF;                  // End address of PSRAM1 (64MB)
    MPU_InitStruct.AttributesIndex = MPU_ATTRIBUTES_NUMBER0;   // Use default memory attribute 0
    MPU_InitStruct.AccessPermission = MPU_REGION_ALL_RW;  // Full read/write access
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;  // No code execution from PSRAM
    MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;     // Not shareable

    /* Configure the region with the given settings */
    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    /* Re-enable the MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}



/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{


  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();


  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */

  SystemClock_Config();

  /* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* Configure the System Power */
  SystemPower_Config();

  MPU_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_GPDMA1_Init();
  MX_CRC_Init();
  MX_TIM8_Init();
  MX_DMA2D_Init();
  MX_GPU2D_Init();
  MX_HSPI1_Init();
  MX_DSIHOST_DSI_Init();
  MX_LTDC_Init();
  MX_OCTOSPI1_Init();
  MX_DCACHE1_Init();
  MX_DCACHE2_Init();
  MX_ICACHE_Init();
  MX_JPEG_Init();
  //MX_TouchGFX_Init();
  /* Call PreOsInit function */
 // MX_TouchGFX_PreOSInit();
  /* USER CODE BEGIN 2 */

  //PSRAM_Test();
  /* initialize LVGL framework */
    lv_init();

    /* initialize display and touchscreen */
    lvgl_display_init();
    lvgl_touchscreen_init();
    //lvgl_touchscreen_init();

    ui_init();


    //configureInterrupts();

    /* Init scheduler */
     osKernelInitialize();

    // Create LVGL task
       osThreadAttr_t attr = {
           .name = "LVGL_Task",
           .priority = osPriorityHigh,
           .stack_size = 512 * 4
       };
       osThreadNew(LVGL_Task, NULL, &attr);
  /* USER CODE END 2 */



  /* Call init function for freertos objects (in cmsis_os2.c) */
  //MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_4;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLMBOOST = RCC_PLLMBOOST_DIV1;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 80;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLLVCIRANGE_0;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the common periph clock
  */
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LTDC|RCC_PERIPHCLK_DSI;
  PeriphClkInit.DsiClockSelection = RCC_DSICLKSOURCE_PLL3;
  PeriphClkInit.LtdcClockSelection = RCC_LTDCCLKSOURCE_PLL3;
  PeriphClkInit.PLL3.PLL3Source = RCC_PLLSOURCE_HSE;
  PeriphClkInit.PLL3.PLL3M = 4;
  PeriphClkInit.PLL3.PLL3N = 125;
  PeriphClkInit.PLL3.PLL3P = 8;
  PeriphClkInit.PLL3.PLL3Q = 2;
  PeriphClkInit.PLL3.PLL3R = 24;
  PeriphClkInit.PLL3.PLL3RGE = RCC_PLLVCIRANGE_0;
  PeriphClkInit.PLL3.PLL3FRACN = 0;
  PeriphClkInit.PLL3.PLL3ClockOut = RCC_PLL3_DIVP|RCC_PLL3_DIVR;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Power Configuration
  * @retval None
  */
static void SystemPower_Config(void)
{

  /*
   * Disable the internal Pull-Up in Dead Battery pins of UCPD peripheral
   */
  HAL_PWREx_DisableUCPDDeadBattery();

  /*
   * Switch to SMPS regulator instead of LDO
   */
  if (HAL_PWREx_ConfigSupply(PWR_SMPS_SUPPLY) != HAL_OK)
  {
    Error_Handler();
  }
/* USER CODE BEGIN PWR */
/* USER CODE END PWR */
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  hcrc.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_ENABLE;
  hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
  hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
  hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
  hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief DCACHE1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_DCACHE1_Init(void)
{

  /* USER CODE BEGIN DCACHE1_Init 0 */

  /* USER CODE END DCACHE1_Init 0 */

  /* USER CODE BEGIN DCACHE1_Init 1 */

  /* USER CODE END DCACHE1_Init 1 */
  hdcache1.Instance = DCACHE1;
  hdcache1.Init.ReadBurstType = DCACHE_READ_BURST_INCR;
  if (HAL_DCACHE_Init(&hdcache1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DCACHE1_Init 2 */

  /* USER CODE END DCACHE1_Init 2 */

}

/**
  * @brief DCACHE2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_DCACHE2_Init(void)
{

  /* USER CODE BEGIN DCACHE2_Init 0 */

  /* USER CODE END DCACHE2_Init 0 */

  /* USER CODE BEGIN DCACHE2_Init 1 */

  /* USER CODE END DCACHE2_Init 1 */
  hdcache2.Instance = DCACHE2;
  hdcache2.Init.ReadBurstType = DCACHE_READ_BURST_INCR;
  if (HAL_DCACHE_Init(&hdcache2) != HAL_OK)
  {
    Error_Handler();
  }
   __HAL_RCC_SYSCFG_CLK_ENABLE();
   HAL_SYSCFG_DisableSRAMCached();
  /* USER CODE BEGIN DCACHE2_Init 2 */

  /* USER CODE END DCACHE2_Init 2 */

}

/**
  * @brief DMA2D Initialization Function
  * @param None
  * @retval None
  */
static void MX_DMA2D_Init(void)
{

  /* USER CODE BEGIN DMA2D_Init 0 */

  /* USER CODE END DMA2D_Init 0 */

  /* USER CODE BEGIN DMA2D_Init 1 */

  /* USER CODE END DMA2D_Init 1 */
  hdma2d.Instance = DMA2D;
  hdma2d.Init.Mode = DMA2D_R2M;
  hdma2d.Init.ColorMode = DMA2D_OUTPUT_RGB565;
  hdma2d.Init.OutputOffset = 0;
  hdma2d.Init.BytesSwap = DMA2D_BYTES_REGULAR;
  hdma2d.Init.LineOffsetMode = DMA2D_LOM_PIXELS;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DMA2D_Init 2 */

  /* USER CODE END DMA2D_Init 2 */

}

/**
  * @brief DSIHOST Initialization Function
  * @param None
  * @retval None
  */
static void MX_DSIHOST_DSI_Init(void)
{

  /* USER CODE BEGIN DSIHOST_Init 0 */
  HAL_GPIO_WritePin(DSI_PWR_ON_GPIO_Port, DSI_PWR_ON_Pin, GPIO_PIN_SET);
  HAL_Delay(5);
  HAL_GPIO_WritePin(DSI_PWR_ON_GPIO_Port, DSI_PWR_ON_Pin, GPIO_PIN_RESET);
  HAL_Delay(11);
  /* USER CODE END DSIHOST_Init 0 */

  DSI_PLLInitTypeDef PLLInit = {0};
  DSI_HOST_TimeoutTypeDef HostTimeouts = {0};
  DSI_PHY_TimerTypeDef PhyTimings = {0};
  DSI_VidCfgTypeDef VidCfg = {0};

  /* USER CODE BEGIN DSIHOST_Init 1 */

  /* USER CODE END DSIHOST_Init 1 */
  hdsi.Instance = DSI;
  hdsi.Init.AutomaticClockLaneControl = DSI_AUTO_CLK_LANE_CTRL_DISABLE;
  hdsi.Init.TXEscapeCkdiv = 4;
  hdsi.Init.NumberOfLanes = DSI_TWO_DATA_LANES;
  hdsi.Init.PHYFrequencyRange = DSI_DPHY_FRANGE_450MHZ_510MHZ;
  hdsi.Init.PHYLowPowerOffset = PHY_LP_OFFSSET_0_CLKP;
  PLLInit.PLLNDIV = 125;
  PLLInit.PLLIDF = DSI_PLL_IN_DIV4;
  PLLInit.PLLODF = DSI_PLL_OUT_DIV2;
  PLLInit.PLLVCORange = DSI_DPHY_VCO_FRANGE_800MHZ_1GHZ;
  PLLInit.PLLChargePump = DSI_PLL_CHARGE_PUMP_2000HZ_4400HZ;
  PLLInit.PLLTuning = DSI_PLL_LOOP_FILTER_2000HZ_4400HZ;
  if (HAL_DSI_Init(&hdsi, &PLLInit) != HAL_OK)
  {
    Error_Handler();
  }
  HostTimeouts.TimeoutCkdiv = 1;
  HostTimeouts.HighSpeedTransmissionTimeout = 0;
  HostTimeouts.LowPowerReceptionTimeout = 0;
  HostTimeouts.HighSpeedReadTimeout = 0;
  HostTimeouts.LowPowerReadTimeout = 0;
  HostTimeouts.HighSpeedWriteTimeout = 0;
  HostTimeouts.HighSpeedWritePrespMode = DSI_HS_PM_DISABLE;
  HostTimeouts.LowPowerWriteTimeout = 0;
  HostTimeouts.BTATimeout = 0;
  if (HAL_DSI_ConfigHostTimeouts(&hdsi, &HostTimeouts) != HAL_OK)
  {
    Error_Handler();
  }
  PhyTimings.ClockLaneHS2LPTime = 11;
  PhyTimings.ClockLaneLP2HSTime = 40;
  PhyTimings.DataLaneHS2LPTime = 12;
  PhyTimings.DataLaneLP2HSTime = 23;
  PhyTimings.DataLaneMaxReadTime = 0;
  PhyTimings.StopWaitTime = 7;
  if (HAL_DSI_ConfigPhyTimer(&hdsi, &PhyTimings) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_ConfigFlowControl(&hdsi, DSI_FLOW_CONTROL_BTA) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_ConfigErrorMonitor(&hdsi, HAL_DSI_ERROR_NONE) != HAL_OK)
  {
    Error_Handler();
  }
  VidCfg.ColorCoding = DSI_RGB565;
  VidCfg.LooselyPacked = DSI_LOOSELY_PACKED_DISABLE;
  VidCfg.Mode = DSI_VID_MODE_BURST;
  VidCfg.PacketSize = 480;
  VidCfg.NumberOfChunks = 0;
  VidCfg.NullPacketSize = 0;
  VidCfg.HSPolarity = DSI_HSYNC_ACTIVE_HIGH;
  VidCfg.VSPolarity = DSI_VSYNC_ACTIVE_HIGH;
  VidCfg.DEPolarity = DSI_DATA_ENABLE_ACTIVE_HIGH;
  VidCfg.HorizontalSyncActive = 6;
  VidCfg.HorizontalBackPorch = 3;
  VidCfg.HorizontalLine = 1452;
  VidCfg.VerticalSyncActive = 20;
  VidCfg.VerticalBackPorch = 12;
  VidCfg.VerticalFrontPorch = 200;
  VidCfg.VerticalActive = 481;
  VidCfg.LPCommandEnable = DSI_LP_COMMAND_ENABLE;
  VidCfg.LPLargestPacketSize = 64;
  VidCfg.LPVACTLargestPacketSize = 0;
  VidCfg.LPHorizontalFrontPorchEnable = DSI_LP_HFP_ENABLE;
  VidCfg.LPHorizontalBackPorchEnable = DSI_LP_HBP_ENABLE;
  VidCfg.LPVerticalActiveEnable = DSI_LP_VACT_ENABLE;
  VidCfg.LPVerticalFrontPorchEnable = DSI_LP_VFP_ENABLE;
  VidCfg.LPVerticalBackPorchEnable = DSI_LP_VBP_ENABLE;
  VidCfg.LPVerticalSyncActiveEnable = DSI_LP_VSYNC_ENABLE;
  VidCfg.FrameBTAAcknowledgeEnable = DSI_FBTAA_ENABLE;
  if (HAL_DSI_ConfigVideoMode(&hdsi, &VidCfg) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_SetGenericVCID(&hdsi, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DSIHOST_Init 2 */

  // Start DSI
  if (HAL_DSI_Start(&hdsi) != HAL_OK)
  {
    Error_Handler();
  }

  /* Switch to DSI PHY PLL clock */
  RCC_PeriphCLKInitTypeDef PeriphClkInit;
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_DSI;
  PeriphClkInit.DsiClockSelection    = RCC_DSICLKSOURCE_DSIPHY;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);
  /* USER CODE END DSIHOST_Init 2 */

}

/**
  * @brief GPDMA1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPDMA1_Init(void)
{

  /* USER CODE BEGIN GPDMA1_Init 0 */

  /* USER CODE END GPDMA1_Init 0 */

  /* Peripheral clock enable */
  __HAL_RCC_GPDMA1_CLK_ENABLE();

  /* GPDMA1 interrupt Init */
    HAL_NVIC_SetPriority(GPDMA1_Channel0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(GPDMA1_Channel0_IRQn);
    HAL_NVIC_SetPriority(GPDMA1_Channel1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(GPDMA1_Channel1_IRQn);

  /* USER CODE BEGIN GPDMA1_Init 1 */

  /* USER CODE END GPDMA1_Init 1 */
  /* USER CODE BEGIN GPDMA1_Init 2 */

  /* USER CODE END GPDMA1_Init 2 */

}

/**
  * @brief GPU2D Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPU2D_Init(void)
{

  /* USER CODE BEGIN GPU2D_Init 0 */

  /* USER CODE END GPU2D_Init 0 */

  /* USER CODE BEGIN GPU2D_Init 1 */

  /* USER CODE END GPU2D_Init 1 */
  hgpu2d.Instance = GPU2D;
  if (HAL_GPU2D_Init(&hgpu2d) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN GPU2D_Init 2 */

  /* USER CODE END GPU2D_Init 2 */

}

/**
  * @brief HSPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_HSPI1_Init(void)
{

  /* USER CODE BEGIN HSPI1_Init 0 */
#if 0 // Disable the HSPI initialization code generated by CubeMX
  /* USER CODE END HSPI1_Init 0 */

  /* USER CODE BEGIN HSPI1_Init 1 */

  /* USER CODE END HSPI1_Init 1 */
  /* HSPI1 parameter configuration*/
  hxspi1.Instance = HSPI1;
  hxspi1.Init.FifoThresholdByte = 2;
  hxspi1.Init.MemoryMode = HAL_XSPI_SINGLE_MEM;
  hxspi1.Init.MemoryType = HAL_XSPI_MEMTYPE_APMEM_16BITS;
  hxspi1.Init.MemorySize = HAL_XSPI_SIZE_512MB;
  hxspi1.Init.ChipSelectHighTimeCycle = 1;
  hxspi1.Init.FreeRunningClock = HAL_XSPI_FREERUNCLK_DISABLE;
  hxspi1.Init.ClockMode = HAL_XSPI_CLOCK_MODE_0;
  hxspi1.Init.WrapSize = HAL_XSPI_WRAP_32_BYTES;
  hxspi1.Init.ClockPrescaler = 0;
  hxspi1.Init.SampleShifting = HAL_XSPI_SAMPLE_SHIFT_NONE;
  hxspi1.Init.DelayHoldQuarterCycle = HAL_XSPI_DHQC_DISABLE;
  hxspi1.Init.ChipSelectBoundary = HAL_XSPI_BONDARYOF_64KB;
  hxspi1.Init.MaxTran = 0;
  hxspi1.Init.Refresh = 0;
  if (HAL_XSPI_Init(&hxspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN HSPI1_Init 2 */
#endif
  BSP_HSPI_RAM_Cfg_t sHSPI_Init;

  sHSPI_Init.LatencyType      = BSP_HSPI_RAM_FIXED_LATENCY;
  sHSPI_Init.BurstType        = BSP_HSPI_RAM_LINEAR_BURST;
  sHSPI_Init.BurstLength      = BSP_HSPI_RAM_BURST_16_BYTES;
  sHSPI_Init.ReadLatencyCode  = BSP_HSPI_RAM_READ_LATENCY_6;
  sHSPI_Init.WriteLatencyCode = BSP_HSPI_RAM_WRITE_LATENCY_6;
  sHSPI_Init.IOMode           = BSP_HSPI_RAM_IO_X16_MODE;

  if (BSP_HSPI_RAM_Init(0, &sHSPI_Init) != BSP_ERROR_NONE)
  {
    printf("\r\nHSPI RAM Initialization : Failed");
    printf("\r\nHSPI RAM Test Aborted");
    printf("\r\n");
    Error_Handler();
  }

  if(BSP_HSPI_RAM_EnableMemoryMappedMode(0) != BSP_ERROR_NONE)
  {
    printf("\r\nHSPI RAM Mem-Mapped Cfg : Failed");
    printf("\r\nHSPI RAM Test Aborted");
    printf("\r\n");
    Error_Handler();
  }
  /* USER CODE END HSPI1_Init 2 */

}

/**
  * @brief ICACHE Initialization Function
  * @param None
  * @retval None
  */
static void MX_ICACHE_Init(void)
{

  /* USER CODE BEGIN ICACHE_Init 0 */

  /* USER CODE END ICACHE_Init 0 */

  /* USER CODE BEGIN ICACHE_Init 1 */

  /* USER CODE END ICACHE_Init 1 */

  /** Enable instruction cache in 1-way (direct mapped cache)
  */
  if (HAL_ICACHE_ConfigAssociativityMode(ICACHE_1WAY) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_ICACHE_Enable() != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ICACHE_Init 2 */

  /* USER CODE END ICACHE_Init 2 */

}

/**
  * @brief JPEG Initialization Function
  * @param None
  * @retval None
  */
static void MX_JPEG_Init(void)
{

  /* USER CODE BEGIN JPEG_Init 0 */

  /* USER CODE END JPEG_Init 0 */

  /* USER CODE BEGIN JPEG_Init 1 */

  /* USER CODE END JPEG_Init 1 */
  hjpeg.Instance = JPEG;
  if (HAL_JPEG_Init(&hjpeg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN JPEG_Init 2 */

  /* USER CODE END JPEG_Init 2 */

}

/**
  * @brief LTDC Initialization Function
  * @param None
  * @retval None
  */
static void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */

  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AH;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AH;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 1;
  hltdc.Init.VerticalSync = 19;
  hltdc.Init.AccumulatedHBP = 2;
  hltdc.Init.AccumulatedVBP = 31;
  hltdc.Init.AccumulatedActiveW = 482;
  hltdc.Init.AccumulatedActiveH = 512;
  hltdc.Init.TotalWidth = 483;
  hltdc.Init.TotalHeigh = 712;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 480;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 480;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  pLayerCfg.Alpha = 255;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;
  pLayerCfg.FBStartAdress = (uint32_t)framebuffer;;
  pLayerCfg.ImageWidth = 480;
  pLayerCfg.ImageHeight = 480;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */
  HAL_Delay(10);
  HAL_DSI_EnterULPM(&hdsi);
  HAL_Delay(10);

  HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_RESET);
  HAL_Delay(10);
  HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_SET);
  HAL_Delay(150);

  HAL_DSI_ExitULPM(&hdsi);
  HAL_Delay(10);

  // CMD Mode
  uint8_t InitParam1[3] = {0xFF ,0x83 , 0x79};
  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 3, 0xB9, InitParam1) != HAL_OK)
  {
    Error_Handler();
  }

  // SETPOWER
  uint8_t InitParam3[16] = {0x44,0x1C,0x1C,0x37,0x57,0x90,0xD0,0xE2,0x58,0x80,0x38,0x38,0xF8,0x33,0x34,0x42};
  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 16, 0xB1, InitParam3) != HAL_OK)
  {
    Error_Handler();
  }

  // SETDISP
  uint8_t InitParam4[9] = {0x80,0x14,0x0C,0x30,0x20,0x50,0x11,0x42,0x1D};
  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 9, 0xB2, InitParam4) != HAL_OK)
  {
    Error_Handler();
  }

  // Set display cycle timing
  uint8_t InitParam5[10] = {0x01,0xAA,0x01,0xAF,0x01,0xAF,0x10,0xEA,0x1C,0xEA};
  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 10, 0xB4, InitParam5) != HAL_OK)
  {
    Error_Handler();
  }

  // SETVCOM
  uint8_t InitParam60[4] = {00,00,00,0xC0};
  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 4, 0xC7, InitParam60) != HAL_OK)
  {
    Error_Handler();
  }

  // Set Panel Related Registers
  if (HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, 0xCC, 0x02) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, 0xD2, 0x77) != HAL_OK)
  {
    Error_Handler();
  }

  uint8_t InitParam50[37] = {
    0x00,0x07,0x00,0x00,0x00,0x08,0x08,0x32,0x10,0x01,0x00,0x01,0x03,0x72,0x03,0x72,0x00,0x08,0x00,
    0x08,0x33,0x33,0x05,0x05,0x37,0x05,0x05,0x37,0x0A,0x00,0x00,0x00,0x0A,0x00,0x01,0x00,0x0E
  };

  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 37, 0xD3, InitParam50) != HAL_OK)
  {
    Error_Handler();
  }

  uint8_t InitParam51[34] = {
    0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x19,0x19,0x18,0x18,0x18,0x18,0x19,0x19,0x01,0x00,
    0x03,0x02,0x05,0x04,0x07,0x06,0x23,0x22,0x21,0x20,0x18,0x18,0x18,0x18,0x00,0x00
  };

  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 34, 0xD5, InitParam51) != HAL_OK)
  {
    Error_Handler();
  }

  uint8_t InitParam52[35] = {
    0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x19,0x19,0x18,0x18,0x19,0x19,0x18,0x18,0x06,0x07,
    0x04,0x05,0x02,0x03,0x00,0x01,0x20,0x21,0x22,0x23,0x18,0x18,0x18,0x18
  };

  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 35, 0xD6, InitParam52) != HAL_OK)
  {
    Error_Handler();
  }

  // SET GAMMA
  uint8_t InitParam8[42] = {
    0x00,0x16,0x1B,0x30,0x36,0x3F,0x24,0x40,0x09,0x0D,0x0F,0x18,0x0E,0x11,0x12,0x11,0x14,0x07,
    0x12,0x13,0x18,0x00,0x17,0x1C,0x30,0x36,0x3F,0x24,0x40,0x09,0x0C,0x0F,0x18,0x0E,0x11,0x14,
    0x11,0x12,0x07,0x12,0x14,0x18
  };

  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 42, 0xE0, InitParam8) != HAL_OK)
  {
    Error_Handler();
  }

  uint8_t InitParam44[3] = {0x2C,0x2C,00};
  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 3, 0xB6, InitParam44) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, 0xBD, 0x00) != HAL_OK)
  {
    Error_Handler();
  }

  uint8_t InitParam14[] = {
    0x01,0x00,0x07,0x0F,0x16,0x1F,0x27,0x30,0x38,0x40,0x47,0x4E,0x56,0x5D,0x65,0x6D,0x74,0x7D,
    0x84,0x8A,0x90,0x99,0xA1,0xA9,0xB0,0xB6,0xBD,0xC4,0xCD,0xD4,0xDD,0xE5,0xEC,0xF3,0x36,0x07,
    0x1C,0xC0,0x1B,0x01,0xF1,0x34,0x00
  };

  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 42, 0xC1, InitParam14) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, 0xBD, 0x01) != HAL_OK)
  {
    Error_Handler();
  }

  uint8_t InitParam15[] = {
    0x00,0x08,0x0F,0x16,0x1F,0x28,0x31,0x39,0x41,0x48,0x51,0x59,0x60,0x68,0x70,0x78,0x7F,0x87,
    0x8D,0x94,0x9C,0xA3,0xAB,0xB3,0xB9,0xC1,0xC8,0xD0,0xD8,0xE0,0xE8,0xEE,0xF5,0x3B,0x1A,0xB6,
    0xA0,0x07,0x45,0xC5,0x37,0x00
  };

  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 42, 0xC1, InitParam15) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, 0xBD, 0x02) != HAL_OK)
  {
    Error_Handler();
  }

  uint8_t InitParam20[42] = {
    0x00,0x09,0x0F,0x18,0x21,0x2A,0x34,0x3C,0x45,0x4C,0x56,0x5E,0x66,0x6E,0x76,0x7E,0x87,0x8E,
    0x95,0x9D,0xA6,0xAF,0xB7,0xBD,0xC5,0xCE,0xD5,0xDF,0xE7,0xEE,0xF4,0xFA,0xFF,0x0C,0x31,0x83,
    0x3C,0x5B,0x56,0x1E,0x5A,0xFF
  };

  if (HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 42, 0xC1, InitParam20) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P1, 0xBD, 0x00) != HAL_OK)
  {
    Error_Handler();
  }

  // Exit Sleep Mode
  if (HAL_DSI_ShortWrite(&hdsi, 0, DSI_DCS_SHORT_PKT_WRITE_P0, DSI_EXIT_SLEEP_MODE, 0x00) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_Delay(120);
  /* USER CODE END LTDC_Init 2 */

}

/**
  * @brief OCTOSPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_OCTOSPI1_Init(void)
{

  /* USER CODE BEGIN OCTOSPI1_Init 0 */
#if 0 // Disable the HSPI initialization code generated by CubeMX
  /* USER CODE END OCTOSPI1_Init 0 */

  OSPIM_CfgTypeDef sOspiManagerCfg = {0};
  HAL_OSPI_DLYB_CfgTypeDef HAL_OSPI_DLYB_Cfg_Struct = {0};

  /* USER CODE BEGIN OCTOSPI1_Init 1 */

  /* USER CODE END OCTOSPI1_Init 1 */
  /* OCTOSPI1 parameter configuration*/
  hospi1.Instance = OCTOSPI1;
  hospi1.Init.FifoThreshold = 4;
  hospi1.Init.DualQuad = HAL_OSPI_DUALQUAD_DISABLE;
  hospi1.Init.MemoryType = HAL_OSPI_MEMTYPE_MACRONIX;
  hospi1.Init.DeviceSize = 27;
  hospi1.Init.ChipSelectHighTime = 2;
  hospi1.Init.FreeRunningClock = HAL_OSPI_FREERUNCLK_DISABLE;
  hospi1.Init.ClockMode = HAL_OSPI_CLOCK_MODE_0;
  hospi1.Init.WrapSize = HAL_OSPI_WRAP_NOT_SUPPORTED;
  hospi1.Init.ClockPrescaler = 1;
  hospi1.Init.SampleShifting = HAL_OSPI_SAMPLE_SHIFTING_NONE;
  hospi1.Init.DelayHoldQuarterCycle = HAL_OSPI_DHQC_ENABLE;
  hospi1.Init.ChipSelectBoundary = 0;
  hospi1.Init.DelayBlockBypass = HAL_OSPI_DELAY_BLOCK_USED;
  hospi1.Init.MaxTran = 0;
  hospi1.Init.Refresh = 0;
  if (HAL_OSPI_Init(&hospi1) != HAL_OK)
  {
    Error_Handler();
  }
  sOspiManagerCfg.ClkPort = 1;
  sOspiManagerCfg.DQSPort = 1;
  sOspiManagerCfg.NCSPort = 1;
  sOspiManagerCfg.IOLowPort = HAL_OSPIM_IOPORT_1_LOW;
  sOspiManagerCfg.IOHighPort = HAL_OSPIM_IOPORT_1_HIGH;
  if (HAL_OSPIM_Config(&hospi1, &sOspiManagerCfg, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_OSPI_DLYB_Cfg_Struct.Units = 0;
  HAL_OSPI_DLYB_Cfg_Struct.PhaseSel = 0;
  if (HAL_OSPI_DLYB_SetConfig(&hospi1, &HAL_OSPI_DLYB_Cfg_Struct) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OCTOSPI1_Init 2 */
#endif
  BSP_OSPI_NOR_Info_t sOSPI_NOR_Info;
  BSP_OSPI_NOR_Init_t sOSPI_NOR_Init;

  int32_t status;

  memset(&sOSPI_NOR_Info, 0, sizeof(sOSPI_NOR_Info));
  memset(&sOSPI_NOR_Init, 0, sizeof(sOSPI_NOR_Init));

  sOSPI_NOR_Init.InterfaceMode = BSP_OSPI_NOR_OPI_MODE;
  sOSPI_NOR_Init.TransferRate  = BSP_OSPI_NOR_DTR_TRANSFER;

  status = BSP_OSPI_NOR_Init(0, &sOSPI_NOR_Init);

  if (status != BSP_ERROR_NONE)
  {
    printf("\r\nOSPI NOR Initialization : Failed");
    printf("\r\nOSPI NOR Test Aborted");
    printf("\r\n");
  }

  BSP_OSPI_NOR_GetInfo(0, &sOSPI_NOR_Info);

  if (BSP_OSPI_NOR_EnableMemoryMappedMode(0) != BSP_ERROR_NONE)
  {
    printf("\r\nOSPI NOR Mem-Mapped Cfg : Failed");
    printf("\r\nOSPI NOR Test Aborted");
    printf("\r\n");
  }
  /* USER CODE END OCTOSPI1_Init 2 */

}

/**
  * @brief TIM8 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM8_Init(void)
{

  /* USER CODE BEGIN TIM8_Init 0 */

  /* USER CODE END TIM8_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM8_Init 1 */

  /* USER CODE END TIM8_Init 1 */
  htim8.Instance = TIM8;
  htim8.Init.Prescaler = 18;
  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim8.Init.Period = 139;
  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim8.Init.RepetitionCounter = 0;
  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim8, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 100;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.BreakAFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.Break2AFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim8, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM8_Init 2 */

  /* USER CODE END TIM8_Init 2 */
  HAL_TIM_MspPostInit(&htim8);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOJ_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LED_GREEN_Pin|LED_RED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DSI_PWR_ON_GPIO_Port, DSI_PWR_ON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, VSYNC_FREQ_Pin|RENDER_TIME_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, MCU_ACTIVE_Pin|FRAME_RATE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_GREEN_Pin LED_RED_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_Pin|LED_RED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_RESET_Pin VSYNC_FREQ_Pin RENDER_TIME_Pin */
  GPIO_InitStruct.Pin = LCD_RESET_Pin|VSYNC_FREQ_Pin|RENDER_TIME_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : DSI_PWR_ON_Pin */
  GPIO_InitStruct.Pin = DSI_PWR_ON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DSI_PWR_ON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USER_BUTTON_Pin */
  GPIO_InitStruct.Pin = USER_BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_BUTTON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DSI_TOUCH_INT_Pin */
  GPIO_InitStruct.Pin = DSI_TOUCH_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(DSI_TOUCH_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MCU_ACTIVE_Pin FRAME_RATE_Pin */
  GPIO_InitStruct.Pin = MCU_ACTIVE_Pin|FRAME_RATE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI8_IRQn, 10, 0);
  HAL_NVIC_EnableIRQ(EXTI8_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
  lv_tick_inc(1);
  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
