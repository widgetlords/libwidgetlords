from pi_spi_din import *

pi_spi_din_init()

inputs = Mod8AI(ChipEnable.CE1)
while True:
    print(inputs.read_single(0))
    sleep(0.5)