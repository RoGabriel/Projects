/*
 * Teclado.h
 *
 *  Created on: 18 de abr. de 2016
 *      Author: Leo
 */


#include "stdint.h"
#include "chip.h"


void Board_KEYBOARD_Init(uint8_t rows, uint8_t columns);

void Board_KEYBOARD_tick_ms(void);

int Board_KEYBOARD_readMatrix(uint8_t row,uint8_t col);

void Board_KEYBOARD_enable(void);

void Board_KEYBOARD_disable(void);

