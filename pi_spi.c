#include <wiringPi.h>
#include <wiringPiSPI.h>

#include "pi_spi.h"

void pi_spi_init()
{
	wiringPiSetupGpio();
	
	// SPI CS Enable Lines
	pinMode(CS_2AO, OUTPUT);
	pinMode(CS_8DI, OUTPUT);
	pinMode(CS_SPARE2, OUTPUT);
	pinMode(CS_SPARE1, OUTPUT);
	pinMode(CS_LEDS, OUTPUT);
	pinMode(CS_LCD1, OUTPUT);
	pinMode(CS_LCD2, OUTPUT);
	pinMode(CS_8KO, OUTPUT);
	pinMode(CS_8AI, OUTPUT);
	pinMode(DIR_RS485, OUTPUT);
	
	digitalWrite(CS_2AO, HIGH);
	digitalWrite(CS_8AI, HIGH);
	digitalWrite(CS_8DI, HIGH);
	digitalWrite(CS_8KO, HIGH);
	digitalWrite(CS_SPARE1, HIGH);
	
	wiringPiSPISetup(0, 500000);
}
