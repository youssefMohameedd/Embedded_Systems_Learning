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
void LCD_Write_Char(uint8 character);
void LCD_Move_Pos(uint8 row, uint8 col);
void LCD_String (uint8 * Sptr);



#endif /* LCD_H_ */