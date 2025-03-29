/*
 * EXTI_HW.h
 *
 * Created: 3/25/2025 2:46:18 PM
 *  Author:Youssef
 */ 


#ifndef EXTI_HW_H_
#define EXTI_HW_H_

/* Register Summary*/


#define GICR_REG   *((volatile uint8 *)0x5B)
#define GIFR_REG   *((volatile uint8 *)0x5A)
#define MCUCR_REG  *((volatile uint8 *)0x55)
#define MCUCSR_REG *((volatile uint8 *)0x54)



/*Bit Definitions*/


#define INT0_BIT    6
#define INT1_BIT    7
#define INT2_BIT    5
#define INTF0_BIT   6
#define INTF1_BIT   7
#define INTF2_BIT   5
#define ISC00_BIT   0
#define ISC01_BIT   1
#define ISC10_BIT   2
#define ISC11_BIT   3
#define ISC2_BIT    6

#endif /* EXTI_HW_H_ */