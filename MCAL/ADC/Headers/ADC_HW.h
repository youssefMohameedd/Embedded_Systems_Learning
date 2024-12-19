/*
 * ADC_HW.h
 *
 * Created: 12/17/2024 5:30:23 PM
 *  Author: Youssef
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_

#include <STD_Types.h>
//ADC Registers
#define ADMUX_REG  *((volatile uint8*)0x27)
#define ADCSRA_REG *((volatile uint8*)0x26)
#define ADCH_REG   *((volatile uint8*)0x25)
#define ADCL_REG   *((volatile uint8*) 0x24)
#define ADCLH_REG  *((volatile uint16*) 0x24)  // used at right adjustment only(which is by default)
#define SFIOR_REG  *((volatile uint8*)0x50)
//ADC Modes
#define ADC_MODE_SINGLE_CONVERSION 0
#define ADC_MODE_AUTO_TRIGGERED    1
//ADC Prescaler
#define ADC_PRESCALER_2   0
#define ADC_PRESCALER_4   2
#define ADC_PRESCALER_8   3
#define ADC_PRESCALER_16  4
#define ADC_PRESCALER_32  5
#define ADC_PRESCALER_64  
//ADC Bits
#define REFS1_BIT 7
#define REFS0_BIT 6
#define ADLAR_BIT 5
#define MUX4_BIT  4
#define MUX3_BIT  3
#define MUX2_BIT  2
#define MUX1_BIT  1
#define MUX0_BIT  0
#define ADEN_BIT  7
#define ADSC_BIT  6
#define ADATE_BIT 5
#define ADIF_BIT  4
#define ADIE_BIT  3
#define ADPS2_BIT 2
#define ADPS1_BIT 1
#define ADPS0_BIT 0
#define ADTS2_BIT 2
#define ADTS1_BIT 1
#define ADTS0_BIT 0



#endif /* ADC_HW_H_ */