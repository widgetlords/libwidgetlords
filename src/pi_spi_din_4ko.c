#include <pi_spi_din.h>
#include <spi.h>

static uint8_t relay_states[5][4] =
{
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
};

void pi_spi_din_4ko_write(enum chip_enable ce, uint8_t address, uint8_t state)
{
	address = address > 3 ? 3 : address;
	
	uint8_t data[3] =
	{
		0x40 | (address << 1),	// Write command
		0x09, 									// GPIO register
		state
	};
	
	spi_open(ce, 500000);
	spi_transfer(data, 3);
	
	relay_states[ce][address] = state;
}

void pi_spi_din_4ko_write_single(enum chip_enable ce, uint8_t address, uint8_t channel, uint8_t state)
{
	channel = channel > 3 ? 3 : channel;
	
	uint8_t current_state = relay_states[ce][address];
	state = (~(1 << channel) & current_state) | (state << channel);
	pi_spi_din_4ko_write(ce, address, state);
}

void pi_spi_din_4ko_init(enum chip_enable ce, uint8_t address)
{
	address = address > 3 ? 3 : address;
	
	uint8_t data[] =
	{
		0x40 | (address << 1),	// Write command
		0x00, 									// IODIR register
		0x00,										// IODIR is output
		0xFF										// IPOL is inverted
	};
	
	spi_open(ce, 500000);
	spi_transfer(data, 4);
	
	// Enable hardware addressing
	data[0] = 0x40 | (address << 1);	// Write command
	data[1] = 0x05;										// IOCON register
	data[2] = 0x08;										// HAEN
	
	spi_transfer(data, 3);
}
