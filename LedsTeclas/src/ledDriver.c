/*
 * ledDriver.c
 *
 *  Created on: 21/9/2015
 *      Author: Eugenio Orosco
 */
#include "chip.h"
#include "ledDriver.h"


void InicializarLeds(void)
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4); /* remapea P2_1 en GPIO5[1], LED0G y habilita el pull up */
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4); /* remapea P2_2 en GPIO5[2], LED0B y habilita el pull up */
	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); /* remapea P2_10 en GPIO0[14], LED1 y habilita el pull up */
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); /* remapea P2_11 en GPIO1[11], LED2 y habilita el pull up */
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); /* remapea P2_12 en GPIO1[12], LED3 y habilita el pull up */

	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1 << 0), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1 << 1), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1 << 2), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1 << 14), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1 << 11), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1 << 12), 1);


}

void PrenderLed(uint8_t NumeroLed)
{
	switch(NumeroLed)
	{
	case LED0R:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
		break;
	case LED0G:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
		break;
	case LED0B:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
		break;
	case LED1:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 14);
		break;
	case LED2:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 11);
		break;
	case LED3:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 12);
		break;
	default:
		break;
	}
}
void ApagaLed(uint8_t NumeroLed)
{
	switch(NumeroLed)
	{
	case LED0R:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0);
		break;
	case LED0G:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
		break;
	case LED0B:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
		break;
	case LED1:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14);
		break;
	case LED2:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11);
		break;
	case LED3:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12);
		break;
	default:
		break;
	}
}
void ToogleLed(uint8_t NumeroLed)
{
	switch(NumeroLed)
	{
	case LED0R:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 5, 0);
		break;
	case LED0G:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 5, 1);
		break;
	case LED0B:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 5, 2);
		break;
	case LED1:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 0, 14);
		break;
	case LED2:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 1, 11);
		break;
	case LED3:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, 1, 12);
		break;
	default:
		break;
	}
}

