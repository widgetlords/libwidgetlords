#include <pi_spi.h>
#include <spi.h>

#define MAX_SPI_FREQ	100000

uint16_t pi_spi_8ai_read_single(uint8_t channel, uint8_t type)
{
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
	else if(type == SPARE1)
	{
		spi_open(SPI_SPARE1, MAX_SPI_FREQ);
	}
	else if(type == SPARE2)
	{
		spi_open(SPI_SPARE2, MAX_SPI_FREQ);
	}
	else if(type == SPARE3)
	{
		spi_open(SPI_SPARE3, MAX_SPI_FREQ);
	}
	else
	{
		return 0;
	}
	
	spi_transfer(data, 3);
	
	return (((uint16_t)data[1] & 0x0F) << 8) | data[2];
}
