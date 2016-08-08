/*
===============================================================================
 Name        : ADConversor2.c
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
#include "ADConversor2.h"       /* <= own header */
#include "stdio.h"
//#include "math.h"
// TODO: insert other definitions and declarations here
int direccion;
#define max_value (0x3FF * 0xFF)

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

    /* perform the needed initialization here */

    leds_init();
    pulsadores_init();
    lcd_init_port();
    lcd_init();
    ADC_Init();
    alarma_init();
    //   Timer_Init();
    //   Timer_Set(1);
       float value;
       lcd_gotoxy(1, 1);
       printf_lcd("Bumetro...\0");

       while(1){

    	   	   value=ADC_Value();

    	   	   if(value>0 && value<50){
    	   		   led_off(LED_RGB_G);
    	   		   led_off(LED1);
    	   		   led_off(LED2);
    	   		   led_off(LED3);
    	   		   alarma_off();
    	   	   }
    	   	   if(value>50 && value<256){
    	   		   led_on(LED_RGB_G);
    	   		   led_off(LED1);
    	   		   led_off(LED2);
    	   		   led_off(LED3);
    	   		   alarma_off();

    	   	   }

    	   	   if(value>256 && value<512){
    	   		   led_on(LED_RGB_G);
    	   		   led_on(LED1);
    	   		   led_off(LED2);
    	   		   led_off(LED3);
    	   		   alarma_off();
    	   	   }

    	   	   if(value>512 && value<768){
    	   		   led_on(LED_RGB_G);
    	   		   led_on(LED1);
    	   		   led_on(LED2);
    	   		   led_off(LED3);
    	   		   alarma_off();
    	   	   }

    	   	   if(value>768 && value<1100){
    	   		   led_on(LED_RGB_G);
    	   		   led_on(LED1);
    	   		   led_on(LED2);
    	   		   led_on(LED3);
    	   		   alarma_on();
    	   	   }
       }


    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
}
void Timer_IRQ(void) {
    /*	int value;

    	int step = high_value / periodo;
    	DAC_Value(value>>8);
    	tecla = key();
    	if(tecla!=old_tecla) {
    		switch(tecla) {
    			case TECLA_1: periodo+=10; break;
    			case TECLA_2: periodo-=10; break;
    			case TECLA_3: high_value+=10*0xff; break;
    			case TECLA_4: high_value-=10*0xff; break;
    		}
    		old_tecla=tecla;
    	}
    	value +=step;
    	if(value>high_value) {
    		value=0;
    		Led_Color_Toggle(LED_1);
    	}

    	Timer_Clear_IRQ();*/
    }
