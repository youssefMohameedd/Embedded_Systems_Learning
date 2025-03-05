/*
 * Stepper_CFG.h
 *
 * Created: 12/23/2024 1:20:57 AM
 *  Author: Youssef Mohamed
 */ 

// Note : Stepper Motor Model is : 28BYJ-48  5V

#ifndef STEPPER_CFG_H_
#define STEPPER_CFG_H_



#define IN1 PD4
#define IN2 PD5
#define IN3 PD6
#define IN4 PD7

#define STEPPER_PORT PD
#define STEPPER_SIG HIGH

#define STEPPING 2// 0 : Half-Stepping(Variable Torque) , 1 : Full-Stepping(Const. Torque) , Wave-Mode (Const. Torque)
#define GR 64 // Gear Ratio of the output shaft speed to the motor shaft speed (64:1)



#endif /* STEPPER_CFG_H_ */