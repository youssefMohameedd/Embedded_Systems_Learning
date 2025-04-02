/*
 * SSD_CFG.h
 *
 * Created: 11/15/2024 6:27:21 PM
 *  Author: maste
 */ 


#ifndef SSD_CFG_H_
#define SSD_CFG_H_

#define SSD_PORT PA_PORT
#define SSD_SIG HIGH // SIG = significance
// Pin definitions
#define EN1 PB1_PIN
#define EN2 PB2_PIN

#define A PA4_PIN
#define B PA5_PIN
#define C PA6_PIN
#define D PA7_PIN

#define MAX_NUM_SSDS 2
typedef enum {SSD_1 = 0 , SSD_2 = 1 }SSD_Num;


#endif /* SSD_CFG_H_ */