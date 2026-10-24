/*
 * RCC_program.c
 *
 * Created: 10/11/2026 12:10:08 AM
 *  Author: Omar
 */ 

// ********************Include LIB Files****************************//
 #include "STD_TYPE.h"
 #include "BIT_MATH.h"
 // ********************Include RCC Files****************************//
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

Std_ReturnType MCAL_RCC_InitSysClock(void){

    std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_SYSCLK == RCC_HSE
        #if RCC_CLK_BYPASS == RCC_RC_CLK_
            SET_BIT(RCC->CR, RCC_CR_HSEBYP);
        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
            CLR_BIT(RCC->CR, RCC_CR_HSEBYP);
        #else
            #error "Invalid RCC_CLK_BYPASS configuration. Please choose either RCC_RC_CLK_ or RCC_CRYSTAL_CLK_."
        #endif

        /**< Enable the High-Speed External clock. */
        SET_BIT(RCC->CR, RCC_CR_HSEON);\

        /**< Wait until the High-Speed External clock is stable. */
        while(!GET_BIT(RCC->CR, RCC_CR_HSERDY));

        RCC->CFGR &= ~(0b11 << 0);   /**< Clear the system clock source bits. */
        RCC->CFGR |= (0b01 << 0);    /**< Select HSE as the system clock source. */

        Local_FunctionStatus = E_OK;
    #elif RCC_SYSCLK == RCC_HSI
        /**< Enable the High-Speed Internal clock. */
        SET_BIT(RCC->CR, RCC_CR_HSION);

        /**< Wait until the High-Speed Internal clock is stable. */
        while(!GET_BIT(RCC->CR, RCC_CR_HSIRDY));

        RCC->CFGR &= ~(0b11 << 0);   /**< Clear the system clock source bits. */
        RCC->CFGR |= (0b00 << 0);    /**< Select HSI as the system clock source. */

        Local_FunctionStatus = E_OK;
    #elif RCC_SYSCLK == RCC_PLL
        #if RCC_PLL_CLK_SRC == RCC_PLL_HSI
            /**< Enable the High-Speed Internal clock. */
            SET_BIT(RCC->CR, RCC_CR_HSION);

            /**< Wait until the High-Speed Internal clock is stable. */
            while(!GET_BIT(RCC->CR, RCC_CR_HSIRDY));

            /**< Configure PLL to use HSI as the input clock source. */
            CLR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC); /**< Clear the PLL source bit to select HSI. */
        #elif RCC_PLL_CLK_SRC == RCC_PLL_HSE
            #if RCC_CLK_BYPASS == RCC_RC_CLK_
                SET_BIT(RCC->CR, RCC_CR_HSEBYP);
            #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
                CLR_BIT(RCC->CR, RCC_CR_HSEBYP);
            #else
                #error "Invalid RCC_CLK_BYPASS configuration. Please choose either RCC_RC_CLK_ or RCC_CRYSTAL_CLK_."
            #endif

            /**< Enable the High-Speed External clock. */
            SET_BIT(RCC->CR, RCC_CR_HSEON);

            /**< Wait until the High-Speed External clock is stable. */
            while(!GET_BIT(RCC->CR, RCC_CR_HSERDY));

            /**< Configure PLL to use HSE as the input clock source. */
            SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC); /**< Set the PLL source bit to select HSE. */
        #else
            #error "Invalid RCC_PLL_CLK_SRC configuration. Please choose either RCC_PLL_HSI or RCC_PLL_HSE."
        #endif

        /**< Configure PLL parameters (M, N, P, Q) as needed. */
        // Example: RCC->PLLCFGR = (M << 0) | (N << 6) | (P << 16) | (Q << 24);

        /**< Enable the PLL. */
        SET_BIT(RCC->CR, RCC_CR_PLLON);

        /**< Wait until the PLL is stable. */
        while(!GET_BIT(RCC->CR, RCC_CR_PLLRDY));

        RCC->CFGR &= ~(0b11 << 0);   /**< Clear the system clock source bits. */
        RCC->CFGR |= (0b10 << 0);    /**< Select PLL as the system clock source. */

        Local_FunctionStatus = E_OK;    
    #else
        #error "Invalid RCC_SYSCLK configuration. Please choose either RCC_HSE, RCC_HSI, or RCC_PLL."
    #endif    

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId){
    std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch(Copy_BusId){
        case RCC_AHB1:
            SET_BIT(RCC->AHB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;
        case RCC_AHB2:
            SET_BIT(RCC->AHB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;
        case RCC_APB1:
            SET_BIT(RCC->APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;
        case RCC_APB2:
            SET_BIT(RCC->APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK; // Invalid bus ID
            break;
    }
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId){
    std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch(Copy_BusId){
        case RCC_AHB1:
            CLR_BIT(RCC->AHB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;
        case RCC_AHB2:
            CLR_BIT(RCC->AHB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;
        case RCC_APB1:
            CLR_BIT(RCC->APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;
        case RCC_APB2:
            CLR_BIT(RCC->APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;
        default:
            Local_FunctionStatus = E_NOT_OK; // Invalid bus ID
            break;
    }
    return Local_FunctionStatus;
}
