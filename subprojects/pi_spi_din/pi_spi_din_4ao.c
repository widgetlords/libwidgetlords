#include <errno.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "pi_spi_din.h"

static int fd;

void pi_spi_din_4ao_init()
{
	if((fd = open("/dev/i2c-1", O_RDWR)) < 0)
	{
		printf("Unable to open I2C device\n");
		return;
	}
	
	if(ioctl(fd, I2C_SLAVE, 0x60) < 0)
	{
		printf("I2C address select failure: %s\n", strerror(errno));
		return;
	}
}

void pi_spi_din_4ao_write_single(uint8_t channel, uint16_t counts)
{
	channel = channel > 3 ? 3 : channel;
	
	uint8_t data[] =
	{
		0x40 | channel << 1,
		0x80 | (counts >> 8 & 0x0F),
		counts & 0xFF
	};
	
	write(fd, data, sizeof(data));
}
