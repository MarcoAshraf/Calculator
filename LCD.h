#include "DIO.h"

#ifndef LCD_H_
#define LCD_H_


void LCD_INIT();
void SEND_CHAR();
void SEND_DATA(uint8_t data);
void delay_ms(unsigned int n);
void delay_us( unsigned int n);
void enable_pulse();
void display_control();
void clear_display();
void return_home();
void move_cursor();
void SEND_STRING(char *s);
void cursor_blink();





typedef enum
{
    D4 = 0,
    D5 = 1,
    D6 = 2,
    D7 = 3,
    A4 = 4,
    A5 = 5,

}DATAPORT;



#endif /* LCD_H_ */
