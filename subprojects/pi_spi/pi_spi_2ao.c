#include <wiringPi.h> 
#include <wiringPiSPI.h>

#include "pi_spi.h"

static const uint8_t CS[2] = { CS_2AO, CS_SPARE1 };

void pi_spi_2ao_write_single(uint8_t channel, uint16_t counts, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	channel = channel > 1 ? 1 : channel;
	
	uint8_t data[] =
	{
		(0x30 | channel << 7) | (counts >> 8 & 0x0F),	// 4bit config and upper 4 bits of counts
		counts & 0xFF									// lower 8 bits of counts
	};
	
	digitalWrite(CS[type], LOW);
	wiringPiSPIDataRW(0, data, 2);
	digitalWrite(CS[type], HIGH);
}
