/*
 * LCD.h
 *
 * Created: 11/25/2024 10:42:07 AM
 *  Author: maste
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <util/delay.h>
#include <DIO.h>
#include <LCD_CFG.h>




/**
 * @brief Latches the LCD display.
 */
void LCD_Latch(void);

/**
 * @brief Initializes the LCD display.
 */
void LCD_Init(void);

/**
 * @brief Writes a command to the LCD display.
 * @param cmd The command to be written (according to the LCD datasheet).
 */
void LCD_Write_Cmd(uint8 cmd);

/**
 * @brief Writes a character to the LCD display.
 * @param character The character to write. Special characters are in the range 0-8.
 */
void LCD_Write_Char(uint8 character);

/**
 * @brief Writes a digit to the LCD display.
 * @param digit The digit to write.
 */
void LCD_Write_Digit(uint8 digit);

/**
 * @brief Writes a string to the LCD display.
 * @param ptr Pointer to the string to write.
 */
void LCD_Write_Str(uint8 * ptr);

/**
 * @brief Writes a number (of multiple digits) to the LCD display.
 * @param number The number to written
 */
void LCD_Write_Number(uint32 number);

/**
 * @brief Moves the cursor position on the LCD display.
 * @param row The row to move the cursor to (0 or 1).
 * @param col The column to move the cursor to (0-15).
 */
void LCD_Move_Pos(uint8 row, uint8 col);

/**
 * @brief Stores a special character in the LCD's CGROM.
 * @param ptr Pointer to the character data.
 * @param index The index of the special character (0-8).
 */
void LCD_Store_Special_Character(uint8 * ptr , uint8 index);



#endif /* LCD_H_ */