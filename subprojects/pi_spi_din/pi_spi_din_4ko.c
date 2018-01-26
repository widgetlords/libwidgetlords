#include <wiringPi.h> 
#include <wiringPiSPI.h>

#include "pi_spi_din.h"

static uint8_t relay_states[5][4] =
{
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
};

static uint8_t chip_select_to_index(uint8_t chip_select)
{
	switch(chip_select)
	{
		case CE0:
		return 0;
		
		case CE1:
		return 1;
		
		case CE2:
		return 2;
		
		case CE3:
		return 3;
		
		case CE4:
		return 4;
		
		default:
		return 4;
	}
}

void pi_spi_din_4ko_write(uint8_t chip_select, uint8_t address, uint8_t state)
{
	address = address > 3 ? 3 : address;
	
	uint8_t data[3] =
	{
		0x40 | (address << 1),	// Write command
		0x09, 					// GPIO register
		state
	};
	
	digitalWrite(chip_select, LOW);
	wiringPiSPIDataRW(0, data, 3);
	digitalWrite(chip_select, HIGH);
	
	relay_states[chip_select_to_index(chip_select)][address] = state;
}

void pi_spi_din_4ko_write_single(uint8_t chip_select, uint8_t address, uint8_t channel, uint8_t state)
{
	channel = channel > 3 ? 3 : channel;
	
	uint8_t current_state = relay_states[chip_select_to_index(chip_select)][address];
	state = (~(1 << channel) & current_state) | (state << channel);
	pi_spi_din_4ko_write(chip_select, address, state);
}

void pi_spi_din_4ko_init(uint8_t chip_select, uint8_t address)
{
	address = address > 3 ? 3 : address;
	
	uint8_t data[] =
	{
		0x40 | (address << 1),	// Write command
		0x00, 					// IODIR register
		0x00,					// IODIR is output
		0xFF					// IPOL is inverted
	};
	
	digitalWrite(chip_select, LOW);
	wiringPiSPIDataRW(0, data, 4);
	digitalWrite(chip_select, HIGH);
	
	// Enable hardware addressing
	data[0] = 0x40 | (address << 1);	// Write command
	data[1] = 0x05;						// IOCON register
	data[2] = 0x08;						// HAEN
	
	digitalWrite(chip_select, LOW);
	wiringPiSPIDataRW(0, data, 3);
	digitalWrite(chip_select, HIGH);
}
