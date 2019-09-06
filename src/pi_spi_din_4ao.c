#include <errno.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <pi_spi_din.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

static int fd = -1;

void pi_spi_din_4ao_init()
{
	// if((fd = open("/dev/i2c-1", O_RDWR)) < 0)
	// {
	// 	printf("Unable to open I2C device\n");
	// 	return;
	// }
	
	// if(ioctl(fd, I2C_SLAVE, 0x60) < 0)
	// {
	// 	printf("I2C address select failure: %s\n", strerror(errno));
	// 	return;
	// }
}

void pi_spi_din_4ao_write_single(uint8_t address, uint8_t channel, uint16_t counts)
{
	address = (address % 8) + 0x60; // valid addresses are from 0x60 to 0x67 only
	channel %= 4; // four channels on this unit

	if(fd < 0)
	{
		fd = open("/dev/i2c-1", O_RDWR);
		if(fd < 0)
		{
			printf("Unable to open I2C device\n");
			return;
		}
	}

	if(ioctl(fd, I2C_SLAVE, address) < 0)
	{
		printf("I2C address select failure: %s\n", strerror(errno));
		return;
	}

	uint8_t data[] =
	{
		0x40 | channel << 1,
		0x80 | (counts >> 8 & 0x0F),
		counts & 0xFF
	};

	write(fd, data, sizeof(data));
}

void pi_spi_din_4ao_close()
{
	if(fd >= 0)
	{
		close(fd);
		fd = -1;
	}
}
