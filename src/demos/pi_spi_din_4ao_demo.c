#include <unistd.h>
#include <widgetlords.h>

int main(void) 
{	
	while(1)
	{
		pi_spi_din_4ao_write_single(0, 0, 800);
		pi_spi_din_4ao_write_single(0, 2, 800);
		pi_spi_din_4ao_write_single(0, 1, 4000);
		pi_spi_din_4ao_write_single(0, 3, 4000);
		usleep(2000000);
		
		pi_spi_din_4ao_write_single(0, 0, 4000);
		pi_spi_din_4ao_write_single(0, 2, 4000);
		pi_spi_din_4ao_write_single(0, 1, 800);
		pi_spi_din_4ao_write_single(0, 3, 800);
		usleep(2000000);
	}

	return 0;
}
