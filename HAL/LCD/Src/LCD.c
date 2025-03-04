/*
 * LCD.c
 *
 * Created: 11/25/2024 10:50:40 AM
 *  Author: Youssef
 */ 

#include <LCD.h>

static uint8 AC = 0; // Address Counter initialization 
static uint8 Init_Flag = 0;

void LCD_Latch(void) {
	Write_Channel(LCD_E, HIGH);
	_delay_ms(1); 
	Write_Channel(LCD_E, LOW);
	_delay_ms(1);
}
// Logic : __HigherNibble__|‾‾Latch‾‾|__LowerNibble__|‾‾Latch‾‾|__
void LCD_Write_Cmd(uint8 cmd) {
	
	Write_Channel(LCD_RS, LOW);
	_delay_us(2);
	
	#if(INIT_MODE==0)
	if(Init_Flag == 1)
	{	
	Write_Nibble(LCD_PORT, LCD_SIG, cmd >> 4); // Send higher nibble
	LCD_Latch();
	}
	Write_Nibble(LCD_PORT, LCD_SIG, cmd & 0x0F); // Send lower nibble
	LCD_Latch();
	
	#elif(INIT_MODE == 1)
	
	Write_Port(LCD_PORT,cmd);
	LCD_Latch();
	
	#endif
	_delay_us(50);
	if(cmd == 0x01 || cmd == 0x02 ) _delay_ms(2);
}

void LCD_Init(void) 
{	
	Set_Channel_Direction(LCD_E, OUTPUT);
	Set_Channel_Direction(LCD_RS, OUTPUT);
	Set_Channel_Direction(LCD_RW, OUTPUT);
	
	_delay_ms(50); // Wait for LCD power-up
	Write_Channel(LCD_RW, LOW); // Always in write mode

	#if(INIT_MODE==0)
	
		Set_Nibble_Direction(LCD_PORT,LCD_SIG,0xF);
		//Initially, we configure the LCD as an 8-bit interface until it's completely stable to convert to a 4 bit-interface(Kinda Formalities) 
		LCD_Write_Cmd(EIGHT_BIT_MODE);	_delay_ms(5); 
		LCD_Write_Cmd(EIGHT_BIT_MODE);	_delay_us(150);
		LCD_Write_Cmd(EIGHT_BIT_MODE);
		LCD_Write_Cmd(FOUR_BIT_MODE);	_delay_ms(1);  // Ensure LCD properly latches 4-bit modeSome LCDs need a brief delay before fully transitioning
		Init_Flag = 1;
		LCD_Write_Cmd(FUNCTION_SET);
		LCD_Write_Cmd(DISPLAY_CONTROL);
		LCD_Write_Cmd(DISPLAY_CLEAR); 
		LCD_Write_Cmd(ENTRY_MODE_SET); //optional

	#elif(INIT_MODE==1)
	
		Init_Flag = 1;
		Set_Port_Direction(LCD_PORT,0xFF);
		//Below 3 commands are left shifted to ensure proper handling by LCD_Write_Cmd function
		LCD_Write_Cmd(EIGHT_BIT_MODE<<4);	_delay_ms(5);
		LCD_Write_Cmd(EIGHT_BIT_MODE<<4);	_delay_us(150);
		LCD_Write_Cmd(EIGHT_BIT_MODE<<4);
		LCD_Write_Cmd(FUNCTION_SET);
		LCD_Write_Cmd(DISPLAY_CONTROL);
		LCD_Write_Cmd(DISPLAY_CLEAR);
		LCD_Write_Cmd(ENTRY_MODE_SET); //optional
		
	#endif

}

void LCD_Move_Pos(uint8 row, uint8 col)
{
	uint8 index = 0;
	if(row <2 && col <16)	index =(row*LINE_2_BASE_ADDRESS) + col;
	else if (row >1 )		index = LINE_2_BASE_ADDRESS + col ;
	else if (col >16)		index = LINE_2_BASE_ADDRESS + (col%16); // wrapping exceeding columns
	AC = index;			// necessary for end of line string bug handling
	SET_BIT(index,7);   // Command Selection to modify the Address Counter value
	LCD_Write_Cmd(index);

}

void LCD_Write_Char(uint8 character)
 {	
	 //Handling end of Line string initiations
	if(AC == 0x10) LCD_Move_Pos(1,0);
	if(AC > 0x4F)
	 {
		 AC = 0 ;
		 LCD_Write_Cmd(RETURN_HOME);
	 }
	
	Write_Channel(LCD_RS, HIGH);
	_delay_us(2);
	
	#if(INIT_MODE==0)
	
	Write_Nibble(LCD_PORT,LCD_SIG, character >> 4);   // Send higher nibble
	LCD_Latch();

	Write_Nibble(LCD_PORT,LCD_SIG, character & 0x0F); // Send lower nibble
	LCD_Latch();
	
	#elif(INIT_MODE==1)
	Write_Port(LCD_PORT,character);
	LCD_Latch();
	
	#endif
	_delay_us(50);
	AC++;
	
}

void LCD_Write_Digit(uint8 digit)
{
	digit = digit + '0' ; //mapping decimal digits to corresponding ascii code
	LCD_Write_Char(digit);
	
}

void LCD_Write_Str(uint8 * ptr)
{ 
	while((*ptr)!='\0')
	{
		LCD_Write_Char(*ptr);
		ptr++;
	}
	
}

uint8  No_Digits(uint32 n)
{
	uint8 counter = 0;
	while (n!=0)
	{	n = n/10;
		counter++;
	}
	return counter;
}

void LCD_Write_Number(uint32 number)
{
	//if(number ==0 )LCD_Write_Char(0);
	
	uint8 counter = No_Digits(number);
	uint32 divisor= 1 ;
	uint8 digit ;
	for (uint8 i = 0 ; i <counter-1 ; i++ )
	{
		 divisor = divisor*10; //used in multiplication and arithmetic shift
	}
	while(number>0)
	{
		digit = number/divisor ;
		LCD_Write_Digit(digit);
		number = number % divisor;  // equivalent to number = number - digit *divisor; anythin%1 =0
		divisor = divisor /10 ;
		// the following condition is to handle 
		if(number == 0 && divisor >1)
		{
			while (divisor >= 1)
			{
				LCD_Write_Digit(0);
				number = number % divisor; 
				divisor = divisor /10 ;
			}

		}
	}
}


void LCD_Store_Special_Character(uint8 * ptr , uint8 index)
{
	//Moving Address Counter to CGRAM
	index = index * CGRAM_STEP;
	CLR_BIT(index,7);
	SET_BIT(index,6);
	LCD_Write_Cmd(index);
	
	for(uint8 i = 0 ; i<8 ; i++)
	{
		LCD_Write_Char(ptr[i]);
		
	}
	//Return back to DDRAM
	LCD_Write_Cmd(RETURN_HOME);
}

