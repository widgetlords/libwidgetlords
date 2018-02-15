#include <spi.h>
#include <wiringPi.h> 
//#include <wiringPiSPI.h>

#include "pi_spi_din.h"

uint16_t pi_spi_din_8ai_read_single(enum chip_enable ce, uint8_t channel)
{
	channel = channel > 7 ? 7 : channel;
	
	uint8_t data[3] =
	{
		0x06 | (channel >> 2 & 0x01),
		channel << 5 & 0xC0,
		0
	};
	
	/*digitalWrite(chip_enable, LOW);
	wiringPiSPIDataRW(0, data, 3);
	digitalWrite(chip_enable, HIGH);*/
	
	spi_open(ce, 500000);
	spi_transfer(data, 3);
	
	return (((uint16_t)data[1] & 0x0F) << 8) | data[2];
}
