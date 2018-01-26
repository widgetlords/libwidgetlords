#include <wiringPi.h>
#include <wiringPiSPI.h>

#include "pi_spi_din.h"

void pi_spi_din_init()
{
	wiringPiSetupGpio();
	
	// SPI CS Enable Lines
	pinMode(CE0, OUTPUT);
	pinMode(CE1, OUTPUT);
	pinMode(CE2, OUTPUT);
	pinMode(CE3, OUTPUT);
	pinMode(CE4, OUTPUT);
	//pinMode(DIR_RS485, OUTPUT);
	
	digitalWrite(CE0, HIGH);
	digitalWrite(CE1, HIGH);
	digitalWrite(CE2, HIGH);
	digitalWrite(CE3, HIGH);
	digitalWrite(CE4, HIGH);
	
	wiringPiSPISetup(0, 500000);
}
