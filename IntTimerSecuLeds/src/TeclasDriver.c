/*
 * TeclasDriver.c
 *
 *  Created on: 21/9/2015
 *      Author: Eugenio Orosco
 */
#include "chip.h"
#include "TeclasDriver.h"


void InicializarTeclas(void)
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_0 en GPIO 0[4], SW1 */
	Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_1 en GPIO 0[8], SW2 */
	Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_2 en GPIO 0[9], SW3 */
	Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_6 en GPIO 1[9], SW4 */

	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1 << 4), 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1 << 8), 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1 << 9), 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1 << 9), 0);


}

uint8_t LeerTecla(uint8_t NumeroTecla)
{
	uint8_t tecla=0;
	switch(NumeroTecla)
	{
	case TECLA1:
		tecla = (0x01) & (~Chip_GPIO_GetPinState(LPC_GPIO_PORT, 0, 4));
		break;
	case TECLA2:
		tecla = (0x01) & (~Chip_GPIO_GetPinState(LPC_GPIO_PORT, 0, 8));
		break;
	case TECLA3:
		tecla = (0x01) & (~Chip_GPIO_GetPinState(LPC_GPIO_PORT, 0, 9));
		break;
	case TECLA4:
		tecla = (0x01) & (~Chip_GPIO_GetPinState(LPC_GPIO_PORT, 1, 9));
		break;
	default:
		tecla=0;
		break;
	}
	return tecla;
}

uint8_t LeerTeclas(void)
{
	uint8_t teclas = 0;
	teclas = LeerTecla(TECLA1);
	teclas |= (LeerTecla(TECLA2) << 1);
	teclas |= (LeerTecla(TECLA3) << 2);
	teclas |= (LeerTecla(TECLA4) << 3);
	return teclas;
}
