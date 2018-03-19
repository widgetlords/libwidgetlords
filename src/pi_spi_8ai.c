#include <spi.h>

#include "pi_spi.h"

#define MAX_SPI_FREQ	100000

uint16_t pi_spi_8ai_read_single(uint8_t channel, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	channel = channel > 7 ? 7 : channel;
	
	uint8_t data[3] =
	{
		0x06 | (channel >> 2 & 0x01),
		channel << 6 & 0xC0,
		0
	};
	
	if(type == DEFAULT)
	{
		spi_open(SPI_8AI, MAX_SPI_FREQ);
	}
	else if(type == OPTIONAL)
	{
		spi_open(SPI_SPARE, MAX_SPI_FREQ);
	}
	
	spi_transfer(data, 3);
	
	return (((uint16_t)data[1] & 0x0F) << 8) | data[2];
}
