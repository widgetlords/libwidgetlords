#include <wiringPi.h> 
#include <wiringPiSPI.h>

#include "pi_spi.h"

static const uint8_t CS[2] = { CS_8AI, CS_SPARE1 };

uint16_t pi_spi_8ai_read_single(uint8_t channel, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	channel = channel > 7 ? 7 : channel;
	
	uint8_t data[3] =
	{
		0x06 | (channel >> 2 & 0x01),
		channel << 6 & 0xC0,
		0
	};
	
	digitalWrite(CS[type], LOW);
	wiringPiSPIDataRW(0, data, 3);
	digitalWrite(CS[type], HIGH);
	
	return (((uint16_t)data[1] & 0x0F) << 8) | data[2];
}
