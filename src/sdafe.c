#include <pi_spi_din.h>
#include <spi.h>
#include <unistd.h>

static enum sdafe_type types[10] = 
{ 
	TYPE_1_MA,
	TYPE_1_MA,
	TYPE_1_MA,
	TYPE_1_MA,
	TYPE_1_MA,
	TYPE_1_MA,
	TYPE_1_MA,
	TYPE_1_MA,
	TYPE_1_MA,
	TYPE_1_MA
};

static void write_type(uint8_t channel)
{
	uint8_t data[10] =
	{
		6,
		types[channel],
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	
	spi_open(channel, 100000);
	spi_transfer(data, sizeof data);
	usleep(860000);
}

static struct sdafe_reading read_data(uint8_t channel)
{
	uint8_t data[10] =
	{
		3,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	
	spi_open(channel, 100000);
	spi_transfer(data, sizeof data);
	
	/*printf("[ ");
	for(int i = 0; i < 10; ++i)
	{
		printf("%d ", data[i]);
	}
	printf("]\n");*/
	
	struct sdafe_reading reading;
	
	if(data[0] != 0x55 || data[9] != 0x55)
	{
		// printf("[ ");
		// for(int i = 0; i < 10; ++i)
		// {
		// 	printf("%d ", data[i]);
		// }
		// printf("]\n");
		
		reading.status = SDAFE_COMM_ERROR;
		reading.value = 0;
		reading.counts = 0;
		reading.type = TYPE_1_MA;
		return reading;
	}
	
	reading.value = data[3] | (data[2] << 8);
	reading.status = data[8];
	reading.counts = data[7] | (data[6] << 8);
	reading.type = data[1];
	
	return reading;
}

void sdafe_set_type(uint8_t channel, enum sdafe_type type)
{
	types[channel] = type;
	
	write_type(channel);
}

struct sdafe_reading sdafe_read(uint8_t channel)
{
	struct sdafe_reading reading = read_data(channel);
	
	if(reading.status == SDAFE_COMM_ERROR)
	{
		return reading;
	};
	
	if(reading.type != types[channel])
	{
		write_type(channel);
		reading = read_data(channel);
	}

	return reading;
}
