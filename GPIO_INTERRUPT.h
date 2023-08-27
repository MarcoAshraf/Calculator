#ifndef GPIO_INTERRUPT_H_
#define GPIO_INTERRUPT_H_
#include "BITWISE_OPERATIONS.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>


void interrupt_init(PORTS PORT, uint8_t Pin);



#endif /* GPIO_INTERRUPT_H_ */
