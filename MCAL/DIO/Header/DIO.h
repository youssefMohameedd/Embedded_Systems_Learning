#ifndef DIO
#define DIO

#include <STD_Types.h>
#include <DIO_CFG.h>



void Set_Channel_Direction (DIO_Channel Ch_ID , DIO_Direction Direction);
void Write_Channel(DIO_Channel Ch_ID ,STD_Level Level);
void Toggle_Channel(DIO_Channel CH_ID);
STD_Level Read_Channel(DIO_Channel Ch_ID);
void Set_Port_Direction(DIO_Port Port_ID , uint8 Direction);
void Write_Port(DIO_Port Port_ID , uint8 Value);
uint8 Read_Port(DIO_Port Port_ID);
void Set_Nibble_Direction(DIO_Port Port_ID , uint8 Significance , uint8 Direction); // Direction from 0x0 to 0xF
uint8 Read_Nibble(DIO_Port Port_ID , uint8 Significance);
void Write_Nibble(DIO_Port Port_ID , uint8 Significance , uint8 Value);


#endif /*DIO.h Inclusion Guards*/