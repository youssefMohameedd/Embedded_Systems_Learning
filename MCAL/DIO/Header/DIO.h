#ifndef DIO
#define DIO

#include <STD_Types.h>
#include <Bit_Math.h>
#include <DIO_CFG.h>
#include <DIO_HW.h>

/**
 * @brief Sets the direction of the specified DIO channel.
 * @param Ch_ID The identifier of the DIO channel (PA0...PD7)
 * @param Direction The desired direction for the DIO channel (STD_HIGH,STD_LOW)
 */
void Set_Channel_Direction (DIO_Channel Ch_ID , DIO_Direction Direction);

/**
 * @brief Writes the specified level to the given DIO channel.
 * @param Ch_ID The identifier of the DIO channel (PA0...PD7)
 * @param Level The level to write to the DIO channel (STD_HIGH,STD_LOW)
 */
void Write_Channel(DIO_Channel Ch_ID, STD_Level Level);

/**
 * @brief Toggles the state of the specified DIO channel.
 * @param CH_ID The identifier of the DIO channel (PA0...PD7)
 */
void Toggle_Channel(DIO_Channel CH_ID);

/**
 * @brief Reads the current level of the specified DIO channel
 * @param Ch_ID The identifier of the DIO channel (PA0...PD7)
 * @return The current level of the DIO channel (STD_HIGH,STD_LOW)
 * @note This function assumes that the DIO channel is configured as an input.
 */
STD_Level Read_Channel(DIO_Channel Ch_ID);

/**
 * @brief Sets the direction of the specified DIO port.
 * @param Port_ID The identifier of the DIO port (PA...PD)
 * @param Direction The desired direction for the DIO port (0x00 to 0xFF)
 */
void Set_Port_Direction(DIO_Port Port_ID , uint8 Direction);

/**
 * @brief Writes a specific value to the whole port
 * @param Port_ID The identifier of the DIO port (PA...PD)
 * @param Value The value to write to the port (0x00 to 0xFF)
 */
void Write_Port(DIO_Port Port_ID , uint8 Value);

/**
 * @brief Reads the current value of the specified port
 * @param Port_ID The identifier of the DIO port (PA...PD)
 * @return The current value of the port (0x00 to 0xFF)
 */
uint8 Read_Port(DIO_Port Port_ID);

/**
 * @brief Sets the direction of a port nibble
 * @param Port_ID The identifier of the DIO port (PA...PD)
 * @param Significance High nibble (1) or Low nibble (0)
 * @param Direction The direction value for the nibble (0x0 to 0xF)
 */
void Set_Nibble_Direction(DIO_Port Port_ID , uint8 Significance , uint8 Direction);

/**
 * @brief Reads the value of a port nibble
 * @param Port_ID The identifier of the DIO port (PA...PD)
 * @param Significance High nibble (1) or Low nibble (0)
 * @return The current value of the nibble (0x0 to 0xF)
 */
uint8 Read_Nibble(DIO_Port Port_ID , uint8 Significance);

/**
 * @brief Writes a value to a port nibble
 * @param Port_ID The identifier of the DIO port (PA...PD)
 * @param Significance High nibble (1) or Low nibble (0)
 * @param Value The value to write to the nibble (0x0 to 0xF)
 */
void Write_Nibble(DIO_Port Port_ID , uint8 Significance , uint8 Value);

#endif /*DIO.h Inclusion Guards*/