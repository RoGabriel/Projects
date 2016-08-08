/*
 * setupDriver.c
 *
 *  Created on: 21/9/2015
 *      Author: Eugenio Orosco
 */
#include "chip.h"



void InicializarCPU(void)
{
	Chip_SetupCoreClock(CLKIN_IRC, MAX_CLOCK_FREQ/4, true);
}

void delayNoelegante(uint32_t delay){
	volatile uint32_t i;
	for(i=0;i<delay;i++);
}

