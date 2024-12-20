/*
 * LCD_CFG.h
 *
 * Created: 11/25/2024 10:48:59 AM
 *  Author: Youssef
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_PORT PA
#define LCD_SIG HIGH  // SIG == significance
#define LCD_RS   PB1
#define LCD_RW   PB2
#define LCD_E    PB3

#define D4 PA4
#define D5 PA5
#define D6 PA6
#define D7 PA7

#define LINE_2_BASE_ADDRESS 0x40
#define CGRAM_STEP 8


#define DISPLAY_CLEAR  0x01 // already move cursor to (0,0)
#define FOUR_BIT_MODE   0x02
#define RETURN_HOME 0x80
#define ENTRY_MODE_SET 0b00000110 //, ID:Increment - SH :Cursor
#define DISPLAY_CONTROL 0b00001111  //D:Display - C:Cursor - B:Blink
#define CURSOR_SHIFT 0b0001xx00  
#define FUNCTION_SET 0b00101000 // N : # Lines(0: 1-Line ,1 :2-Line), F:Font




#endif /* LCD_CFG_H_ */