/*
 * LED.h
 *
 * Created: 11/11/2024 11:07:47 PM
 *  Author: master
 */ 


#ifndef LED_H_
#define LED_H_

#include <util/delay.h>
#include <DIO.h>
#include <LED_CFG.h>

//This is HAL driver for LED , PushButton and Buzzer  

/** 
* @brief the function is to initialize the LED 
* @param  LED  LED pin number(LED0,LED1,LED2)
*/
void LED_Init(DIO_Channel LED);

/**
 * @brief this function intializes the PushButton
 * @param PushB Pushbutton pin number (PushB0,PushB1,PushB2)
 */
void PushB_Init(DIO_Channel PushB);

/**
 * @brief this function intializes the Buzzer
 */
void Buzzer_Init();

/**
 * @brief Write specific value to LED
 * @param LED LED pin number(LED0,LED1,LED2)
 * @param Level the STD_Level to write to the LED (STD_HIGH,STD_LOW)
 */
void Write_LED (DIO_Channel LED , STD_Level Level);

/**
 * @brief Write a specific value to the Buzzer
 * @param Buzzer Buzzer pin number (Buzzer)
 * @param Level the STD_Level to write to the Buzzer (STD_HIGH, STD_LOW)
 */
void Write_Buzzer(DIO_Channel Buzzer, STD_Level Level);

/**
 * @brief Read the debounced state of a PushButton
 * @param PushB Pushbutton pin number (PushB0, PushB1, PushB2)
 * @return The debounced state of the PushButton (STD_HIGH, STD_LOW)
 */
STD_Level Read_PushB (DIO_Channel PushB);

/**
 * @brief Toggle the state of an LED
 * @param LED LED pin number (LED0, LED1, LED2)
 */
void Toggle_LED(DIO_Channel LED);

#endif /* LED_H_ */