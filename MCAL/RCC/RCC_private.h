/*
 * RCC_PRIVATE.h
 *
 * Created: 10/11/2026 12:10:08 AM
 *  Author: Omar
 */ 

#ifndef RCC_PRIVATE_H_  
#define RCC_PRIVATE_H_
#include "STD_TYPES.h"

typedef struct
{
    volatile u32 CR;          /* Offset: 0x00 */
    volatile u32 PLLCFGR;     /* Offset: 0x04 */
    volatile u32 CFGR;        /* Offset: 0x08 */
    volatile u32 CIR;         /* Offset: 0x0C */
    volatile u32 AHB1RSTR;    /* Offset: 0x10 */
    volatile u32 AHB2RSTR;    /* Offset: 0x14 */
    u32 Reserved1[2];         /* Offset: 0x18 - 0x1C */
    volatile u32 APB1RSTR;    /* Offset: 0x20 */
    volatile u32 APB2RSTR;    /* Offset: 0x24 */
    u32 Reserved2[2];         /* Offset: 0x28 - 0x2C */
    volatile u32 AHB1ENR;     /* Offset: 0x30 */
    volatile u32 AHB2ENR;     /* Offset: 0x34 */
    u32 Reserved3[2];         /* Offset: 0x38 - 0x3C */
    volatile u32 APB1ENR;     /* Offset: 0x40 */
    volatile u32 APB2ENR;     /* Offset: 0x44 */
    u32 Reserved4[10];        /* Offset: 0x48 - 0x6C */
    volatile u32 BDCR;        /* Offset: 0x70 */
    volatile u32 CSR;         /* Offset: 0x74 */
} RCC_RegDef_t;    
#define RCC_BASE_ADDRESS 0x40023800 /**< Base address of the RCC peripheral. */
#define RCC ((RCC_RegDef_t *)RCC_BASE_ADDRESS) /**< Pointer to the RCC peripheral structure. */
 

#define RCC_HSI             0   /**< High-Speed Internal Clock Source (HSI) */
#define RCC_HSE             1   /**< High-Speed External Clock Source (HSE) */
#define RCC_PLL             2   /**< Phase-Locked Loop Clock Source (PLL) */


#define RCC_CR_HSION 0
#define RCC_CR_HSIRDY 1
#define RCC_CR_HSICAL 8
#define RCC_CR_HSEON 16
#define RCC_CR_HSERDY 17
#define RCC_CR_HSEBYP 18
#define RCC_CR_CSSON 19
#define RCC_CR_PLLON 24
#define RCC_CR_PLLRDY 25


#define RCC_PLLCFGR_PLLSRC 22

/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTAL_CLK_    0   /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK_         1   /**< RC Oscillator Clock Type */

/** @} */ // end of RCC_Clock_Type


/* AHB Prescaler Options (HPRE bits in RCC_CFGR) */
#define RCC_AHB_DIV1           0b0000  /* 0: system clock not divided */
#define RCC_AHB_DIV2           0b1000  /* 8: system clock divided by 2 */
#define RCC_AHB_DIV4           0b1001  /* 9: system clock divided by 4 */
#define RCC_AHB_DIV8           0b1010  /* 10: system clock divided by 8 */
#define RCC_AHB_DIV16          0b1011  /* 11: system clock divided by 16 */

/* APB1 & APB2 Prescaler Options (PPRE1/PPRE2 bits in RCC_CFGR) */
#define RCC_APB_DIV1           0b000   /* 0: HCLK not divided */
#define RCC_APB_DIV2           0b100   /* 4: HCLK divided by 2 */
#define RCC_APB_DIV4           0b101   /* 5: HCLK divided by 4 */
#define RCC_APB_DIV8           0b110   /* 6: HCLK divided by 8 */
#define RCC_APB_DIV16          0b111   /* 7: HCLK divided by 16 */

#endif /* RCC_PRIVATE_H_ */