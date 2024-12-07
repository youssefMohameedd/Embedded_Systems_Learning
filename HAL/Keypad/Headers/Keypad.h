/*
 * Keypad.h
 *
 * Created: 12/5/2024 3:45:07 PM
 *  Author: maste
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <STD_Types.h>

#define r1 PD7
#define r2 PD6
#define r3 PD5
#define r4 PD4

#define c1 PD3
#define c2 PD2
#define c3 PD1
#define c4 PD0





void Keypad_Init(void); // sets PORTD as an output and Pull_up 
uint8 Keypad_Read_Char(void);


#endif /* KEYPAD_H_ */