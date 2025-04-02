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
#include <avr/io.h>

static float value = 0 ;

void ADC_ISR(void)
{
	
	value = Sensor_Read(NTC);
	
	
}

int main(void)
{
	//Preferably initialize the ADC before the LCD to ensure delay for stabilazaiton
	ADC_Init(NTC);
	ADC_Set_Callback(ADC_ISR);
	
	LCD_Init();
	_delay_ms(10);	

	while(1)
	{
	
		SSD_Write_Two_Digits(value);
		
		
	}

	return 0;
}