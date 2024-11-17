/*
 * LED.h
 *
 * Created: 11/11/2024 11:07:47 PM
 *  Author: master
 */ 


#ifndef LED_H_
#define LED_H_

//This is HAL driver for LED and Push button together

#include <STD_Types.h>
#include <DIO_CFG.h>
#include <LED_CFG.h>


void LED_Init(DIO_Channel LED);
void PushB_Init(DIO_Channel PushB);
void Write_LED (DIO_Channel LED , STD_Level Level);
STD_Level Debounced_Read_PushB (DIO_Channel PushB);
void Toggle_LED(DIO_Channel LED);


#endif /* LED_H_ */