#include <wiringPi.h> 
#include <wiringPiSPI.h>

#include "pi_spi_din.h"

uint16_t pi_spi_din_8ai_read_single(uint8_t chip_enable, uint8_t channel)
{
	channel = channel > 7 ? 7 : channel;
	
	uint8_t data[3] =
	{
		0x06 | (channel >> 2 & 0x01),
		channel << 6 & 0xC0,
		0
	};
	
	digitalWrite(chip_enable, LOW);
	wiringPiSPIDataRW(0, data, 3);
	digitalWrite(chip_enable, HIGH);
	
	return (((uint16_t)data[1] & 0x0F) << 8) | data[2];
}
