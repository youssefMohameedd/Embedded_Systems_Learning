/*
 * ADC.h
 *
 * Created: 12/17/2024 5:28:18 PM
 *  Author: maste
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <STD_Types.h>
#include <ADC_CFG.h>
#include <Bit_Math.h>
/*
Notice : We need to use Bit Masking to configure our ADC Registers
to ensure that previous values of the register wouldn't affect
our current assignation( Masks are mainly clear masks)
(we have made something similar in SSD - Write_Nibble )
*/
void ADC_Init (void);
uint16 ADC_Read (ADC_Channels Channel);


#endif /* ADC_H_ */