#ifndef PI_SPI_DIN_H
#define PI_SPI_DIN_H

#include <stdint.h>

#define HEN 17

enum chip_enable
{
	CE0 = 0,
	CE1 = 1,
	CE2 = 2,
	CE3 = 3,
	CE4 = 4
};

void pi_spi_din_init();

void pi_spi_din_4ao_init();
void pi_spi_din_4ao_write_single(uint8_t channel, uint16_t counts);

uint16_t pi_spi_din_8ai_read_single(enum chip_enable ce, uint8_t channel);

uint8_t pi_spi_din_8di_read(enum chip_enable ce, uint8_t address);
uint8_t pi_spi_din_8di_read_single(enum chip_enable ce, uint8_t address, uint8_t channel);
void pi_spi_din_8di_init(enum chip_enable ce, uint8_t address);

void pi_spi_din_4ko_write(enum chip_enable ce, uint8_t address, uint8_t state);
void pi_spi_din_4ko_write_single(enum chip_enable ce, uint8_t address, uint8_t channel, uint8_t state);
void pi_spi_din_4ko_init(enum chip_enable ce, uint8_t address);

#endif
