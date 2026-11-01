/*
 * GPIO_PRIVATE.h
 *
 * Created: 10/24/2026
 *  Author: Omar
 */ 

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct GPIO_RegDef_t
{
    volatile u32 MODER;       /* Offset: 0x00 */
    volatile u32 OTYPER;      /* Offset: 0x04 */
    volatile u32 OSPEEDR;     /* Offset: 0x08 */
    volatile u32 PUPDR;       /* Offset: 0x0C */
    volatile u32 IDR;         /* Offset: 0x10 */
    volatile u32 ODR;         /* Offset: 0x14 */
    volatile u32 BSRR;        /* Offset: 0x18 */
    volatile u32 LCKR;        /* Offset: 0x1C */
    volatile u32 AFRL[2];      /* Offset: 0x20 - 0x24 */
    volatile u32 AFRH[2];      /* Offset: 0x24 - 0x28 */
} GPIO_RegDef_t;

#define GPIOA_BASE_ADDRESS 0x40020000U /**< Base address of GPIOA peripheral. */
#define GPIOB_BASE_ADDRESS 0x40020400U /**< Base address of GPIOB peripheral. */
#define GPIOC_BASE_ADDRESS 0x40020800U /**< Base address of GPIOC peripheral. */

#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE_ADDRESS) /**< Pointer to the GPIOA peripheral structure. */
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE_ADDRESS) /**< Pointer to the GPIOB peripheral structure. */
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE_ADDRESS) /**< Pointer to the GPIOC peripheral structure. */



#endif/*GPIO_PRIVATE_H_*/