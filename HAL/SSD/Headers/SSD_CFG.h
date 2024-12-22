/*
 * SSD_CFG.h
 *
 * Created: 11/15/2024 6:27:21 PM
 *  Author: maste
 */ 


#ifndef SSD_CFG_H_
#define SSD_CFG_H_

#define SSD_PORT PA
#define SSD_SIG HIGH // SIG = significance
// Pin definitions
#define EN1 PB1
#define EN2 PB2

#define A PA4
#define B PA5
#define C PA6
#define D PA7

#define MAX_NUM_SSDS 2
typedef enum {SSD_1 = 0 , SSD_2 = 1 }SSD_Num;


#endif /* SSD_CFG_H_ */