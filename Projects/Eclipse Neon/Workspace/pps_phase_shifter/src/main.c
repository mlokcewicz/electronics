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
#include "stm32f0xx.h"

#include "drivers/clock.h"

int main(void){

    HAL_Init();
    SystemClock_Config();

    /**---------------------------------------------------*/

    volatile uint32_t dupa = HAL_RCC_GetSysClockFreq();

	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);

	for(;;)
	{
	    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	    HAL_Delay(500);
	}

    /**---------------------------------------------------*/

}
