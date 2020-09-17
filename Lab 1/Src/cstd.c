/*
 * cstd.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Wombat
 */

#import "main.h"

float cSqrt(float n) {
	// babylonian method for square root
	float guess = n;
	float y = 1;
	float precision = 0.001;
	while (guess - y > precision) {
		guess = (guess + y) / 2;
		y = n / guess;
	}
	return guess;
}

void cStd(float *array, uint32_t size, float *std) {
	float sum = 0;
	for (uint32_t i = 0; i < size; i++) {
		sum += array[i];
	}
	float avg = sum / size;

	float variance = 0;
	for (uint32_t i = 0; i < size; i++) {
		variance += ((array[i] - avg) * (array[i] - avg)) / (size - 1);
	}
	(*std) = cSqrt(variance);
}

