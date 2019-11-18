#include <stdio.h>
#include <unistd.h>
#include <widgetlords.h>

int main(void)
{
	while(1)
	{
		printf("\nCH 1\tCH 2\tCH 3\tCH 4\tCH 5\tCH 6\tCH 7\tCH 8\n");
		for(int i = 0; i < 8; ++i)
		{
			pi_spi_8ai_16b_set_channel(i, DEFAULT);
			printf("%i\t", pi_spi_8ai_16b_read(DEFAULT));
		}
		usleep(500000);
	}

	return 0;
}
