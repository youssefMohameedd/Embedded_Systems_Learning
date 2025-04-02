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
#include <GIE.h>


/*
Notice : We need to use Bit Masking to configure our ADC Registers
to ensure that previous values of the register wouldn't affect
our current assignation (we have made something similar in DIO  Write_Nibble )
*/
/**
 * @brief Initializes the ADC module.
 */
void ADC_Init (ADC_Channels Channel);

/**
 * @brief Starts conversion of the specified ADC channel.
 * @param Channel The ADC channel to read.
 * @return The 10-bit value read from the specified ADC channel.
 */
void ADC_Start_Conversion(ADC_Channels Channel);

float ADC_GetResult(void);

void ADC_Interrupt_Enable(void);

void ADC_Interrupt_Disable(void);

void ADC_Set_Callback(PTR_FN CB_Address);



#endif /* ADC_H_ */