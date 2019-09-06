#include <unistd.h>
#include <widgetlords.h>

int main(void) 
{	
	pi_spi_din_4ko_init(CE3, 0);
  	
	while(1)
	{
		pi_spi_din_4ko_write(CE3, 0, 0x5);
		usleep(1000000);
		pi_spi_din_4ko_write(CE3, 0, 0xA);
		usleep(1000000);
	}

	return 0;
}
