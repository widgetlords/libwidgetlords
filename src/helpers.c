#include <math.h>
#include <stdint.h>
                
double widgetlords_steinhart_hart
(
	double r_room, 
	double r_beta, 
	uint16_t counts_range, 
	uint16_t counts
)
{
	#define R_LOAD 10000.
	#define T_KELVIN_0C 273.15
	#define T_NOMINAL_TEMP 25.
	
	double reading = counts * R_LOAD / (counts_range - counts);
	double inv_t = 1 / (T_KELVIN_0C + 25.) + 
		1 / r_beta * log(reading / r_room);
	double t = 1 / inv_t - T_KELVIN_0C;
	return t;
}

double widgetlords_counts_to_value
(
	uint16_t counts, 
	uint16_t zero_counts,
	uint16_t range_counts, 
	double zero, 
	double range
)
{	
	double reading = (counts - zero_counts) * (range - zero) / 
		(range_counts - zero_counts) + zero;
	return reading;
}
