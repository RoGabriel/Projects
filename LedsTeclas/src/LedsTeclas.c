/*
===============================================================================
 Name        : LedsTeclas.c
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
#include "LedsTeclas.h"       /* <= own header */
#include "ledDriver.h"
#include "TeclasDriver.h"
#include "setupDriver.h"

// TODO: insert other definitions and declarations here
#define MAXDELAY 700000

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

    uint8_t TeclaPresionada = 0;
    /* perform the needed initialization here */
    InicializarCPU();
    InicializarLeds();
    InicializarTeclas();

    	while(1){

    		if(LeerTecla(TECLA1)){
    			delayNoelegante(MAXDELAY);
    			TeclaPresionada = 1;
    		}

    		if(LeerTecla(TECLA2)){
    			delayNoelegante(MAXDELAY);
    			TeclaPresionada = 2;
    		}

    		if(LeerTecla(TECLA3)){
    			delayNoelegante(MAXDELAY);
    			TeclaPresionada = 3;
    		}

    		if(LeerTecla(TECLA4)){
    			delayNoelegante(MAXDELAY);
    			TeclaPresionada = 4;
    		}

    		switch(TeclaPresionada){
    			case 1:
    				ToogleLed(LED0R);
    				ApagaLed(LED1);
					ApagaLed(LED2);
					ApagaLed(LED3);
    				break;
    			case 2:
    				ToogleLed(LED1);
    				ApagaLed(LED0R);
					ApagaLed(LED2);
					ApagaLed(LED3);
    				break;
    			case 3:
    				ToogleLed(LED2);
    				ApagaLed(LED0R);
					ApagaLed(LED1);
					ApagaLed(LED3);
    				break;
    			case 4:
    				ToogleLed(LED3);
    				ApagaLed(LED0R);
					ApagaLed(LED1);
					ApagaLed(LED2);
    				break;

    		}
    		delayNoelegante(2000000);
    	}
    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}
