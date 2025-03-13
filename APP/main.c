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
	
	LCD_Init();
	
	uint16 Value = 10 ;
	uint16 prev_Value = Value ;
	
	ADC_Init();
	LCD_Move_Pos(0,3);
	LCD_Write_Str("Temp:");
	LCD_Write_Number(Value);
	while(1)
	{

		Value =Sensor_Read(LM35);
		if(prev_Value != Value )
		{
			LCD_Write_Cmd(DISPLAY_CLEAR);
			LCD_Move_Pos(0,3);
			LCD_Write_Str("Temp:");
			LCD_Write_Number(Value);
			prev_Value = Value;
			_delay_ms(100);
		}
		else _delay_ms(50);
		

	}
	return 0;   
}

