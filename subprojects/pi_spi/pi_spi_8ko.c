#include <wiringPi.h> 
#include <wiringPiSPI.h>

#include "pi_spi.h"

static const uint8_t CS[2] = { CS_8KO, CS_SPARE1 };
static uint8_t state[2] = { 0x00, 0x00 };

void pi_spi_8ko_write(uint8_t data, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	
	digitalWrite(CS[type], LOW);
	wiringPiSPIDataRW(0, &data, 1);
	digitalWrite(CS[type], HIGH);
	
	state[type] = data;
}

void pi_spi_8ko_write_single(uint8_t channel, uint8_t data, uint8_t type)
{
	type = (type != DEFAULT && type != OPTIONAL) ? DEFAULT : type;
	channel = channel > 7 ? 7 : channel;
	
	data = (~(1 << channel) & state[type]) | (data << channel);
	
	pi_spi_8ko_write(data, type);
}
