from pi_spi import *

pi_spi_init()

inputs = Mod8DI()
while True:
    print(inputs.read())
    sleep(0.5)