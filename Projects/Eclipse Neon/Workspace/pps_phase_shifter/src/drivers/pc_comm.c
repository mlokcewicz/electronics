/*
 * pc_comm.c
 *
 *  Created on: 07.01.2017
 *      Author: mlokc
 */

#include "../hal.h"
#include "drivers/pc_comm.h"
#include "stm32f0xx_hal.h"

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart1_rx;

void pc_comm_init(void)
{
    huart1.Instance = USART1;
    huart1.Init.BaudRate = HAL_USART_BAUDRATE;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

    if(HAL_UART_Init(&huart1) != HAL_OK)
    {
        //error
    }
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_InitStruct.Alternate = GPIO_AF1_USART1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pin = HAL_USART_TX_PIN | HAL_USART_RX_PIN;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(HAL_USART_PORT,&GPIO_InitStruct);

    __HAL_RCC_DMA1_CLK_ENABLE();

    HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);

    hdma_usart1_tx.Instance = DMA1_Channel2;
    hdma_usart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_tx.Init.Mode = DMA_NORMAL;
    hdma_usart1_tx.Init.Priority = DMA_PRIORITY_LOW;
    if(HAL_DMA_Init(&hdma_usart1_tx) != HAL_OK)
    {
        //error;
    }

    __HAL_LINKDMA(huart, hdmatx, hdma_usart1_tx);

    hdma_usart1_rx.Instance = DMA1_Channel3;
    hdma_usart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc = DMA_MINC_DISABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_rx.Init.Mode = DMA_CIRCULAR;
    hdma_usart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    if(HAL_DMA_Init(&hdma_usart1_rx) != HAL_OK)
    {
        //error;
    }

    __HAL_LINKDMA(huart, hdmarx, hdma_usart1_rx);

/**
  * @brief  DeInitializes the PPP MSP.
  * @retval None
  */
}

bool pc_comm_send_data(uint8_t *data, uint32_t size)
{
   return HAL_UART_Transmit_DMA(&huart1, data, size) == HAL_OK;
}

bool pc_comm_reveive_data(uint8_t *data, uint32_t size)
{
   return HAL_UART_Receive_DMA(&huart1, data, size) == HAL_OK;
}




