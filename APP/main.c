/*
 * Project_Test.c
 *
 * Created: 10/27/2024 10:29:19 PM
 * Author : Youssef Mohamed
 */ 
/**
 * @brief Main entry point of the application.
 * This function initializes the Segment Display (SSD), Buzzer, and three push buttons (PushB0, PushB1, PushB2).
 * It then enters a main loop that handles the following functionality:
 * - Keeps the value within the range of 0 to 99
 * - Increments the value when PushB0 is pressed
 * - Decrements the value when PushB1 is pressed
 * - Sets a flag when PushB2 is pressed, which triggers a countdown from the current value to 0
 * - Displays the current value on the SSD
 * The function returns 0 to indicate successful execution.
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

int main(void)
{	
	LCD_Init();
	_delay_ms(3);

	LCD_Write_Char('A');
	LCD_Write_Char('B');
	_delay_ms(1000);
	LCD_Write_Char('C');
	LCD_Write_Char('D');
	_delay_ms(5);
	LCD_Write_Cmd(DISPLAY_CLEAR);
	LCD_Write_Cmd(RETURN_HOME);
	_delay_ms(5);
	LCD_Write_Char('A');
	LCD_Write_Char('B');
	_delay_ms(1000);
	LCD_Write_Char('C');
	LCD_Write_Char('D');

	while(1)
	{


		
	}
	
	return 0;   
}
