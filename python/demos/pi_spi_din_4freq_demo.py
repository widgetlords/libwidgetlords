from time import sleep
from widgetlords.pi_spi_din import *

freq = Mod4Freq(ChipEnable.CE0)
while True:
    # Read frequency counter
    print('\n------------------------------------------------')
    print('Channel 1 frequency:', freq.read_fixed(0), 'Hz')
    print('Channel 2 frequency:', freq.read_fixed(1), 'Hz')
    print('Channel 3 frequency:', freq.read_fixed(2), 'Hz')
    print('Channel 4 frequency:', freq.read_fixed(3), 'Hz')
    
    # Read pulse counter
    print('Channel 1 pulses:', freq.read_pulse(0))
    print('Channel 2 pulses:', freq.read_pulse(1))
    print('Channel 3 pulses:', freq.read_pulse(2))
    print('Channel 4 pulses:', freq.read_pulse(3))
    
    # read DI
    print('DI:', freq.read_di())
    
    print('Channel 1 frequency (variable):', freq.read_variable(0), 'Hz')
    print('Channel 2 frequency (variable):', freq.read_variable(1), 'Hz')
    print('Channel 3 frequency (variable):', freq.read_variable(2), 'Hz')
    print('Channel 4 frequency (variable):', freq.read_variable(3), 'Hz')
    
    sleep(1)