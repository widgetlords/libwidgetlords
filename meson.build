project('libwidgetlords', 'c', default_options: '-std=c11')

pkg = import('pkgconfig')

#wiringpi = dependency('wiringPi')
# meson still can't locate wiringPi using regular methods
wiringpi = meson.get_compiler('c').find_library('wiringPi')

include = include_directories('include')
source = [
  'src/pi_spi.c',
  'src/pi_spi_2ao.c',
  'src/pi_spi_8ai.c',
  'src/pi_spi_8di.c',
  'src/pi_spi_8ko.c',
  'src/pi_spi_din.c',
  'src/pi_spi_din_8ai.c',
  'src/pi_spi_din_8di.c',
  'src/pi_spi_din_4ko.c',
  'src/pi_spi_din_4ao.c',
  'src/vpe_2901a.c',
  'src/sdafe.c',
  'src/vpe_3011b.c',
  'src/spi.c'
]
lib = library('widgetlords',
              source,
              dependencies: [wiringpi],
              install: true,
              include_directories: include,
              version: '1.0.0')

install_headers('include/pi_spi.h', 'include/pi_spi_din.h', subdir: 'widgetlords')

dep = declare_dependency(include_directories: include, link_with: lib)

pkg.generate(libraries: [lib], 
             version: '1.0.0', 
             name: 'libwidgetlords',
             description: 'libwidgetlords',
             subdirs: ['widgetlords'])

if get_option('python')
  # maybe one day
  #py = import('python3')
  #message(py.sysconfig_path())
  
  message('Getting python install dir')
  r = run_command('python3', '-c', 'from distutils.sysconfig import get_python_lib; print(get_python_lib())')
  if r.returncode() != 0
    error('Cannot find python install dir')
  endif
  python_dir = r.stdout().strip()
  message(python_dir)

  install_data('python/pi_spi.py', 'python/pi_spi_din.py', install_dir: python_dir)
endif

executable('pi_spi_8ko_demo', 'src/pi_spi_8ko_demo.c', dependencies: [dep])
executable('pi_spi_8ai_demo', 'src/pi_spi_8ai_demo.c', dependencies: [dep])
executable('pi_spi_8di_demo', 'src/pi_spi_8di_demo.c', dependencies: [dep])
executable('pi_spi_2ao_demo', 'src/pi_spi_2ao_demo.c', dependencies: [dep])

executable('pi_spi_din_4ko_demo', 'src/pi_spi_din_4ko_demo.c', dependencies: [dep])
executable('pi_spi_din_8ai_demo', 'src/pi_spi_din_8ai_demo.c', dependencies: [dep])
executable('pi_spi_din_8di_demo', 'src/pi_spi_din_8di_demo.c', dependencies: [dep])
executable('pi_spi_din_4ao_demo', 'src/pi_spi_din_4ao_demo.c', dependencies: [dep])
executable('vpe_2901a_demo', 'src/vpe_2901a_demo.c', dependencies: [dep])
executable('vpe_3011b_demo', 'src/vpe_3011b_demo.c', dependencies: [dep])