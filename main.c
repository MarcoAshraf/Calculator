#include "DIO.h"
#include "GPIO_INTERRUPT.h"
#include "LCD.h"
#include "Keypad.h"
#include "parse.h"
#include "stdlib.h"
#include "stdio.h"


extern int LCD_pos;
extern int LCD_counter;

uint8_t counter =0;

float parse(char *s);
char s[100];


int main(void)
{
    Keypad_INIT();
    delay_ms(50);
    LCD_INIT();
    SEND_DATA(':');
    //clear_display();

    while(1)
    {


        //SEND_STRING("TEST");


    }

	return 0;
}





void Read_Keypad()
{
        uint8_t Keypad[4][4]=   {{'1','2','3','+'},
                                {'4','5','6','-'},
                                {'7','8','9','*'},
                                {'#','0','=','/'}}; // Initializing array to loop on it
        // Clearing the interrupt Flag
        GPIO_PORTB_ICR_R=0xFF;
        uint8_t row = 0;
        uint8_t col = 0;
        for (row = 0; row < 4; row++)
        {
            int temp = bit_check(GPIO_PORTB_DATA_R, row);
            if(!temp)
            {
                break;
            }
        }


        for (col = 4; col < 8; col++)
        {
            bitset(GPIO_PORTB_DATA_R, col);

            if (bit_check(GPIO_PORTB_DATA_R, row))
            {
                //reset the state of the columns back to 0
                bitclear(GPIO_PORTB_DATA_R, 4);
                bitclear(GPIO_PORTB_DATA_R, 5);
                bitclear(GPIO_PORTB_DATA_R, 6);
                bitclear(GPIO_PORTB_DATA_R, 7);
                if(row!=4 &&Keypad[row][col-4]!= '=')
                {
                    if(Keypad[row][col-4] == '#') // Reset
                    {
                        clear_display();
                        return_home();
                        LCD_pos = 0;
                        LCD_counter = 0;
                        counter = 0;
                    }
                    else
                    {
                    SEND_DATA(Keypad[row][col-4]);
                    s[counter] = Keypad[row][col-4];
                    counter++;
                    }
                }
                else if(Keypad[row][col-4]== '=')
                {
                    float temp = parse(s);
                    /*
                    if((int)temp == (int)SyntaxError)
                    {
                        clear_display();
                        LCD_pos = 0;
                        LCD_counter = 0;
                        SEND_STRING("Syntax Error");
                        delay_ms(1000);
                        clear_display();
                        return_home();
                        LCD_pos = 0;
                        LCD_counter = 0;
                        counter = 0;

                    }

                    else if(((int)temp == (int)MathError) < 1e-9)
                    {
                        clear_display();
                        LCD_pos = 0;
                        LCD_counter = 0;
                        SEND_STRING("Math Error");
                        delay_ms(1000);
                        clear_display();
                        return_home();
                        LCD_pos = 0;
                        LCD_counter = 0;
                        counter = 0;
                    }
                    else
                   {*/
                       // sprintf(s, "%f", parse(s));
                        ltoa((int)temp, s);
                        clear_display();
                        SEND_STRING(s);
                  // }
                }
                delay_ms(50);
                GPIO_PORTB_ICR_R=0xFF;
                SETBIT(NVIC_UNPEND0_R, 1);
                return;
            }

        }

}
