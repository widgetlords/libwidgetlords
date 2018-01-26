#include "pi_spi.h"

#include <unistd.h>

int main(void) 
{	
  	pi_spi_init();
  	
  	while(1)
  	{
		pi_spi_8ko_write(0xaa, DEFAULT);
		usleep(1000000);
		pi_spi_8ko_write(0x55, DEFAULT);
		usleep(1000000);
	}

	return 0;
}
