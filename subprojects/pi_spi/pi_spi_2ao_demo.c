#include "pi_spi.h"

#include <stdio.h>

int main(void) 
{	
  	pi_spi_init();
  	
  	while(1)
  	{
		pi_spi_2ao_write_single(745, 0, DEFAULT);
		pi_spi_2ao_write_single(3723, 1, DEFAULT);
		delay(2000);
		
		pi_spi_2ao_write_single(3733, 0, DEFAULT);
		pi_spi_2ao_write_single(745, 1, DEFAULT);
		delay(2000);
  	}

	return 0;
}
