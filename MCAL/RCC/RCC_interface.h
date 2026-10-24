/*
 * RCC_interface.h
 *
 * Created: 10/11/2026 12:10:08 AM
 *  Author: Omar
 */ 

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "STD_TYPES.h"

/**
 * @brief Available clock domains for peripheral clock configuration.
 */
#define RCC_AHB1                0 /**< Advanced High-performance Bus 1 (AHB1) domain. */
#define RCC_AHB2                1 /**< Advanced High-performance Bus 2 (AHB2) domain. */
#define RCC_APB1                2 /**< Advanced Peripheral Bus 1 (APB1) domain. */
#define RCC_APB2                3 /**< Advanced Peripheral Bus 2 (APB2) domain. */


#define RCC_AHB1ENR_GPIOAEN     0  
#define RCC_AHB1ENR_GPIOBEN     1 
#define RCC_AHB1ENR_GPIOCEN     2 
#define RCC_AHB1ENR_GPIODEN     3 
#define RCC_AHB1ENR_GPIOEEN     4 
#define RCC_AHB1ENR_GPIOHEN     7 
#define RCC_AHB1ENR_CRCEN       12 
#define RCC_AHB1ENR_DMA1EN      21 
#define RCC_AHB1ENR_DMA2EN      22 


#define RCC_AHB2ENR_OTGFSEN     7


#define RCC_APB1_TIM2EN         0
#define RCC_APB1_TIM3EN         1
#define RCC_APB1_TIM4EN         2
#define RCC_APB1_TIM5EN         3
#define RCC_APB1_WWDGEN         11
#define RCC_APB1_SPI2EN         14
#define RCC_APB1_SPI3EN         15
#define RCC_APB1_USART2EN       17
#define RCC_APB1_I2C1EN         21
#define RCC_APB1_I2C2EN         22
#define RCC_APB1_I2C3EN         23
#define RCC_APB1_PWREN          28


#define RCC_APB2_TIM1EN         0
#define RCC_APB2_USART1EN       4
#define RCC_APB2_USART6EN       5
#define RCC_APB2_ADC1EN         8
#define RCC_APB2_SDIOEN         11
#define RCC_APB2_SPI1EN         12
#define RCC_APB2_SPI4EN         13
#define RCC_APB2_SYSCFGEN       14
#define RCC_APB2_TIM9EN         16
#define RCC_APB2_TIM10EN        17
#define RCC_APB2_TIM11EN        18



/**
 * @defgroup RCC_API RCC APIs
 * @brief Functions for RCC (Reset and Clock Control) configuration.
 * @{
 */

/**
 * @brief Initialize the system clock configuration.
 *
 * This function initializes the system clock configuration according to the desired settings.
 * It should be called early in the program to properly configure the clock system.
 *
 * @return Std_ReturnType
 * @retval E_OK     Clock initialization successful.
 * @retval E_NOT_OK Clock initialization failed.
 */
Std_ReturnType MCAL_RCC_InitSysClock(void);

/**
 * @brief Enable a specific peripheral on a specific bus.
 *
 * This function enables a specific peripheral on a specific bus.
 *
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType
 * @retval E_OK     Peripheral enabling successful.
 * @retval E_NOT_OK Peripheral enabling failed.
 */
Std_ReturnType MCAL_RCC_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId);

/**
 * @brief Disable a specific peripheral.
 *
 * This function disables a previously enabled peripheral.
 * 
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType
 * @retval E_OK     Peripheral disabling successful.
 * @retval E_NOT_OK Peripheral disabling failed.
 */
Std_ReturnType MCAL_RCC_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId);

/**
 * @}
 */


#endif /* RCC_INTERFACE_H_ */