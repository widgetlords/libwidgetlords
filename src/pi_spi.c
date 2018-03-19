#include <wiringPi.h>
#include <spi.h>

#include "pi_spi.h"

void pi_spi_init()
{
	wiringPiSetupGpio();
	
	pinMode(DIR_RS485, OUTPUT);
}
