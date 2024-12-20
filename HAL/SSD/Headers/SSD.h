/*
 * SSD.h
 *
 * Created: 11/15/2024 6:27:53 PM
 *  Author: master
 */ 


#ifndef SSD_H_
#define SSD_H_

#include <util/delay.h>
#include <DIO.h>
#include <SSD_CFG.h>


void SSD_init(void);
void SSD_Write_One_Digit(SSD_Num SSD_Number , uint8 value);
void SSD_Write_Two_Digits(uint8 value);



#endif /* SSD_H_ */