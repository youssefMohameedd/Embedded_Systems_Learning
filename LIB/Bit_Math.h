/*
 * Bit_Math.h
 *
 * Created: 10/30/2024 5:41:43 PM
 *  Author: maste
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_




#define SET_BIT(REG,BIT) (REG)|=(1<<BIT)
#define GET_BIT(REG,BIT) ((REG)>>BIT)&1
#define TOGGLE_BIT(REG,BIT) (REG)^=(1<<BIT)
#define CLR_BIT(REG,BIT) (REG)&=(~(1<<BIT))




#endif /* BIT_MATH_H_ */