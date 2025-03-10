/*
 * ADC_CFG.h
 *
 * Created: 12/17/2024 6:41:13 PM
 *  Author: Youssef
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#include <ADC_HW.h>

//Token to get information about the required ADC Channel
typedef enum {
    ADC0 = 0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5,
    ADC6,
    ADC7
}ADC_Channels;

//Clearing Masks
#define PRESCALER_CLR_MASK               0b11111000
#define ADC_TRIGGERING_SOURCE_CLEAR_MASK 0b00011111
#define ADC_CHANNEL_CLEAR_MASK           0b11100000
#define ADC_VOLTAGE_REF_CLR_MASK         0b00111111

//Setting Masks
#define ADC_VOLTAGE_REF         AVCC_VOLTAGE
#define PRESCALAR_FACTOR        ADC_PRESCALER_128
#define ADC_MODE                ADC_MODE_SINGLE_CONVERSION
#define ADC_TRIGGERING_MODE     ADC_TRIGGER_SOURCE_FREE_RUNNING


#endif /* ADC_CFG_H_ */