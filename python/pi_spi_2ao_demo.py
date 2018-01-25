from pi_spi import *

pi_spi_init()

outputs = Mod2AO()
while True:
    outputs.write_single(745, 0)
    outputs.write_single(3723, 1)
    sleep(2)
    
    outputs.write_single(3733, 0)
    outputs.write_single(745, 1)
    sleep(2)