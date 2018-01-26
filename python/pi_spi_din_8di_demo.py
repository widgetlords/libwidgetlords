from pi_spi_din import *

pi_spi_din_init()

inputs = Mod8DI(ChipSelect.CE2)
while True:
    print(inputs.read())
    sleep(0.5)