/*
 * Stepper.h
 *
 * Created: 12/16/2024 2:24:10 PM
 *  Author: maste
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#include <util/delay.h>
#include <DIO.h>

void Stepper_Init(void);
void Stepper_Rotate(sint16 angle); // specify polarity using a sign to the angle


#endif /* STEPPER_H_ */