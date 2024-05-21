pymod = import('python')
python = pymod.find_installation('python3', required: false, disabler: true)

python.install_sources(
  'pi_spi_din_4ao_prog.py',
  'widgetlords/__init__.py',
  'widgetlords/pi_spi.py',
  'widgetlords/pi_spi_din.py',
  subdir: 'widgetlords',
  pure: true
)
