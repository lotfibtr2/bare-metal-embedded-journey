#include<stdint.h>

#define GPIO    (*(gpio*)(0x4002 0000UL))


struct gpio
{
    volatile uint32_t MODER,OTYPER,OSPEEDR,PUPDR,IDR,ODR,BSRR,LCKR,AFRL[2];

};

void main ()
{
     // infinite loop 
    
}