/*
===============================================================================
 Name        : TecladoMatricial.c
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
#include "TecladoMatricial.h"
// TODO: insert other definitions and declarations here
int tecla=0;
int filas = 4;
int columnas = 3;
int i,j;

const MAXDELAY=2000000;

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
    Board_KEYBOARD_Init(filas, columnas);

    lcd_gotoxy(1,1);
    printf_lcd("Tecla Press: ");

    while(1){
    	Board_KEYBOARD_tick_ms();

    	lcd_gotoxy(13,1);
    	for (i=0;i<4;i++){
    		for(j=0;j<3;j++){

    			if(Board_KEYBOARD_readMatrix(i,j)==0){
    					switch(i){
    						case 0:
    							switch(j){
    								case 0:
    									lcd_putc('1');
    									break;

    								case 1:
    									lcd_putc('2');
    									break;

    								case 2:
    									lcd_putc('3');
    									break;
    							}
    							break;

    						case 1:
    							switch(j){
    								case 0:
    									lcd_putc('4');
    									break;

    								case 1:
    									lcd_putc('5');
    									break;

    								case 2:
    									lcd_putc('6');
    									break;
    							}
    							break;

    						case 2:
    							switch(j){
    								case 0:
    									lcd_putc('7');
    									break;

    								case 1:
    									lcd_putc('8');
    									break;

    								case 2:
    									lcd_putc('9');
    									break;
    							}
    							break;

    						case 3:
    							switch(j){
    								case 0:
    									lcd_putc('*');
    									break;

    								case 1:
    									lcd_putc('0');
    									break;

    								case 2:
    									lcd_putc('#');
    									break;
    								}
    							break;
    					}
    			}

    		}
    	}
 //   	delayNoelegante(MAXDELAY);
    }


    // Force the counter to be placed into memory
    volatile static int j = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        j++ ;
    }
    return 0 ;
}
