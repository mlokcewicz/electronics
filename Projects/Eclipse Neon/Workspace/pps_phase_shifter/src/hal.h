/*
 * hal.h
 *
 *  Created on: 07.01.2017
 *      Author: mlokc
 */

#ifndef HAL_H_
#define HAL_H_

#define HAL_BOARD_TYPE                  1

/** 1 - STM32F0DISCOVERY
 *  2 - PPS_PHASE_SHIFTER_PCB_V100
 */

#if HAL_BOARD_TYPE == 1

/** RCC */
#define HAL_RCC_HSE_STATE               RCC_HSE_OFF
#define HAL_RCC_HSI_STATE               RCC_HSI_ON

#define HAL_RCC_PLL_MUL                 RCC_PLL_MUL6

#define HAL_RCC_PLL_SOURCE              RCC_PLLSOURCE_HSI
#define HAL_RCC_PLL_STATE               RCC_PLL_ON
#define HAL_RCC_PLL_PREIV               RCC_PREDIV_DIV1

/** USART */
#define HAL_USART_PORT                  GPIOA
#define HAL_USART_TX_PIN                GPIO_PIN_9
#define HAL_USART_RX_PIN                GPIO_PIN_10
#define HAL_USART_BAUDRATE              115200

/** SPI */
#define HAL_SPI_PORT                    GPIOA
#define HAL_SPI_NSS_PIN                 GPIO_PIN_4
#define HAL_SPI_SCK_PIN                 GPIO_PIN_5
#define HAL_SPI_MISO_PIN                GPIO_PIN_6
#define HAL_SPI_MOSI_PIN                GPIO_PIN_7

/** IO */
#define HAL_LED_PORT                    GPIOC
#define HAL_LED_PIN                     GPIO_PIN_8

#endif

#if HAL_BOARD_TYPE == 2

/** RCC */
#define HAL_RCC_HSE_STATE               RCC_HSE_ON
#define HAL_RCC_HSI_STATE               RCC_HSI_OFF

#define HAL_RCC_PLL_MUL                 RCC_PLL_MUL6

#define HAL_RCC_PLL_SOURCE              RCC_PLLSOURCE_HSE
#define HAL_RCC_PLL_STATE               RCC_PLL_ON
#define HAL_RCC_PLL_PREIV               RCC_PREDIV_DIV1

/** USART */
#define HAL_USART_PORT                  GPIOA
#define HAL_USART_TX_PIN                GPIO_PIN_2
#define HAL_USART_RX_PIN                GPIO_PIN_3

/** SPI */
#define HAL_SPI_PORT                    GPIOA
#define HAL_SPI_NSS_PIN                 GPIO_PIN_4
#define HAL_SPI_SCK_PIN                 GPIO_PIN_5
#define HAL_SPI_MISO_PIN                GPIO_PIN_6
#define HAL_SPI_MOSI_PIN                GPIO_PIN_7

/** IO */
#define HAL_LED_PORT                    GPIOB
#define HAL_LED_PIN                     GPIO_PIN_7

#endif

/** IO */
#define HAL_DDS_PS2_PORT                GPIOB
#define HAL_DDS_PS2_PIN                 GPIO_PIN_1

#define HAL_DDS_PS1_PORT                GPIOA
#define HAL_DDS_PS1_PIN                 GPIO_PIN_8

#define HAL_DDS_PS0_PORT                GPIOA
#define HAL_DDS_PS0_PIN                 GPIO_PIN_9

#define HAL_DDS_IO_UPDATE_PORT          GPIOA
#define HAL_DDS_IO_UPDATE_PIN           GPIO_PIN_10

#define HAL_DDS_PLL_LOCK_SYNC_IN_PORT   GPIOA
#define HAL_DDS_PLL_LOCK_SYNC_IN_PIN    GPIO_PIN_11

#define HAL_DDS_SYNC_OUT_PORT           GPIOA
#define HAL_DDS_SYNC_OUT_PIN            GPIO_PIN_12

#define HAL_DDS_RESET_PORT              GPIOA
#define HAL_DDS_RESET_PIN               GPIO_PIN_15

#define HAL_DDS_IO_RESET_PORT           GPIOB
#define HAL_DDS_IO_RESET_PIN            GPIO_PIN_3

#endif /* HAL_H_ */
