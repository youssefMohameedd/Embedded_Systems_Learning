/*
 * LCD.h
 *
 * Created: 11/25/2024 10:42:07 AM
 *  Author: maste
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <STD_Types.h>

void LCD_Latch(void);
void LCD_Init(void);
void LCD_Write_Cmd(uint8 cmd);
void LCD_Write_Char(uint8 character); // special chars: 0 - 8
void LCD_Write_Digit(uint8 digit);
void LCD_Write_Str(uint8 * ptr);
void LCD_Write_Number(uint32 number);
void LCD_Move_Pos(uint8 row, uint8 col); // row :0,1 , col: 0 - 15
void LCD_Store_Special_Character(uint8 * ptr , uint8 index); // index : 0 - 8 in CGROM ,done at code beginning




#endif /* LCD_H_ */