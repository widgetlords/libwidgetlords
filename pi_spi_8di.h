#ifndef PI_SPI_8DI_H
#define PI_SPI_8DI_H

P99_PROTOTYPE(uint8_t, pi_spi_8di_read, uint8_t, uint8_t);
#define pi_spi_8di_read(...) P99_CALL_DEFARG(pi_spi_8di_read, 2, __VA_ARGS__)
#define pi_spi_8di_read_defarg_0() 0
#define pi_spi_8di_read_defarg_1() DEFAULT

P99_PROTOTYPE(uint8_t, pi_spi_8di_read_single, uint8_t, uint8_t, uint8_t);
#define pi_spi_8di_read_single(...) P99_CALL_DEFARG(pi_spi_8di_read_single, 3, __VA_ARGS__)
#define pi_spi_8di_read_single_defarg_1() 0
#define pi_spi_8di_read_single_defarg_2() DEFAULT

P99_PROTOTYPE(void, pi_spi_8di_init, uint8_t, uint8_t);
#define pi_spi_8di_init(...) P99_CALL_DEFARG(pi_spi_8di_init, 2, __VA_ARGS__)
#define pi_spi_8di_init_defarg_0() 0
#define pi_spi_8di_init_defarg_1() DEFAULT

#endif
