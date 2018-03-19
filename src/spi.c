#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <asm/ioctl.h>
#include <linux/spi/spidev.h>

#include "spi.h"

//static int *fds = NULL;
//static int num_fds = 0;

static int fd = -1;
static uint8_t current_channel;

static const char prefix[] = "/dev/spidev0.";

static const uint8_t     spiBPW   = 8;
static const uint16_t 	 spiDelay = 0;
static const uint8_t     spiMode  = SPI_MODE_0;

static uint32_t spiSpeed = 500000;

/*void cleanup()
{
	free(fds);
	fds = NULL;
	num_fds = 0;
}

void spi_init(uint8_t channels, uint32_t speed)
{
	// Don't leak memory
	if(fds != NULL)
	{
		return;
	}
	
	spiSpeed = speed;
	
	// allocate buffer
	num_fds = channels;
	fds = malloc(sizeof(int) * num_fds);
	
	// gather file handles
	for(uint8_t i = 0; i < num_fds; ++i)
	{
		char spidev[sizeof(prefix) + 2];
		strcpy(spidev, prefix);
		snprintf(spidev + sizeof(prefix) - 1, 2, "%d", i);
		//printf("%s\n", spidev);
		
		int fd;
		if((fd = open(spidev, O_RDWR)) < 0)
		{
			printf("Unable to open SPI device\n");
			cleanup();
			return;
		}
		fds[i] = fd;
	}
	
	// confgure SPI parameters
	for(uint8_t i = 0; i < num_fds; ++i)
	{
		if(ioctl(fds[i], SPI_IOC_WR_MODE, &spiMode) < 0)
		{
			printf("SPI Mode Change failure: %s\n", strerror(errno));
			cleanup();
			return;
		}
	  
		if(ioctl(fds[i], SPI_IOC_WR_BITS_PER_WORD, &spiBPW) < 0)
		{
			printf("SPI BPW Change failure: %s\n", strerror(errno));
			cleanup();
			return;
		}

		if(ioctl(fds[i], SPI_IOC_WR_MAX_SPEED_HZ, &spiSpeed) < 0)
		{
			printf("SPI Speed Change failure: %s\n", strerror(errno));
			cleanup();
			return;
		}
	}
}*/

/*void spi_transfer(uint8_t channel, uint8_t *data, uint32_t len)
{
	if(channel > num_fds)
	{
		return;
	}
	
	struct spi_ioc_transfer spi;
	
	memset(&spi, 0, sizeof(spi));

	spi.tx_buf        = (uint64_t)data;
	spi.rx_buf        = (uint64_t)data;
	spi.len           = len;
	spi.delay_usecs   = spiDelay;
	spi.speed_hz      = spiSpeed;
	spi.bits_per_word = spiBPW;

	return ioctl(fds[channel], SPI_IOC_MESSAGE(1), &spi);
}*/

void spi_transfer(uint8_t *data, uint32_t len)
{
	// do nothing if no device is open
	if(fd < 0)
	{
		return;
	}
	
	struct spi_ioc_transfer spi;
	
	memset(&spi, 0, sizeof(spi));

	spi.tx_buf        = (uint32_t)data;
	spi.rx_buf        = (uint32_t)data;
	spi.len           = len;
	spi.delay_usecs   = spiDelay;
	spi.speed_hz      = spiSpeed;
	spi.bits_per_word = spiBPW;

	ioctl(fd, SPI_IOC_MESSAGE(1), &spi);
}

void spi_open(uint8_t channel, uint32_t speed)
{
	if(channel != current_channel && fd >= 0)
	{
		close(fd);
	}
	else if(channel == current_channel && fd >= 0)
	{
		return;
	}
	
	current_channel = channel;
	
	spiSpeed = speed;
	
	char spidev[sizeof(prefix) + 2];
	strcpy(spidev, prefix);
	snprintf(spidev + sizeof(prefix) - 1, 2, "%d", current_channel);
	
	// aquire SPI device handle
	if((fd = open(spidev, O_RDWR)) < 0)
	{
		printf("Unable to open SPI device\n");
		return;
	}
	
	// confgure SPI parameters
	if(ioctl(fd, SPI_IOC_WR_MODE, &spiMode) < 0)
	{
		printf("SPI Mode Change failure: %s\n", strerror(errno));
		return;
	}
  
	if(ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &spiBPW) < 0)
	{
		printf("SPI BPW Change failure: %s\n", strerror(errno));
		return;
	}

	if(ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &spiSpeed) < 0)
	{
		printf("SPI Speed Change failure: %s\n", strerror(errno));
		return;
	}
}
