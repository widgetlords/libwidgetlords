#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIO_HIGH  1
#define GPIO_LOW   0

#define GPIO_INPUT        1
#define GPIO_OUTPUT       2
#define GPIO_OPEN_DRAIN   4 // not implemented yet
#define GPIO_OPEN_SOURCE  8 // not implemented yet

void gpio_init();
void gpio_configure(uint32_t pin, uint8_t flags);
void gpio_write(uint32_t pin, uint8_t value);
int8_t gpio_read(uint32_t pin);

#endif