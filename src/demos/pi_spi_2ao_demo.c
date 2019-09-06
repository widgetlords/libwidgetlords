#include <stdio.h>
#include <unistd.h>
#include <widgetlords.h>

int main(void) 
{
	while(1)
	{
		pi_spi_2ao_write_single(0, 745, DEFAULT);
		pi_spi_2ao_write_single(1, 3723, DEFAULT);
		usleep(2000000);
		
		pi_spi_2ao_write_single(0, 3733, DEFAULT);
		pi_spi_2ao_write_single(1, 745, DEFAULT);
		usleep(2000000);
	}

	return 0;
}