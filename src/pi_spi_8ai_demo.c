#include "pi_spi.h"

#include <stdio.h>
#include <unistd.h>

int main(void) 
{	
  	pi_spi_init();
  	
  	while(1)
  	{
		printf("\nCH 1\tCH 2\tCH 3\tCH 4\tCH 5\tCH 6\tCH 7\tCH 8\n");
		for(int i = 0; i < 8; ++i)
		{
			printf("%i\t", pi_spi_8ai_read_single(i, DEFAULT));
		}
		usleep(500000);
	}

	return 0;
}
