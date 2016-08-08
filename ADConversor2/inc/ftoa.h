/*
 * ftos.h
 *
 *  Created on: 18 de abr. de 2016
 *      Author: Leo
 */

#ifndef FTOA_H_
#define FTOA_H_

#include "stdio.h"
#include "math.h"

// reverses a string 'str' of length 'len'
void reverse(char *str, int len);

 // Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d);

// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint);

#endif /* FTOA_H_ */
