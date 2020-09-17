/*
 * asmmult.s
 *
 *  Created on: Sep 16, 2020
 *      Author: Wombat
 */

// unified indicates that we're using a mix of different ARM instructions,
// e.g., 16-bit Thumb and 32-bit ARM instructions may be present (and are)
.syntax unified

// .global exports the label asmMult, which is expected by lab1math.h
.global asmMult

// .section marks a new section in assembly. .text identifies it as source code;
// .rodata marks it as read-only, setting it to go in FLASH, not SRAM
.section .text.rodata

/**
 * void asmMult(float *array1, float *array2, uint32_t size, float *products);
 *
 * R0 = pointer to array1
 * R1 = pointer to array2
 * R2 = size
 * R3 = pointer to products
 */

asmMult:
	PUSH		{R4, R5}			// saving R4-R9 according to calling convention


loop:
	SUBS		R2, R2, #1			// size = size - 1
	BLT			done				// loop finishes when R1 < 0
	ADD			R4, R0, R2, LSL #2	// calculate base address (in R4) for array1 element
	ADD			R5, R1, R2, LSL #2	// calculate base address (in R5) for array2 element
	VLDR.f32	S0, [R4]			// load element into fp register S0 (from address in R4)
	VLDR.f32	S1, [R5]			// load element into fp register S1 (from address in R5)
	VMUL.f32	S2, S0, S1			// multiply the two elements
	ADD			R5, R3, R2, LSL #2	// calculate base address (in R5) for products element
	VSTR.f32	S2, [R5]			// store product in products

continue:
	B			loop				// next iteration

done:
	POP			{R4, R5}			// restore context
	BX			LR					// return
