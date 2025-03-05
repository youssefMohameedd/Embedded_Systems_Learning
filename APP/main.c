/*
 * Project_Test.c
 *
 * Created: 10/27/2024 10:29:19 PM
 * Author : Youssef Mohamed
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include <SSD.h>
#include <LED.h>
#include <LCD.h>
#include <Keypad.h>
#include <Stepper.h>
#include <ADC.h>


int main(void)
{
	
	Stepper_Init();
	
	while(1)
	{
		Stepper_Rotate(360,2);
		_delay_ms(2000);
	}
	
	return 0;   
}

