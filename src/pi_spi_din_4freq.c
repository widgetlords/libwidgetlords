#include <pi_spi_din.h>
#include <spi.h>

#define FIXED			0x00
#define PULSE			0x04
#define DI 				0x08
#define VARIABLE	0x09

static uint32_t pi_spi_din_4freq_read(enum chip_enable ce, uint8_t address, uint8_t channel, uint8_t offset)
{
	address %= 8;
	channel %= 4;

	uint8_t data[] =
	{
		address << 1,
		channel + offset,
		0x00,
		0x00,
		0x00,
		0x00
	};

	spi_open(ce, 500000);
	spi_transfer(data, sizeof(data));

	uint32_t value = (data[2] << 24) + (data[3] << 16) + (data[4] << 8) + data[5];
	return value;
}

uint32_t pi_spi_din_4freq_read_fixed(enum chip_enable ce, uint8_t address, uint8_t channel)
{
	return pi_spi_din_4freq_read(ce, address, channel, FIXED);
}

uint32_t pi_spi_din_4freq_read_variable(enum chip_enable ce, uint8_t address, uint8_t channel)
{
	return pi_spi_din_4freq_read(ce, address, channel, VARIABLE);
}

uint32_t pi_spi_din_4freq_read_pulse(enum chip_enable ce, uint8_t address, uint8_t channel)
{
	return pi_spi_din_4freq_read(ce, address, channel, PULSE);
}

uint8_t pi_spi_din_4freq_read_di(enum chip_enable ce, uint8_t address)
{
	return pi_spi_din_4freq_read(ce, address, 0, DI);
}