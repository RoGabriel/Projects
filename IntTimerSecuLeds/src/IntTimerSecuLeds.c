/*
===============================================================================
 Name        : IntTimerSecuLeds.c
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

#include "IntTimerSecuLeds.h"       /* <= own header */
#include "ledDriver.h"
#include "TeclasDriver.h"
#include "chip.h"
#include "TimerDriver.h"
#include "setupDriver.h"

// TODO: insert other definitions and declarations here

extern uint32_t MyRITimerFlagCounter;



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


//    uint8_t auxTecla = 0, AddTimerValue=0;

    // comentar si no queres bajar la frecuencia
    InicializarCPU();

    /* perform the needed initialization here */
    InicializarLeds();
    InicializarTeclas();
    InicializarTimer(100);

    while(1){
    		MyRITimerFlagCounter = GetTimer();
    		if(MyRITimerFlagCounter == (25)){
    			ApagaLed(LED3);
    			PrenderLed(LED0R);
    		}
    		if(MyRITimerFlagCounter == (50)){
    			ApagaLed(LED0R);
    			PrenderLed(LED1);
    		}
    		if(MyRITimerFlagCounter == (75)){
    			ApagaLed(LED1);
    			PrenderLed(LED2);
    		}
    		if(MyRITimerFlagCounter == (100)){
    			ApagaLed(LED2);
    			PrenderLed(LED3);
    			ClearTimer();
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

void RIT_IRQHandler (void){
	Chip_RIT_ClearInt(LPC_RITIMER);
	MyRITimerFlagCounter ++;
}

