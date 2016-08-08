/*
===============================================================================
 Name        : RelojTiempoReal.c
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
#include "rtc.h"
#include "rtc_18xx_43xx.h"
#include "chip.h"
#include "stdint.h"

#include "lpc_types.h"
#include "RelojTiempoReal.h"
// TODO: insert other definitions and declarations here
int sec_anterior=0;

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
   // RTC_TIME_T FullTime;
       leds_init();
       lcd_init_port();
       lcd_init();

       rtc_set(0,1,14,16,6,16,1,2016);
       rtc_init();
       lcd_gotoxy(1, 1);
       printf_lcd("Hora:\0");
       lcd_gotoxy(9, 1);
       lcd_putc(':');
       lcd_gotoxy(12, 1);
       lcd_putc(':');
       lcd_gotoxy(1, 2);
       printf_lcd("Fecha:\0");
       lcd_gotoxy(9, 2);
       lcd_putc('/');
       lcd_gotoxy(12, 2);
       lcd_putc('/');
       while(1)
       {
    	   rtc_printf(7,1, RTC_TIMETYPE_HOUR);
           rtc_printf(10,1, RTC_TIMETYPE_MINUTE);
           rtc_printf(13,1, RTC_TIMETYPE_SECOND);

           rtc_printf(7,2, RTC_TIMETYPE_DAYOFMONTH);
           rtc_printf(10,2, RTC_TIMETYPE_MONTH);
           rtc_printf(13,2, RTC_TIMETYPE_YEAR);

       }
    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}
