from time import sleep
from widgetlords.pi_spi_din import *

relays = Mod4KO(ChipEnable.CE3)
while True:
    relays.write(0x5)
    sleep(1)
    relays.write(0xA)
    sleep(1)