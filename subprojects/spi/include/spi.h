#ifndef SPI_H
#define SPI_H

#include <stdint.h>

void spi_init(uint8_t channels, uint32_t speed);
void spi_transfer(uint8_t channel, uint8_t *data, uint32_t len);

#endif
