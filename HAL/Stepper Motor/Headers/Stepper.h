/*
 * Stepper.h
 *
 * Created: 12/16/2024 2:24:10 PM
 *  Author: Youssef
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#include <util/delay.h>
#include <DIO.h>
#include <Stepper_CFG.h>

/**
 * @brief Initializes the stepper motor hardware.
 */
void Stepper_Init(void);

/**
 * @brief Rotates the stepper motor by the specified angle.
 * @param angle The angle to rotate the stepper motor by, in degrees,the angle sign determines the direction of rotation.
 */
void Stepper_Rotate(sint16 angle);


#endif /* STEPPER_H_ */