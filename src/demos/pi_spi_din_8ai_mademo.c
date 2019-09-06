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
			double ma = widgetlords_counts_to_value(counts, 750, 3700, 4., 20.);
			printf("CH %i: %f mA\n", i, ma);
		}
		usleep(500000);
		printf("\n");
	}

	return 0;
}
