#include <spi.h>
#include <wiringPi.h>

#include "pi_spi_din.h"

void pi_spi_din_init()
{
	wiringPiSetupGpio();
	
	//pinMode(DIR_RS485, OUTPUT);

	pinMode(HEN, OUTPUT);
	digitalWrite(HEN, HIGH);

	spi_init(8, 500000);
}
