project('pi_spi', 'c', default_options: '-std=c11')

#wiringpi = dependency('wiringPi')
# meson still can't locate wiringPi using regular methods
wiringpi = meson.get_compiler('c').find_library('wiringPi')

spi = subproject('spi').get_variable('dep')

include = include_directories('include')
lib = library('pi_spi',
              'pi_spi.c',
              'pi_spi_2ao.c',
              'pi_spi_8ai.c',
              'pi_spi_8di.c',
              'pi_spi_8ko.c',
              dependencies: [wiringpi, spi],
              install: true,
              include_directories: include)


dep = declare_dependency(include_directories: include, link_with: lib)
install_headers('include/pi_spi.h')

executable('pi_spi_8ko_demo', 'pi_spi_8ko_demo.c', dependencies: [dep])
executable('pi_spi_8ai_demo', 'pi_spi_8ai_demo.c', dependencies: [dep])
executable('pi_spi_8di_demo', 'pi_spi_8di_demo.c', dependencies: [dep])
executable('pi_spi_2ao_demo', 'pi_spi_2ao_demo.c', dependencies: [dep])