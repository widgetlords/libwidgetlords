#ifndef PI_SPI_8AI_H
#define PI_SPI_8AI_H

P99_PROTOTYPE(uint16_t, pi_spi_8ai_read_single, uint8_t, uint8_t);
#define pi_spi_8ai_read_single(...) P99_CALL_DEFARG(pi_spi_8ai_read_single, 2, __VA_ARGS__)
#define pi_spi_8ai_read_single_defarg_1() DEFAULT

#endif
