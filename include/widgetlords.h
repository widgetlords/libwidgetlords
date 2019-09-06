#ifndef WIDGETLORDS_H
#define WIDGETLORDS_H

#include <gpio.h>
#include <pi_spi.h>
#include <pi_spi_din.h>
#include <spi.h>

double widgetlords_steinhart_hart(
	double r_room,
	double r_beta,
	uint16_t counts_range,
	uint16_t counts
);

double widgetlords_counts_to_value(
	uint16_t counts,
	uint16_t zero_counts,
	uint16_t range_counts,
	double zero,
	double range
);

#endif
