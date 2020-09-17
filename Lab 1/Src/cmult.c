/*
 * cmult.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Wombat
 */

#import "main.h"

void cMult(float *array1, float *array2, uint32_t size, float *products) {
	for (uint32_t i = 0; i < size; i++) {
		products[i] = array1[i] * array2[i];
	}
}
