#include <asm/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <spi.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

static int fd = -1;
static uint8_t current_channel;

static const char prefix[] = "/dev/spidev0.";

static const uint8_t     spiBPW   = 8;
static const uint16_t 	 spiDelay = 0;
static const uint8_t     spiMode  = SPI_MODE_0;

static uint32_t spiSpeed = 500000;

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

	int status = ioctl(fd, SPI_IOC_MESSAGE(1), &spi);
	if(status < 0)
	{
		perror("Failed to perform SPI transfer");
	}
}

void spi_open(uint8_t channel, uint32_t speed)
{
	if(channel != current_channel && fd >= 0)
	{
		close(fd);
		fd = -1;
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
		printf("Unable to open SPI device: %s\n", spidev);
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