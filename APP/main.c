/*
 * Project_Test.c
 *
 * Created: 10/27/2024 10:29:19 PM
 * Author : Youssef Mohamed
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <STD_Types.h>
#include <SSD.h>
#include <util/delay.h>
#include <LED.h>
#include <LCD.h>
#include <LCD_CFG.h>
#include <Bit_Math.h>
#include <Keypad.h>
#include <DIO.h>



int main(void)
{
	LCD_Init();
	_delay_ms(10);
	Keypad_Init();
	
	uint8 val = 'N';

	while(1)
	{
		val = Keypad_Read_Char();
		if(val!='N')
		{	
			LCD_Write_Char(val);
			if(val=='*') LCD_Write_Cmd(DISPLAY_CLEAR);
			_delay_ms(100);
		}
		
		
		
	}
	
	

	return 0;   
}


