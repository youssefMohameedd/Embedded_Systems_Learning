/*
 * Keypad.h
 *
 * Created: 12/5/2024 3:45:07 PM
 *  Author: maste
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <STD_Types.h>


void Keypad_Init(void); // sets PORTD as an output and Pull_up 
uint8 Keypad_Read_Char(void);


#endif /* KEYPAD_H_ */