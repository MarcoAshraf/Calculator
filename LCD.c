#include "LCD.h"

int LCD_pos;
int LCD_counter;
//RS->PA4  E->PA5  D4->PE0  D5->PE1  D6->PE2  D7->PE3
void LCD_INIT()
{
    delay_ms(30); //wait for 30ms for the power to stabilize

    DIO_INIT(PORTA, 0b00110000, 0b00000000);//initialize PORTA with pins 4,5 as output

    DIO_INIT(PORTE, 0b00001111, 0b00000000);//initialize PORTE with pins 0,1,2,3 as outputs

    //send instruction 001DLNF-- choose which operation mode, number of display lines, Font size,
    DIO_WRITE(PORTA, A4, 0); //RS = 0 for instruction mode
    //0100
    DIO_WRITE(PORTE, D4, 0);
    DIO_WRITE(PORTE, D5, 1);
    DIO_WRITE(PORTE, D6, 0);
    DIO_WRITE(PORTE, D7, 0);
    enable_pulse();
    enable_pulse();
    DIO_WRITE(PORTE, D4, 0); //ignored
    DIO_WRITE(PORTE, D5, 0); //ignored
    DIO_WRITE(PORTE, D6, 0); //font 0:small 1:big
    DIO_WRITE(PORTE, D7, 0); //number of lines 0:1, 1:2

    enable_pulse();

    //set display settings 1DCB-- Display on/off, cursor on/off, cursor blinking on/off
    display_control();

    //clear display
    clear_display();


    //return home
    return_home();



}


void SEND_CHAR()
{

    DIO_WRITE(PORTA, A4, 1); //set RS 1 to switch to data mode
    DIO_WRITE(PORTE, D7, 0);
    DIO_WRITE(PORTE, D6, 1);
    DIO_WRITE(PORTE, D5, 1);
    DIO_WRITE(PORTE, D4, 0);
    enable_pulse();
    DIO_WRITE(PORTE, D7, 0);
    DIO_WRITE(PORTE, D6, 1);
    DIO_WRITE(PORTE, D5, 1);
    DIO_WRITE(PORTE, D4, 0);
    enable_pulse();
}

void move_cursor()
{
    DIO_WRITE(PORTA, A4, 0); //set RS 1 to switch to data mode
    DIO_WRITE(PORTE, D7, 1);
    DIO_WRITE(PORTE, D6, 0);
    DIO_WRITE(PORTE, D5, 1);
    DIO_WRITE(PORTE, D4, 0);
    enable_pulse();
    DIO_WRITE(PORTE, D7, 1);
    DIO_WRITE(PORTE, D6, 0);
    DIO_WRITE(PORTE, D5, 0);
    DIO_WRITE(PORTE, D4, 0);
    enable_pulse();


}

void cursor_blink()
{
    DIO_WRITE(PORTA, A4, 0);
    DIO_WRITE(PORTE, D7, 0);
    DIO_WRITE(PORTE, D6, 0);
    DIO_WRITE(PORTE, D5, 0);
    DIO_WRITE(PORTE, D4, 0);
    enable_pulse();
    DIO_WRITE(PORTE, D7, 1);
    DIO_WRITE(PORTE, D6, 1);
    DIO_WRITE(PORTE, D5, 1);
    DIO_WRITE(PORTE, D4, 1);
    enable_pulse();
}

void SEND_DATA(uint8_t data)
{

    if(LCD_pos==16)       //when you reach the end of line
    {
        clear_display();
        return_home();
        LCD_pos = 0;
        LCD_counter++;
    }
    else;
    if(LCD_counter == 4 )
    {
        cursor_blink();
    }
    else if(LCD_counter == 5 && LCD_pos == 8)
    {
        return;
    }

    DIO_WRITE(PORTA, A4, 1); //set RS 1 to switch to data mode
    DIO_WRITE(PORTE, D7, CHECKBIT(data, 7));
    DIO_WRITE(PORTE, D6, CHECKBIT(data, 6));
    DIO_WRITE(PORTE, D5, CHECKBIT(data, 5));
    DIO_WRITE(PORTE, D4, CHECKBIT(data, 4));
    enable_pulse();
    DIO_WRITE(PORTE, D7, CHECKBIT(data, 3));
    DIO_WRITE(PORTE, D6, CHECKBIT(data, 2));
    DIO_WRITE(PORTE, D5, CHECKBIT(data, 1));
    DIO_WRITE(PORTE, D4, CHECKBIT(data, 0));
    enable_pulse();
    LCD_pos++;

}

void SEND_STRING(char *s)
{
    int i=0;
    while(s[i] != '\0')
    {
        SEND_DATA(s[i]);
        i++;
    }
}

void enable_pulse()
{
    DIO_WRITE(PORTA, A5, 1);
    delay_ms(10);
    DIO_WRITE(PORTA, A5, 0);
    delay_ms(10);
}


void delay_ms(unsigned int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {};
}

void delay_us( unsigned int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {};

}

void display_control()
{
    DIO_WRITE(PORTA, A4, 0);
    delay_us(40);
    for(int i=0; i<4; i++)
    {
        DIO_WRITE(PORTE, i, 0);
    }
    enable_pulse();
    DIO_WRITE(PORTE, D7, 1);
    DIO_WRITE(PORTE, D6, 1);
    DIO_WRITE(PORTE, D5, 0);
    DIO_WRITE(PORTE, D4, 0);
    enable_pulse();
}


void clear_display()
{
    DIO_WRITE(PORTA, A4, 0);
    delay_us(40);
    for(int i=0; i<4; i++)
    {
           DIO_WRITE(PORTE, i, 0);
    }
    enable_pulse();
    DIO_WRITE(PORTE, D4, 1);
    for(int i=1; i<4; i++)
    {
           DIO_WRITE(PORTE, i, 0);
    }
    enable_pulse();
}

void return_home()
{
    DIO_WRITE(PORTA, A4, 0);
    delay_ms(2);
    for(int i=0; i<4; i++)
    {
          DIO_WRITE(PORTE, i, 0);
    }
    enable_pulse();
    DIO_WRITE(PORTE, D7, 0);
    DIO_WRITE(PORTE, D6, 0);
    DIO_WRITE(PORTE, D5, 1);
    DIO_WRITE(PORTE, D4, 0);
    enable_pulse();
}



