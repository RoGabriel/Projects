/*
 * Buzzer.h
 *
 *  Created on: 18 de abr. de 2016
 *      Author: Leo
 */

#include "stdint.h"
#include "puertos.h"
#include "chip.h"


#define ALARMA   12



void alarma_init(void);
void alarma_on(void);
void alarma_off(void);
//void delay(void);
void delay2(void);
