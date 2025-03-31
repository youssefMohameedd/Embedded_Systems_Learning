/*
 * EXTI_CFG.h
 *
 * Created: 3/25/2025 2:46:33 PM
 *  Author: Youssef
 */ 


#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

#include <EXTI_Types.h>

//Init config for interrupt sense control -- improve comments in this file
#define EXTI0_SENSE_CONTROL		INT0_RISING
#define EXTI1_SENSE_CONTROL		INT1_RISING
#define EXTI2_SENSE_CONTROL		INT2_RISING // Range : FALLING - RISING,  only !!

//Init config for interrupt Activation Mode (Enable-Disable)
#define EXTI0_MODE	ENABLE
#define EXTI1_MODE	ENABLE
#define EXTI2_MODE	DISABLE



#endif /* EXTI_CFG_H_ */