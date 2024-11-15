/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

extern uint32_t X_PROFILER;
#include <stdio.h>

#include "FreeRTOS.h"
#include "queue.h"
#include "event_groups.h"


/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern QueueHandle_t TransmissionQueue;
extern EventGroupHandle_t xErrorEventGroup;
extern EventGroupHandle_t xWarningEventGroup;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#ifdef DEBUG
    #define DEBUG_PRINT(level, ...) printf("[" level "] " __VA_ARGS__)
#else
    #define DEBUG_PRINT(level, ...) // Do nothing
#endif

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define WIFI_EN_Pin GPIO_PIN_0
#define WIFI_EN_GPIO_Port GPIOE
#define TEMP_CS_Pin GPIO_PIN_12
#define TEMP_CS_GPIO_Port GPIOG
#define WIFI_D2_Pin GPIO_PIN_10
#define WIFI_D2_GPIO_Port GPIOC
#define WIFI_D0_Pin GPIO_PIN_8
#define WIFI_D0_GPIO_Port GPIOC
#define RLY2_ON_Pin GPIO_PIN_4
#define RLY2_ON_GPIO_Port GPIOE
#define HEATER_ON_Pin GPIO_PIN_1
#define HEATER_ON_GPIO_Port GPIOE
#define TOF_INTN_Pin GPIO_PIN_5
#define TOF_INTN_GPIO_Port GPIOB
#define DSI_RESETn_Pin GPIO_PIN_5
#define DSI_RESETn_GPIO_Port GPIOD
#define WIFI_CMD_Pin GPIO_PIN_2
#define WIFI_CMD_GPIO_Port GPIOD
#define WIFI_D3_Pin GPIO_PIN_11
#define WIFI_D3_GPIO_Port GPIOC
#define RLY1_ON_Pin GPIO_PIN_3
#define RLY1_ON_GPIO_Port GPIOE
#define WIFI_CLK_Pin GPIO_PIN_12
#define WIFI_CLK_GPIO_Port GPIOC
#define EEPROM_WP_Pin GPIO_PIN_6
#define EEPROM_WP_GPIO_Port GPIOH
#define WIFI_D1_Pin GPIO_PIN_9
#define WIFI_D1_GPIO_Port GPIOC
#define RLY3_ON_Pin GPIO_PIN_5
#define RLY3_ON_GPIO_Port GPIOE
#define DSI_BL_CTRL_Pin GPIO_PIN_6
#define DSI_BL_CTRL_GPIO_Port GPIOI
#define PUMP_SPLOW1_Pin GPIO_PIN_7
#define PUMP_SPLOW1_GPIO_Port GPIOD
#define LCDRST_Pin GPIO_PIN_7
#define LCDRST_GPIO_Port GPIOG
#define DRDY_Pin GPIO_PIN_6
#define DRDY_GPIO_Port GPIOG
#define PUMP_SPEED1_Pin GPIO_PIN_6
#define PUMP_SPEED1_GPIO_Port GPIOE
#define PUMP_ON_Pin GPIO_PIN_2
#define PUMP_ON_GPIO_Port GPIOE
#define LCDSTBY_Pin GPIO_PIN_8
#define LCDSTBY_GPIO_Port GPIOG
#define SPI1_NSS_Pin GPIO_PIN_5
#define SPI1_NSS_GPIO_Port GPIOG
#define USER_Button_Pin GPIO_PIN_13
#define USER_Button_GPIO_Port GPIOC
#define STEPA_STEP_Pin GPIO_PIN_0
#define STEPA_STEP_GPIO_Port GPIOF
#define STEPA_RESET_Pin GPIO_PIN_2
#define STEPA_RESET_GPIO_Port GPIOF
#define STEPA_DIR_Pin GPIO_PIN_1
#define STEPA_DIR_GPIO_Port GPIOF
#define STEPA_EN_Pin GPIO_PIN_4
#define STEPA_EN_GPIO_Port GPIOF
#define STEPA_SLEEP_Pin GPIO_PIN_3
#define STEPA_SLEEP_GPIO_Port GPIOF
#define HEARTBEAT_Pin GPIO_PIN_15
#define HEARTBEAT_GPIO_Port GPIOD
#define POOL_COVER_Pin GPIO_PIN_10
#define POOL_COVER_GPIO_Port GPIOF
#define STEPB_STEP_Pin GPIO_PIN_5
#define STEPB_STEP_GPIO_Port GPIOF
#define STEPB_RESET_Pin GPIO_PIN_7
#define STEPB_RESET_GPIO_Port GPIOF
#define STEPB_EN_Pin GPIO_PIN_9
#define STEPB_EN_GPIO_Port GPIOF
#define STEPB_DIR_Pin GPIO_PIN_6
#define STEPB_DIR_GPIO_Port GPIOF
#define STEPB_SLEEP_Pin GPIO_PIN_8
#define STEPB_SLEEP_GPIO_Port GPIOF
#define PUMP_SPEED3_Pin GPIO_PIN_8
#define PUMP_SPEED3_GPIO_Port GPIOE
#define CTP_RST_Pin GPIO_PIN_13
#define CTP_RST_GPIO_Port GPIOE
#define CTP_INT_Pin GPIO_PIN_12
#define CTP_INT_GPIO_Port GPIOD
#define CTP_INT_EXTI_IRQn EXTI12_IRQn
#define VBUS_SENSE_Pin GPIO_PIN_1
#define VBUS_SENSE_GPIO_Port GPIOG
#define PUMP_SPEED2_Pin GPIO_PIN_7
#define PUMP_SPEED2_GPIO_Port GPIOE
#define USB_ON_Pin GPIO_PIN_12
#define USB_ON_GPIO_Port GPIOE
#define PUMP_SPLOW2_Pin GPIO_PIN_8
#define PUMP_SPLOW2_GPIO_Port GPIOD
#define PUMP_FLOW_Pin GPIO_PIN_13
#define PUMP_FLOW_GPIO_Port GPIOD
#define ESPBOOT_Pin GPIO_PIN_14
#define ESPBOOT_GPIO_Port GPIOD
#define ORP_OUT_Pin GPIO_PIN_2
#define ORP_OUT_GPIO_Port GPIOC
#define PH_OUT_Pin GPIO_PIN_0
#define PH_OUT_GPIO_Port GPIOC
#define UCPD_ADC2_Pin GPIO_PIN_15
#define UCPD_ADC2_GPIO_Port GPIOF
#define BUZZ1_Pin GPIO_PIN_9
#define BUZZ1_GPIO_Port GPIOE
#define PUMP_SPEED4_Pin GPIO_PIN_10
#define PUMP_SPEED4_GPIO_Port GPIOE
#define BUZZ2_Pin GPIO_PIN_11
#define BUZZ2_GPIO_Port GPIOE
#define PUMP_SPLOW4_Pin GPIO_PIN_10
#define PUMP_SPLOW4_GPIO_Port GPIOD
#define PUMP_SPLOW3_Pin GPIO_PIN_9
#define PUMP_SPLOW3_GPIO_Port GPIOD
#define PUMP_24V_ENABLE_Pin GPIO_PIN_2
#define PUMP_24V_ENABLE_GPIO_Port GPIOB
#define UCPD_ADC1_Pin GPIO_PIN_0
#define UCPD_ADC1_GPIO_Port GPIOG
#define LCD_EN_Pin GPIO_PIN_14
#define LCD_EN_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
