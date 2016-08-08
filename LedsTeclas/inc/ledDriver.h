/*
 * ledDriver.h
 *
 *  Created on: 21/9/2015
 *      Author: Eugenio Orosco
 */

#ifndef LEDDRIVER_H_
#define LED_H_

#define LED0R 1
#define LED0G 2
#define LED0B 3
#define LED1 4
#define LED2 5
#define LED3 6

#include "chip.h"

void InicializarLeds(void);
void PrenderLed(uint8_t);
void ApagaLed(uint8_t);
void ToogleLed(uint8_t);




#endif /* LEDDRIVER_H_ */
