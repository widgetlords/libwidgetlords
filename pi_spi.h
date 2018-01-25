#ifndef PI_SPI_H
#define PI_SPI_H

#include <stdint.h>
#include "p99/p99.h"

// Define Pins as used by Pi-SPi modules
#define CS_2AO		4
#define CS_8DI		17
#define CS_SPARE2	27
#define CS_SPARE1	22
#define CS_LEDS		18
#define CS_LCD1		23
#define CS_LCD2		24
#define CS_8KO		8
#define CS_8AI		7
#define DIR_RS485	25

void pi_spi_init();

#define DEFAULT 0
#define OPTIONAL 1

#include "pi_spi_2ao.h"
#include "pi_spi_8ai.h"
#include "pi_spi_8di.h"
#include "pi_spi_8ko.h"

void delay(unsigned int howLong);

#endif
