/*
===============================================================================
 Name        : AlarmaBuzzer.c
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
#include "AlarmaBuzzer.h"
// TODO: insert other definitions and declarations here
bool estado=0;
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
    lcd_init_port();
    lcd_init();
    leds_init();
    pulsadores_init();
    alarma_init();
    alarma_off();
    while(1)
    	{
        if (estado_pulsador(TEC2))
    	{
    		alarma_on();
    		estado=1;
    	}
        if(estado){
        	if (estado_pulsador(TEC3))
        	        {
        	        	alarma_off();
        	        	estado=0;
        	        }
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
