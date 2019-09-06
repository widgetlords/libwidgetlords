#include <pi_spi.h>
#include <spi.h>

static uint8_t state[2] = { 0x00, 0x00 };

void pi_spi_8ko_write(uint8_t data, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	
	if(type == DEFAULT)
	{
		spi_open(SPI_8KO, 500000);
	}
	else if(type == OPTIONAL)
	{
		spi_open(SPI_SPARE, 500000);
	}
	
	state[type] = data;
	
	spi_transfer(&data, 1);
}

void pi_spi_8ko_write_single(uint8_t channel, uint8_t data, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	channel = channel > 7 ? 7 : channel;
	
	data = (~(1 << channel) & state[type]) | (data << channel);
	
	pi_spi_8ko_write(data, type);
}
