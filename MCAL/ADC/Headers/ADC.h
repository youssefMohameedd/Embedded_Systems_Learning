/*
 * ADC.h
 *
 * Created: 12/17/2024 5:28:18 PM
 *  Author: Youssef
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <STD_Types.h>
#include <Bit_Math.h>
#include <ADC_CFG.h>
#include <ADC_HW.h>



/*
Notice : We need to use Bit Masking to configure our ADC Registers
to ensure that previous values of the register wouldn't affect
our current assignation (we have made something similar in DIO  Write_Nibble )
*/
void ADC_Init (void);
uint16 ADC_Read (ADC_Channels Channel);


#endif /* ADC_H_ */