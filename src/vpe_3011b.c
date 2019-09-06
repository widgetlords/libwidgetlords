#include <gpio.h>
#include <pi_spi_din.h>
#include <spi.h>

// GPIO pins
#define K1 5
#define K2 6
#define K3 13
#define K4 19

void vpe_3011b_init()
{
	gpio_init();
	gpio_configure(K1, GPIO_OUTPUT);
	gpio_configure(K2, GPIO_OUTPUT);
	gpio_configure(K3, GPIO_OUTPUT);
	gpio_configure(K4, GPIO_OUTPUT);
	
	// init DI
	uint8_t data[] =
	{
		0x40,	// Write command
		0x00,	// IODIR register
		0xFF,	// IODIR is input
		0xFF	// IPOL is inverted
	};
	
	spi_open(5, 1000000);
	spi_transfer(data, 4);
}

void vpe_3011b_4ko_write_single(uint8_t channel, uint8_t value)
{
	channel &= 0x03;
	
	switch(channel)
	{
		case 0:
		if(value)
		{
			gpio_write(K1, GPIO_HIGH);
		}
		else
		{
			gpio_write(K1, GPIO_LOW);
		}
		break;
		
		case 1:
		if(value)
		{
			gpio_write(K2, GPIO_HIGH);
		}
		else
		{
			gpio_write(K2, GPIO_LOW);
		}
		break;
		
		case 2:
		if(value)
		{
			gpio_write(K3, GPIO_HIGH);
		}
		else
		{
			gpio_write(K3, GPIO_LOW);
		}
		break;
		
		case 3:
		if(value)
		{
			gpio_write(K4, GPIO_HIGH);
		}
		else
		{
			gpio_write(K4, GPIO_LOW);
		}
		break;
	}
}

uint8_t vpe_3011b_8di_read()
{	
	uint8_t data[3] =
	{
		0x41,	// Read command
		0x09,	// GPIO register
		0x00
	};
	
	spi_open(5, 1000000);
	spi_transfer(data, 3);
	
	return data[2];
}

uint8_t vpe_3011b_8di_read_single(uint8_t channel)
{
	channel &= 0x07;
	
	return vpe_3011b_8di_read() >> channel & 0x01;
}
