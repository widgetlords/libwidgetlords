#include <pi_spi.h>
#include <spi.h>

uint8_t pi_spi_8di_read(uint8_t address, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	address = address > 3 ? 3 : address;
	
	uint8_t data[3] =
	{
		0x41 | (address << 1),	// Read command
		0x09, 									// GPIO register
		0x00
	};
	
	if(type == DEFAULT)
	{
		spi_open(SPI_8DI, 500000);
	}
	else if(type == OPTIONAL)
	{
		spi_open(SPI_SPARE, 500000);
	}
	
	spi_transfer(data, 3);
	
	return data[2];
}

uint8_t pi_spi_8di_read_single(uint8_t address, uint8_t channel, uint8_t type)
{
	channel = channel > 7 ? 7 : channel;
	
	return (pi_spi_8di_read(address, type) >> channel) & 0x01;
}

void pi_spi_8di_init(uint8_t address, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	address = address > 3 ? 3 : address;
	
	if(type == DEFAULT)
	{
		spi_open(SPI_8DI, 500000);
	}
	else if(type == OPTIONAL)
	{
		spi_open(SPI_SPARE, 500000);
	}
	
	uint8_t data[] =
	{
		0x40 | (address << 1),	// Write command
		0x00, 									// IODIR register
		0xFF,										// IODIR is input
		0xFF										// IPOL is inverted
	};
	
	spi_transfer(data, 4);
	
	// Enable hardware addressing
	data[0] = 0x40 | (address << 1);	// Write command
	data[1] = 0x05;										// IOCON register
	data[2] = 0x08;										// HAEN
	
	spi_transfer(data, 3);
}
