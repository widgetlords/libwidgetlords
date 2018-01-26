#include <wiringPi.h> 
#include <wiringPiI2C.h>

#include "pi_spi_din.h"

static int dev_handle;

void pi_spi_din_4ao_init()
{
	dev_handle = wiringPiI2CSetup(0x60);
}

void pi_spi_din_4ao_write_single(uint8_t channel, uint16_t counts)
{
	channel = channel > 3 ? 3 : channel;
	
	uint8_t reg = 0x40 | channel << 1;
	wiringPiI2CWriteReg16(dev_handle, reg, counts);
}
