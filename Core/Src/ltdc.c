/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ltdc.c
  * @brief   This file provides code for the configuration
  *          of the LTDC instances.
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
#include "ltdc.h"

/* USER CODE BEGIN 0 */
#include "dsihost.h"
void LCD_Init(void) {

    // Step 1: Set STBYB low to keep the display in standby mode initially
    HAL_GPIO_WritePin(LCDSTBY_GPIO_Port, LCDSTBY_Pin, GPIO_PIN_RESET);

    // Step 2: Ensure LCD_EN is low (disable display)
    HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);

    // Step 3: Perform a reset
    HAL_GPIO_WritePin(LCDRST_GPIO_Port, LCDRST_Pin, GPIO_PIN_RESET);
    HAL_Delay(10); // Wait for t_reset (10 ms) as specified

    // Step 4: Release the reset pin
    HAL_GPIO_WritePin(LCDRST_GPIO_Port, LCDRST_Pin, GPIO_PIN_SET);
    HAL_Delay(1); // Short delay to stabilize after releasing reset

    // Step 5: Bring STBYB high to exit standby mode
    HAL_GPIO_WritePin(LCDSTBY_GPIO_Port, LCDSTBY_Pin, GPIO_PIN_SET);
    HAL_Delay(1); // Wait for t_en (1 ms) after enabling standby

    // Step 6: Enable the LCD by setting LCD_EN high (if applicable in your setup)
    HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
    HAL_Delay(1); // Additional delay to stabilize after enabling LCD_EN

    // Optional: Add additional setup or configuration here if required by your display
}

#define DSI_SHORT
void ICN6211_Init(void) {
    HAL_StatusTypeDef status;
#ifdef DSI_LONG

    uint8_t param;

    param = 0xC1;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x7A, &param);
    if (status != HAL_OK) return;

    param = 0x20;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x20, &param);
    if (status != HAL_OK) return;

    param = 0x90;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x21, &param);
    if (status != HAL_OK) return;

    param = 0x13;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x22, &param);
    if (status != HAL_OK) return;

    param = 0x30;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x23, &param);
    if (status != HAL_OK) return;

    param = 0x08;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x24, &param);
    if (status != HAL_OK) return;

    param = 0x30;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x25, &param);
    if (status != HAL_OK) return;

    param = 0x00;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x26, &param);
    if (status != HAL_OK) return;

    param = 0x08;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x27, &param);
    if (status != HAL_OK) return;

    param = 0x04;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x28, &param);
    if (status != HAL_OK) return;

    param = 0x08;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x29, &param);
    if (status != HAL_OK) return;

    param = 0x80;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x34, &param);
    if (status != HAL_OK) return;

    param = 0x30;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x36, &param);
    if (status != HAL_OK) return;

    param = 0x29;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x86, &param);
    if (status != HAL_OK) return;

    param = 0xA0;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0xB5, &param);
    if (status != HAL_OK) return;

    param = 0xFF;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x5C, &param);
    if (status != HAL_OK) return;

    param = 0x01;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x2A, &param);
    if (status != HAL_OK) return;

    param = 0x92;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x56, &param);
    if (status != HAL_OK) return;

    param = 0x73;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x6B, &param);
    if (status != HAL_OK) return;

    param = 0x0C;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x69, &param);
    if (status != HAL_OK) return;

    param = 0x40;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x10, &param);
    if (status != HAL_OK) return;

    param = 0x88;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x11, &param);
    if (status != HAL_OK) return;

    param = 0x20;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0xB6, &param);
    if (status != HAL_OK) return;

    param = 0x20;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x51, &param);
    if (status != HAL_OK) return;

    param = 0x10;
    status = HAL_DSI_LongWrite(&hdsi, 0, DSI_DCS_LONG_PKT_WRITE, 1, 0x09, &param);
    if (status != HAL_OK) return;

#endif

#ifdef DSI_SHORT
    // Initialization sequence with DSI short write commands




    // Initialization sequence with DSI short write commands

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x7A, 0xC1);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x20, 0x20);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x21, 0x90);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x22, 0x13);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x23, 0x30);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x24, 0x08);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x25, 0x30);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x26, 0x00);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x27, 0x08);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x28, 0x04);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x29, 0x08);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x34, 0x80);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x36, 0x30);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x86, 0x29);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0xB5, 0xA0);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x5C, 0xFF);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x2A, 0x01);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x56, 0x92);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x6B, 0x73);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x69, 0x0C);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x10, 0x40);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x11, 0x88);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0xB6, 0x20);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;

    status = HAL_DSI_ShortWrite(&hdsi, 0, DSI_GEN_SHORT_PKT_WRITE_P1, 0x51, 0x20);  // Generic Short Write with 1 parameter
    if (status != HAL_OK) return;


#endif
}



/* USER CODE END 0 */

LTDC_HandleTypeDef hltdc;

/* LTDC init function */
void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */

  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IIPC;
  hltdc.Init.HorizontalSync = 7;
  hltdc.Init.VerticalSync = 3;
  hltdc.Init.AccumulatedHBP = 55;
  hltdc.Init.AccumulatedVBP = 11;
  hltdc.Init.AccumulatedActiveW = 855;
  hltdc.Init.AccumulatedActiveH = 491;
  hltdc.Init.TotalWidth = 903;
  hltdc.Init.TotalHeigh = 499;
  hltdc.Init.Backcolor.Blue = 255;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 800;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 480;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB888;
  pLayerCfg.Alpha = 255;
  pLayerCfg.Alpha0 = 255;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;
  pLayerCfg.FBStartAdress = 0;
  pLayerCfg.ImageWidth = 0;
  pLayerCfg.ImageHeight = 0;
  pLayerCfg.Backcolor.Blue = 255;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */





  HAL_DSI_EnterULPM(&hdsi);
  HAL_Delay(10);

  // Step 6: Proceed with ICN6211-specific initialization commands
  LCD_Init();
      ICN6211_Init(); // Initialize the ICN6211 driver with proper commands
      HAL_DSI_ExitULPM(&hdsi);
      HAL_Delay(10);
  /* USER CODE END LTDC_Init 2 */

}

void HAL_LTDC_MspInit(LTDC_HandleTypeDef* ltdcHandle)
{

  if(ltdcHandle->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspInit 0 */

  /* USER CODE END LTDC_MspInit 0 */
    /* LTDC clock enable */
    __HAL_RCC_LTDC_CLK_ENABLE();
  /* USER CODE BEGIN LTDC_MspInit 1 */

  /* USER CODE END LTDC_MspInit 1 */
  }
}

void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef* ltdcHandle)
{

  if(ltdcHandle->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspDeInit 0 */

  /* USER CODE END LTDC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LTDC_CLK_DISABLE();
  /* USER CODE BEGIN LTDC_MspDeInit 1 */

  /* USER CODE END LTDC_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
