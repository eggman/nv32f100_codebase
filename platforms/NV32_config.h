/******************************************************************************
*
* NOTE:系统所使用的一些宏定义，以及时钟模式的选择。
******************************************************************************/

#ifndef _NVxx_CONFIG_H_
#define _NVxx_CONFIG_H_


#include <stdint.h>

#define CPU_NV32
#define TEST


#define TRIM_IRC                    /*!< 是否使用定义的TRIM值来校准内部IRC，若注释则使用出厂校准的TRIM值出厂校准至37.5K--48M */
#define SPI0_PINREMAP               /*!< SPI0的管脚映射定义 */
//#define ENABLE_WDOG               /*!< 使能看门狗 */
//#define DISABLE_NMI               /*!< 禁用NMI中断输入引脚 */

/*! 定义是否打印系统信息 */      
#define PRINT_SYS_LOG           

#if     !defined(BOOT_LOADER)
#endif

//#define OUTPUT_BUSCLK             /*!< 定义是否输出系统时钟，输出引脚为PH2 */
#define ICS_TRIM_VALUE  0x2c   


    /*! 定义时钟的时钟模式以及频率
     */
   //#define USE_FEE                         /*!< 使用外部时钟FEE模式 */
   //#define USE_FEE_OSC                     /*!< 使用外部时钟输入OSC模式 */
     #define USE_FEI                         /*!< 使用系统内部时钟IRC */
  // #define USE_FBELP	
   //#define USE_FBE_OSC

   /*! 定义外部晶振频率. */
   //#define EXT_CLK_FREQ_KHZ	32          /* in KHz */
   //#define EXT_CLK_FREQ_KHZ	4000        /* in KHz */
   //#define EXT_CLK_FREQ_KHZ	4000        /* in KHz */
   //#define EXT_CLK_FREQ_KHZ	1000        /* in KHz */
     #define EXT_CLK_FREQ_KHZ	10000       /* in KHz */
    /*! 定义所使用的UART口 */
    #define TERM_PORT   UART1               /*!< 定义使用UART1口，开发板上默认使用UART1口 */


    /* 定义总线时钟主频 */
    #if	defined(USE_FEI)
        #define  BUS_CLK_HZ		48000000L
    #elif  (EXT_CLK_FREQ_KHZ == 10000)
        #define  BUS_CLK_HZ		50000000L
    #elif  (EXT_CLK_FREQ_KHZ == 12000)
        #define  BUS_CLK_HZ   30000000L
    #elif  (EXT_CLK_FREQ_KHZ == 8000)
        #define  BUS_CLK_HZ		24000000L
    #elif  (EXT_CLK_FREQ_KHZ == 4000)
        #define  BUS_CLK_HZ		40000000L
    #elif  (EXT_CLK_FREQ_KHZ == 32)
        #define  BUS_CLK_HZ		16777216L
    #else   
        #define  BUS_CLK_HZ		60000000L
    #endif

    /*! define UART baud rate */
    #define UART_PRINT_BITRATE              115200      /*! UART波特率 */

/*! 
 * 板载LED
 *  
 */
#define LED0_Init()            	GPIOB->PDDR |= (1<<25)  //初始化
#define LED0_Toggle()           GPIOB->PTOR  = (1<<25)  //翻转
#define LED0_On()               GPIOB->PCOR  = (1<<25)  //置位
#define LED0_Off()              GPIOB->PSOR  = (1<<25)  //清零

#define LED1_Init()            	GPIOB->PDDR |= (1<<26)  
#define LED1_Toggle()           GPIOB->PTOR  = (1<<26)
#define LED1_On()               GPIOB->PCOR  = (1<<26)
#define LED1_Off()              GPIOB->PSOR  = (1<<26)

#define LED2_Init()            	GPIOB->PDDR |= (1<<7)     
#define LED2_Toggle()           GPIOB->PTOR  = (1<<7)
#define LED2_On()               GPIOB->PCOR  = (1<<7)
#define LED2_Off()              GPIOB->PSOR  = (1<<7)

#define RED_Init()              LED2_Init()
#define RED_Set()               LED2_Off()
#define RED_Clear()             LED2_On()
#define RED_Toggle()            LED2_Toggle()

#define GREEN_Init()            LED0_Init()
#define GREEN_Set()             LED0_Off()
#define GREEN_Clear()           LED0_On()
#define GREEN_Toggle()          LED0_Toggle()

#define BLUE_Init()             LED1_Init()
#define BLUE_Set()              LED1_Off()
#define BLUE_Clear()            LED1_On()
#define BLUE_Toggle()           LED1_Toggle()


#endif /* NVxx_CONFIG_H_ */
