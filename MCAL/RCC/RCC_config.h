/*
 * RCC_config.h
 *
 * Created: 10/11/2026 12:10:08 AM
 *  Author: Omar
 */ 



#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */

 #define RCC_SYSCLK                 RCC_HSE  


 /**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */

 #if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS        RCC_CRYSTAL_CLK_
                                
#endif /**< RCC_SYSCLK */

#if RCC_SYSCLK == RCC_PLL
/**
    * @brief Configure the PLL input clock source when using RCC_PLL.
    * @note Choose one of the available options:
    *       RCC_PLL_HSI       - Use HSI as the PLL input clock source.
    *       RCC_PLL_HSE       - Use HSE as the PLL input clock source.
    */
    
#define RCC_PLL_CLK_SRC        RCC_PLL_HSE

/* 
     * Configure PLL factors (M, N, P, Q) 
     * Formula: f(VCO clock) = f(PLL clock input) × (N / M)
     *          f(PLL general clock output) = f(VCO clock) / P
     */
    #define RCC_PLL_M_VAL          8     /* Range: 2 to 63 */
    #define RCC_PLL_N_VAL          84    /* Range: 192 to 432 */
    #define RCC_PLL_P_VAL          2     /* Options: 2, 4, 6, 8 */
    #define RCC_PLL_Q_VAL          4     /* Range: 2 to 15 */

#endif /**< RCC_SYSCLK */

/**
 * @brief Configure the AHB, APB1, and APB2 prescalers.
 */
#define RCC_AHB_PRESCALER      RCC_AHB_DIV1   /* Options: DIV1, DIV2, DIV4, DIV8, DIV16... */
#define RCC_APB1_PRESCALER     RCC_APB_DIV2   /* Options: DIV1, DIV2, DIV4, DIV8, DIV16 */
#define RCC_APB2_PRESCALER     RCC_APB_DIV1   /* Options: DIV1, DIV2, DIV4, DIV8, DIV16 */

/** @} */ /* End of RCC_System_Clock_Config */





#endif /* RCC_CONFIG_H_ */