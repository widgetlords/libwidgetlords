#include <gpio.h>
#include <pi_spi_din.h>
#include <spi.h>

// GPIO pins
#define K1 5
#define K2 6
#define DI1 13
#define DI2 19

void vpe_2901a_2ao_write_single(uint8_t channel, uint16_t counts)
{
	channel = channel > 1 ? 1 : channel;
	
	uint8_t data[] =
	{
		(0x30 | channel << 7) | (counts >> 8 & 0x0F),	// 4bit config and upper 4 bits of counts
		counts & 0xFF									// lower 8 bits of counts
	};
	
	spi_open(5, 500000);
	spi_transfer(data, 2);
}

void vpe_2901a_init()
{
	gpio_init();
	gpio_configure(K1, GPIO_OUTPUT);
	gpio_configure(K2, GPIO_OUTPUT);
	gpio_configure(DI1, GPIO_INPUT);
	gpio_configure(DI2, GPIO_INPUT);
}

void vpe_2901a_2ko_write_single(uint8_t channel, uint8_t value)
{
	channel = channel > 1 ? 1 : channel;
	
	if(channel == 0)
	{
		if(value)
		{
			gpio_write(K1, GPIO_HIGH);
		}
		else
		{
			gpio_write(K1, GPIO_LOW);
		}
	}
	else
	{
		if(value)
		{
			gpio_write(K2, GPIO_HIGH);
		}
		else
		{
			gpio_write(K2, GPIO_LOW);
		}
	}
}

uint8_t vpe_2901a_2di_read_single(uint8_t channel)
{
	uint8_t value;
	
	if(channel == 0)
	{
		value = gpio_read(DI1);
	}
	else
	{
		value = gpio_read(DI1);
	}
	
	return !value;
}
