#include <spi.h>
#include <wiringPi.h>

#include "pi_spi_din.h"

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
	pinMode(K1, OUTPUT);
	pinMode(K2, OUTPUT);
	pinMode(DI1, INPUT);
	pinMode(DI2, INPUT);
}

void vpe_2901a_2ko_write_single(uint8_t channel, uint8_t value)
{
	channel = channel > 1 ? 1 : channel;
	
	if(channel == 0)
	{
		if(value)
		{
			digitalWrite(K1, HIGH);
		}
		else
		{
			digitalWrite(K1, LOW);
		}
	}
	else
	{
		if(value)
		{
			digitalWrite(K2, HIGH);
		}
		else
		{
			digitalWrite(K2, LOW);
		}
	}
}

uint8_t vpe_2901a_2di_read_single(uint8_t channel)
{
	uint8_t value;
	
	if(channel == 0)
	{
		value = digitalRead(DI1);
	}
	else
	{
		value = digitalRead(DI2);
	}
	
	return !value;
}
