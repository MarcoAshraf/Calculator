
#include "Keypad.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "GPIO_INTERRUPT.h"


void Keypad_INIT()
{
    DIO_INIT(PORTB, 0b11110000, 0b00001111);

    interrupt_init(PORTB, 0);
    interrupt_init(PORTB, 1);
    interrupt_init(PORTB, 2);
    interrupt_init(PORTB, 3);

}




