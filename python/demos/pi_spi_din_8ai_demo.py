from time import sleep
from widgetlords.pi_spi_din import *

inputs = Mod8AI(ChipEnable.CE1)
while True:
    for i in range(0, 8):
        print(inputs.read_single(i))
        sleep(0.5)