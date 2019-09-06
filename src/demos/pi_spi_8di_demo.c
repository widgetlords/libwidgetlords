#include <stdio.h>
#include <unistd.h>
#include <widgetlords.h>

int main(void) 
{	
	pi_spi_8di_init(0, DEFAULT);
  	
	while(1)
	{
		printf("%i\n", pi_spi_8di_read(0, DEFAULT));
		usleep(500000);
	}

	return 0;
}
