/*
 * asmstd.s
 *
 *  Created on: Sep 17, 2020
 *      Author: Wombat
 */

// unified indicates that we're using a mix of different ARM instructions,
// e.g., 16-bit Thumb and 32-bit ARM instructions may be present (and are)
.syntax unified

// .global exports the label asmStd, which is expected by lab1math.h
.global asmStd

// .section marks a new section in assembly. .text identifies it as source code;
// .rodata marks it as read-only, setting it to go in FLASH, not SRAM
.section .text.rodata

/**
 * void asmMult(float *array, uint32_t size, float *std);
 *
 * R0 = pointer to array
 * R1 = size
 * R2 = pointer to std
 */

asmStd:
	PUSH		{R4, R5}			// saving R4 and R5 according to calling convention
	MOV			R4, R1				// copying size to R4
	MOV			R5, R1				// copying size to R5

sumLoop:
	SUBS		R4, R4, #1			// size = size - 1
	BLT			avg					// loop finishes when R1 < 0
	// TODO

continueSum:
	B			sumLoop				// next iteration

avg:
	// TODO

varianceLoop:
	// TODO

continueVariance:
	B			varianceLoop		// next iteration


