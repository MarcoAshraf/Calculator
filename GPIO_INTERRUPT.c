#include "GPIO_INTERRUPT.h"

void interrupt_init(PORTS PORT, uint8_t Pin)
{
    switch(PORT)
    {
    case PORTA:
            SETBIT(NVIC_EN0_R, 0);
            CLEARBIT(GPIO_PORTA_IM_R, Pin);
            CLEARBIT(GPIO_PORTA_IS_R, Pin);
            CLEARBIT(GPIO_PORTA_IBE_R, Pin);
            CLEARBIT(GPIO_PORTA_IEV_R, Pin);
            SETBIT(GPIO_PORTA_ICR_R,Pin);
            SETBIT(GPIO_PORTA_IM_R, Pin);
            break;

    case PORTB:
            SETBIT(NVIC_EN0_R, 1);
            CLEARBIT(GPIO_PORTB_IM_R, Pin);
            CLEARBIT(GPIO_PORTB_IS_R, Pin);
            CLEARBIT(GPIO_PORTB_IBE_R, Pin);
            CLEARBIT(GPIO_PORTB_IEV_R, Pin);
            SETBIT(GPIO_PORTB_ICR_R,Pin);
            SETBIT(GPIO_PORTB_IM_R, Pin);
            break;

    case PORTC:
            SETBIT(NVIC_EN0_R, 2);
            CLEARBIT(GPIO_PORTC_IM_R, Pin);
            CLEARBIT(GPIO_PORTC_IS_R, Pin);
            CLEARBIT(GPIO_PORTC_IBE_R, Pin);
            CLEARBIT(GPIO_PORTC_IEV_R, Pin);
            SETBIT(GPIO_PORTC_ICR_R,Pin);
            SETBIT(GPIO_PORTC_IM_R, Pin);
            break;

    case PORTD:
            SETBIT(NVIC_EN0_R, 3);
            CLEARBIT(GPIO_PORTD_IM_R, Pin);
            CLEARBIT(GPIO_PORTD_IS_R, Pin);
            CLEARBIT(GPIO_PORTD_IBE_R, Pin);
            CLEARBIT(GPIO_PORTD_IEV_R, Pin);
            SETBIT(GPIO_PORTD_ICR_R,Pin);
            SETBIT(GPIO_PORTD_IM_R, Pin);
            break;

    case PORTE:
            SETBIT(NVIC_EN0_R, 4);
            CLEARBIT(GPIO_PORTE_IM_R, Pin);
            CLEARBIT(GPIO_PORTE_IS_R, Pin);
            CLEARBIT(GPIO_PORTE_IBE_R, Pin);
            CLEARBIT(GPIO_PORTE_IEV_R, Pin);
            SETBIT(GPIO_PORTE_ICR_R,Pin);
            SETBIT(GPIO_PORTE_IM_R, Pin);
            break;


    case PORTF:
            SETBIT(NVIC_EN0_R, 30);
            CLEARBIT(GPIO_PORTF_IM_R, Pin);
            CLEARBIT(GPIO_PORTF_IS_R, Pin);
            CLEARBIT(GPIO_PORTF_IBE_R, Pin);
            CLEARBIT(GPIO_PORTF_IEV_R, Pin);
            SETBIT(GPIO_PORTF_ICR_R,Pin);
            SETBIT(GPIO_PORTF_IM_R, Pin);
           break;


    }

}


