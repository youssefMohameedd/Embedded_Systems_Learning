/*
 * EXTI.h
 *
 * Created: 3/25/2025 2:45:06 PM
 *  Author: Youssef
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include <GIE.h>
#include <EXTI_Types.h>
#include <EXTI_CFG.h>

/* @Brief: Initializes the EXTI Peripheral for future use */
void EXTI_Init(void);

/*@Brief Modifies current Mode of Operation for a specific External Interrupt 
//@param: INT : EXTI0,EXTI1,EXTI2
//@param: Mode:  Enable - Disable
//@param: Sense:   INTx_LOW_LEVEL, INTx_FALLING_RISING, INTx_FALLING, INTx_RISING

*/
void EXTI_Setup (uint8 INT , uint8 Mode , uint8 Sense);

/* @Brief: Call Back function that assigns ISR address of the main the corresponding vector */
void EXTI_CallBack_Function(void (*Foo_Ptr) (void));


#endif /* EXTI_H_ */