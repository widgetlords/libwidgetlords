from pi_spi_din import *

pi_spi_din_init()

inputs = Mod8AI(ChipSelect.CE1)
while True:
    print(inputs.read_single(0))
    sleep(0.5)