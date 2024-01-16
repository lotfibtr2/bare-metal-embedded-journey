#include<stdint.h>

/*Defining the adresses of registers*/
#define PERIPH_BASE           (0x40000000UL)
#define AHB1_PERIPH_OFFSET    (0x00020000UL)
#define AHB1_PERIPH_BASE     (PERIPH_BASE + AHB1_PERIPH_OFFSET)

#define GPIOA_OFFSET         (0x0000UL)
#define GPIOB_OFFSET         (0x0400UL)
#define GPIOC_OFFSET         (0x0800UL)
#define GPIOD_OFFSET         (0x0C00UL)
#define GPIOA_BASE           (AHB1_PERIPH_BASE + GPIOA_OFFSET)
#define GPIOB_BASE           (AHB1_PERIPH_BASE + GPIOB_OFFSET)
#define GPIOC_BASE           (AHB1_PERIPH_BASE + GPIOC_OFFSET)
#define GPIOD_BASE           (AHB1_PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET           (0x3800UL)
#define RCC_BASE	         (AHB1_PERIPH_BASE + RCC_OFFSET)
#define RCC_AHB1EN_OFFSET	 (0x30UL)
#define RCC_AHB1EN_R		 (*(volatile unsigned int *)(RCC_BASE + RCC_AHB1EN_OFFSET))

#define GPIOAEN              (1U << 0)
#define GPIOBEN              (1U << 1)
#define GPIOCEN              (1U << 2)
#define GPIODEN              (1U << 3)

#define GPIOx_MODER_OFFSET   (0x00UL)
#define GPIOA_MODE_R         (*(volatile unsigned int *)(GPIOA_BASE + GPIOx_MODER_OFFSET))
#define GPIOB_MODE_R         (*(volatile unsigned int *)(GPIOB_BASE + GPIOx_MODER_OFFSET))
#define GPIOC_MODE_R         (*(volatile unsigned int *)(GPIOC_BASE + GPIOx_MODER_OFFSET))
#define GPIOD_MODE_R         (*(volatile unsigned int *)(GPIOD_BASE + GPIOx_MODER_OFFSET))

#define GPIOA_ODR_OFFSET     (0x14UL)
#define GPIOB_ODR_OFFSET     (0x14UL)
#define GPIOC_ODR_OFFSET     (0x14UL)
#define GPIOD_ODR_OFFSET     (0x14UL)

#define GPIOA_OD_R           (*(volatile unsigned int *)(GPIOA_BASE + GPIOA_ODR_OFFSET))
#define GPIOB_OD_R           (*(volatile unsigned int *)(GPIOB_BASE + GPIOB_ODR_OFFSET))
#define GPIOC_OD_R           (*(volatile unsigned int *)(GPIOC_BASE + GPIOC_ODR_OFFSET))
#define GPIOD_OD_R           (*(volatile unsigned int *)(GPIOD_BASE + GPIOD_ODR_OFFSET))

#define PIN12                (1U << 12)
#define PIN13                (1U << 13)
#define PIN14                (1U << 14)
#define PIN15                (1U << 15)

#define LED3                 PIN13
#define LED4                 PIN12
#define LED5                 PIN14
#define LED6                 PIN15

#define __IO  				 volatile


typedef struct
{
  volatile uint32_t DUMMY[12];
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */

} RCC_TypeDef;

typedef struct
{
	volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */

} GPIO_TypeDef;

#define RCC 				((RCC_TypeDef *)RCC_BASE)
#define GPIOA 			    ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB 			    ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC 			    ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD 			    ((GPIO_TypeDef *)GPIOD_BASE)


int main(void)
{
    // set clock access to GPIOD
	RCC->AHB1ENR |= GPIODEN;
	// set OUTPUT mode to GPIOD
	for(int i = 24;i<=31;i+=2)
	{
		GPIOD->MODER |= (1U <<i );
		GPIOD->MODER &= ~(1U <<i+1);
	}


    while (1)
    {
    	GPIOD->ODR ^= LED6;
    	GPIOD->ODR ^= LED3;
    	GPIOD->ODR ^= LED4;
    	GPIOD->ODR ^= LED5;
    	for(int i = 0;i < 1000000 ; i++){}



        // Your main loop code goes here
    }

    // Typically, you would not reach this point, so you might want to return a value.
    return 0;
}






