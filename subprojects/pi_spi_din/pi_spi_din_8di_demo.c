#include "pi_spi_din.h"

#include <stdio.h>
#include <unistd.h>

int main(void) 
{	
  	pi_spi_din_init();
  	pi_spi_din_8di_init(CE2, 0);
  	
  	while(1)
  	{
		printf("%i\n", pi_spi_din_8di_read(CE2, 0));
		usleep(500000);
	}

	return 0;
}
