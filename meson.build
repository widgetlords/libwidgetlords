project('libwidgetlords', 'c', default_options: '-std=c11')

#wiringpi = dependency('wiringPi')
# meson still can't locate wiringPi using regular methods
#wiringpi = meson.get_compiler('c').find_library('wiringPi')

pi_spi = subproject('pi_spi').get_variable('dep')
pi_spi_din = subproject('pi_spi_din').get_variable('dep')
spi = subproject('spi').get_variable('dep')