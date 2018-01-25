from pi_spi import *

pi_spi_init()

relays = Mod8KO()
while True:
    relays.write(0x00)
    sleep(1)
    relays.write(0xFF)
    sleep(1)