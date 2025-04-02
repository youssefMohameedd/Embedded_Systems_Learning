/*
 * LED_CFG.h
 *
 This file is specfied for AMIT Kit for Embedded Systems Diploma
 You can change Definitions based on your Kit xD
 * Created: 11/11/2024 11:07:16 PM
 *  Author: Youssef
 */ 


#ifndef LED_CFG_H_
#define LED_CFG_H_

//LEDs Definitions

#define LED0 PC2_PIN
#define LED1 PC7_PIN
#define LED2 PD3_PIN

// All Push buttons and Buzzer in AMIT Board are connected in a pull down resistor connection

#define PushB0 PD2_PIN // originally PB0
#define PushB1 PD6_PIN
#define PushB2 PD2_PIN

#define BUZZER PA3_PIN

#endif /* LED_CFG_H_ */