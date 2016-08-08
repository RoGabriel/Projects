/*
===============================================================================
 Name        : DisplayLCD.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "DisplayLCD.h"

// TODO: insert other definitions and declarations here
int i=1,j=1,k=1,m=1;
char string_1[12]="Boton->UNO\0";
char string_2[12]="Boton->DOS\0";
char string_3[12]="Boton->TRES\0";
char string_4[16]="Boton->CUATRO\0";
char string_5[16]="Boton->ninguno\0";

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
#if defined (__MULTICORE_MASTER) || defined (__MULTICORE_NONE)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
#endif
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here
    		leds_init();
    		lcd_init_port();
    		lcd_init();
    		pulsadores_init();

            lcd_gotoxy(1, 1);
    		lcd_putc('P');
    		lcd_putc('U');
    		lcd_putc('L');
    		lcd_putc('S');
    		lcd_putc('A');
    		lcd_putc('D');
    		lcd_putc('O');
    		lcd_putc('R');
    		lcd_putc(' ');
    		lcd_putc('P');
    		lcd_putc('R');
    		lcd_putc('E');
    		lcd_putc('S');
    		lcd_putc('S');
    		lcd_putc(':');

    		while(1)
    	{
/*    		lcd_gotoxy(1, 1);
    		lcd_putc('P');
    		lcd_putc('U');
    		lcd_putc('L');
    		lcd_putc('S');
    		lcd_putc('A');
    		lcd_putc('D');
    		lcd_putc('O');
    		lcd_putc('R');
    		lcd_putc(' ');
    		lcd_putc('P');
    		lcd_putc('R');
    		lcd_putc('E');
    		lcd_putc('S');
    		lcd_putc('S');
    		lcd_putc(':');
*/
    	if (estado_pulsador(TEC4))
    	{
    		led_on(LED3);
    		lcd_gotoxy(1, 2);
    		printf_lcd("                ");
    		lcd_gotoxy(1, 2);
    		printf_lcd(string_4);
    	}else
    		{
    			led_off(LED3);
    		}
        if (estado_pulsador(TEC3))
        {
        	led_on(LED2);
        	lcd_gotoxy(1, 2);
        	printf_lcd("                ");
        	lcd_gotoxy(1, 2);
        	printf_lcd(string_3);
        }else
        	{
        		led_off(LED2);
            }
    	if (estado_pulsador(TEC2))
        {
        	led_on(LED1);
    		lcd_gotoxy(1, 2);
    		printf_lcd("                ");
    		lcd_gotoxy(1, 2);
    		printf_lcd(string_2);
    	}else
        	{
    		led_off(LED1);
    		}
    	if (estado_pulsador(TEC1))
    	{
        	led_on(LED_RGB_B);
    		lcd_gotoxy(1, 2);
    		printf_lcd("                ");
    		lcd_gotoxy(1, 2);
    		printf_lcd(string_1);
    	}else
    	{
    		led_off(LED_RGB_B);
        }
      }
    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}
