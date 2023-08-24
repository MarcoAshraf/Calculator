#include "DIO.h"



void DIO_INIT(PORTS PORT, uint8_t OUTPUT, uint8_t INPUT)
{

    SETBIT(SYSCTL_RCGCGPIO_R, PORT);
    while(!CHECKBIT(SYSCTL_RCGCGPIO_R, PORT)){};

    switch(PORT)
    {
    case PORTA:
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        GPIO_PORTA_CR_R = (OUTPUT | INPUT);
        GPIO_PORTA_DIR_R = OUTPUT;
        GPIO_PORTA_PUR_R = INPUT;
        GPIO_PORTA_DEN_R =(OUTPUT | INPUT);


        break;
    case PORTB:
        GPIO_PORTB_LOCK_R = 0x4C4F434B;
        GPIO_PORTB_CR_R = (OUTPUT | INPUT);
        GPIO_PORTB_DIR_R = OUTPUT;
        GPIO_PORTB_PUR_R = INPUT;
        GPIO_PORTB_DEN_R =(OUTPUT | INPUT);


        break;
    case PORTC:
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        GPIO_PORTC_CR_R = (OUTPUT | INPUT);
        GPIO_PORTC_DIR_R = OUTPUT;
        GPIO_PORTC_PUR_R = INPUT;
        GPIO_PORTC_DEN_R =(OUTPUT | INPUT);


        break;
    case PORTD:
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        GPIO_PORTD_CR_R = (OUTPUT | INPUT);
        GPIO_PORTD_DIR_R = OUTPUT;
        GPIO_PORTD_PUR_R = INPUT;
        GPIO_PORTD_DEN_R =(OUTPUT | INPUT);

        break;
    case PORTE:
        GPIO_PORTE_LOCK_R = 0x4C4F434B;
        GPIO_PORTE_CR_R = (OUTPUT | INPUT);
        GPIO_PORTE_DIR_R = OUTPUT;
        GPIO_PORTE_PUR_R = INPUT;
        GPIO_PORTE_DEN_R =(OUTPUT | INPUT);


        break;
    case PORTF:
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        GPIO_PORTF_CR_R = (OUTPUT | INPUT);
        GPIO_PORTF_DIR_R = OUTPUT;
        GPIO_PORTF_PUR_R = INPUT;
        GPIO_PORTF_DEN_R =(OUTPUT | INPUT);


        break;
    }
}

void DIO_WRITE(PORTS PORT, uint8_t PIN, uint8_t Value)
{

        switch(PORT)
          {
              case PORTA:
                  if(Value == 1)
                  {
                      GPIO_PORTA_DATA_BITS_R[1<<PIN] = 1<<PIN;
                  }
                  else
                  {
                      GPIO_PORTA_DATA_BITS_R[1<<PIN] = ~(1<<PIN);
                  }
              break;
              case PORTB:
                  if(Value == 1)
                  {
                      GPIO_PORTB_DATA_BITS_R[1<<PIN] = 1<<PIN;
                  }
                  else
                  {
                  GPIO_PORTB_DATA_BITS_R[1<<PIN] = ~(1<<PIN);
                  }
              break;
              case PORTC:

                  if(Value == 1)
                  {
                      GPIO_PORTC_DATA_BITS_R[1<<PIN] = 1<<PIN;
                  }
                  else
                  {
                      GPIO_PORTC_DATA_BITS_R[1<<PIN] = ~(1<<PIN);
                  }

              break;
              case PORTD:
                  if(Value == 1)
                  {
                      GPIO_PORTD_DATA_BITS_R[1<<PIN] = 1<<PIN;
                  }
                  else
                  {
                      GPIO_PORTD_DATA_BITS_R[1<<PIN] = ~(1<<PIN);
                  }

              break;
              case PORTE:
                  if(Value == 1)
                  {
                      GPIO_PORTE_DATA_BITS_R[1<<PIN] = 1<<PIN;
                  }
                  else
                  {
                      GPIO_PORTE_DATA_BITS_R[1<<PIN] = ~(1<<PIN);
                  }

              break;
              case PORTF:
                  if(Value == 1)
                  {
                      GPIO_PORTF_DATA_BITS_R[1<<PIN] = 1<<PIN;
                  }
                  else
                  {
                      GPIO_PORTF_DATA_BITS_R[1<<PIN] = ~(1<<PIN);
                  }

              break;
          }
}





/*
uint8_t read(PORT, uint8_t PIN)
{
    switch(PORT)
             {
             case PORTA:
                 return(GPIO_PORTF_DATA_BITS_R[1<<PIN])


                 break;
             case PORTB:


                 break;
             case PORTC:



                 break;
             case PORTD:


                 break;
             case PORTE:


                 break;
             case PORTF:


                 break;
             }
}
*/


