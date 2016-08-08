/*
 * TeclasDriver.h
 *
 *  Created on: 21/9/2015
 *      Author: Eugenio Orosco
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#define TECLA1 1
#define TECLA2 2
#define TECLA3 3
#define TECLA4 4


#include "chip.h"

void InicializarTeclas(void);
uint8_t LeerTecla(uint8_t);
uint8_t LeerTeclas(void);





#endif /* SWITCH_H_ */
