#ifndef PI_SPI_2AO_H
#define PI_SPI_2AO_H

P99_PROTOTYPE(void, pi_spi_2ao_write_single, uint16_t, uint8_t, uint8_t);
#define pi_spi_2ao_write_single(...) P99_CALL_DEFARG(pi_spi_2ao_write_single, 3, __VA_ARGS__)
#define pi_spi_2ao_write_single_defarg_2() DEFAULT

#endif
