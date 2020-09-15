/*
 * cmax.c
 *
 *  Created on: Sep 14, 2020
 *      Author: Wombat
 */

#import "main.h"

void cMax(float *array, uint32_t size, float *max, uint32_t *maxIndex) {
	(*max) = array[0];
	(*maxIndex) = 0;

	for (uint32_t i = 1; i < size; i++) {
		if (array[i] > (*max)) {
			(*max) = array[i];
			(*maxIndex) = i;
		}
	}
}
