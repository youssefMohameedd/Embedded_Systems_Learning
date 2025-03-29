/*
 * GIE.h
 *
 * Created: 3/28/2025 12:23:12 AM
 *  Author: Youssef
 */ 


#ifndef GIE_H_
#define GIE_H_

#include <STD_Types.h>
#include <Bit_Math.h>

// Hardware Definitions : Registers - Bits

#define SREG_REG   *((volatile uint8 *)0x5F)
#define  I_BIT				 7

// Functions Prototypes

void GI_Enable(void);
void GI_Disable(void);

#endif /* GIE_H_ */