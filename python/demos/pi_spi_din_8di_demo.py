from time import sleep
from widgetlords.pi_spi_din import *

inputs = Mod8DI(ChipEnable.CE2)
while True:
    print(inputs.read())
    sleep(0.5)