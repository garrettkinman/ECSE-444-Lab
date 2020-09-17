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
	PUSH			{R4, R5}			// saving R4 and R5 according to calling convention
	MOV				R4, R1				// copying size to R4
	MOV				R5, #0				// put 0 in R5
	VMOV			S0, R5				// move 0 to S0
	VCVT.f32.u32	S0, S0				// initializing sum to 0 in S0

sumLoop:
	SUBS			R4, R4, #1			// size = size - 1
	BLT				avg					// loop finishes when R1 < 0
	ADD				R5, R0, R4, LSL #2	// calculate base address (in R5) for array element
	VLDR.f32		S1, [R5]			// load element from array
	VADD.f32		S0, S0, S1			// sum += element

continueSum:
	B				sumLoop				// next iteration

avg:
	VMOV			S1, R1				// move size to S1
	VCVT.f32.u32	S1, S1				// convert size to fp
	VDIV.f32		S0, S0, S1			// avg = sum / size
	MOV				R4, R1				// copy size to R4 again
	SUB				R5, R4, #1			// take size - 1 in R5 (to use in division)
	VMOV			S4, R5				// move (size - 1) to S4
	VCVT.f32.u32	S4, S4				// convert (size - 1) to fp
	MOV				R5, #0				// put 0 in R5
	VMOV			S2, R5				// move 0 to S2
	VCVT.f32.u32	S2, S2				// initialize variance to 0 in S2

varianceLoop:
	SUBS			R4, R4, #1			// size = size - 1
	BLT				done				// loop finishes when R1 < 0
	ADD				R5, R0, R4, LSL #2	// calculate base address (in R5) for array element
	VLDR.f32		S3, [R5]			// load element from array
	VSUB.f32		S3, S3, S0			// subtract avg from element
	VMUL.f32		S3, S3, S3			// (element - avg)^2
	VDIV.f32		S3, S3, S4			// ((element - avg)^2) / (size - 1)
	VADD.f32		S2, S2, S3			// variance += ((element - avg)^2) / (size - 1)

continueVariance:
	B				varianceLoop		// next iteration

done:
	VSQRT.f32		S2, S2				// std = sqrt(variance)
	VSTR.f32		S2, [R2]			// store std in R2
	POP				{R4, R5}			// restore context
	BX				LR					// return
