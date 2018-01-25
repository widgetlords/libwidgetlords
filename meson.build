#project('libvpprocess', 'c', default_options: '-std=c99')
project('libvpprocess', 'c')
add_global_arguments('-std=c11', language: 'c')

#wiringpi = dependency('wiringPi')
#wiringpi = meson.get_compiler('c').find_library('wiringPi')
wiringpi = find_library('wiringPi')

#pi_spi_8ko = library('pi_spi_8ko', 'pi_spi_8ko.c', dependencies: wiringpi)
pi_spi = shared_library('pi_spi', 
                        'pi_spi.c',
                        'pi_spi_2ao.c',
                        'pi_spi_8ai.c',
                        'pi_spi_8di.c',
                        'pi_spi_8ko.c',
                        dependencies: wiringpi)

executable('pi_spi_8ko_demo', 'pi_spi_8ko_demo.c', link_with: pi_spi, dependencies: wiringpi)
executable('pi_spi_8ai_demo', 'pi_spi_8ai_demo.c', link_with: pi_spi, dependencies: wiringpi)
executable('pi_spi_8di_demo', 'pi_spi_8di_demo.c', link_with: pi_spi, dependencies: wiringpi)
executable('pi_spi_2ao_demo', 'pi_spi_2ao_demo.c', link_with: pi_spi, dependencies: wiringpi)