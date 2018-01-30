project('spi', 'c', default_options: '-std=c11')

include = include_directories('include')
lib = static_library('spi',
              	     'spi.c',
	              include_directories: include)


dep = declare_dependency(include_directories: include, link_with: lib)
#install_headers('include/pi_spi_din.h')