/*
 * clock.c
 *
 *  Created on: 07.01.2017
 *      Author: mlokc
 */

#include "../hal.h"
#include "stm32f0xx_hal.h"

#include "drivers/clock.h"

void SystemClock_Config(void){

    HAL_RCC_DeInit();
    HAL_RCC_EnableCSS();

    RCC_ClkInitTypeDef RCC_ClkInitStruct;

    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;

    RCC_PLLInitTypeDef RCC_PLLInitStruct;

    RCC_PLLInitStruct.PLLMUL = HAL_RCC_PLL_MUL;
    RCC_PLLInitStruct.PLLSource = HAL_RCC_PLL_SOURCE;
    RCC_PLLInitStruct.PLLState = HAL_RCC_PLL_STATE;
    RCC_PLLInitStruct.PREDIV = HAL_RCC_PLL_PREIV;

    RCC_OscInitTypeDef RCC_OscInitStruct;

    RCC_OscInitStruct.HSEState = HAL_RCC_HSE_STATE;
    RCC_OscInitStruct.HSI14CalibrationValue = RCC_HSI14CALIBRATION_DEFAULT;
    RCC_OscInitStruct.HSI14State = RCC_HSI14_OFF;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.HSIState = HAL_RCC_HSI_STATE;
    RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
    RCC_OscInitStruct.LSIState = RCC_LSI_OFF;
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.PLL = RCC_PLLInitStruct;

    HAL_RCC_OscConfig(&RCC_OscInitStruct);
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);
}

