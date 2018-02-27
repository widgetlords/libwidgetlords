#include <spi.h>
#include <wiringPi.h>

#include "pi_spi_din.h"

void pi_spi_din_init()
{
	wiringPiSetupGpio();
	
	//pinMode(DIR_RS485, OUTPUT);
	//digitalWrite(DIR_RS485, LOW); // Receive mode

	pinMode(HEN, OUTPUT);
	digitalWrite(HEN, HIGH); // Disable HART
}
