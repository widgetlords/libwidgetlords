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
			double vdc = widgetlords_counts_to_value(counts, 0, 3700, 0., 10.);
			printf("CH %i: %f V\n", i, vdc);
		}
		usleep(500000);
		printf("\n");
	}

	return 0;
}
