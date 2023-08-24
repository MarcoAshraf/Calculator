#ifndef DIO_H_
#define DIO_H_

#include "BITWISE_OPERATIONS.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

typedef enum
{
    PORTA = 0,
    PORTB = 1,
    PORTC = 2,
    PORTD = 3,
    PORTE = 4,
    PORTF = 5

}PORTS;

void DIO_INIT(PORTS PORT, uint8_t OUTPUT, uint8_t INPUT);

void DIO_WRITE(PORTS PORT, uint8_t PIN, uint8_t Value);



#endif /* DIO_H_ */
