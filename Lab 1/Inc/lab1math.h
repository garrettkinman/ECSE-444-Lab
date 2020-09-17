/*
 * lab1math.h
 *
 *  Created on: Sep 14, 2020
 *      Author: Wombat
 */

#ifndef INC_LAB1MATH_H_
#define INC_LAB1MATH_H_

#include "main.h"

void cMax(float *array, uint32_t size, float *max, uint32_t *maxIndex);

extern void asmMax(float *array, uint32_t size, float *max, uint32_t *maxIndex);

void cMult(float *array1, float *array2, uint32_t size, float *products);

extern void asmMult(float *array1, float *array2, uint32_t size, float *products);

#endif /* INC_LAB1MATH_H_ */
