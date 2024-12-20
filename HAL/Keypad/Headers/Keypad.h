/*
 * Keypad.h
 *
 * Created: 12/5/2024 3:45:07 PM
 *  Author: Youssef
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <util/delay.h>
#include <DIO.h>


void Keypad_Init(void);
uint8 Keypad_Read_Char(void);


#endif /* KEYPAD_H_ */