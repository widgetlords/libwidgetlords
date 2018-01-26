#include "pi_spi.h"

#include <stdio.h>

int main(void) 
{	
  	pi_spi_init();
  	pi_spi_8di_init(0, DEFAULT);
  	
  	while(1)
  	{
		printf("%i\n", pi_spi_8di_read(0, DEFAULT));
		delay(500);
	}

	return 0;
}
