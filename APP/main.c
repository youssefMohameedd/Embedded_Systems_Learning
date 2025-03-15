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
#include <Sensors.h>


int main(void)
{
	
	
	ADC_Init();
	SSD_init();
	
	
	uint16 Value = 20 ;
	
	while(1)
	{
		Value = Sensor_Read(NTC);
		for(uint8 counter = 0 ; counter < 5 ; counter++)
		{
			SSD_Write_Two_Digits(Value);
		}
		
	}
	
	
	return 0;   
}

