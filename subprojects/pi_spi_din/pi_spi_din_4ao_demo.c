#include "pi_spi_din.h"

int main(void) 
{	
  	pi_spi_din_init();
  	pi_spi_din_4ao_init();
  	
  	while(1)
  	{
		pi_spi_din_4ao_write_single(0, 745);
		pi_spi_din_4ao_write_single(2, 745);
		pi_spi_din_4ao_write_single(1, 3723);
		pi_spi_din_4ao_write_single(3, 3723);
		delay(2000);
		
		pi_spi_din_4ao_write_single(0, 3733);
		pi_spi_din_4ao_write_single(2, 3733);
		pi_spi_din_4ao_write_single(1, 745);
		pi_spi_din_4ao_write_single(3, 745);
		delay(2000);
  	}

	return 0;
}
