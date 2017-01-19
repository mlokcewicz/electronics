/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "hal.h"
#include "stm32f0xx_hal.h"

#include "drivers/pc_comm.h"

static void SystemClock_Config(void){

    HAL_RCC_DeInit();
    HAL_RCC_EnableCSS();

    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;

    RCC_OscInitStruct.HSEState = HAL_RCC_HSE_STATE;
    RCC_OscInitStruct.HSI14CalibrationValue = RCC_HSI14CALIBRATION_DEFAULT;
    RCC_OscInitStruct.HSI14State = RCC_HSI14_OFF;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.HSIState = HAL_RCC_HSI_STATE;
    RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = HAL_RCC_PLL_MUL;
    RCC_OscInitStruct.PLL.PLLSource = HAL_RCC_PLL_SOURCE;
    RCC_OscInitStruct.PLL.PLLState = HAL_RCC_PLL_STATE;
    RCC_OscInitStruct.PLL.PREDIV = HAL_RCC_PLL_PREIV;

    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;

    if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        //error
    }
    if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
    {
        //error
    }
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);
}

int main(void){

    HAL_Init();
    SystemClock_Config();

    pc_comm_init();

    /**---------------------------------------------------*/

    volatile uint32_t dupa = HAL_RCC_GetSysClockFreq();

	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = HAL_LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	HAL_GPIO_WritePin(HAL_LED_PORT, HAL_LED_PIN, GPIO_PIN_SET);
	uint8_t s_data[] = "HIT!\n";
	uint8_t r_data = 0;

	pc_comm_reveive_data(&r_data, 1);


	for(;;)
	{
	    HAL_GPIO_TogglePin(HAL_LED_PORT, HAL_LED_PIN);
	    HAL_Delay(500);

	    if(r_data == 'h' ){
	    pc_comm_send_data(s_data, strlen(s_data));
	    r_data = 0;
	    }
	}

    /**---------------------------------------------------*/

}
