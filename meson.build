project('libwidgetlords', 'c', default_options: '-std=c11')

#wiringpi = dependency('wiringPi')
# meson still can't locate wiringPi using regular methods
#wiringpi = meson.get_compiler('c').find_library('wiringPi')

pi_spi = subproject('pi_spi').get_variable('dep')
pi_spi_din = subproject('pi_spi_din').get_variable('dep')
spi = subproject('spi').get_variable('dep')


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