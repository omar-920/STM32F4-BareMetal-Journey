/*
 * GPIO_PROGRAM.c
 *
 * Created: 10/24/2026
 *  Author: Omar
 */ 

// *********************Include LIB Files****************************//
 #include "STD_TYPE.h"
 #include "BIT_MATH.h"
 // ********************Include GPIO Files****************************//
 #include "GPIO_INTERFACE.h"
 #include "GPIO_PRIVATE.h"

/* ================================================================ */
/* ===================== API IMPLEMENTATION ======================= */
/* ================================================================ */

Std_ReturnType MCAL_GPIO_Init(const GPIO_PinConfig_t *pPinConfig)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if(pPinConfig != NULL){
        GPIO_RegDef_t *Local_pGPIO = NULL;
        switch(pPinConfig->Port){
            case GPIO_PORT_A:
                Local_pGPIO = GPIOA;
                break;
            case GPIO_PORT_B:
                Local_pGPIO = GPIOB;
                break;
            case GPIO_PORT_C:
                Local_pGPIO = GPIOC;
                break;
            default:
                return E_NOT_OK; // Invalid port
        }

        // Configure mode
        Local_pGPIO->MODER &= ~(0b11 << (pPinConfig->Pin * 2)); // Clear mode bits
        Local_pGPIO->MODER |= (pPinConfig->Mode << (pPinConfig->Pin * 2)); // Set mode bits

        Local_pGPIO->PUPDR &= ~(0b11 << (pPinConfig->Pin * 2)); // Clear pull-up/pull-down bits
        Local_pGPIO->PUPDR |= (pPinConfig->PullUpPullDown << (pPinConfig->Pin * 2)); // Set pull-up/pull-down bits
    
        if(pPinConfig->Mode == GPIO_MODE_OUTPUT || pPinConfig->Mode == GPIO_MODE_AF){
            // Configure output type
            Local_pGPIO->OTYPER &= ~(0b1 << pPinConfig->Pin); // Clear output type bit
            Local_pGPIO->OTYPER |= (pPinConfig->OutputType << pPinConfig->Pin); // Set output type bit
            // Configure speed
            Local_pGPIO->OSPEEDR &= ~(0b11 << (pPinConfig->Pin * 2)); // Clear speed bits
            Local_pGPIO->OSPEEDR |= (pPinConfig->Speed << (pPinConfig->Pin * 2)); // Set speed bits
        }
        Local_FunctionStatus = E_OK;
    }
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_GPIO_SetPinValue(u8 Copy_Port, u8 Copy_Pin, u8 Copy_Value)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    GPIO_RegDef_t *Local_pGPIO = NULL;

    switch(Copy_Port){
        case GPIO_PORT_A:
            Local_pGPIO = GPIOA;
            break;
        case GPIO_PORT_B:
            Local_pGPIO = GPIOB;
            break;
        case GPIO_PORT_C:
            Local_pGPIO = GPIOC;
            break;
        default:
            return E_NOT_OK; // Invalid port
    }

    if(Copy_Value == GPIO_HIGH){
        Local_pGPIO->BSRR = (1 << Copy_Pin); // Set the pin
    } else if(Copy_Value == GPIO_LOW){
        Local_pGPIO->BSRR = (1 << (Copy_Pin + 16)); // Clear the pin
    } else {
        return E_NOT_OK; // Invalid value
    }

    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}
 
Std_ReturnType MCAL_GPIO_GetPinValue(u8 Copy_Port, u8 Copy_Pin, u8 *pValue)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    GPIO_RegDef_t *Local_pGPIO = NULL;

    if(pValue == NULL){
        return E_NOT_OK; // Null pointer check
    }

    switch(Copy_Port){
        case GPIO_PORT_A:
            Local_pGPIO = GPIOA;
            break;
        case GPIO_PORT_B:
            Local_pGPIO = GPIOB;
            break;
        case GPIO_PORT_C:
            Local_pGPIO = GPIOC;
            break;
        default:
            return E_NOT_OK; // Invalid port
    }

    *pValue = GET_BIT(Local_pGPIO->IDR, Copy_Pin);
    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_GPIO_TogglePin(u8 Copy_Port, u8 Copy_Pin)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    GPIO_RegDef_t *Local_pGPIO = NULL;

    switch(Copy_Port){
        case GPIO_PORT_A:
            Local_pGPIO = GPIOA;
            break;
        case GPIO_PORT_B:
            Local_pGPIO = GPIOB;
            break;
        case GPIO_PORT_C:
            Local_pGPIO = GPIOC;
            break;
        default:
            return E_NOT_OK; // Invalid port
    }

    TOG_BIT(Local_pGPIO->ODR, Copy_Pin);
    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}