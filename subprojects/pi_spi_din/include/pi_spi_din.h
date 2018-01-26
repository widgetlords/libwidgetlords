#ifndef PI_SPI_DIN_H
#define PI_SPI_DIN_H

#include <stdint.h>

// SPI chip select pins
#define CE0 8
#define CE1 7
#define CE2 24
#define CE3 23
#define CE4 18

void pi_spi_din_init();

void pi_spi_din_4ao_init();
void pi_spi_din_4ao_write_single(uint8_t channel, uint16_t counts);

uint16_t pi_spi_din_8ai_read_single(uint8_t chip_select, uint8_t channel);

uint8_t pi_spi_din_8di_read(uint8_t chip_select, uint8_t address);
uint8_t pi_spi_din_8di_read_single(uint8_t chip_select, uint8_t address, uint8_t channel);
void pi_spi_din_8di_init(uint8_t chip_select, uint8_t address);

void pi_spi_din_4ko_write(uint8_t chip_select, uint8_t address, uint8_t state);
void pi_spi_din_4ko_write_single(uint8_t chip_select, uint8_t address, uint8_t channel, uint8_t state);
void pi_spi_din_4ko_init(uint8_t chip_select, uint8_t address);

#endif
