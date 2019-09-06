#include <errno.h>
#include <fcntl.h>
#include <gpio.h>
#include <linux/gpio.h> // see this file for API details
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define CONSUMER_LABEL "libwidgetlords"

static int fd = -1;
static int *handles;
static uint8_t handles_len = 0;

static uint8_t initialized = 0;

void gpio_init()
{
  if(initialized)
  {
    return;
  }

	fd = open("/dev/gpiochip0", O_RDWR);
	if(fd < 0)
	{
		printf("Unable to open /dev/gpiochip0: %s\n", strerror(errno));
		return;
	}

	struct gpiochip_info info;
	if(ioctl(fd, GPIO_GET_CHIPINFO_IOCTL, &info) < 0)
	{
		printf("GPIO failure: %s\n", strerror(errno));
		return;
	}

	// printf("GPIO chip name: %s\n", info.name);
	// printf("GPIO chip label: %s\n", info.label);
	// printf("GPIO chip lines: %d\n", info.lines);

  handles_len = info.lines;
  handles = calloc(handles_len, sizeof(int));

  // Here we iterate through each line and configure its "line_offset"
  // to be the same as its position in the chip. The other system calls
  // address GPIOs via "line_offset" instead of the true index. The 
  // reason for this is unknown but we have to deal with it.
	for(uint8_t i = 0; i < info.lines; ++i)
	{
		struct gpioline_info info2;
		memset(&info2, 0, sizeof(info2)); // get to a known state
		info2.line_offset = i;
		if(ioctl(fd, GPIO_GET_LINEINFO_IOCTL, &info2) < 0)
		{
			printf("GPIO failure: %s\n", strerror(errno));
			return;
		}

		// printf("GPIO Line %d name: %s\n", i, info2.name);
		// printf("GPIO Line %d consumer: %s\n", i, info2.consumer);
		// printf("GPIO Line %d line_offset: %d\n", i, info2.line_offset);
    // printf("GPIO Line %d used by kernel: %d\n", i, info2.flags & GPIOLINE_FLAG_KERNEL);
	}

	// close(fd);
	// fd = open("/dev/gpiochip1", O_RDWR);
	// if(fd < 0)
	// {
	// 	printf("Unable to open /dev/gpiochip1\n");
	// 	return;
	// }

	// if(ioctl(fd, GPIO_GET_CHIPINFO_IOCTL, &info) < 0)
	// {
	// 	printf("GPIO failure: %s\n", strerror(errno));
	// 	return;
	// }

	// printf("GPIO chip name: %s\n", info.name);
	// printf("GPIO chip label: %s\n", info.label);
	// printf("GPIO chip lines: %d\n", info.lines);

  initialized = 1;
}

void gpio_configure(uint32_t pin, uint8_t flags)
{
  if(pin >= handles_len) // avoid segfaults
  {
    return;
  }
  if(handles[pin] > 0) // if we are reconfiguring a GPIO with a handle make sure to free it
  {
    close(handles[pin]);
  }

  struct gpiohandle_request request;
	memset(&request, 0, sizeof(request)); // get to a known state

  if(flags & GPIO_INPUT)
  {
    request.flags = GPIOHANDLE_REQUEST_INPUT;
  }
  else if(flags & GPIO_OUTPUT)
  {
    request.flags = GPIOHANDLE_REQUEST_OUTPUT;  
  }
	request.lineoffsets[0] = pin;
  strcpy(request.consumer_label, CONSUMER_LABEL);
	request.lines = 1;

	if(ioctl(fd, GPIO_GET_LINEHANDLE_IOCTL, &request) < 0)
	{
		printf("GPIO failure: %s\n", strerror(errno));
		return;
	}

  handles[pin] = request.fd;
  // if(handles[pin] <= 0)
  // {
  //   printf("GPIO failure: %s\n", strerror(errno));
	// 	return;
  // }
}

void gpio_write(uint32_t pin, uint8_t value)
{
  if(pin >= handles_len) // avoid segfaults
  {
    return;
  }

  struct gpiohandle_data data;
  memset(&data, 0, sizeof(data)); // get to a known state
  data.values[0] = value;

  if(ioctl(handles[pin], GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data) < 0)
	{
		printf("GPIO failure: %s\n", strerror(errno));
		return;
	}
}

int8_t gpio_read(uint32_t pin)
{
  if(pin >= handles_len) // avoid segfaults
  {
    return -1;
  }

  struct gpiohandle_data data;
  memset(&data, 0, sizeof(data)); // get to a known state

  if(ioctl(handles[pin], GPIOHANDLE_GET_LINE_VALUES_IOCTL, &data) < 0)
	{
		printf("GPIO failure: %s\n", strerror(errno));
		return -1;
	}

  return data.values[0];
}