/*
 * TimerDriver.c
 *
 *  Created on: 21/9/2015
 *      Author: Eugenio Orosco
 */
#include "TimerDriver.h"



uint32_t MyRITimerFlagCounter;

void InicializarTimer(uint8_t TimerValue)
{
	Chip_RIT_Init(LPC_RITIMER);
	Chip_RIT_SetTimerInterval (LPC_RITIMER, TimerValue);
	NVIC_ClearPendingIRQ(RITIMER_IRQn);
	NVIC_EnableIRQ(RITIMER_IRQn);
	ClearTimer();
}

void SetBaseTimer(uint8_t TimerValue){
	Chip_RIT_SetTimerInterval (LPC_RITIMER, TimerValue);
}

void ClearTimer(void){
	MyRITimerFlagCounter = 0;
}

uint32_t GetTimer(void){
	return MyRITimerFlagCounter;
}


