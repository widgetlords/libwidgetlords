#ifndef PI_SPI_8KO_H
#define PI_SPI_8KO_H

P99_PROTOTYPE(void, pi_spi_8ko_write, uint8_t, uint8_t);
#define pi_spi_8ko_write(...) P99_CALL_DEFARG(pi_spi_8ko_write, 2, __VA_ARGS__)
//P99_DECLARE_DEFARG(pi_spi_8ko_update, , DEFAULT);
#define pi_spi_8ko_write_defarg_1() DEFAULT

P99_PROTOTYPE(void, pi_spi_8ko_write_single, uint8_t, uint8_t, uint8_t);
#define pi_spi_8ko_write_single(...) P99_CALL_DEFARG(pi_spi_8ko_write_single, 3, __VA_ARGS__)
#define pi_spi_8ko_write_single_defarg_2() DEFAULT

#endif
