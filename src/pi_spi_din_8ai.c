#include <pi_spi_din.h>
#include <spi.h>

#define MAX_SPI_FREQ	100000

uint16_t pi_spi_din_8ai_read_single(enum chip_enable ce, uint8_t channel)
{
	channel = channel > 7 ? 7 : channel;
	
	uint8_t data[3] =
	{
		0x06 | ((channel >> 2) & 0x01),
		(channel << 6) & 0xC0,
		0
	};
	
	spi_open(ce, MAX_SPI_FREQ);
	spi_transfer(data, 3);
	
	return (((uint16_t)data[1] & 0x0F) << 8) | data[2];
}
