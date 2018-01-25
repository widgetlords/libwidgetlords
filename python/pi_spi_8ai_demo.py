from pi_spi import *

pi_spi_init()

inputs = Mod8AI()
while True:
    print(inputs.read_single(0))
    sleep(0.5)