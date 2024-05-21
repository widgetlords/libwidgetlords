dtc = find_program('dtc')

pi_spi = custom_target('pi-spi.dtbo',
  output: 'pi-spi.dtbo',
  input: 'pi-spi.dts',
  command: [ dtc, '-@', '-I', 'dts', '-O', 'dtb', '-o', '@OUTPUT@', '@INPUT@' ],
  build_by_default: true,
  install: true,
  install_dir: '/usr/share/libwidgetlords/',
  install_mode: ['rw-r--r--', 'root', 'root']
)

vpe_2701c = custom_target('vpe-2701c.dtbo',
  output: 'vpe-2701c.dtbo',
  input: 'vpe-2701c.dts',
  command: [ dtc, '-@', '-I', 'dts', '-O', 'dtb', '-o', '@OUTPUT@', '@INPUT@' ],
  build_by_default: true,
  install: true,
  install_dir: '/usr/share/libwidgetlords/',
  install_mode: ['rw-r--r--', 'root', 'root']
)

vpe_2901a = custom_target('vpe-2901a.dtbo',
  output: 'vpe-2901a.dtbo',
  input: 'vpe-2901a.dts',
  command: [ dtc, '-@', '-I', 'dts', '-O', 'dtb', '-o', '@OUTPUT@', '@INPUT@' ],
  build_by_default: true,
  install: true,
  install_dir: '/usr/share/libwidgetlords/',
  install_mode: ['rw-r--r--', 'root', 'root']
)

vpe_3011b = custom_target('vpe-3011b.dtbo',
  output: 'vpe-3011b.dtbo',
  input: 'vpe-3011b.dts',
  command: [ dtc, '-@', '-I', 'dts', '-O', 'dtb', '-o', '@OUTPUT@', '@INPUT@' ],
  build_by_default: true,
  install: true,
  install_dir: '/usr/share/libwidgetlords/',
  install_mode: ['rw-r--r--', 'root', 'root']
)
