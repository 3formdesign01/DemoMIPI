/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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
#include "cmsis_os2.h"
#include "crc.h"
#include "dcache.h"
#include "dsihost.h"
#include "i2c.h"
#include "icache.h"
#include "ltdc.h"
#include "memorymap.h"
#include "sdmmc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
static void SystemPower_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



#define I2C_TIMEOUT 1000  // Increased timeout duration for I2C communication in milliseconds
#define RETRY_COUNT 3     // Number of times to retry communication
#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 480
uint8_t frameBuffer[DISPLAY_WIDTH * DISPLAY_HEIGHT * 3]; // Correct size for 24-bit access per pixel

// Function to fill the screen with a specific color
void FillScreenWithColor(uint8_t red, uint8_t green, uint8_t blue, uint32_t n_pixels)
{
    uint8_t* tempBuffer = frameBuffer; // Use a temporary pointer for iteration

    while (n_pixels > 0)
    {
        *tempBuffer = blue;
        tempBuffer++;

        *tempBuffer = green;
        tempBuffer++;

        *tempBuffer = red;
        tempBuffer++;

        n_pixels--; // Decrement the pixel count
    }
}

// Function to display a color for a specific duration (milliseconds)
void DisplayColorTransition(uint8_t red, uint8_t green, uint8_t blue, uint32_t duration_ms)
{
    // Fill the frame buffer with the specified color
    FillScreenWithColor(red, green, blue, DISPLAY_WIDTH * DISPLAY_HEIGHT);

    // Update the LTDC display with the new frame buffer
    HAL_LTDC_SetAddress(&hltdc, (uint32_t)frameBuffer, 0);

    // Delay for the specified duration
    HAL_Delay(duration_ms);
}

// Function to check device response at specified address with retry logic
HAL_StatusTypeDef Check_I2C_Address(I2C_HandleTypeDef* hi2c, uint16_t DevAddress) {
    HAL_StatusTypeDef status = HAL_ERROR;
    for(int attempt = 0; attempt < RETRY_COUNT; attempt++) {
        status = HAL_I2C_IsDeviceReady(hi2c, DevAddress << 1, 1, I2C_TIMEOUT);
        if(status == HAL_OK) {
            break;
        }
    }
    return status;
}

void Test_I2C_Addresses(I2C_HandleTypeDef* hi2c) {
    uint16_t addresses[] = {0x70, 0x60, 0x38, 0x55};
    int address_count = sizeof(addresses) / sizeof(addresses[0]);

    for (int i = 0; i < address_count; i++) {
        HAL_StatusTypeDef result = Check_I2C_Address(hi2c, addresses[i]);
        if (result == HAL_OK) {
            printf("Device found at address 0x%X\n", addresses[i]);
        } else {
            printf("No response from address 0x%X after %d attempts\n", addresses[i], RETRY_COUNT);
        }
    }
}


// Function to initialize PWM with a specific duty cycle
void PWM_SetDutyCycle(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t dutyCycle)
{
    // Assuming dutyCycle is a percentage (0-100)
    uint32_t pulse = (dutyCycle * (htim->Init.Period + 1)) / 100;

    // Set the pulse value
    __HAL_TIM_SET_COMPARE(htim, channel, pulse);
}

// Function to gradually change the brightness
void Adjust_Brightness(TIM_HandleTypeDef *htim, uint32_t channel)
{
    for (uint16_t i = 0; i <= 100; i += 10) // Increase brightness
    {
        PWM_SetDutyCycle(htim, channel, i);
        HAL_Delay(1000); // Delay for 100 ms to see the change in brightness
    }

    for (uint16_t i = 100; i > 0; i -= 10) // Decrease brightness
    {
        PWM_SetDutyCycle(htim, channel, i);
        HAL_Delay(1000); // Delay for 100 ms to see the change in brightness
    }
}

// Declare global variables for storing touch coordinates
uint8_t touchCount;
uint32_t x, y, z, b;






long unsigned int getRunTimeCounterValue()
{

}



/* USER CODE END 0 */

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

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  MX_I2C5_Init();
  MX_ICACHE_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();

  MX_USART3_UART_Init();
  MX_TIM4_Init();
  MX_I2C3_Init();
  MX_USART1_UART_Init();
  MX_DCACHE1_Init();
  MX_DCACHE2_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM7_Init();
  MX_SPI3_Init();
  MX_DSIHOST_DSI_Init();
  MX_LTDC_Init();
//  MX_SDMMC2_SD_Init();
  MX_CRC_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);




	while(1)
	          		{


	          			DisplayColorTransition(255,0,0,500);
	          			DisplayColorTransition(0,255,0,500);
	          			DisplayColorTransition(0,0,255,500);
	          			DisplayColorTransition(0,0,0,500);
	          			DisplayColorTransition(255,255,255,500);

	          		}

//	RTC_WriteTime(&hrtc,24,MONTH_OCTOBER,WEEKDAY_MONDAY,28,15,18,0);
  /* USER CODE END 2 */

  /* Init scheduler */
//  osKernelInitialize();

  /* Call init function for freertos objects (in cmsis_os2.c) */
//  MX_FREERTOS_Init();

  /* Start scheduler */
//  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    vTaskStartScheduler();

	while (1) {
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE
                              |RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_4;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLMBOOST = RCC_PLLMBOOST_DIV1;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 80;
  RCC_OscInitStruct.PLL.PLLP = 50;
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
  PeriphClkInit.PLL3.PLL3M = 2;
  PeriphClkInit.PLL3.PLL3N = 52;
  PeriphClkInit.PLL3.PLL3P = 7;
  PeriphClkInit.PLL3.PLL3Q = 2;
  PeriphClkInit.PLL3.PLL3R = 15;
  PeriphClkInit.PLL3.PLL3RGE = RCC_PLLVCIRANGE_1;
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
  HAL_PWREx_EnableVddIO2();

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
	while (1) {
		printf("Error_Handler\r\n");
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
