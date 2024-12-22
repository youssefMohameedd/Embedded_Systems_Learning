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

/**
 * @brief Initializes the Seven Segment Display (SSD) module.
 */
void SSD_init(void);

/**
 * @brief Writes a single digit to the specified SSD number.
 * @param SSD_Number The SSD number to write to.
 * @param value The value to write to the SSD.
 */
void SSD_Write_One_Digit(SSD_Num SSD_Number, uint8 value);

/**
 * @brief Writes two digits to the SSD.
 * @param value The two-digit value to write to the SSD.
 */
void SSD_Write_Two_Digits(uint8 value);



#endif /* SSD_H_ */