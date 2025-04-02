/*
 * STD_Types.h
 *
 * Created: 10/30/2024 5:36:12 PM
 *  Author: maste
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


//Types
typedef unsigned char uint8 ;
typedef signed char sint8 ;
typedef unsigned short int uint16;
typedef signed short int sint16;
typedef unsigned int uint32;
typedef signed int sint32 ;


//Pointer to function typedef
typedef void (*PTR_FN)(void);

typedef enum {LOW,HIGH}STD_Level;

#define TRUE 1
#define FALSE 0

#define NULL 0

#endif /* STD_TYPES_H_ */