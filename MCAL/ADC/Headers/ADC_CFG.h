/*
 * ADC_CFG.h
 *
 * Created: 12/17/2024 6:41:13 PM
 *  Author: Youssef
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#include <ADC_HW.h>


#define ADC_VOLT_RESOLUTION_FACTOR 5.0/1024.0 // to convert bits into voltage

//Token to get information about the required ADC Channel
typedef enum {
    ADC_Channel0 = 0,
    ADC_Channel1,
    ADC_Channel2,
    ADC_Channel3,
    ADC_Channel4,
    ADC_Channel5,
    ADC_Channel6,
    ADC_Channel7
}ADC_Channels;

//Clearing Masks
#define ADC_VOLTAGE_REF_CLEAR_MASK       0b00111111
#define PRESCALER_CLR_MASK               0b11111000
#define ADC_TRIGGERING_SOURCE_CLEAR_MASK 0b00011111
#define ADC_CHANNEL_CLEAR_MASK           0b11100000


//Setting Masks
#define ADC_VOLTAGE_REF         AVCC_VOLTAGE // use AVCC in AMIT Board
#define PRESCALAR_FACTOR        ADC_PRESCALER_128 // use the largest factor to minimize sampling frequency to match ADC specsin Atmega32
#define ADC_MODE                ADC_MODE_SINGLE_CONVERSION
#define ADC_TRIGGERING_MODE     ADC_TRIGGER_SOURCE_FREE_RUNNING
#define ADC_Interrupt           FALSE


#endif /* ADC_CFG_H_ */