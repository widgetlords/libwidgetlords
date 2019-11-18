#include <pi_spi.h>
#include <spi.h>

#define MAX_SPI_FREQ	100000

uint8_t _channels[4] = { 0, 0, 0, 0 };

int8_t _open(uint8_t type)
{
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
		return -1;
	}

	return 0;
}

// read data from previously opened SPI device
uint16_t _read(uint8_t channel)
{
	uint8_t data[2] = { channel, channel };

	spi_transfer(data, 2);

	return ((uint16_t)data[0] << 8) | data[1];
}

void pi_spi_8ai_16b_set_channel(uint8_t channel, uint8_t type)
{
	channel = channel > 7 ? 7 : channel;

	uint8_t ret = _open(type);
	if(ret < 0) { return; }

	_channels[type] = channel;

	// read once to write channel to mux
	_read(channel);
	// read twice to ensure ADC has updated reading
	_read(channel);
}

uint16_t pi_spi_8ai_16b_read(uint8_t type)
{
	uint8_t ret = _open(type);
	if(ret < 0) { return 0; }

	return _read(_channels[type]);
}
