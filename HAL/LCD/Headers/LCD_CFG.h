/*
 * LCD_CFG.h
 *
 * Created: 11/25/2024 10:48:59 AM
 *  Author: Youssef
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

// H/W Connections
#define LCD_PORT PA_PORT
#define LCD_SIG  HIGH  // SIG == significance
#define LCD_RS   PB1_PIN
#define LCD_RW   PB2_PIN
#define LCD_E    PB3_PIN

#define D4 PA4_PIN
#define D5 PA5_PIN
#define D6 PA6_PIN
#define D7 PA7_PIN
//Based on Datasheet
#define LINE_2_BASE_ADDRESS 0x40
#define CGRAM_STEP 8
//Manually Configured by the user
#define INIT_MODE 0 // 0 : 4-bit Mode , 1 : 8-bit Mode
//Basic Instructions
#define EIGHT_BIT_MODE  0b0011
#define FOUR_BIT_MODE   0b0010 
#define FUNCTION_SET    0b00101000 // 001/DL/N/F/00  // DL: Data-Length (0:4-bit,1:8-bit) N : # Lines(0: 1-Line ,1 :2-Line), F:Font (0: 5x8 dots , 1 : 5x11 dots)
#define DISPLAY_CONTROL 0b00001111  // 00001DCB  D:Display - C:Cursor - B:Blink
#define DISPLAY_CLEAR   0b00000001 //0000 0001 // already move cursor to (0,0)
#define ENTRY_MODE_SET  0b00000110 // 000001/ID/SH   ID:Increment position automatically - SH : Shifts Entire  , Configured by Processor by default

#define RETURN_HOME     0b10000000 // 0b 1000 0000




//#define CURSOR_SHIFT 0b0001xx00


#endif /* LCD_CFG_H_ */