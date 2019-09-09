#ifndef PI_SPI_DIN_H
#define PI_SPI_DIN_H

#include <stdint.h>

#define HEN 17
#define DIR_RS485 25

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
void pi_spi_din_4ao_write_single(uint8_t address, uint8_t channel, uint16_t counts);
void pi_spi_din_4ao_close();

uint16_t pi_spi_din_8ai_read_single(enum chip_enable ce, uint8_t channel);

uint8_t pi_spi_din_8di_read(enum chip_enable ce, uint8_t address);
uint8_t pi_spi_din_8di_read_single(enum chip_enable ce, uint8_t address, uint8_t channel);
void pi_spi_din_8di_init(enum chip_enable ce, uint8_t address);

void pi_spi_din_4ko_write(enum chip_enable ce, uint8_t address, uint8_t state);
void pi_spi_din_4ko_write_single(enum chip_enable ce, uint8_t address, uint8_t channel, uint8_t state);
void pi_spi_din_4ko_init(enum chip_enable ce, uint8_t address);

uint32_t pi_spi_din_4freq_read_fixed(enum chip_enable ce, uint8_t address, uint8_t channel);
uint32_t pi_spi_din_4freq_read_variable(enum chip_enable ce, uint8_t address, uint8_t channel);
uint32_t pi_spi_din_4freq_read_pulse(enum chip_enable ce, uint8_t address, uint8_t channel);
uint8_t pi_spi_din_4freq_read_di(enum chip_enable ce, uint8_t address);

void vpe_2901a_init();
void vpe_2901a_2ao_write_single(uint8_t channel, uint16_t counts);
void vpe_2901a_2ko_write_single(uint8_t channel, uint8_t value);
uint8_t vpe_2901a_2di_read_single(uint8_t channel);
#define VPE_2901A_SDAFE_1 6
#define VPE_2901A_SDAFE_2 7

void vpe_3011b_init();
void vpe_3011b_4ko_write_single(uint8_t channel, uint8_t value);
uint8_t vpe_3011b_8di_read();
uint8_t vpe_3011b_8di_read_single(uint8_t channel);
#define VPE_3011B_SDAFE_1 6
#define VPE_3011B_SDAFE_2 7
#define VPE_3011B_SDAFE_3 8
#define VPE_3011B_SDAFE_4 9

//--------------------------------SDAFE---------------------------------
enum sdafe_type
{
	TYPE_1_MA = 1,		// Input 0 to 20 mA, Returns 0 to 20000, Scaler 1000
	TYPE_2_MA = 2,		// Input 0 to 20 mA, Returns 0 to 10000, Scaler 100
	TYPE_3_MA = 3,		// Input 4 to 20 mA, Returns 0 to 10000, Scaler 100 Note: Readings below 4 mA return as 0

	TYPE_4_5VDC = 4,	// Input 0 to 5 VDC, Returns 0 to 5000, Scaler 1000
	TYPE_5_5VDC = 5,	// Input 0 to 5 VDC, Returns 0 to 10000, Scaler 100
	TYPE_6_5VDC = 6,	// Input 1 to 5 VDC, Returns 0 to 10000, Scaler 100 Note: Readngs beluw 1 VDC return as 0

	TYPE_7_10VDC = 7,	// Input 0 to 10 VDC, Returns 0 to 10000, Scaler 1000
	TYPE_8_10VDC = 8,	// Input 0 to 10 VDC, Returns 0 to 10000, Scaler 100
	TYPE_9_10VDC = 9	// Input 2 to 10 VDC, Returns 0 to 10000, Scaler 100 Note: Readings below 2 VDC return as 0
};

enum sdafe_status
{
	SDAFE_OK = 0,
	SDAFE_POLARITY = 1,
	SDAFE_OVER_RANGE = 2,
	SDAFE_COMM_ERROR = 3
};

struct sdafe_reading
{
	uint16_t value;
	enum sdafe_status status;
	uint16_t counts;
	enum sdafe_type type;
};

void sdafe_set_type(uint8_t channel, enum sdafe_type type);
struct sdafe_reading sdafe_read(uint8_t channel);

#endif
