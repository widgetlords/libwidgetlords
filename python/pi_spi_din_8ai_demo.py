from time import sleep
from widgetlords.pi_spi_din import *

init()

inputs = Mod8AI(ChipEnable.CE1)
while True:
    print(inputs.read_single(0))
    sleep(0.5)