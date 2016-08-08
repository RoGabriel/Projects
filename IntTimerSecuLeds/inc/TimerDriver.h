/*
 * TimerDriver.h
 *
 *  Created on: 21/9/2015
 *      Author: Eugenio Orosco
 */

#ifndef TIMERDRIVER_H_
#define TIMERDRIVER_H_

#include "chip.h"

void InicializarTimer(uint8_t);

void SetBaseTimer(uint8_t);

void ClearTimer(void);

uint32_t GetTimer(void);



#endif /* TIMERDRIVER_H_ */
