#ifndef DIO_CFG
#define DIO_CFG

typedef enum {PA = 0 , PB , PC , PD }DIO_Port;

typedef enum 
{
    PA0 = 0 ,
    PA1 = 1 ,
    PA2 = 2 ,
    PA3 = 3 ,
    PA4 = 4 ,
    PA5 = 5 ,
    PA6 = 6 ,
    PA7 = 7 ,
    PB0 = 8 ,
    PB1 = 9 , 
    PB2 = 10 ,
    PB3 = 11 , 
    PB4 = 12 ,
    PB5 = 13 ,
    PB6 = 14 ,
    PB7 = 15 ,
    PC0 = 16 , 
    PC1 = 17 , 
    PC2 = 18 ,
    PC3 = 19 ,
    PC4 = 20 ,
    PC5 = 21 ,
    PC6 = 22 ,
    PC7 = 23 ,
    PD0 = 24 ,
    PD1 = 25 ,
    PD2 = 26 ,
    PD3 = 27 ,
    PD4 = 28 ,
    PD5 = 29 ,
    PD6 = 30 ,
    PD7 = 31 
}DIO_Channel;

typedef enum {INPUT ,OUTPUT, PULL_UP}DIO_Direction;

#endif /*DIO_CFG Inclusion guards*/
