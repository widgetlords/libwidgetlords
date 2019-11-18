project('libwidgetlords', 'c', default_options: '-std=c11')

pkg = import('pkgconfig')

cc = meson.get_compiler('c')

# add -lm
m_dep = cc.find_library('m', required : false)

include = include_directories('include')
source = [
  'src/gpio.c',
  'src/helpers.c',
  'src/pi_spi.c',
  'src/pi_spi_2ao.c',
  'src/pi_spi_8ai.c',
  'src/pi_spi_8ai_16b.c',
  'src/pi_spi_8di.c',
  'src/pi_spi_8ko.c',
  'src/pi_spi_din.c',
  'src/pi_spi_din_8ai.c',
  'src/pi_spi_din_8di.c',
  'src/pi_spi_din_4ko.c',
  'src/pi_spi_din_4ao.c',
  'src/pi_spi_din_4freq.c',
  'src/vpe_2901a.c',
  'src/sdafe.c',
  'src/vpe_3011b.c',
  'src/spi.c'
]
lib = library('widgetlords',
              source,
              # dependencies: [m_dep, wiringpi],
              dependencies: [m_dep],
              install: true,
              include_directories: include,
              version: '2.0.0')

install_headers('include/gpio.h', 'include/pi_spi.h', 'include/pi_spi_din.h', 'include/spi.h', 'include/widgetlords.h', subdir: 'widgetlords')

install_data('libwidgetlords.vapi', install_dir: 'share/vala/vapi')

dep = declare_dependency(include_directories: include, link_with: lib)

pkg.generate(libraries: [lib], 
             version: '2.0.0', 
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

  install_data('python/widgetlords/__init__.py',
               'python/widgetlords/pi_spi.py', 
               'python/widgetlords/pi_spi_din.py',
               'python/pi_spi_din_4ao_prog.py', 
               install_dir: join_paths(python_dir, 'widgetlords'))
endif

executable('pi_spi_8ko_demo', 'src/demos/pi_spi_8ko_demo.c', dependencies: [dep])
executable('pi_spi_8ai_demo', 'src/demos/pi_spi_8ai_demo.c', dependencies: [dep])
executable('pi_spi_8ai_16b_demo', 'src/demos/pi_spi_8ai_16b_demo.c', dependencies: [dep])
executable('pi_spi_8di_demo', 'src/demos/pi_spi_8di_demo.c', dependencies: [dep])
executable('pi_spi_2ao_demo', 'src/demos/pi_spi_2ao_demo.c', dependencies: [dep])

executable('pi_spi_din_4ko_demo', 'src/demos/pi_spi_din_4ko_demo.c', dependencies: [dep])
executable('pi_spi_din_8ai_demo', 'src/demos/pi_spi_din_8ai_demo.c', dependencies: [dep])
executable('pi_spi_din_8ai_mademo', 'src/demos/pi_spi_din_8ai_mademo.c', dependencies: [dep])
executable('pi_spi_din_8ai_10vdemo', 'src/demos/pi_spi_din_8ai_10vdemo.c', dependencies: [dep])
executable('pi_spi_din_8ai_thermdemo', 'src/demos/pi_spi_din_8ai_thermdemo.c', dependencies: [dep])
executable('pi_spi_din_8di_demo', 'src/demos/pi_spi_din_8di_demo.c', dependencies: [dep])
executable('pi_spi_din_4ao_demo', 'src/demos/pi_spi_din_4ao_demo.c', dependencies: [dep])
executable('pi_spi_din_4freq_demo', 'src/demos/pi_spi_din_4freq_demo.c', dependencies: [dep])
executable('vpe_2901a_demo', 'src/demos/vpe_2901a_demo.c', dependencies: [dep])
executable('vpe_3011b_demo', 'src/demos/vpe_3011b_demo.c', dependencies: [dep])
