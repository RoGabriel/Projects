/*
 * Buzzer.c
 *
 *  Created on: 18 de abr. de 2016
 *      Author: Leo
 */

#include "Buzzer.h"

void alarma_init(void){
	port_pin(6,12, MD_PUP,init_out);
	port_pin(6,12, disable, low);
}

void alarma_on(void){
	port_pin(6,12, disable, high);
}

void alarma_off(void){
	port_pin(6,12, disable, low);
}

void delay3(){
	long int i=0,x=0;
	for(i=0; i<9999999; i++){x++;}
}

void delay2(){
	long int i=0,x=0;
	for(i=0; i<999999999; i++){x++;}
}
