#include "pi_spi_din.h"

int main(void) 
{	
  	pi_spi_din_init();
  	pi_spi_din_4ko_init(CE3, 0);
  	
  	while(1)
  	{
		pi_spi_din_4ko_write(CE3, 0, 0x5);
		delay(1000);
		pi_spi_din_4ko_write(CE3, 0, 0xA);
		delay(1000);
	}

	return 0;
}
