/*
 * LCD.c
 *
 * Created: 11/25/2024 10:50:40 AM
 *  Author: Youssef
 */ 

#include <LCD_CFG.h>
#include <STD_Types.h>
#include <DIO.h>
#include <util/delay.h>
#include <Bit_Math.h>


void LCD_Latch(void) {
	Write_Channel(LCD_E, HIGH);
	_delay_ms(1); 
	Write_Channel(LCD_E, LOW);
	_delay_ms(1);
}

// Data are sent within Enable HIGH , Enable gets pulled down after all valid data sent
void LCD_Write_Cmd(uint8 cmd) {
	
	Write_Channel(LCD_RS, LOW);
	_delay_us(2);
	
	Write_Nibble(LCD_PORT, HIGH, cmd >> 4); // Send higher nibble
	LCD_Latch();

	Write_Nibble(LCD_PORT, HIGH, cmd & 0x0F); // Send lower nibble
	LCD_Latch();

	 _delay_us(50);
	 if(cmd== 0x01 ) _delay_ms(2);
}

void LCD_Init(void) {
	
	
	Set_Port_Direction(LCD_PORT, 0xFF);
	Set_Channel_Direction(LCD_E, OUTPUT);
	Set_Channel_Direction(LCD_RS, OUTPUT);
	Set_Channel_Direction(LCD_RW, OUTPUT);
	_delay_ms(50); // Wait for LCD power-up
	Write_Channel(LCD_RW, LOW); // Always in write mode
	
	LCD_Write_Cmd(FOUR_BIT_MODE);
	LCD_Write_Cmd(FUNCTION_SET);
	LCD_Write_Cmd(DISPLAY_CONTROL);
	LCD_Write_Cmd(ENTRY_MODE_SET);
	LCD_Write_Cmd(DISPLAY_CLEAR);
	_delay_ms(5);
	
	/*
	LCD_Write_Cmd(0x02);
	LCD_Write_Cmd(0x28);
	LCD_Write_Cmd(0x0C);
	LCD_Write_Cmd(0x01);	
	*/
}

void LCD_Write_Char(uint8 character) {
	
	Write_Channel(LCD_RS, HIGH);
	_delay_us(2);

	Write_Nibble(LCD_PORT, HIGH, character >> 4); // Send higher nibble & we may depend on operation cycles for tsu2+th2
	LCD_Latch();

	Write_Nibble(LCD_PORT, HIGH, character & 0x0F); // Send lower nibble
	LCD_Latch();

	_delay_us(50);
}


