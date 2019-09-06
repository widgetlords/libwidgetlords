#include <stdio.h>
#include <unistd.h>
#include <widgetlords.h>

int main(void) 
{	
	while(1)
	{
		for(int i = 0; i < 8; ++i)
		{
			uint16_t counts = pi_spi_din_8ai_read_single(CE0, i);
			double temp = widgetlords_steinhart_hart(10000., 3380., 4095, counts);
			printf("CH %i: %f C\n", i, temp);
		}
		usleep(500000);
		printf("\n");
	}

	return 0;
}
