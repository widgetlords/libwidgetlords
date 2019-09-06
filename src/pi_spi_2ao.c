#include <pi_spi.h>
#include <spi.h>

void pi_spi_2ao_write_single(uint8_t channel, uint16_t counts, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	channel = channel > 1 ? 1 : channel;
	
	uint8_t data[] =
	{
		(0x30 | channel << 7) | (counts >> 8 & 0x0F),	// 4bit config and upper 4 bits of counts
		counts & 0xFF																	// lower 8 bits of counts
	};
	
	if(type == DEFAULT)
	{
		spi_open(SPI_2AO, 500000);
	}
	else if(type == OPTIONAL)
	{
		spi_open(SPI_SPARE, 500000);
	}
	
	spi_transfer(data, 2);
}
