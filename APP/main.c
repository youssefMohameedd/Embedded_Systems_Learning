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
	LCD_Init();
	_delay_ms(10);
	
	uint16 value ;

	while(1)
	{
		value = Sensor_Read(LM35);
		LCD_Write_Cmd(DISPLAY_CLEAR);
		LCD_Move_Pos(0,3);
		LCD_Write_Str("Temp:");
		LCD_Write_Number(value);
		
		_delay_ms(250);
		
		
	}
	
	return 0;
}
