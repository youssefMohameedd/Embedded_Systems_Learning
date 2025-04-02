/*
 * EXTI_Types.h
 *
 * Created: 3/25/2025 2:46:55 PM
 *  Author: Youssef
 */ 


#ifndef EXTI_TYPES_H_
#define EXTI_TYPES_H_

#include <EXTI_HW.h>


#define EXTI0	INT0_BIT
#define EXTI1	INT1_BIT
#define EXTI2	INT2_BIT

#define DISABLE 0
#define ENABLE 1

//Sense Control Masks

#define INT0_LOW_LEVEL		0b0000
#define INT0_FALLING_RISING	0b0001
#define INT0_FALLING		0b0010
#define INT0_RISING			0b0011

#define INT1_LOW_LEVEL		0b0000
#define INT1_FALLING_RISING	0b0100
#define INT1_FALLING		0b1000
#define INT1_RISING			0b1100

#define INT2_FALLING		0 << ISC2_BIT
#define INT2_RISING	    	1 << ISC2_BIT

//Mask Definitions
#define EXTI_SENSE_CONTROL_CLEAR_MASK 0b11110000
#define EXTI_MODE_CLEAR_MASK 0b00011111
#define EXTI_FLAG_CLEAR_MASK 0b11111111




#endif /* EXTI_TYPES_H_ */