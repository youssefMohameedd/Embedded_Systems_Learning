

#include <DIO.h>

void Set_Channel_Direction (DIO_Channel Ch_ID , DIO_Direction Direction)
{
    uint8 port = Ch_ID/8 ;
    uint8 pin = Ch_ID%8 ;
	
	switch(port)
	{
		case PA:
		if(Direction == INPUT)
		{
			CLR_BIT(DDRA_REG,pin);
			CLR_BIT(PORTA_REG,pin);
		}
		else if(Direction == PULL_UP)
		{
			CLR_BIT(DDRA_REG,pin);
			SET_BIT(PORTA_REG,pin);
		}
		else if(Direction == OUTPUT)	
			SET_BIT(DDRA_REG,pin);
		break;
		case PB:
		if(Direction == INPUT)		
		{
			CLR_BIT(DDRB_REG,pin);
			CLR_BIT(PORTB_REG,pin);
		}
		else if(Direction == PULL_UP)
		{
			CLR_BIT(DDRB_REG,pin);
			SET_BIT(PORTB_REG,pin);
		}	
		else if(Direction == OUTPUT)
			SET_BIT(DDRB_REG,pin);
		break;
		case PC:
		if(Direction == INPUT)	
		{
			CLR_BIT(DDRC_REG,pin);
			CLR_BIT(PORTC_REG,pin);
		}
		else if(Direction == PULL_UP)
		{
			CLR_BIT(DDRC_REG,pin);
			SET_BIT(PORTC_REG,pin);
		}
		else if(Direction == OUTPUT)
			SET_BIT(DDRC_REG,pin);
		break;
		case PD:
		if(Direction == INPUT)	
		{
			CLR_BIT(DDRD_REG,pin);
			CLR_BIT(PORTD_REG,pin);
		}
		else if(Direction == PULL_UP)
		{
			CLR_BIT(DDRD_REG,pin);
			SET_BIT(PORTD_REG,pin);
		}
		else if(Direction == OUTPUT)
			SET_BIT(DDRD_REG,pin);
		break;
	}
	
}

void Write_Channel(DIO_Channel Ch_ID ,STD_Level Level)
{
    uint8 port = Ch_ID/8 ;
    uint8 pin = Ch_ID%8 ;
	
	switch(port)
	{
		case PA:
		if(Level == LOW)		CLR_BIT(PORTA_REG,pin);
		else if(Level == HIGH)	SET_BIT(PORTA_REG,pin);
		break;
		case PB:
		if(Level == LOW)		CLR_BIT(PORTB_REG,pin);
		else if(Level == HIGH)	SET_BIT(PORTB_REG,pin);
		break;
		case PC:
		if(Level == LOW)		CLR_BIT(PORTC_REG,pin);
		else if(Level == HIGH)	SET_BIT(PORTC_REG,pin);
		break;
		case PD:
		if(Level == LOW)		CLR_BIT(PORTD_REG,pin);
		else if(Level == HIGH)	SET_BIT(PORTD_REG,pin);
		break;
	}

}

void Toggle_Channel(DIO_Channel Ch_ID)
{
	uint8 port = Ch_ID/8 ;
	uint8 pin  = Ch_ID%8 ;
	switch(port)
	{
		case PA:
		TOGGLE_BIT(PORTA_REG,pin);
		break;
		case PB:
		TOGGLE_BIT(PORTB_REG,pin);
		break;
		case PC:
		TOGGLE_BIT(PORTC_REG,pin);
		break;
		case PD:
		TOGGLE_BIT(PORTD_REG,pin);
		break;
	}
	
}

STD_Level Read_Channel(DIO_Channel Ch_ID)
{
	STD_Level Level;
	uint8 port = Ch_ID/8 ;
	uint8 pin = Ch_ID%8 ;
	
	switch(port)
	{
		case PA:	
		Level = GET_BIT(PINA_REG,pin);
		break;
		case PB:	
		Level = GET_BIT(PINB_REG,pin);
		break;
		case PC:	
		Level = GET_BIT(PINC_REG,pin);
		break;
		case PD:	
		Level = GET_BIT(PIND_REG,pin);
		break;
	}
	return Level;		
}

void Set_Port_Direction(DIO_Port Port_ID , uint8 Direction)
{
	switch(Port_ID)
	{
		case PA:	
		DDRA_REG = Direction;
		break;
		case PB:	
		DDRB_REG = Direction;
		break;
		case PC:	
		DDRC_REG = Direction;
		break;
		case PD:	
		DDRD_REG = Direction;
		break;
	}
}

void Write_Port(DIO_Port Port_ID , uint8 Value)
{
	switch(Port_ID)
	{
		case PA:	
		PORTA_REG = Value;
		break;
		case PB:	
		PORTB_REG = Value;
		break;
		case PC:	
		PORTC_REG = Value;
		break;
		case PD:	
		PORTD_REG = Value;
		break;
	}
}

uint8 Read_Port(DIO_Port Port_ID)
{
	uint8 value ;
	
	switch(Port_ID)
	{
		case PA:
		value = PINA_REG;
		break;
		case PB:
		value = PINB_REG;
		break;
		case PC:
		value = PINC_REG;
		break;
		case PD:
		value = PIND_REG;
		break;
	}
	return value ;	
}
//Below Functions can be improved (Ask ChatGPT)
void Set_Nibble_Direction(DIO_Port Port_ID , uint8 Significance , uint8 Direction)
{
	switch(Port_ID)
	{
		case PA:
		if(Significance == HIGH)
		{
			DDRA_REG = (DDRA_REG & 0x0F) | (Direction << 4);
		}
		else if(Significance == LOW)
		{
			DDRA_REG = (DDRA_REG & 0xF0) | (Direction);
		}
		break;
		case PB:
		if(Significance == HIGH)
		{
			DDRB_REG = (DDRB_REG & 0x0F) | (Direction << 4);
		}
		else if(Significance == LOW)
		{
			DDRB_REG = (DDRB_REG & 0xF0) | (Direction);
		}
		break;
		case PC:
		if(Significance == HIGH)
		{
			DDRC_REG = (DDRC_REG & 0x0F) | (Direction << 4);
		}
		else if( Significance == LOW)
		{
			DDRC_REG = (DDRC_REG & 0xF0) | (Direction);
		}
		break;
		case PD:
		if(Significance == HIGH)
		{
			DDRD_REG = (DDRD_REG & 0x0F) | (Direction << 4);
		}
		else if(Significance == LOW)
		{
			DDRD_REG = (DDRD_REG & 0xF0) | (Direction);
		}
		break;
	}
}
			
uint8 Read_Nibble(DIO_Port Port_ID , uint8 Significance)
{
	
	uint8 value = Read_Port(Port_ID);
	if(Significance == HIGH)	value =  (value & 0xF0) >> 4 ; 
	else if (Significance == LOW) value = (value &0x0F) ;
	
	return value ;
}

void Write_Nibble(DIO_Port Port_ID , uint8 Significance , uint8 Value)
{
	Value = (Significance==HIGH)?(Read_Nibble(Port_ID,LOW)|(Value <<4)):((Read_Nibble(Port_ID,HIGH)<<4))|(Value);
	Write_Port(Port_ID,Value);
}