#include "pi_spi.h"

int main(void) 
{	
  	pi_spi_init();
  	
  	while(1)
  	{
		pi_spi_8ko_write(0xaa);
		delay(1000);
		pi_spi_8ko_write(0x55);
		delay(1000);
	}

	return 0;
}
