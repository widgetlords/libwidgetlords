#ifndef PI_SPI_H
#define PI_SPI_H

#include <stdint.h>

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

void pi_spi_2ao_write_single(uint8_t channel, uint16_t counts, uint8_t type);

uint16_t pi_spi_8ai_read_single(uint8_t channel, uint8_t type);

uint8_t pi_spi_8di_read(uint8_t address, uint8_t type);
uint8_t pi_spi_8di_read_single(uint8_t address, uint8_t channel, uint8_t type);
void pi_spi_8di_init(uint8_t address, uint8_t type);

void pi_spi_8ko_write(uint8_t data, uint8_t type);
void pi_spi_8ko_write_single(uint8_t channel, uint8_t data, uint8_t type);

#endif
