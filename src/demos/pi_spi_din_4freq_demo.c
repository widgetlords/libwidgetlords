#include <stdio.h>
#include <unistd.h>
#include <widgetlords.h>

int main(void) 
{	
	while(1)
	{
		printf("Channel\tFixed\tVariable\tPulse\n");
		for(uint8_t i = 0; i < 4; ++i)
		{
			uint32_t fixed = pi_spi_din_4freq_read_fixed(CE0, 0, i);
			uint32_t variable = pi_spi_din_4freq_read_variable(CE0, 0, i);
			uint32_t pulse = pi_spi_din_4freq_read_pulse(CE0, 0, i);
			printf("%i\t%i\t%i\t\t%i\n", i, fixed, variable, pulse);
		}
		uint8_t di = pi_spi_din_4freq_read_di(CE0, 0);
		printf("DI: %i\n\n", di);
		usleep(500000);
	}

	return 0;
}
