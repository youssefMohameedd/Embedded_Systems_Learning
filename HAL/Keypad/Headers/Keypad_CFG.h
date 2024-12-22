/*
 * Keypad_CFG.h
 *
 * Created: 12/23/2024 1:23:18 AM
 *  Author: maste
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/*Important Note: When you connect keypad to the board, make sure it
doesn't interfere with any LED or PushButton pins as they disturb its
operation.I have wasted 50 EGP for thinking that the keypad
isn't functioning , and I hope you don't :)*/

// Pin Definitions

#define r1 PB7
#define r2 PB6
#define r3 PB5
#define r4 PB4

#define c1 PC6
#define c2 PC5
#define c3 PC4
#define c4 PC3

//Columns mode
#define INPUT 0
#define PULL_UP 1


#define KEYPAD_INIT_MODE PULL_UP

#define NUM_OF_ROWS 4
#define NUM_OF_COLS 4

//Change below lines based on your keypad
uint8 rows[4] = {r1,r2,r3,r4};
uint8 cols[4] = {c1,c2,c3,c4};


uint8 KeyPad[4][4]={{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};



#endif /* KEYPAD_CFG_H_ */