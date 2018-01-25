#include <wiringPi.h> 
#include <wiringPiSPI.h>

#include "pi_spi.h"

static const uint8_t CS[2] = { CS_8DI, CS_SPARE1 };

uint8_t pi_spi_8di_read(uint8_t address, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	address = address > 3 ? 3 : address;
	
	uint8_t data[3] =
	{
		0x41 | (address << 1),	// Read command
		0x09, 					// GPIO register
		0x00
	};
	
	digitalWrite(CS[type], LOW);
	wiringPiSPIDataRW(0, data, 3);
	digitalWrite(CS[type], HIGH);
	
	return data[2];
}

uint8_t pi_spi_8di_read_single(uint8_t channel, uint8_t address, uint8_t type)
{
	channel = channel > 7 ? 7 : channel;
	
	return pi_spi_8di_read(address, type) >> channel & 0x01;
}

void pi_spi_8di_init(uint8_t address, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	address = address > 3 ? 3 : address;
	
	uint8_t data[] =
	{
		0x40 | (address << 1),	// Write command
		0x00, 					// IODIR register
		0xFF,					// IODIR is input
		0xFF					// IPOL is inverted
	};
	
	digitalWrite(CS[type], LOW);
	wiringPiSPIDataRW(0, data, 4);
	digitalWrite(CS[type], HIGH);
	
	// Enable hardware addressing
	data[0] = 0x40 | (address << 1);	// Write command
	data[1] = 0x05;						// IOCON register
	data[2] = 0x08;						// HAEN
	
	digitalWrite(CS[type], LOW);
	wiringPiSPIDataRW(0, data, 3);
	digitalWrite(CS[type], HIGH);
}
