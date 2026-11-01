/*
 * GPIO_INTERFACE.h
 *
 * Created: 10/24/2026
 *  Author: Omar
 */ 

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#include "STD_TYPE.h"


#define GPIO_PORT_A                 0
#define GPIO_PORT_B                 1
#define GPIO_PORT_C                 2

#define GPIO_LOW                    0
#define GPIO_HIGH                   1

#define GPIO_PIN_0                  0
#define GPIO_PIN_1                  1
#define GPIO_PIN_2                  2
#define GPIO_PIN_3                  3
#define GPIO_PIN_4                  4
#define GPIO_PIN_5                  5
#define GPIO_PIN_6                  6
#define GPIO_PIN_7                  7
#define GPIO_PIN_8                  8
#define GPIO_PIN_9                  9
#define GPIO_PIN_10                 10
#define GPIO_PIN_11                 11
#define GPIO_PIN_12                 12
#define GPIO_PIN_13                 13
#define GPIO_PIN_14                 14
#define GPIO_PIN_15                 15

#define GPIO_MODE_INPUT             0b00
#define GPIO_MODE_OUTPUT            0b01
#define GPIO_MODE_AF                0b10
#define GPIO_MODE_ANALOG            0b11

#define GPIO_OUTPUT_PUSH_PULL       0
#define GPIO_OUTPUT_OPEN_DRAIN      1

#define GPIO_SPEED_LOW              0b00
#define GPIO_SPEED_MEDIUM           0b01
#define GPIO_SPEED_HIGH             0b10
#define GPIO_SPEED_VERY_HIGH        0b11

#define GPIO_PUPDR_NO_PULL          0b00
#define GPIO_PUPDR_PULL_UP          0b01
#define GPIO_PUPDR_PULL_DOWN        0b10
#define GPIO_PUPDR_RESERVED         0b11

typedef struct
{
    u8 Port;           /**< GPIO port number (0 for A, 1 for B, 2 for C). */
    u8 Pin;            /**< GPIO pin number (0 to 15). */
    u8 Mode;           /**< GPIO mode (input, output, alternate function, analog). */
    u8 OutputType;     /**< GPIO output type (push-pull or open-drain). */
    u8 Speed;          /**< GPIO speed (low, medium, high, very high). */
    u8 PullUpPullDown; /**< GPIO pull-up/pull-down configuration. */
} GPIO_PinConfig_t;



Std_ReturnType MCAL_GPIO_Init(const GPIO_PinConfig_t *pPinConfig);

Std_ReturnType MCAL_GPIO_SetPinValue(u8 Copy_Port, u8 Copy_Pin, u8 Copy_Value);

Std_ReturnType MCAL_GPIO_GetPinValue(u8 Copy_Port, u8 Copy_Pin, u8 *pValue);

Std_ReturnType MCAL_GPIO_TogglePin(u8 Copy_Port, u8 Copy_Pin);


#endif /* GPIO_INTERFACE_H_ */
