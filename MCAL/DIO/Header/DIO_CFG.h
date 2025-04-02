#ifndef DIO_CFG
#define DIO_CFG

typedef enum {PA_PORT = 0 , PB_PORT , PC_PORT , PD_PORT }DIO_Port;
	
//Token to include information about the port and the pin .
typedef enum 
{
    PA0_PIN = 0 ,
    PA1_PIN = 1 ,
    PA2_PIN = 2 ,
    PA3_PIN = 3 ,
    PA4_PIN = 4 ,
    PA5_PIN = 5 ,
    PA6_PIN = 6 ,
    PA7_PIN = 7 ,
    PB0_PIN = 8 ,
    PB1_PIN = 9 , 
    PB2_PIN = 10 ,
    PB3_PIN = 11 , 
    PB4_PIN = 12 ,
    PB5_PIN = 13 ,
    PB6_PIN = 14 ,
    PB7_PIN = 15 ,
    PC0_PIN = 16 , 
    PC1_PIN = 17 , 
    PC2_PIN = 18 ,
    PC3_PIN = 19 ,
    PC4_PIN = 20 ,
    PC5_PIN = 21 ,
    PC6_PIN = 22 ,
    PC7_PIN = 23 ,
    PD0_PIN = 24 ,
    PD1_PIN = 25 ,
    PD2_PIN = 26 ,
    PD3_PIN = 27 ,
    PD4_PIN = 28 ,
    PD5_PIN = 29 ,
    PD6_PIN = 30 ,
    PD7_PIN = 31 
}DIO_Channel;

typedef enum {INPUT ,OUTPUT, PULL_UP}DIO_Direction;

#endif /*DIO_CFG Inclusion guards*/
